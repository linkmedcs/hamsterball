package com.hamsterwheel.awe;

import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.opengl.*;
import android.util.Log;
import org.json.*;
import java.nio.*;
import java.util.*;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

final class GameRenderer implements GLSurfaceView.Renderer {
    static final String TAG="Hamsterwheel";
    final AssetManager assets;
    final JSONArray races;
    volatile float inputX,inputY;
    volatile boolean paused;
    volatile int requestedRace=0;
    volatile boolean restart;
    boolean trace;
    long lastTrace;
    volatile String status="Loading original course…";
    volatile float remaining=60;
    volatile int falls;
    volatile boolean won,timedOut;
    private float pendingYaw;
    Scene course,ball,hamster;
    Physics physics;
    final HashMap<String,Integer> textures=new HashMap<>();
    final float[] projection=new float[16],view=new float[16],model=new float[16];
    final float[] mv=new float[16],mvp=new float[16],rotation=new float[16],scratch=new float[16];
    int program,aPosition,aNormal,aUV,uMVP,uModel,uColor,uTexture,uTextured,uAmbient;
    int currentRace=-1;
    long previous;
    float accumulator,yaw=0,cameraX,cameraY,cameraZ;
    boolean cameraReady;
    boolean failed;

    GameRenderer(AssetManager assets,JSONArray races){this.assets=assets;this.races=races;}
    synchronized void orbit(float delta){pendingYaw+=delta;}
    synchronized float consumeYaw(){float value=pendingYaw;pendingYaw=0;return value;}

    @Override public void onSurfaceCreated(GL10 gl,EGLConfig config){
        try {
            program=createProgram(
                "uniform mat4 uMVP; uniform mat4 uModel; attribute vec3 aPosition; attribute vec3 aNormal; attribute vec2 aUV; varying vec2 vUV; varying vec3 vNormal; void main(){vUV=aUV;vNormal=mat3(uModel)*aNormal;gl_Position=uMVP*vec4(aPosition,1.0);}",
                "precision mediump float; uniform sampler2D uTexture; uniform vec4 uColor; uniform float uTextured; uniform float uAmbient; varying vec2 vUV; varying vec3 vNormal; void main(){vec4 tex=mix(vec4(1.0),texture2D(uTexture,vUV),uTextured); vec4 col=tex*uColor; if(col.a<0.03)discard; float light=uAmbient+(1.0-uAmbient)*abs(dot(normalize(vNormal),normalize(vec3(-0.3,0.9,0.4))));gl_FragColor=vec4(col.rgb*light,col.a);}");
            aPosition=GLES20.glGetAttribLocation(program,"aPosition");
            aNormal=GLES20.glGetAttribLocation(program,"aNormal");
            aUV=GLES20.glGetAttribLocation(program,"aUV");
            uMVP=GLES20.glGetUniformLocation(program,"uMVP");
            uModel=GLES20.glGetUniformLocation(program,"uModel");
            uColor=GLES20.glGetUniformLocation(program,"uColor");
            uTexture=GLES20.glGetUniformLocation(program,"uTexture");
            uTextured=GLES20.glGetUniformLocation(program,"uTextured");
            uAmbient=GLES20.glGetUniformLocation(program,"uAmbient");
            textures.clear();
            ball=Scene.load(assets,"models/sphere.hwa");upload(ball);
            for(Scene.Group group:ball.groups)group.color[3]=.22f;
            hamster=Scene.load(assets,"models/hamster-waiting.hwa");upload(hamster);
            currentRace=-1;course=null;failed=false;restart=false;
            GLES20.glEnable(GLES20.GL_DEPTH_TEST);
            GLES20.glEnable(GLES20.GL_BLEND);
            GLES20.glBlendFunc(GLES20.GL_SRC_ALPHA,GLES20.GL_ONE_MINUS_SRC_ALPHA);
            Matrix.setIdentityM(rotation,0);
            Log.i(TAG,"OpenGL ready: "+GLES20.glGetString(GLES20.GL_RENDERER));
        }catch(Exception error){fail(error);}
    }

    @Override public void onSurfaceChanged(GL10 gl,int width,int height){
        GLES20.glViewport(0,0,width,height);
        Matrix.perspectiveM(projection,0,48f,width/(float)Math.max(1,height),5,16000);
    }

    private void loadRace(int index)throws Exception{
        Scene next=Scene.load(assets,"scenes/"+races.getJSONObject(index).getString("id")+".hwa");
        Physics nextPhysics=new Physics(next,(float)races.getJSONObject(index).getJSONObject("parameters").getDouble("TIME"));
        release(course);course=next;physics=nextPhysics;upload(course);
        currentRace=index;restart=false;accumulator=0;previous=System.nanoTime();
        cameraReady=false;Matrix.setIdentityM(rotation,0);
        status=races.getJSONObject(index).getString("title");
        won=timedOut=false;
        Log.i(TAG,"Course loaded: "+status+", "+course.groups.size()+" material groups, "+course.markers.size()+" markers");
    }

