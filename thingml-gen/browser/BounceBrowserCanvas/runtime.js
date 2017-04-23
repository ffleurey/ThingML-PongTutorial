'use strict';

var RunThingMLConfiguration = function() {
/*$REQUIRE_PLUGINS$*/
var bb_MAX = 10000;
var bb_bx = 10000 / 2;
var bb_dx = 200;
var bb_YSIZE = 128;
var bb_by = 10000 / 2;
var bb_XSIZE = 160;
var bb_dy = 130;
/*$CONFIGURATION bb$*/
const bb = new BouncingBall('bb', null, bb_MAX, bb_bx, bb_dx, bb_YSIZE, bb_by, bb_XSIZE, bb_dy, false);
var disp_SCALE = 5;
var disp_Buffer = null;
var disp_XFRAMESIZE = null;
var disp_YFRAMESIZE = null;
var disp_BufferCanvas = null;
var disp_Display = null;
/*$CONFIGURATION disp$*/
const disp = new BrowserCanvasDisplay('disp', null, disp_SCALE, disp_Buffer, disp_XFRAMESIZE, disp_YFRAMESIZE, disp_BufferCanvas, disp_Display, false);
var timer_Timeouts = {};
/*$CONFIGURATION timer$*/
const timer = new TimerBrowser('timer', null, timer_Timeouts, false);
/*$PLUGINS$*/
//Connecting internal ports...
//Connecting ports...
timer.bus.on('timer?timer_timeout', (id) => bb.receivetimer_timeoutOnclock(id));
bb.bus.on('clock?timer_start', (id, time) => timer.receivetimer_startOntimer(id, time));
bb.bus.on('clock?timer_cancel', (id) => timer.receivetimer_cancelOntimer(id));
disp.bus.on('display?displayReady', () => bb.receivedisplayReadyOndisplay());
disp.bus.on('display?displayError', () => bb.receivedisplayErrorOndisplay());
bb.bus.on('display?create', (xsize, ysize) => disp.receivecreateOndisplay(xsize, ysize));
bb.bus.on('display?update', () => disp.receiveupdateOndisplay());
bb.bus.on('display?clear', () => disp.receiveclearOndisplay());
bb.bus.on('display?setColor', (r, g, b) => disp.receivesetColorOndisplay(r, g, b));
bb.bus.on('display?drawRect', (x, y, width, height) => disp.receivedrawRectOndisplay(x, y, width, height));
bb.bus.on('display?fillRect', (x, y, width, height) => disp.receivefillRectOndisplay(x, y, width, height));
/*$PLUGINS_CONNECTORS$*/
timer._init();
disp._init();
bb._init();
/*$PLUGINS_END$*/
};

window.addEventListener('DOMContentLoaded', function(){
	RunThingMLConfiguration();
});
