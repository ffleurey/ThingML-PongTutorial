/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application SimpleBrickSDL2
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <pthread.h>
#include "thingml_typedefs.h"
#include "runtime.h"
#include "BasicIAController.h"
#include "SDL2Display.h"
#include "SimpleBrick.h"

#include "Timer.h"




/*****************************************************************************
 * Definitions for configuration : SimpleBrickSDL2
 *****************************************************************************/

uint8_t array_bb_SimpleBrick_bricks_var[5];
uint8_t array_bb_SimpleBrick_fgcolor_var[3];
uint8_t array_bb_SimpleBrick_bgcolor_var[3];
//Declaration of instance variables
//Instance ctrl
// Variables for the properties of the instance
struct BasicIAController_Instance ctrl_var;
// Variables for the sessions of the instance
//Instance disp
// Variables for the properties of the instance
struct SDL2Display_Instance disp_var;
// Variables for the sessions of the instance
//Instance bb
// Variables for the properties of the instance
struct SimpleBrick_Instance bb_var;
// Variables for the sessions of the instance

//Instance Timer for network plugin PosixTimerPlugin
struct Timer_Instance Timer_instance;

// Enqueue of messages BasicIAController::controls::position
void enqueue_BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y){
fifo_lock();
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_controls >> 8) & 0xFF );
_fifo_enqueue( _instance->id_controls & 0xFF );

// parameter x
union u_x_t {
int16_t p;
byte bytebuffer[2];
} u_x;
u_x.p = x;
_fifo_enqueue(u_x.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[0] & 0xFF );

