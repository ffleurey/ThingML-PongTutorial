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
 * Definition for type : VelocityController
 **/
public class VelocityController extends Component implements IVelocityController_ctrl_in, IVelocityController_clock {

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
result += "\ttimerID = " + VelocityController_timerID_var;
result += "\tXMAX = " + TimerController_XMAX_var;
result += "\tYMAX = " + TimerController_YMAX_var;
result += "\tXMIN = " + TimerController_XMIN_var;
result += "\tYMIN = " + TimerController_YMIN_var;
result += "\tposX = " + TimerController_posX_var;
result += "\tposY = " + TimerController_posY_var;
result += "\tdx = " + TimerController_dx_var;
result += "\tdy = " + TimerController_dy_var;
result += "";
return result;
}

@Override
public void receive(final Event event, final Port p){
if (root == null) {
boolean consumed = false;
if (event.getType().equals(fireType)) {
final FireMessageType.FireMessage fire = (FireMessageType.FireMessage) event;
consumed = true;
sendFire_via_controls((int) (fire.id));
}
if (!consumed && event.getType().equals(velocityType)) {
final VelocityMessageType.VelocityMessage velocity = (VelocityMessageType.VelocityMessage) event;
consumed = true;
TimerController_dx_var = (int) (velocity.dx);
TimerController_dy_var = (int) (velocity.dy);
}
if (!consumed){
super.receive(event, p);
}
else {for (Component child : forks) {
Event child_e = event.clone();
child.receive(child_e, p);
}
for(int i = 0; i < behavior.regions.length; i++) {
behavior.regions[i].handle(event, p);}
}
} else {
super.receive(event, p);
}
}

private Collection<IVelocityController_clockClient> clock_clients = Collections.synchronizedCollection(new LinkedList<IVelocityController_clockClient>());
public synchronized void registerOnClock(IVelocityController_clockClient client){
clock_clients.add(client);
}

public synchronized void unregisterFromClock(IVelocityController_clockClient client){
clock_clients.remove(client);
}

private Collection<IVelocityController_controlsClient> controls_clients = Collections.synchronizedCollection(new LinkedList<IVelocityController_controlsClient>());
public synchronized void registerOnControls(IVelocityController_controlsClient client){
controls_clients.add(client);
}

public synchronized void unregisterFromControls(IVelocityController_controlsClient client){
controls_clients.remove(client);
}

@Override
public synchronized void velocity_via_ctrl_in(int ControllerMsgs_velocity_dx_var, int ControllerMsgs_velocity_dy_var){
receive(velocityType.instantiate(ControllerMsgs_velocity_dx_var, ControllerMsgs_velocity_dy_var), ctrl_in_port);
}

@Override
public synchronized void fire_via_ctrl_in(int ControllerMsgs_fire_id_var){
receive(fireType.instantiate(ControllerMsgs_fire_id_var), ctrl_in_port);
}

@Override
public synchronized void timer_timeout_via_clock(int TimerMsgs_timer_timeout_id_var){
receive(timer_timeoutType.instantiate(TimerMsgs_timer_timeout_id_var), clock_port);
}

private void sendTimer_start_via_clock(int TimerMsgs_timer_start_id_var, int TimerMsgs_timer_start_time_var){
//ThingML send
clock_port.send(timer_startType.instantiate(TimerMsgs_timer_start_id_var, TimerMsgs_timer_start_time_var));
//send to other clients
for(IVelocityController_clockClient client : clock_clients){
client.timer_start_from_clock(TimerMsgs_timer_start_id_var, TimerMsgs_timer_start_time_var);
}}

private void sendTimer_cancel_via_clock(int TimerMsgs_timer_cancel_id_var){
//ThingML send
clock_port.send(timer_cancelType.instantiate(TimerMsgs_timer_cancel_id_var));
//send to other clients
for(IVelocityController_clockClient client : clock_clients){
client.timer_cancel_from_clock(TimerMsgs_timer_cancel_id_var);
}}

