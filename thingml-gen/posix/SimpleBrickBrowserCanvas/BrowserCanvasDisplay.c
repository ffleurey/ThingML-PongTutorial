/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing BrowserCanvasDisplay
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "BrowserCanvasDisplay.h"

/*****************************************************************************
 * Implementation for type : BrowserCanvasDisplay
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void Display_SC_OnExit(int state, struct BrowserCanvasDisplay_Instance *_instance);
//Prototypes: Message Sending
void BrowserCanvasDisplay_send_vctrl_fire(struct BrowserCanvasDisplay_Instance *_instance, uint8_t id);
void BrowserCanvasDisplay_send_vctrl_velocity(struct BrowserCanvasDisplay_Instance *_instance, int16_t dx, int16_t dy);
void BrowserCanvasDisplay_send_display_displayReady(struct BrowserCanvasDisplay_Instance *_instance);
void BrowserCanvasDisplay_send_display_displayError(struct BrowserCanvasDisplay_Instance *_instance);
//Prototypes: Function
void f_BrowserCanvasDisplay_initDisplay(struct BrowserCanvasDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize);
void f_BrowserCanvasDisplay_destroyDisplay(struct BrowserCanvasDisplay_Instance *_instance);
void f_BrowserCanvasDisplay_updateDisplay(struct BrowserCanvasDisplay_Instance *_instance);
void f_BrowserCanvasDisplay_clearScreen(struct BrowserCanvasDisplay_Instance *_instance);
void f_BrowserCanvasDisplay_setColor(struct BrowserCanvasDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void f_BrowserCanvasDisplay_drawRect(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void f_BrowserCanvasDisplay_fillRect(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void f_BrowserCanvasDisplay_drawDigit(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t d, uint8_t size);
void f_BrowserCanvasDisplay_drawInteger(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void f_BrowserCanvasDisplay_clearInteger(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t digits, uint8_t scale);
// Declaration of functions:
// Definition of function initDisplay
void f_BrowserCanvasDisplay_initDisplay(struct BrowserCanvasDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize) {
_instance->BrowserCanvasDisplay_XFRAMESIZE_var = xsize;
_instance->BrowserCanvasDisplay_YFRAMESIZE_var = ysize;

      document.body.style.backgroundColor = "gray";
      
      /* Create buffer canvas */
      var buffer = document.createElement("canvas");
      buffer.setAttribute("width", _instance->BrowserCanvasDisplay_XFRAMESIZE_var);
      buffer.setAttribute("height", _instance->BrowserCanvasDisplay_YFRAMESIZE_var);
      buffer.style.imageRendering = "pixelated";
      _instance->BrowserCanvasDisplay_BufferCanvas_var = buffer;
      
      var bufferCtx = buffer.getContext("2d");
      bufferCtx.imageSmoothingEnabled = false;
      bufferCtx.mozImageSmoothingEnabled = false;
      bufferCtx.webkitImageSmoothingEnabled = false;
      bufferCtx.msImageSmoothingEnabled = false;
      _instance->BrowserCanvasDisplay_Buffer_var = bufferCtx;
      
      /* Create the display canvas */
      var display = document.createElement("canvas");
      display.setAttribute("width", _instance->BrowserCanvasDisplay_XFRAMESIZE_var * _instance->BrowserCanvasDisplay_SCALE_var);
      display.setAttribute("height", _instance->BrowserCanvasDisplay_YFRAMESIZE_var * _instance->BrowserCanvasDisplay_SCALE_var);
      
      var displayCtx = display.getContext("2d");
      displayCtx.imageSmoothingEnabled = false;
      displayCtx.mozImageSmoothingEnabled = false;
      displayCtx.webkitImageSmoothingEnabled = false;
      displayCtx.msImageSmoothingEnabled = false;
      
      _instance->BrowserCanvasDisplay_Display_var = displayCtx;
      
      // Put it in the middle of the window
      display.style.position = "absolute";
      display.style.left = "50%";
      display.style.top = "50%";
      display.style.marginLeft =  -_instance->BrowserCanvasDisplay_XFRAMESIZE_var / 2 * _instance->BrowserCanvasDisplay_SCALE_var+"px";
      display.style.marginTop =  -_instance->BrowserCanvasDisplay_YFRAMESIZE_var / 2 * _instance->BrowserCanvasDisplay_SCALE_var+"px";
      document.body.appendChild(display);
      
      bufferCtx.lineWidth = 2;
      bufferCtx.fillStyle = "rgb(255,0,0)";
      bufferCtx.fillRect(0,0,100,100);
    
