'use strict';

StateJS.internalTransitionsTriggerCompletion = true;

/**
 * Definition for type : SimpleBrick
 **/
function SimpleBrick(name, root, SimpleBrick_BOTTOM_var, SimpleBrick_prevBY_var, SimpleBrick_prevPY_var, SimpleBrick_fgcolor_var, SimpleBrick_BRICK_ROWS_var, SimpleBrick_prevPX_var, SimpleBrick_br_var, SimpleBrick_padlen_var, SimpleBrick_prevBX_var, SimpleBrick_lives_var, SimpleBrick_level_var, SimpleBrick_YMAX_var, SimpleBrick_dy_var, SimpleBrick_XDISPSIZE_var, SimpleBrick_bgcolor_var, SimpleBrick_YDISPSIZE_var, SimpleBrick_BRICK_HEIGHT_var, SimpleBrick_TOP_var, SimpleBrick_LEFT_var, SimpleBrick_score_var, SimpleBrick_XMAX_var, SimpleBrick_padx_var, SimpleBrick_pady_var, SimpleBrick_bricks_var, SimpleBrick_by_var, SimpleBrick_SCALE_var, SimpleBrick_dx_var, SimpleBrick_RIGHT_var, SimpleBrick_bx_var, debug) {

this.name = name;
this.root = (root === null)? this : root;
this.debug = debug;
this.ready = false;
this.bus = new EventEmitter();
//Attributes
this.SimpleBrick_BOTTOM_var = SimpleBrick_BOTTOM_var;
this.debug_SimpleBrick_BOTTOM_var = SimpleBrick_BOTTOM_var;
this.SimpleBrick_prevBY_var = SimpleBrick_prevBY_var;
this.debug_SimpleBrick_prevBY_var = SimpleBrick_prevBY_var;
this.SimpleBrick_prevPY_var = SimpleBrick_prevPY_var;
this.debug_SimpleBrick_prevPY_var = SimpleBrick_prevPY_var;
this.SimpleBrick_fgcolor_var = SimpleBrick_fgcolor_var;
this.debug_SimpleBrick_fgcolor_var = SimpleBrick_fgcolor_var;
this.SimpleBrick_BRICK_ROWS_var = SimpleBrick_BRICK_ROWS_var;
this.debug_SimpleBrick_BRICK_ROWS_var = SimpleBrick_BRICK_ROWS_var;
this.SimpleBrick_prevPX_var = SimpleBrick_prevPX_var;
this.debug_SimpleBrick_prevPX_var = SimpleBrick_prevPX_var;
this.SimpleBrick_br_var = SimpleBrick_br_var;
this.debug_SimpleBrick_br_var = SimpleBrick_br_var;
this.SimpleBrick_padlen_var = SimpleBrick_padlen_var;
this.debug_SimpleBrick_padlen_var = SimpleBrick_padlen_var;
this.SimpleBrick_prevBX_var = SimpleBrick_prevBX_var;
this.debug_SimpleBrick_prevBX_var = SimpleBrick_prevBX_var;
this.SimpleBrick_lives_var = SimpleBrick_lives_var;
this.debug_SimpleBrick_lives_var = SimpleBrick_lives_var;
this.SimpleBrick_level_var = SimpleBrick_level_var;
this.debug_SimpleBrick_level_var = SimpleBrick_level_var;
this.SimpleBrick_YMAX_var = SimpleBrick_YMAX_var;
this.debug_SimpleBrick_YMAX_var = SimpleBrick_YMAX_var;
this.SimpleBrick_dy_var = SimpleBrick_dy_var;
this.debug_SimpleBrick_dy_var = SimpleBrick_dy_var;
this.SimpleBrick_XDISPSIZE_var = SimpleBrick_XDISPSIZE_var;
this.debug_SimpleBrick_XDISPSIZE_var = SimpleBrick_XDISPSIZE_var;
this.SimpleBrick_bgcolor_var = SimpleBrick_bgcolor_var;
this.debug_SimpleBrick_bgcolor_var = SimpleBrick_bgcolor_var;
this.SimpleBrick_YDISPSIZE_var = SimpleBrick_YDISPSIZE_var;
this.debug_SimpleBrick_YDISPSIZE_var = SimpleBrick_YDISPSIZE_var;
this.SimpleBrick_BRICK_HEIGHT_var = SimpleBrick_BRICK_HEIGHT_var;
this.debug_SimpleBrick_BRICK_HEIGHT_var = SimpleBrick_BRICK_HEIGHT_var;
this.SimpleBrick_TOP_var = SimpleBrick_TOP_var;
this.debug_SimpleBrick_TOP_var = SimpleBrick_TOP_var;
this.SimpleBrick_LEFT_var = SimpleBrick_LEFT_var;
this.debug_SimpleBrick_LEFT_var = SimpleBrick_LEFT_var;
this.SimpleBrick_score_var = SimpleBrick_score_var;
this.debug_SimpleBrick_score_var = SimpleBrick_score_var;
this.SimpleBrick_XMAX_var = SimpleBrick_XMAX_var;
this.debug_SimpleBrick_XMAX_var = SimpleBrick_XMAX_var;
this.SimpleBrick_padx_var = SimpleBrick_padx_var;
this.debug_SimpleBrick_padx_var = SimpleBrick_padx_var;
this.SimpleBrick_pady_var = SimpleBrick_pady_var;
this.debug_SimpleBrick_pady_var = SimpleBrick_pady_var;
this.SimpleBrick_bricks_var = SimpleBrick_bricks_var;
this.debug_SimpleBrick_bricks_var = SimpleBrick_bricks_var;
this.SimpleBrick_by_var = SimpleBrick_by_var;
this.debug_SimpleBrick_by_var = SimpleBrick_by_var;
this.SimpleBrick_SCALE_var = SimpleBrick_SCALE_var;
this.debug_SimpleBrick_SCALE_var = SimpleBrick_SCALE_var;
this.SimpleBrick_SC_LAUNCH_countdown_var;
this.SimpleBrick_dx_var = SimpleBrick_dx_var;
this.debug_SimpleBrick_dx_var = SimpleBrick_dx_var;
this.SimpleBrick_RIGHT_var = SimpleBrick_RIGHT_var;
this.debug_SimpleBrick_RIGHT_var = SimpleBrick_RIGHT_var;
this.SimpleBrick_bx_var = SimpleBrick_bx_var;
this.debug_SimpleBrick_bx_var = SimpleBrick_bx_var;
this.build(name);
}
//State machine (states and regions)
SimpleBrick.prototype.build = function(session) {//optional session name and root instance to fork a new session
this.statemachine = new StateJS.StateMachine('SC');
this._initial_SimpleBrick_SC = new StateJS.PseudoState('_initial', this.statemachine, StateJS.PseudoStateKind.Initial);
let SimpleBrick_SC_INIT = new StateJS.State('INIT', this.statemachine).entry(() => {
this.bus.emit('display?create', this.SimpleBrick_XDISPSIZE_var, this.SimpleBrick_YDISPSIZE_var);
});
let SimpleBrick_SC_LAUNCH = new StateJS.State('LAUNCH', this.statemachine).entry(() => {
this.bus.emit('clock?timer_start', 0, 33);
this.SimpleBrick_SC_LAUNCH_countdown_var = 30 * 3;
this.drawScore();
this.drawLives();
this.bus.emit('display?update');
});
let SimpleBrick_SC_PLAY = new StateJS.State('PLAY', this.statemachine).entry(() => {
this.bus.emit('clock?timer_start', 0, 33);
});
let SimpleBrick_SC_LOSTBALL = new StateJS.State('LOSTBALL', this.statemachine).entry(() => {
this.bus.emit('clock?timer_start', 0, 1000);
this.SimpleBrick_lives_var = this.SimpleBrick_lives_var - 1;
this.bus.emit('lives=', this.SimpleBrick_lives_var);
this.eraseBall();
this.erasePad();
this.drawLives();
this.bus.emit('display?update');
});
let SimpleBrick_SC_NEXTLEVEL = new StateJS.State('NEXTLEVEL', this.statemachine).entry(() => {
this.bus.emit('clock?timer_start', 0, 1000);
this.SimpleBrick_level_var = this.SimpleBrick_level_var + 1;
this.bus.emit('level=', this.SimpleBrick_level_var);
this.eraseBall();
this.erasePad();
this.drawLives();
this.createBricks();
this.bus.emit('display?update');
});
let SimpleBrick_SC_GAMEOVER = new StateJS.State('GAMEOVER', this.statemachine).entry(() => {
this.bus.emit('clock?timer_start', 0, 500);
this.SimpleBrick_lives_var = this.SimpleBrick_lives_var - 1;
this.bus.emit('lives=', this.SimpleBrick_lives_var);
this.eraseBall();
this.erasePad();
this.bus.emit('display?setColor', 255, 255, 255);
this.bus.emit('display?drawRect', 10, 46, 140, 50);
this.bus.emit('display?setColor', this.SimpleBrick_fgcolor_var[0]
, this.SimpleBrick_fgcolor_var[1]
, this.SimpleBrick_fgcolor_var[2]
);
this.bus.emit('display?fillRect', 11, 47, 138, 48);
this.bus.emit('display?setBGColor', this.SimpleBrick_fgcolor_var[0]
, this.SimpleBrick_fgcolor_var[1]
, this.SimpleBrick_fgcolor_var[2]
);
this.bus.emit('display?setColor', 158, 209, 130);
this.bus.emit('display?drawInteger', 23, 56, this.SimpleBrick_score_var, 5, 6);
this.bus.emit('display?update');
});
this._initial_SimpleBrick_SC.to(SimpleBrick_SC_INIT);
this.statemachine.to(null).when((position) => {return position._port === 'controller' && position._msg === 'position';}).effect((position) => {
let center_var = (this.SimpleBrick_RIGHT_var - this.SimpleBrick_LEFT_var - this.SimpleBrick_padlen_var);
center_var = position.x * center_var;
center_var = center_var / 200;
this.SimpleBrick_padx_var = this.SimpleBrick_LEFT_var + center_var + (this.SimpleBrick_RIGHT_var - this.SimpleBrick_LEFT_var) / 2;
this.bus.emit('padx=', this.SimpleBrick_padx_var);
});
SimpleBrick_SC_INIT.to(SimpleBrick_SC_LAUNCH).when((displayReady) => {return displayReady._port === 'display' && displayReady._msg === 'displayReady';}).effect((displayReady) => {
this.bus.emit('display?clear');
this.initColors();
this.bus.emit('display?setColor', this.SimpleBrick_bgcolor_var[0]
, this.SimpleBrick_bgcolor_var[1]
, this.SimpleBrick_bgcolor_var[2]
);
this.bus.emit('display?fillRect', 0, 0, this.SimpleBrick_XDISPSIZE_var, this.SimpleBrick_YDISPSIZE_var);
this.bus.emit('display?setColor', this.SimpleBrick_fgcolor_var[0]
, this.SimpleBrick_fgcolor_var[1]
, this.SimpleBrick_fgcolor_var[2]
);
this.bus.emit('display?fillRect', 0, 0, this.SimpleBrick_XDISPSIZE_var, 1);
this.bus.emit('display?fillRect', 0, 0, 18, 14);
this.bus.emit('display?fillRect', 90 - 28, 0, 28, 14);
this.bus.emit('display?fillRect', this.SimpleBrick_XDISPSIZE_var - 18, 0, 18, 14);
this.drawWalls();
this.createBricks();
});
SimpleBrick_SC_LAUNCH.to(SimpleBrick_SC_PLAY).when((timer_timeout) => {return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && timer_timeout.id === 0 && this.SimpleBrick_SC_LAUNCH_countdown_var === 0;}).effect((timer_timeout) => {
this.drawCountDown(0);
this.resetBall();
this.bus.emit('display?update');
});
SimpleBrick_SC_LAUNCH.to(null).when((timer_timeout) => {return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && timer_timeout.id === 0 && this.SimpleBrick_SC_LAUNCH_countdown_var > 0;}).effect((timer_timeout) => {
this.bus.emit('clock?timer_start', 0, 33);
this.drawPad();
this.drawCountDown(this.SimpleBrick_SC_LAUNCH_countdown_var / 30 + 1);
this.SimpleBrick_SC_LAUNCH_countdown_var = this.SimpleBrick_SC_LAUNCH_countdown_var - 1;
this.bus.emit('display?update');
});
SimpleBrick_SC_PLAY.to(null).when((timer_timeout) => {return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && timer_timeout.id === 0;}).effect((timer_timeout) => {
this.SimpleBrick_bx_var = this.SimpleBrick_bx_var + this.SimpleBrick_dx_var;
this.bus.emit('bx=', this.SimpleBrick_bx_var);
this.SimpleBrick_by_var = this.SimpleBrick_by_var + this.SimpleBrick_dy_var;
this.bus.emit('by=', this.SimpleBrick_by_var);
let wl_var = this.SimpleBrick_LEFT_var + this.SimpleBrick_br_var;
let wr_var = this.SimpleBrick_RIGHT_var - this.SimpleBrick_br_var;
let wt_var = this.SimpleBrick_TOP_var + this.SimpleBrick_br_var;
let wb_var = this.SimpleBrick_BOTTOM_var - this.SimpleBrick_br_var;
if(this.SimpleBrick_bx_var < wl_var) {
this.SimpleBrick_dx_var =  -this.SimpleBrick_dx_var;
this.bus.emit('dx=', this.SimpleBrick_dx_var);
this.SimpleBrick_bx_var = 2 * wl_var - this.SimpleBrick_bx_var;
this.bus.emit('bx=', this.SimpleBrick_bx_var);

} else {
if(this.SimpleBrick_bx_var > wr_var) {
this.SimpleBrick_dx_var =  -this.SimpleBrick_dx_var;
this.bus.emit('dx=', this.SimpleBrick_dx_var);
this.SimpleBrick_bx_var = 2 * wr_var - this.SimpleBrick_bx_var;
this.bus.emit('bx=', this.SimpleBrick_bx_var);

}

}
if(this.SimpleBrick_by_var < wt_var) {
this.SimpleBrick_dy_var =  -this.SimpleBrick_dy_var;
this.bus.emit('dy=', this.SimpleBrick_dy_var);
this.SimpleBrick_by_var = 2 * wt_var - this.SimpleBrick_by_var;
this.bus.emit('by=', this.SimpleBrick_by_var);

} else {
if(this.SimpleBrick_by_var > wb_var) {
this.bus.emit('game?lostBall');

}

}
if(this.SimpleBrick_dy_var > 0) {
if(this.SimpleBrick_by_var > this.SimpleBrick_pady_var - this.SimpleBrick_br_var && this.SimpleBrick_by_var < this.SimpleBrick_pady_var + this.SimpleBrick_br_var) {
if(this.SimpleBrick_bx_var > this.SimpleBrick_padx_var - this.SimpleBrick_padlen_var / 2 && this.SimpleBrick_bx_var < this.SimpleBrick_padx_var + this.SimpleBrick_padlen_var / 2) {
this.SimpleBrick_dy_var =  -this.SimpleBrick_dy_var;
this.bus.emit('dy=', this.SimpleBrick_dy_var);
this.SimpleBrick_by_var = 2 * (this.SimpleBrick_pady_var - this.SimpleBrick_br_var) - this.SimpleBrick_by_var;
this.bus.emit('by=', this.SimpleBrick_by_var);
this.SimpleBrick_dx_var = this.SimpleBrick_dx_var / 4 + (this.SimpleBrick_bx_var - this.SimpleBrick_padx_var) / 4;
this.bus.emit('dx=', this.SimpleBrick_dx_var);

}

}

}
let collision_var = this.collideBrick(this.SimpleBrick_bx_var - this.SimpleBrick_br_var, this.SimpleBrick_by_var - this.SimpleBrick_br_var) || this.collideBrick(this.SimpleBrick_bx_var + this.SimpleBrick_br_var, this.SimpleBrick_by_var - this.SimpleBrick_br_var) || this.collideBrick(this.SimpleBrick_bx_var + this.SimpleBrick_br_var, this.SimpleBrick_by_var + this.SimpleBrick_br_var) || this.collideBrick(this.SimpleBrick_bx_var - this.SimpleBrick_br_var, this.SimpleBrick_by_var + this.SimpleBrick_br_var);
if(collision_var) {
this.SimpleBrick_dy_var =  -this.SimpleBrick_dy_var;
this.bus.emit('dy=', this.SimpleBrick_dy_var);
this.SimpleBrick_score_var = this.SimpleBrick_score_var + 10;
this.bus.emit('score=', this.SimpleBrick_score_var);
this.drawScore();
if(this.bricksLeft() === 0) {
this.bus.emit('game?nextLevel');

}

}
this.drawBall();
this.drawPad();
this.bus.emit('display?update');
this.bus.emit('clock?timer_start', 0, 33);
});
SimpleBrick_SC_LOSTBALL.to(SimpleBrick_SC_LAUNCH).when((timer_timeout) => {return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && timer_timeout.id === 0 && this.SimpleBrick_lives_var > 0;});
SimpleBrick_SC_LOSTBALL.to(SimpleBrick_SC_GAMEOVER).when((timer_timeout) => {return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && timer_timeout.id === 0 && this.SimpleBrick_lives_var === 0;});
SimpleBrick_SC_NEXTLEVEL.to(SimpleBrick_SC_LAUNCH).when((timer_timeout) => {return timer_timeout._port === 'clock' && timer_timeout._msg === 'timer_timeout' && timer_timeout.id === 0;});
SimpleBrick_SC_PLAY.to(SimpleBrick_SC_LOSTBALL).when((lostBall) => {return lostBall._port === 'game' && lostBall._msg === 'lostBall';});
SimpleBrick_SC_PLAY.to(SimpleBrick_SC_NEXTLEVEL).when((nextLevel) => {return nextLevel._port === 'game' && nextLevel._msg === 'nextLevel';});
}
//ThingML-defined functions
SimpleBrick.prototype.initColors = function() {
this.SimpleBrick_bgcolor_var[0] = 53;
this.bus.emit('bgcolor=', this.SimpleBrick_bgcolor_var);
this.SimpleBrick_bgcolor_var[1] = 40;
this.bus.emit('bgcolor=', this.SimpleBrick_bgcolor_var);
this.SimpleBrick_bgcolor_var[2] = 120;
this.bus.emit('bgcolor=', this.SimpleBrick_bgcolor_var);
this.SimpleBrick_fgcolor_var[0] = 107;
this.bus.emit('fgcolor=', this.SimpleBrick_fgcolor_var);
this.SimpleBrick_fgcolor_var[1] = 94;
this.bus.emit('fgcolor=', this.SimpleBrick_fgcolor_var);
this.SimpleBrick_fgcolor_var[2] = 174;
this.bus.emit('fgcolor=', this.SimpleBrick_fgcolor_var);
this.bus.emit('display?setBGColor', this.SimpleBrick_bgcolor_var[0]
, this.SimpleBrick_bgcolor_var[1]
, this.SimpleBrick_bgcolor_var[2]
);
this.bus.emit('display?setColor', this.SimpleBrick_fgcolor_var[0]
, this.SimpleBrick_fgcolor_var[1]
, this.SimpleBrick_fgcolor_var[2]
);
};

