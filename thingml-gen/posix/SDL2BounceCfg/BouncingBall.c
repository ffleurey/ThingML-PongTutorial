/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing BouncingBall
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "BouncingBall.h"

/*****************************************************************************
 * Implementation for type : BouncingBall
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void BouncingBall_SC_OnExit(int state, struct BouncingBall_Instance *_instance);
//Prototypes: Message Sending
void BouncingBall_send_ball_updateBall(struct BouncingBall_Instance *_instance, uint8_t oldx, uint8_t oldy, uint8_t newx, uint8_t newy);
//Prototypes: Function
uint8_t f_BouncingBall_getBallX(struct BouncingBall_Instance *_instance, uint16_t bx);
uint8_t f_BouncingBall_getBallY(struct BouncingBall_Instance *_instance, uint16_t by);
// Declaration of functions:
// Definition of function getBallX
uint8_t f_BouncingBall_getBallX(struct BouncingBall_Instance *_instance, uint16_t bx) {
;long l = bx;
l = l * (_instance->Constants_XSIZE_var - 8);
l = l / (_instance->BouncingBall_MAX_var + 1) + 4;
return l;
}
// Definition of function getBallY
uint8_t f_BouncingBall_getBallY(struct BouncingBall_Instance *_instance, uint16_t by) {
;long l = by;
l = l * (_instance->Constants_YSIZE_var - 8);
l = l / (_instance->BouncingBall_MAX_var + 1) + 4;
return l;
}

// Sessions functionss:


// On Entry Actions:
void BouncingBall_SC_OnEntry(int state, struct BouncingBall_Instance *_instance) {
switch(state) {
case BOUNCINGBALL_SC_STATE:{
_instance->BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
BouncingBall_SC_OnEntry(_instance->BouncingBall_SC_State, _instance);
break;
}
case BOUNCINGBALL_SC_STOP_STATE:{
break;
}
case BOUNCINGBALL_SC_BOUNCE_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void BouncingBall_SC_OnExit(int state, struct BouncingBall_Instance *_instance) {
switch(state) {
case BOUNCINGBALL_SC_STATE:{
BouncingBall_SC_OnExit(_instance->BouncingBall_SC_State, _instance);
break;}
case BOUNCINGBALL_SC_STOP_STATE:{
break;}
case BOUNCINGBALL_SC_BOUNCE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void BouncingBall_handle_ball_bounce(struct BouncingBall_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BouncingBall_SC_State_event_consumed = 0;
if (_instance->BouncingBall_SC_State == BOUNCINGBALL_SC_STOP_STATE) {
if (BouncingBall_SC_State_event_consumed == 0 && 1) {
BouncingBall_SC_OnExit(BOUNCINGBALL_SC_STOP_STATE, _instance);
_instance->BouncingBall_SC_State = BOUNCINGBALL_SC_BOUNCE_STATE;
BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_BOUNCE_STATE, _instance);
BouncingBall_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BouncingBall_handle_ball_stop(struct BouncingBall_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BouncingBall_SC_State_event_consumed = 0;
if (_instance->BouncingBall_SC_State == BOUNCINGBALL_SC_BOUNCE_STATE) {
if (BouncingBall_SC_State_event_consumed == 0 && 1) {
BouncingBall_SC_OnExit(BOUNCINGBALL_SC_BOUNCE_STATE, _instance);
_instance->BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_STOP_STATE, _instance);
BouncingBall_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BouncingBall_handle_clock_timer_timeout(struct BouncingBall_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SC
uint8_t BouncingBall_SC_State_event_consumed = 0;
if (_instance->BouncingBall_SC_State == BOUNCINGBALL_SC_BOUNCE_STATE) {
if (BouncingBall_SC_State_event_consumed == 0 && id == 1) {
_instance->BouncingBall_bx_var = _instance->BouncingBall_bx_var + _instance->BouncingBall_dx_var;
_instance->BouncingBall_by_var = _instance->BouncingBall_by_var + _instance->BouncingBall_dy_var;
if(_instance->BouncingBall_bx_var < 0) {
_instance->BouncingBall_dx_var =  -_instance->BouncingBall_dx_var;
_instance->BouncingBall_bx_var =  -_instance->BouncingBall_bx_var;

} else {
if(_instance->BouncingBall_bx_var > _instance->BouncingBall_MAX_var) {
_instance->BouncingBall_dx_var =  -_instance->BouncingBall_dx_var;
_instance->BouncingBall_bx_var = _instance->BouncingBall_bx_var - (_instance->BouncingBall_bx_var - _instance->BouncingBall_MAX_var);

}

}
if(_instance->BouncingBall_by_var < 0) {
_instance->BouncingBall_dy_var =  -_instance->BouncingBall_dy_var;
_instance->BouncingBall_by_var =  -_instance->BouncingBall_by_var;

} else {
if(_instance->BouncingBall_by_var > _instance->BouncingBall_MAX_var) {
_instance->BouncingBall_dy_var =  -_instance->BouncingBall_dy_var;
_instance->BouncingBall_by_var = _instance->BouncingBall_by_var - (_instance->BouncingBall_by_var - _instance->BouncingBall_MAX_var);

}

}
;uint8_t newX = f_BouncingBall_getBallX(_instance, _instance->BouncingBall_bx_var);
;uint8_t newY = f_BouncingBall_getBallY(_instance, _instance->BouncingBall_by_var);
BouncingBall_send_ball_updateBall(_instance, _instance->BouncingBall_SC_BOUNCE_lastX_var, _instance->BouncingBall_SC_BOUNCE_lastY_var, newX, newY);
_instance->BouncingBall_SC_BOUNCE_lastX_var = newX;
_instance->BouncingBall_SC_BOUNCE_lastY_var = newY;
BouncingBall_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
void (*external_BouncingBall_send_ball_updateBall_listener)(struct BouncingBall_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BouncingBall_send_ball_updateBall_listener)(struct BouncingBall_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BouncingBall_send_ball_updateBall_listener(void (*_listener)(struct BouncingBall_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_BouncingBall_send_ball_updateBall_listener = _listener;
}
void register_BouncingBall_send_ball_updateBall_listener(void (*_listener)(struct BouncingBall_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
BouncingBall_send_ball_updateBall_listener = _listener;
}
void BouncingBall_send_ball_updateBall(struct BouncingBall_Instance *_instance, uint8_t oldx, uint8_t oldy, uint8_t newx, uint8_t newy){
if (BouncingBall_send_ball_updateBall_listener != 0x0) BouncingBall_send_ball_updateBall_listener(_instance, oldx, oldy, newx, newy);
if (external_BouncingBall_send_ball_updateBall_listener != 0x0) external_BouncingBall_send_ball_updateBall_listener(_instance, oldx, oldy, newx, newy);
;
}



