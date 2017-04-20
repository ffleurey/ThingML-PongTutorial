/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application SDL2BounceCfg
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
#include "SDL2BounceApp.h"
#include "BouncingBall.h"

#include "Timer.h"




/*****************************************************************************
 * Definitions for configuration : SDL2BounceCfg
 *****************************************************************************/

//Declaration of instance variables
//Instance a
// Variables for the properties of the instance
struct SDL2BounceApp_Instance a_var;
// Variables for the sessions of the instance
//Instance b3
// Variables for the properties of the instance
struct BouncingBall_Instance b3_var;
// Variables for the sessions of the instance
//Instance b5
// Variables for the properties of the instance
struct BouncingBall_Instance b5_var;
// Variables for the sessions of the instance
//Instance b1
// Variables for the properties of the instance
struct BouncingBall_Instance b1_var;
// Variables for the sessions of the instance
//Instance b2
// Variables for the properties of the instance
struct BouncingBall_Instance b2_var;
// Variables for the sessions of the instance
//Instance b4
// Variables for the properties of the instance
struct BouncingBall_Instance b4_var;
// Variables for the sessions of the instance

//Instance Timer for network plugin PosixTimerPlugin
struct Timer_Instance Timer_instance;

// Enqueue of messages SDL2BounceApp::ball::bounce
void enqueue_SDL2BounceApp_send_ball_bounce(struct SDL2BounceApp_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_ball >> 8) & 0xFF );
_fifo_enqueue( _instance->id_ball & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SDL2BounceApp::ball::stop
void enqueue_SDL2BounceApp_send_ball_stop(struct SDL2BounceApp_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_ball >> 8) & 0xFF );
_fifo_enqueue( _instance->id_ball & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages BouncingBall::ball::updateBall
void enqueue_BouncingBall_send_ball_updateBall(struct BouncingBall_Instance *_instance, uint8_t oldx, uint8_t oldy, uint8_t newx, uint8_t newy){
fifo_lock();
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_ball >> 8) & 0xFF );
_fifo_enqueue( _instance->id_ball & 0xFF );

// parameter oldx
union u_oldx_t {
uint8_t p;
byte bytebuffer[1];
} u_oldx;
u_oldx.p = oldx;
_fifo_enqueue(u_oldx.bytebuffer[0] & 0xFF );

// parameter oldy
union u_oldy_t {
uint8_t p;
byte bytebuffer[1];
} u_oldy;
u_oldy.p = oldy;
_fifo_enqueue(u_oldy.bytebuffer[0] & 0xFF );

// parameter newx
union u_newx_t {
uint8_t p;
byte bytebuffer[1];
} u_newx;
u_newx.p = newx;
_fifo_enqueue(u_newx.bytebuffer[0] & 0xFF );

// parameter newy
union u_newy_t {
uint8_t p;
byte bytebuffer[1];
} u_newy;
u_newy.p = newy;
_fifo_enqueue(u_newy.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}


//New dispatcher for messages
void dispatch_updateBall(uint16_t sender, uint8_t param_oldx, uint8_t param_oldy, uint8_t param_newx, uint8_t param_newy) {
if (sender == b5_var.id_ball) {
SDL2BounceApp_handle_ball_updateBall(&a_var, param_oldx, param_oldy, param_newx, param_newy);

}
if (sender == b1_var.id_ball) {
SDL2BounceApp_handle_ball_updateBall(&a_var, param_oldx, param_oldy, param_newx, param_newy);

}
if (sender == b2_var.id_ball) {
SDL2BounceApp_handle_ball_updateBall(&a_var, param_oldx, param_oldy, param_newx, param_newy);

}
if (sender == b3_var.id_ball) {
SDL2BounceApp_handle_ball_updateBall(&a_var, param_oldx, param_oldy, param_newx, param_newy);

}
if (sender == b4_var.id_ball) {
SDL2BounceApp_handle_ball_updateBall(&a_var, param_oldx, param_oldy, param_newx, param_newy);

}

}


//New dispatcher for messages
void dispatch_bounce(uint16_t sender) {
if (sender == a_var.id_ball) {
BouncingBall_handle_ball_bounce(&b5_var);
BouncingBall_handle_ball_bounce(&b1_var);
BouncingBall_handle_ball_bounce(&b2_var);
BouncingBall_handle_ball_bounce(&b3_var);
BouncingBall_handle_ball_bounce(&b4_var);

}

}