SimpleBrick.prototype.resetBall = function() {
this.SimpleBrick_bx_var = this.SimpleBrick_padx_var - this.SimpleBrick_br_var / this.SimpleBrick_SCALE_var;
this.bus.emit('bx=', this.SimpleBrick_bx_var);
this.SimpleBrick_by_var = this.SimpleBrick_pady_var - this.SimpleBrick_br_var / this.SimpleBrick_SCALE_var;
this.bus.emit('by=', this.SimpleBrick_by_var);
this.SimpleBrick_dx_var = this.SimpleBrick_XMAX_var / 98;
this.bus.emit('dx=', this.SimpleBrick_dx_var);
this.SimpleBrick_dy_var =  -this.SimpleBrick_XMAX_var / 65;
this.bus.emit('dy=', this.SimpleBrick_dy_var);
};

SimpleBrick.prototype.eraseBall = function() {
let bs_var = (this.SimpleBrick_br_var * 2) / this.SimpleBrick_SCALE_var;
if(this.SimpleBrick_prevBX_var > 0) {
this.bus.emit('display?setColor', this.SimpleBrick_bgcolor_var[0]
, this.SimpleBrick_bgcolor_var[1]
, this.SimpleBrick_bgcolor_var[2]
);
this.bus.emit('display?fillRect', this.SimpleBrick_prevBX_var, this.SimpleBrick_prevBY_var, bs_var, bs_var);

}
};

