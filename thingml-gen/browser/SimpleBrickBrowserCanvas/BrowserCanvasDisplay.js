'use strict';

StateJS.internalTransitionsTriggerCompletion = true;

/**
 * Definition for type : BrowserCanvasDisplay
 **/
function BrowserCanvasDisplay(name, root, BrowserCanvasDisplay_XFRAMESIZE_var, BrowserCanvasDisplay_YFRAMESIZE_var, BrowserCanvasDisplay_BufferCanvas_var, BrowserCanvasDisplay_SCALE_var, BrowserCanvasDisplay_Buffer_var, BrowserCanvasDisplay_Display_var, debug) {

this.name = name;
this.root = (root === null)? this : root;
this.debug = debug;
this.ready = false;
this.bus = new EventEmitter();
//Attributes
this.BrowserCanvasDisplay_XFRAMESIZE_var = BrowserCanvasDisplay_XFRAMESIZE_var;
this.debug_BrowserCanvasDisplay_XFRAMESIZE_var = BrowserCanvasDisplay_XFRAMESIZE_var;
this.BrowserCanvasDisplay_YFRAMESIZE_var = BrowserCanvasDisplay_YFRAMESIZE_var;
this.debug_BrowserCanvasDisplay_YFRAMESIZE_var = BrowserCanvasDisplay_YFRAMESIZE_var;
this.BrowserCanvasDisplay_BufferCanvas_var = BrowserCanvasDisplay_BufferCanvas_var;
this.debug_BrowserCanvasDisplay_BufferCanvas_var = BrowserCanvasDisplay_BufferCanvas_var;
this.BrowserCanvasDisplay_SCALE_var = BrowserCanvasDisplay_SCALE_var;
this.debug_BrowserCanvasDisplay_SCALE_var = BrowserCanvasDisplay_SCALE_var;
this.BrowserCanvasDisplay_Buffer_var = BrowserCanvasDisplay_Buffer_var;
this.debug_BrowserCanvasDisplay_Buffer_var = BrowserCanvasDisplay_Buffer_var;
this.BrowserCanvasDisplay_Display_var = BrowserCanvasDisplay_Display_var;
this.debug_BrowserCanvasDisplay_Display_var = BrowserCanvasDisplay_Display_var;
this.build(name);
}
//State machine (states and regions)
BrowserCanvasDisplay.prototype.build = function(session) {//optional session name and root instance to fork a new session
this.statemachine = new StateJS.StateMachine('SC');
this._initial_Display_SC = new StateJS.PseudoState('_initial', this.statemachine, StateJS.PseudoStateKind.Initial);
let Display_SC_Wait = new StateJS.State('Wait', this.statemachine);
let Display_SC_Running = new StateJS.State('Running', this.statemachine).entry(() => {
this.bus.emit('display?displayReady');
});
let Display_SC_Destroyed = new StateJS.State('Destroyed', this.statemachine);
this._initial_Display_SC.to(Display_SC_Wait);
Display_SC_Running.to(null).when((fillRect) => {return fillRect._port === 'display' && fillRect._msg === 'fillRect';}).effect((fillRect) => {
this.fillRect(fillRect.x, fillRect.y, fillRect.width, fillRect.height);
});
Display_SC_Running.to(null).when((clear) => {return clear._port === 'display' && clear._msg === 'clear';}).effect((clear) => {
this.clearScreen();
});
Display_SC_Running.to(null).when((drawRect) => {return drawRect._port === 'display' && drawRect._msg === 'drawRect';}).effect((drawRect) => {
this.drawRect(drawRect.x, drawRect.y, drawRect.width, drawRect.height);
});
Display_SC_Wait.to(Display_SC_Running).when((create) => {return create._port === 'display' && create._msg === 'create';}).effect((create) => {
this.initDisplay(create.xsize, create.ysize);
});
Display_SC_Running.to(null).when((update) => {return update._port === 'display' && update._msg === 'update';}).effect((update) => {
this.updateDisplay();
});
Display_SC_Running.to(Display_SC_Destroyed).when((destroy) => {return destroy._port === 'display' && destroy._msg === 'destroy';}).effect((destroy) => {
this.destroyDisplay();
});
Display_SC_Running.to(null).when((setColor) => {return setColor._port === 'display' && setColor._msg === 'setColor';}).effect((setColor) => {
this.Display_fg_r_var = setColor.r;
this.bus.emit('fg_r=', this.Display_fg_r_var);
this.Display_fg_g_var = setColor.g;
this.bus.emit('fg_g=', this.Display_fg_g_var);
this.Display_fg_b_var = setColor.b;
this.bus.emit('fg_b=', this.Display_fg_b_var);
this.setColor(setColor.r, setColor.g, setColor.b);
});
Display_SC_Running.to(null).when((setBGColor) => {return setBGColor._port === 'display' && setBGColor._msg === 'setBGColor';}).effect((setBGColor) => {
this.Display_bg_r_var = setBGColor.r;
this.bus.emit('bg_r=', this.Display_bg_r_var);
this.Display_bg_g_var = setBGColor.g;
this.bus.emit('bg_g=', this.Display_bg_g_var);
this.Display_bg_b_var = setBGColor.b;
this.bus.emit('bg_b=', this.Display_bg_b_var);
});
Display_SC_Running.to(null).when((drawInteger) => {return drawInteger._port === 'display' && drawInteger._msg === 'drawInteger';}).effect((drawInteger) => {
this.drawInteger(drawInteger.x, drawInteger.y, drawInteger.v, drawInteger.digits, drawInteger.scale);
});
}
//ThingML-defined functions
BrowserCanvasDisplay.prototype.initDisplay = function(BrowserCanvasDisplay_initDisplay_xsize_var, BrowserCanvasDisplay_initDisplay_ysize_var) {
this.BrowserCanvasDisplay_XFRAMESIZE_var = BrowserCanvasDisplay_initDisplay_xsize_var;
this.bus.emit('XFRAMESIZE=', this.BrowserCanvasDisplay_XFRAMESIZE_var);
this.BrowserCanvasDisplay_YFRAMESIZE_var = BrowserCanvasDisplay_initDisplay_ysize_var;
this.bus.emit('YFRAMESIZE=', this.BrowserCanvasDisplay_YFRAMESIZE_var);

      document.body.style.backgroundColor = "gray";
      
      /* Create buffer canvas */
      var buffer = document.createElement("canvas");
      buffer.setAttribute("width", this.BrowserCanvasDisplay_XFRAMESIZE_var);
      buffer.setAttribute("height", this.BrowserCanvasDisplay_YFRAMESIZE_var);
      buffer.style.imageRendering = "pixelated";
      this.BrowserCanvasDisplay_BufferCanvas_var = buffer;
      
      var bufferCtx = buffer.getContext("2d");
      bufferCtx.imageSmoothingEnabled = false;
      bufferCtx.mozImageSmoothingEnabled = false;
      bufferCtx.webkitImageSmoothingEnabled = false;
      bufferCtx.msImageSmoothingEnabled = false;
      this.BrowserCanvasDisplay_Buffer_var = bufferCtx;
      
      /* Create the display canvas */
      var display = document.createElement("canvas");
      display.setAttribute("width", this.BrowserCanvasDisplay_XFRAMESIZE_var * this.BrowserCanvasDisplay_SCALE_var);
      display.setAttribute("height", this.BrowserCanvasDisplay_YFRAMESIZE_var * this.BrowserCanvasDisplay_SCALE_var);
      
      var displayCtx = display.getContext("2d");
      displayCtx.imageSmoothingEnabled = false;
      displayCtx.mozImageSmoothingEnabled = false;
      displayCtx.webkitImageSmoothingEnabled = false;
      displayCtx.msImageSmoothingEnabled = false;
      
      this.BrowserCanvasDisplay_Display_var = displayCtx;
      
      // Put it in the middle of the window
      display.style.position = "absolute";
      display.style.left = "50%";
      display.style.top = "50%";
      display.style.marginLeft =  -this.BrowserCanvasDisplay_XFRAMESIZE_var / 2 * this.BrowserCanvasDisplay_SCALE_var+"px";
      display.style.marginTop =  -this.BrowserCanvasDisplay_YFRAMESIZE_var / 2 * this.BrowserCanvasDisplay_SCALE_var+"px";
      display.style.cursor = "none";
      document.body.appendChild(display);
      
      // Add mouse over events
      display.addEventListener("mousemove", (e) => {
        var mouseX = e.offsetX/(this.BrowserCanvasDisplay_XFRAMESIZE_var * this.BrowserCanvasDisplay_SCALE_var); // [0,1]
        
        // TODO: Some hardcoded numbers
        var dispX = mouseX*10240; //XMAX
        var posX = (dispX-5120)*200/8406;
        posX = Math.max(-100, Math.min(100, posX));
        
        
this.bus.emit('vctrl?position', posX, 0);

      });
    
this.clearScreen();

      document.addEventListener("keydown", (e) => {
        if (e.key == "ArrowLeft") {
          
this.bus.emit('vctrl?velocity',  -8, 0);

        } else if (e.key == "ArrowRight") {
          
this.bus.emit('vctrl?velocity', 8, 0);

        }
      });
      document.addEventListener("keyup", (e) => {
        if (e.key == "ArrowLeft" || e.key == "ArrowRight") {
          
this.bus.emit('vctrl?velocity', 0, 0);

        }
      });
    

      window.setPadPosition = (x) => { //[-100, 100]
        
this.bus.emit('vctrl?position', x, 0);

      };
    
};