    @Override public void onDrawFrame(GL10 gl){
        if(failed){GLES20.glClearColor(.15f,.02f,.02f,1);GLES20.glClear(GLES20.GL_COLOR_BUFFER_BIT);return;}
        try{
            int requested=requestedRace;
            if(currentRace!=requested||restart)loadRace(requested);
            long now=System.nanoTime();
            float dt=Math.min(.05f,(now-previous)/1e9f);previous=now;
            yaw+=consumeYaw();
            float oldX=physics.x,oldZ=physics.z;
            if(!paused){
                accumulator+=dt;
                float c=(float)Math.cos(yaw),s=(float)Math.sin(yaw);
                while(accumulator>=Physics.STEP){
                    physics.tick(inputX*c+inputY*s,-inputX*s+inputY*c);
                    accumulator-=Physics.STEP;
                }
            }else accumulator=0;
            float dx=physics.x-oldX,dz=physics.z-oldZ;
            float distance=(float)Math.hypot(dx,dz);
            if(distance>.0001&&distance<100){
                Matrix.setRotateM(scratch,0,(float)Math.toDegrees(distance/Physics.RADIUS),dz,0,-dx);
                Matrix.multiplyMM(model,0,scratch,0,rotation,0);
                System.arraycopy(model,0,rotation,0,16);
            }
            remaining=Math.max(0,physics.limit-physics.elapsed);falls=physics.falls;
            won=physics.won;timedOut=physics.timedOut;
            if(trace && now-lastTrace>1_000_000_000L){
                lastTrace=now;
                Log.i(TAG,"STATE x="+physics.x+" y="+physics.y+" z="+physics.z+
                    " grounded="+physics.grounded+" falls="+falls+" input="+inputX+","+inputY);
            }
            GLES20.glClearColor(course.background[0],course.background[1],course.background[2],1);
            GLES20.glClear(GLES20.GL_COLOR_BUFFER_BIT|GLES20.GL_DEPTH_BUFFER_BIT);
            GLES20.glUseProgram(program);
            float tx=physics.x+(float)Math.sin(yaw)*430,ty=physics.y+340,tz=physics.z+(float)Math.cos(yaw)*430;
            float smooth=cameraReady?1-(float)Math.exp(-dt*8):1;
            cameraX+=(tx-cameraX)*smooth;cameraY+=(ty-cameraY)*smooth;cameraZ+=(tz-cameraZ)*smooth;cameraReady=true;
            Matrix.setLookAtM(view,0,cameraX,cameraY,cameraZ,physics.x,physics.y-5,physics.z,0,1,0);
            Matrix.setIdentityM(model,0);draw(course,model,course.ambient);
            Matrix.setIdentityM(model,0);Matrix.translateM(model,0,physics.x,physics.y,physics.z);
            if(Math.hypot(physics.vx,physics.vz)>5)
                Matrix.rotateM(model,0,(float)Math.toDegrees(Math.atan2(physics.vx,physics.vz)),0,1,0);
            draw(hamster,model,.7f);
            Matrix.setIdentityM(scratch,0);Matrix.translateM(scratch,0,physics.x,physics.y,physics.z);
            Matrix.multiplyMM(model,0,scratch,0,rotation,0);
            GLES20.glDepthMask(false);draw(ball,model,.8f);GLES20.glDepthMask(true);
        }catch(Exception error){fail(error);}
    }

    private void fail(Exception error){
        failed=true;status="Load error: "+error.getMessage();Log.e(TAG,status,error);
    }

    private void upload(Scene scene)throws Exception{
        for(Scene.Group g:scene.groups){
            if(!g.visible)continue;
            int[] id=new int[1];GLES20.glGenBuffers(1,id,0);g.buffer=id[0];
            FloatBuffer data=ByteBuffer.allocateDirect(g.vertices.length*4).order(ByteOrder.nativeOrder()).asFloatBuffer();
            data.put(g.vertices).position(0);
            GLES20.glBindBuffer(GLES20.GL_ARRAY_BUFFER,g.buffer);
            GLES20.glBufferData(GLES20.GL_ARRAY_BUFFER,g.vertices.length*4,data,GLES20.GL_STATIC_DRAW);
            texture(g.texture);
        }
        GLES20.glBindBuffer(GLES20.GL_ARRAY_BUFFER,0);
    }

    private void release(Scene scene){
        if(scene==null)return;
        for(Scene.Group group:scene.groups)if(group.buffer!=0)GLES20.glDeleteBuffers(1,new int[]{group.buffer},0);
    }

