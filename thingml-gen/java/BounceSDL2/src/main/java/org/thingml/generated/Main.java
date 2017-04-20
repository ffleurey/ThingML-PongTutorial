/**
 * File generated by the ThingML IDE
 * /!\Do not edit this file/!\
 * In case of a bug in the generated code,
 * please submit an issue on our GitHub
 **/

package org.thingml.generated;

import org.thingml.java.*;
import org.thingml.java.ext.*;

import org.thingml.generated.api.*;
import org.thingml.generated.messages.*;

import java.util.*;
public class Main {
//Things
public static Java2DDisplay Java2DDisplay_disp;
public static BouncingBall BouncingBall_bb;
public static TimerJava TimerJava_timer;
public static void main(String args[]) {
//Things
Java2DDisplay_disp = (Java2DDisplay) new Java2DDisplay("disp (Java2DDisplay)", (int)0, (int) (5), (int)0).buildBehavior(null, null);
BouncingBall_bb = (BouncingBall) new BouncingBall("bb (BouncingBall)", (int) (10000), (int) (200), (int) (128), (int) (200), (int) (10000 / 2), (int) (10000 / 2), (int) (160), (int) (200), (int) (130)).buildBehavior(null, null);
TimerJava_timer = (TimerJava) new TimerJava("timer (TimerJava)").buildBehavior(null, null);
//Connecting internal ports...
//Connectors
TimerJava_timer.getTimer_port().addListener(BouncingBall_bb.getClock_port());
BouncingBall_bb.getClock_port().addListener(TimerJava_timer.getTimer_port());
Java2DDisplay_disp.getDisplay_port().addListener(BouncingBall_bb.getDisplay_port());
BouncingBall_bb.getDisplay_port().addListener(Java2DDisplay_disp.getDisplay_port());
//Init instances (queues, etc)
Java2DDisplay_disp.init();
BouncingBall_bb.init();
TimerJava_timer.init();
//Network components for external connectors
/*$NETWORK$*/
//External Connectors
/*$EXT CONNECTORS$*/
/*$START$*/
Java2DDisplay_disp.start();
TimerJava_timer.start();
BouncingBall_bb.start();
//Hook to stop instances following client/server dependencies (clients firsts)
Runtime.getRuntime().addShutdownHook(new Thread() {
public void run() {
BouncingBall_bb.stop();
TimerJava_timer.stop();
Java2DDisplay_disp.stop();
/*$STOP$*/
}
});

}
}
