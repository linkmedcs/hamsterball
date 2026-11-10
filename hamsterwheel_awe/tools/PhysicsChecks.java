package com.hamsterwheel.awe;

/** Host JVM checks for the actual Android Physics implementation. */
public final class PhysicsChecks {
    static void check(boolean condition,String name){if(!condition)throw new AssertionError(name);}
    static Scene floor(boolean goal){
        Scene scene=new Scene();
        Scene.Marker spawn=new Scene.Marker();spawn.name="START1-1";scene.markers.add(spawn);
        Scene.Group group=new Scene.Group();group.collidable=true;group.goal=goal;
        group.vertices=new float[]{
            -1000,0,-1000,0,1,0,0,0, -1000,0,1000,0,1,0,0,0, 1000,0,1000,0,1,0,0,0,
            -1000,0,-1000,0,1,0,0,0, 1000,0,1000,0,1,0,0,0, 1000,0,-1000,0,1,0,0,0};
        scene.groups.add(group);return scene;
    }
    public static void main(String[] args){
        Physics p=new Physics(floor(false),60);
        for(int i=0;i<600;i++)p.tick(0,0);
        check(Math.abs(p.y-25)<.01f,"sphere must settle at its radius");
        check(p.falls==0&&p.grounded,"stable floor contact");
        for(int i=0;i<120;i++)p.tick(1,0);
        check(p.x>100,"input accelerates the sphere");
        check(p.vx<=360.01f,"speed cap");
        p.y=-1000;p.tick(0,0);
        check(p.falls==1&&p.x==p.checkpointX,"fall respawns at checkpoint");
        p=new Physics(floor(true),60);
        for(int i=0;i<120;i++)p.tick(0,0);
        check(p.won,"original goal material completes course on contact");
        p=new Physics(floor(false),.02f);
        for(int i=0;i<10;i++)p.tick(0,0);
        check(p.timedOut,"countdown ends course");
        float[] out=new float[3];
        Physics.nearest(new float[]{0,0,0,100,0,0,0,0,100},20,40,20,out);
        check(Math.abs(out[0]-20)<.001&&out[1]==0&&Math.abs(out[2]-20)<.001,"triangle interior nearest point");
        Physics.nearest(new float[]{0,0,0,100,0,0,0,0,100},-20,40,-20,out);
        check(out[0]==0&&out[1]==0&&out[2]==0,"triangle vertex nearest point");
        System.out.println("Physics checks passed: floor, input, speed cap, fall, goal, timeout, nearest point.");
    }
}
