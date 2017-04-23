'use strict';

StateJS.internalTransitionsTriggerCompletion = true;

/**
 * Definition for type : BouncingBall
 **/
function BouncingBall(name, root, BouncingBall_MAX_var, BouncingBall_bx_var, BouncingBall_dx_var, BouncingBall_YSIZE_var, BouncingBall_by_var, BouncingBall_XSIZE_var, BouncingBall_dy_var, debug) {

this.name = name;
this.root = (root === null)? this : root;
this.debug = debug;
this.ready = false;
this.bus = new EventEmitter();
//Attributes
this.BouncingBall_SC_lastX_var = 200;
this.BouncingBall_SC_lastY_var = 200;
this.BouncingBall_MAX_var = BouncingBall_MAX_var;
this.debug_BouncingBall_MAX_var = BouncingBall_MAX_var;
this.BouncingBall_bx_var = BouncingBall_bx_var;
this.debug_BouncingBall_bx_var = BouncingBall_bx_var;
this.BouncingBall_dx_var = BouncingBall_dx_var;
this.debug_BouncingBall_dx_var = BouncingBall_dx_var;
this.BouncingBall_YSIZE_var = BouncingBall_YSIZE_var;
this.debug_BouncingBall_YSIZE_var = BouncingBall_YSIZE_var;
this.BouncingBall_by_var = BouncingBall_by_var;
this.debug_BouncingBall_by_var = BouncingBall_by_var;
this.BouncingBall_XSIZE_var = BouncingBall_XSIZE_var;
this.debug_BouncingBall_XSIZE_var = BouncingBall_XSIZE_var;
this.BouncingBall_dy_var = BouncingBall_dy_var;
this.debug_BouncingBall_dy_var = BouncingBall_dy_var;
this.build(name);
}
//State machine (states and regions)
BouncingBall.prototype.build = function(session) {//optional session name and root instance to fork a new session
this.statemachine = new StateJS.StateMachine('SC');
this._initial_BouncingBall_SC = new StateJS.PseudoState('_initial', this.statemachine, StateJS.PseudoStateKind.Initial);
let BouncingBall_SC_INIT = new StateJS.State('INIT', this.statemachine).entry(() => {
this.bus.emit('display?create', this.BouncingBall_XSIZE_var, this.BouncingBall_YSIZE_var);
});
let BouncingBall_SC_BOUNCE = new StateJS.State('BOUNCE', this.statemachine).entry(() => {
this.bus.emit('clock?timer_start', 0, 33);
});
this._initial_BouncingBall_SC.to(BouncingBall_SC_INIT);
BouncingBall_SC_INIT.to(BouncingBall_SC_BOUNCE).when((displayReady) => {return displayReady._port === 'display' && displayReady._msg === 'displayReady';}).effect((displayReady) => {
this.bus.emit('display?clear');
this.bus.emit('display?setColor', 255, 255, 255);
this.bus.emit('display?drawRect', 0, 0, this.BouncingBall_XSIZE_var - 1, this.BouncingBall_YSIZE_var - 1);
});
BouncingBall_SC_BOUNCE.to(BouncingBall_SC_BOUNCE).when((timer_timeout) => {return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && timer_timeout.id === 0;}).effect((timer_timeout) => {
this.BouncingBall_bx_var = this.BouncingBall_bx_var + this.BouncingBall_dx_var;
this.bus.emit('bx=', this.BouncingBall_bx_var);
this.BouncingBall_by_var = this.BouncingBall_by_var + this.BouncingBall_dy_var;
this.bus.emit('by=', this.BouncingBall_by_var);
if(this.BouncingBall_bx_var < 0) {
this.BouncingBall_dx_var =  -this.BouncingBall_dx_var;
this.bus.emit('dx=', this.BouncingBall_dx_var);
this.BouncingBall_bx_var =  -this.BouncingBall_bx_var;
this.bus.emit('bx=', this.BouncingBall_bx_var);

} else {
if(this.BouncingBall_bx_var > this.BouncingBall_MAX_var) {
this.BouncingBall_dx_var =  -this.BouncingBall_dx_var;
this.bus.emit('dx=', this.BouncingBall_dx_var);
this.BouncingBall_bx_var = 2 * this.BouncingBall_MAX_var - this.BouncingBall_bx_var;
this.bus.emit('bx=', this.BouncingBall_bx_var);

}

}
if(this.BouncingBall_by_var < 0) {
this.BouncingBall_dy_var =  -this.BouncingBall_dy_var;
this.bus.emit('dy=', this.BouncingBall_dy_var);
this.BouncingBall_by_var =  -this.BouncingBall_by_var;
this.bus.emit('by=', this.BouncingBall_by_var);

} else {
if(this.BouncingBall_by_var > this.BouncingBall_MAX_var) {
this.BouncingBall_dy_var =  -this.BouncingBall_dy_var;
this.bus.emit('dy=', this.BouncingBall_dy_var);
this.BouncingBall_by_var = 2 * this.BouncingBall_MAX_var - this.BouncingBall_by_var;
this.bus.emit('by=', this.BouncingBall_by_var);

}

}
let newX_var = this.getBallX(this.BouncingBall_bx_var);
let newY_var = this.getBallY(this.BouncingBall_by_var);
this.bus.emit('display?setColor', 0, 0, 0);
this.bus.emit('display?fillRect', this.BouncingBall_SC_lastX_var - 3, this.BouncingBall_SC_lastY_var - 3, 6, 6);
this.bus.emit('display?setColor', 255, 255, 255);
this.bus.emit('display?fillRect', newX_var - 2, newY_var - 3, 4, 6);
this.bus.emit('display?fillRect', newX_var - 3, newY_var - 2, 6, 4);
this.bus.emit('display?update');
this.BouncingBall_SC_lastX_var = newX_var;
this.BouncingBall_SC_lastY_var = newY_var;
});
}
//ThingML-defined functions
BouncingBall.prototype.getBallX = function(BouncingBall_getBallX_bx_var) {
let l_var = BouncingBall_getBallX_bx_var;
l_var = l_var * (this.BouncingBall_XSIZE_var - 8);
l_var = l_var / (this.BouncingBall_MAX_var + 1) + 4;
return l_var;
};

