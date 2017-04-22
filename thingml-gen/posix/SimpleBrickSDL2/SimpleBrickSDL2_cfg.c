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
#include "SDL2Display.h"
#include "SimpleBrick.h"

#include "Timer.h"




/*****************************************************************************
 * Definitions for configuration : SimpleBrickSDL2
 *****************************************************************************/

uint8_t array_bb_SimpleBrick_bricks_var[5];
//Declaration of instance variables
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

// Enqueue of messages SDL2Display::display::displayError
void enqueue_SDL2Display_send_display_displayError(struct SDL2Display_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );
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
// Enqueue of messages SDL2Display::controls::position
void enqueue_SDL2Display_send_controls_position(struct SDL2Display_Instance *_instance, int16_t x, int16_t y){
fifo_lock();
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

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
// Enqueue of messages SimpleBrick::display::setColor
void enqueue_SimpleBrick_send_display_setColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );

// parameter r
union u_r_t {
uint8_t p;
byte bytebuffer[1];
} u_r;
u_r.p = r;
_fifo_enqueue(u_r.bytebuffer[0] & 0xFF );

// parameter g
union u_g_t {
uint8_t p;
byte bytebuffer[1];
} u_g;
u_g.p = g;
_fifo_enqueue(u_g.bytebuffer[0] & 0xFF );