private void sendPosition_via_controls(int ControllerMsgs_position_x_var, int ControllerMsgs_position_y_var){
//ThingML send
controls_port.send(positionType.instantiate(ControllerMsgs_position_x_var, ControllerMsgs_position_y_var));
//send to other clients
for(IVelocityController_controlsClient client : controls_clients){
client.position_from_controls(ControllerMsgs_position_x_var, ControllerMsgs_position_y_var);
}}

private void sendFire_via_controls(int ControllerMsgs_fire_id_var){
//ThingML send
controls_port.send(fireType.instantiate(ControllerMsgs_fire_id_var));
//send to other clients
for(IVelocityController_controlsClient client : controls_clients){
client.fire_from_controls(ControllerMsgs_fire_id_var);
}}

//Attributes
private final int TimerController_YMAX_var;
private final int TimerController_XMIN_var;
private int TimerController_posY_var;
private final int TimerController_YMIN_var;
private int TimerController_dx_var;
private int TimerController_dy_var;
private final int TimerController_XMAX_var;
private final int VelocityController_timerID_var;
private int TimerController_posX_var;
private int debug_TimerController_YMAX_var;
private int debug_TimerController_XMIN_var;
private int debug_TimerController_posY_var;
private int debug_TimerController_YMIN_var;
private int debug_TimerController_dx_var;
private int debug_TimerController_dy_var;
private int debug_TimerController_XMAX_var;
private int debug_VelocityController_timerID_var;
private int debug_TimerController_posX_var;
//Ports
private Port ctrl_in_port;
private Port clock_port;
private Port controls_port;
//Message types
protected final VelocityMessageType velocityType = new VelocityMessageType();
public VelocityMessageType getVelocityType(){
return velocityType;
}

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
public VelocityController() {
super();
TimerController_YMAX_var = (int) 100;
TimerController_XMIN_var = (int)  -100;
TimerController_posY_var = (int) 0;
TimerController_YMIN_var = (int)  -100;
TimerController_dx_var = (int) 0;
TimerController_dy_var = (int) 0;
TimerController_XMAX_var = (int) 100;
VelocityController_timerID_var = (int) 4;
TimerController_posX_var = (int) 0;
}

//Constructor (only readonly (final) attributes)
public VelocityController(final int TimerController_YMAX_var, final int TimerController_XMIN_var, final int TimerController_YMIN_var, final int TimerController_XMAX_var, final int VelocityController_timerID_var) {
super();
this.TimerController_YMAX_var = TimerController_YMAX_var;
this.TimerController_XMIN_var = TimerController_XMIN_var;
this.TimerController_YMIN_var = TimerController_YMIN_var;
this.TimerController_XMAX_var = TimerController_XMAX_var;
this.VelocityController_timerID_var = VelocityController_timerID_var;
}

//Constructor (all attributes)
public VelocityController(String name, final int TimerController_YMAX_var, final int TimerController_XMIN_var, final int TimerController_posY_var, final int TimerController_YMIN_var, final int TimerController_dx_var, final int TimerController_dy_var, final int TimerController_XMAX_var, final int VelocityController_timerID_var, final int TimerController_posX_var) {
super(name);
this.TimerController_YMAX_var = TimerController_YMAX_var;
this.TimerController_XMIN_var = TimerController_XMIN_var;
this.TimerController_posY_var = TimerController_posY_var;
this.TimerController_YMIN_var = TimerController_YMIN_var;
this.TimerController_dx_var = TimerController_dx_var;
this.TimerController_dy_var = TimerController_dy_var;
this.TimerController_XMAX_var = TimerController_XMAX_var;
this.VelocityController_timerID_var = VelocityController_timerID_var;
this.TimerController_posX_var = TimerController_posX_var;
}

//Getters and Setters for non readonly/final attributes
public int getTimerController_YMAX_var() {
return TimerController_YMAX_var;
}

public int getTimerController_XMIN_var() {
return TimerController_XMIN_var;
}

public int getTimerController_posY_var() {
return TimerController_posY_var;
}

public void setTimerController_posY_var(int TimerController_posY_var) {
this.TimerController_posY_var = TimerController_posY_var;
}

