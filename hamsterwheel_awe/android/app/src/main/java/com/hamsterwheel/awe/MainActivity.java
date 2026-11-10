package com.hamsterwheel.awe;

import android.app.*;
import android.content.*;
import android.graphics.*;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.*;
import android.widget.*;
import org.json.*;

public final class MainActivity extends Activity {
    GLSurfaceView surface;
    GameRenderer game;
    JSONArray races;
    boolean userPaused;

    @Override public void onCreate(Bundle state){
        super.onCreate(state);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        getWindow().getDecorView().setSystemUiVisibility(View.SYSTEM_UI_FLAG_FULLSCREEN|
            View.SYSTEM_UI_FLAG_HIDE_NAVIGATION|View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY|
            View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN|View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION|View.SYSTEM_UI_FLAG_LAYOUT_STABLE);
        try{
            races=new JSONArray(new String(Scene.bytes(getAssets(),"races.json"),"UTF-8"));
            game=new GameRenderer(getAssets(),races);
            game.requestedRace=Math.max(0,Math.min(races.length()-1,getIntent().getIntExtra("course",0)));
            userPaused=getIntent().getBooleanExtra("paused",false);
            game.paused=userPaused;
            game.trace=getIntent().getBooleanExtra("trace",false);
            FrameLayout frame=new FrameLayout(this);
            surface=new GLSurfaceView(this);surface.setEGLContextClientVersion(2);
            surface.setEGLConfigChooser(8,8,8,8,24,0);
            surface.setPreserveEGLContextOnPause(true);surface.setRenderer(game);
            frame.addView(surface);
            frame.addView(new Controls(this));
            setContentView(frame);
        }catch(Exception e){TextView error=new TextView(this);error.setText(e.toString());setContentView(error);}
    }

    void chooseCourse(){
        game.paused=true;game.inputX=game.inputY=0;
        String[] names=new String[races.length()];
        for(int i=0;i<names.length;i++)names[i]=String.format(java.util.Locale.ROOT,"%02d  %s",i+1,races.optJSONObject(i).optString("title"));
        AlertDialog dialog=new AlertDialog.Builder(this).setTitle("Choose original course")
            .setSingleChoiceItems(names,game.requestedRace,(d,which)->{
                game.requestedRace=which;game.restart=true;userPaused=false;d.dismiss();
            }).setNegativeButton("Cancel",null).create();
        dialog.setOnDismissListener(d->game.paused=userPaused);dialog.show();
    }

    @Override protected void onPause(){super.onPause();if(game!=null){game.paused=true;game.inputX=game.inputY=0;surface.onPause();}}
    @Override protected void onResume(){super.onResume();if(game!=null){game.paused=userPaused;surface.onResume();}}

    final class Controls extends View {
        final Paint paint=new Paint(Paint.ANTI_ALIAS_FLAG);
        final RectF courses=new RectF(),reset=new RectF(),pause=new RectF();
        float scale,cx,cy,radius=66,stickX,stickY;
        int joystick=-1,orbit=-1;
        float orbitX;
        Controls(Context context){super(context);setLayerType(View.LAYER_TYPE_SOFTWARE,null);}

