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

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;

import javax.swing.*;
import java.awt.event.*;

//END: @java_import annotation

/**
 * Definition for type : Java2DDisplay
 **/
public class Java2DDisplay extends Component implements IJava2DDisplay_display {


	// START: @java_features annotation

	protected JPanel canevas;
	protected JFrame frame;
	protected Graphics2D g2d;
	
	// Cache the colors which have been already created
	protected Hashtable<String, Color> colors = new Hashtable<String, Color>();
	protected Color getColor(int r, int g, int b) {
		String key = new String() + r + ';' + g + ';' +  b;
		if (colors.containsKey(key)) return colors.get(key);
		else {
			Color c = new Color(r,g,b);
			colors.put(key, c);
			return c;
		}
	}

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
result += "\tSCALE = " + Java2DDisplay_SCALE_var;
result += "\tXFRAMESIZE = " + Java2DDisplay_XFRAMESIZE_var;
result += "\tYFRAMESIZE = " + Java2DDisplay_YFRAMESIZE_var;
result += "";
return result;
}

private Collection<IJava2DDisplay_vctrlClient> vctrl_clients = Collections.synchronizedCollection(new LinkedList<IJava2DDisplay_vctrlClient>());
public synchronized void registerOnVctrl(IJava2DDisplay_vctrlClient client){
vctrl_clients.add(client);
}

public synchronized void unregisterFromVctrl(IJava2DDisplay_vctrlClient client){
vctrl_clients.remove(client);
}

private Collection<IJava2DDisplay_displayClient> display_clients = Collections.synchronizedCollection(new LinkedList<IJava2DDisplay_displayClient>());
public synchronized void registerOnDisplay(IJava2DDisplay_displayClient client){
display_clients.add(client);
}

public synchronized void unregisterFromDisplay(IJava2DDisplay_displayClient client){
display_clients.remove(client);
}

@Override
public synchronized void create_via_display(int DisplayMsgs_create_xsize_var, int DisplayMsgs_create_ysize_var){
receive(createType.instantiate(DisplayMsgs_create_xsize_var, DisplayMsgs_create_ysize_var), display_port);
}

@Override
public synchronized void destroy_via_display(){
receive(destroyType.instantiate(), display_port);
}

@Override
public synchronized void update_via_display(){
receive(updateType.instantiate(), display_port);
}

@Override
public synchronized void clear_via_display(){
receive(clearType.instantiate(), display_port);
}

@Override
public synchronized void setColor_via_display(int DisplayMsgs_setColor_r_var, int DisplayMsgs_setColor_g_var, int DisplayMsgs_setColor_b_var){
receive(setColorType.instantiate(DisplayMsgs_setColor_r_var, DisplayMsgs_setColor_g_var, DisplayMsgs_setColor_b_var), display_port);
}

@Override
public synchronized void drawRect_via_display(int DisplayMsgs_drawRect_x_var, int DisplayMsgs_drawRect_y_var, int DisplayMsgs_drawRect_width_var, int DisplayMsgs_drawRect_height_var){
receive(drawRectType.instantiate(DisplayMsgs_drawRect_x_var, DisplayMsgs_drawRect_y_var, DisplayMsgs_drawRect_width_var, DisplayMsgs_drawRect_height_var), display_port);
}

@Override
public synchronized void fillRect_via_display(int DisplayMsgs_fillRect_x_var, int DisplayMsgs_fillRect_y_var, int DisplayMsgs_fillRect_width_var, int DisplayMsgs_fillRect_height_var){
receive(fillRectType.instantiate(DisplayMsgs_fillRect_x_var, DisplayMsgs_fillRect_y_var, DisplayMsgs_fillRect_width_var, DisplayMsgs_fillRect_height_var), display_port);
}

private void sendFire_via_vctrl(int ControllerMsgs_fire_id_var){
//ThingML send
vctrl_port.send(fireType.instantiate(ControllerMsgs_fire_id_var));
//send to other clients
for(IJava2DDisplay_vctrlClient client : vctrl_clients){
client.fire_from_vctrl(ControllerMsgs_fire_id_var);
}}

