'use strict';

StateJS.internalTransitionsTriggerCompletion = true;

/**
 * Definition for type : DrawThingML
 **/
function DrawThingML(name, root, DrawThingML_YDISPSIZE_var, DrawThingML_XDISPSIZE_var, debug) {

this.name = name;
this.root = (root === null)? this : root;
this.debug = debug;
this.ready = false;
this.bus = new EventEmitter();
//Attributes
this.DrawThingML_YDISPSIZE_var = DrawThingML_YDISPSIZE_var;
this.debug_DrawThingML_YDISPSIZE_var = DrawThingML_YDISPSIZE_var;
this.DrawThingML_XDISPSIZE_var = DrawThingML_XDISPSIZE_var;
this.debug_DrawThingML_XDISPSIZE_var = DrawThingML_XDISPSIZE_var;
this.build(name);
}
//State machine (states and regions)
DrawThingML.prototype.build = function(session) {//optional session name and root instance to fork a new session
this.statemachine = new StateJS.StateMachine('null').entry(() => {
this.bus.emit('display?create', this.DrawThingML_XDISPSIZE_var, this.DrawThingML_YDISPSIZE_var);
});
this._initial_DrawThingML = new StateJS.PseudoState('_initial', this.statemachine, StateJS.PseudoStateKind.Initial);
let DrawThingML_null_DRAW = new StateJS.State('DRAW', this.statemachine);
this._initial_DrawThingML.to(DrawThingML_null_DRAW);
DrawThingML_null_DRAW.to(null).when((displayReady) => {return displayReady._port === 'display' && displayReady._msg === 'displayReady';}).effect((displayReady) => {
this.bus.emit('display?clear');
this.drawThingML(20, 60);
this.bus.emit('display?update');
});
}
//ThingML-defined functions
DrawThingML.prototype.drawThingML = function(DrawThingML_drawThingML_px_var, DrawThingML_drawThingML_py_var) {
this.bus.emit('display?setColor', 255, 255, 255);
this.bus.emit('display?fillRect', DrawThingML_drawThingML_px_var, DrawThingML_drawThingML_py_var, 108, 13);
let x_var = DrawThingML_drawThingML_px_var + 1;
let y_var = DrawThingML_drawThingML_py_var + 1;
this.bus.emit('display?setColor', 80, 80, 80);
this.bus.emit('display?fillRect', x_var + 0, y_var + 0, 12, 2);
this.bus.emit('display?fillRect', x_var + 5, y_var + 0, 2, 11);
this.bus.emit('display?fillRect', x_var + 18, y_var + 0, 2, 11);
this.bus.emit('display?fillRect', x_var + 27, y_var + 0, 2, 11);
this.bus.emit('display?fillRect', x_var + 18, y_var + 5, 11, 2);
this.bus.emit('display?fillRect', x_var + 36, y_var + 0, 2, 11);
this.bus.emit('display?fillRect', x_var + 44, y_var + 0, 2, 11);
this.bus.emit('display?fillRect', x_var + 46, y_var + 1, 1, 3);
this.bus.emit('display?fillRect', x_var + 47, y_var + 2, 1, 3);
this.bus.emit('display?fillRect', x_var + 48, y_var + 3, 1, 3);
this.bus.emit('display?fillRect', x_var + 49, y_var + 4, 1, 3);
this.bus.emit('display?fillRect', x_var + 50, y_var + 5, 1, 3);
this.bus.emit('display?fillRect', x_var + 51, y_var + 6, 1, 3);
this.bus.emit('display?fillRect', x_var + 52, y_var + 7, 1, 3);
this.bus.emit('display?fillRect', x_var + 53, y_var + 0, 2, 11);
this.bus.emit('display?fillRect', x_var + 62, y_var + 0, 2, 11);
this.bus.emit('display?fillRect', x_var + 62, y_var + 0, 12, 2);
this.bus.emit('display?fillRect', x_var + 62, y_var + 9, 12, 2);
this.bus.emit('display?fillRect', x_var + 62, y_var + 9, 12, 2);
this.bus.emit('display?fillRect', x_var + 69, y_var + 5, 5, 2);
this.bus.emit('display?fillRect', x_var + 72, y_var + 7, 2, 2);
this.bus.emit('display?setColor', 232, 141, 10);
this.bus.emit('display?fillRect', x_var + 80, y_var + 0, 11, 2);
this.bus.emit('display?fillRect', x_var + 80, y_var + 0, 2, 11);
this.bus.emit('display?fillRect', x_var + 85, y_var + 0, 2, 11);
this.bus.emit('display?fillRect', x_var + 89, y_var + 0, 2, 11);
this.bus.emit('display?fillRect', x_var + 95, y_var + 0, 2, 11);
this.bus.emit('display?fillRect', x_var + 95, y_var + 9, 11, 2);
};

//Public API for lifecycle management
DrawThingML.prototype._stop = function() {
this.root = null;
this.ready = false;
};

DrawThingML.prototype._delete = function() {
this.statemachine = null;
this.null_instance = null;
this.bus.removeAllListeners();
};

//Public API for third parties
DrawThingML.prototype._init = function() {
this.null_instance = new StateJS.StateMachineInstance("null_instance");
StateJS.initialise(this.statemachine, this.null_instance );
this.ready = true;
};

DrawThingML.prototype._receive = function(msg) {//msg = {_port:myPort, _msg:myMessage, paramN=paramN, ...}
if(this.ready){
StateJS.evaluate(this.statemachine, this.null_instance, msg);
} else { setTimeout(()=>this._receive(msg),0) }};
DrawThingML.prototype.receivedisplayReadyOndisplay = function() {
this._receive({_port:"display", _msg:"displayReady"});
};

DrawThingML.prototype.receivedisplayErrorOndisplay = function() {
this._receive({_port:"display", _msg:"displayError"});
};

DrawThingML.prototype.toString = function() {
let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
result += '\n\tYDISPSIZE = ' + this.DrawThingML_YDISPSIZE_var;
result += '\n\tXDISPSIZE = ' + this.DrawThingML_XDISPSIZE_var;
result += '';
return result;
};
