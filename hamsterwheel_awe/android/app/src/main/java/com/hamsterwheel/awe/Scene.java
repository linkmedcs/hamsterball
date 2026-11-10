package com.hamsterwheel.awe;

import android.content.res.AssetManager;
import org.json.*;
import java.io.*;
import java.nio.*;
import java.util.*;

final class Scene {
    static final class Group {
        String name, texture;
        float[] color, vertices;
        int count, buffer;
        boolean visible, collidable, goal;
    }
    static final class Marker {
        String name;
        float x, y, z;
    }
    final ArrayList<Group> groups = new ArrayList<>();
    final ArrayList<Marker> markers = new ArrayList<>();
    float[] background = {.12f, .14f, .2f};
    float ambient = .45f;

    static byte[] bytes(AssetManager assets, String file) throws IOException {
        try (InputStream input = assets.open(file); ByteArrayOutputStream out = new ByteArrayOutputStream()) {
            byte[] block = new byte[16384];
            int n;
            while ((n = input.read(block)) != -1) out.write(block, 0, n);
            return out.toByteArray();
        }
    }

    static Scene load(AssetManager assets, String file) throws Exception {
        ByteBuffer input = ByteBuffer.wrap(bytes(assets, file)).order(ByteOrder.LITTLE_ENDIAN);
        if (input.getInt() != 0x31415748) throw new IOException("Invalid scene signature");
        int length = input.getInt();
        if (length < 0 || length > input.remaining()) throw new IOException("Invalid scene header");
        byte[] json = new byte[length]; input.get(json);
        JSONObject meta = new JSONObject(new String(json, "UTF-8"));
        Scene scene = new Scene();
        JSONArray env = meta.getJSONArray("environment");
        for (int i = 0; i < 3; i++) scene.background[i] = (float) env.getDouble(i);
        scene.ambient = Math.max(.32f, (float)env.getDouble(3));
        JSONArray markers = meta.getJSONArray("markers");
        for (int i = 0; i < markers.length(); i++) {
            JSONObject obj = markers.getJSONObject(i);
            Marker m = new Marker(); m.name = obj.getString("name");
            JSONArray p = obj.getJSONArray("position");
            m.x = (float)p.getDouble(0); m.y = (float)p.getDouble(1); m.z = (float)p.getDouble(2);
            scene.markers.add(m);
        }
        JSONArray groups = meta.getJSONArray("groups");
        for (int i = 0; i < groups.length(); i++) {
            JSONObject obj = groups.getJSONObject(i);
            Group group = new Group(); group.name = obj.getString("name");
            group.texture = obj.getString("texture"); group.count = obj.getInt("count");
            if (group.count < 0 || group.count % 3 != 0 || (long)group.count*32 > input.remaining())
                throw new IOException("Invalid scene geometry");
            group.color = new float[4];
            for (int j = 0; j < 4; j++) group.color[j] = (float)obj.getJSONArray("color").getDouble(j);
            group.vertices = new float[group.count*8]; input.asFloatBuffer().get(group.vertices);
            input.position(input.position()+group.count*32);
            String tag = group.name.toUpperCase(Locale.ROOT);
            group.visible = !tag.startsWith("E:");
            group.collidable = group.visible && !tag.contains("NOCOLLIDE");
            group.goal = tag.startsWith("N:GOAL");
            scene.groups.add(group);
        }
        if (input.hasRemaining()) throw new IOException("Unexpected scene trailer");
        return scene;
    }
}