private void sendVelocity_via_vctrl(int ControllerMsgs_velocity_dx_var, int ControllerMsgs_velocity_dy_var){
//ThingML send
vctrl_port.send(velocityType.instantiate(ControllerMsgs_velocity_dx_var, ControllerMsgs_velocity_dy_var));
//send to other clients
for(IJava2DDisplay_vctrlClient client : vctrl_clients){
client.velocity_from_vctrl(ControllerMsgs_velocity_dx_var, ControllerMsgs_velocity_dy_var);
}}

private void sendDisplayReady_via_display(){
//ThingML send
display_port.send(displayReadyType.instantiate());
//send to other clients
for(IJava2DDisplay_displayClient client : display_clients){
client.displayReady_from_display();
}}

private void sendDisplayError_via_display(){
//ThingML send
display_port.send(displayErrorType.instantiate());
//send to other clients
for(IJava2DDisplay_displayClient client : display_clients){
client.displayError_from_display();
}}

//Attributes
private final int Java2DDisplay_SCALE_var;
private int Java2DDisplay_YFRAMESIZE_var;
private int Java2DDisplay_XFRAMESIZE_var;
private int debug_Java2DDisplay_SCALE_var;
private int debug_Java2DDisplay_YFRAMESIZE_var;
private int debug_Java2DDisplay_XFRAMESIZE_var;
//Ports
private Port vctrl_port;
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

//Empty Constructor
public Java2DDisplay() {
super();
Java2DDisplay_SCALE_var = (int) 5;
}

//Constructor (only readonly (final) attributes)
public Java2DDisplay(final int Java2DDisplay_SCALE_var) {
super();
this.Java2DDisplay_SCALE_var = Java2DDisplay_SCALE_var;
}

//Constructor (all attributes)
public Java2DDisplay(String name, final int Java2DDisplay_SCALE_var, final int Java2DDisplay_YFRAMESIZE_var, final int Java2DDisplay_XFRAMESIZE_var) {
super(name);
this.Java2DDisplay_SCALE_var = Java2DDisplay_SCALE_var;
this.Java2DDisplay_YFRAMESIZE_var = Java2DDisplay_YFRAMESIZE_var;
this.Java2DDisplay_XFRAMESIZE_var = Java2DDisplay_XFRAMESIZE_var;
}

//Getters and Setters for non readonly/final attributes
public int getJava2DDisplay_SCALE_var() {
return Java2DDisplay_SCALE_var;
}

public int getJava2DDisplay_YFRAMESIZE_var() {
return Java2DDisplay_YFRAMESIZE_var;
}

public void setJava2DDisplay_YFRAMESIZE_var(int Java2DDisplay_YFRAMESIZE_var) {
this.Java2DDisplay_YFRAMESIZE_var = Java2DDisplay_YFRAMESIZE_var;
}

public int getJava2DDisplay_XFRAMESIZE_var() {
return Java2DDisplay_XFRAMESIZE_var;
}

public void setJava2DDisplay_XFRAMESIZE_var(int Java2DDisplay_XFRAMESIZE_var) {
this.Java2DDisplay_XFRAMESIZE_var = Java2DDisplay_XFRAMESIZE_var;
}

