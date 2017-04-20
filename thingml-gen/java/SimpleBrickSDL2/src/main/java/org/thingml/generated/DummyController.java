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

/**
 * Definition for type : DummyController
 **/
public class DummyController extends Component implements IDummyController_clock {

private List<AttributeListener> attListener = new ArrayList<AttributeListener>();
public void addAttributeListener(AttributeListener listener){
this.attListener.add(listener);
}

public void removeAttributeListener(AttributeListener listener){
this.attListener.remove(listener);
}

private boolean debug = false;
public boolean isDebug() {return debug;}
public void setDebug(boolean debug) {this.debug = debug;}
@Override
public String toString() {
String result = "instance " + getName() + "\n";
result += "\ttimerID = " + DummyController_timerID_var;
result += "\tXMAX = " + DummyController_XMAX_var;
result += "\tYMAX = " + DummyController_YMAX_var;
result += "\tXMIN = " + DummyController_XMIN_var;
result += "\tYMIN = " + DummyController_YMIN_var;
result += "\tposX = " + DummyController_posX_var;
result += "\tposY = " + DummyController_posY_var;
result += "\tdx = " + DummyController_dx_var;
result += "\tdy = " + DummyController_dy_var;
result += "";
return result;
}

private Collection<IDummyController_clockClient> clock_clients = Collections.synchronizedCollection(new LinkedList<IDummyController_clockClient>());
public synchronized void registerOnClock(IDummyController_clockClient client){
clock_clients.add(client);
}

public synchronized void unregisterFromClock(IDummyController_clockClient client){
clock_clients.remove(client);
}

private Collection<IDummyController_controlsClient> controls_clients = Collections.synchronizedCollection(new LinkedList<IDummyController_controlsClient>());
public synchronized void registerOnControls(IDummyController_controlsClient client){
controls_clients.add(client);
}

public synchronized void unregisterFromControls(IDummyController_controlsClient client){
controls_clients.remove(client);
}

@Override
public synchronized void timer_timeout_via_clock(int TimerMsgs_timer_timeout_id_var){
receive(timer_timeoutType.instantiate(TimerMsgs_timer_timeout_id_var), clock_port);
}

private void sendTimer_start_via_clock(int TimerMsgs_timer_start_id_var, int TimerMsgs_timer_start_time_var){
//ThingML send
clock_port.send(timer_startType.instantiate(TimerMsgs_timer_start_id_var, TimerMsgs_timer_start_time_var));
//send to other clients
for(IDummyController_clockClient client : clock_clients){
client.timer_start_from_clock(TimerMsgs_timer_start_id_var, TimerMsgs_timer_start_time_var);
}}

private void sendTimer_cancel_via_clock(int TimerMsgs_timer_cancel_id_var){
//ThingML send
clock_port.send(timer_cancelType.instantiate(TimerMsgs_timer_cancel_id_var));
//send to other clients
for(IDummyController_clockClient client : clock_clients){
client.timer_cancel_from_clock(TimerMsgs_timer_cancel_id_var);
}}

private void sendPosition_via_controls(int ControllerMsgs_position_x_var, int ControllerMsgs_position_y_var){
//ThingML send
controls_port.send(positionType.instantiate(ControllerMsgs_position_x_var, ControllerMsgs_position_y_var));
//send to other clients
for(IDummyController_controlsClient client : controls_clients){
client.position_from_controls(ControllerMsgs_position_x_var, ControllerMsgs_position_y_var);
}}

private void sendFire_via_controls(){
//ThingML send
controls_port.send(fireType.instantiate());
//send to other clients
for(IDummyController_controlsClient client : controls_clients){
client.fire_from_controls();
}}

//Attributes
private int DummyController_posY_var;
private final int DummyController_YMIN_var;
private final int DummyController_timerID_var;
private int DummyController_posX_var;
private int DummyController_dy_var;
private final int DummyController_XMAX_var;
private final int DummyController_XMIN_var;
private final int DummyController_YMAX_var;
private int DummyController_dx_var;
private int debug_DummyController_posY_var;
private int debug_DummyController_YMIN_var;
private int debug_DummyController_timerID_var;
private int debug_DummyController_posX_var;
private int debug_DummyController_dy_var;
private int debug_DummyController_XMAX_var;
private int debug_DummyController_XMIN_var;
private int debug_DummyController_YMAX_var;
private int debug_DummyController_dx_var;
//Ports
private Port clock_port;
private Port controls_port;
//Message types
protected final PositionMessageType positionType = new PositionMessageType();
public PositionMessageType getPositionType(){
return positionType;
}

protected final FireMessageType fireType = new FireMessageType();
public FireMessageType getFireType(){
return fireType;
}

protected final Timer_startMessageType timer_startType = new Timer_startMessageType();
public Timer_startMessageType getTimer_startType(){
return timer_startType;
}

protected final Timer_cancelMessageType timer_cancelType = new Timer_cancelMessageType();
public Timer_cancelMessageType getTimer_cancelType(){
return timer_cancelType;
}

protected final Timer_timeoutMessageType timer_timeoutType = new Timer_timeoutMessageType();
public Timer_timeoutMessageType getTimer_timeoutType(){
return timer_timeoutType;
}

//Empty Constructor
public DummyController() {
super();
DummyController_posY_var = (int) 0;
DummyController_YMIN_var = (int)  -100;
DummyController_timerID_var = (int) 3;
DummyController_posX_var = (int) 0;
DummyController_dy_var = (int) 5;
DummyController_XMAX_var = (int) 100;
DummyController_XMIN_var = (int)  -100;
DummyController_YMAX_var = (int) 100;
DummyController_dx_var = (int) 5;
}

//Constructor (only readonly (final) attributes)
public DummyController(final int DummyController_YMIN_var, final int DummyController_timerID_var, final int DummyController_XMAX_var, final int DummyController_XMIN_var, final int DummyController_YMAX_var) {
super();
this.DummyController_YMIN_var = DummyController_YMIN_var;
this.DummyController_timerID_var = DummyController_timerID_var;
this.DummyController_XMAX_var = DummyController_XMAX_var;
this.DummyController_XMIN_var = DummyController_XMIN_var;
this.DummyController_YMAX_var = DummyController_YMAX_var;
}

//Constructor (all attributes)
public DummyController(String name, final int DummyController_posY_var, final int DummyController_YMIN_var, final int DummyController_timerID_var, final int DummyController_posX_var, final int DummyController_dy_var, final int DummyController_XMAX_var, final int DummyController_XMIN_var, final int DummyController_YMAX_var, final int DummyController_dx_var) {
super(name);
this.DummyController_posY_var = DummyController_posY_var;
this.DummyController_YMIN_var = DummyController_YMIN_var;
this.DummyController_timerID_var = DummyController_timerID_var;
this.DummyController_posX_var = DummyController_posX_var;
this.DummyController_dy_var = DummyController_dy_var;
this.DummyController_XMAX_var = DummyController_XMAX_var;
this.DummyController_XMIN_var = DummyController_XMIN_var;
this.DummyController_YMAX_var = DummyController_YMAX_var;
this.DummyController_dx_var = DummyController_dx_var;
}

//Getters and Setters for non readonly/final attributes
public int getDummyController_posY_var() {
return DummyController_posY_var;
}

public void setDummyController_posY_var(int DummyController_posY_var) {
this.DummyController_posY_var = DummyController_posY_var;
}

public int getDummyController_YMIN_var() {
return DummyController_YMIN_var;
}

public int getDummyController_timerID_var() {
return DummyController_timerID_var;
}

public int getDummyController_posX_var() {
return DummyController_posX_var;
}

public void setDummyController_posX_var(int DummyController_posX_var) {
this.DummyController_posX_var = DummyController_posX_var;
}

public int getDummyController_dy_var() {
return DummyController_dy_var;
}

public void setDummyController_dy_var(int DummyController_dy_var) {
this.DummyController_dy_var = DummyController_dy_var;
}

public int getDummyController_XMAX_var() {
return DummyController_XMAX_var;
}

public int getDummyController_XMIN_var() {
return DummyController_XMIN_var;
}

public int getDummyController_YMAX_var() {
return DummyController_YMAX_var;
}

public int getDummyController_dx_var() {
return DummyController_dx_var;
}

public void setDummyController_dx_var(int DummyController_dx_var) {
this.DummyController_dx_var = DummyController_dx_var;
}

//Getters for Ports
public Port getClock_port() {
return clock_port;
}
public Port getControls_port() {
return controls_port;
}
private CompositeState buildDummyController_SC(){
final List<AtomicState> states_DummyController_SC = new ArrayList<AtomicState>();
final AtomicState state_DummyController_SC_Bouncing = new AtomicState("Bouncing")
{
@Override
public void onEntry() {
sendTimer_start_via_clock((int) (getDummyController_timerID_var()), (int) (50));
}

};
states_DummyController_SC.add(state_DummyController_SC_Bouncing);
final List<Region> regions_DummyController_SC = new ArrayList<Region>();
final List<Handler> transitions_DummyController_SC = new ArrayList<Handler>();
transitions_DummyController_SC.add(new Transition("132313280",timer_timeoutType, clock_port, state_DummyController_SC_Bouncing, state_DummyController_SC_Bouncing){
@Override
public boolean doCheck(final Event e) {
final Timer_timeoutMessageType.Timer_timeoutMessage timer_timeout = (Timer_timeoutMessageType.Timer_timeoutMessage) e;
return timer_timeout.id == getDummyController_timerID_var();
}

@Override
public void doExecute(final Event e) {
final Timer_timeoutMessageType.Timer_timeoutMessage timer_timeout = (Timer_timeoutMessageType.Timer_timeoutMessage) e;
DummyController_posX_var = (int) (getDummyController_posX_var() + getDummyController_dx_var());
DummyController_posY_var = (int) (getDummyController_posY_var() + getDummyController_dy_var());
if(getDummyController_posX_var() < getDummyController_XMIN_var()) {
DummyController_posX_var = (int) (2 * getDummyController_XMIN_var() - getDummyController_posX_var());
DummyController_dx_var = (int) ( -getDummyController_dx_var());

} else {
if(getDummyController_posX_var() > getDummyController_XMAX_var()) {
DummyController_posX_var = (int) (2 * getDummyController_XMAX_var() - getDummyController_posX_var());
DummyController_dx_var = (int) ( -getDummyController_dx_var());

}

}
if(getDummyController_posY_var() < getDummyController_YMIN_var()) {
DummyController_posY_var = (int) (2 * getDummyController_YMIN_var() - getDummyController_posY_var());
DummyController_dy_var = (int) ( -getDummyController_dy_var());

} else {
if(getDummyController_posY_var() > getDummyController_YMAX_var()) {
DummyController_posY_var = (int) (2 * getDummyController_YMAX_var() - getDummyController_posY_var());
DummyController_dy_var = (int) ( -getDummyController_dy_var());

}

}
sendPosition_via_controls((int) (getDummyController_posX_var()), (int) (getDummyController_posY_var()));
}

});
final CompositeState state_DummyController_SC = new CompositeState("SC", states_DummyController_SC, state_DummyController_SC_Bouncing, transitions_DummyController_SC, regions_DummyController_SC, false);
return state_DummyController_SC;
}

public Component buildBehavior(String session, Component root) {
if (root == null) {
//Init ports
clock_port = new Port(PortType.REQUIRED, "clock", this);
controls_port = new Port(PortType.PROVIDED, "controls", this);
} else {
clock_port = ((DummyController)root).clock_port;
controls_port = ((DummyController)root).controls_port;
}
createCepStreams();if (session == null){
//Init state machine
behavior = buildDummyController_SC();
}
return this;
}

}
