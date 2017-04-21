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
 * Definition for type : DrawThingML
 **/
public class DrawThingML extends Component implements IDrawThingML_display {

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
result += "\tXDISPSIZE = " + DrawThingML_XDISPSIZE_var;
result += "\tYDISPSIZE = " + DrawThingML_YDISPSIZE_var;
result += "";
return result;
}

private Collection<IDrawThingML_displayClient> display_clients = Collections.synchronizedCollection(new LinkedList<IDrawThingML_displayClient>());
public synchronized void registerOnDisplay(IDrawThingML_displayClient client){
display_clients.add(client);
}

public synchronized void unregisterFromDisplay(IDrawThingML_displayClient client){
display_clients.remove(client);
}

@Override
public synchronized void displayReady_via_display(){
receive(displayReadyType.instantiate(), display_port);
}

@Override
public synchronized void displayError_via_display(){
receive(displayErrorType.instantiate(), display_port);
}

private void sendCreate_via_display(int DisplayMsgs_create_xsize_var, int DisplayMsgs_create_ysize_var){
//ThingML send
display_port.send(createType.instantiate(DisplayMsgs_create_xsize_var, DisplayMsgs_create_ysize_var));
//send to other clients
for(IDrawThingML_displayClient client : display_clients){
client.create_from_display(DisplayMsgs_create_xsize_var, DisplayMsgs_create_ysize_var);
}}

private void sendFillRect_via_display(int DisplayMsgs_fillRect_x_var, int DisplayMsgs_fillRect_y_var, int DisplayMsgs_fillRect_width_var, int DisplayMsgs_fillRect_height_var){
//ThingML send
display_port.send(fillRectType.instantiate(DisplayMsgs_fillRect_x_var, DisplayMsgs_fillRect_y_var, DisplayMsgs_fillRect_width_var, DisplayMsgs_fillRect_height_var));
//send to other clients
for(IDrawThingML_displayClient client : display_clients){
client.fillRect_from_display(DisplayMsgs_fillRect_x_var, DisplayMsgs_fillRect_y_var, DisplayMsgs_fillRect_width_var, DisplayMsgs_fillRect_height_var);
}}

private void sendDrawRect_via_display(int DisplayMsgs_drawRect_x_var, int DisplayMsgs_drawRect_y_var, int DisplayMsgs_drawRect_width_var, int DisplayMsgs_drawRect_height_var){
//ThingML send
display_port.send(drawRectType.instantiate(DisplayMsgs_drawRect_x_var, DisplayMsgs_drawRect_y_var, DisplayMsgs_drawRect_width_var, DisplayMsgs_drawRect_height_var));
//send to other clients
for(IDrawThingML_displayClient client : display_clients){
client.drawRect_from_display(DisplayMsgs_drawRect_x_var, DisplayMsgs_drawRect_y_var, DisplayMsgs_drawRect_width_var, DisplayMsgs_drawRect_height_var);
}}

private void sendClear_via_display(){
//ThingML send
display_port.send(clearType.instantiate());
//send to other clients
for(IDrawThingML_displayClient client : display_clients){
client.clear_from_display();
}}

private void sendSetColor_via_display(int DisplayMsgs_setColor_r_var, int DisplayMsgs_setColor_g_var, int DisplayMsgs_setColor_b_var){
//ThingML send
display_port.send(setColorType.instantiate(DisplayMsgs_setColor_r_var, DisplayMsgs_setColor_g_var, DisplayMsgs_setColor_b_var));
//send to other clients
for(IDrawThingML_displayClient client : display_clients){
client.setColor_from_display(DisplayMsgs_setColor_r_var, DisplayMsgs_setColor_g_var, DisplayMsgs_setColor_b_var);
}}

private void sendUpdate_via_display(){
//ThingML send
display_port.send(updateType.instantiate());
//send to other clients
for(IDrawThingML_displayClient client : display_clients){
client.update_from_display();
}}