f_BrowserCanvasDisplay_clearScreen(_instance);

      document.addEventListener("keydown", (e) => {
        if (e.key == "ArrowLeft") {
          
BrowserCanvasDisplay_send_vctrl_velocity(_instance,  -8, 0);

        } else if (e.key == "ArrowRight") {
          
BrowserCanvasDisplay_send_vctrl_velocity(_instance, 8, 0);

        }
      });
      document.addEventListener("keyup", (e) => {
        if (e.key == "ArrowLeft" || e.key == "ArrowRight") {
          
BrowserCanvasDisplay_send_vctrl_velocity(_instance, 0, 0);

        }
      });
    
}
// Definition of function destroyDisplay
void f_BrowserCanvasDisplay_destroyDisplay(struct BrowserCanvasDisplay_Instance *_instance) {
}
// Definition of function updateDisplay
void f_BrowserCanvasDisplay_updateDisplay(struct BrowserCanvasDisplay_Instance *_instance) {
_instance->BrowserCanvasDisplay_Display_var.drawImage(_instance->BrowserCanvasDisplay_BufferCanvas_var, 0, 0, _instance->BrowserCanvasDisplay_XFRAMESIZE_var * _instance->BrowserCanvasDisplay_SCALE_var, _instance->BrowserCanvasDisplay_YFRAMESIZE_var * _instance->BrowserCanvasDisplay_SCALE_var);
}
// Definition of function clearScreen
void f_BrowserCanvasDisplay_clearScreen(struct BrowserCanvasDisplay_Instance *_instance) {
f_BrowserCanvasDisplay_setColor(_instance, 0, 0, 0);
f_BrowserCanvasDisplay_fillRect(_instance, 0, 0, _instance->BrowserCanvasDisplay_XFRAMESIZE_var, _instance->BrowserCanvasDisplay_YFRAMESIZE_var);
f_BrowserCanvasDisplay_updateDisplay(_instance);
}
// Definition of function setColor
void f_BrowserCanvasDisplay_setColor(struct BrowserCanvasDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b) {

      _instance->BrowserCanvasDisplay_Buffer_var.strokeStyle = "rgb("+r+", "+g+", "+b+")";
      _instance->BrowserCanvasDisplay_Buffer_var.fillStyle = "rgb("+r+", "+g+", "+b+")";
    
}
// Definition of function drawRect
void f_BrowserCanvasDisplay_drawRect(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {

      var xr = Math.round(x);
      var yr = Math.round(y);
      var wr = Math.round(width);
      var hr = Math.round(height);
      _instance->BrowserCanvasDisplay_Buffer_var.strokeRect(xr, yr, wr, hr);
    
}
// Definition of function fillRect
void f_BrowserCanvasDisplay_fillRect(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {

      var xr = Math.round(x);
      var yr = Math.round(y);
      var wr = Math.round(width);
      var hr = Math.round(height);
      _instance->BrowserCanvasDisplay_Buffer_var.fillRect(xr, yr, wr, hr);
    
}
// Definition of function drawDigit
void f_BrowserCanvasDisplay_drawDigit(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t d, uint8_t size) {
if(d == 0) {
f_BrowserCanvasDisplay_fillRect(_instance, x, y, size, 5 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y, 3 * size, size);
f_BrowserCanvasDisplay_fillRect(_instance, x + 2 * size, y, size, 5 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);

} else {
if(d == 1) {
f_BrowserCanvasDisplay_fillRect(_instance, x + size, y, size, 5 * size);

} else {
if(d == 2) {
f_BrowserCanvasDisplay_fillRect(_instance, x, y, size * 3, size);
f_BrowserCanvasDisplay_fillRect(_instance, x + 2 * size, y, size, 3 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 2 * size, 3 * size, size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 2 * size, size, 3 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);

} else {
if(d == 3) {
f_BrowserCanvasDisplay_fillRect(_instance, x, y, size * 3, size);
f_BrowserCanvasDisplay_fillRect(_instance, x + 2 * size, y, size, 5 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);
f_BrowserCanvasDisplay_fillRect(_instance, x + size, y + 2 * size, 2 * size, size);

} else {
if(d == 4) {
f_BrowserCanvasDisplay_fillRect(_instance, x, y, size, 3 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 2 * size, 3 * size, size);
f_BrowserCanvasDisplay_fillRect(_instance, x + 2 * size, y, size, 5 * size);

} else {
if(d == 5) {
f_BrowserCanvasDisplay_fillRect(_instance, x, y, size * 3, size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y, size, 3 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 2 * size, 3 * size, size);
f_BrowserCanvasDisplay_fillRect(_instance, x + 2 * size, y + 2 * size, size, 3 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);

} else {
if(d == 6) {
f_BrowserCanvasDisplay_fillRect(_instance, x, y, size * 3, size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y, size, 5 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 2 * size, 3 * size, size);
f_BrowserCanvasDisplay_fillRect(_instance, x + 2 * size, y + 2 * size, size, 3 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);

} else {
if(d == 7) {
f_BrowserCanvasDisplay_fillRect(_instance, x, y, 3 * size, size);
f_BrowserCanvasDisplay_fillRect(_instance, x + 2 * size, y, size, 5 * size);

} else {
if(d == 8) {
f_BrowserCanvasDisplay_fillRect(_instance, x, y, size, 5 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y, 3 * size, size);
f_BrowserCanvasDisplay_fillRect(_instance, x + 2 * size, y, size, 5 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 2 * size, 3 * size, size);

} else {
if(d == 9) {
f_BrowserCanvasDisplay_fillRect(_instance, x, y, size, 3 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y, 3 * size, size);
f_BrowserCanvasDisplay_fillRect(_instance, x + 2 * size, y, size, 5 * size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);
f_BrowserCanvasDisplay_fillRect(_instance, x, y + 2 * size, 3 * size, size);

}

}

}

}

}

}

}

}

}

}
}
// Definition of function drawInteger
void f_BrowserCanvasDisplay_drawInteger(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale) {
f_BrowserCanvasDisplay_clearInteger(_instance, x, y, digits, scale);
;int16_t val = v;
;uint8_t d = digits;
while(d > 0) {
f_BrowserCanvasDisplay_drawDigit(_instance, x + (d - 1) * 4 * scale, y, val % 10, scale);
val = val / 10;
d = d - 1;

}
}
// Definition of function clearInteger
void f_BrowserCanvasDisplay_clearInteger(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t digits, uint8_t scale) {
f_BrowserCanvasDisplay_setColor(_instance, _instance->Display_bg_r_var, _instance->Display_bg_g_var, _instance->Display_bg_b_var);
f_BrowserCanvasDisplay_fillRect(_instance, x, y, (digits * 4 - 1) * scale, 5 * scale);
f_BrowserCanvasDisplay_setColor(_instance, _instance->Display_fg_r_var, _instance->Display_fg_g_var, _instance->Display_fg_b_var);
}

// Sessions functionss:


// On Entry Actions:
void Display_SC_OnEntry(int state, struct BrowserCanvasDisplay_Instance *_instance) {
switch(state) {
case DISPLAY_SC_STATE:{
_instance->Display_SC_State = DISPLAY_SC_WAIT_STATE;
Display_SC_OnEntry(_instance->Display_SC_State, _instance);
break;
}
case DISPLAY_SC_WAIT_STATE:{
break;
}
case DISPLAY_SC_RUNNING_STATE:{
BrowserCanvasDisplay_send_display_displayReady(_instance);
break;
}
case DISPLAY_SC_DESTROYED_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Display_SC_OnExit(int state, struct BrowserCanvasDisplay_Instance *_instance) {
switch(state) {
case DISPLAY_SC_STATE:{
Display_SC_OnExit(_instance->Display_SC_State, _instance);
break;}
case DISPLAY_SC_WAIT_STATE:{
break;}
case DISPLAY_SC_RUNNING_STATE:{
break;}
case DISPLAY_SC_DESTROYED_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void BrowserCanvasDisplay_handle_display_drawInteger(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_BrowserCanvasDisplay_drawInteger(_instance, x, y, v, digits, scale);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BrowserCanvasDisplay_handle_display_setBGColor(struct BrowserCanvasDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
_instance->Display_bg_r_var = r;
_instance->Display_bg_g_var = g;
_instance->Display_bg_b_var = b;
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BrowserCanvasDisplay_handle_display_drawRect(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_BrowserCanvasDisplay_drawRect(_instance, x, y, width, height);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BrowserCanvasDisplay_handle_display_setColor(struct BrowserCanvasDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
_instance->Display_fg_r_var = r;
_instance->Display_fg_g_var = g;
_instance->Display_fg_b_var = b;
f_BrowserCanvasDisplay_setColor(_instance, r, g, b);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BrowserCanvasDisplay_handle_display_clear(struct BrowserCanvasDisplay_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_BrowserCanvasDisplay_clearScreen(_instance);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BrowserCanvasDisplay_handle_display_create(struct BrowserCanvasDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_WAIT_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
Display_SC_OnExit(DISPLAY_SC_WAIT_STATE, _instance);
_instance->Display_SC_State = DISPLAY_SC_RUNNING_STATE;
f_BrowserCanvasDisplay_initDisplay(_instance, xsize, ysize);
Display_SC_OnEntry(DISPLAY_SC_RUNNING_STATE, _instance);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BrowserCanvasDisplay_handle_display_destroy(struct BrowserCanvasDisplay_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
Display_SC_OnExit(DISPLAY_SC_RUNNING_STATE, _instance);
_instance->Display_SC_State = DISPLAY_SC_DESTROYED_STATE;
f_BrowserCanvasDisplay_destroyDisplay(_instance);
Display_SC_OnEntry(DISPLAY_SC_DESTROYED_STATE, _instance);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BrowserCanvasDisplay_handle_display_fillRect(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_BrowserCanvasDisplay_fillRect(_instance, x, y, width, height);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BrowserCanvasDisplay_handle_display_update(struct BrowserCanvasDisplay_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_BrowserCanvasDisplay_updateDisplay(_instance);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
void (*external_BrowserCanvasDisplay_send_vctrl_fire_listener)(struct BrowserCanvasDisplay_Instance *, uint8_t)= 0x0;
void (*BrowserCanvasDisplay_send_vctrl_fire_listener)(struct BrowserCanvasDisplay_Instance *, uint8_t)= 0x0;
void register_external_BrowserCanvasDisplay_send_vctrl_fire_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *, uint8_t)){
external_BrowserCanvasDisplay_send_vctrl_fire_listener = _listener;
}
void register_BrowserCanvasDisplay_send_vctrl_fire_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *, uint8_t)){
BrowserCanvasDisplay_send_vctrl_fire_listener = _listener;
}
void BrowserCanvasDisplay_send_vctrl_fire(struct BrowserCanvasDisplay_Instance *_instance, uint8_t id){
if (BrowserCanvasDisplay_send_vctrl_fire_listener != 0x0) BrowserCanvasDisplay_send_vctrl_fire_listener(_instance, id);
if (external_BrowserCanvasDisplay_send_vctrl_fire_listener != 0x0) external_BrowserCanvasDisplay_send_vctrl_fire_listener(_instance, id);
;
}
void (*external_BrowserCanvasDisplay_send_vctrl_velocity_listener)(struct BrowserCanvasDisplay_Instance *, int16_t, int16_t)= 0x0;
void (*BrowserCanvasDisplay_send_vctrl_velocity_listener)(struct BrowserCanvasDisplay_Instance *, int16_t, int16_t)= 0x0;
void register_external_BrowserCanvasDisplay_send_vctrl_velocity_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *, int16_t, int16_t)){
external_BrowserCanvasDisplay_send_vctrl_velocity_listener = _listener;
}
void register_BrowserCanvasDisplay_send_vctrl_velocity_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *, int16_t, int16_t)){
BrowserCanvasDisplay_send_vctrl_velocity_listener = _listener;
}
void BrowserCanvasDisplay_send_vctrl_velocity(struct BrowserCanvasDisplay_Instance *_instance, int16_t dx, int16_t dy){
if (BrowserCanvasDisplay_send_vctrl_velocity_listener != 0x0) BrowserCanvasDisplay_send_vctrl_velocity_listener(_instance, dx, dy);
if (external_BrowserCanvasDisplay_send_vctrl_velocity_listener != 0x0) external_BrowserCanvasDisplay_send_vctrl_velocity_listener(_instance, dx, dy);
;
}
void (*external_BrowserCanvasDisplay_send_display_displayReady_listener)(struct BrowserCanvasDisplay_Instance *)= 0x0;
void (*BrowserCanvasDisplay_send_display_displayReady_listener)(struct BrowserCanvasDisplay_Instance *)= 0x0;
void register_external_BrowserCanvasDisplay_send_display_displayReady_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *)){
external_BrowserCanvasDisplay_send_display_displayReady_listener = _listener;
}
void register_BrowserCanvasDisplay_send_display_displayReady_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *)){
BrowserCanvasDisplay_send_display_displayReady_listener = _listener;
}
void BrowserCanvasDisplay_send_display_displayReady(struct BrowserCanvasDisplay_Instance *_instance){
if (BrowserCanvasDisplay_send_display_displayReady_listener != 0x0) BrowserCanvasDisplay_send_display_displayReady_listener(_instance);
if (external_BrowserCanvasDisplay_send_display_displayReady_listener != 0x0) external_BrowserCanvasDisplay_send_display_displayReady_listener(_instance);
;
}
void (*external_BrowserCanvasDisplay_send_display_displayError_listener)(struct BrowserCanvasDisplay_Instance *)= 0x0;
void (*BrowserCanvasDisplay_send_display_displayError_listener)(struct BrowserCanvasDisplay_Instance *)= 0x0;
void register_external_BrowserCanvasDisplay_send_display_displayError_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *)){
external_BrowserCanvasDisplay_send_display_displayError_listener = _listener;
}
void register_BrowserCanvasDisplay_send_display_displayError_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *)){
BrowserCanvasDisplay_send_display_displayError_listener = _listener;
}
void BrowserCanvasDisplay_send_display_displayError(struct BrowserCanvasDisplay_Instance *_instance){
if (BrowserCanvasDisplay_send_display_displayError_listener != 0x0) BrowserCanvasDisplay_send_display_displayError_listener(_instance);
if (external_BrowserCanvasDisplay_send_display_displayError_listener != 0x0) external_BrowserCanvasDisplay_send_display_displayError_listener(_instance);
;
}