public int getTimerController_YMIN_var() {
return TimerController_YMIN_var;
}

public int getTimerController_dx_var() {
return TimerController_dx_var;
}

public void setTimerController_dx_var(int TimerController_dx_var) {
this.TimerController_dx_var = TimerController_dx_var;
}

public int getTimerController_dy_var() {
return TimerController_dy_var;
}

public void setTimerController_dy_var(int TimerController_dy_var) {
this.TimerController_dy_var = TimerController_dy_var;
}

public int getTimerController_XMAX_var() {
return TimerController_XMAX_var;
}

public int getVelocityController_timerID_var() {
return VelocityController_timerID_var;
}

public int getTimerController_posX_var() {
return TimerController_posX_var;
}

public void setTimerController_posX_var(int TimerController_posX_var) {
this.TimerController_posX_var = TimerController_posX_var;
}

//Getters for Ports
public Port getCtrl_in_port() {
return ctrl_in_port;
}
public Port getClock_port() {
return clock_port;
}
public Port getControls_port() {
return controls_port;
}
private CompositeState buildVelocityController_SC(){
final List<AtomicState> states_VelocityController_SC = new ArrayList<AtomicState>();
final AtomicState state_VelocityController_SC_Running = new AtomicState("Running")
{
@Override
public void onEntry() {
sendTimer_start_via_clock((int) (getVelocityController_timerID_var()), (int) (50));
}

};
states_VelocityController_SC.add(state_VelocityController_SC_Running);
final List<Region> regions_VelocityController_SC = new ArrayList<Region>();
final List<Handler> transitions_VelocityController_SC = new ArrayList<Handler>();
transitions_VelocityController_SC.add(new Transition("845435327",timer_timeoutType, clock_port, state_VelocityController_SC_Running, state_VelocityController_SC_Running){
@Override
public boolean doCheck(final Event e) {
final Timer_timeoutMessageType.Timer_timeoutMessage timer_timeout = (Timer_timeoutMessageType.Timer_timeoutMessage) e;
return timer_timeout.id == getVelocityController_timerID_var();
}

@Override
public void doExecute(final Event e) {
final Timer_timeoutMessageType.Timer_timeoutMessage timer_timeout = (Timer_timeoutMessageType.Timer_timeoutMessage) e;
TimerController_posX_var = (int) (getTimerController_posX_var() + getTimerController_dx_var());
TimerController_posY_var = (int) (getTimerController_posY_var() + getTimerController_dy_var());
if(getTimerController_posX_var() < getTimerController_XMIN_var()) {
TimerController_posX_var = (int) (getTimerController_XMIN_var());

} else {
if(getTimerController_posX_var() > getTimerController_XMAX_var()) {
TimerController_posX_var = (int) (getTimerController_XMAX_var());

}

}
if(getTimerController_posY_var() < getTimerController_YMIN_var()) {
TimerController_posY_var = (int) (getTimerController_YMIN_var());

} else {
if(getTimerController_posY_var() > getTimerController_YMAX_var()) {
TimerController_posY_var = (int) (getTimerController_YMAX_var());

}

}
sendPosition_via_controls((int) (getTimerController_posX_var()), (int) (getTimerController_posY_var()));
}

});
final CompositeState state_VelocityController_SC = new CompositeState("SC", states_VelocityController_SC, state_VelocityController_SC_Running, transitions_VelocityController_SC, regions_VelocityController_SC, false);
return state_VelocityController_SC;
}

public Component buildBehavior(String session, Component root) {
if (root == null) {
//Init ports
ctrl_in_port = new Port(PortType.REQUIRED, "ctrl_in", this);
clock_port = new Port(PortType.REQUIRED, "clock", this);
controls_port = new Port(PortType.PROVIDED, "controls", this);
} else {
ctrl_in_port = ((VelocityController)root).ctrl_in_port;
clock_port = ((VelocityController)root).clock_port;
controls_port = ((VelocityController)root).controls_port;
}
createCepStreams();if (session == null){
//Init state machine
behavior = buildVelocityController_SC();
}
return this;
}

}