BrowserCanvasDisplay.prototype.destroyDisplay = function() {
};

BrowserCanvasDisplay.prototype.updateDisplay = function() {
this.BrowserCanvasDisplay_Display_var.drawImage(this.BrowserCanvasDisplay_BufferCanvas_var, 0, 0, this.BrowserCanvasDisplay_XFRAMESIZE_var * this.BrowserCanvasDisplay_SCALE_var, this.BrowserCanvasDisplay_YFRAMESIZE_var * this.BrowserCanvasDisplay_SCALE_var);
};

BrowserCanvasDisplay.prototype.clearScreen = function() {
this.setColor(0, 0, 0);
this.fillRect(0, 0, this.BrowserCanvasDisplay_XFRAMESIZE_var, this.BrowserCanvasDisplay_YFRAMESIZE_var);
this.updateDisplay();
};

BrowserCanvasDisplay.prototype.setColor = function(BrowserCanvasDisplay_setColor_r_var, BrowserCanvasDisplay_setColor_g_var, BrowserCanvasDisplay_setColor_b_var) {

      this.BrowserCanvasDisplay_Buffer_var.strokeStyle = "rgb("+BrowserCanvasDisplay_setColor_r_var+", "+BrowserCanvasDisplay_setColor_g_var+", "+BrowserCanvasDisplay_setColor_b_var+")";
      this.BrowserCanvasDisplay_Buffer_var.fillStyle = "rgb("+BrowserCanvasDisplay_setColor_r_var+", "+BrowserCanvasDisplay_setColor_g_var+", "+BrowserCanvasDisplay_setColor_b_var+")";
    
};

