'use strict';

StateJS.internalTransitionsTriggerCompletion = true;


/*
 * Definition for type : VelocityController
 */

function VelocityController(name, root, TimerController_dy_var, TimerController_XMAX_var, TimerController_dx_var, TimerController_XMIN_var, VelocityController_timerID_var, TimerController_YMAX_var, TimerController_posX_var, TimerController_YMIN_var, TimerController_posY_var, debug) {
	this.name = name;
	this.root = (root === null)? this : root;
	this.debug = debug;
	this.ready = false;
	this.bus = (root === null)? new EventEmitter() : this.root.bus;
	
	/*Attributes*/
	this.TimerController_dy_var = TimerController_dy_var;
	this.debug_TimerController_dy_var = TimerController_dy_var;
	this.TimerController_XMAX_var = TimerController_XMAX_var;
	this.debug_TimerController_XMAX_var = TimerController_XMAX_var;
	this.TimerController_dx_var = TimerController_dx_var;
	this.debug_TimerController_dx_var = TimerController_dx_var;
	this.TimerController_XMIN_var = TimerController_XMIN_var;
	this.debug_TimerController_XMIN_var = TimerController_XMIN_var;
	this.VelocityController_timerID_var = VelocityController_timerID_var;
	this.debug_VelocityController_timerID_var = VelocityController_timerID_var;
	this.TimerController_YMAX_var = TimerController_YMAX_var;
	this.debug_TimerController_YMAX_var = TimerController_YMAX_var;
	this.TimerController_posX_var = TimerController_posX_var;
	this.debug_TimerController_posX_var = TimerController_posX_var;
	this.TimerController_YMIN_var = TimerController_YMIN_var;
	this.debug_TimerController_YMIN_var = TimerController_YMIN_var;
	this.TimerController_posY_var = TimerController_posY_var;
	this.debug_TimerController_posY_var = TimerController_posY_var;
	
	this.build(name);
}

VelocityController.prototype.build = function(session) {
	/*State machine (states and regions)*/
	/*Building root component*/
	this._statemachine = new StateJS.StateMachine('SC');
	let _initial_VelocityController_SC = new StateJS.PseudoState('_initial', this._statemachine, StateJS.PseudoStateKind.Initial);
	let VelocityController_SC_Running = new StateJS.State('Running', this._statemachine).entry(() => {
		setTimeout(() => this.bus.emit('clock?timer_start', this.VelocityController_timerID_var, 50), 0);
	});
	_initial_VelocityController_SC.to(VelocityController_SC_Running);
	VelocityController_SC_Running.to(VelocityController_SC_Running).when((timer_timeout) => {
		return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && (timer_timeout.id === this.VelocityController_timerID_var);
	}).effect((timer_timeout) => {
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
		setTimeout(() => this.bus.emit('controls?position', this.TimerController_posX_var, this.TimerController_posY_var), 0);
	});
	this._statemachine.to(null).when((fire) => {
		return fire._port === 'ctrl_in' && fire._msg === 'fire';
	}).effect((fire) => {
		setTimeout(() => this.bus.emit('controls?fire', fire.id), 0);
	});
	VelocityController_SC_Running.to(null).when((position) => {
		return position._port === 'ctrl_in' && position._msg === 'position';
	}).effect((position) => {
		this.TimerController_posX_var = position.x;
		this.bus.emit('posX=', this.TimerController_posX_var);
		this.TimerController_posY_var = position.y;
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
		setTimeout(() => this.bus.emit('controls?position', this.TimerController_posX_var, this.TimerController_posY_var), 0);
	});
	this._statemachine.to(null).when((velocity) => {
		return velocity._port === 'ctrl_in' && velocity._msg === 'velocity';
	}).effect((velocity) => {
		this.TimerController_dx_var = velocity.dx;
		this.bus.emit('dx=', this.TimerController_dx_var);
		this.TimerController_dy_var = velocity.dy;
		this.bus.emit('dy=', this.TimerController_dy_var);
	});
}
VelocityController.prototype._stop = function() {
	this.root = null;
	this.ready = false;
}

VelocityController.prototype._delete = function() {
	this._statemachine = null;
	this._SC_instance = null;
	this.bus.removeAllListeners();
}

VelocityController.prototype._init = function() {
	this._SC_instance = new StateJS.StateMachineInstance("SC_instance");
	StateJS.initialise(this._statemachine, this._SC_instance);
	this.ready = true;
}

VelocityController.prototype._receive = function(msg) {
	/*msg = {_port:myPort, _msg:myMessage, paramN=paramN, ...}*/
	if (this.ready) {
		StateJS.evaluate(this._statemachine, this._SC_instance, msg);
	} else {
		setTimeout(()=>this._receive(msg),0);
	}
}

VelocityController.prototype.receivevelocityOnctrl_in = function(dx, dy) {
	this._receive({_port:"ctrl_in", _msg:"velocity", dx:dx, dy:dy});
}

VelocityController.prototype.receivefireOnctrl_in = function(id) {
	this._receive({_port:"ctrl_in", _msg:"fire", id:id});
}

VelocityController.prototype.receivepositionOnctrl_in = function(x, y) {
	this._receive({_port:"ctrl_in", _msg:"position", x:x, y:y});
}

VelocityController.prototype.receivetimer_timeoutOnclock = function(id) {
	this._receive({_port:"clock", _msg:"timer_timeout", id:id});
}

VelocityController.prototype.toString = function() {
	let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
	result += '\n\tdy = ' + this.TimerController_dy_var;
	result += '\n\tXMAX = ' + this.TimerController_XMAX_var;
	result += '\n\tdx = ' + this.TimerController_dx_var;
	result += '\n\tXMIN = ' + this.TimerController_XMIN_var;
	result += '\n\ttimerID = ' + this.VelocityController_timerID_var;
	result += '\n\tYMAX = ' + this.TimerController_YMAX_var;
	result += '\n\tposX = ' + this.TimerController_posX_var;
	result += '\n\tYMIN = ' + this.TimerController_YMIN_var;
	result += '\n\tposY = ' + this.TimerController_posY_var;
	result += '';
	return result;
}

