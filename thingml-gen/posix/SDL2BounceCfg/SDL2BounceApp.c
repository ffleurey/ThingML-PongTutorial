/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing SDL2BounceApp
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "SDL2BounceApp.h"

/*****************************************************************************
 * Implementation for type : SDL2BounceApp
 *****************************************************************************/


// BEGIN: Code from the c_global annotation SDL2BounceApp

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

// END: Code from the c_global annotation SDL2BounceApp

// Declaration of prototypes:
//Prototypes: State Machine
void BounceApp_SC_OnExit(int state, struct SDL2BounceApp_Instance *_instance);
//Prototypes: Message Sending
void SDL2BounceApp_send_clock_timer_start(struct SDL2BounceApp_Instance *_instance, uint8_t id, uint32_t time);
void SDL2BounceApp_send_clock_timer_cancel(struct SDL2BounceApp_Instance *_instance, uint8_t id);
void SDL2BounceApp_send_ball_bounce(struct SDL2BounceApp_Instance *_instance);
void SDL2BounceApp_send_ball_stop(struct SDL2BounceApp_Instance *_instance);
//Prototypes: Function
void f_SDL2BounceApp_startEventPolling(struct SDL2BounceApp_Instance *_instance);
void f_SDL2BounceApp_initDisplay(struct SDL2BounceApp_Instance *_instance);
void f_SDL2BounceApp_destroyDisplay(struct SDL2BounceApp_Instance *_instance);
void f_SDL2BounceApp_clearScreen(struct SDL2BounceApp_Instance *_instance);
void f_SDL2BounceApp_setColor(struct SDL2BounceApp_Instance *_instance, uint16_t c);
void f_SDL2BounceApp_drawRect(struct SDL2BounceApp_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void f_SDL2BounceApp_fillRect(struct SDL2BounceApp_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void f_SDL2BounceApp_drawText(struct SDL2BounceApp_Instance *_instance, uint8_t x, uint8_t y, uint8_t size, char * text);
// Declaration of functions:
// Fork a thread to execute the function f_SDL2BounceApp_startEventPolling

// Struct for the parameters of the function  f_SDL2BounceApp_startEventPolling
struct f_SDL2BounceApp_startEventPolling_struct {
  struct SDL2BounceApp_Instance *_instance;

  pthread_mutex_t *lock;
  pthread_cond_t *cv;
};

// Definition of function start_receiver_process (executed in a separate thread)
void f_SDL2BounceApp_startEventPolling_run(struct SDL2BounceApp_Instance *_instance)
{
  SDL_Event event;
while(1) {
SDL_WaitEvent(&event);
if(event.type == SDL_WINDOWEVENT) {
if(event.window.event == SDL_WINDOWEVENT_CLOSE) {
f_SDL2BounceApp_destroyDisplay(_instance);
exit(0);

}

}

}

}


void f_SDL2BounceApp_startEventPolling_proc(void * p)
{
  // Get parameters from the main thread
  struct f_SDL2BounceApp_startEventPolling_struct params = *((struct f_SDL2BounceApp_startEventPolling_struct *) p);
  
  // Unblock the main thread
  pthread_mutex_lock(params.lock);
  pthread_cond_signal(params.cv);
  pthread_mutex_unlock(params.lock);
  
  // Run the function
  //f_SDL2BounceApp_startEventPolling_run(params._instance, params.esums_device);
  f_SDL2BounceApp_startEventPolling_run(params._instance);
}

// Operation called by the runtime and forking a new thread
void f_SDL2BounceApp_startEventPolling(struct SDL2BounceApp_Instance *_instance)
{
  // Store parameters
  struct f_SDL2BounceApp_startEventPolling_struct params;
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
  pthread_create( &thread, NULL, f_SDL2BounceApp_startEventPolling_proc, (void*) &params);
  // Wait until it has started and read its parameters
  pthread_cond_wait(params.cv, params.lock);
  // Realease mutex
  pthread_mutex_unlock(params.lock);
}// Definition of function initDisplay
void f_SDL2BounceApp_initDisplay(struct SDL2BounceApp_Instance *_instance) {
window = SDL_CreateWindow
	    (	"ThingML / SDL2 Window", SDL_WINDOWPOS_UNDEFINED,
	        SDL_WINDOWPOS_UNDEFINED,
	        (_instance->Constants_XSIZE_var - 1) * _instance->SDL2BounceApp_scale_var, (_instance->Constants_YSIZE_var - 1) * _instance->SDL2BounceApp_scale_var, SDL_WINDOW_SHOWN	);
renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
SDL_RenderSetScale(renderer, _instance->SDL2BounceApp_scale_var, _instance->SDL2BounceApp_scale_var);
TTF_Init();
f_SDL2BounceApp_clearScreen(_instance);
f_SDL2BounceApp_startEventPolling(_instance);
}
// Definition of function destroyDisplay
void f_SDL2BounceApp_destroyDisplay(struct SDL2BounceApp_Instance *_instance) {
SDL_DestroyWindow(window);
    	SDL_Quit();
}
// Definition of function clearScreen
void f_SDL2BounceApp_clearScreen(struct SDL2BounceApp_Instance *_instance) {
SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
SDL_RenderClear( renderer );
SDL_RenderPresent(renderer);
}
// Definition of function setColor
void f_SDL2BounceApp_setColor(struct SDL2BounceApp_Instance *_instance, uint16_t c) {
_instance->SDL2BounceApp_color_var = c;
}
// Definition of function drawRect
void f_SDL2BounceApp_drawRect(struct SDL2BounceApp_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
SDL_Rect r;
	    r.x = x;
	    r.y = y;
	    r.w = width;
	    r.h = height;
if(_instance->SDL2BounceApp_color_var == COLOR_BLACK) {
SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

} else {
if(_instance->SDL2BounceApp_color_var == COLOR_WHITE) {
SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

}

}
SDL_RenderDrawRect( renderer, &r );
SDL_RenderPresent(renderer);
}
// Definition of function fillRect
void f_SDL2BounceApp_fillRect(struct SDL2BounceApp_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
SDL_Rect r;
	    r.x = x;
	    r.y = y;
	    r.w = width;
	    r.h = height;
if(_instance->SDL2BounceApp_color_var == COLOR_BLACK) {
SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

} else {
if(_instance->SDL2BounceApp_color_var == COLOR_WHITE) {
SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

}

}
SDL_RenderFillRect( renderer, &r );
SDL_RenderPresent(renderer);
}
// Definition of function drawText
void f_SDL2BounceApp_drawText(struct SDL2BounceApp_Instance *_instance, uint8_t x, uint8_t y, uint8_t size, char * text) {
TTF_Font* Sans = TTF_OpenFont(_instance->SDL2BounceApp_TTF_FONT_PATH_var, 20);
if(Sans == NULL) {
fprintf(stdout, "[ERROR] SDL2BounceApp: TTF font file could not be loaded. Text will not be rendered.\n");

} else {
SDL_Color White = {255, 255, 255};
SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, text, White);
SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
SDL_Rect Message_rect; //create a rect
			Message_rect.x = x;  //controls the rects x coordinate 
			Message_rect.y = y - 10; // controls the rects y coordinte
			Message_rect.w = 100; // controls the width of the rect
			Message_rect.h = 30; // controls the height of the rect
	
			SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
			
			SDL_FreeSurface(surfaceMessage);
			SDL_DestroyTexture(Message); 
SDL_RenderPresent(renderer);

}
}

// Sessions functionss:


// On Entry Actions:
void BounceApp_SC_OnEntry(int state, struct SDL2BounceApp_Instance *_instance) {
switch(state) {
case BOUNCEAPP_SC_STATE:{
_instance->BounceApp_SC_State = BOUNCEAPP_SC_WELCOME_STATE;
f_SDL2BounceApp_initDisplay(_instance);
BounceApp_SC_OnEntry(_instance->BounceApp_SC_State, _instance);
break;
}
case BOUNCEAPP_SC_WELCOME_STATE:{
f_SDL2BounceApp_clearScreen(_instance);
f_SDL2BounceApp_setColor(_instance, COLOR_WHITE);
f_SDL2BounceApp_fillRect(_instance, 0, 0, _instance->Constants_XSIZE_var, _instance->Constants_YSIZE_var);
f_SDL2BounceApp_setColor(_instance, COLOR_BLACK);
f_SDL2BounceApp_fillRect(_instance, 5, 5, _instance->Constants_XSIZE_var - 10, _instance->Constants_YSIZE_var - 10);
f_SDL2BounceApp_setColor(_instance, COLOR_WHITE);
f_SDL2BounceApp_drawText(_instance, 30, _instance->Constants_YSIZE_var / 2 - 10, 2, "Bounce !");
SDL2BounceApp_send_clock_timer_start(_instance, 0, 2000);
break;
}
case BOUNCEAPP_SC_BOUNCING_STATE:{
f_SDL2BounceApp_clearScreen(_instance);
f_SDL2BounceApp_drawRect(_instance, 0, 0, _instance->Constants_XSIZE_var - 1, _instance->Constants_YSIZE_var - 1);
SDL2BounceApp_send_ball_bounce(_instance);
SDL2BounceApp_send_clock_timer_start(_instance, 1, 30);
break;
}
default: break;
}
}

// On Exit Actions:
void BounceApp_SC_OnExit(int state, struct SDL2BounceApp_Instance *_instance) {
switch(state) {
case BOUNCEAPP_SC_STATE:{
BounceApp_SC_OnExit(_instance->BounceApp_SC_State, _instance);
break;}
case BOUNCEAPP_SC_WELCOME_STATE:{
break;}
case BOUNCEAPP_SC_BOUNCING_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void SDL2BounceApp_handle_clock_timer_timeout(struct SDL2BounceApp_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SC
uint8_t BounceApp_SC_State_event_consumed = 0;
if (_instance->BounceApp_SC_State == BOUNCEAPP_SC_WELCOME_STATE) {
if (BounceApp_SC_State_event_consumed == 0 && id == 0) {
BounceApp_SC_OnExit(BOUNCEAPP_SC_WELCOME_STATE, _instance);
_instance->BounceApp_SC_State = BOUNCEAPP_SC_BOUNCING_STATE;
BounceApp_SC_OnEntry(BOUNCEAPP_SC_BOUNCING_STATE, _instance);
BounceApp_SC_State_event_consumed = 1;
}
}
else if (_instance->BounceApp_SC_State == BOUNCEAPP_SC_BOUNCING_STATE) {
if (BounceApp_SC_State_event_consumed == 0 && id == 1) {
SDL2BounceApp_send_clock_timer_start(_instance, 1, 30);
BounceApp_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SDL2BounceApp_handle_ball_updateBall(struct SDL2BounceApp_Instance *_instance, uint8_t oldx, uint8_t oldy, uint8_t newx, uint8_t newy) {
if(!(_instance->active)) return;
//Region SC
uint8_t BounceApp_SC_State_event_consumed = 0;
if (_instance->BounceApp_SC_State == BOUNCEAPP_SC_BOUNCING_STATE) {
if (BounceApp_SC_State_event_consumed == 0 && 1) {
f_SDL2BounceApp_setColor(_instance, COLOR_BLACK);
f_SDL2BounceApp_fillRect(_instance, oldx - 3, oldy - 3, 6, 6);
f_SDL2BounceApp_setColor(_instance, COLOR_WHITE);
f_SDL2BounceApp_fillRect(_instance, newx - 2, newy - 3, 4, 6);
f_SDL2BounceApp_fillRect(_instance, newx - 3, newy - 2, 6, 4);
BounceApp_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
void (*external_SDL2BounceApp_send_clock_timer_start_listener)(struct SDL2BounceApp_Instance *, uint8_t, uint32_t)= 0x0;
void (*SDL2BounceApp_send_clock_timer_start_listener)(struct SDL2BounceApp_Instance *, uint8_t, uint32_t)= 0x0;
void register_external_SDL2BounceApp_send_clock_timer_start_listener(void (*_listener)(struct SDL2BounceApp_Instance *, uint8_t, uint32_t)){
external_SDL2BounceApp_send_clock_timer_start_listener = _listener;
}
void register_SDL2BounceApp_send_clock_timer_start_listener(void (*_listener)(struct SDL2BounceApp_Instance *, uint8_t, uint32_t)){
SDL2BounceApp_send_clock_timer_start_listener = _listener;
}
void SDL2BounceApp_send_clock_timer_start(struct SDL2BounceApp_Instance *_instance, uint8_t id, uint32_t time){
if (SDL2BounceApp_send_clock_timer_start_listener != 0x0) SDL2BounceApp_send_clock_timer_start_listener(_instance, id, time);
if (external_SDL2BounceApp_send_clock_timer_start_listener != 0x0) external_SDL2BounceApp_send_clock_timer_start_listener(_instance, id, time);
;
}
void (*external_SDL2BounceApp_send_clock_timer_cancel_listener)(struct SDL2BounceApp_Instance *, uint8_t)= 0x0;
void (*SDL2BounceApp_send_clock_timer_cancel_listener)(struct SDL2BounceApp_Instance *, uint8_t)= 0x0;
void register_external_SDL2BounceApp_send_clock_timer_cancel_listener(void (*_listener)(struct SDL2BounceApp_Instance *, uint8_t)){
external_SDL2BounceApp_send_clock_timer_cancel_listener = _listener;
}
void register_SDL2BounceApp_send_clock_timer_cancel_listener(void (*_listener)(struct SDL2BounceApp_Instance *, uint8_t)){
SDL2BounceApp_send_clock_timer_cancel_listener = _listener;
}
void SDL2BounceApp_send_clock_timer_cancel(struct SDL2BounceApp_Instance *_instance, uint8_t id){
if (SDL2BounceApp_send_clock_timer_cancel_listener != 0x0) SDL2BounceApp_send_clock_timer_cancel_listener(_instance, id);
if (external_SDL2BounceApp_send_clock_timer_cancel_listener != 0x0) external_SDL2BounceApp_send_clock_timer_cancel_listener(_instance, id);
;
}
void (*external_SDL2BounceApp_send_ball_bounce_listener)(struct SDL2BounceApp_Instance *)= 0x0;
void (*SDL2BounceApp_send_ball_bounce_listener)(struct SDL2BounceApp_Instance *)= 0x0;
void register_external_SDL2BounceApp_send_ball_bounce_listener(void (*_listener)(struct SDL2BounceApp_Instance *)){
external_SDL2BounceApp_send_ball_bounce_listener = _listener;
}
void register_SDL2BounceApp_send_ball_bounce_listener(void (*_listener)(struct SDL2BounceApp_Instance *)){
SDL2BounceApp_send_ball_bounce_listener = _listener;
}
void SDL2BounceApp_send_ball_bounce(struct SDL2BounceApp_Instance *_instance){
if (SDL2BounceApp_send_ball_bounce_listener != 0x0) SDL2BounceApp_send_ball_bounce_listener(_instance);
if (external_SDL2BounceApp_send_ball_bounce_listener != 0x0) external_SDL2BounceApp_send_ball_bounce_listener(_instance);
;
}
void (*external_SDL2BounceApp_send_ball_stop_listener)(struct SDL2BounceApp_Instance *)= 0x0;
void (*SDL2BounceApp_send_ball_stop_listener)(struct SDL2BounceApp_Instance *)= 0x0;
void register_external_SDL2BounceApp_send_ball_stop_listener(void (*_listener)(struct SDL2BounceApp_Instance *)){
external_SDL2BounceApp_send_ball_stop_listener = _listener;
}
void register_SDL2BounceApp_send_ball_stop_listener(void (*_listener)(struct SDL2BounceApp_Instance *)){
SDL2BounceApp_send_ball_stop_listener = _listener;
}
void SDL2BounceApp_send_ball_stop(struct SDL2BounceApp_Instance *_instance){
if (SDL2BounceApp_send_ball_stop_listener != 0x0) SDL2BounceApp_send_ball_stop_listener(_instance);
if (external_SDL2BounceApp_send_ball_stop_listener != 0x0) external_SDL2BounceApp_send_ball_stop_listener(_instance);
;
}



