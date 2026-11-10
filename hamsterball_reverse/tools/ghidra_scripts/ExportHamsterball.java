// Annotate known evidence and export an inspectable first-stage analysis.
// @category Hamsterball
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.*;

public class ExportHamsterball extends GhidraScript {
    private PrintWriter writer(Path path) throws Exception {
        return new PrintWriter(Files.newBufferedWriter(path, StandardCharsets.UTF_8));
    }
    private String clean(Object v) {
        return String.valueOf(v).replace('\t', ' ').replace('\n', ' ').replace('\r', ' ');
    }
    public void run() throws Exception {
        String expected = "047d6613005513e1cafc607f83b1520973828e77babbdaa52846723060a94b58";
        if (!expected.equalsIgnoreCase(currentProgram.getExecutableSHA256())) {
            throw new IllegalStateException("Executable hash mismatch");
        }
        String[] args = getScriptArgs();
        if (args.length != 2) throw new IllegalArgumentException("Export directory and seed TSV required");
        Path out = Paths.get(args[0]); Files.createDirectories(out);
        FunctionManager fm = currentProgram.getFunctionManager();
        Listing listing = currentProgram.getListing();
        DecompInterface decompiler = new DecompInterface();
        if (!decompiler.openProgram(currentProgram)) throw new IllegalStateException("Decompiler unavailable");
        Set<Address> exports = new LinkedHashSet<>();
        try (PrintWriter seeds = writer(out.resolve("seed-resolution.tsv"))) {
            seeds.println("requested_va\tlabel\tevidence\tresolved_function\tboundary_status\tdecompile_status");
            for (String row : Files.readAllLines(Paths.get(args[1]), StandardCharsets.UTF_8)) {
                if (row.startsWith("address\t") || row.isBlank()) continue;
                String[] cells = row.split("\t", -1);
                Address a = toAddr(cells[0]);
                String label = cells[1];
                setEOLComment(a, cells[2] + "; analysis annotation, not recovered source symbol");
                Function f = fm.getFunctionContaining(a);
                boolean seeded = false;
                if (f == null && !label.startsWith("anchor_")) {
                    // Seed only executable candidates; string-reference anchors are not entries.
                    disassemble(a);
                    f = createFunction(a, label);
                    seeded = f != null;
                }
                if (f == null) {
                    seeds.println(a + "\t" + label + "\t" + clean(cells[2]) + "\t\tunresolved\tnot_attempted");
                    continue;
                }
                boolean exact = f.getEntryPoint().equals(a);
                if (exact && (f.getName().startsWith("FUN_") || f.getName().equals("candidate_Beginner_ctor") || f.getName().startsWith("candidate_Beginner_vslot_"))) {
                    Symbol duplicate = currentProgram.getSymbolTable().getSymbol(label, a, currentProgram.getGlobalNamespace());
                    if (duplicate != null && duplicate.getSymbolType() == SymbolType.LABEL) duplicate.delete();
                    f.setName(label, SourceType.USER_DEFINED);
                }
                if (currentProgram.getSymbolTable().getSymbol(label, a, currentProgram.getGlobalNamespace()) == null) {
                    createLabel(a, label, false, SourceType.USER_DEFINED);
                }
                String status = "already_exported";
                if (exports.add(f.getEntryPoint())) {
                    String stem = f.getEntryPoint().toString();
                    DecompileResults result = decompiler.decompileFunction(f, 90, monitor);
                    status = result.decompileCompleted() ? "completed_unreviewed" : "failed:" + clean(result.getErrorMessage());
                    try (PrintWriter c = writer(out.resolve(stem + ".c"))) {
                        c.println("/* AUTOMATIC DECOMPILER OUTPUT: not validated source; types and calling conventions may be wrong.");
                        c.println(" * Original executable SHA-256: " + expected);
                        c.println(" * Function: " + f.getEntryPoint() + " name: " + f.getName() + " */");
                        if (result.decompileCompleted()) c.println(result.getDecompiledFunction().getC());
                        else c.println("/* " + clean(result.getErrorMessage()) + " */");
                    }
                    try (PrintWriter asm = writer(out.resolve(stem + ".asm"))) {
                        InstructionIterator instructions = listing.getInstructions(f.getBody(), true);
                        while (instructions.hasNext()) {
                            Instruction i = instructions.next();
                            asm.println(i.getAddress() + "\t" + i);
                        }
                    }
                    try (PrintWriter refs = writer(out.resolve(stem + ".references.tsv"))) {
                        refs.println("direction\tfrom\tto\ttype");
                        ReferenceIterator incoming = currentProgram.getReferenceManager().getReferencesTo(f.getEntryPoint());
                        while (incoming.hasNext()) {
                            Reference r = incoming.next();
                            refs.println("incoming\t" + r.getFromAddress() + "\t" + r.getToAddress() + "\t" + r.getReferenceType());
                        }
                        InstructionIterator instructions = listing.getInstructions(f.getBody(), true);
                        while (instructions.hasNext()) {
                            Instruction i = instructions.next();
                            for (Reference r : i.getReferencesFrom()) {
                                if (r.getReferenceType().isCall()) refs.println("call\t" + r.getFromAddress() + "\t" + r.getToAddress() + "\t" + r.getReferenceType());
                            }
                        }
                    }
                }
                seeds.println(a + "\t" + label + "\t" + clean(cells[2]) + "\t" + f.getEntryPoint()
                    + "\t" + (seeded ? "created_from_evidence_seed_unreviewed" : exact ? "matches_analyzer_entry" : "inside_analyzer_function") + "\t" + status);
            }
        } finally { decompiler.dispose(); }
        int count = 0;
        try (PrintWriter index = writer(out.resolve("functions.tsv"))) {
            index.println("entry\tname\tbody_bytes\tcalling_convention\tsignature\tthunk\texternal");
            FunctionIterator functions = fm.getFunctions(true);
            while (functions.hasNext()) {
                Function f = functions.next(); count++;
                index.println(f.getEntryPoint() + "\t" + clean(f.getName()) + "\t" + f.getBody().getNumAddresses()
                    + "\t" + clean(f.getCallingConventionName()) + "\t" + clean(f.getSignature()) + "\t" + f.isThunk() + "\t" + f.isExternal());
            }
        }
        try (PrintWriter metadata = writer(out.resolve("analysis-summary.txt"))) {
            metadata.println("executable_sha256=" + expected);
            metadata.println("language=" + currentProgram.getLanguageID());
            metadata.println("compiler_spec=" + currentProgram.getCompilerSpec().getCompilerSpecID());
            metadata.println("image_base=" + currentProgram.getImageBase());
            metadata.println("analyzer_function_count=" + count);
            metadata.println("exported_function_count=" + exports.size());
            metadata.println("Automatic boundaries, signatures and inferred types require manual validation.");
        }
        println("HAMSTERBALL_EXPORT_OK functions=" + count + " exports=" + exports.size());
    }
}