BrowserCanvasDisplay.prototype.drawRect = function(BrowserCanvasDisplay_drawRect_x_var, BrowserCanvasDisplay_drawRect_y_var, BrowserCanvasDisplay_drawRect_width_var, BrowserCanvasDisplay_drawRect_height_var) {

      var xr = Math.round(BrowserCanvasDisplay_drawRect_x_var);
      var yr = Math.round(BrowserCanvasDisplay_drawRect_y_var);
      var wr = Math.round(BrowserCanvasDisplay_drawRect_width_var);
      var hr = Math.round(BrowserCanvasDisplay_drawRect_height_var);
      this.BrowserCanvasDisplay_Buffer_var.fillRect(xr, yr, wr, 1);
      this.BrowserCanvasDisplay_Buffer_var.fillRect(xr, yr+hr-1, wr, 1);
      this.BrowserCanvasDisplay_Buffer_var.fillRect(xr, yr, 1, hr);
      this.BrowserCanvasDisplay_Buffer_var.fillRect(xr+wr-1, yr, 1, hr);
    
};

BrowserCanvasDisplay.prototype.fillRect = function(BrowserCanvasDisplay_fillRect_x_var, BrowserCanvasDisplay_fillRect_y_var, BrowserCanvasDisplay_fillRect_width_var, BrowserCanvasDisplay_fillRect_height_var) {

      var xr = Math.round(BrowserCanvasDisplay_fillRect_x_var);
      var yr = Math.round(BrowserCanvasDisplay_fillRect_y_var);
      var wr = Math.round(BrowserCanvasDisplay_fillRect_width_var);
      var hr = Math.round(BrowserCanvasDisplay_fillRect_height_var);
      this.BrowserCanvasDisplay_Buffer_var.fillRect(xr, yr, wr, hr);
    
};

