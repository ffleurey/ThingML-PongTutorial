'use strict';

StateJS.internalTransitionsTriggerCompletion = true;

/**
 * Definition for type : VelocityController
 **/
function VelocityController(name, root, TimerController_posX_var, TimerController_dx_var, TimerController_YMIN_var, TimerController_dy_var, TimerController_posY_var, TimerController_XMIN_var, TimerController_YMAX_var, TimerController_XMAX_var, VelocityController_timerID_var, debug) {

this.name = name;
this.root = (root === null)? this : root;
this.debug = debug;
this.ready = false;
this.bus = new EventEmitter();
//Attributes
this.TimerController_posX_var = TimerController_posX_var;
this.debug_TimerController_posX_var = TimerController_posX_var;
this.TimerController_dx_var = TimerController_dx_var;
this.debug_TimerController_dx_var = TimerController_dx_var;
this.TimerController_YMIN_var = TimerController_YMIN_var;
this.debug_TimerController_YMIN_var = TimerController_YMIN_var;
this.TimerController_dy_var = TimerController_dy_var;
this.debug_TimerController_dy_var = TimerController_dy_var;
this.TimerController_posY_var = TimerController_posY_var;
this.debug_TimerController_posY_var = TimerController_posY_var;
this.TimerController_XMIN_var = TimerController_XMIN_var;
this.debug_TimerController_XMIN_var = TimerController_XMIN_var;
this.TimerController_YMAX_var = TimerController_YMAX_var;
this.debug_TimerController_YMAX_var = TimerController_YMAX_var;
this.TimerController_XMAX_var = TimerController_XMAX_var;
this.debug_TimerController_XMAX_var = TimerController_XMAX_var;
this.VelocityController_timerID_var = VelocityController_timerID_var;
this.debug_VelocityController_timerID_var = VelocityController_timerID_var;
this.build(name);
}
//State machine (states and regions)
VelocityController.prototype.build = function(session) {//optional session name and root instance to fork a new session
this.statemachine = new StateJS.StateMachine('SC');
this._initial_VelocityController_SC = new StateJS.PseudoState('_initial', this.statemachine, StateJS.PseudoStateKind.Initial);
let VelocityController_SC_Running = new StateJS.State('Running', this.statemachine).entry(() => {
this.bus.emit('clock?timer_start', this.VelocityController_timerID_var, 50);
});
this._initial_VelocityController_SC.to(VelocityController_SC_Running);
this.statemachine.to(null).when((velocity) => {return velocity._port === 'ctrl_in' && velocity._msg === 'velocity';}).effect((velocity) => {
this.TimerController_dx_var = velocity.dx;
this.bus.emit('dx=', this.TimerController_dx_var);
this.TimerController_dy_var = velocity.dy;
this.bus.emit('dy=', this.TimerController_dy_var);
});
this.statemachine.to(null).when((fire) => {return fire._port === 'ctrl_in' && fire._msg === 'fire';}).effect((fire) => {
this.bus.emit('controls?fire', fire.id);
});
VelocityController_SC_Running.to(VelocityController_SC_Running).when((timer_timeout) => {return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && timer_timeout.id === this.VelocityController_timerID_var;}).effect((timer_timeout) => {
this.TimerController_posX_var = this.TimerController_posX_var + this.TimerController_dx_var;
this.bus.emit('posX=', this.TimerController_posX_var);
this.TimerController_posY_var = this.TimerController_posY_var + this.TimerController_dy_var;
this.bus.emit('posY=', this.TimerController_posY_var);
if(this.TimerController_posX_var < this.TimerController_XMIN_var) {
this.TimerController_posX_var = this.TimerController_XMIN_var;
this.bus.emit('posX=', this.TimerController_posX_var);

} else {
if(this.TimerController_posX_var > this.TimerController_XMAX_var) {
this.TimerController_posX_var = this.TimerController_XMAX_var;
this.bus.emit('posX=', this.TimerController_posX_var);

}

}
if(this.TimerController_posY_var < this.TimerController_YMIN_var) {
this.TimerController_posY_var = this.TimerController_YMIN_var;
this.bus.emit('posY=', this.TimerController_posY_var);

} else {
if(this.TimerController_posY_var > this.TimerController_YMAX_var) {
this.TimerController_posY_var = this.TimerController_YMAX_var;
this.bus.emit('posY=', this.TimerController_posY_var);

}

}
this.bus.emit('controls?position', this.TimerController_posX_var, this.TimerController_posY_var);
});
}
//ThingML-defined functions
//Public API for lifecycle management
VelocityController.prototype._stop = function() {
this.root = null;
this.ready = false;
};

VelocityController.prototype._delete = function() {
this.statemachine = null;
this.SC_instance = null;
this.bus.removeAllListeners();
};

//Public API for third parties
VelocityController.prototype._init = function() {
this.SC_instance = new StateJS.StateMachineInstance("SC_instance");
StateJS.initialise(this.statemachine, this.SC_instance );
this.ready = true;
};

VelocityController.prototype._receive = function(msg) {//msg = {_port:myPort, _msg:myMessage, paramN=paramN, ...}
if(this.ready){
StateJS.evaluate(this.statemachine, this.SC_instance, msg);
} else { setTimeout(()=>this._receive(msg),0) }};
VelocityController.prototype.receivevelocityOnctrl_in = function(dx, dy) {
this._receive({_port:"ctrl_in", _msg:"velocity", dx:dx, dy:dy});
};

VelocityController.prototype.receivefireOnctrl_in = function(id) {
this._receive({_port:"ctrl_in", _msg:"fire", id:id});
};

VelocityController.prototype.receivetimer_timeoutOnclock = function(id) {
this._receive({_port:"clock", _msg:"timer_timeout", id:id});
};

VelocityController.prototype.toString = function() {
let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
result += '\n\tposX = ' + this.TimerController_posX_var;
result += '\n\tdx = ' + this.TimerController_dx_var;
result += '\n\tYMIN = ' + this.TimerController_YMIN_var;
result += '\n\tdy = ' + this.TimerController_dy_var;
result += '\n\tposY = ' + this.TimerController_posY_var;
result += '\n\tXMIN = ' + this.TimerController_XMIN_var;
result += '\n\tYMAX = ' + this.TimerController_YMAX_var;
result += '\n\tXMAX = ' + this.TimerController_XMAX_var;
result += '\n\ttimerID = ' + this.VelocityController_timerID_var;
result += '';
return result;
};