BouncingBall.prototype.getBallY = function(BouncingBall_getBallY_by_var) {
let l_var = BouncingBall_getBallY_by_var;
l_var = l_var * (this.BouncingBall_YSIZE_var - 8);
l_var = l_var / (this.BouncingBall_MAX_var + 1) + 4;
return l_var;
};

//Public API for lifecycle management
BouncingBall.prototype._stop = function() {
this.root = null;
this.ready = false;
};

BouncingBall.prototype._delete = function() {
this.statemachine = null;
this.SC_instance = null;
this.bus.removeAllListeners();
};

//Public API for third parties
BouncingBall.prototype._init = function() {
this.SC_instance = new StateJS.StateMachineInstance("SC_instance");
StateJS.initialise(this.statemachine, this.SC_instance );
this.ready = true;
};

BouncingBall.prototype._receive = function(msg) {//msg = {_port:myPort, _msg:myMessage, paramN=paramN, ...}
if(this.ready){
StateJS.evaluate(this.statemachine, this.SC_instance, msg);
} else { setTimeout(()=>this._receive(msg),0) }};
BouncingBall.prototype.receivetimer_timeoutOnclock = function(id) {
this._receive({_port:"clock", _msg:"timer_timeout", id:id});
};

BouncingBall.prototype.receivedisplayReadyOndisplay = function() {
this._receive({_port:"display", _msg:"displayReady"});
};

BouncingBall.prototype.receivedisplayErrorOndisplay = function() {
this._receive({_port:"display", _msg:"displayError"});
};

BouncingBall.prototype.toString = function() {
let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
result += '\n\tlastX = ' + this.BouncingBall_SC_lastX_var;
result += '\n\tlastY = ' + this.BouncingBall_SC_lastY_var;
result += '\n\tMAX = ' + this.BouncingBall_MAX_var;
result += '\n\tbx = ' + this.BouncingBall_bx_var;
result += '\n\tdx = ' + this.BouncingBall_dx_var;
result += '\n\tYSIZE = ' + this.BouncingBall_YSIZE_var;
result += '\n\tby = ' + this.BouncingBall_by_var;
result += '\n\tXSIZE = ' + this.BouncingBall_XSIZE_var;
result += '\n\tdy = ' + this.BouncingBall_dy_var;
result += '';
return result;
};
