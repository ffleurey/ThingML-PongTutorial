'use strict';

var RunThingMLConfiguration = function() {
/*$REQUIRE_PLUGINS$*/
var timer_Timeouts = {};
/*$CONFIGURATION timer$*/
const timer = new TimerBrowser('timer', null, timer_Timeouts, false);
var bb_fgcolor = [];
var bb_bgcolor = [];
var bb_bricks = [];
var bb_LEFT = 1 * 64;
var bb_score = 0;
var bb_prevPY =  -1;
var bb_BRICK_HEIGHT = 9;
var bb_padx = Math.floor(128 * 64 / 2);
var bb_by = 128 * 64;
var bb_TOP = 14 * 64;
var bb_BOTTOM = 128 * 64 + 8 * 64;
var bb_bx = Math.floor(160 * 64 / 2);
var bb_dy = Math.floor( -160 * 64 / 65);
var bb_RIGHT = 160 * 64 - 1 * 64;
var bb_br = 3 * 64;
var bb_YDISPSIZE = 128;
var bb_prevBY =  -1;
var bb_SCALE = 64;
var bb_padlen = Math.floor(160 * 64 / 6);
var bb_prevPX =  -1;
var bb_dx = Math.floor(160 * 64 / 98);
var bb_lives = 3;
var bb_level = 1;
var bb_pady = 128 * 64 - 6 * 64;
var bb_BRICK_ROWS = 5;
var bb_XDISPSIZE = 160;
var bb_XMAX = 160 * 64;
var bb_YMAX = 128 * 64;
var bb_prevBX =  -1;
/*$CONFIGURATION bb$*/
const bb = new SimpleBrick('bb', null, bb_LEFT, bb_score, bb_prevPY, bb_BRICK_HEIGHT, bb_padx, bb_by, bb_TOP, bb_fgcolor, bb_BOTTOM, bb_bx, bb_dy, bb_RIGHT, bb_br, bb_YDISPSIZE, bb_prevBY, bb_bgcolor, bb_SCALE, bb_padlen, bb_prevPX, bb_dx, bb_lives, bb_level, bb_pady, bb_BRICK_ROWS, bb_XDISPSIZE, bb_bricks, bb_XMAX, bb_YMAX, bb_prevBX, false);
var ctrl_YMAX = 100;
var ctrl_XMIN =  -100;
var ctrl_timerID = 4;
var ctrl_dy = 0;
var ctrl_posX = 0;
var ctrl_posY = 0;
var ctrl_XMAX = 100;
var ctrl_YMIN =  -100;
var ctrl_dx = 0;
/*$CONFIGURATION ctrl$*/
const ctrl = new VelocityController('ctrl', null, ctrl_YMAX, ctrl_XMIN, ctrl_timerID, ctrl_dy, ctrl_posX, ctrl_posY, ctrl_XMAX, ctrl_YMIN, ctrl_dx, false);
var disp_YFRAMESIZE = null;
var disp_Display = null;
var disp_SCALE = 5;
var disp_XFRAMESIZE = null;
var disp_Buffer = null;
var disp_BufferCanvas = null;
/*$CONFIGURATION disp$*/
const disp = new BrowserCanvasDisplay('disp', null, disp_YFRAMESIZE, disp_Display, disp_SCALE, disp_XFRAMESIZE, disp_Buffer, disp_BufferCanvas, false);
/*$PLUGINS$*/
//Connecting internal ports...
bb.bus.on('game?lostBall', () => bb.receivelostBallOngame());
bb.bus.on('game?nextLevel', () => bb.receivenextLevelOngame());
//Connecting ports...
ctrl.bus.on('controls?position', (x, y) => bb.receivepositionOncontroller(x, y));
disp.bus.on('vctrl?velocity', (dx, dy) => ctrl.receivevelocityOnctrl_in(dx, dy));
disp.bus.on('vctrl?fire', (id) => ctrl.receivefireOnctrl_in(id));
disp.bus.on('vctrl?position', (x, y) => ctrl.receivepositionOnctrl_in(x, y));
disp.bus.on('display?displayReady', () => bb.receivedisplayReadyOndisplay());
disp.bus.on('display?displayError', () => bb.receivedisplayErrorOndisplay());
bb.bus.on('display?create', (xsize, ysize) => disp.receivecreateOndisplay(xsize, ysize));
bb.bus.on('display?update', () => disp.receiveupdateOndisplay());
bb.bus.on('display?clear', () => disp.receiveclearOndisplay());
bb.bus.on('display?setColor', (r, g, b) => disp.receivesetColorOndisplay(r, g, b));
bb.bus.on('display?setBGColor', (r, g, b) => disp.receivesetBGColorOndisplay(r, g, b));
bb.bus.on('display?drawRect', (x, y, width, height) => disp.receivedrawRectOndisplay(x, y, width, height));
bb.bus.on('display?fillRect', (x, y, width, height) => disp.receivefillRectOndisplay(x, y, width, height));
bb.bus.on('display?drawInteger', (x, y, v, digits, scale) => disp.receivedrawIntegerOndisplay(x, y, v, digits, scale));
timer.bus.on('timer?timer_timeout', (id) => bb.receivetimer_timeoutOnclock(id));
bb.bus.on('clock?timer_start', (id, time) => timer.receivetimer_startOntimer(id, time));
bb.bus.on('clock?timer_cancel', (id) => timer.receivetimer_cancelOntimer(id));
timer.bus.on('timer?timer_timeout', (id) => ctrl.receivetimer_timeoutOnclock(id));
ctrl.bus.on('clock?timer_start', (id, time) => timer.receivetimer_startOntimer(id, time));
ctrl.bus.on('clock?timer_cancel', (id) => timer.receivetimer_cancelOntimer(id));
/*$PLUGINS_CONNECTORS$*/
timer._init();
disp._init();
ctrl._init();
bb._init();
/*$PLUGINS_END$*/
};

window.addEventListener('DOMContentLoaded', function(){
	RunThingMLConfiguration();
});
