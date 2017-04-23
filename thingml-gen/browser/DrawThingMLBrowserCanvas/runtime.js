'use strict';

var RunThingMLConfiguration = function() {
/*$REQUIRE_PLUGINS$*/
var bb_YDISPSIZE = 128;
var bb_XDISPSIZE = 160;
/*$CONFIGURATION bb$*/
const bb = new DrawThingML('bb', null, bb_YDISPSIZE, bb_XDISPSIZE, false);
var disp_SCALE = 5;
var disp_XFRAMESIZE = null;
var disp_Display = null;
var disp_YFRAMESIZE = null;
var disp_BufferCanvas = null;
var disp_Buffer = null;
/*$CONFIGURATION disp$*/
const disp = new BrowserCanvasDisplay('disp', null, disp_SCALE, disp_XFRAMESIZE, disp_Display, disp_YFRAMESIZE, disp_BufferCanvas, disp_Buffer, false);
/*$PLUGINS$*/
//Connecting internal ports...
//Connecting ports...
disp.bus.on('display?displayReady', () => bb.receivedisplayReadyOndisplay());
disp.bus.on('display?displayError', () => bb.receivedisplayErrorOndisplay());
bb.bus.on('display?create', (xsize, ysize) => disp.receivecreateOndisplay(xsize, ysize));
bb.bus.on('display?update', () => disp.receiveupdateOndisplay());
bb.bus.on('display?clear', () => disp.receiveclearOndisplay());
bb.bus.on('display?setColor', (r, g, b) => disp.receivesetColorOndisplay(r, g, b));
bb.bus.on('display?drawRect', (x, y, width, height) => disp.receivedrawRectOndisplay(x, y, width, height));
bb.bus.on('display?fillRect', (x, y, width, height) => disp.receivefillRectOndisplay(x, y, width, height));
/*$PLUGINS_CONNECTORS$*/
disp._init();
bb._init();
/*$PLUGINS_END$*/
};

window.addEventListener('DOMContentLoaded', function(){
	RunThingMLConfiguration();
});