        void text(Canvas canvas,String text,float x,float y,float size,int color){
            paint.setColor(color);paint.setTextSize(size);paint.setTypeface(Typeface.create("sans-serif-medium",Typeface.NORMAL));canvas.drawText(text,x,y,paint);
        }
        void button(Canvas canvas,RectF box,String label){
            paint.setColor(0xc920293b);canvas.drawRoundRect(box,12,12,paint);
            paint.setTextSize(16);float width=paint.measureText(label);
            text(canvas,label,box.centerX()-width/2,box.centerY()+6,16,Color.WHITE);
        }
        @Override protected void onDraw(Canvas real){
            super.onDraw(real);
            scale=Math.max(.1f,getHeight()/540f);
            Canvas canvas=real;canvas.save();canvas.scale(scale,scale);
            float w=getWidth()/scale,h=getHeight()/scale;
            cx=100;cy=h-100;
            paint.setColor(0xcc111a29);canvas.drawRoundRect(18,18,332,100,18,18,paint);
            text(canvas,"HAMSTERWHEEL AWE",34,45,13,0xff9dc3ff);
            text(canvas,game.status,34,76,23,Color.WHITE);
            courses.set(w-316,22,w-220,66);reset.set(w-210,22,w-114,66);pause.set(w-104,22,w-18,66);
            button(canvas,courses,"Courses");button(canvas,reset,"Restart");button(canvas,pause,userPaused?"Resume":"Pause");
            paint.setColor(0xb2111a29);canvas.drawRoundRect(w/2-90,20,w/2+90,89,18,18,paint);
            String time=String.format(java.util.Locale.ROOT,"%05.1f",game.remaining);
            text(canvas,time,w/2-53,64,34,game.remaining<10?0xffffaa83:Color.WHITE);
            text(canvas,"RESPAWNS "+game.falls,34,123,13,0xffe4dcf4);
            paint.setColor(0x50142238);canvas.drawCircle(cx,cy,radius,paint);
            paint.setColor(0x70d5e6ff);paint.setStyle(Paint.Style.STROKE);paint.setStrokeWidth(2);canvas.drawCircle(cx,cy,radius,paint);paint.setStyle(Paint.Style.FILL);
            paint.setColor(0xb0e1ebff);canvas.drawCircle(cx+stickX*radius,cy+stickY*radius,25,paint);
            text(canvas,"ROLL",cx-18,cy+radius+27,12,0xffe0e5ef);
            text(canvas,"Drag right side to orbit",w-240,h-35,14,0xffe0e5ef);
            if(userPaused||game.won||game.timedOut){
                paint.setColor(0xd5111a29);canvas.drawRoundRect(w/2-195,h/2-62,w/2+195,h/2+62,24,24,paint);
                String title=game.won?"COURSE COMPLETE":game.timedOut?"TIME UP":"PAUSED";
                paint.setTextSize(26);float width=paint.measureText(title);
                text(canvas,title,w/2-width/2,h/2-3,26,Color.WHITE);
                text(canvas,game.won||game.timedOut?"Restart or choose another course":"Tap Resume to continue",w/2-145,h/2+29,16,0xffbbd5ff);
            }
            canvas.restore();postInvalidateOnAnimation();
        }

        @Override public boolean onTouchEvent(MotionEvent e){
            int action=e.getActionMasked(),index=e.getActionIndex(),id=e.getPointerId(index);
            float x=e.getX(index)/scale,y=e.getY(index)/scale;
            if(action==MotionEvent.ACTION_DOWN||action==MotionEvent.ACTION_POINTER_DOWN){
                if(courses.contains(x,y)){chooseCourse();return true;}
                if(reset.contains(x,y)){userPaused=false;game.paused=false;game.restart=true;return true;}
                if(pause.contains(x,y)){userPaused=!userPaused;game.paused=userPaused;return true;}
                if(x<getWidth()/scale*.45f&&joystick<0){joystick=id;updateStick(x,y);}
                else if(orbit<0){orbit=id;orbitX=x;}
            }else if(action==MotionEvent.ACTION_MOVE){
                for(int i=0;i<e.getPointerCount();i++){
                    if(e.getPointerId(i)==joystick)updateStick(e.getX(i)/scale,e.getY(i)/scale);
                    if(e.getPointerId(i)==orbit){float next=e.getX(i)/scale;game.orbit((orbitX-next)*.008f);orbitX=next;}
                }
            }else if(action==MotionEvent.ACTION_UP||action==MotionEvent.ACTION_POINTER_UP){
                if(id==joystick){joystick=-1;stickX=stickY=0;game.inputX=game.inputY=0;}
                if(id==orbit)orbit=-1;
            }else if(action==MotionEvent.ACTION_CANCEL){
                joystick=orbit=-1;stickX=stickY=0;game.inputX=game.inputY=0;
            }
            return true;
        }
        void updateStick(float x,float y){
            stickX=(x-cx)/radius;stickY=(y-cy)/radius;
            float len=(float)Math.hypot(stickX,stickY);if(len>1){stickX/=len;stickY/=len;}
            game.inputX=Math.abs(stickX)<.08f?0:stickX;game.inputY=Math.abs(stickY)<.08f?0:stickY;
        }
    }
}