//New dispatcher for messages
void dispatch_timer_timeout(uint16_t sender, uint8_t param_id) {
if (sender == Timer_instance.listener_id) {
BouncingBall_handle_clock_timer_timeout(&b4_var, param_id);

}
if (sender == Timer_instance.listener_id) {
BouncingBall_handle_clock_timer_timeout(&b5_var, param_id);

}
if (sender == Timer_instance.listener_id) {
BouncingBall_handle_clock_timer_timeout(&b1_var, param_id);

}
if (sender == Timer_instance.listener_id) {
BouncingBall_handle_clock_timer_timeout(&b2_var, param_id);

}
if (sender == Timer_instance.listener_id) {
BouncingBall_handle_clock_timer_timeout(&b3_var, param_id);

}
if (sender == Timer_instance.listener_id) {
SDL2BounceApp_handle_clock_timer_timeout(&a_var, param_id);

}

}


//New dispatcher for messages
void dispatch_stop(uint16_t sender) {
if (sender == a_var.id_ball) {
BouncingBall_handle_ball_stop(&b5_var);
BouncingBall_handle_ball_stop(&b1_var);
BouncingBall_handle_ball_stop(&b2_var);
BouncingBall_handle_ball_stop(&b3_var);
BouncingBall_handle_ball_stop(&b4_var);

}

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
case 4:{
byte mbuf[8 - 2];
while (mbufi < (8 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_updateBall = 2;
union u_updateBall_oldx_t {
uint8_t p;
byte bytebuffer[1];
} u_updateBall_oldx;
u_updateBall_oldx.bytebuffer[0] = mbuf[mbufi_updateBall + 0];
mbufi_updateBall += 1;
union u_updateBall_oldy_t {
uint8_t p;
byte bytebuffer[1];
} u_updateBall_oldy;
u_updateBall_oldy.bytebuffer[0] = mbuf[mbufi_updateBall + 0];
mbufi_updateBall += 1;
union u_updateBall_newx_t {
uint8_t p;
byte bytebuffer[1];
} u_updateBall_newx;
u_updateBall_newx.bytebuffer[0] = mbuf[mbufi_updateBall + 0];
mbufi_updateBall += 1;
union u_updateBall_newy_t {
uint8_t p;
byte bytebuffer[1];
} u_updateBall_newy;
u_updateBall_newy.bytebuffer[0] = mbuf[mbufi_updateBall + 0];
mbufi_updateBall += 1;
dispatch_updateBall((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_updateBall_oldx.p /* oldx */ ,
 u_updateBall_oldy.p /* oldy */ ,
 u_updateBall_newx.p /* newx */ ,
 u_updateBall_newy.p /* newy */ );
break;
}
case 2:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_bounce = 2;
dispatch_bounce((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 3:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_stop = 2;
dispatch_stop((mbuf[0] << 8) + mbuf[1] /* instance port*/);
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
}
return 1;
}

void forward_SDL2BounceApp_send_clock_timer_cancel(struct SDL2BounceApp_Instance *_instance, uint8_t id){
if(_instance->id_clock == a_var.id_clock) {
forward_Timer_SDL2BounceApp_send_clock_timer_cancel(_instance, id);
}
}
void forward_SDL2BounceApp_send_clock_timer_start(struct SDL2BounceApp_Instance *_instance, uint8_t id, uint32_t time){
if(_instance->id_clock == a_var.id_clock) {
forward_Timer_SDL2BounceApp_send_clock_timer_start(_instance, id, time);
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

void initialize_configuration_SDL2BounceCfg() {
// Initialize connectors
register_external_SDL2BounceApp_send_clock_timer_start_listener(&forward_SDL2BounceApp_send_clock_timer_start);
register_external_SDL2BounceApp_send_clock_timer_cancel_listener(&forward_SDL2BounceApp_send_clock_timer_cancel);
register_SDL2BounceApp_send_ball_bounce_listener(&enqueue_SDL2BounceApp_send_ball_bounce);
register_SDL2BounceApp_send_ball_stop_listener(&enqueue_SDL2BounceApp_send_ball_stop);
register_BouncingBall_send_ball_updateBall_listener(&enqueue_BouncingBall_send_ball_updateBall);

// Init the ID, state variables and properties for external connector Timer
// Init the ID, state variables and properties for external connector Timer
// Init the ID, state variables and properties for external connector Timer
// Init the ID, state variables and properties for external connector Timer
// Init the ID, state variables and properties for external connector Timer
// Init the ID, state variables and properties for external connector Timer

// Network Initialization
// Initialise Timer:
Timer_instance.listener_id = add_instance(&Timer_instance);
Timer_setup(&Timer_instance);

pthread_t thread_Timer;
pthread_create( &thread_Timer, NULL, Timer_loop, &Timer_instance);

// End Network Initialization

// Init the ID, state variables and properties for instance b1
b1_var.active = true;
b1_var.id_clock = add_instance( (void*) &b1_var);
b1_var.id_ball = add_instance( (void*) &b1_var);
b1_var.BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
b1_var.BouncingBall_MAX_var = 10000;
b1_var.BouncingBall_bx_var = 10000 / 2;
b1_var.BouncingBall_by_var = 10000 / 2;
b1_var.BouncingBall_dx_var =  -105;
b1_var.BouncingBall_dy_var = 190;
b1_var.Constants_XSIZE_var = 160;
b1_var.Constants_YSIZE_var = 128;
b1_var.BouncingBall_SC_BOUNCE_lastX_var = 200;
b1_var.BouncingBall_SC_BOUNCE_lastY_var = 200;

BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_STATE, &b1_var);
// Init the ID, state variables and properties for instance b3
b3_var.active = true;
b3_var.id_clock = add_instance( (void*) &b3_var);
b3_var.id_ball = add_instance( (void*) &b3_var);
b3_var.BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
b3_var.BouncingBall_MAX_var = 10000;
b3_var.BouncingBall_bx_var = 10000 / 2;
b3_var.BouncingBall_by_var = 10000 / 2;
b3_var.BouncingBall_dx_var =  -85;
b3_var.BouncingBall_dy_var =  -257;
b3_var.Constants_XSIZE_var = 160;
b3_var.Constants_YSIZE_var = 128;
b3_var.BouncingBall_SC_BOUNCE_lastX_var = 200;
b3_var.BouncingBall_SC_BOUNCE_lastY_var = 200;

BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_STATE, &b3_var);
// Init the ID, state variables and properties for instance b5
b5_var.active = true;
b5_var.id_clock = add_instance( (void*) &b5_var);
b5_var.id_ball = add_instance( (void*) &b5_var);
b5_var.BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
b5_var.BouncingBall_MAX_var = 10000;
b5_var.BouncingBall_bx_var = 10000 / 2;
b5_var.BouncingBall_by_var = 10000 / 2;
b5_var.BouncingBall_dx_var = 78;
b5_var.BouncingBall_dy_var = 135;
b5_var.Constants_XSIZE_var = 160;
b5_var.Constants_YSIZE_var = 128;
b5_var.BouncingBall_SC_BOUNCE_lastX_var = 200;
b5_var.BouncingBall_SC_BOUNCE_lastY_var = 200;

BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_STATE, &b5_var);
// Init the ID, state variables and properties for instance b2
b2_var.active = true;
b2_var.id_clock = add_instance( (void*) &b2_var);
b2_var.id_ball = add_instance( (void*) &b2_var);
b2_var.BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
b2_var.BouncingBall_MAX_var = 10000;
b2_var.BouncingBall_bx_var = 10000 / 2;
b2_var.BouncingBall_by_var = 10000 / 2;
b2_var.BouncingBall_dx_var = 155;
b2_var.BouncingBall_dy_var =  -138;
b2_var.Constants_XSIZE_var = 160;
b2_var.Constants_YSIZE_var = 128;
b2_var.BouncingBall_SC_BOUNCE_lastX_var = 200;
b2_var.BouncingBall_SC_BOUNCE_lastY_var = 200;

BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_STATE, &b2_var);
// Init the ID, state variables and properties for instance b4
b4_var.active = true;
b4_var.id_clock = add_instance( (void*) &b4_var);
b4_var.id_ball = add_instance( (void*) &b4_var);
b4_var.BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
b4_var.BouncingBall_MAX_var = 10000;
b4_var.BouncingBall_bx_var = 10000 / 2;
b4_var.BouncingBall_by_var = 10000 / 2;
b4_var.BouncingBall_dx_var = 192;
b4_var.BouncingBall_dy_var =  -62;
b4_var.Constants_XSIZE_var = 160;
b4_var.Constants_YSIZE_var = 128;
b4_var.BouncingBall_SC_BOUNCE_lastX_var = 200;
b4_var.BouncingBall_SC_BOUNCE_lastY_var = 200;

BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_STATE, &b4_var);
// Init the ID, state variables and properties for instance a
a_var.active = true;
a_var.id_clock = add_instance( (void*) &a_var);
a_var.id_ball = add_instance( (void*) &a_var);
a_var.BounceApp_SC_State = BOUNCEAPP_SC_WELCOME_STATE;
a_var.SDL2BounceApp_TTF_FONT_PATH_var = "/usr/share/fonts/truetype/freefont/FreeSansBold.ttf";
a_var.SDL2BounceApp_color_var = COLOR_WHITE;
a_var.SDL2BounceApp_scale_var = 5;
a_var.Constants_XSIZE_var = 160;
a_var.Constants_YSIZE_var = 128;

BounceApp_SC_OnEntry(BOUNCEAPP_SC_STATE, &a_var);
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
    
    initialize_configuration_SDL2BounceCfg();

    while (1) {
        
// Network Listener// End Network Listener

int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
}

        processMessageQueue();
  }
}