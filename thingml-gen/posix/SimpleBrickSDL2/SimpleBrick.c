/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing SimpleBrick
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "SimpleBrick.h"

/*****************************************************************************
 * Implementation for type : SimpleBrick
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void SimpleBrick_SC_OnExit(int state, struct SimpleBrick_Instance *_instance);
//Prototypes: Message Sending
void SimpleBrick_send_clock_timer_start(struct SimpleBrick_Instance *_instance, uint8_t id, uint32_t time);
void SimpleBrick_send_clock_timer_cancel(struct SimpleBrick_Instance *_instance, uint8_t id);
void SimpleBrick_send_display_create(struct SimpleBrick_Instance *_instance, uint8_t xsize, uint8_t ysize);
void SimpleBrick_send_display_fillRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void SimpleBrick_send_display_drawRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void SimpleBrick_send_display_clear(struct SimpleBrick_Instance *_instance);
void SimpleBrick_send_display_setColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void SimpleBrick_send_display_setBGColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void SimpleBrick_send_display_drawInteger(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void SimpleBrick_send_display_update(struct SimpleBrick_Instance *_instance);
//Prototypes: Function
void f_SimpleBrick_initColors(struct SimpleBrick_Instance *_instance);
void f_SimpleBrick_drawBall(struct SimpleBrick_Instance *_instance);
void f_SimpleBrick_drawPad(struct SimpleBrick_Instance *_instance);
void f_SimpleBrick_drawWalls(struct SimpleBrick_Instance *_instance);
uint8_t f_SimpleBrick_bitIsSet(struct SimpleBrick_Instance *_instance, uint8_t variable, uint8_t bit);
uint8_t f_SimpleBrick_setBit(struct SimpleBrick_Instance *_instance, uint8_t variable, uint8_t bit);
uint8_t f_SimpleBrick_unsetBit(struct SimpleBrick_Instance *_instance, uint8_t variable, uint8_t bit);
void f_SimpleBrick_createBricks(struct SimpleBrick_Instance *_instance);
void f_SimpleBrick_drawBrick(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y);
void f_SimpleBrick_removeBrick(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y);
uint8_t f_SimpleBrick_collideBrick(struct SimpleBrick_Instance *_instance, int16_t xpos, int16_t ypos);
void f_SimpleBrick_drawScore(struct SimpleBrick_Instance *_instance);
void f_SimpleBrick_drawLives(struct SimpleBrick_Instance *_instance);
// Declaration of functions:
// Definition of function initColors
void f_SimpleBrick_initColors(struct SimpleBrick_Instance *_instance) {
_instance->SimpleBrick_bgcolor_var[0] = 53;
_instance->SimpleBrick_bgcolor_var[1] = 40;
_instance->SimpleBrick_bgcolor_var[2] = 120;
_instance->SimpleBrick_fgcolor_var[0] = 107;
_instance->SimpleBrick_fgcolor_var[1] = 94;
_instance->SimpleBrick_fgcolor_var[2] = 174;
SimpleBrick_send_display_setBGColor(_instance, _instance->SimpleBrick_bgcolor_var[0]
, _instance->SimpleBrick_bgcolor_var[1]
, _instance->SimpleBrick_bgcolor_var[2]
);
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_fgcolor_var[0]
, _instance->SimpleBrick_fgcolor_var[1]
, _instance->SimpleBrick_fgcolor_var[2]
);
}
// Definition of function drawBall
void f_SimpleBrick_drawBall(struct SimpleBrick_Instance *_instance) {
;uint8_t bs = (_instance->SimpleBrick_br_var * 2) / _instance->SimpleBrick_SCALE_var;
if(_instance->SimpleBrick_prevBX_var > 0) {
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_bgcolor_var[0]
, _instance->SimpleBrick_bgcolor_var[1]
, _instance->SimpleBrick_bgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_prevBX_var, _instance->SimpleBrick_prevBY_var, bs, bs);

}
_instance->SimpleBrick_prevBX_var = (_instance->SimpleBrick_bx_var - _instance->SimpleBrick_br_var) / _instance->SimpleBrick_SCALE_var;
_instance->SimpleBrick_prevBY_var = (_instance->SimpleBrick_by_var - _instance->SimpleBrick_br_var) / _instance->SimpleBrick_SCALE_var;
SimpleBrick_send_display_setColor(_instance, 183, 199, 111);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_prevBX_var, _instance->SimpleBrick_prevBY_var, bs, bs);
}
// Definition of function drawPad
void f_SimpleBrick_drawPad(struct SimpleBrick_Instance *_instance) {
;uint8_t ps = _instance->SimpleBrick_padlen_var / _instance->SimpleBrick_SCALE_var;
if(_instance->SimpleBrick_prevPX_var > 0) {
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_bgcolor_var[0]
, _instance->SimpleBrick_bgcolor_var[1]
, _instance->SimpleBrick_bgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_prevPX_var, _instance->SimpleBrick_prevPY_var, ps, 4);

}
_instance->SimpleBrick_prevPX_var = (_instance->SimpleBrick_padx_var - (_instance->SimpleBrick_padlen_var / 2)) / _instance->SimpleBrick_SCALE_var;
_instance->SimpleBrick_prevPY_var = _instance->SimpleBrick_pady_var / _instance->SimpleBrick_SCALE_var;
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_fgcolor_var[0]
, _instance->SimpleBrick_fgcolor_var[1]
, _instance->SimpleBrick_fgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_prevPX_var, _instance->SimpleBrick_prevPY_var, ps, 4);
}
// Definition of function drawWalls
void f_SimpleBrick_drawWalls(struct SimpleBrick_Instance *_instance) {
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_fgcolor_var[0]
, _instance->SimpleBrick_fgcolor_var[1]
, _instance->SimpleBrick_fgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_LEFT_var / _instance->SimpleBrick_SCALE_var - 1, _instance->SimpleBrick_TOP_var / _instance->SimpleBrick_SCALE_var - 1, (_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / _instance->SimpleBrick_SCALE_var + 1, 1);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_LEFT_var / _instance->SimpleBrick_SCALE_var - 1, _instance->SimpleBrick_BOTTOM_var / _instance->SimpleBrick_SCALE_var - 1, (_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / _instance->SimpleBrick_SCALE_var + 1, 1);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_LEFT_var / _instance->SimpleBrick_SCALE_var - 1, _instance->SimpleBrick_TOP_var / _instance->SimpleBrick_SCALE_var, 1, (_instance->SimpleBrick_BOTTOM_var - _instance->SimpleBrick_TOP_var) / _instance->SimpleBrick_SCALE_var);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_RIGHT_var / _instance->SimpleBrick_SCALE_var - 1, _instance->SimpleBrick_TOP_var / _instance->SimpleBrick_SCALE_var, 1, (_instance->SimpleBrick_BOTTOM_var - _instance->SimpleBrick_TOP_var) / _instance->SimpleBrick_SCALE_var);
}
// Definition of function bitIsSet
uint8_t f_SimpleBrick_bitIsSet(struct SimpleBrick_Instance *_instance, uint8_t variable, uint8_t bit) {
return ((1 << bit) & variable) != 0;
}
// Definition of function setBit
uint8_t f_SimpleBrick_setBit(struct SimpleBrick_Instance *_instance, uint8_t variable, uint8_t bit) {
return variable | (1 << bit);
}
// Definition of function unsetBit
uint8_t f_SimpleBrick_unsetBit(struct SimpleBrick_Instance *_instance, uint8_t variable, uint8_t bit) {
return variable & ~(1 << bit);
}
// Definition of function createBricks
void f_SimpleBrick_createBricks(struct SimpleBrick_Instance *_instance) {
;int8_t y = 0;
while(y < _instance->SimpleBrick_BRICK_ROWS_var) {
_instance->SimpleBrick_bricks_var[y] = 0xFF;
;int8_t x = 0;
while(x < 8) {
if(f_SimpleBrick_bitIsSet(_instance, _instance->SimpleBrick_bricks_var[y]
, x)) {
f_SimpleBrick_drawBrick(_instance, x, y);

}
x = x + 1;

}
y = y + 1;

}
}
// Definition of function drawBrick
void f_SimpleBrick_drawBrick(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y) {
;int16_t bx = _instance->SimpleBrick_LEFT_var + ((_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 8) * x;
;int16_t by = _instance->SimpleBrick_TOP_var + 20 * _instance->SimpleBrick_SCALE_var + _instance->SimpleBrick_BRICK_HEIGHT_var * y * _instance->SimpleBrick_SCALE_var;
SimpleBrick_send_display_setColor(_instance, 155, 103, 89);
SimpleBrick_send_display_fillRect(_instance, bx / _instance->SimpleBrick_SCALE_var + 1, by / _instance->SimpleBrick_SCALE_var + 1, ((_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 8) / _instance->SimpleBrick_SCALE_var - 2, _instance->SimpleBrick_BRICK_HEIGHT_var - 2);
SimpleBrick_send_display_setColor(_instance, 100, 56, 43);
SimpleBrick_send_display_drawRect(_instance, bx / _instance->SimpleBrick_SCALE_var + 1, by / _instance->SimpleBrick_SCALE_var + 1, ((_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 8) / _instance->SimpleBrick_SCALE_var - 2, _instance->SimpleBrick_BRICK_HEIGHT_var - 2);
}
// Definition of function removeBrick
void f_SimpleBrick_removeBrick(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y) {
;int16_t bx = _instance->SimpleBrick_LEFT_var + ((_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 8) * x;
;int16_t by = _instance->SimpleBrick_TOP_var + 20 * _instance->SimpleBrick_SCALE_var + _instance->SimpleBrick_BRICK_HEIGHT_var * y * _instance->SimpleBrick_SCALE_var;
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_bgcolor_var[0]
, _instance->SimpleBrick_bgcolor_var[1]
, _instance->SimpleBrick_bgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, bx / _instance->SimpleBrick_SCALE_var + 1, by / _instance->SimpleBrick_SCALE_var + 1, ((_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 8) / _instance->SimpleBrick_SCALE_var - 2, _instance->SimpleBrick_BRICK_HEIGHT_var - 2);
_instance->SimpleBrick_bricks_var[y] = f_SimpleBrick_unsetBit(_instance, _instance->SimpleBrick_bricks_var[y]
, x);
}
// Definition of function collideBrick
uint8_t f_SimpleBrick_collideBrick(struct SimpleBrick_Instance *_instance, int16_t xpos, int16_t ypos) {
;int8_t bry = (ypos - _instance->SimpleBrick_TOP_var - 20 * _instance->SimpleBrick_SCALE_var) / (_instance->SimpleBrick_BRICK_HEIGHT_var * _instance->SimpleBrick_SCALE_var);
;uint8_t result = 0;
if(bry >= 0 && bry < _instance->SimpleBrick_BRICK_ROWS_var) {
;int8_t brx = (xpos - _instance->SimpleBrick_LEFT_var) / ((_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 8);
if(f_SimpleBrick_bitIsSet(_instance, _instance->SimpleBrick_bricks_var[bry]
, brx)) {
f_SimpleBrick_removeBrick(_instance, brx, bry);
result = 1;

}

}
return result;
}
// Definition of function drawScore
void f_SimpleBrick_drawScore(struct SimpleBrick_Instance *_instance) {
SimpleBrick_send_display_setColor(_instance, 158, 209, 130);
SimpleBrick_send_display_drawInteger(_instance, 98, 2, _instance->SimpleBrick_score_var, 5, 2);
}
// Definition of function drawLives
void f_SimpleBrick_drawLives(struct SimpleBrick_Instance *_instance) {
SimpleBrick_send_display_setColor(_instance, 183, 199, 111);
SimpleBrick_send_display_fillRect(_instance, 22, 4, 6, 6);
SimpleBrick_send_display_fillRect(_instance, 37, 4, 6, 6);
SimpleBrick_send_display_fillRect(_instance, 52, 4, 6, 6);
}

// Sessions functionss:


// On Entry Actions:
void SimpleBrick_SC_OnEntry(int state, struct SimpleBrick_Instance *_instance) {
switch(state) {
case SIMPLEBRICK_SC_STATE:{
_instance->SimpleBrick_SC_State = SIMPLEBRICK_SC_INIT_STATE;
SimpleBrick_SC_OnEntry(_instance->SimpleBrick_SC_State, _instance);
break;
}
case SIMPLEBRICK_SC_INIT_STATE:{
SimpleBrick_send_display_create(_instance, _instance->SimpleBrick_XDISPSIZE_var, _instance->SimpleBrick_YDISPSIZE_var);
break;
}
case SIMPLEBRICK_SC_PLAY_STATE:{
SimpleBrick_send_clock_timer_start(_instance, 0, 33);
break;
}
default: break;
}
}

// On Exit Actions:
void SimpleBrick_SC_OnExit(int state, struct SimpleBrick_Instance *_instance) {
switch(state) {
case SIMPLEBRICK_SC_STATE:{
SimpleBrick_SC_OnExit(_instance->SimpleBrick_SC_State, _instance);
break;}
case SIMPLEBRICK_SC_INIT_STATE:{
break;}
case SIMPLEBRICK_SC_PLAY_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void SimpleBrick_handle_display_displayReady(struct SimpleBrick_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t SimpleBrick_SC_State_event_consumed = 0;
if (_instance->SimpleBrick_SC_State == SIMPLEBRICK_SC_INIT_STATE) {
if (SimpleBrick_SC_State_event_consumed == 0 && 1) {
SimpleBrick_SC_OnExit(SIMPLEBRICK_SC_INIT_STATE, _instance);
_instance->SimpleBrick_SC_State = SIMPLEBRICK_SC_PLAY_STATE;
SimpleBrick_send_display_clear(_instance);
f_SimpleBrick_initColors(_instance);
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_bgcolor_var[0]
, _instance->SimpleBrick_bgcolor_var[1]
, _instance->SimpleBrick_bgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, 0, 0, _instance->SimpleBrick_XDISPSIZE_var, _instance->SimpleBrick_YDISPSIZE_var);
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_fgcolor_var[0]
, _instance->SimpleBrick_fgcolor_var[1]
, _instance->SimpleBrick_fgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, 0, 0, _instance->SimpleBrick_XDISPSIZE_var, 1);
SimpleBrick_send_display_fillRect(_instance, 0, 0, 18, 14);
SimpleBrick_send_display_fillRect(_instance, 90 - 28, 0, 28, 14);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_XDISPSIZE_var - 18, 0, 18, 14);
f_SimpleBrick_drawScore(_instance);
f_SimpleBrick_drawLives(_instance);
f_SimpleBrick_drawWalls(_instance);
f_SimpleBrick_createBricks(_instance);
SimpleBrick_SC_OnEntry(SIMPLEBRICK_SC_PLAY_STATE, _instance);
SimpleBrick_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SimpleBrick_handle_clock_timer_timeout(struct SimpleBrick_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SC
uint8_t SimpleBrick_SC_State_event_consumed = 0;
if (_instance->SimpleBrick_SC_State == SIMPLEBRICK_SC_PLAY_STATE) {
if (SimpleBrick_SC_State_event_consumed == 0 && id == 0) {
SimpleBrick_SC_OnExit(SIMPLEBRICK_SC_PLAY_STATE, _instance);
_instance->SimpleBrick_SC_State = SIMPLEBRICK_SC_PLAY_STATE;
_instance->SimpleBrick_bx_var = _instance->SimpleBrick_bx_var + _instance->SimpleBrick_dx_var;
_instance->SimpleBrick_by_var = _instance->SimpleBrick_by_var + _instance->SimpleBrick_dy_var;
;uint16_t wl = _instance->SimpleBrick_LEFT_var + _instance->SimpleBrick_br_var;
;uint16_t wr = _instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_br_var;
;uint16_t wt = _instance->SimpleBrick_TOP_var + _instance->SimpleBrick_br_var;
;uint16_t wb = _instance->SimpleBrick_BOTTOM_var - _instance->SimpleBrick_br_var;
if(_instance->SimpleBrick_bx_var < wl) {
_instance->SimpleBrick_dx_var =  -_instance->SimpleBrick_dx_var;
_instance->SimpleBrick_bx_var = 2 * wl - _instance->SimpleBrick_bx_var;

} else {
if(_instance->SimpleBrick_bx_var > wr) {
_instance->SimpleBrick_dx_var =  -_instance->SimpleBrick_dx_var;
_instance->SimpleBrick_bx_var = 2 * wr - _instance->SimpleBrick_bx_var;

}

}
if(_instance->SimpleBrick_by_var < wt) {
_instance->SimpleBrick_dy_var =  -_instance->SimpleBrick_dy_var;
_instance->SimpleBrick_by_var = 2 * wt - _instance->SimpleBrick_by_var;

} else {
if(_instance->SimpleBrick_by_var > wb) {
_instance->SimpleBrick_dy_var =  -_instance->SimpleBrick_dy_var;
_instance->SimpleBrick_by_var = 2 * wb - _instance->SimpleBrick_by_var;

}

}
if(_instance->SimpleBrick_dy_var > 0) {
if(_instance->SimpleBrick_by_var > _instance->SimpleBrick_pady_var - _instance->SimpleBrick_br_var && _instance->SimpleBrick_by_var < _instance->SimpleBrick_pady_var + _instance->SimpleBrick_br_var) {
if(_instance->SimpleBrick_bx_var > _instance->SimpleBrick_padx_var - _instance->SimpleBrick_padlen_var / 2 && _instance->SimpleBrick_bx_var < _instance->SimpleBrick_padx_var + _instance->SimpleBrick_padlen_var / 2) {
_instance->SimpleBrick_dy_var =  -_instance->SimpleBrick_dy_var;
_instance->SimpleBrick_by_var = 2 * (_instance->SimpleBrick_pady_var - _instance->SimpleBrick_br_var) - _instance->SimpleBrick_by_var;
_instance->SimpleBrick_dx_var = _instance->SimpleBrick_dx_var / 4 + (_instance->SimpleBrick_bx_var - _instance->SimpleBrick_padx_var) / 4;

}

}

}
;uint8_t collision = f_SimpleBrick_collideBrick(_instance, _instance->SimpleBrick_bx_var - _instance->SimpleBrick_br_var, _instance->SimpleBrick_by_var - _instance->SimpleBrick_br_var) || f_SimpleBrick_collideBrick(_instance, _instance->SimpleBrick_bx_var + _instance->SimpleBrick_br_var, _instance->SimpleBrick_by_var - _instance->SimpleBrick_br_var) || f_SimpleBrick_collideBrick(_instance, _instance->SimpleBrick_bx_var + _instance->SimpleBrick_br_var, _instance->SimpleBrick_by_var + _instance->SimpleBrick_br_var) || f_SimpleBrick_collideBrick(_instance, _instance->SimpleBrick_bx_var - _instance->SimpleBrick_br_var, _instance->SimpleBrick_by_var + _instance->SimpleBrick_br_var);
if(collision) {
_instance->SimpleBrick_dy_var =  -_instance->SimpleBrick_dy_var;
_instance->SimpleBrick_score_var = _instance->SimpleBrick_score_var + 10;
f_SimpleBrick_drawScore(_instance);

}
f_SimpleBrick_drawBall(_instance);
f_SimpleBrick_drawPad(_instance);
SimpleBrick_send_display_update(_instance);
SimpleBrick_SC_OnEntry(SIMPLEBRICK_SC_PLAY_STATE, _instance);
SimpleBrick_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SimpleBrick_handle_controller_position(struct SimpleBrick_Instance *_instance, int16_t x, int16_t y) {
if(!(_instance->active)) return;
//Region SC
uint8_t SimpleBrick_SC_State_event_consumed = 0;
if (_instance->SimpleBrick_SC_State == SIMPLEBRICK_SC_PLAY_STATE) {
if (SimpleBrick_SC_State_event_consumed == 0 && 1) {
;int16_t center = (_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 2;
_instance->SimpleBrick_padx_var = _instance->SimpleBrick_LEFT_var + center + (x * (_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var - _instance->SimpleBrick_padlen_var)) / 200;
SimpleBrick_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
void (*external_SimpleBrick_send_clock_timer_start_listener)(struct SimpleBrick_Instance *, uint8_t, uint32_t)= 0x0;
void (*SimpleBrick_send_clock_timer_start_listener)(struct SimpleBrick_Instance *, uint8_t, uint32_t)= 0x0;
void register_external_SimpleBrick_send_clock_timer_start_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint32_t)){
external_SimpleBrick_send_clock_timer_start_listener = _listener;
}
void register_SimpleBrick_send_clock_timer_start_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint32_t)){
SimpleBrick_send_clock_timer_start_listener = _listener;
}
void SimpleBrick_send_clock_timer_start(struct SimpleBrick_Instance *_instance, uint8_t id, uint32_t time){
if (SimpleBrick_send_clock_timer_start_listener != 0x0) SimpleBrick_send_clock_timer_start_listener(_instance, id, time);
if (external_SimpleBrick_send_clock_timer_start_listener != 0x0) external_SimpleBrick_send_clock_timer_start_listener(_instance, id, time);
;
}
void (*external_SimpleBrick_send_clock_timer_cancel_listener)(struct SimpleBrick_Instance *, uint8_t)= 0x0;
void (*SimpleBrick_send_clock_timer_cancel_listener)(struct SimpleBrick_Instance *, uint8_t)= 0x0;
void register_external_SimpleBrick_send_clock_timer_cancel_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t)){
external_SimpleBrick_send_clock_timer_cancel_listener = _listener;
}
void register_SimpleBrick_send_clock_timer_cancel_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t)){
SimpleBrick_send_clock_timer_cancel_listener = _listener;
}
void SimpleBrick_send_clock_timer_cancel(struct SimpleBrick_Instance *_instance, uint8_t id){
if (SimpleBrick_send_clock_timer_cancel_listener != 0x0) SimpleBrick_send_clock_timer_cancel_listener(_instance, id);
if (external_SimpleBrick_send_clock_timer_cancel_listener != 0x0) external_SimpleBrick_send_clock_timer_cancel_listener(_instance, id);
;
}
void (*external_SimpleBrick_send_display_create_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t)= 0x0;
void (*SimpleBrick_send_display_create_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_SimpleBrick_send_display_create_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t)){
external_SimpleBrick_send_display_create_listener = _listener;
}
void register_SimpleBrick_send_display_create_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t)){
SimpleBrick_send_display_create_listener = _listener;
}
void SimpleBrick_send_display_create(struct SimpleBrick_Instance *_instance, uint8_t xsize, uint8_t ysize){
if (SimpleBrick_send_display_create_listener != 0x0) SimpleBrick_send_display_create_listener(_instance, xsize, ysize);
if (external_SimpleBrick_send_display_create_listener != 0x0) external_SimpleBrick_send_display_create_listener(_instance, xsize, ysize);
;
}
void (*external_SimpleBrick_send_display_fillRect_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*SimpleBrick_send_display_fillRect_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_SimpleBrick_send_display_fillRect_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_SimpleBrick_send_display_fillRect_listener = _listener;
}
void register_SimpleBrick_send_display_fillRect_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
SimpleBrick_send_display_fillRect_listener = _listener;
}
void SimpleBrick_send_display_fillRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
if (SimpleBrick_send_display_fillRect_listener != 0x0) SimpleBrick_send_display_fillRect_listener(_instance, x, y, width, height);
if (external_SimpleBrick_send_display_fillRect_listener != 0x0) external_SimpleBrick_send_display_fillRect_listener(_instance, x, y, width, height);
;
}
void (*external_SimpleBrick_send_display_drawRect_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*SimpleBrick_send_display_drawRect_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_SimpleBrick_send_display_drawRect_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_SimpleBrick_send_display_drawRect_listener = _listener;
}
void register_SimpleBrick_send_display_drawRect_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
SimpleBrick_send_display_drawRect_listener = _listener;
}
void SimpleBrick_send_display_drawRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
if (SimpleBrick_send_display_drawRect_listener != 0x0) SimpleBrick_send_display_drawRect_listener(_instance, x, y, width, height);
if (external_SimpleBrick_send_display_drawRect_listener != 0x0) external_SimpleBrick_send_display_drawRect_listener(_instance, x, y, width, height);
;
}
void (*external_SimpleBrick_send_display_clear_listener)(struct SimpleBrick_Instance *)= 0x0;
void (*SimpleBrick_send_display_clear_listener)(struct SimpleBrick_Instance *)= 0x0;
void register_external_SimpleBrick_send_display_clear_listener(void (*_listener)(struct SimpleBrick_Instance *)){
external_SimpleBrick_send_display_clear_listener = _listener;
}
void register_SimpleBrick_send_display_clear_listener(void (*_listener)(struct SimpleBrick_Instance *)){
SimpleBrick_send_display_clear_listener = _listener;
}
void SimpleBrick_send_display_clear(struct SimpleBrick_Instance *_instance){
if (SimpleBrick_send_display_clear_listener != 0x0) SimpleBrick_send_display_clear_listener(_instance);
if (external_SimpleBrick_send_display_clear_listener != 0x0) external_SimpleBrick_send_display_clear_listener(_instance);
;
}
void (*external_SimpleBrick_send_display_setColor_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*SimpleBrick_send_display_setColor_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_SimpleBrick_send_display_setColor_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)){
external_SimpleBrick_send_display_setColor_listener = _listener;
}
void register_SimpleBrick_send_display_setColor_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)){
SimpleBrick_send_display_setColor_listener = _listener;
}
void SimpleBrick_send_display_setColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
if (SimpleBrick_send_display_setColor_listener != 0x0) SimpleBrick_send_display_setColor_listener(_instance, r, g, b);
if (external_SimpleBrick_send_display_setColor_listener != 0x0) external_SimpleBrick_send_display_setColor_listener(_instance, r, g, b);
;
}
void (*external_SimpleBrick_send_display_setBGColor_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*SimpleBrick_send_display_setBGColor_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_SimpleBrick_send_display_setBGColor_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)){
external_SimpleBrick_send_display_setBGColor_listener = _listener;
}
void register_SimpleBrick_send_display_setBGColor_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)){
SimpleBrick_send_display_setBGColor_listener = _listener;
}
void SimpleBrick_send_display_setBGColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
if (SimpleBrick_send_display_setBGColor_listener != 0x0) SimpleBrick_send_display_setBGColor_listener(_instance, r, g, b);
if (external_SimpleBrick_send_display_setBGColor_listener != 0x0) external_SimpleBrick_send_display_setBGColor_listener(_instance, r, g, b);
;
}
void (*external_SimpleBrick_send_display_drawInteger_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)= 0x0;
void (*SimpleBrick_send_display_drawInteger_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)= 0x0;
void register_external_SimpleBrick_send_display_drawInteger_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)){
external_SimpleBrick_send_display_drawInteger_listener = _listener;
}
void register_SimpleBrick_send_display_drawInteger_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)){
SimpleBrick_send_display_drawInteger_listener = _listener;
}
void SimpleBrick_send_display_drawInteger(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale){
if (SimpleBrick_send_display_drawInteger_listener != 0x0) SimpleBrick_send_display_drawInteger_listener(_instance, x, y, v, digits, scale);
if (external_SimpleBrick_send_display_drawInteger_listener != 0x0) external_SimpleBrick_send_display_drawInteger_listener(_instance, x, y, v, digits, scale);
;
}
void (*external_SimpleBrick_send_display_update_listener)(struct SimpleBrick_Instance *)= 0x0;
void (*SimpleBrick_send_display_update_listener)(struct SimpleBrick_Instance *)= 0x0;
void register_external_SimpleBrick_send_display_update_listener(void (*_listener)(struct SimpleBrick_Instance *)){
external_SimpleBrick_send_display_update_listener = _listener;
}
void register_SimpleBrick_send_display_update_listener(void (*_listener)(struct SimpleBrick_Instance *)){
SimpleBrick_send_display_update_listener = _listener;
}
void SimpleBrick_send_display_update(struct SimpleBrick_Instance *_instance){
if (SimpleBrick_send_display_update_listener != 0x0) SimpleBrick_send_display_update_listener(_instance);
if (external_SimpleBrick_send_display_update_listener != 0x0) external_SimpleBrick_send_display_update_listener(_instance);
;
}