// parameter y
union u_y_t {
int16_t p;
byte bytebuffer[2];
} u_y;
u_y.p = y;
_fifo_enqueue(u_y.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SDL2Display::display::displayReady
void enqueue_SDL2Display_send_display_displayReady(struct SDL2Display_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SDL2Display::display::displayError
void enqueue_SDL2Display_send_display_displayError(struct SDL2Display_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SDL2Display::controls::position
void enqueue_SDL2Display_send_controls_position(struct SDL2Display_Instance *_instance, int16_t x, int16_t y){
fifo_lock();
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_controls >> 8) & 0xFF );
_fifo_enqueue( _instance->id_controls & 0xFF );

// parameter x
union u_x_t {
int16_t p;
byte bytebuffer[2];
} u_x;
u_x.p = x;
_fifo_enqueue(u_x.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[0] & 0xFF );

// parameter y
union u_y_t {
int16_t p;
byte bytebuffer[2];
} u_y;
u_y.p = y;
_fifo_enqueue(u_y.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SimpleBrick::ia::updateIA
void enqueue_SimpleBrick_send_ia_updateIA(struct SimpleBrick_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady){
fifo_lock();
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_ia >> 8) & 0xFF );
_fifo_enqueue( _instance->id_ia & 0xFF );

// parameter ballx
union u_ballx_t {
int16_t p;
byte bytebuffer[2];
} u_ballx;
u_ballx.p = ballx;
_fifo_enqueue(u_ballx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_ballx.bytebuffer[0] & 0xFF );

// parameter bally
union u_bally_t {
int16_t p;
byte bytebuffer[2];
} u_bally;
u_bally.p = bally;
_fifo_enqueue(u_bally.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bally.bytebuffer[0] & 0xFF );

// parameter padx
union u_padx_t {
int16_t p;
byte bytebuffer[2];
} u_padx;
u_padx.p = padx;
_fifo_enqueue(u_padx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_padx.bytebuffer[0] & 0xFF );

// parameter pady
union u_pady_t {
int16_t p;
byte bytebuffer[2];
} u_pady;
u_pady.p = pady;
_fifo_enqueue(u_pady.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_pady.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SimpleBrick::game::nextLevel
void enqueue_SimpleBrick_send_game_nextLevel(struct SimpleBrick_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_game & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SimpleBrick::game::lostBall
void enqueue_SimpleBrick_send_game_lostBall(struct SimpleBrick_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_game & 0xFF );
}
fifo_unlock_and_notify();
}


//New dispatcher for messages
void dispatch_clear(uint16_t sender) {
if (sender == bb_var.id_game) {

}
if (sender == bb_var.id_display) {
SDL2Display_handle_display_clear(&disp_var);

}

}

void sync_dispatch_SimpleBrick_send_display_clear(struct SimpleBrick_Instance *_instance){
dispatch_clear(_instance->id_display);
}

//New dispatcher for messages
void dispatch_timer_cancel(uint16_t sender, uint8_t param_id) {
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_fillRect(uint16_t sender, uint8_t param_x, uint8_t param_y, uint8_t param_width, uint8_t param_height) {
if (sender == bb_var.id_game) {

}
if (sender == bb_var.id_display) {
SDL2Display_handle_display_fillRect(&disp_var, param_x, param_y, param_width, param_height);

}

}

void sync_dispatch_SimpleBrick_send_display_fillRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
dispatch_fillRect(_instance->id_display, x, y, width, height);
}

//New dispatcher for messages
void dispatch_lostBall(uint16_t sender) {
if (sender == bb_var.id_game) {
SimpleBrick_handle_game_lostBall(&bb_var);

}
if (sender == bb_var.id_ia) {

}

}


//New dispatcher for messages
void dispatch_missBall(uint16_t sender) {
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_timer_timeout(uint16_t sender, uint8_t param_id) {
if (sender == bb_var.id_game) {

}
if (sender == Timer_instance.listener_id) {
SimpleBrick_handle_clock_timer_timeout(&bb_var, param_id);

}

}


//New dispatcher for messages
void dispatch_displayReady(uint16_t sender) {
if (sender == bb_var.id_game) {

}
if (sender == disp_var.id_display) {
SimpleBrick_handle_display_displayReady(&bb_var);

}

}


//New dispatcher for messages
void dispatch_position(uint16_t sender, int16_t param_x, int16_t param_y) {
if (sender == bb_var.id_game) {

}
if (sender == disp_var.id_controls) {
SimpleBrick_handle_controller_position(&bb_var, param_x, param_y);

}
if (sender == ctrl_var.id_controls) {
SimpleBrick_handle_controller_position(&bb_var, param_x, param_y);

}

}


//New dispatcher for messages
void dispatch_setColor(uint16_t sender, uint8_t param_r, uint8_t param_g, uint8_t param_b) {
if (sender == bb_var.id_game) {

}
if (sender == bb_var.id_display) {
SDL2Display_handle_display_setColor(&disp_var, param_r, param_g, param_b);

}

}

void sync_dispatch_SimpleBrick_send_display_setColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
dispatch_setColor(_instance->id_display, r, g, b);
}

//New dispatcher for messages
void dispatch_drawRect(uint16_t sender, uint8_t param_x, uint8_t param_y, uint8_t param_width, uint8_t param_height) {
if (sender == bb_var.id_game) {

}
if (sender == bb_var.id_display) {
SDL2Display_handle_display_drawRect(&disp_var, param_x, param_y, param_width, param_height);

}

}

void sync_dispatch_SimpleBrick_send_display_drawRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
dispatch_drawRect(_instance->id_display, x, y, width, height);
}

//New dispatcher for messages
void dispatch_nextLevel(uint16_t sender) {
if (sender == bb_var.id_game) {
SimpleBrick_handle_game_nextLevel(&bb_var);

}

}


//New dispatcher for messages
void dispatch_timer_start(uint16_t sender, uint8_t param_id, uint32_t param_time) {
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_velocity(uint16_t sender, int16_t param_dx, int16_t param_dy) {
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_update(uint16_t sender) {
if (sender == bb_var.id_game) {

}
if (sender == bb_var.id_display) {
SDL2Display_handle_display_update(&disp_var);

}

}

void sync_dispatch_SimpleBrick_send_display_update(struct SimpleBrick_Instance *_instance){
dispatch_update(_instance->id_display);
}

//New dispatcher for messages
void dispatch_updateIA(uint16_t sender, int16_t param_ballx, int16_t param_bally, int16_t param_padx, int16_t param_pady) {
if (sender == bb_var.id_game) {

}
if (sender == bb_var.id_ia) {
BasicIAController_handle_game_updateIA(&ctrl_var, param_ballx, param_bally, param_padx, param_pady);

}

}


//New dispatcher for messages
void dispatch_drawInteger(uint16_t sender, uint8_t param_x, uint8_t param_y, int16_t param_v, uint8_t param_digits, uint8_t param_scale) {
if (sender == bb_var.id_game) {

}
if (sender == bb_var.id_display) {
SDL2Display_handle_display_drawInteger(&disp_var, param_x, param_y, param_v, param_digits, param_scale);

}

}

void sync_dispatch_SimpleBrick_send_display_drawInteger(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale){
dispatch_drawInteger(_instance->id_display, x, y, v, digits, scale);
}

//New dispatcher for messages
void dispatch_create(uint16_t sender, uint8_t param_xsize, uint8_t param_ysize) {
if (sender == bb_var.id_game) {

}
if (sender == bb_var.id_display) {
SDL2Display_handle_display_create(&disp_var, param_xsize, param_ysize);

}

}

void sync_dispatch_SimpleBrick_send_display_create(struct SimpleBrick_Instance *_instance, uint8_t xsize, uint8_t ysize){
dispatch_create(_instance->id_display, xsize, ysize);
}

//New dispatcher for messages
void dispatch_destroy(uint16_t sender) {
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_fire(uint16_t sender, uint8_t param_id) {
if (sender == bb_var.id_game) {

}
if (sender == disp_var.id_controls) {

}
if (sender == ctrl_var.id_controls) {

}

}


//New dispatcher for messages
void dispatch_displayError(uint16_t sender) {
if (sender == bb_var.id_game) {

}
if (sender == disp_var.id_display) {

}

}


//New dispatcher for messages
void dispatch_hitBall(uint16_t sender) {
if (sender == bb_var.id_game) {

}
if (sender == bb_var.id_ia) {

}

}


//New dispatcher for messages
void dispatch_setBGColor(uint16_t sender, uint8_t param_r, uint8_t param_g, uint8_t param_b) {
if (sender == bb_var.id_game) {

}
if (sender == bb_var.id_display) {
SDL2Display_handle_display_setBGColor(&disp_var, param_r, param_g, param_b);

}

}

void sync_dispatch_SimpleBrick_send_display_setBGColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
dispatch_setBGColor(_instance->id_display, r, g, b);
}

int processMessageQueue() {
fifo_lock();
while (fifo_empty()) fifo_wait();
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 6:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_nextLevel = 2;
dispatch_nextLevel((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 7:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_lostBall = 2;
dispatch_lostBall((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 1:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_timer_timeout = 2;
union u_timer_timeout_id_t {
uint8_t p;
byte bytebuffer[1];
} u_timer_timeout_id;
u_timer_timeout_id.bytebuffer[0] = mbuf[mbufi_timer_timeout + 0];
mbufi_timer_timeout += 1;
dispatch_timer_timeout((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_timer_timeout_id.p /* id */ );
break;
}
case 3:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_displayReady = 2;
dispatch_displayReady((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 5:{
byte mbuf[12 - 2];
while (mbufi < (12 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_updateIA = 2;
union u_updateIA_ballx_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_ballx;
u_updateIA_ballx.bytebuffer[1] = mbuf[mbufi_updateIA + 0];
u_updateIA_ballx.bytebuffer[0] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
union u_updateIA_bally_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_bally;
u_updateIA_bally.bytebuffer[1] = mbuf[mbufi_updateIA + 0];
u_updateIA_bally.bytebuffer[0] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
union u_updateIA_padx_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_padx;
u_updateIA_padx.bytebuffer[1] = mbuf[mbufi_updateIA + 0];
u_updateIA_padx.bytebuffer[0] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
union u_updateIA_pady_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_pady;
u_updateIA_pady.bytebuffer[1] = mbuf[mbufi_updateIA + 0];
u_updateIA_pady.bytebuffer[0] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
dispatch_updateIA((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_updateIA_ballx.p /* ballx */ ,
 u_updateIA_bally.p /* bally */ ,
 u_updateIA_padx.p /* padx */ ,
 u_updateIA_pady.p /* pady */ );
break;
}
case 2:{
byte mbuf[8 - 2];
while (mbufi < (8 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_position = 2;
union u_position_x_t {
int16_t p;
byte bytebuffer[2];
} u_position_x;
u_position_x.bytebuffer[1] = mbuf[mbufi_position + 0];
u_position_x.bytebuffer[0] = mbuf[mbufi_position + 1];
mbufi_position += 2;
union u_position_y_t {
int16_t p;
byte bytebuffer[2];
} u_position_y;
u_position_y.bytebuffer[1] = mbuf[mbufi_position + 0];
u_position_y.bytebuffer[0] = mbuf[mbufi_position + 1];
mbufi_position += 2;
dispatch_position((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_position_x.p /* x */ ,
 u_position_y.p /* y */ );
break;
}
case 4:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_displayError = 2;
dispatch_displayError((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
}
return 1;
}

void forward_SimpleBrick_send_clock_timer_start(struct SimpleBrick_Instance *_instance, uint8_t id, uint32_t time){
if(_instance->id_clock == bb_var.id_clock) {
forward_Timer_SimpleBrick_send_clock_timer_start(_instance, id, time);
}
}
void forward_SimpleBrick_send_clock_timer_cancel(struct SimpleBrick_Instance *_instance, uint8_t id){
if(_instance->id_clock == bb_var.id_clock) {
forward_Timer_SimpleBrick_send_clock_timer_cancel(_instance, id);
}
}

//external Message enqueue
void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id) {
if ((msgSize >= 2) && (msg != NULL)) {
uint8_t msgSizeOK = 0;
switch(msg[0] * 256 + msg[1]) {
case 1:
if(msgSize == 3) {
msgSizeOK = 1;}
break;
}

if(msgSizeOK == 1) {
fifo_lock();
if ( fifo_byte_available() > (msgSize + 2) ) {
	uint8_t i;
	for (i = 0; i < 2; i++) {
		_fifo_enqueue(msg[i]);
	}
	_fifo_enqueue((listener_id >> 8) & 0xFF);
	_fifo_enqueue(listener_id & 0xFF);
	for (i = 2; i < msgSize; i++) {
		_fifo_enqueue(msg[i]);
	}
}
fifo_unlock_and_notify();
}
}
}

void initialize_configuration_SimpleBrickSDL2() {
// Initialize connectors
register_external_SimpleBrick_send_clock_timer_start_listener(&forward_SimpleBrick_send_clock_timer_start);
register_external_SimpleBrick_send_clock_timer_cancel_listener(&forward_SimpleBrick_send_clock_timer_cancel);
register_BasicIAController_send_controls_position_listener(&enqueue_BasicIAController_send_controls_position);
register_SDL2Display_send_display_displayReady_listener(&enqueue_SDL2Display_send_display_displayReady);
register_SDL2Display_send_display_displayError_listener(&enqueue_SDL2Display_send_display_displayError);
register_SDL2Display_send_controls_position_listener(&enqueue_SDL2Display_send_controls_position);
register_SimpleBrick_send_display_create_listener(&sync_dispatch_SimpleBrick_send_display_create);
register_SimpleBrick_send_display_fillRect_listener(&sync_dispatch_SimpleBrick_send_display_fillRect);
register_SimpleBrick_send_display_drawRect_listener(&sync_dispatch_SimpleBrick_send_display_drawRect);
register_SimpleBrick_send_display_clear_listener(&sync_dispatch_SimpleBrick_send_display_clear);
register_SimpleBrick_send_display_setColor_listener(&sync_dispatch_SimpleBrick_send_display_setColor);
register_SimpleBrick_send_display_setBGColor_listener(&sync_dispatch_SimpleBrick_send_display_setBGColor);
register_SimpleBrick_send_display_drawInteger_listener(&sync_dispatch_SimpleBrick_send_display_drawInteger);
register_SimpleBrick_send_display_update_listener(&sync_dispatch_SimpleBrick_send_display_update);
register_SimpleBrick_send_ia_updateIA_listener(&enqueue_SimpleBrick_send_ia_updateIA);
register_SimpleBrick_send_game_lostBall_listener(&enqueue_SimpleBrick_send_game_lostBall);
register_SimpleBrick_send_game_nextLevel_listener(&enqueue_SimpleBrick_send_game_nextLevel);

// Init the ID, state variables and properties for external connector Timer

// Network Initialization
// Initialise Timer:
Timer_instance.listener_id = add_instance(&Timer_instance);
Timer_setup(&Timer_instance);

pthread_t thread_Timer;
pthread_create( &thread_Timer, NULL, Timer_loop, &Timer_instance);

// End Network Initialization

// Init the ID, state variables and properties for instance disp
disp_var.active = true;
disp_var.id_display = add_instance( (void*) &disp_var);
disp_var.id_controls = add_instance( (void*) &disp_var);
disp_var.Display_SC_State = DISPLAY_SC_WAIT_STATE;
disp_var.SDL2Display_scale_var = 5;
disp_var.SDL2Display_xctrl_var = 0;
disp_var.Display_bg_b_var = 0;
disp_var.Display_bg_r_var = 0;
disp_var.Display_bg_g_var = 0;
disp_var.Display_fg_r_var = 0;
disp_var.Display_fg_b_var = 0;
disp_var.Display_fg_g_var = 0;

Display_SC_OnEntry(DISPLAY_SC_STATE, &disp_var);
// Init the ID, state variables and properties for instance bb
bb_var.active = true;
bb_var.id_clock = add_instance( (void*) &bb_var);
bb_var.id_display = add_instance( (void*) &bb_var);
bb_var.id_controller = add_instance( (void*) &bb_var);
bb_var.id_ia = add_instance( (void*) &bb_var);
bb_var.id_game = add_instance( (void*) &bb_var);
bb_var.SimpleBrick_SC_State = SIMPLEBRICK_SC_INIT_STATE;
bb_var.SimpleBrick_YMAX_var = 128 * 64;
bb_var.SimpleBrick_BRICK_ROWS_var = 5;
bb_var.SimpleBrick_pady_var = 128 * 64 - 6 * 64;
bb_var.SimpleBrick_RIGHT_var = 160 * 64 - 1 * 64;
bb_var.SimpleBrick_level_var = 1;
bb_var.SimpleBrick_prevBY_var =  -1;
bb_var.SimpleBrick_SCALE_var = 64;
bb_var.SimpleBrick_br_var = 3 * 64;
bb_var.SimpleBrick_bx_var = 160 * 64 / 2;
bb_var.SimpleBrick_dy_var =  -160 * 64 / 65;
bb_var.SimpleBrick_lives_var = 3;
bb_var.SimpleBrick_dx_var = 160 * 64 / 98;
bb_var.SimpleBrick_XDISPSIZE_var = 160;
bb_var.SimpleBrick_by_var = 128 * 64;
bb_var.SimpleBrick_BOTTOM_var = 128 * 64 + 8 * 64;
bb_var.SimpleBrick_BRICK_HEIGHT_var = 9;
bb_var.SimpleBrick_padx_var = 128 * 64 / 2;
bb_var.SimpleBrick_XMAX_var = 160 * 64;
bb_var.SimpleBrick_score_var = 0;
bb_var.SimpleBrick_padlen_var = 160 * 64 / 6;
bb_var.SimpleBrick_prevPX_var =  -1;
bb_var.SimpleBrick_TOP_var = 14 * 64;
bb_var.SimpleBrick_prevBX_var =  -1;
bb_var.SimpleBrick_YDISPSIZE_var = 128;
bb_var.SimpleBrick_LEFT_var = 1 * 64;
bb_var.SimpleBrick_prevPY_var =  -1;
bb_var.SimpleBrick_bricks_var = array_bb_SimpleBrick_bricks_var;
bb_var.SimpleBrick_bricks_var_size = 5;
bb_var.SimpleBrick_fgcolor_var = array_bb_SimpleBrick_fgcolor_var;
bb_var.SimpleBrick_fgcolor_var_size = 3;
bb_var.SimpleBrick_bgcolor_var = array_bb_SimpleBrick_bgcolor_var;
bb_var.SimpleBrick_bgcolor_var_size = 3;

SimpleBrick_SC_OnEntry(SIMPLEBRICK_SC_STATE, &bb_var);
// Init the ID, state variables and properties for instance ctrl
ctrl_var.active = true;
ctrl_var.id_game = add_instance( (void*) &ctrl_var);
ctrl_var.id_controls = add_instance( (void*) &ctrl_var);
ctrl_var.BasicIAController_SC_State = BASICIACONTROLLER_SC_FOLLOWING_STATE;
ctrl_var.BasicIAController_ctrlx_var = 0;

BasicIAController_SC_OnEntry(BASICIACONTROLLER_SC_STATE, &ctrl_var);
}




void term(int signum)
{
    

    fflush(stdout);
    fflush(stderr);
    exit(signum);
}


int main(int argc, char *argv[]) {
    struct sigaction action;
    memset(&action, 0, sizeof(struct sigaction));
    action.sa_handler = term;
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGTERM, &action, NULL);

    init_runtime();
    
    initialize_configuration_SimpleBrickSDL2();

    while (1) {
        
// Network Listener// End Network Listener

int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
}

        processMessageQueue();
  }
}