'use strict';

var RunThingMLConfiguration = function() {
	/*$REQUIRE_PLUGINS$*/
	
	var game_bricks = [];var game_bgcolor = [];var game_fgcolor = [];
	var game_BRICK_ROWS = 5;
	var game_score = 0;
	var game_lives = 3;
	var game_br = 3 * 64;
	var game_pady = 128 * 64 - 6 * 64;
	var game_prevPY =  -1;
	var game_tone_duration = 50;
	var game_by = 128 * 64;
	var game_prevPX =  -1;
	var game_level = 1;
	var game_BOTTOM = 128 * 64 + 8 * 64;
	var game_RIGHT = 160 * 64 - 1 * 64;
	var game_prevBX =  -1;
	var game_padlen = 25 * 64;
	var game_prevBY =  -1;
	var game_XMAX = 160 * 64;
	var game_XDISPSIZE = 160;
	var game_tone1 = 440;
	var game_YMAX = 128 * 64;
	var game_period = 33;
	var game_LEFT = 1 * 64;
	var game_tone2 = 880;
	var game_YDISPSIZE = 128;
	var game_SCALE = 64;
	var game_bx = Math.floor(160 * 64 / 2);
	var game_TOP = 14 * 64;
	var game_dx = Math.floor(160 * 64 / 98);
	var game_dy = Math.floor( -160 * 64 / 65);
	var game_padx = Math.floor(128 * 64 / 2);
	var game_BRICK_HEIGHT = 9;
	const game = new BreakoutGame('game', null, game_BRICK_ROWS, game_score, game_bricks, game_lives, game_br, game_pady, game_prevPY, game_tone_duration, game_by, game_prevPX, game_level, game_BOTTOM, game_RIGHT, game_bgcolor, game_prevBX, game_padlen, game_prevBY, game_XMAX, game_XDISPSIZE, game_tone1, game_YMAX, game_period, game_LEFT, game_fgcolor, game_tone2, game_YDISPSIZE, game_SCALE, game_bx, game_TOP, game_dx, game_dy, game_padx, game_BRICK_HEIGHT, false);
	var sound_synth = new Tone.Synth().toMaster();
	const sound = new SoundControllerBrowser('sound', null, sound_synth, false);
	var disp_fg_r = 0;
	var disp_fg_b = 0;
	var disp_fg_g = 0;
	var disp_bg_b = 0;
	var disp_XFRAMESIZE = null;
	var disp_bg_g = 0;
	var disp_SCALE = 5;
	var disp_Display = null;
	var disp_BufferCanvas = null;
	var disp_bg_r = 0;
	var disp_YFRAMESIZE = null;
	var disp_Buffer = null;
	const disp = new DisplayBrowser('disp', null, disp_fg_r, disp_fg_b, disp_fg_g, disp_bg_b, disp_XFRAMESIZE, disp_bg_g, disp_SCALE, disp_Display, disp_BufferCanvas, disp_bg_r, disp_YFRAMESIZE, disp_Buffer, false);
	var ctrl_dy = 0;
	var ctrl_XMAX = 100;
	var ctrl_dx = 0;
	var ctrl_XMIN =  -100;
	var ctrl_timerID = 4;
	var ctrl_YMAX = 100;
	var ctrl_posX = 0;
	var ctrl_YMIN =  -100;
	var ctrl_posY = 0;
	const ctrl = new VelocityController('ctrl', null, ctrl_dy, ctrl_XMAX, ctrl_dx, ctrl_XMIN, ctrl_timerID, ctrl_YMAX, ctrl_posX, ctrl_YMIN, ctrl_posY, false);
	var timer_Timeouts = {};
	const timer = new TimerBrowser('timer', null, timer_Timeouts, false);
	
	/*Connecting internal ports...*/
	game.bus.on('game?lostBall', () => game.receivelostBallOngame());
	game.bus.on('game?nextLevel', () => game.receivenextLevelOngame());
	/*Connecting ports...*/
	game.bus.on('sound?tone', (freq, time) => sound.receivetoneOnsound(freq, time));
	timer.bus.on('timer?timer_timeout', (id) => ctrl.receivetimer_timeoutOnclock(id));
	ctrl.bus.on('clock?timer_start', (id, time) => timer.receivetimer_startOntimer(id, time));
	ctrl.bus.on('clock?timer_cancel', (id) => timer.receivetimer_cancelOntimer(id));
	timer.bus.on('timer?timer_timeout', (id) => game.receivetimer_timeoutOnclock(id));
	game.bus.on('clock?timer_start', (id, time) => timer.receivetimer_startOntimer(id, time));
	game.bus.on('clock?timer_cancel', (id) => timer.receivetimer_cancelOntimer(id));
	ctrl.bus.on('controls?position', (x, y) => game.receivepositionOncontroller(x, y));
	disp.bus.on('vctrl?velocity', (dx, dy) => ctrl.receivevelocityOnctrl_in(dx, dy));
	disp.bus.on('vctrl?fire', (id) => ctrl.receivefireOnctrl_in(id));
	disp.bus.on('vctrl?position', (x, y) => ctrl.receivepositionOnctrl_in(x, y));
	disp.bus.on('display?displayReady', () => game.receivedisplayReadyOndisplay());
	disp.bus.on('display?displayError', () => game.receivedisplayErrorOndisplay());
	game.bus.on('display?create', (xsize, ysize) => disp.receivecreateOndisplay(xsize, ysize));
	game.bus.on('display?update', () => disp.receiveupdateOndisplay());
	game.bus.on('display?clear', () => disp.receiveclearOndisplay());
	game.bus.on('display?setColor', (r, g, b) => disp.receivesetColorOndisplay(r, g, b));
	game.bus.on('display?setBGColor', (r, g, b) => disp.receivesetBGColorOndisplay(r, g, b));
	game.bus.on('display?drawRect', (x, y, width, height) => disp.receivedrawRectOndisplay(x, y, width, height));
	game.bus.on('display?fillRect', (x, y, width, height) => disp.receivefillRectOndisplay(x, y, width, height));
	game.bus.on('display?drawInteger', (x, y, v, digits, scale) => disp.receivedrawIntegerOndisplay(x, y, v, digits, scale));
	game.bus.on('display?drawThingML', (x, y) => disp.receivedrawThingMLOndisplay(x, y));
	
	sound._init();
	timer._init();
	disp._init();
	ctrl._init();
	game._init();
	
	/*$PLUGINS_END$*/
}

window.addEventListener('DOMContentLoaded', function(){
	RunThingMLConfiguration();
});