SimpleBrick.prototype.drawBall = function() {
let bs_var = (this.SimpleBrick_br_var * 2) / this.SimpleBrick_SCALE_var;
this.eraseBall();
this.SimpleBrick_prevBX_var = (this.SimpleBrick_bx_var - this.SimpleBrick_br_var) / this.SimpleBrick_SCALE_var;
this.bus.emit('prevBX=', this.SimpleBrick_prevBX_var);
this.SimpleBrick_prevBY_var = (this.SimpleBrick_by_var - this.SimpleBrick_br_var) / this.SimpleBrick_SCALE_var;
this.bus.emit('prevBY=', this.SimpleBrick_prevBY_var);
this.bus.emit('display?setColor', 183, 199, 111);
this.bus.emit('display?fillRect', this.SimpleBrick_prevBX_var, this.SimpleBrick_prevBY_var, bs_var, bs_var);
};

SimpleBrick.prototype.erasePad = function() {
let ps_var = this.SimpleBrick_padlen_var / this.SimpleBrick_SCALE_var;
if(this.SimpleBrick_prevPX_var > 0) {
this.bus.emit('display?setColor', this.SimpleBrick_bgcolor_var[0]
, this.SimpleBrick_bgcolor_var[1]
, this.SimpleBrick_bgcolor_var[2]
);
this.bus.emit('display?fillRect', this.SimpleBrick_prevPX_var, this.SimpleBrick_prevPY_var, ps_var, 4);

}
};

