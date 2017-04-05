/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing DrawThingML
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "DrawThingML.h"

/*****************************************************************************
 * Implementation for type : DrawThingML
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void DrawThingML_OnExit(int state, struct DrawThingML_Instance *_instance);
//Prototypes: Message Sending
void DrawThingML_send_display_create(struct DrawThingML_Instance *_instance, uint8_t xsize, uint8_t ysize);
void DrawThingML_send_display_fillRect(struct DrawThingML_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void DrawThingML_send_display_drawRect(struct DrawThingML_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void DrawThingML_send_display_clear(struct DrawThingML_Instance *_instance);
void DrawThingML_send_display_setColor(struct DrawThingML_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void DrawThingML_send_display_update(struct DrawThingML_Instance *_instance);
//Prototypes: Function
void f_DrawThingML_drawThingML(struct DrawThingML_Instance *_instance, int16_t x, int16_t y);
// Declaration of functions:
// Definition of function drawThingML
void f_DrawThingML_drawThingML(struct DrawThingML_Instance *_instance, int16_t x, int16_t y) {
DrawThingML_send_display_setColor(_instance, 255, 255, 255);
DrawThingML_send_display_fillRect(_instance, x, y, 108, 13);
x = x + 1;
y = y + 1;
DrawThingML_send_display_setColor(_instance, 80, 80, 80);
DrawThingML_send_display_fillRect(_instance, x + 0, y + 0, 12, 2);
DrawThingML_send_display_fillRect(_instance, x + 5, y + 0, 2, 11);
DrawThingML_send_display_fillRect(_instance, x + 18, y + 0, 2, 11);
DrawThingML_send_display_fillRect(_instance, x + 27, y + 0, 2, 11);
DrawThingML_send_display_fillRect(_instance, x + 18, y + 5, 11, 2);
DrawThingML_send_display_fillRect(_instance, x + 36, y + 0, 2, 11);
DrawThingML_send_display_fillRect(_instance, x + 44, y + 0, 2, 11);
DrawThingML_send_display_fillRect(_instance, x + 46, y + 1, 1, 3);
DrawThingML_send_display_fillRect(_instance, x + 47, y + 2, 1, 3);
DrawThingML_send_display_fillRect(_instance, x + 48, y + 3, 1, 3);
DrawThingML_send_display_fillRect(_instance, x + 49, y + 4, 1, 3);
DrawThingML_send_display_fillRect(_instance, x + 50, y + 5, 1, 3);
DrawThingML_send_display_fillRect(_instance, x + 51, y + 6, 1, 3);
DrawThingML_send_display_fillRect(_instance, x + 52, y + 7, 1, 3);
DrawThingML_send_display_fillRect(_instance, x + 53, y + 0, 2, 11);
DrawThingML_send_display_fillRect(_instance, x + 62, y + 0, 2, 11);
DrawThingML_send_display_fillRect(_instance, x + 62, y + 0, 12, 2);
DrawThingML_send_display_fillRect(_instance, x + 62, y + 9, 12, 2);
DrawThingML_send_display_fillRect(_instance, x + 62, y + 9, 12, 2);
DrawThingML_send_display_fillRect(_instance, x + 69, y + 5, 5, 2);
DrawThingML_send_display_fillRect(_instance, x + 72, y + 7, 2, 2);
DrawThingML_send_display_setColor(_instance, 232, 141, 10);
DrawThingML_send_display_fillRect(_instance, x + 80, y + 0, 11, 2);
DrawThingML_send_display_fillRect(_instance, x + 80, y + 0, 2, 11);
DrawThingML_send_display_fillRect(_instance, x + 85, y + 0, 2, 11);
DrawThingML_send_display_fillRect(_instance, x + 89, y + 0, 2, 11);
DrawThingML_send_display_fillRect(_instance, x + 95, y + 0, 2, 11);
DrawThingML_send_display_fillRect(_instance, x + 95, y + 9, 11, 2);
}

// Sessions functionss:


// On Entry Actions:
void DrawThingML_OnEntry(int state, struct DrawThingML_Instance *_instance) {
switch(state) {
case DRAWTHINGML_STATE:{
_instance->DrawThingML_State = DRAWTHINGML_NULL_DRAW_STATE;
DrawThingML_send_display_create(_instance, _instance->DrawThingML_XDISPSIZE_var, _instance->DrawThingML_YDISPSIZE_var);
DrawThingML_OnEntry(_instance->DrawThingML_State, _instance);
break;
}
case DRAWTHINGML_NULL_DRAW_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void DrawThingML_OnExit(int state, struct DrawThingML_Instance *_instance) {
switch(state) {
case DRAWTHINGML_STATE:{
DrawThingML_OnExit(_instance->DrawThingML_State, _instance);
break;}
case DRAWTHINGML_NULL_DRAW_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void DrawThingML_handle_display_displayReady(struct DrawThingML_Instance *_instance) {
if(!(_instance->active)) return;
//Region null
uint8_t DrawThingML_State_event_consumed = 0;
if (_instance->DrawThingML_State == DRAWTHINGML_NULL_DRAW_STATE) {
if (DrawThingML_State_event_consumed == 0 && 1) {
DrawThingML_send_display_clear(_instance);
f_DrawThingML_drawThingML(_instance, 20, 60);
DrawThingML_send_display_update(_instance);
DrawThingML_State_event_consumed = 1;
}
}
//End Region null
//End dsregion null
//Session list: 
}

// Observers for outgoing messages:
void (*external_DrawThingML_send_display_create_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t)= 0x0;
void (*DrawThingML_send_display_create_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_DrawThingML_send_display_create_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t)){
external_DrawThingML_send_display_create_listener = _listener;
}
void register_DrawThingML_send_display_create_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t)){
DrawThingML_send_display_create_listener = _listener;
}
void DrawThingML_send_display_create(struct DrawThingML_Instance *_instance, uint8_t xsize, uint8_t ysize){
if (DrawThingML_send_display_create_listener != 0x0) DrawThingML_send_display_create_listener(_instance, xsize, ysize);
if (external_DrawThingML_send_display_create_listener != 0x0) external_DrawThingML_send_display_create_listener(_instance, xsize, ysize);
;
}
void (*external_DrawThingML_send_display_fillRect_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*DrawThingML_send_display_fillRect_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_DrawThingML_send_display_fillRect_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_DrawThingML_send_display_fillRect_listener = _listener;
}
void register_DrawThingML_send_display_fillRect_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
DrawThingML_send_display_fillRect_listener = _listener;
}
void DrawThingML_send_display_fillRect(struct DrawThingML_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
if (DrawThingML_send_display_fillRect_listener != 0x0) DrawThingML_send_display_fillRect_listener(_instance, x, y, width, height);
if (external_DrawThingML_send_display_fillRect_listener != 0x0) external_DrawThingML_send_display_fillRect_listener(_instance, x, y, width, height);
;
}
void (*external_DrawThingML_send_display_drawRect_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*DrawThingML_send_display_drawRect_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_DrawThingML_send_display_drawRect_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_DrawThingML_send_display_drawRect_listener = _listener;
}
void register_DrawThingML_send_display_drawRect_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
DrawThingML_send_display_drawRect_listener = _listener;
}
void DrawThingML_send_display_drawRect(struct DrawThingML_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
if (DrawThingML_send_display_drawRect_listener != 0x0) DrawThingML_send_display_drawRect_listener(_instance, x, y, width, height);
if (external_DrawThingML_send_display_drawRect_listener != 0x0) external_DrawThingML_send_display_drawRect_listener(_instance, x, y, width, height);
;
}
void (*external_DrawThingML_send_display_clear_listener)(struct DrawThingML_Instance *)= 0x0;
void (*DrawThingML_send_display_clear_listener)(struct DrawThingML_Instance *)= 0x0;
void register_external_DrawThingML_send_display_clear_listener(void (*_listener)(struct DrawThingML_Instance *)){
external_DrawThingML_send_display_clear_listener = _listener;
}
void register_DrawThingML_send_display_clear_listener(void (*_listener)(struct DrawThingML_Instance *)){
DrawThingML_send_display_clear_listener = _listener;
}
void DrawThingML_send_display_clear(struct DrawThingML_Instance *_instance){
if (DrawThingML_send_display_clear_listener != 0x0) DrawThingML_send_display_clear_listener(_instance);
if (external_DrawThingML_send_display_clear_listener != 0x0) external_DrawThingML_send_display_clear_listener(_instance);
;
}
void (*external_DrawThingML_send_display_setColor_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*DrawThingML_send_display_setColor_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_DrawThingML_send_display_setColor_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t)){
external_DrawThingML_send_display_setColor_listener = _listener;
}
void register_DrawThingML_send_display_setColor_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t)){
DrawThingML_send_display_setColor_listener = _listener;
}
void DrawThingML_send_display_setColor(struct DrawThingML_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
if (DrawThingML_send_display_setColor_listener != 0x0) DrawThingML_send_display_setColor_listener(_instance, r, g, b);
if (external_DrawThingML_send_display_setColor_listener != 0x0) external_DrawThingML_send_display_setColor_listener(_instance, r, g, b);
;
}
void (*external_DrawThingML_send_display_update_listener)(struct DrawThingML_Instance *)= 0x0;
void (*DrawThingML_send_display_update_listener)(struct DrawThingML_Instance *)= 0x0;
void register_external_DrawThingML_send_display_update_listener(void (*_listener)(struct DrawThingML_Instance *)){
external_DrawThingML_send_display_update_listener = _listener;
}
void register_DrawThingML_send_display_update_listener(void (*_listener)(struct DrawThingML_Instance *)){
DrawThingML_send_display_update_listener = _listener;
}
void DrawThingML_send_display_update(struct DrawThingML_Instance *_instance){
if (DrawThingML_send_display_update_listener != 0x0) DrawThingML_send_display_update_listener(_instance);
if (external_DrawThingML_send_display_update_listener != 0x0) external_DrawThingML_send_display_update_listener(_instance);
;
}



