'use strict';

StateJS.internalTransitionsTriggerCompletion = true;


/*
 * Definition for type : BreakoutGame
 */

function BreakoutGame(name, root, BreakoutGame_BRICK_ROWS_var, BreakoutGame_score_var, BreakoutGame_bricks_var, BreakoutGame_lives_var, BreakoutGame_br_var, BreakoutGame_pady_var, BreakoutGame_prevPY_var, BreakoutGame_tone_duration_var, BreakoutGame_by_var, BreakoutGame_prevPX_var, BreakoutGame_level_var, BreakoutGame_BOTTOM_var, BreakoutGame_RIGHT_var, BreakoutGame_bgcolor_var, BreakoutGame_prevBX_var, BreakoutGame_padlen_var, BreakoutGame_prevBY_var, BreakoutGame_XMAX_var, BreakoutGame_XDISPSIZE_var, BreakoutGame_tone1_var, BreakoutGame_YMAX_var, BreakoutGame_period_var, BreakoutGame_LEFT_var, BreakoutGame_fgcolor_var, BreakoutGame_tone2_var, BreakoutGame_YDISPSIZE_var, BreakoutGame_SCALE_var, BreakoutGame_bx_var, BreakoutGame_TOP_var, BreakoutGame_dx_var, BreakoutGame_dy_var, BreakoutGame_padx_var, BreakoutGame_BRICK_HEIGHT_var, debug) {
	this.name = name;
	this.root = (root === null)? this : root;
	this.debug = debug;
	this.ready = false;
	this.bus = (root === null)? new EventEmitter() : this.root.bus;
	
	/*Attributes*/
	this.BreakoutGame_BRICK_ROWS_var = BreakoutGame_BRICK_ROWS_var;
	this.debug_BreakoutGame_BRICK_ROWS_var = BreakoutGame_BRICK_ROWS_var;
	this.BreakoutGame_score_var = BreakoutGame_score_var;
	this.debug_BreakoutGame_score_var = BreakoutGame_score_var;
	this.BreakoutGame_bricks_var = BreakoutGame_bricks_var;
	this.debug_BreakoutGame_bricks_var = BreakoutGame_bricks_var;
	this.BreakoutGame_lives_var = BreakoutGame_lives_var;
	this.debug_BreakoutGame_lives_var = BreakoutGame_lives_var;
	this.BreakoutGame_br_var = BreakoutGame_br_var;
	this.debug_BreakoutGame_br_var = BreakoutGame_br_var;
	this.BreakoutGame_pady_var = BreakoutGame_pady_var;
	this.debug_BreakoutGame_pady_var = BreakoutGame_pady_var;
	this.BreakoutGame_prevPY_var = BreakoutGame_prevPY_var;
	this.debug_BreakoutGame_prevPY_var = BreakoutGame_prevPY_var;
	this.BreakoutGame_tone_duration_var = BreakoutGame_tone_duration_var;
	this.debug_BreakoutGame_tone_duration_var = BreakoutGame_tone_duration_var;
	this.BreakoutGame_by_var = BreakoutGame_by_var;
	this.debug_BreakoutGame_by_var = BreakoutGame_by_var;
	this.BreakoutGame_prevPX_var = BreakoutGame_prevPX_var;
	this.debug_BreakoutGame_prevPX_var = BreakoutGame_prevPX_var;
	this.BreakoutGame_level_var = BreakoutGame_level_var;
	this.debug_BreakoutGame_level_var = BreakoutGame_level_var;
	this.BreakoutGame_BOTTOM_var = BreakoutGame_BOTTOM_var;
	this.debug_BreakoutGame_BOTTOM_var = BreakoutGame_BOTTOM_var;
	this.BreakoutGame_RIGHT_var = BreakoutGame_RIGHT_var;
	this.debug_BreakoutGame_RIGHT_var = BreakoutGame_RIGHT_var;
	this.BreakoutGame_bgcolor_var = BreakoutGame_bgcolor_var;
	this.debug_BreakoutGame_bgcolor_var = BreakoutGame_bgcolor_var;
	this.BreakoutGame_prevBX_var = BreakoutGame_prevBX_var;
	this.debug_BreakoutGame_prevBX_var = BreakoutGame_prevBX_var;
	this.BreakoutGame_padlen_var = BreakoutGame_padlen_var;
	this.debug_BreakoutGame_padlen_var = BreakoutGame_padlen_var;
	this.BreakoutGame_prevBY_var = BreakoutGame_prevBY_var;
	this.debug_BreakoutGame_prevBY_var = BreakoutGame_prevBY_var;
	this.BreakoutGame_XMAX_var = BreakoutGame_XMAX_var;
	this.debug_BreakoutGame_XMAX_var = BreakoutGame_XMAX_var;
	this.BreakoutGame_XDISPSIZE_var = BreakoutGame_XDISPSIZE_var;
	this.debug_BreakoutGame_XDISPSIZE_var = BreakoutGame_XDISPSIZE_var;
	this.BreakoutGame_tone1_var = BreakoutGame_tone1_var;
	this.debug_BreakoutGame_tone1_var = BreakoutGame_tone1_var;
	this.BreakoutGame_YMAX_var = BreakoutGame_YMAX_var;
	this.debug_BreakoutGame_YMAX_var = BreakoutGame_YMAX_var;
	this.BreakoutGame_period_var = BreakoutGame_period_var;
	this.debug_BreakoutGame_period_var = BreakoutGame_period_var;
	this.BreakoutGame_LEFT_var = BreakoutGame_LEFT_var;
	this.debug_BreakoutGame_LEFT_var = BreakoutGame_LEFT_var;
	this.BreakoutGame_fgcolor_var = BreakoutGame_fgcolor_var;
	this.debug_BreakoutGame_fgcolor_var = BreakoutGame_fgcolor_var;
	this.BreakoutGame_tone2_var = BreakoutGame_tone2_var;
	this.debug_BreakoutGame_tone2_var = BreakoutGame_tone2_var;
	this.BreakoutGame_YDISPSIZE_var = BreakoutGame_YDISPSIZE_var;
	this.debug_BreakoutGame_YDISPSIZE_var = BreakoutGame_YDISPSIZE_var;
	this.BreakoutGame_SCALE_var = BreakoutGame_SCALE_var;
	this.debug_BreakoutGame_SCALE_var = BreakoutGame_SCALE_var;
	this.BreakoutGame_bx_var = BreakoutGame_bx_var;
	this.debug_BreakoutGame_bx_var = BreakoutGame_bx_var;
	this.BreakoutGame_TOP_var = BreakoutGame_TOP_var;
	this.debug_BreakoutGame_TOP_var = BreakoutGame_TOP_var;
	this.BreakoutGame_dx_var = BreakoutGame_dx_var;
	this.debug_BreakoutGame_dx_var = BreakoutGame_dx_var;
	this.BreakoutGame_dy_var = BreakoutGame_dy_var;
	this.debug_BreakoutGame_dy_var = BreakoutGame_dy_var;
	this.BreakoutGame_SC_LAUNCH_countdown_var;
	this.BreakoutGame_padx_var = BreakoutGame_padx_var;
	this.debug_BreakoutGame_padx_var = BreakoutGame_padx_var;
	this.BreakoutGame_BRICK_HEIGHT_var = BreakoutGame_BRICK_HEIGHT_var;
	this.debug_BreakoutGame_BRICK_HEIGHT_var = BreakoutGame_BRICK_HEIGHT_var;
	
	this.build(name);
}