SimpleBrick.prototype.drawPad = function() {
let ps_var = this.SimpleBrick_padlen_var / this.SimpleBrick_SCALE_var;
this.erasePad();
this.SimpleBrick_prevPX_var = (this.SimpleBrick_padx_var - (this.SimpleBrick_padlen_var / 2)) / this.SimpleBrick_SCALE_var;
this.bus.emit('prevPX=', this.SimpleBrick_prevPX_var);
this.SimpleBrick_prevPY_var = this.SimpleBrick_pady_var / this.SimpleBrick_SCALE_var;
this.bus.emit('prevPY=', this.SimpleBrick_prevPY_var);
this.bus.emit('display?setColor', this.SimpleBrick_fgcolor_var[0]
, this.SimpleBrick_fgcolor_var[1]
, this.SimpleBrick_fgcolor_var[2]
);
this.bus.emit('display?fillRect', this.SimpleBrick_prevPX_var, this.SimpleBrick_prevPY_var, ps_var, 4);
};

SimpleBrick.prototype.drawCountDown = function(SimpleBrick_drawCountDown_c_var) {
this.bus.emit('display?setColor', this.SimpleBrick_fgcolor_var[0]
, this.SimpleBrick_fgcolor_var[1]
, this.SimpleBrick_fgcolor_var[2]
);
if(SimpleBrick_drawCountDown_c_var > 0) {
this.bus.emit('display?setColor', this.SimpleBrick_fgcolor_var[0]
, this.SimpleBrick_fgcolor_var[1]
, this.SimpleBrick_fgcolor_var[2]
);
this.bus.emit('display?setBGColor', this.SimpleBrick_bgcolor_var[0]
, this.SimpleBrick_bgcolor_var[1]
, this.SimpleBrick_bgcolor_var[2]
);
this.bus.emit('display?drawInteger', 80 - 6, 90, SimpleBrick_drawCountDown_c_var, 1, 4);

} else {
this.bus.emit('display?setColor', this.SimpleBrick_bgcolor_var[0]
, this.SimpleBrick_bgcolor_var[1]
, this.SimpleBrick_bgcolor_var[2]
);
this.bus.emit('display?fillRect', 80 - 6, 90, 12, 20);

}
};