// parameter b
union u_b_t {
uint8_t p;
byte bytebuffer[1];
} u_b;
u_b.p = b;
_fifo_enqueue(u_b.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SimpleBrick::display::drawInteger
void enqueue_SimpleBrick_send_display_drawInteger(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale){
fifo_lock();
if ( fifo_byte_available() > 10 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );

// parameter x
union u_x_t {
uint8_t p;
byte bytebuffer[1];
} u_x;
u_x.p = x;
_fifo_enqueue(u_x.bytebuffer[0] & 0xFF );

// parameter y
union u_y_t {
uint8_t p;
byte bytebuffer[1];
} u_y;
u_y.p = y;
_fifo_enqueue(u_y.bytebuffer[0] & 0xFF );

// parameter v
union u_v_t {
int16_t p;
byte bytebuffer[2];
} u_v;
u_v.p = v;
_fifo_enqueue(u_v.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_v.bytebuffer[0] & 0xFF );

// parameter digits
union u_digits_t {
uint8_t p;
byte bytebuffer[1];
} u_digits;
u_digits.p = digits;
_fifo_enqueue(u_digits.bytebuffer[0] & 0xFF );

// parameter scale
union u_scale_t {
uint8_t p;
byte bytebuffer[1];
} u_scale;
u_scale.p = scale;
_fifo_enqueue(u_scale.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SimpleBrick::display::clear
void enqueue_SimpleBrick_send_display_clear(struct SimpleBrick_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SimpleBrick::display::setBGColor
void enqueue_SimpleBrick_send_display_setBGColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );

// parameter r
union u_r_t {
uint8_t p;
byte bytebuffer[1];
} u_r;
u_r.p = r;
_fifo_enqueue(u_r.bytebuffer[0] & 0xFF );

// parameter g
union u_g_t {
uint8_t p;
byte bytebuffer[1];
} u_g;
u_g.p = g;
_fifo_enqueue(u_g.bytebuffer[0] & 0xFF );

// parameter b
union u_b_t {
uint8_t p;
byte bytebuffer[1];
} u_b;
u_b.p = b;
_fifo_enqueue(u_b.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SimpleBrick::display::fillRect
void enqueue_SimpleBrick_send_display_fillRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
fifo_lock();
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (9 >> 8) & 0xFF );
_fifo_enqueue( 9 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );

// parameter x
union u_x_t {
uint8_t p;
byte bytebuffer[1];
} u_x;
u_x.p = x;
_fifo_enqueue(u_x.bytebuffer[0] & 0xFF );

// parameter y
union u_y_t {
uint8_t p;
byte bytebuffer[1];
} u_y;
u_y.p = y;
_fifo_enqueue(u_y.bytebuffer[0] & 0xFF );

// parameter width
union u_width_t {
uint8_t p;
byte bytebuffer[1];
} u_width;
u_width.p = width;
_fifo_enqueue(u_width.bytebuffer[0] & 0xFF );

// parameter height
union u_height_t {
uint8_t p;
byte bytebuffer[1];
} u_height;
u_height.p = height;
_fifo_enqueue(u_height.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SimpleBrick::display::create
void enqueue_SimpleBrick_send_display_create(struct SimpleBrick_Instance *_instance, uint8_t xsize, uint8_t ysize){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (10 >> 8) & 0xFF );
_fifo_enqueue( 10 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );

// parameter xsize
union u_xsize_t {
uint8_t p;
byte bytebuffer[1];
} u_xsize;
u_xsize.p = xsize;
_fifo_enqueue(u_xsize.bytebuffer[0] & 0xFF );

// parameter ysize
union u_ysize_t {
uint8_t p;
byte bytebuffer[1];
} u_ysize;
u_ysize.p = ysize;
_fifo_enqueue(u_ysize.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SimpleBrick::display::drawRect
void enqueue_SimpleBrick_send_display_drawRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
fifo_lock();
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (11 >> 8) & 0xFF );
_fifo_enqueue( 11 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );

// parameter x
union u_x_t {
uint8_t p;
byte bytebuffer[1];
} u_x;
u_x.p = x;
_fifo_enqueue(u_x.bytebuffer[0] & 0xFF );

// parameter y
union u_y_t {
uint8_t p;
byte bytebuffer[1];
} u_y;
u_y.p = y;
_fifo_enqueue(u_y.bytebuffer[0] & 0xFF );

// parameter width
union u_width_t {
uint8_t p;
byte bytebuffer[1];
} u_width;
u_width.p = width;
_fifo_enqueue(u_width.bytebuffer[0] & 0xFF );

// parameter height
union u_height_t {
uint8_t p;
byte bytebuffer[1];
} u_height;
u_height.p = height;
_fifo_enqueue(u_height.bytebuffer[0] & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SimpleBrick::display::update
void enqueue_SimpleBrick_send_display_update(struct SimpleBrick_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (12 >> 8) & 0xFF );
_fifo_enqueue( 12 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );
}
fifo_unlock_and_notify();
}


//New dispatcher for messages
void dispatch_fire(uint16_t sender, uint8_t param_id) {
if (sender == disp_var.id_controls) {

}

}


//New dispatcher for messages
void dispatch_setBGColor(uint16_t sender, uint8_t param_r, uint8_t param_g, uint8_t param_b) {
if (sender == bb_var.id_display) {
SDL2Display_handle_display_setBGColor(&disp_var, param_r, param_g, param_b);

}

}


//New dispatcher for messages
void dispatch_displayReady(uint16_t sender) {
if (sender == disp_var.id_display) {
SimpleBrick_handle_display_displayReady(&bb_var);

}

}


//New dispatcher for messages
void dispatch_timer_timeout(uint16_t sender, uint8_t param_id) {
if (sender == Timer_instance.listener_id) {
SimpleBrick_handle_clock_timer_timeout(&bb_var, param_id);

}

}


//New dispatcher for messages
void dispatch_create(uint16_t sender, uint8_t param_xsize, uint8_t param_ysize) {
if (sender == bb_var.id_display) {
SDL2Display_handle_display_create(&disp_var, param_xsize, param_ysize);

}

}


//New dispatcher for messages
void dispatch_position(uint16_t sender, int16_t param_x, int16_t param_y) {
if (sender == disp_var.id_controls) {
SimpleBrick_handle_controller_position(&bb_var, param_x, param_y);

}

}


//New dispatcher for messages
void dispatch_setColor(uint16_t sender, uint8_t param_r, uint8_t param_g, uint8_t param_b) {
if (sender == bb_var.id_display) {
SDL2Display_handle_display_setColor(&disp_var, param_r, param_g, param_b);

}

}


//New dispatcher for messages
void dispatch_drawInteger(uint16_t sender, uint8_t param_x, uint8_t param_y, int16_t param_v, uint8_t param_digits, uint8_t param_scale) {
if (sender == bb_var.id_display) {
SDL2Display_handle_display_drawInteger(&disp_var, param_x, param_y, param_v, param_digits, param_scale);

}

}


//New dispatcher for messages
void dispatch_clear(uint16_t sender) {
if (sender == bb_var.id_display) {
SDL2Display_handle_display_clear(&disp_var);

}

}


//New dispatcher for messages
void dispatch_displayError(uint16_t sender) {
if (sender == disp_var.id_display) {

}

}


//New dispatcher for messages
void dispatch_fillRect(uint16_t sender, uint8_t param_x, uint8_t param_y, uint8_t param_width, uint8_t param_height) {
if (sender == bb_var.id_display) {
SDL2Display_handle_display_fillRect(&disp_var, param_x, param_y, param_width, param_height);

}

}


//New dispatcher for messages
void dispatch_drawRect(uint16_t sender, uint8_t param_x, uint8_t param_y, uint8_t param_width, uint8_t param_height) {
if (sender == bb_var.id_display) {
SDL2Display_handle_display_drawRect(&disp_var, param_x, param_y, param_width, param_height);

}

}


//New dispatcher for messages
void dispatch_update(uint16_t sender) {
if (sender == bb_var.id_display) {
SDL2Display_handle_display_update(&disp_var);

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
case 5:{
byte mbuf[7 - 2];
while (mbufi < (7 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_setColor = 2;
union u_setColor_r_t {
uint8_t p;
byte bytebuffer[1];
} u_setColor_r;
u_setColor_r.bytebuffer[0] = mbuf[mbufi_setColor + 0];
mbufi_setColor += 1;
union u_setColor_g_t {
uint8_t p;
byte bytebuffer[1];
} u_setColor_g;
u_setColor_g.bytebuffer[0] = mbuf[mbufi_setColor + 0];
mbufi_setColor += 1;
union u_setColor_b_t {
uint8_t p;
byte bytebuffer[1];
} u_setColor_b;
u_setColor_b.bytebuffer[0] = mbuf[mbufi_setColor + 0];
mbufi_setColor += 1;
dispatch_setColor((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_setColor_r.p /* r */ ,
 u_setColor_g.p /* g */ ,
 u_setColor_b.p /* b */ );
break;
}
case 6:{
byte mbuf[10 - 2];
while (mbufi < (10 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_drawInteger = 2;
union u_drawInteger_x_t {
uint8_t p;
byte bytebuffer[1];
} u_drawInteger_x;
u_drawInteger_x.bytebuffer[0] = mbuf[mbufi_drawInteger + 0];
mbufi_drawInteger += 1;
union u_drawInteger_y_t {
uint8_t p;
byte bytebuffer[1];
} u_drawInteger_y;
u_drawInteger_y.bytebuffer[0] = mbuf[mbufi_drawInteger + 0];
mbufi_drawInteger += 1;
union u_drawInteger_v_t {
int16_t p;
byte bytebuffer[2];
} u_drawInteger_v;
u_drawInteger_v.bytebuffer[1] = mbuf[mbufi_drawInteger + 0];
u_drawInteger_v.bytebuffer[0] = mbuf[mbufi_drawInteger + 1];
mbufi_drawInteger += 2;
union u_drawInteger_digits_t {
uint8_t p;
byte bytebuffer[1];
} u_drawInteger_digits;
u_drawInteger_digits.bytebuffer[0] = mbuf[mbufi_drawInteger + 0];
mbufi_drawInteger += 1;
union u_drawInteger_scale_t {
uint8_t p;
byte bytebuffer[1];
} u_drawInteger_scale;
u_drawInteger_scale.bytebuffer[0] = mbuf[mbufi_drawInteger + 0];
mbufi_drawInteger += 1;
dispatch_drawInteger((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_drawInteger_x.p /* x */ ,
 u_drawInteger_y.p /* y */ ,
 u_drawInteger_v.p /* v */ ,
 u_drawInteger_digits.p /* digits */ ,
 u_drawInteger_scale.p /* scale */ );
break;
}
case 7:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_clear = 2;
dispatch_clear((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 2:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_displayError = 2;
dispatch_displayError((mbuf[0] << 8) + mbuf[1] /* instance port*/);
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
case 8:{
byte mbuf[7 - 2];
while (mbufi < (7 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_setBGColor = 2;
union u_setBGColor_r_t {
uint8_t p;
byte bytebuffer[1];
} u_setBGColor_r;
u_setBGColor_r.bytebuffer[0] = mbuf[mbufi_setBGColor + 0];
mbufi_setBGColor += 1;
union u_setBGColor_g_t {
uint8_t p;
byte bytebuffer[1];
} u_setBGColor_g;
u_setBGColor_g.bytebuffer[0] = mbuf[mbufi_setBGColor + 0];
mbufi_setBGColor += 1;
union u_setBGColor_b_t {
uint8_t p;
byte bytebuffer[1];
} u_setBGColor_b;
u_setBGColor_b.bytebuffer[0] = mbuf[mbufi_setBGColor + 0];
mbufi_setBGColor += 1;
dispatch_setBGColor((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_setBGColor_r.p /* r */ ,
 u_setBGColor_g.p /* g */ ,
 u_setBGColor_b.p /* b */ );
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
case 9:{
byte mbuf[8 - 2];
while (mbufi < (8 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_fillRect = 2;
union u_fillRect_x_t {
uint8_t p;
byte bytebuffer[1];
} u_fillRect_x;
u_fillRect_x.bytebuffer[0] = mbuf[mbufi_fillRect + 0];
mbufi_fillRect += 1;
union u_fillRect_y_t {
uint8_t p;
byte bytebuffer[1];
} u_fillRect_y;
u_fillRect_y.bytebuffer[0] = mbuf[mbufi_fillRect + 0];
mbufi_fillRect += 1;
union u_fillRect_width_t {
uint8_t p;
byte bytebuffer[1];
} u_fillRect_width;
u_fillRect_width.bytebuffer[0] = mbuf[mbufi_fillRect + 0];
mbufi_fillRect += 1;
union u_fillRect_height_t {
uint8_t p;
byte bytebuffer[1];
} u_fillRect_height;
u_fillRect_height.bytebuffer[0] = mbuf[mbufi_fillRect + 0];
mbufi_fillRect += 1;
dispatch_fillRect((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_fillRect_x.p /* x */ ,
 u_fillRect_y.p /* y */ ,
 u_fillRect_width.p /* width */ ,
 u_fillRect_height.p /* height */ );
break;
}
case 10:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_create = 2;
union u_create_xsize_t {
uint8_t p;
byte bytebuffer[1];
} u_create_xsize;
u_create_xsize.bytebuffer[0] = mbuf[mbufi_create + 0];
mbufi_create += 1;
union u_create_ysize_t {
uint8_t p;
byte bytebuffer[1];
} u_create_ysize;
u_create_ysize.bytebuffer[0] = mbuf[mbufi_create + 0];
mbufi_create += 1;
dispatch_create((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_create_xsize.p /* xsize */ ,
 u_create_ysize.p /* ysize */ );
break;
}
case 11:{
byte mbuf[8 - 2];
while (mbufi < (8 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_drawRect = 2;
union u_drawRect_x_t {
uint8_t p;
byte bytebuffer[1];
} u_drawRect_x;
u_drawRect_x.bytebuffer[0] = mbuf[mbufi_drawRect + 0];
mbufi_drawRect += 1;
union u_drawRect_y_t {
uint8_t p;
byte bytebuffer[1];
} u_drawRect_y;
u_drawRect_y.bytebuffer[0] = mbuf[mbufi_drawRect + 0];
mbufi_drawRect += 1;
union u_drawRect_width_t {
uint8_t p;
byte bytebuffer[1];
} u_drawRect_width;
u_drawRect_width.bytebuffer[0] = mbuf[mbufi_drawRect + 0];
mbufi_drawRect += 1;
union u_drawRect_height_t {
uint8_t p;
byte bytebuffer[1];
} u_drawRect_height;
u_drawRect_height.bytebuffer[0] = mbuf[mbufi_drawRect + 0];
mbufi_drawRect += 1;
dispatch_drawRect((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_drawRect_x.p /* x */ ,
 u_drawRect_y.p /* y */ ,
 u_drawRect_width.p /* width */ ,
 u_drawRect_height.p /* height */ );
break;
}
case 12:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_update = 2;
dispatch_update((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 4:{
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
register_SDL2Display_send_display_displayReady_listener(&enqueue_SDL2Display_send_display_displayReady);
register_SDL2Display_send_display_displayError_listener(&enqueue_SDL2Display_send_display_displayError);
register_SDL2Display_send_controls_position_listener(&enqueue_SDL2Display_send_controls_position);
register_SimpleBrick_send_display_create_listener(&enqueue_SimpleBrick_send_display_create);
register_SimpleBrick_send_display_fillRect_listener(&enqueue_SimpleBrick_send_display_fillRect);
register_SimpleBrick_send_display_drawRect_listener(&enqueue_SimpleBrick_send_display_drawRect);
register_SimpleBrick_send_display_clear_listener(&enqueue_SimpleBrick_send_display_clear);
register_SimpleBrick_send_display_setColor_listener(&enqueue_SimpleBrick_send_display_setColor);
register_SimpleBrick_send_display_setBGColor_listener(&enqueue_SimpleBrick_send_display_setBGColor);
register_SimpleBrick_send_display_drawInteger_listener(&enqueue_SimpleBrick_send_display_drawInteger);
register_SimpleBrick_send_display_update_listener(&enqueue_SimpleBrick_send_display_update);

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
disp_var.Display_fg_b_var = 0;
disp_var.Display_bg_b_var = 0;
disp_var.Display_bg_r_var = 0;
disp_var.Display_bg_g_var = 0;
disp_var.Display_fg_g_var = 0;
disp_var.SDL2Display_xctrl_var = 0;
disp_var.Display_fg_r_var = 0;

Display_SC_OnEntry(DISPLAY_SC_STATE, &disp_var);
// Init the ID, state variables and properties for instance bb
bb_var.active = true;
bb_var.id_clock = add_instance( (void*) &bb_var);
bb_var.id_display = add_instance( (void*) &bb_var);
bb_var.id_controller = add_instance( (void*) &bb_var);
bb_var.SimpleBrick_SC_State = SIMPLEBRICK_SC_INIT_STATE;
bb_var.SimpleBrick_prevPY_var =  -1;
bb_var.SimpleBrick_BRICK_ROWS_var = 5;
bb_var.SimpleBrick_LEFT_var = 2 * 64;
bb_var.SimpleBrick_dx_var = 160 * 64 / 98;
bb_var.SimpleBrick_XDISPSIZE_var = 160;
bb_var.SimpleBrick_TOP_var = 13 * 64;
bb_var.SimpleBrick_padx_var = 128 * 64 / 2;
bb_var.SimpleBrick_by_var = 128 * 64 / 2;
bb_var.SimpleBrick_SCALE_var = 64;
bb_var.SimpleBrick_bx_var = 160 * 64 / 2;
bb_var.SimpleBrick_YMAX_var = 128 * 64;
bb_var.SimpleBrick_BOTTOM_var = 128 * 64 + 8 * 64;
bb_var.SimpleBrick_RIGHT_var = 160 * 64 - 2 * 64;
bb_var.SimpleBrick_SC_score_var = 0;
bb_var.SimpleBrick_YDISPSIZE_var = 128;
bb_var.SimpleBrick_XMAX_var = 160 * 64;
bb_var.SimpleBrick_pady_var = 128 * 64 - 6 * 64;
bb_var.SimpleBrick_prevBY_var =  -1;
bb_var.SimpleBrick_BRICK_HEIGHT_var = 9;
bb_var.SimpleBrick_prevPX_var =  -1;
bb_var.SimpleBrick_prevBX_var =  -1;
bb_var.SimpleBrick_padlen_var = 160 * 64 / 6;
bb_var.SimpleBrick_br_var = 3 * 64;
bb_var.SimpleBrick_dy_var = 160 * 64 / 65;
bb_var.SimpleBrick_bricks_var = array_bb_SimpleBrick_bricks_var;
bb_var.SimpleBrick_bricks_var_size = 5;

SimpleBrick_SC_OnEntry(SIMPLEBRICK_SC_STATE, &bb_var);
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