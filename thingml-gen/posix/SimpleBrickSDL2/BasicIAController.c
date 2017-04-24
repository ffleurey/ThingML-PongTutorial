/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing BasicIAController
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "BasicIAController.h"

/*****************************************************************************
 * Implementation for type : BasicIAController
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void BasicIAController_SC_OnExit(int state, struct BasicIAController_Instance *_instance);
//Prototypes: Message Sending
void BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y);
void BasicIAController_send_controls_fire(struct BasicIAController_Instance *_instance, uint8_t id);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void BasicIAController_SC_OnEntry(int state, struct BasicIAController_Instance *_instance) {
switch(state) {
case BASICIACONTROLLER_SC_STATE:{
_instance->BasicIAController_SC_State = BASICIACONTROLLER_SC_FOLLOWING_STATE;
BasicIAController_SC_OnEntry(_instance->BasicIAController_SC_State, _instance);
break;
}
case BASICIACONTROLLER_SC_FOLLOWING_STATE:{
BasicIAController_send_controls_position(_instance, _instance->BasicIAController_ctrlx_var, 0);
break;
}
default: break;
}
}

// On Exit Actions:
void BasicIAController_SC_OnExit(int state, struct BasicIAController_Instance *_instance) {
switch(state) {
case BASICIACONTROLLER_SC_STATE:{
BasicIAController_SC_OnExit(_instance->BasicIAController_SC_State, _instance);
break;}
case BASICIACONTROLLER_SC_FOLLOWING_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void BasicIAController_handle_game_updateIA(struct BasicIAController_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady) {
if(!(_instance->active)) return;
//Region SC
uint8_t BasicIAController_SC_State_event_consumed = 0;
if (_instance->BasicIAController_SC_State == BASICIACONTROLLER_SC_FOLLOWING_STATE) {
if (BasicIAController_SC_State_event_consumed == 0 && 1) {
BasicIAController_SC_OnExit(BASICIACONTROLLER_SC_FOLLOWING_STATE, _instance);
_instance->BasicIAController_SC_State = BASICIACONTROLLER_SC_FOLLOWING_STATE;
if(ballx > padx + 300) {
_instance->BasicIAController_ctrlx_var = _instance->BasicIAController_ctrlx_var + 4;

} else {
if(ballx < padx - 300) {
_instance->BasicIAController_ctrlx_var = _instance->BasicIAController_ctrlx_var - 4;

}

}
if(_instance->BasicIAController_ctrlx_var <  -100) {
_instance->BasicIAController_ctrlx_var =  -100;

} else {
if(_instance->BasicIAController_ctrlx_var > 100) {
_instance->BasicIAController_ctrlx_var = 100;

}

}
BasicIAController_SC_OnEntry(BASICIACONTROLLER_SC_FOLLOWING_STATE, _instance);
BasicIAController_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
void (*external_BasicIAController_send_controls_position_listener)(struct BasicIAController_Instance *, int16_t, int16_t)= 0x0;
void (*BasicIAController_send_controls_position_listener)(struct BasicIAController_Instance *, int16_t, int16_t)= 0x0;
void register_external_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t)){
external_BasicIAController_send_controls_position_listener = _listener;
}
void register_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t)){
BasicIAController_send_controls_position_listener = _listener;
}
void BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y){
if (BasicIAController_send_controls_position_listener != 0x0) BasicIAController_send_controls_position_listener(_instance, x, y);
if (external_BasicIAController_send_controls_position_listener != 0x0) external_BasicIAController_send_controls_position_listener(_instance, x, y);
;
}
void (*external_BasicIAController_send_controls_fire_listener)(struct BasicIAController_Instance *, uint8_t)= 0x0;
void (*BasicIAController_send_controls_fire_listener)(struct BasicIAController_Instance *, uint8_t)= 0x0;
void register_external_BasicIAController_send_controls_fire_listener(void (*_listener)(struct BasicIAController_Instance *, uint8_t)){
external_BasicIAController_send_controls_fire_listener = _listener;
}
void register_BasicIAController_send_controls_fire_listener(void (*_listener)(struct BasicIAController_Instance *, uint8_t)){
BasicIAController_send_controls_fire_listener = _listener;
}
void BasicIAController_send_controls_fire(struct BasicIAController_Instance *_instance, uint8_t id){
if (BasicIAController_send_controls_fire_listener != 0x0) BasicIAController_send_controls_fire_listener(_instance, id);
if (external_BasicIAController_send_controls_fire_listener != 0x0) external_BasicIAController_send_controls_fire_listener(_instance, id);
;
}