//Getters for Ports
public Port getVctrl_port() {
return vctrl_port;
}
public Port getDisplay_port() {
return display_port;
}
private CompositeState buildDisplay_SC(){
final List<AtomicState> states_Display_SC = new ArrayList<AtomicState>();
final AtomicState state_Display_SC_Wait = new AtomicState("Wait")
;
states_Display_SC.add(state_Display_SC_Wait);
final AtomicState state_Display_SC_Running = new AtomicState("Running")
{
@Override
public void onEntry() {
sendDisplayReady_via_display();
}

};
states_Display_SC.add(state_Display_SC_Running);
final AtomicState state_Display_SC_Destroyed = new AtomicState("Destroyed")
;
states_Display_SC.add(state_Display_SC_Destroyed);
final List<Region> regions_Display_SC = new ArrayList<Region>();
final List<Handler> transitions_Display_SC = new ArrayList<Handler>();
transitions_Display_SC.add(new Transition("726833325",createType, display_port, state_Display_SC_Wait, state_Display_SC_Running){
@Override
public void doExecute(final Event e) {
final CreateMessageType.CreateMessage create = (CreateMessageType.CreateMessage) e;
initDisplay((int) (create.xsize), (int) (create.ysize));
}

});
transitions_Display_SC.add(new InternalTransition("649466505",setColorType, display_port, state_Display_SC_Running){
@Override
public void doExecute(final Event e) {
final SetColorMessageType.SetColorMessage setColor = (SetColorMessageType.SetColorMessage) e;
setColor((int) (setColor.r), (int) (setColor.g), (int) (setColor.b));
}

});
transitions_Display_SC.add(new InternalTransition("1781122891",clearType, display_port, state_Display_SC_Running){
@Override
public void doExecute(final Event e) {
clearScreen();
}

});
transitions_Display_SC.add(new InternalTransition("462112304",drawRectType, display_port, state_Display_SC_Running){
@Override
public void doExecute(final Event e) {
final DrawRectMessageType.DrawRectMessage drawRect = (DrawRectMessageType.DrawRectMessage) e;
drawRect((int) (drawRect.x), (int) (drawRect.y), (int) (drawRect.width), (int) (drawRect.height));
}

});
transitions_Display_SC.add(new InternalTransition("1359811368",fillRectType, display_port, state_Display_SC_Running){
@Override
public void doExecute(final Event e) {
final FillRectMessageType.FillRectMessage fillRect = (FillRectMessageType.FillRectMessage) e;
fillRect((int) (fillRect.x), (int) (fillRect.y), (int) (fillRect.width), (int) (fillRect.height));
}

});
transitions_Display_SC.add(new InternalTransition("861612659",updateType, display_port, state_Display_SC_Running){
@Override
public void doExecute(final Event e) {
updateDisplay();
}

});
transitions_Display_SC.add(new Transition("1121971522",destroyType, display_port, state_Display_SC_Running, state_Display_SC_Destroyed){
@Override
public void doExecute(final Event e) {
destroyDisplay();
}

});
final CompositeState state_Display_SC = new CompositeState("SC", states_Display_SC, state_Display_SC_Wait, transitions_Display_SC, regions_Display_SC, false);
return state_Display_SC;
}

public Component buildBehavior(String session, Component root) {
if (root == null) {
//Init ports
vctrl_port = new Port(PortType.PROVIDED, "vctrl", this);
display_port = new Port(PortType.PROVIDED, "display", this);
} else {
vctrl_port = ((Java2DDisplay)root).vctrl_port;
display_port = ((Java2DDisplay)root).display_port;
}
createCepStreams();if (session == null){
//Init state machine
behavior = buildDisplay_SC();
}
return this;
}

