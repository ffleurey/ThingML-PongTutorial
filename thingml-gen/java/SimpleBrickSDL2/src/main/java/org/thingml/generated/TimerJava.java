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

//START: @java_import annotation
import java.util.*;

//END: @java_import annotation

/**
 * Definition for type : TimerJava
 **/
public class TimerJava extends Component implements ITimerJava_timer {


	// START: @java_features annotation

	Hashtable<Integer, TimerTask> tasks = new Hashtable<Integer, TimerTask>();
	Timer timer = new java.util.Timer();

	// END: @java_features annotation

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
result += "";
return result;
}

private Collection<ITimerJava_timerClient> timer_clients = Collections.synchronizedCollection(new LinkedList<ITimerJava_timerClient>());
public synchronized void registerOnTimer(ITimerJava_timerClient client){
timer_clients.add(client);
}

public synchronized void unregisterFromTimer(ITimerJava_timerClient client){
timer_clients.remove(client);
}

@Override
public synchronized void timer_start_via_timer(int TimerMsgs_timer_start_id_var, int TimerMsgs_timer_start_time_var){
receive(timer_startType.instantiate(TimerMsgs_timer_start_id_var, TimerMsgs_timer_start_time_var), timer_port);
}

@Override
public synchronized void timer_cancel_via_timer(int TimerMsgs_timer_cancel_id_var){
receive(timer_cancelType.instantiate(TimerMsgs_timer_cancel_id_var), timer_port);
}

private void sendTimer_timeout_via_timer(int TimerMsgs_timer_timeout_id_var){
//ThingML send
timer_port.send(timer_timeoutType.instantiate(TimerMsgs_timer_timeout_id_var));
//send to other clients
for(ITimerJava_timerClient client : timer_clients){
client.timer_timeout_from_timer(TimerMsgs_timer_timeout_id_var);
}}

//Attributes
//Ports
private Port timer_port;
//Message types
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
public TimerJava() {
super();
}

//Constructor (all attributes)
public TimerJava(String name) {
super(name);
}

//Getters and Setters for non readonly/final attributes
//Getters for Ports
public Port getTimer_port() {
return timer_port;
}
private CompositeState buildTimerJava_SoftTimer(){
final List<AtomicState> states_TimerJava_SoftTimer = new ArrayList<AtomicState>();
final AtomicState state_TimerJava_SoftTimer_default = new AtomicState("default")
;
states_TimerJava_SoftTimer.add(state_TimerJava_SoftTimer_default);
final List<Region> regions_TimerJava_SoftTimer = new ArrayList<Region>();
final List<Handler> transitions_TimerJava_SoftTimer = new ArrayList<Handler>();
transitions_TimerJava_SoftTimer.add(new InternalTransition("510830551",timer_startType, timer_port, state_TimerJava_SoftTimer_default){
@Override
public boolean doCheck(final Event e) {
final Timer_startMessageType.Timer_startMessage timer_start = (Timer_startMessageType.Timer_startMessage) e;
return timer_start.time > 0;
}

@Override
public void doExecute(final Event e) {
final Timer_startMessageType.Timer_startMessage timer_start = (Timer_startMessageType.Timer_startMessage) e;
startTimer((int) (timer_start.id), (int) (timer_start.time));
}

});
transitions_TimerJava_SoftTimer.add(new InternalTransition("cancel",timer_cancelType, timer_port, state_TimerJava_SoftTimer_default){
@Override
public void doExecute(final Event e) {
final Timer_cancelMessageType.Timer_cancelMessage timer_cancel = (Timer_cancelMessageType.Timer_cancelMessage) e;
cancel((int) (timer_cancel.id));
}

});
final CompositeState state_TimerJava_SoftTimer = new CompositeState("SoftTimer", states_TimerJava_SoftTimer, state_TimerJava_SoftTimer_default, transitions_TimerJava_SoftTimer, regions_TimerJava_SoftTimer, false);
return state_TimerJava_SoftTimer;
}

public Component buildBehavior(String session, Component root) {
if (root == null) {
//Init ports
timer_port = new Port(PortType.PROVIDED, "timer", this);
} else {
timer_port = ((TimerJava)root).timer_port;
}
createCepStreams();if (session == null){
//Init state machine
behavior = buildTimerJava_SoftTimer();
}
return this;
}

private void startTimer(final int TimerJava_startTimer_id_var, final int TimerJava_startTimer_delay_var) {
final int t_id = TimerJava_startTimer_id_var;
TimerTask t = tasks.get(t_id);
if (t == null) t = new TimerTask() { public void run(){
sendTimer_timeout_via_timer((int) (t_id));

        } };
else 
cancel((int) (TimerJava_startTimer_id_var));
timer.schedule(t, TimerJava_startTimer_delay_var);
}
private void cancel(final int TimerJava_cancel_id_var) {
TimerTask t = tasks.get(TimerJava_cancel_id_var);
if (t != null) t.cancel();
timer.purge();
}
}