SimpleBrick.prototype.drawWalls = function() {
this.bus.emit('display?setColor', this.SimpleBrick_fgcolor_var[0]
, this.SimpleBrick_fgcolor_var[1]
, this.SimpleBrick_fgcolor_var[2]
);
this.bus.emit('display?fillRect', this.SimpleBrick_LEFT_var / this.SimpleBrick_SCALE_var - 1, this.SimpleBrick_TOP_var / this.SimpleBrick_SCALE_var - 1, (this.SimpleBrick_RIGHT_var - this.SimpleBrick_LEFT_var) / this.SimpleBrick_SCALE_var + 1, 1);
this.bus.emit('display?fillRect', this.SimpleBrick_LEFT_var / this.SimpleBrick_SCALE_var - 1, this.SimpleBrick_BOTTOM_var / this.SimpleBrick_SCALE_var - 1, (this.SimpleBrick_RIGHT_var - this.SimpleBrick_LEFT_var) / this.SimpleBrick_SCALE_var + 1, 1);
this.bus.emit('display?fillRect', this.SimpleBrick_LEFT_var / this.SimpleBrick_SCALE_var - 1, this.SimpleBrick_TOP_var / this.SimpleBrick_SCALE_var, 1, (this.SimpleBrick_BOTTOM_var - this.SimpleBrick_TOP_var) / this.SimpleBrick_SCALE_var);
this.bus.emit('display?fillRect', this.SimpleBrick_RIGHT_var / this.SimpleBrick_SCALE_var - 1, this.SimpleBrick_TOP_var / this.SimpleBrick_SCALE_var, 1, (this.SimpleBrick_BOTTOM_var - this.SimpleBrick_TOP_var) / this.SimpleBrick_SCALE_var);
};