//Attributes
private final int DrawThingML_YDISPSIZE_var;
private final int DrawThingML_XDISPSIZE_var;
private int debug_DrawThingML_YDISPSIZE_var;
private int debug_DrawThingML_XDISPSIZE_var;
//Ports
private Port display_port;
//Message types
protected final ClearMessageType clearType = new ClearMessageType();
public ClearMessageType getClearType(){
return clearType;
}

protected final SetColorMessageType setColorType = new SetColorMessageType();
public SetColorMessageType getSetColorType(){
return setColorType;
}

protected final DrawRectMessageType drawRectType = new DrawRectMessageType();
public DrawRectMessageType getDrawRectType(){
return drawRectType;
}

protected final FillRectMessageType fillRectType = new FillRectMessageType();
public FillRectMessageType getFillRectType(){
return fillRectType;
}

protected final CreateMessageType createType = new CreateMessageType();
public CreateMessageType getCreateType(){
return createType;
}

protected final DestroyMessageType destroyType = new DestroyMessageType();
public DestroyMessageType getDestroyType(){
return destroyType;
}

protected final UpdateMessageType updateType = new UpdateMessageType();
public UpdateMessageType getUpdateType(){
return updateType;
}

protected final DisplayReadyMessageType displayReadyType = new DisplayReadyMessageType();
public DisplayReadyMessageType getDisplayReadyType(){
return displayReadyType;
}

protected final DisplayErrorMessageType displayErrorType = new DisplayErrorMessageType();
public DisplayErrorMessageType getDisplayErrorType(){
return displayErrorType;
}

//Empty Constructor
public DrawThingML() {
super();
DrawThingML_YDISPSIZE_var = (int) 128;
DrawThingML_XDISPSIZE_var = (int) 160;
}

//Constructor (only readonly (final) attributes)
public DrawThingML(final int DrawThingML_YDISPSIZE_var, final int DrawThingML_XDISPSIZE_var) {
super();
this.DrawThingML_YDISPSIZE_var = DrawThingML_YDISPSIZE_var;
this.DrawThingML_XDISPSIZE_var = DrawThingML_XDISPSIZE_var;
}

//Constructor (all attributes)
public DrawThingML(String name, final int DrawThingML_YDISPSIZE_var, final int DrawThingML_XDISPSIZE_var) {
super(name);
this.DrawThingML_YDISPSIZE_var = DrawThingML_YDISPSIZE_var;
this.DrawThingML_XDISPSIZE_var = DrawThingML_XDISPSIZE_var;
}

//Getters and Setters for non readonly/final attributes
public int getDrawThingML_YDISPSIZE_var() {
return DrawThingML_YDISPSIZE_var;
}

public int getDrawThingML_XDISPSIZE_var() {
return DrawThingML_XDISPSIZE_var;
}

//Getters for Ports
public Port getDisplay_port() {
return display_port;
}
private CompositeState buildDrawThingML(){
final List<AtomicState> states_DrawThingML = new ArrayList<AtomicState>();
final AtomicState state_DrawThingML_null_DRAW = new AtomicState("DRAW")
;
states_DrawThingML.add(state_DrawThingML_null_DRAW);
final List<Region> regions_DrawThingML = new ArrayList<Region>();
final List<Handler> transitions_DrawThingML = new ArrayList<Handler>();
transitions_DrawThingML.add(new InternalTransition("1396387179",displayReadyType, display_port, state_DrawThingML_null_DRAW){
@Override
public void doExecute(final Event e) {
sendClear_via_display();
drawThingML((int) (20), (int) (60));
sendUpdate_via_display();
}

});
final CompositeState state_DrawThingML = new CompositeState("null", states_DrawThingML, state_DrawThingML_null_DRAW, transitions_DrawThingML, regions_DrawThingML, false){
@Override
public void onEntry() {
sendCreate_via_display((int) (getDrawThingML_XDISPSIZE_var()), (int) (getDrawThingML_YDISPSIZE_var()));
super.onEntry();
}

}
;
return state_DrawThingML;
}

