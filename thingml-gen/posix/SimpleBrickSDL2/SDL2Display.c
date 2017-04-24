/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing SDL2Display
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "SDL2Display.h"

/*****************************************************************************
 * Implementation for type : SDL2Display
 *****************************************************************************/


// BEGIN: Code from the c_global annotation SDL2Display

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

// END: Code from the c_global annotation SDL2Display

// Declaration of prototypes:
//Prototypes: State Machine
void Display_SC_OnExit(int state, struct SDL2Display_Instance *_instance);
//Prototypes: Message Sending
void SDL2Display_send_display_displayReady(struct SDL2Display_Instance *_instance);
void SDL2Display_send_display_displayError(struct SDL2Display_Instance *_instance);
void SDL2Display_send_controls_position(struct SDL2Display_Instance *_instance, int16_t x, int16_t y);
void SDL2Display_send_controls_fire(struct SDL2Display_Instance *_instance, uint8_t id);
//Prototypes: Function
void f_SDL2Display_updateControl(struct SDL2Display_Instance *_instance, int16_t dx);
void f_SDL2Display_startEventPolling(struct SDL2Display_Instance *_instance);
void f_SDL2Display_initDisplay(struct SDL2Display_Instance *_instance, uint8_t xsize, uint8_t ysize);
void f_SDL2Display_destroyDisplay(struct SDL2Display_Instance *_instance);
void f_SDL2Display_clearScreen(struct SDL2Display_Instance *_instance);
void f_SDL2Display_setColor(struct SDL2Display_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void f_SDL2Display_drawRect(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void f_SDL2Display_fillRect(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void f_SDL2Display_updateDisplay(struct SDL2Display_Instance *_instance);
void f_SDL2Display_drawDigit(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, uint8_t d, uint8_t size);
void f_SDL2Display_drawInteger(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void f_SDL2Display_clearInteger(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, uint8_t digits, uint8_t scale);
// Declaration of functions:
// Definition of function updateControl
void f_SDL2Display_updateControl(struct SDL2Display_Instance *_instance, int16_t dx) {
_instance->SDL2Display_xctrl_var = _instance->SDL2Display_xctrl_var + dx;
if(_instance->SDL2Display_xctrl_var > 100) {
_instance->SDL2Display_xctrl_var = 100;

} else {
if(_instance->SDL2Display_xctrl_var <  -100) {
_instance->SDL2Display_xctrl_var =  -100;

}

}
SDL2Display_send_controls_position(_instance, _instance->SDL2Display_xctrl_var, 0);
}
// Fork a thread to execute the function f_SDL2Display_startEventPolling

// Struct for the parameters of the function  f_SDL2Display_startEventPolling
struct f_SDL2Display_startEventPolling_struct {
  struct SDL2Display_Instance *_instance;

  pthread_mutex_t *lock;
  pthread_cond_t *cv;
};

// Definition of function start_receiver_process (executed in a separate thread)
void f_SDL2Display_startEventPolling_run(struct SDL2Display_Instance *_instance)
{
  SDL_Event event;
while(1) {
SDL_WaitEvent(&event);
if(event.type == SDL_WINDOWEVENT) {
if(event.window.event == SDL_WINDOWEVENT_CLOSE) {
f_SDL2Display_destroyDisplay(_instance);
exit(0);

}

} else {
if(event.type == SDL_KEYDOWN) {
switch(event.key.keysym.sym) {
case SDLK_LEFT:  
f_SDL2Display_updateControl(_instance,  -10);
 break;
case SDLK_RIGHT: 
f_SDL2Display_updateControl(_instance, 10);
 break;
}

} else {
if(event.type == SDL_MOUSEMOTION) {
;uint16_t mousex = event.motion.x;
;uint16_t mousey = event.motion.y;
_instance->SDL2Display_xctrl_var = ((mousex - _instance->SDL2Display_XFRAMESIZE_var / 2) * 220) / _instance->SDL2Display_XFRAMESIZE_var;
f_SDL2Display_updateControl(_instance, 0);

}

}

}

}

}


void f_SDL2Display_startEventPolling_proc(void * p)
{
  // Get parameters from the main thread
  struct f_SDL2Display_startEventPolling_struct params = *((struct f_SDL2Display_startEventPolling_struct *) p);
  
  // Unblock the main thread
  pthread_mutex_lock(params.lock);
  pthread_cond_signal(params.cv);
  pthread_mutex_unlock(params.lock);
  
  // Run the function
  //f_SDL2Display_startEventPolling_run(params._instance, params.esums_device);
  f_SDL2Display_startEventPolling_run(params._instance);
}

// Operation called by the runtime and forking a new thread
void f_SDL2Display_startEventPolling(struct SDL2Display_Instance *_instance)
{
  // Store parameters
  struct f_SDL2Display_startEventPolling_struct params;
  pthread_mutex_t lock;
  pthread_cond_t cv;
  params.lock = &lock;
  params.cv = &cv;
  params._instance = _instance;

  pthread_mutex_init(params.lock, NULL);
  pthread_cond_init(params.cv, NULL);
  //Start the new thread
  pthread_mutex_lock(params.lock);
  pthread_t thread; 
  pthread_create( &thread, NULL, f_SDL2Display_startEventPolling_proc, (void*) &params);
  // Wait until it has started and read its parameters
  pthread_cond_wait(params.cv, params.lock);
  // Realease mutex
  pthread_mutex_unlock(params.lock);
}// Definition of function initDisplay
void f_SDL2Display_initDisplay(struct SDL2Display_Instance *_instance, uint8_t xsize, uint8_t ysize) {
_instance->SDL2Display_XFRAMESIZE_var = (xsize - 1) * _instance->SDL2Display_scale_var;
_instance->SDL2Display_YFRAMESIZE_var = (ysize - 1) * _instance->SDL2Display_scale_var;
window = SDL_CreateWindow
	    (	"ThingML / SDL2 Window", SDL_WINDOWPOS_UNDEFINED,
	        SDL_WINDOWPOS_UNDEFINED,
	        _instance->SDL2Display_XFRAMESIZE_var, _instance->SDL2Display_YFRAMESIZE_var, SDL_WINDOW_SHOWN	);
renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
SDL_RenderSetScale(renderer, _instance->SDL2Display_scale_var, _instance->SDL2Display_scale_var);
f_SDL2Display_clearScreen(_instance);
f_SDL2Display_startEventPolling(_instance);
f_SDL2Display_updateControl(_instance, 0);
}
// Definition of function destroyDisplay
void f_SDL2Display_destroyDisplay(struct SDL2Display_Instance *_instance) {
SDL_DestroyWindow(window);
    	SDL_Quit();
}
// Definition of function clearScreen
void f_SDL2Display_clearScreen(struct SDL2Display_Instance *_instance) {
SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
SDL_RenderClear( renderer );
SDL_RenderPresent(renderer);
}
// Definition of function setColor
void f_SDL2Display_setColor(struct SDL2Display_Instance *_instance, uint8_t r, uint8_t g, uint8_t b) {
SDL_SetRenderDrawColor( renderer, r, g, b, 255);
}
// Definition of function drawRect
void f_SDL2Display_drawRect(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
SDL_Rect r;
	    r.x = x;
	    r.y = y;
	    r.w = width;
	    r.h = height;
SDL_RenderDrawRect( renderer, &r );
}
// Definition of function fillRect
void f_SDL2Display_fillRect(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
SDL_Rect r;
	    r.x = x;
	    r.y = y;
	    r.w = width;
	    r.h = height;
SDL_RenderFillRect( renderer, &r );
}
// Definition of function updateDisplay
void f_SDL2Display_updateDisplay(struct SDL2Display_Instance *_instance) {
SDL_RenderPresent(renderer);
}
// Definition of function drawDigit
void f_SDL2Display_drawDigit(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, uint8_t d, uint8_t size) {
if(d < 1) {
f_SDL2Display_fillRect(_instance, x, y, size, 5 * size);
f_SDL2Display_fillRect(_instance, x, y, 3 * size, size);
f_SDL2Display_fillRect(_instance, x + 2 * size, y, size, 5 * size);
f_SDL2Display_fillRect(_instance, x, y + 4 * size, 3 * size, size);

} else {
if(d < 2) {
f_SDL2Display_fillRect(_instance, x + size, y, size, 5 * size);

} else {
if(d < 3) {
f_SDL2Display_fillRect(_instance, x, y, size * 3, size);
f_SDL2Display_fillRect(_instance, x + 2 * size, y, size, 3 * size);
f_SDL2Display_fillRect(_instance, x, y + 2 * size, 3 * size, size);
f_SDL2Display_fillRect(_instance, x, y + 2 * size, size, 3 * size);
f_SDL2Display_fillRect(_instance, x, y + 4 * size, 3 * size, size);

} else {
if(d < 4) {
f_SDL2Display_fillRect(_instance, x, y, size * 3, size);
f_SDL2Display_fillRect(_instance, x + 2 * size, y, size, 5 * size);
f_SDL2Display_fillRect(_instance, x, y + 4 * size, 3 * size, size);
f_SDL2Display_fillRect(_instance, x + size, y + 2 * size, 2 * size, size);

} else {
if(d < 5) {
f_SDL2Display_fillRect(_instance, x, y, size, 3 * size);
f_SDL2Display_fillRect(_instance, x, y + 2 * size, 3 * size, size);
f_SDL2Display_fillRect(_instance, x + 2 * size, y, size, 5 * size);

} else {
if(d < 6) {
f_SDL2Display_fillRect(_instance, x, y, size * 3, size);
f_SDL2Display_fillRect(_instance, x, y, size, 3 * size);
f_SDL2Display_fillRect(_instance, x, y + 2 * size, 3 * size, size);
f_SDL2Display_fillRect(_instance, x + 2 * size, y + 2 * size, size, 3 * size);
f_SDL2Display_fillRect(_instance, x, y + 4 * size, 3 * size, size);

} else {
if(d < 7) {
f_SDL2Display_fillRect(_instance, x, y, size * 3, size);
f_SDL2Display_fillRect(_instance, x, y, size, 5 * size);
f_SDL2Display_fillRect(_instance, x, y + 2 * size, 3 * size, size);
f_SDL2Display_fillRect(_instance, x + 2 * size, y + 2 * size, size, 3 * size);
f_SDL2Display_fillRect(_instance, x, y + 4 * size, 3 * size, size);

} else {
if(d < 8) {
f_SDL2Display_fillRect(_instance, x, y, 3 * size, size);
f_SDL2Display_fillRect(_instance, x + 2 * size, y, size, 5 * size);

} else {
if(d < 9) {
f_SDL2Display_fillRect(_instance, x, y, size, 5 * size);
f_SDL2Display_fillRect(_instance, x, y, 3 * size, size);
f_SDL2Display_fillRect(_instance, x + 2 * size, y, size, 5 * size);
f_SDL2Display_fillRect(_instance, x, y + 4 * size, 3 * size, size);
f_SDL2Display_fillRect(_instance, x, y + 2 * size, 3 * size, size);

} else {
f_SDL2Display_fillRect(_instance, x, y, size, 3 * size);
f_SDL2Display_fillRect(_instance, x, y, 3 * size, size);
f_SDL2Display_fillRect(_instance, x + 2 * size, y, size, 5 * size);
f_SDL2Display_fillRect(_instance, x, y + 4 * size, 3 * size, size);
f_SDL2Display_fillRect(_instance, x, y + 2 * size, 3 * size, size);

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
void f_SDL2Display_drawInteger(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale) {
f_SDL2Display_clearInteger(_instance, x, y, digits, scale);
;int16_t val = v;
;uint8_t d = digits;
while(d > 0) {
f_SDL2Display_drawDigit(_instance, x + (d - 1) * 4 * scale, y, val % 10, scale);
val = val / 10;
d = d - 1;

}
}
// Definition of function clearInteger
void f_SDL2Display_clearInteger(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, uint8_t digits, uint8_t scale) {
f_SDL2Display_setColor(_instance, _instance->Display_bg_r_var, _instance->Display_bg_g_var, _instance->Display_bg_b_var);
f_SDL2Display_fillRect(_instance, x, y, (digits * 4 - 1) * scale, 5 * scale);
f_SDL2Display_setColor(_instance, _instance->Display_fg_r_var, _instance->Display_fg_g_var, _instance->Display_fg_b_var);
}

// Sessions functionss:


// On Entry Actions:
void Display_SC_OnEntry(int state, struct SDL2Display_Instance *_instance) {
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
SDL2Display_send_display_displayReady(_instance);
break;
}
case DISPLAY_SC_DESTROYED_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Display_SC_OnExit(int state, struct SDL2Display_Instance *_instance) {
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
void SDL2Display_handle_display_clear(struct SDL2Display_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_SDL2Display_clearScreen(_instance);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SDL2Display_handle_display_fillRect(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_SDL2Display_fillRect(_instance, x, y, width, height);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SDL2Display_handle_display_update(struct SDL2Display_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_SDL2Display_updateDisplay(_instance);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SDL2Display_handle_display_drawInteger(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_SDL2Display_drawInteger(_instance, x, y, v, digits, scale);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SDL2Display_handle_display_create(struct SDL2Display_Instance *_instance, uint8_t xsize, uint8_t ysize) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_WAIT_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
Display_SC_OnExit(DISPLAY_SC_WAIT_STATE, _instance);
_instance->Display_SC_State = DISPLAY_SC_RUNNING_STATE;
f_SDL2Display_initDisplay(_instance, xsize, ysize);
Display_SC_OnEntry(DISPLAY_SC_RUNNING_STATE, _instance);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SDL2Display_handle_display_destroy(struct SDL2Display_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
Display_SC_OnExit(DISPLAY_SC_RUNNING_STATE, _instance);
_instance->Display_SC_State = DISPLAY_SC_DESTROYED_STATE;
f_SDL2Display_destroyDisplay(_instance);
Display_SC_OnEntry(DISPLAY_SC_DESTROYED_STATE, _instance);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SDL2Display_handle_display_setColor(struct SDL2Display_Instance *_instance, uint8_t r, uint8_t g, uint8_t b) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
_instance->Display_fg_r_var = r;
_instance->Display_fg_g_var = g;
_instance->Display_fg_b_var = b;
f_SDL2Display_setColor(_instance, r, g, b);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SDL2Display_handle_display_drawRect(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_SDL2Display_drawRect(_instance, x, y, width, height);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SDL2Display_handle_display_setBGColor(struct SDL2Display_Instance *_instance, uint8_t r, uint8_t g, uint8_t b) {
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

// Observers for outgoing messages:
void (*external_SDL2Display_send_display_displayReady_listener)(struct SDL2Display_Instance *)= 0x0;
void (*SDL2Display_send_display_displayReady_listener)(struct SDL2Display_Instance *)= 0x0;
void register_external_SDL2Display_send_display_displayReady_listener(void (*_listener)(struct SDL2Display_Instance *)){
external_SDL2Display_send_display_displayReady_listener = _listener;
}
void register_SDL2Display_send_display_displayReady_listener(void (*_listener)(struct SDL2Display_Instance *)){
SDL2Display_send_display_displayReady_listener = _listener;
}
void SDL2Display_send_display_displayReady(struct SDL2Display_Instance *_instance){
if (SDL2Display_send_display_displayReady_listener != 0x0) SDL2Display_send_display_displayReady_listener(_instance);
if (external_SDL2Display_send_display_displayReady_listener != 0x0) external_SDL2Display_send_display_displayReady_listener(_instance);
;
}
void (*external_SDL2Display_send_display_displayError_listener)(struct SDL2Display_Instance *)= 0x0;
void (*SDL2Display_send_display_displayError_listener)(struct SDL2Display_Instance *)= 0x0;
void register_external_SDL2Display_send_display_displayError_listener(void (*_listener)(struct SDL2Display_Instance *)){
external_SDL2Display_send_display_displayError_listener = _listener;
}
void register_SDL2Display_send_display_displayError_listener(void (*_listener)(struct SDL2Display_Instance *)){
SDL2Display_send_display_displayError_listener = _listener;
}
void SDL2Display_send_display_displayError(struct SDL2Display_Instance *_instance){
if (SDL2Display_send_display_displayError_listener != 0x0) SDL2Display_send_display_displayError_listener(_instance);
if (external_SDL2Display_send_display_displayError_listener != 0x0) external_SDL2Display_send_display_displayError_listener(_instance);
;
}
void (*external_SDL2Display_send_controls_position_listener)(struct SDL2Display_Instance *, int16_t, int16_t)= 0x0;
void (*SDL2Display_send_controls_position_listener)(struct SDL2Display_Instance *, int16_t, int16_t)= 0x0;
void register_external_SDL2Display_send_controls_position_listener(void (*_listener)(struct SDL2Display_Instance *, int16_t, int16_t)){
external_SDL2Display_send_controls_position_listener = _listener;
}
void register_SDL2Display_send_controls_position_listener(void (*_listener)(struct SDL2Display_Instance *, int16_t, int16_t)){
SDL2Display_send_controls_position_listener = _listener;
}
void SDL2Display_send_controls_position(struct SDL2Display_Instance *_instance, int16_t x, int16_t y){
if (SDL2Display_send_controls_position_listener != 0x0) SDL2Display_send_controls_position_listener(_instance, x, y);
if (external_SDL2Display_send_controls_position_listener != 0x0) external_SDL2Display_send_controls_position_listener(_instance, x, y);
;
}
void (*external_SDL2Display_send_controls_fire_listener)(struct SDL2Display_Instance *, uint8_t)= 0x0;
void (*SDL2Display_send_controls_fire_listener)(struct SDL2Display_Instance *, uint8_t)= 0x0;
void register_external_SDL2Display_send_controls_fire_listener(void (*_listener)(struct SDL2Display_Instance *, uint8_t)){
external_SDL2Display_send_controls_fire_listener = _listener;
}
void register_SDL2Display_send_controls_fire_listener(void (*_listener)(struct SDL2Display_Instance *, uint8_t)){
SDL2Display_send_controls_fire_listener = _listener;
}
void SDL2Display_send_controls_fire(struct SDL2Display_Instance *_instance, uint8_t id){
if (SDL2Display_send_controls_fire_listener != 0x0) SDL2Display_send_controls_fire_listener(_instance, id);
if (external_SDL2Display_send_controls_fire_listener != 0x0) external_SDL2Display_send_controls_fire_listener(_instance, id);
;
}