SimpleBrick.prototype.bitIsSet = function(SimpleBrick_bitIsSet_variable_var, SimpleBrick_bitIsSet_bit_var) {
return ((1 << SimpleBrick_bitIsSet_bit_var) & SimpleBrick_bitIsSet_variable_var) != 0;
};

SimpleBrick.prototype.setBit = function(SimpleBrick_setBit_variable_var, SimpleBrick_setBit_bit_var) {
return SimpleBrick_setBit_variable_var | (1 << SimpleBrick_setBit_bit_var);
};

SimpleBrick.prototype.unsetBit = function(SimpleBrick_unsetBit_variable_var, SimpleBrick_unsetBit_bit_var) {
return SimpleBrick_unsetBit_variable_var & ~(1 << SimpleBrick_unsetBit_bit_var);
};

SimpleBrick.prototype.createBricks = function() {
let y_var = 0;
while(y_var < this.SimpleBrick_BRICK_ROWS_var) {
this.SimpleBrick_bricks_var[y_var] = 0xFF;
this.bus.emit('bricks=', this.SimpleBrick_bricks_var);
let x_var = 0;
while(x_var < 8) {
if(this.bitIsSet(this.SimpleBrick_bricks_var[y_var]
, x_var)) {
this.drawBrick(x_var, y_var);

}
x_var = x_var + 1;

}
y_var = y_var + 1;

}
};