    private int texture(String name)throws Exception{
        if(textures.containsKey(name))return textures.get(name);
        Bitmap image;
        if(name.isEmpty()){
            image=Bitmap.createBitmap(1,1,Bitmap.Config.ARGB_8888);image.eraseColor(Color.WHITE);
        }else{
            try(java.io.InputStream stream=assets.open("textures/"+name)){
                image=BitmapFactory.decodeStream(stream);
            }
            if(image==null)throw new java.io.IOException("Unsupported texture: "+name);
        }
        // GLES 2.0 repeat needs power-of-two textures on all supported devices.
        int w=1,h=1;while(w<image.getWidth())w*=2;while(h<image.getHeight())h*=2;
        if(w!=image.getWidth()||h!=image.getHeight()){
            Bitmap resized=Bitmap.createScaledBitmap(image,w,h,true);image.recycle();image=resized;
        }
        int[] id=new int[1];GLES20.glGenTextures(1,id,0);
        GLES20.glBindTexture(GLES20.GL_TEXTURE_2D,id[0]);
        GLES20.glTexParameteri(GLES20.GL_TEXTURE_2D,GLES20.GL_TEXTURE_MIN_FILTER,GLES20.GL_LINEAR);
        GLES20.glTexParameteri(GLES20.GL_TEXTURE_2D,GLES20.GL_TEXTURE_MAG_FILTER,GLES20.GL_LINEAR);
        GLES20.glTexParameteri(GLES20.GL_TEXTURE_2D,GLES20.GL_TEXTURE_WRAP_S,GLES20.GL_REPEAT);
        GLES20.glTexParameteri(GLES20.GL_TEXTURE_2D,GLES20.GL_TEXTURE_WRAP_T,GLES20.GL_REPEAT);
        GLUtils.texImage2D(GLES20.GL_TEXTURE_2D,0,image,0);image.recycle();
        textures.put(name,id[0]);return id[0];
    }

    private void draw(Scene scene,float[] transform,float ambient)throws Exception{
        Matrix.multiplyMM(mv,0,view,0,transform,0);Matrix.multiplyMM(mvp,0,projection,0,mv,0);
        GLES20.glUniformMatrix4fv(uMVP,1,false,mvp,0);
        GLES20.glUniformMatrix4fv(uModel,1,false,transform,0);
        GLES20.glUniform1f(uAmbient,ambient);
        GLES20.glUniform1i(uTexture,0);GLES20.glActiveTexture(GLES20.GL_TEXTURE0);
        for(Scene.Group group:scene.groups){
            if(!group.visible)continue;
            GLES20.glBindBuffer(GLES20.GL_ARRAY_BUFFER,group.buffer);
            GLES20.glEnableVertexAttribArray(aPosition);GLES20.glEnableVertexAttribArray(aNormal);GLES20.glEnableVertexAttribArray(aUV);
            GLES20.glVertexAttribPointer(aPosition,3,GLES20.GL_FLOAT,false,32,0);
            GLES20.glVertexAttribPointer(aNormal,3,GLES20.GL_FLOAT,false,32,12);
            GLES20.glVertexAttribPointer(aUV,2,GLES20.GL_FLOAT,false,32,24);
            GLES20.glUniform4fv(uColor,1,group.color,0);
            GLES20.glUniform1f(uTextured,group.texture.isEmpty()?0:1);
            GLES20.glBindTexture(GLES20.GL_TEXTURE_2D,texture(group.texture));
            boolean decal=group.name.toUpperCase(Locale.ROOT).contains("NOCOLLIDE");
            if(decal){GLES20.glEnable(GLES20.GL_POLYGON_OFFSET_FILL);GLES20.glPolygonOffset(-2,-2);}
            GLES20.glDrawArrays(GLES20.GL_TRIANGLES,0,group.count);
            if(decal)GLES20.glDisable(GLES20.GL_POLYGON_OFFSET_FILL);
        }
        GLES20.glBindBuffer(GLES20.GL_ARRAY_BUFFER,0);
    }

    private int shader(int type,String source){
        int shader=GLES20.glCreateShader(type);GLES20.glShaderSource(shader,source);GLES20.glCompileShader(shader);
        int[] compiled=new int[1];GLES20.glGetShaderiv(shader,GLES20.GL_COMPILE_STATUS,compiled,0);
        if(compiled[0]==0)throw new IllegalStateException(GLES20.glGetShaderInfoLog(shader));
        return shader;
    }
    private int createProgram(String vs,String fs){
        int v=shader(GLES20.GL_VERTEX_SHADER,vs),f=shader(GLES20.GL_FRAGMENT_SHADER,fs);
        int result=GLES20.glCreateProgram();GLES20.glAttachShader(result,v);GLES20.glAttachShader(result,f);GLES20.glLinkProgram(result);
        int[] linked=new int[1];GLES20.glGetProgramiv(result,GLES20.GL_LINK_STATUS,linked,0);
        GLES20.glDeleteShader(v);GLES20.glDeleteShader(f);
        if(linked[0]==0)throw new IllegalStateException(GLES20.glGetProgramInfoLog(result));
        return result;
    }
}