public Component buildBehavior(String session, Component root) {
if (root == null) {
//Init ports
display_port = new Port(PortType.REQUIRED, "display", this);
} else {
display_port = ((DrawThingML)root).display_port;
}
createCepStreams();if (session == null){
//Init state machine
behavior = buildDrawThingML();
}
return this;
}

private void drawThingML(final int DrawThingML_drawThingML_px_var, final int DrawThingML_drawThingML_py_var) {
sendSetColor_via_display((int) (255), (int) (255), (int) (255));
sendFillRect_via_display((int) (DrawThingML_drawThingML_px_var), (int) (DrawThingML_drawThingML_py_var), (int) (108), (int) (13));
int x_var = (int) (DrawThingML_drawThingML_px_var + 1);

int y_var = (int) (DrawThingML_drawThingML_py_var + 1);

sendSetColor_via_display((int) (80), (int) (80), (int) (80));
sendFillRect_via_display((int) (x_var + 0), (int) (y_var + 0), (int) (12), (int) (2));
sendFillRect_via_display((int) (x_var + 5), (int) (y_var + 0), (int) (2), (int) (11));
sendFillRect_via_display((int) (x_var + 18), (int) (y_var + 0), (int) (2), (int) (11));
sendFillRect_via_display((int) (x_var + 27), (int) (y_var + 0), (int) (2), (int) (11));
sendFillRect_via_display((int) (x_var + 18), (int) (y_var + 5), (int) (11), (int) (2));
sendFillRect_via_display((int) (x_var + 36), (int) (y_var + 0), (int) (2), (int) (11));
sendFillRect_via_display((int) (x_var + 44), (int) (y_var + 0), (int) (2), (int) (11));
sendFillRect_via_display((int) (x_var + 46), (int) (y_var + 1), (int) (1), (int) (3));
sendFillRect_via_display((int) (x_var + 47), (int) (y_var + 2), (int) (1), (int) (3));
sendFillRect_via_display((int) (x_var + 48), (int) (y_var + 3), (int) (1), (int) (3));
sendFillRect_via_display((int) (x_var + 49), (int) (y_var + 4), (int) (1), (int) (3));
sendFillRect_via_display((int) (x_var + 50), (int) (y_var + 5), (int) (1), (int) (3));
sendFillRect_via_display((int) (x_var + 51), (int) (y_var + 6), (int) (1), (int) (3));
sendFillRect_via_display((int) (x_var + 52), (int) (y_var + 7), (int) (1), (int) (3));
sendFillRect_via_display((int) (x_var + 53), (int) (y_var + 0), (int) (2), (int) (11));
sendFillRect_via_display((int) (x_var + 62), (int) (y_var + 0), (int) (2), (int) (11));
sendFillRect_via_display((int) (x_var + 62), (int) (y_var + 0), (int) (12), (int) (2));
sendFillRect_via_display((int) (x_var + 62), (int) (y_var + 9), (int) (12), (int) (2));
sendFillRect_via_display((int) (x_var + 62), (int) (y_var + 9), (int) (12), (int) (2));
sendFillRect_via_display((int) (x_var + 69), (int) (y_var + 5), (int) (5), (int) (2));
sendFillRect_via_display((int) (x_var + 72), (int) (y_var + 7), (int) (2), (int) (2));
sendSetColor_via_display((int) (232), (int) (141), (int) (10));
sendFillRect_via_display((int) (x_var + 80), (int) (y_var + 0), (int) (11), (int) (2));
sendFillRect_via_display((int) (x_var + 80), (int) (y_var + 0), (int) (2), (int) (11));
sendFillRect_via_display((int) (x_var + 85), (int) (y_var + 0), (int) (2), (int) (11));
sendFillRect_via_display((int) (x_var + 89), (int) (y_var + 0), (int) (2), (int) (11));
sendFillRect_via_display((int) (x_var + 95), (int) (y_var + 0), (int) (2), (int) (11));
sendFillRect_via_display((int) (x_var + 95), (int) (y_var + 9), (int) (11), (int) (2));
}
}