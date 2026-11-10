package com.hamsterwheel.awe;

import java.util.*;

/** Fixed-step sphere / original triangle collision, with an XZ broad phase. */
final class Physics {
    static final float RADIUS = 25f, STEP = 1f/120f, CELL = 160f;
    static final class Triangle {
        final float[] p = new float[9];
        final boolean goal;
        Triangle(float[] vertices, int offset, boolean goal) {
            for (int i=0;i<3;i++) System.arraycopy(vertices, offset+i*8, p, i*3, 3);
            this.goal = goal;
        }
    }
    final HashMap<Long, ArrayList<Triangle>> grid = new HashMap<>();
    final ArrayList<Triangle> large = new ArrayList<>();
    final ArrayList<Scene.Marker> safe = new ArrayList<>();
    final HashSet<Triangle> candidates = new HashSet<>();
    final float[] point = new float[3];
    float x,y,z,vx,vy,vz, checkpointX,checkpointY,checkpointZ;
    float elapsed, limit=60, travel;
    boolean won, timedOut, grounded;
    int falls;

    private long key(int x, int z) { return ((long)x << 32) ^ (z & 0xffffffffL); }
    private int cell(float f) { return (int)Math.floor(f/CELL); }

    Physics(Scene scene, float time) {
        limit=time;
        for (Scene.Marker m:scene.markers) {
            if (m.name.equals("START1-1")) {
                checkpointX=m.x;checkpointY=m.y+RADIUS+1;checkpointZ=m.z;
            }
            if (m.name.toUpperCase(Locale.ROOT).startsWith("SAFE")) safe.add(m);
        }
        for (Scene.Group group:scene.groups) if(group.collidable) {
            for(int i=0;i<group.vertices.length;i+=24) {
                Triangle t=new Triangle(group.vertices,i,group.goal);
                float[] p=t.p;
                float ux=p[3]-p[0],uy=p[4]-p[1],uz=p[5]-p[2];
                float wx=p[6]-p[0],wy=p[7]-p[1],wz=p[8]-p[2];
                float nx=uy*wz-uz*wy,ny=uz*wx-ux*wz,nz=ux*wy-uy*wx;
                if(nx*nx+ny*ny+nz*nz<.0001f)continue;
                int x0=cell(Math.min(p[0],Math.min(p[3],p[6]))-RADIUS);
                int x1=cell(Math.max(p[0],Math.max(p[3],p[6]))+RADIUS);
                int z0=cell(Math.min(p[2],Math.min(p[5],p[8]))-RADIUS);
                int z1=cell(Math.max(p[2],Math.max(p[5],p[8]))+RADIUS);
                if((long)(x1-x0+1)*(z1-z0+1)>1024){large.add(t);continue;}
                for(int a=x0;a<=x1;a++)for(int b=z0;b<=z1;b++)
                    grid.computeIfAbsent(key(a,b),unused->new ArrayList<>()).add(t);
            }
        }
        respawn(false);
    }

    void respawn(boolean count) {
        x=checkpointX;y=checkpointY;z=checkpointZ;vx=vy=vz=0;
        if(count)falls++;
    }

    void tick(float inputX,float inputZ) {
        if(won||timedOut)return;
        elapsed+=STEP;
        if(elapsed>=limit){timedOut=true;return;}
        vx+=inputX*600f*STEP;vz+=inputZ*600f*STEP;
        float speed=(float)Math.hypot(vx,vz);
        if(speed>360){vx*=360/speed;vz*=360/speed;}
        vy-=850*STEP;
        float damping=(float)Math.exp(-(grounded?1.45f:.15f)*STEP);
        vx*=damping;vz*=damping;
        x+=vx*STEP;y+=vy*STEP;z+=vz*STEP;
        travel+=(float)Math.hypot(vx,vz)*STEP;
        grounded=false;
        candidates.clear();
        ArrayList<Triangle> bucket=grid.get(key(cell(x),cell(z)));
        if(bucket!=null)candidates.addAll(bucket);
        candidates.addAll(large);
        for(int pass=0;pass<3;pass++) for(Triangle t:candidates) {
            nearest(t.p,x,y,z,point);
            float dx=x-point[0],dy=y-point[1],dz=z-point[2];
            float d2=dx*dx+dy*dy+dz*dz;
            if(d2>=RADIUS*RADIUS||d2<.000001f)continue;
            float distance=(float)Math.sqrt(d2);
            float nx=dx/distance,ny=dy/distance,nz=dz/distance;
            float correction=RADIUS-distance+.001f;
            x+=nx*correction;y+=ny*correction;z+=nz*correction;
            float dot=vx*nx+vy*ny+vz*nz;
            if(dot<0){vx-=dot*nx;vy-=dot*ny;vz-=dot*nz;}
            if(ny>.45f){grounded=true;if(t.goal)won=true;}
        }
        if(grounded)for(Scene.Marker m:safe){
            float dx=x-m.x,dz=z-m.z;
            if(dx*dx+dz*dz<65*65 && Math.abs(y-m.y-RADIUS)<45){
                checkpointX=m.x;checkpointY=m.y+RADIUS+1;checkpointZ=m.z;break;
            }
        }
        if(y<checkpointY-650)respawn(true);
    }

    // Closest point on a triangle, including edge and vertex Voronoi regions.
    static void nearest(float[] p,float x,float y,float z,float[] out){
        float ax=p[0],ay=p[1],az=p[2],bx=p[3],by=p[4],bz=p[5],cx=p[6],cy=p[7],cz=p[8];
        float ux=bx-ax,uy=by-ay,uz=bz-az,wx=cx-ax,wy=cy-ay,wz=cz-az;
        float qx=x-ax,qy=y-ay,qz=z-az;
        float d1=ux*qx+uy*qy+uz*qz,d2=wx*qx+wy*qy+wz*qz;
        if(d1<=0&&d2<=0){set(out,ax,ay,az);return;}
        qx=x-bx;qy=y-by;qz=z-bz;
        float d3=ux*qx+uy*qy+uz*qz,d4=wx*qx+wy*qy+wz*qz;
        if(d3>=0&&d4<=d3){set(out,bx,by,bz);return;}
        float vc=d1*d4-d3*d2;
        if(vc<=0&&d1>=0&&d3<=0){float v=d1/(d1-d3);set(out,ax+v*ux,ay+v*uy,az+v*uz);return;}
        qx=x-cx;qy=y-cy;qz=z-cz;
        float d5=ux*qx+uy*qy+uz*qz,d6=wx*qx+wy*qy+wz*qz;
        if(d6>=0&&d5<=d6){set(out,cx,cy,cz);return;}
        float vb=d5*d2-d1*d6;
        if(vb<=0&&d2>=0&&d6<=0){float w=d2/(d2-d6);set(out,ax+w*wx,ay+w*wy,az+w*wz);return;}
        float va=d3*d6-d5*d4;
        if(va<=0&&d4-d3>=0&&d5-d6>=0){float w=(d4-d3)/(d4-d3+d5-d6);set(out,bx+w*(cx-bx),by+w*(cy-by),bz+w*(cz-bz));return;}
        float inverse=1/(va+vb+vc),v=vb*inverse,w=vc*inverse;
        set(out,ax+ux*v+wx*w,ay+uy*v+wy*w,az+uz*v+wz*w);
    }
    static void set(float[] out,float x,float y,float z){out[0]=x;out[1]=y;out[2]=z;}
}