BrowserCanvasDisplay.prototype.drawDigit = function(Display_drawDigit_x_var, Display_drawDigit_y_var, Display_drawDigit_d_var, Display_drawDigit_size_var) {
if(Display_drawDigit_d_var < 1) {
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 5 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var + 2 * Display_drawDigit_size_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 5 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 4 * Display_drawDigit_size_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);

} else {
if(Display_drawDigit_d_var < 2) {
this.fillRect(Display_drawDigit_x_var + Display_drawDigit_size_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 5 * Display_drawDigit_size_var);

} else {
if(Display_drawDigit_d_var < 3) {
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, Display_drawDigit_size_var * 3, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var + 2 * Display_drawDigit_size_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 3 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 2 * Display_drawDigit_size_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 2 * Display_drawDigit_size_var, Display_drawDigit_size_var, 3 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 4 * Display_drawDigit_size_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);

} else {
if(Display_drawDigit_d_var < 4) {
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, Display_drawDigit_size_var * 3, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var + 2 * Display_drawDigit_size_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 5 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 4 * Display_drawDigit_size_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var + Display_drawDigit_size_var, Display_drawDigit_y_var + 2 * Display_drawDigit_size_var, 2 * Display_drawDigit_size_var, Display_drawDigit_size_var);

} else {
if(Display_drawDigit_d_var < 5) {
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 3 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 2 * Display_drawDigit_size_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var + 2 * Display_drawDigit_size_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 5 * Display_drawDigit_size_var);

} else {
if(Display_drawDigit_d_var < 6) {
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, Display_drawDigit_size_var * 3, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 3 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 2 * Display_drawDigit_size_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var + 2 * Display_drawDigit_size_var, Display_drawDigit_y_var + 2 * Display_drawDigit_size_var, Display_drawDigit_size_var, 3 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 4 * Display_drawDigit_size_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);

} else {
if(Display_drawDigit_d_var < 7) {
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, Display_drawDigit_size_var * 3, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 5 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 2 * Display_drawDigit_size_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var + 2 * Display_drawDigit_size_var, Display_drawDigit_y_var + 2 * Display_drawDigit_size_var, Display_drawDigit_size_var, 3 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 4 * Display_drawDigit_size_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);

} else {
if(Display_drawDigit_d_var < 8) {
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var + 2 * Display_drawDigit_size_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 5 * Display_drawDigit_size_var);

} else {
if(Display_drawDigit_d_var < 9) {
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 5 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var + 2 * Display_drawDigit_size_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 5 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 4 * Display_drawDigit_size_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 2 * Display_drawDigit_size_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);

} else {
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 3 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var + 2 * Display_drawDigit_size_var, Display_drawDigit_y_var, Display_drawDigit_size_var, 5 * Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 4 * Display_drawDigit_size_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);
this.fillRect(Display_drawDigit_x_var, Display_drawDigit_y_var + 2 * Display_drawDigit_size_var, 3 * Display_drawDigit_size_var, Display_drawDigit_size_var);

}

}

}

}

}

}

}

}

}
};

BrowserCanvasDisplay.prototype.drawInteger = function(Display_drawInteger_x_var, Display_drawInteger_y_var, Display_drawInteger_v_var, Display_drawInteger_digits_var, Display_drawInteger_scale_var) {
this.clearInteger(Display_drawInteger_x_var, Display_drawInteger_y_var, Display_drawInteger_digits_var, Display_drawInteger_scale_var);
let val_var = Display_drawInteger_v_var;
let d_var = Display_drawInteger_digits_var;
while(d_var > 0) {
this.drawDigit(Display_drawInteger_x_var + (d_var - 1) * 4 * Display_drawInteger_scale_var, Display_drawInteger_y_var, val_var % 10, Display_drawInteger_scale_var);
val_var = val_var / 10;
d_var = d_var - 1;

}
};

