'use strict';

StateJS.internalTransitionsTriggerCompletion = true;


/*
 * Definition for type : TimerBrowser
 */

function TimerBrowser(name, root, TimerBrowser_Timeouts_var, debug) {
	this.name = name;
	this.root = (root === null)? this : root;
	this.debug = debug;
	this.ready = false;
	this.bus = (root === null)? new EventEmitter() : this.root.bus;
	
	/*Attributes*/
	this.TimerBrowser_Timeouts_var = TimerBrowser_Timeouts_var;
	this.debug_TimerBrowser_Timeouts_var = TimerBrowser_Timeouts_var;
	
	this.build(name);
}

TimerBrowser.prototype.build = function(session) {
	/*State machine (states and regions)*/
	/*Building root component*/
	this._statemachine = new StateJS.StateMachine('SoftTimer');
	let _initial_TimerBrowser_SoftTimer = new StateJS.PseudoState('_initial', this._statemachine, StateJS.PseudoStateKind.Initial);
	let TimerBrowser_SoftTimer_default = new StateJS.State('default', this._statemachine);
	_initial_TimerBrowser_SoftTimer.to(TimerBrowser_SoftTimer_default);
	TimerBrowser_SoftTimer_default.to(null).when((timer_cancel) => {
		return timer_cancel._port === 'timer' && timer_cancel._msg === 'timer_cancel';
	}).effect((timer_cancel) => {
		this.cancel(timer_cancel.id);
	});
	TimerBrowser_SoftTimer_default.to(null).when((timer_start) => {
		return timer_start._port === 'timer' && timer_start._msg === 'timer_start' && (timer_start.time > 0);
	}).effect((timer_start) => {
		this.startTimer(timer_start.id, timer_start.time);
	});
}
TimerBrowser.prototype.startTimer = function(TimerBrowser_startTimer_id_var, TimerBrowser_startTimer_delay_var) {
	
		if (this.TimerBrowser_Timeouts_var[TimerBrowser_startTimer_id_var] != undefined) {
	
	this.cancel(TimerBrowser_startTimer_id_var);
	
		}
	
		this.TimerBrowser_Timeouts_var[TimerBrowser_startTimer_id_var] = setTimeout(() => {
	
	setTimeout(() => this.bus.emit('timer?timer_timeout', TimerBrowser_startTimer_id_var), 0);
	
		this.TimerBrowser_Timeouts_var[TimerBrowser_startTimer_id_var] = undefined;
	}, TimerBrowser_startTimer_delay_var);
	
}

TimerBrowser.prototype.cancel = function(TimerBrowser_cancel_id_var) {
	
		if (this.TimerBrowser_Timeouts_var[TimerBrowser_cancel_id_var] != undefined) {
			clearTimeout(this.TimerBrowser_Timeouts_var[TimerBrowser_cancel_id_var]);
			this.TimerBrowser_Timeouts_var[TimerBrowser_cancel_id_var] = undefined;
		}
	
}

TimerBrowser.prototype._stop = function() {
	this.root = null;
	this.ready = false;
}

TimerBrowser.prototype._delete = function() {
	this._statemachine = null;
	this._SoftTimer_instance = null;
	this.bus.removeAllListeners();
}

TimerBrowser.prototype._init = function() {
	this._SoftTimer_instance = new StateJS.StateMachineInstance("SoftTimer_instance");
	StateJS.initialise(this._statemachine, this._SoftTimer_instance);
	this.ready = true;
}

TimerBrowser.prototype._receive = function(msg) {
	/*msg = {_port:myPort, _msg:myMessage, paramN=paramN, ...}*/
	if (this.ready) {
		StateJS.evaluate(this._statemachine, this._SoftTimer_instance, msg);
	} else {
		setTimeout(()=>this._receive(msg),0);
	}
}

TimerBrowser.prototype.receivetimer_startOntimer = function(id, time) {
	this._receive({_port:"timer", _msg:"timer_start", id:id, time:time});
}

TimerBrowser.prototype.receivetimer_cancelOntimer = function(id) {
	this._receive({_port:"timer", _msg:"timer_cancel", id:id});
}

TimerBrowser.prototype.toString = function() {
	let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
	result += '\n\tTimeouts = ' + this.TimerBrowser_Timeouts_var;
	result += '';
	return result;
}