SimpleBrick.prototype.bricksLeft = function() {
let result_var = 0;
let y_var = 0;
while(y_var < this.SimpleBrick_BRICK_ROWS_var) {
let x_var = 0;
while(x_var < 8) {
if(this.bitIsSet(this.SimpleBrick_bricks_var[y_var]
, x_var)) {
result_var = result_var + 1;

}
x_var = x_var + 1;

}
y_var = y_var + 1;

}
return result_var;
};

SimpleBrick.prototype.drawBrick = function(SimpleBrick_drawBrick_x_var, SimpleBrick_drawBrick_y_var) {
let bx_var = this.SimpleBrick_LEFT_var + ((this.SimpleBrick_RIGHT_var - this.SimpleBrick_LEFT_var) / 8) * SimpleBrick_drawBrick_x_var;
let by_var = this.SimpleBrick_TOP_var + 20 * this.SimpleBrick_SCALE_var + this.SimpleBrick_BRICK_HEIGHT_var * SimpleBrick_drawBrick_y_var * this.SimpleBrick_SCALE_var;
this.bus.emit('display?setColor', 155, 103, 89);
this.bus.emit('display?fillRect', bx_var / this.SimpleBrick_SCALE_var + 1, by_var / this.SimpleBrick_SCALE_var + 1, ((this.SimpleBrick_RIGHT_var - this.SimpleBrick_LEFT_var) / 8) / this.SimpleBrick_SCALE_var - 2, this.SimpleBrick_BRICK_HEIGHT_var - 2);
this.bus.emit('display?setColor', 100, 56, 43);
this.bus.emit('display?drawRect', bx_var / this.SimpleBrick_SCALE_var + 1, by_var / this.SimpleBrick_SCALE_var + 1, ((this.SimpleBrick_RIGHT_var - this.SimpleBrick_LEFT_var) / 8) / this.SimpleBrick_SCALE_var - 2, this.SimpleBrick_BRICK_HEIGHT_var - 2);
};

SimpleBrick.prototype.removeBrick = function(SimpleBrick_removeBrick_x_var, SimpleBrick_removeBrick_y_var) {
let bx_var = this.SimpleBrick_LEFT_var + ((this.SimpleBrick_RIGHT_var - this.SimpleBrick_LEFT_var) / 8) * SimpleBrick_removeBrick_x_var;
let by_var = this.SimpleBrick_TOP_var + 20 * this.SimpleBrick_SCALE_var + this.SimpleBrick_BRICK_HEIGHT_var * SimpleBrick_removeBrick_y_var * this.SimpleBrick_SCALE_var;
this.bus.emit('display?setColor', this.SimpleBrick_bgcolor_var[0]
, this.SimpleBrick_bgcolor_var[1]
, this.SimpleBrick_bgcolor_var[2]
);
this.bus.emit('display?fillRect', bx_var / this.SimpleBrick_SCALE_var + 1, by_var / this.SimpleBrick_SCALE_var + 1, ((this.SimpleBrick_RIGHT_var - this.SimpleBrick_LEFT_var) / 8) / this.SimpleBrick_SCALE_var - 2, this.SimpleBrick_BRICK_HEIGHT_var - 2);
this.SimpleBrick_bricks_var[SimpleBrick_removeBrick_y_var] = this.unsetBit(this.SimpleBrick_bricks_var[SimpleBrick_removeBrick_y_var]
, SimpleBrick_removeBrick_x_var);
this.bus.emit('bricks=', this.SimpleBrick_bricks_var);
};

SimpleBrick.prototype.collideBrick = function(SimpleBrick_collideBrick_xpos_var, SimpleBrick_collideBrick_ypos_var) {
let bry_var = (SimpleBrick_collideBrick_ypos_var - this.SimpleBrick_TOP_var - 20 * this.SimpleBrick_SCALE_var) / (this.SimpleBrick_BRICK_HEIGHT_var * this.SimpleBrick_SCALE_var);
let result_var = false;
if(bry_var >= 0 && bry_var < this.SimpleBrick_BRICK_ROWS_var) {
let brx_var = (SimpleBrick_collideBrick_xpos_var - this.SimpleBrick_LEFT_var) / ((this.SimpleBrick_RIGHT_var - this.SimpleBrick_LEFT_var) / 8);
if(this.bitIsSet(this.SimpleBrick_bricks_var[bry_var]
, brx_var)) {
this.removeBrick(brx_var, bry_var);
result_var = true;

}

}
return result_var;
};

SimpleBrick.prototype.drawScore = function() {
this.bus.emit('display?setColor', 158, 209, 130);
this.bus.emit('display?drawInteger', 98, 2, this.SimpleBrick_score_var, 5, 2);
};