BrowserCanvasDisplay.prototype.clearInteger = function(Display_clearInteger_x_var, Display_clearInteger_y_var, Display_clearInteger_digits_var, Display_clearInteger_scale_var) {
this.setColor(this.Display_bg_r_var, this.Display_bg_g_var, this.Display_bg_b_var);
this.fillRect(Display_clearInteger_x_var, Display_clearInteger_y_var, (Display_clearInteger_digits_var * 4 - 1) * Display_clearInteger_scale_var, 5 * Display_clearInteger_scale_var);
this.setColor(this.Display_fg_r_var, this.Display_fg_g_var, this.Display_fg_b_var);
};

//Public API for lifecycle management
BrowserCanvasDisplay.prototype._stop = function() {
this.root = null;
this.ready = false;
};

BrowserCanvasDisplay.prototype._delete = function() {
this.statemachine = null;
this.SC_instance = null;
this.bus.removeAllListeners();
};

//Public API for third parties
BrowserCanvasDisplay.prototype._init = function() {
this.SC_instance = new StateJS.StateMachineInstance("SC_instance");
StateJS.initialise(this.statemachine, this.SC_instance );
this.ready = true;
};

BrowserCanvasDisplay.prototype._receive = function(msg) {//msg = {_port:myPort, _msg:myMessage, paramN=paramN, ...}
if(this.ready){
StateJS.evaluate(this.statemachine, this.SC_instance, msg);
} else { setTimeout(()=>this._receive(msg),0) }};
BrowserCanvasDisplay.prototype.receivecreateOndisplay = function(xsize, ysize) {
this._receive({_port:"display", _msg:"create", xsize:xsize, ysize:ysize});
};

BrowserCanvasDisplay.prototype.receivedestroyOndisplay = function() {
this._receive({_port:"display", _msg:"destroy"});
};

BrowserCanvasDisplay.prototype.receiveupdateOndisplay = function() {
this._receive({_port:"display", _msg:"update"});
};

BrowserCanvasDisplay.prototype.receiveclearOndisplay = function() {
this._receive({_port:"display", _msg:"clear"});
};

BrowserCanvasDisplay.prototype.receivesetColorOndisplay = function(r, g, b) {
this._receive({_port:"display", _msg:"setColor", r:r, g:g, b:b});
};

BrowserCanvasDisplay.prototype.receivesetBGColorOndisplay = function(r, g, b) {
this._receive({_port:"display", _msg:"setBGColor", r:r, g:g, b:b});
};

BrowserCanvasDisplay.prototype.receivedrawRectOndisplay = function(x, y, width, height) {
this._receive({_port:"display", _msg:"drawRect", x:x, y:y, width:width, height:height});
};

BrowserCanvasDisplay.prototype.receivefillRectOndisplay = function(x, y, width, height) {
this._receive({_port:"display", _msg:"fillRect", x:x, y:y, width:width, height:height});
};

BrowserCanvasDisplay.prototype.receivedrawIntegerOndisplay = function(x, y, v, digits, scale) {
this._receive({_port:"display", _msg:"drawInteger", x:x, y:y, v:v, digits:digits, scale:scale});
};

BrowserCanvasDisplay.prototype.toString = function() {
let result = 'instance ' + this.name + ':' + this.constructor.name + '\n';
result += '\n\tXFRAMESIZE = ' + this.BrowserCanvasDisplay_XFRAMESIZE_var;
result += '\n\tYFRAMESIZE = ' + this.BrowserCanvasDisplay_YFRAMESIZE_var;
result += '\n\tBufferCanvas = ' + this.BrowserCanvasDisplay_BufferCanvas_var;
result += '\n\tSCALE = ' + this.BrowserCanvasDisplay_SCALE_var;
result += '\n\tBuffer = ' + this.BrowserCanvasDisplay_Buffer_var;
result += '\n\tDisplay = ' + this.BrowserCanvasDisplay_Display_var;
result += '';
return result;
};
