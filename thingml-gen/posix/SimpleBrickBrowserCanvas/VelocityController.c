/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing VelocityController
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "VelocityController.h"

/*****************************************************************************
 * Implementation for type : VelocityController
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void VelocityController_SC_OnExit(int state, struct VelocityController_Instance *_instance);
//Prototypes: Message Sending
void VelocityController_send_clock_timer_start(struct VelocityController_Instance *_instance, uint8_t id, uint32_t time);
void VelocityController_send_clock_timer_cancel(struct VelocityController_Instance *_instance, uint8_t id);
void VelocityController_send_controls_position(struct VelocityController_Instance *_instance, int16_t x, int16_t y);
void VelocityController_send_controls_fire(struct VelocityController_Instance *_instance, uint8_t id);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void VelocityController_SC_OnEntry(int state, struct VelocityController_Instance *_instance) {
switch(state) {
case VELOCITYCONTROLLER_SC_STATE:{
_instance->VelocityController_SC_State = VELOCITYCONTROLLER_SC_RUNNING_STATE;
VelocityController_SC_OnEntry(_instance->VelocityController_SC_State, _instance);
break;
}
case VELOCITYCONTROLLER_SC_RUNNING_STATE:{
VelocityController_send_clock_timer_start(_instance, _instance->VelocityController_timerID_var, 50);
break;
}
default: break;
}
}

// On Exit Actions:
void VelocityController_SC_OnExit(int state, struct VelocityController_Instance *_instance) {
switch(state) {
case VELOCITYCONTROLLER_SC_STATE:{
VelocityController_SC_OnExit(_instance->VelocityController_SC_State, _instance);
break;}
case VELOCITYCONTROLLER_SC_RUNNING_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void VelocityController_handle_ctrl_in_velocity(struct VelocityController_Instance *_instance, int16_t dx, int16_t dy) {
if(!(_instance->active)) return;
//Region SC
uint8_t VelocityController_SC_State_event_consumed = 0;
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
_instance->TimerController_dx_var = dx;
_instance->TimerController_dy_var = dy;
VelocityController_SC_State_event_consumed = 1;
}
}
void VelocityController_handle_ctrl_in_fire(struct VelocityController_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SC
uint8_t VelocityController_SC_State_event_consumed = 0;
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
VelocityController_send_controls_fire(_instance, id);
VelocityController_SC_State_event_consumed = 1;
}
}
void VelocityController_handle_clock_timer_timeout(struct VelocityController_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SC
uint8_t VelocityController_SC_State_event_consumed = 0;
if (_instance->VelocityController_SC_State == VELOCITYCONTROLLER_SC_RUNNING_STATE) {
if (VelocityController_SC_State_event_consumed == 0 && id == _instance->VelocityController_timerID_var) {
VelocityController_SC_OnExit(VELOCITYCONTROLLER_SC_RUNNING_STATE, _instance);
_instance->VelocityController_SC_State = VELOCITYCONTROLLER_SC_RUNNING_STATE;
_instance->TimerController_posX_var = _instance->TimerController_posX_var + _instance->TimerController_dx_var;
_instance->TimerController_posY_var = _instance->TimerController_posY_var + _instance->TimerController_dy_var;
if(_instance->TimerController_posX_var < _instance->TimerController_XMIN_var) {
_instance->TimerController_posX_var = _instance->TimerController_XMIN_var;

} else {
if(_instance->TimerController_posX_var > _instance->TimerController_XMAX_var) {
_instance->TimerController_posX_var = _instance->TimerController_XMAX_var;

}

}
if(_instance->TimerController_posY_var < _instance->TimerController_YMIN_var) {
_instance->TimerController_posY_var = _instance->TimerController_YMIN_var;

} else {
if(_instance->TimerController_posY_var > _instance->TimerController_YMAX_var) {
_instance->TimerController_posY_var = _instance->TimerController_YMAX_var;

}

}
VelocityController_send_controls_position(_instance, _instance->TimerController_posX_var, _instance->TimerController_posY_var);
VelocityController_SC_OnEntry(VELOCITYCONTROLLER_SC_RUNNING_STATE, _instance);
VelocityController_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
void (*external_VelocityController_send_clock_timer_start_listener)(struct VelocityController_Instance *, uint8_t, uint32_t)= 0x0;
void (*VelocityController_send_clock_timer_start_listener)(struct VelocityController_Instance *, uint8_t, uint32_t)= 0x0;
void register_external_VelocityController_send_clock_timer_start_listener(void (*_listener)(struct VelocityController_Instance *, uint8_t, uint32_t)){
external_VelocityController_send_clock_timer_start_listener = _listener;
}
void register_VelocityController_send_clock_timer_start_listener(void (*_listener)(struct VelocityController_Instance *, uint8_t, uint32_t)){
VelocityController_send_clock_timer_start_listener = _listener;
}
void VelocityController_send_clock_timer_start(struct VelocityController_Instance *_instance, uint8_t id, uint32_t time){
if (VelocityController_send_clock_timer_start_listener != 0x0) VelocityController_send_clock_timer_start_listener(_instance, id, time);
if (external_VelocityController_send_clock_timer_start_listener != 0x0) external_VelocityController_send_clock_timer_start_listener(_instance, id, time);
;
}
void (*external_VelocityController_send_clock_timer_cancel_listener)(struct VelocityController_Instance *, uint8_t)= 0x0;
void (*VelocityController_send_clock_timer_cancel_listener)(struct VelocityController_Instance *, uint8_t)= 0x0;
void register_external_VelocityController_send_clock_timer_cancel_listener(void (*_listener)(struct VelocityController_Instance *, uint8_t)){
external_VelocityController_send_clock_timer_cancel_listener = _listener;
}
void register_VelocityController_send_clock_timer_cancel_listener(void (*_listener)(struct VelocityController_Instance *, uint8_t)){
VelocityController_send_clock_timer_cancel_listener = _listener;
}
void VelocityController_send_clock_timer_cancel(struct VelocityController_Instance *_instance, uint8_t id){
if (VelocityController_send_clock_timer_cancel_listener != 0x0) VelocityController_send_clock_timer_cancel_listener(_instance, id);
if (external_VelocityController_send_clock_timer_cancel_listener != 0x0) external_VelocityController_send_clock_timer_cancel_listener(_instance, id);
;
}
void (*external_VelocityController_send_controls_position_listener)(struct VelocityController_Instance *, int16_t, int16_t)= 0x0;
void (*VelocityController_send_controls_position_listener)(struct VelocityController_Instance *, int16_t, int16_t)= 0x0;
void register_external_VelocityController_send_controls_position_listener(void (*_listener)(struct VelocityController_Instance *, int16_t, int16_t)){
external_VelocityController_send_controls_position_listener = _listener;
}
void register_VelocityController_send_controls_position_listener(void (*_listener)(struct VelocityController_Instance *, int16_t, int16_t)){
VelocityController_send_controls_position_listener = _listener;
}
void VelocityController_send_controls_position(struct VelocityController_Instance *_instance, int16_t x, int16_t y){
if (VelocityController_send_controls_position_listener != 0x0) VelocityController_send_controls_position_listener(_instance, x, y);
if (external_VelocityController_send_controls_position_listener != 0x0) external_VelocityController_send_controls_position_listener(_instance, x, y);
;
}
void (*external_VelocityController_send_controls_fire_listener)(struct VelocityController_Instance *, uint8_t)= 0x0;
void (*VelocityController_send_controls_fire_listener)(struct VelocityController_Instance *, uint8_t)= 0x0;
void register_external_VelocityController_send_controls_fire_listener(void (*_listener)(struct VelocityController_Instance *, uint8_t)){
external_VelocityController_send_controls_fire_listener = _listener;
}
void register_VelocityController_send_controls_fire_listener(void (*_listener)(struct VelocityController_Instance *, uint8_t)){
VelocityController_send_controls_fire_listener = _listener;
}
void VelocityController_send_controls_fire(struct VelocityController_Instance *_instance, uint8_t id){
if (VelocityController_send_controls_fire_listener != 0x0) VelocityController_send_controls_fire_listener(_instance, id);
if (external_VelocityController_send_controls_fire_listener != 0x0) external_VelocityController_send_controls_fire_listener(_instance, id);
;
}



