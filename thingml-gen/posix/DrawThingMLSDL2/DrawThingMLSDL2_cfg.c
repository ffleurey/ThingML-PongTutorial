/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application DrawThingMLSDL2
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
#include "DrawThingML.h"
#include "SDL2Display.h"





/*****************************************************************************
 * Definitions for configuration : DrawThingMLSDL2
 *****************************************************************************/

//Declaration of instance variables
//Instance bb
// Variables for the properties of the instance
struct DrawThingML_Instance bb_var;
// Variables for the sessions of the instance
//Instance disp
// Variables for the properties of the instance
struct SDL2Display_Instance disp_var;
// Variables for the sessions of the instance


// Enqueue of messages DrawThingML::display::clear
void enqueue_DrawThingML_send_display_clear(struct DrawThingML_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages DrawThingML::display::drawRect
void enqueue_DrawThingML_send_display_drawRect(struct DrawThingML_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
fifo_lock();
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

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
// Enqueue of messages DrawThingML::display::setColor
void enqueue_DrawThingML_send_display_setColor(struct DrawThingML_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
fifo_lock();
if ( fifo_byte_available() > 7 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

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
// Enqueue of messages DrawThingML::display::fillRect
void enqueue_DrawThingML_send_display_fillRect(struct DrawThingML_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
fifo_lock();
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

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
// Enqueue of messages DrawThingML::display::create
void enqueue_DrawThingML_send_display_create(struct DrawThingML_Instance *_instance, uint8_t xsize, uint8_t ysize){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

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
// Enqueue of messages DrawThingML::display::update
void enqueue_DrawThingML_send_display_update(struct DrawThingML_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

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

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

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

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );
}
fifo_unlock_and_notify();
}


//New dispatcher for messages
void dispatch_displayReady(uint16_t sender) {
if (sender == disp_var.id_display) {
DrawThingML_handle_display_displayReady(&bb_var);

}

}


//New dispatcher for messages
void dispatch_clear(uint16_t sender) {
if (sender == bb_var.id_display) {
SDL2Display_handle_display_clear(&disp_var);

}

}


//New dispatcher for messages
void dispatch_drawRect(uint16_t sender, uint8_t param_x, uint8_t param_y, uint8_t param_width, uint8_t param_height) {
if (sender == bb_var.id_display) {
SDL2Display_handle_display_drawRect(&disp_var, param_x, param_y, param_width, param_height);

}

}


//New dispatcher for messages
void dispatch_setColor(uint16_t sender, uint8_t param_r, uint8_t param_g, uint8_t param_b) {
if (sender == bb_var.id_display) {
SDL2Display_handle_display_setColor(&disp_var, param_r, param_g, param_b);

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
void dispatch_create(uint16_t sender, uint8_t param_xsize, uint8_t param_ysize) {
if (sender == bb_var.id_display) {
SDL2Display_handle_display_create(&disp_var, param_xsize, param_ysize);

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
case 7:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_displayReady = 2;
dispatch_displayReady((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 1:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_clear = 2;
dispatch_clear((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 2:{
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
case 3:{
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
case 8:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_displayError = 2;
dispatch_displayError((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 4:{
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
case 5:{
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
case 6:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
uint8_t mbufi_update = 2;
dispatch_update((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
}
return 1;
}


//external Message enqueue

void initialize_configuration_DrawThingMLSDL2() {
// Initialize connectors
register_DrawThingML_send_display_create_listener(&enqueue_DrawThingML_send_display_create);
register_DrawThingML_send_display_fillRect_listener(&enqueue_DrawThingML_send_display_fillRect);
register_DrawThingML_send_display_drawRect_listener(&enqueue_DrawThingML_send_display_drawRect);
register_DrawThingML_send_display_clear_listener(&enqueue_DrawThingML_send_display_clear);
register_DrawThingML_send_display_setColor_listener(&enqueue_DrawThingML_send_display_setColor);
register_DrawThingML_send_display_update_listener(&enqueue_DrawThingML_send_display_update);
register_SDL2Display_send_display_displayReady_listener(&enqueue_SDL2Display_send_display_displayReady);
register_SDL2Display_send_display_displayError_listener(&enqueue_SDL2Display_send_display_displayError);


// Network Initialization
// End Network Initialization

// Init the ID, state variables and properties for instance disp
disp_var.active = true;
disp_var.id_display = add_instance( (void*) &disp_var);
disp_var.id_controls = add_instance( (void*) &disp_var);
disp_var.Display_SC_State = DISPLAY_SC_WAIT_STATE;
disp_var.SDL2Display_xctrl_var = 0;
disp_var.SDL2Display_scale_var = 5;

Display_SC_OnEntry(DISPLAY_SC_STATE, &disp_var);
// Init the ID, state variables and properties for instance bb
bb_var.active = true;
bb_var.id_display = add_instance( (void*) &bb_var);
bb_var.DrawThingML_State = DRAWTHINGML_NULL_DRAW_STATE;
bb_var.DrawThingML_YDISPSIZE_var = 128;
bb_var.DrawThingML_XDISPSIZE_var = 160;

DrawThingML_OnEntry(DRAWTHINGML_STATE, &bb_var);
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
    
    initialize_configuration_DrawThingMLSDL2();

    while (1) {
        
// Network Listener// End Network Listener

int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
}

        processMessageQueue();
  }
}