BreakoutGame.prototype.build = function(session) {
	/*State machine (states and regions)*/
	/*Building root component*/
	this._statemachine = new StateJS.StateMachine('SC');
	let _initial_BreakoutGame_SC = new StateJS.PseudoState('_initial', this._statemachine, StateJS.PseudoStateKind.Initial);
	let BreakoutGame_SC_INIT = new StateJS.State('INIT', this._statemachine).entry(() => {
		this.bus.emit('display?create', this.BreakoutGame_XDISPSIZE_var, this.BreakoutGame_YDISPSIZE_var);
	});
	let BreakoutGame_SC_LAUNCH = new StateJS.State('LAUNCH', this._statemachine).entry(() => {
		setTimeout(() => this.bus.emit('clock?timer_start', 0, 33), 0);
		this.BreakoutGame_SC_LAUNCH_countdown_var = 30 * 3;
		this.drawScore();
		this.drawLives();
		this.bus.emit('display?update');
	});
	let BreakoutGame_SC_PLAY = new StateJS.State('PLAY', this._statemachine).entry(() => {
		setTimeout(() => this.bus.emit('clock?timer_start', 0, this.BreakoutGame_period_var), 0);
	});
	let BreakoutGame_SC_LOSTBALL = new StateJS.State('LOSTBALL', this._statemachine).entry(() => {
		setTimeout(() => this.bus.emit('clock?timer_start', 0, 500), 0);
		this.BreakoutGame_lives_var = this.BreakoutGame_lives_var - 1;
		this.bus.emit('lives=', this.BreakoutGame_lives_var);
		this.eraseBall();
		this.erasePad();
		this.drawLives();
		this.bus.emit('display?update');
	});
	let BreakoutGame_SC_NEXTLEVEL = new StateJS.State('NEXTLEVEL', this._statemachine).entry(() => {
		setTimeout(() => this.bus.emit('clock?timer_start', 0, 1000), 0);
		this.BreakoutGame_level_var = this.BreakoutGame_level_var + 1;
		this.bus.emit('level=', this.BreakoutGame_level_var);
		this.drawLevel();
		this.eraseBall();
		this.erasePad();
		if((this.BreakoutGame_level_var % 2) === 0 && this.BreakoutGame_padlen_var > 5 * this.BreakoutGame_SCALE_var) {
		this.BreakoutGame_padlen_var = this.BreakoutGame_padlen_var - (4 * this.BreakoutGame_SCALE_var);
		this.bus.emit('padlen=', this.BreakoutGame_padlen_var);
		
		}
		if((this.BreakoutGame_level_var % 2) === 1) {
		this.BreakoutGame_dy_var = Math.floor((this.BreakoutGame_dy_var * 3) / 2);
		this.bus.emit('dy=', this.BreakoutGame_dy_var);
		
		}
		this.drawLives();
		this.createBricks();
		this.bus.emit('display?update');
	});
	let BreakoutGame_SC_GAMEOVER = new StateJS.State('GAMEOVER', this._statemachine).entry(() => {
		this.eraseBall();
		this.erasePad();
		this.bus.emit('display?setColor', 255, 255, 255);
		this.bus.emit('display?fillRect', 8, 30, 142, 76);
		this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
		, this.BreakoutGame_fgcolor_var[1]
		, this.BreakoutGame_fgcolor_var[2]
		);
		this.bus.emit('display?fillRect', 9, 31, 140, 50);
		this.bus.emit('display?setBGColor', this.BreakoutGame_fgcolor_var[0]
		, this.BreakoutGame_fgcolor_var[1]
		, this.BreakoutGame_fgcolor_var[2]
		);
		this.bus.emit('display?setColor', 158, 209, 130);
		this.bus.emit('display?drawInteger', 23, 40, this.BreakoutGame_score_var, 5, 6);
		this.bus.emit('display?drawThingML', 26, 87);
		this.bus.emit('display?update');
	});
	_initial_BreakoutGame_SC.to(BreakoutGame_SC_INIT);
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_NEXTLEVEL).when((nextLevel) => {
		return nextLevel._port === 'game' && nextLevel._msg === 'nextLevel';
	}).effect((nextLevel) => {
		setTimeout(() => this.bus.emit('clock?timer_cancel', 0), 0);
	});
	BreakoutGame_SC_PLAY.to(BreakoutGame_SC_LOSTBALL).when((lostBall) => {
		return lostBall._port === 'game' && lostBall._msg === 'lostBall';
	}).effect((lostBall) => {
		setTimeout(() => this.bus.emit('clock?timer_cancel', 0), 0);
	});
	BreakoutGame_SC_NEXTLEVEL.to(BreakoutGame_SC_LAUNCH).when((timer_timeout) => {
		return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && (timer_timeout.id === 0);
	});
	BreakoutGame_SC_LAUNCH.to(BreakoutGame_SC_PLAY).when((timer_timeout) => {
		return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_SC_LAUNCH_countdown_var === 0);
	}).effect((timer_timeout) => {
		this.drawCountDown(0);
		this.resetBall();
		this.bus.emit('display?update');
	});
	BreakoutGame_SC_LAUNCH.to(null).when((timer_timeout) => {
		return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_SC_LAUNCH_countdown_var > 0);
	}).effect((timer_timeout) => {
		setTimeout(() => this.bus.emit('clock?timer_start', 0, 33), 0);
		this.drawPad();
		if((this.BreakoutGame_SC_LAUNCH_countdown_var % 30) === 0) {
		this.drawCountDown(Math.floor(this.BreakoutGame_SC_LAUNCH_countdown_var / 30));
		
		}
		this.BreakoutGame_SC_LAUNCH_countdown_var = this.BreakoutGame_SC_LAUNCH_countdown_var - 1;
		this.bus.emit('display?update');
	});
	BreakoutGame_SC_PLAY.to(null).when((timer_timeout) => {
		return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && (timer_timeout.id === 0);
	}).effect((timer_timeout) => {
		this.BreakoutGame_bx_var = this.BreakoutGame_bx_var + this.BreakoutGame_dx_var;
		this.bus.emit('bx=', this.BreakoutGame_bx_var);
		this.BreakoutGame_by_var = this.BreakoutGame_by_var + this.BreakoutGame_dy_var;
		this.bus.emit('by=', this.BreakoutGame_by_var);
		let wl_var = this.BreakoutGame_LEFT_var + this.BreakoutGame_br_var;
		let wr_var = this.BreakoutGame_RIGHT_var - this.BreakoutGame_br_var;
		let wt_var = this.BreakoutGame_TOP_var + this.BreakoutGame_br_var;
		let wb_var = this.BreakoutGame_BOTTOM_var - this.BreakoutGame_br_var;
		if(this.BreakoutGame_bx_var < wl_var) {
		this.bus.emit('sound?tone', this.BreakoutGame_tone2_var, this.BreakoutGame_tone_duration_var);
		this.BreakoutGame_dx_var =  -this.BreakoutGame_dx_var;
		this.bus.emit('dx=', this.BreakoutGame_dx_var);
		this.BreakoutGame_bx_var = 2 * wl_var - this.BreakoutGame_bx_var;
		this.bus.emit('bx=', this.BreakoutGame_bx_var);
		this.incrementScore( -1);
		
		} else {
		if(this.BreakoutGame_bx_var > wr_var) {
		this.bus.emit('sound?tone', this.BreakoutGame_tone2_var, this.BreakoutGame_tone_duration_var);
		this.BreakoutGame_dx_var =  -this.BreakoutGame_dx_var;
		this.bus.emit('dx=', this.BreakoutGame_dx_var);
		this.BreakoutGame_bx_var = 2 * wr_var - this.BreakoutGame_bx_var;
		this.bus.emit('bx=', this.BreakoutGame_bx_var);
		this.incrementScore( -1);
		
		}
		
		}
		if(this.BreakoutGame_by_var < wt_var) {
		this.bus.emit('sound?tone', this.BreakoutGame_tone2_var, this.BreakoutGame_tone_duration_var);
		this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
		this.bus.emit('dy=', this.BreakoutGame_dy_var);
		this.BreakoutGame_by_var = 2 * wt_var - this.BreakoutGame_by_var;
		this.bus.emit('by=', this.BreakoutGame_by_var);
		this.incrementScore( -1);
		
		} else {
		if(this.BreakoutGame_by_var > wb_var) {
		setTimeout(() => this.bus.emit('game?lostBall'), 0);
		
		}
		
		}
		if(this.BreakoutGame_dy_var > 0) {
		if(this.BreakoutGame_by_var > this.BreakoutGame_pady_var - this.BreakoutGame_br_var && this.BreakoutGame_by_var < this.BreakoutGame_pady_var + this.BreakoutGame_br_var) {
		if(this.BreakoutGame_bx_var > this.BreakoutGame_padx_var - Math.floor(this.BreakoutGame_padlen_var / 2) && this.BreakoutGame_bx_var < this.BreakoutGame_padx_var + Math.floor(this.BreakoutGame_padlen_var / 2)) {
		this.bus.emit('sound?tone', this.BreakoutGame_tone2_var, this.BreakoutGame_tone_duration_var);
		this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
		this.bus.emit('dy=', this.BreakoutGame_dy_var);
		this.BreakoutGame_by_var = 2 * (this.BreakoutGame_pady_var - this.BreakoutGame_br_var) - this.BreakoutGame_by_var;
		this.bus.emit('by=', this.BreakoutGame_by_var);
		this.BreakoutGame_dx_var = Math.floor(this.BreakoutGame_dx_var / 4) + Math.floor((this.BreakoutGame_bx_var - this.BreakoutGame_padx_var) / 4);
		this.bus.emit('dx=', this.BreakoutGame_dx_var);
		
		}
		
		}
		
		}
		let collision_var = this.collideBrick(this.BreakoutGame_bx_var - this.BreakoutGame_br_var, this.BreakoutGame_by_var - this.BreakoutGame_br_var) || this.collideBrick(this.BreakoutGame_bx_var + this.BreakoutGame_br_var, this.BreakoutGame_by_var - this.BreakoutGame_br_var) || this.collideBrick(this.BreakoutGame_bx_var + this.BreakoutGame_br_var, this.BreakoutGame_by_var + this.BreakoutGame_br_var) || this.collideBrick(this.BreakoutGame_bx_var - this.BreakoutGame_br_var, this.BreakoutGame_by_var + this.BreakoutGame_br_var);
		if(collision_var) {
		this.bus.emit('sound?tone', this.BreakoutGame_tone1_var, this.BreakoutGame_tone_duration_var);
		this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
		this.bus.emit('dy=', this.BreakoutGame_dy_var);
		this.incrementScore(10);
		if(this.bricksLeft() === 0) {
		setTimeout(() => this.bus.emit('game?nextLevel'), 0);
		
		}
		
		}
		this.drawBall();
		this.drawPad();
		setTimeout(() => this.bus.emit('ia?updateIA', this.BreakoutGame_bx_var, this.BreakoutGame_by_var, this.BreakoutGame_padx_var, this.BreakoutGame_pady_var), 0);
		this.bus.emit('display?update');
		setTimeout(() => this.bus.emit('clock?timer_start', 0, this.BreakoutGame_period_var), 0);
	});
	BreakoutGame_SC_LOSTBALL.to(BreakoutGame_SC_LAUNCH).when((timer_timeout) => {
		return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_lives_var > 0);
	});
	BreakoutGame_SC_LOSTBALL.to(BreakoutGame_SC_GAMEOVER).when((timer_timeout) => {
		return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && (timer_timeout.id === 0 && this.BreakoutGame_lives_var === 0);
	});
	this._statemachine.to(null).when((position) => {
		return position._port === 'controller' && position._msg === 'position';
	}).effect((position) => {
		let center_var = (this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var - this.BreakoutGame_padlen_var);
		center_var = position.x * center_var;
		center_var = Math.floor(center_var / 200);
		this.BreakoutGame_padx_var = this.BreakoutGame_LEFT_var + center_var + Math.floor((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 2);
		this.bus.emit('padx=', this.BreakoutGame_padx_var);
	});
	BreakoutGame_SC_INIT.to(BreakoutGame_SC_LAUNCH).when((displayReady) => {
		return displayReady._port === 'display' && displayReady._msg === 'displayReady';
	}).effect((displayReady) => {
		this.bus.emit('display?clear');
		this.initColors();
		this.bus.emit('display?setColor', this.BreakoutGame_bgcolor_var[0]
		, this.BreakoutGame_bgcolor_var[1]
		, this.BreakoutGame_bgcolor_var[2]
		);
		this.bus.emit('display?fillRect', 0, 0, this.BreakoutGame_XDISPSIZE_var, this.BreakoutGame_YDISPSIZE_var);
		this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
		, this.BreakoutGame_fgcolor_var[1]
		, this.BreakoutGame_fgcolor_var[2]
		);
		this.bus.emit('display?fillRect', 0, 0, this.BreakoutGame_XDISPSIZE_var, 14);
		this.drawWalls();
		this.createBricks();
		this.drawLevel();
	});
}
BreakoutGame.prototype.initColors = function() {
	this.BreakoutGame_bgcolor_var[0] = 53;
	this.bus.emit('bgcolor=', this.BreakoutGame_bgcolor_var);
	this.BreakoutGame_bgcolor_var[1] = 40;
	this.bus.emit('bgcolor=', this.BreakoutGame_bgcolor_var);
	this.BreakoutGame_bgcolor_var[2] = 120;
	this.bus.emit('bgcolor=', this.BreakoutGame_bgcolor_var);
	this.BreakoutGame_fgcolor_var[0] = 107;
	this.bus.emit('fgcolor=', this.BreakoutGame_fgcolor_var);
	this.BreakoutGame_fgcolor_var[1] = 94;
	this.bus.emit('fgcolor=', this.BreakoutGame_fgcolor_var);
	this.BreakoutGame_fgcolor_var[2] = 174;
	this.bus.emit('fgcolor=', this.BreakoutGame_fgcolor_var);
	this.bus.emit('display?setBGColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
}

BreakoutGame.prototype.resetBall = function() {
	this.BreakoutGame_bx_var = this.BreakoutGame_padx_var - Math.floor(this.BreakoutGame_br_var / this.BreakoutGame_SCALE_var);
	this.bus.emit('bx=', this.BreakoutGame_bx_var);
	this.BreakoutGame_by_var = this.BreakoutGame_pady_var - Math.floor(this.BreakoutGame_br_var / this.BreakoutGame_SCALE_var);
	this.bus.emit('by=', this.BreakoutGame_by_var);
	this.BreakoutGame_dx_var = (this.BreakoutGame_padx_var + this.BreakoutGame_prevBX_var + this.BreakoutGame_prevBY_var) % 300 - 150;
	this.bus.emit('dx=', this.BreakoutGame_dx_var);
	if(this.BreakoutGame_dy_var > 0) {
	this.BreakoutGame_dy_var =  -this.BreakoutGame_dy_var;
	this.bus.emit('dy=', this.BreakoutGame_dy_var);
	
	}
	this.BreakoutGame_prevBX_var =  -1;
	this.bus.emit('prevBX=', this.BreakoutGame_prevBX_var);
	this.BreakoutGame_prevBY_var =  -1;
	this.bus.emit('prevBY=', this.BreakoutGame_prevBY_var);
}

BreakoutGame.prototype.eraseBall = function() {
	let bs_var = Math.floor((this.BreakoutGame_br_var * 2) / this.BreakoutGame_SCALE_var);
	if(this.BreakoutGame_prevBX_var > 0) {
	this.bus.emit('display?setColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?fillRect', this.BreakoutGame_prevBX_var, this.BreakoutGame_prevBY_var, bs_var, bs_var);
	
	}
	this.BreakoutGame_prevBX_var =  -1;
	this.bus.emit('prevBX=', this.BreakoutGame_prevBX_var);
	this.BreakoutGame_prevBY_var =  -1;
	this.bus.emit('prevBY=', this.BreakoutGame_prevBY_var);
}

BreakoutGame.prototype.drawBall = function() {
	let bs_var = Math.floor((this.BreakoutGame_br_var * 2) / this.BreakoutGame_SCALE_var);
	this.eraseBall();
	this.BreakoutGame_prevBX_var = Math.floor((this.BreakoutGame_bx_var - this.BreakoutGame_br_var) / this.BreakoutGame_SCALE_var);
	this.bus.emit('prevBX=', this.BreakoutGame_prevBX_var);
	this.BreakoutGame_prevBY_var = Math.floor((this.BreakoutGame_by_var - this.BreakoutGame_br_var) / this.BreakoutGame_SCALE_var);
	this.bus.emit('prevBY=', this.BreakoutGame_prevBY_var);
	this.bus.emit('display?setColor', 183, 199, 111);
	this.bus.emit('display?fillRect', this.BreakoutGame_prevBX_var, this.BreakoutGame_prevBY_var, bs_var, bs_var);
}

BreakoutGame.prototype.erasePad = function() {
	let ps_var = Math.floor(this.BreakoutGame_padlen_var / this.BreakoutGame_SCALE_var);
	if(this.BreakoutGame_prevPX_var > 0) {
	this.bus.emit('display?setColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?fillRect', this.BreakoutGame_prevPX_var, this.BreakoutGame_prevPY_var, ps_var, 4);
	
	}
}

BreakoutGame.prototype.drawPad = function() {
	let ps_var = Math.floor(this.BreakoutGame_padlen_var / this.BreakoutGame_SCALE_var);
	this.erasePad();
	this.BreakoutGame_prevPX_var = Math.floor((this.BreakoutGame_padx_var - (Math.floor(this.BreakoutGame_padlen_var / 2))) / this.BreakoutGame_SCALE_var);
	this.bus.emit('prevPX=', this.BreakoutGame_prevPX_var);
	this.BreakoutGame_prevPY_var = Math.floor(this.BreakoutGame_pady_var / this.BreakoutGame_SCALE_var);
	this.bus.emit('prevPY=', this.BreakoutGame_prevPY_var);
	this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	this.bus.emit('display?fillRect', this.BreakoutGame_prevPX_var, this.BreakoutGame_prevPY_var, ps_var, 4);
}

BreakoutGame.prototype.drawCountDown = function(BreakoutGame_drawCountDown_c_var) {
	this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	if(BreakoutGame_drawCountDown_c_var > 0) {
	this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	this.bus.emit('display?setBGColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?drawInteger', 80 - 6, 90, BreakoutGame_drawCountDown_c_var, 1, 4);
	
	} else {
	this.bus.emit('display?setColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?fillRect', 80 - 6, 90, 12, 20);
	
	}
}

BreakoutGame.prototype.drawWalls = function() {
	this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	this.bus.emit('display?fillRect', Math.floor(this.BreakoutGame_LEFT_var / this.BreakoutGame_SCALE_var) - 1, Math.floor(this.BreakoutGame_TOP_var / this.BreakoutGame_SCALE_var) - 1, Math.floor((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / this.BreakoutGame_SCALE_var) + 1, 1);
	this.bus.emit('display?fillRect', Math.floor(this.BreakoutGame_LEFT_var / this.BreakoutGame_SCALE_var) - 1, Math.floor(this.BreakoutGame_BOTTOM_var / this.BreakoutGame_SCALE_var), Math.floor((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / this.BreakoutGame_SCALE_var) + 1, 1);
	this.bus.emit('display?fillRect', Math.floor(this.BreakoutGame_LEFT_var / this.BreakoutGame_SCALE_var) - 1, Math.floor(this.BreakoutGame_TOP_var / this.BreakoutGame_SCALE_var), 1, Math.floor((this.BreakoutGame_BOTTOM_var - this.BreakoutGame_TOP_var) / this.BreakoutGame_SCALE_var));
	this.bus.emit('display?fillRect', Math.floor(this.BreakoutGame_RIGHT_var / this.BreakoutGame_SCALE_var), Math.floor(this.BreakoutGame_TOP_var / this.BreakoutGame_SCALE_var), 1, Math.floor((this.BreakoutGame_BOTTOM_var - this.BreakoutGame_TOP_var) / this.BreakoutGame_SCALE_var));
}

BreakoutGame.prototype.bitIsSet = function(BreakoutGame_bitIsSet_variable_var, BreakoutGame_bitIsSet_bit_var) {
	return ((1 << BreakoutGame_bitIsSet_bit_var) & BreakoutGame_bitIsSet_variable_var) != 0;
}

BreakoutGame.prototype.unsetBit = function(BreakoutGame_unsetBit_variable_var, BreakoutGame_unsetBit_bit_var) {
	return BreakoutGame_unsetBit_variable_var & ~(1 << BreakoutGame_unsetBit_bit_var);
}

BreakoutGame.prototype.createBricks = function() {
	let y_var = 0;
	while(y_var < this.BreakoutGame_BRICK_ROWS_var) {
	this.BreakoutGame_bricks_var[y_var] = 0xFF;
	this.bus.emit('bricks=', this.BreakoutGame_bricks_var);
	let x_var = 0;
	while(x_var < 8) {
	if(this.bitIsSet(this.BreakoutGame_bricks_var[y_var]
	, x_var)) {
	this.drawBrick(x_var, y_var);
	
	}
	x_var = x_var + 1;
	
	}
	y_var = y_var + 1;
	
	}
}

BreakoutGame.prototype.bricksLeft = function() {
	let result_var = 0;
	let y_var = 0;
	while(y_var < this.BreakoutGame_BRICK_ROWS_var) {
	let x_var = 0;
	while(x_var < 8) {
	if(this.bitIsSet(this.BreakoutGame_bricks_var[y_var]
	, x_var)) {
	result_var = result_var + 1;
	
	}
	x_var = x_var + 1;
	
	}
	y_var = y_var + 1;
	
	}
	return result_var;
}

BreakoutGame.prototype.drawBrick = function(BreakoutGame_drawBrick_x_var, BreakoutGame_drawBrick_y_var) {
	let bx_var = this.BreakoutGame_LEFT_var + (Math.floor((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) * BreakoutGame_drawBrick_x_var;
	let by_var = this.BreakoutGame_TOP_var + 20 * this.BreakoutGame_SCALE_var + this.BreakoutGame_BRICK_HEIGHT_var * BreakoutGame_drawBrick_y_var * this.BreakoutGame_SCALE_var;
	this.bus.emit('display?setColor', 155, 103, 89);
	this.bus.emit('display?fillRect', Math.floor(bx_var / this.BreakoutGame_SCALE_var) + 1, Math.floor(by_var / this.BreakoutGame_SCALE_var) + 1, Math.floor((Math.floor((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) / this.BreakoutGame_SCALE_var) - 2, this.BreakoutGame_BRICK_HEIGHT_var - 2);
	this.bus.emit('display?setColor', 100, 56, 43);
	this.bus.emit('display?drawRect', Math.floor(bx_var / this.BreakoutGame_SCALE_var) + 1, Math.floor(by_var / this.BreakoutGame_SCALE_var) + 1, Math.floor((Math.floor((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) / this.BreakoutGame_SCALE_var) - 2, this.BreakoutGame_BRICK_HEIGHT_var - 2);
}

BreakoutGame.prototype.removeBrick = function(BreakoutGame_removeBrick_x_var, BreakoutGame_removeBrick_y_var) {
	let bx_var = this.BreakoutGame_LEFT_var + (Math.floor((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) * BreakoutGame_removeBrick_x_var;
	let by_var = this.BreakoutGame_TOP_var + 20 * this.BreakoutGame_SCALE_var + this.BreakoutGame_BRICK_HEIGHT_var * BreakoutGame_removeBrick_y_var * this.BreakoutGame_SCALE_var;
	this.bus.emit('display?setColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?fillRect', Math.floor(bx_var / this.BreakoutGame_SCALE_var) + 1, Math.floor(by_var / this.BreakoutGame_SCALE_var) + 1, Math.floor((Math.floor((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)) / this.BreakoutGame_SCALE_var) - 2, this.BreakoutGame_BRICK_HEIGHT_var - 2);
	this.BreakoutGame_bricks_var[BreakoutGame_removeBrick_y_var] = this.unsetBit(this.BreakoutGame_bricks_var[BreakoutGame_removeBrick_y_var]
	, BreakoutGame_removeBrick_x_var);
	this.bus.emit('bricks=', this.BreakoutGame_bricks_var);
}

BreakoutGame.prototype.collideBrick = function(BreakoutGame_collideBrick_xpos_var, BreakoutGame_collideBrick_ypos_var) {
	let bry_var = Math.floor((BreakoutGame_collideBrick_ypos_var - this.BreakoutGame_TOP_var - 20 * this.BreakoutGame_SCALE_var) / (this.BreakoutGame_BRICK_HEIGHT_var * this.BreakoutGame_SCALE_var));
	let result_var = false;
	if(bry_var >= 0 && bry_var < this.BreakoutGame_BRICK_ROWS_var) {
	let brx_var = Math.floor((BreakoutGame_collideBrick_xpos_var - this.BreakoutGame_LEFT_var) / (Math.floor((this.BreakoutGame_RIGHT_var - this.BreakoutGame_LEFT_var) / 8)));
	if(this.bitIsSet(this.BreakoutGame_bricks_var[bry_var]
	, brx_var)) {
	this.removeBrick(brx_var, bry_var);
	result_var = true;
	
	}
	
	}
	return result_var;
}

BreakoutGame.prototype.drawLevel = function() {
	this.bus.emit('display?setColor', 158, 209, 130);
	this.bus.emit('display?setBGColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	this.bus.emit('display?setColor', this.BreakoutGame_bgcolor_var[0]
	, this.BreakoutGame_bgcolor_var[1]
	, this.BreakoutGame_bgcolor_var[2]
	);
	this.bus.emit('display?drawInteger', 6, 2, this.BreakoutGame_level_var, 2, 2);
}

BreakoutGame.prototype.incrementScore = function(BreakoutGame_incrementScore_diff_var) {
	this.BreakoutGame_score_var = this.BreakoutGame_score_var + BreakoutGame_incrementScore_diff_var;
	this.bus.emit('score=', this.BreakoutGame_score_var);
	if(this.BreakoutGame_score_var < 0) {
	this.BreakoutGame_score_var = 0;
	this.bus.emit('score=', this.BreakoutGame_score_var);
	
	}
	this.drawScore();
}

BreakoutGame.prototype.drawScore = function() {
	this.bus.emit('display?setColor', 158, 209, 130);
	this.bus.emit('display?setBGColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	this.bus.emit('display?drawInteger', 58, 2, this.BreakoutGame_score_var, 5, 2);
}

BreakoutGame.prototype.drawLives = function() {
	this.bus.emit('display?setColor', this.BreakoutGame_fgcolor_var[0]
	, this.BreakoutGame_fgcolor_var[1]
	, this.BreakoutGame_fgcolor_var[2]
	);
	this.bus.emit('display?fillRect', 124, 4, 24 + 6, 6);
	this.bus.emit('display?setColor', 183, 199, 111);
	let i_var = 0;
	while(i_var < this.BreakoutGame_lives_var) {
	this.bus.emit('display?fillRect', 124 + (2 - i_var) * 12, 4, 6, 6);
	i_var = i_var + 1;
	
	}
}

BreakoutGame.prototype._stop = function() {
	this.root = null;
	this.ready = false;
}

BreakoutGame.prototype._delete = function() {
	this._statemachine = null;
	this._SC_instance = null;
	this.bus.removeAllListeners();
}

BreakoutGame.prototype._init = function() {
	this._SC_instance = new StateJS.StateMachineInstance("SC_instance");
	StateJS.initialise(this._statemachine, this._SC_instance);
	this.ready = true;
}

BreakoutGame.prototype._receive = function(msg) {
	/*msg = {_port:myPort, _msg:myMessage, paramN=paramN, ...}*/
	if (this.ready) {
		StateJS.evaluate(this._statemachine, this._SC_instance, msg);
	} else {
		setTimeout(()=>this._receive(msg),0);
	}
}

BreakoutGame.prototype.receivetimer_timeoutOnclock = function(id) {
	this._receive({_port:"clock", _msg:"timer_timeout", id:id});
}

BreakoutGame.prototype.receivedisplayReadyOndisplay = function() {
	this._receive({_port:"display", _msg:"displayReady"});
}

BreakoutGame.prototype.receivedisplayErrorOndisplay = function() {
	this._receive({_port:"display", _msg:"displayError"});
}

BreakoutGame.prototype.receivepositionOncontroller = function(x, y) {
	this._receive({_port:"controller", _msg:"position", x:x, y:y});
}

BreakoutGame.prototype.receivelostBallOngame = function() {
	this._receive({_port:"game", _msg:"lostBall"});
}

BreakoutGame.prototype.receivenextLevelOngame = function() {
	this._receive({_port:"game", _msg:"nextLevel"});
}

BreakoutGame.prototype.toString = function() {
	let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
	result += '\n\tBRICK_ROWS = ' + this.BreakoutGame_BRICK_ROWS_var;
	result += '\n\tscore = ' + this.BreakoutGame_score_var;
	result += '\n\tbricks = ' + this.BreakoutGame_bricks_var;
	result += '\n\tlives = ' + this.BreakoutGame_lives_var;
	result += '\n\tbr = ' + this.BreakoutGame_br_var;
	result += '\n\tpady = ' + this.BreakoutGame_pady_var;
	result += '\n\tprevPY = ' + this.BreakoutGame_prevPY_var;
	result += '\n\ttone_duration = ' + this.BreakoutGame_tone_duration_var;
	result += '\n\tby = ' + this.BreakoutGame_by_var;
	result += '\n\tprevPX = ' + this.BreakoutGame_prevPX_var;
	result += '\n\tlevel = ' + this.BreakoutGame_level_var;
	result += '\n\tBOTTOM = ' + this.BreakoutGame_BOTTOM_var;
	result += '\n\tRIGHT = ' + this.BreakoutGame_RIGHT_var;
	result += '\n\tbgcolor = ' + this.BreakoutGame_bgcolor_var;
	result += '\n\tprevBX = ' + this.BreakoutGame_prevBX_var;
	result += '\n\tpadlen = ' + this.BreakoutGame_padlen_var;
	result += '\n\tprevBY = ' + this.BreakoutGame_prevBY_var;
	result += '\n\tXMAX = ' + this.BreakoutGame_XMAX_var;
	result += '\n\tXDISPSIZE = ' + this.BreakoutGame_XDISPSIZE_var;
	result += '\n\ttone1 = ' + this.BreakoutGame_tone1_var;
	result += '\n\tYMAX = ' + this.BreakoutGame_YMAX_var;
	result += '\n\tperiod = ' + this.BreakoutGame_period_var;
	result += '\n\tLEFT = ' + this.BreakoutGame_LEFT_var;
	result += '\n\tfgcolor = ' + this.BreakoutGame_fgcolor_var;
	result += '\n\ttone2 = ' + this.BreakoutGame_tone2_var;
	result += '\n\tYDISPSIZE = ' + this.BreakoutGame_YDISPSIZE_var;
	result += '\n\tSCALE = ' + this.BreakoutGame_SCALE_var;
	result += '\n\tbx = ' + this.BreakoutGame_bx_var;
	result += '\n\tTOP = ' + this.BreakoutGame_TOP_var;
	result += '\n\tdx = ' + this.BreakoutGame_dx_var;
	result += '\n\tdy = ' + this.BreakoutGame_dy_var;
	result += '\n\tcountdown = ' + this.BreakoutGame_SC_LAUNCH_countdown_var;
	result += '\n\tpadx = ' + this.BreakoutGame_padx_var;
	result += '\n\tBRICK_HEIGHT = ' + this.BreakoutGame_BRICK_HEIGHT_var;
	result += '';
	return result;
}