private void initDisplay(final int Java2DDisplay_initDisplay_xsize_var, final int Java2DDisplay_initDisplay_ysize_var) {
Java2DDisplay_XFRAMESIZE_var = (int) (Java2DDisplay_initDisplay_xsize_var);
Java2DDisplay_YFRAMESIZE_var = (int) (Java2DDisplay_initDisplay_ysize_var);

		final BufferedImage displayBuffer = new BufferedImage(getJava2DDisplay_XFRAMESIZE_var(), getJava2DDisplay_YFRAMESIZE_var(), BufferedImage.TYPE_INT_ARGB);
		g2d = displayBuffer.createGraphics();
		
		canevas = new JPanel() {
			  private static final long serialVersionUID = 1L;
			  public void update(Graphics g) {
				  paint(g);
			  }
			
			  public void paint(Graphics g) {
				  g.drawImage(displayBuffer, 0, 0, getJava2DDisplay_XFRAMESIZE_var() * getJava2DDisplay_SCALE_var(), getJava2DDisplay_YFRAMESIZE_var() * getJava2DDisplay_SCALE_var(), 0, 0, getJava2DDisplay_XFRAMESIZE_var(), getJava2DDisplay_YFRAMESIZE_var(), null);
			  }
		};
		canevas.setSize(new Dimension(getJava2DDisplay_XFRAMESIZE_var() * getJava2DDisplay_SCALE_var(), getJava2DDisplay_YFRAMESIZE_var() * getJava2DDisplay_SCALE_var()));
		canevas.setPreferredSize(new Dimension(getJava2DDisplay_XFRAMESIZE_var() * getJava2DDisplay_SCALE_var(), getJava2DDisplay_YFRAMESIZE_var() * getJava2DDisplay_SCALE_var()));
		
		frame = new JFrame("ThingML Java2D Display") {
            private static final long serialVersionUID = 1L;
            public void processWindowEvent(java.awt.event.WindowEvent e) {
                super.processWindowEvent(e);
                if (e.getID() == java.awt.event.WindowEvent.WINDOW_CLOSING) {
                    System.exit(0);
                }
              }
        };
        
        frame.setBackground(Color.black);
        frame.add(canevas);
        frame.pack();
        frame.setResizable(false);
        
        canevas.addKeyListener(new KeyListener() {

            @Override
            public void keyTyped(KeyEvent e) {}

            @Override
            public void keyReleased(KeyEvent e) {
            	int keyCode = e.getKeyCode();
			    switch( keyCode ) { 
			        case KeyEvent.VK_LEFT:
			            
sendVelocity_via_vctrl((int) (0), (int) (0));

			            break;
			        case KeyEvent.VK_RIGHT :
			            
sendVelocity_via_vctrl((int) (0), (int) (0));

			            break;
			     }
            }

            @Override
            public void keyPressed(KeyEvent e) {
                int keyCode = e.getKeyCode();
			    switch( keyCode ) { 
			        case KeyEvent.VK_LEFT:
			            
sendVelocity_via_vctrl((int) ( -8), (int) (0));

			            break;
			        case KeyEvent.VK_RIGHT :
			            
sendVelocity_via_vctrl((int) (8), (int) (0));

			            break;
			     }
            }
        });
        canevas.setFocusable(true);
        canevas.requestFocusInWindow();
        
        frame.setVisible(true);
        
        canevas.repaint();
}
private void destroyDisplay() {
frame.setVisible(false);
		frame.dispose();
}
private void clearScreen() {
g2d.clearRect(0, 0, getJava2DDisplay_XFRAMESIZE_var(), getJava2DDisplay_YFRAMESIZE_var());
}
private void setColor(final int Java2DDisplay_setColor_r_var, final int Java2DDisplay_setColor_g_var, final int Java2DDisplay_setColor_b_var) {
g2d.setColor(getColor(Java2DDisplay_setColor_r_var,Java2DDisplay_setColor_g_var,Java2DDisplay_setColor_b_var));
}
private void drawRect(final int Java2DDisplay_drawRect_x_var, final int Java2DDisplay_drawRect_y_var, final int Java2DDisplay_drawRect_width_var, final int Java2DDisplay_drawRect_height_var) {
g2d.drawRect(Java2DDisplay_drawRect_x_var,Java2DDisplay_drawRect_y_var,Java2DDisplay_drawRect_width_var - 1,Java2DDisplay_drawRect_height_var - 1);
}
private void fillRect(final int Java2DDisplay_fillRect_x_var, final int Java2DDisplay_fillRect_y_var, final int Java2DDisplay_fillRect_width_var, final int Java2DDisplay_fillRect_height_var) {
g2d.fillRect(Java2DDisplay_fillRect_x_var,Java2DDisplay_fillRect_y_var,Java2DDisplay_fillRect_width_var,Java2DDisplay_fillRect_height_var);
}
private void updateDisplay() {
canevas.repaint();
}
}