SimpleBrick.prototype.drawLives = function() {
this.bus.emit('display?setColor', this.SimpleBrick_bgcolor_var[0]
, this.SimpleBrick_bgcolor_var[1]
, this.SimpleBrick_bgcolor_var[2]
);
this.bus.emit('display?fillRect', 22, 4, 36, 6);
this.bus.emit('display?setColor', 183, 199, 111);
let i_var = 0;
while(i_var < this.SimpleBrick_lives_var) {
this.bus.emit('display?fillRect', 22 + i_var * 15, 4, 6, 6);
i_var = i_var + 1;

}
};

//Public API for lifecycle management
SimpleBrick.prototype._stop = function() {
this.root = null;
this.ready = false;
};

SimpleBrick.prototype._delete = function() {
this.statemachine = null;
this.SC_instance = null;
this.bus.removeAllListeners();
};

//Public API for third parties
SimpleBrick.prototype._init = function() {
this.SC_instance = new StateJS.StateMachineInstance("SC_instance");
StateJS.initialise(this.statemachine, this.SC_instance );
this.ready = true;
};

SimpleBrick.prototype._receive = function(msg) {//msg = {_port:myPort, _msg:myMessage, paramN=paramN, ...}
if(this.ready){
StateJS.evaluate(this.statemachine, this.SC_instance, msg);
} else { setTimeout(()=>this._receive(msg),0) }};
SimpleBrick.prototype.receivetimer_timeoutOnclock = function(id) {
this._receive({_port:"clock", _msg:"timer_timeout", id:id});
};

SimpleBrick.prototype.receivedisplayReadyOndisplay = function() {
this._receive({_port:"display", _msg:"displayReady"});
};

SimpleBrick.prototype.receivedisplayErrorOndisplay = function() {
this._receive({_port:"display", _msg:"displayError"});
};

SimpleBrick.prototype.receivepositionOncontroller = function(x, y) {
this._receive({_port:"controller", _msg:"position", x:x, y:y});
};

SimpleBrick.prototype.receivelostBallOngame = function() {
this._receive({_port:"game", _msg:"lostBall"});
};

SimpleBrick.prototype.receivenextLevelOngame = function() {
this._receive({_port:"game", _msg:"nextLevel"});
};

SimpleBrick.prototype.toString = function() {
let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
result += '\n\tBOTTOM = ' + this.SimpleBrick_BOTTOM_var;
result += '\n\tprevBY = ' + this.SimpleBrick_prevBY_var;
result += '\n\tprevPY = ' + this.SimpleBrick_prevPY_var;
result += '\n\tfgcolor = ' + this.SimpleBrick_fgcolor_var;
result += '\n\tBRICK_ROWS = ' + this.SimpleBrick_BRICK_ROWS_var;
result += '\n\tprevPX = ' + this.SimpleBrick_prevPX_var;
result += '\n\tbr = ' + this.SimpleBrick_br_var;
result += '\n\tpadlen = ' + this.SimpleBrick_padlen_var;
result += '\n\tprevBX = ' + this.SimpleBrick_prevBX_var;
result += '\n\tlives = ' + this.SimpleBrick_lives_var;
result += '\n\tlevel = ' + this.SimpleBrick_level_var;
result += '\n\tYMAX = ' + this.SimpleBrick_YMAX_var;
result += '\n\tdy = ' + this.SimpleBrick_dy_var;
result += '\n\tXDISPSIZE = ' + this.SimpleBrick_XDISPSIZE_var;
result += '\n\tbgcolor = ' + this.SimpleBrick_bgcolor_var;
result += '\n\tYDISPSIZE = ' + this.SimpleBrick_YDISPSIZE_var;
result += '\n\tBRICK_HEIGHT = ' + this.SimpleBrick_BRICK_HEIGHT_var;
result += '\n\tTOP = ' + this.SimpleBrick_TOP_var;
result += '\n\tLEFT = ' + this.SimpleBrick_LEFT_var;
result += '\n\tscore = ' + this.SimpleBrick_score_var;
result += '\n\tXMAX = ' + this.SimpleBrick_XMAX_var;
result += '\n\tpadx = ' + this.SimpleBrick_padx_var;
result += '\n\tpady = ' + this.SimpleBrick_pady_var;
result += '\n\tbricks = ' + this.SimpleBrick_bricks_var;
result += '\n\tby = ' + this.SimpleBrick_by_var;
result += '\n\tSCALE = ' + this.SimpleBrick_SCALE_var;
result += '\n\tcountdown = ' + this.SimpleBrick_SC_LAUNCH_countdown_var;
result += '\n\tdx = ' + this.SimpleBrick_dx_var;
result += '\n\tRIGHT = ' + this.SimpleBrick_RIGHT_var;
result += '\n\tbx = ' + this.SimpleBrick_bx_var;
result += '';
return result;
};
