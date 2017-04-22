/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing TimerBrowser
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "TimerBrowser.h"

/*****************************************************************************
 * Implementation for type : TimerBrowser
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void TimerBrowser_SoftTimer_OnExit(int state, struct TimerBrowser_Instance *_instance);
//Prototypes: Message Sending
void TimerBrowser_send_timer_timer_timeout(struct TimerBrowser_Instance *_instance, uint8_t id);
//Prototypes: Function
void f_TimerBrowser_startTimer(struct TimerBrowser_Instance *_instance, int id, int delay);
void f_TimerBrowser_cancel(struct TimerBrowser_Instance *_instance, int id);
// Declaration of functions:
// Definition of function startTimer
void f_TimerBrowser_startTimer(struct TimerBrowser_Instance *_instance, int id, int delay) {

      if (_instance->TimerBrowser_Timeouts_var[id] != undefined) {
        
f_TimerBrowser_cancel(_instance, id);

      }
      
      _instance->TimerBrowser_Timeouts_var[id] = setTimeout(() => {
        
TimerBrowser_send_timer_timer_timeout(_instance, id);

        _instance->TimerBrowser_Timeouts_var[id] = undefined;
      }, delay);
    
}
// Definition of function cancel
void f_TimerBrowser_cancel(struct TimerBrowser_Instance *_instance, int id) {

        if (_instance->TimerBrowser_Timeouts_var[id] != undefined) {
          clearTimeout(_instance->TimerBrowser_Timeouts_var[id]);
          _instance->TimerBrowser_Timeouts_var[id] = undefined;
        }
      
}

// Sessions functionss:


// On Entry Actions:
void TimerBrowser_SoftTimer_OnEntry(int state, struct TimerBrowser_Instance *_instance) {
switch(state) {
case TIMERBROWSER_SOFTTIMER_STATE:{
_instance->TimerBrowser_SoftTimer_State = TIMERBROWSER_SOFTTIMER_DEFAULT_STATE;
TimerBrowser_SoftTimer_OnEntry(_instance->TimerBrowser_SoftTimer_State, _instance);
break;
}
case TIMERBROWSER_SOFTTIMER_DEFAULT_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void TimerBrowser_SoftTimer_OnExit(int state, struct TimerBrowser_Instance *_instance) {
switch(state) {
case TIMERBROWSER_SOFTTIMER_STATE:{
TimerBrowser_SoftTimer_OnExit(_instance->TimerBrowser_SoftTimer_State, _instance);
break;}
case TIMERBROWSER_SOFTTIMER_DEFAULT_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void TimerBrowser_handle_timer_timer_start(struct TimerBrowser_Instance *_instance, uint8_t id, uint32_t time) {
if(!(_instance->active)) return;
//Region SoftTimer
uint8_t TimerBrowser_SoftTimer_State_event_consumed = 0;
if (_instance->TimerBrowser_SoftTimer_State == TIMERBROWSER_SOFTTIMER_DEFAULT_STATE) {
if (TimerBrowser_SoftTimer_State_event_consumed == 0 && time > 0) {
f_TimerBrowser_startTimer(_instance, id, time);
TimerBrowser_SoftTimer_State_event_consumed = 1;
}
}
//End Region SoftTimer
//End dsregion SoftTimer
//Session list: 
}
void TimerBrowser_handle_timer_timer_cancel(struct TimerBrowser_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SoftTimer
uint8_t TimerBrowser_SoftTimer_State_event_consumed = 0;
if (_instance->TimerBrowser_SoftTimer_State == TIMERBROWSER_SOFTTIMER_DEFAULT_STATE) {
if (TimerBrowser_SoftTimer_State_event_consumed == 0 && 1) {
f_TimerBrowser_cancel(_instance, id);
TimerBrowser_SoftTimer_State_event_consumed = 1;
}
}
//End Region SoftTimer
//End dsregion SoftTimer
//Session list: 
}

// Observers for outgoing messages:
void (*external_TimerBrowser_send_timer_timer_timeout_listener)(struct TimerBrowser_Instance *, uint8_t)= 0x0;
void (*TimerBrowser_send_timer_timer_timeout_listener)(struct TimerBrowser_Instance *, uint8_t)= 0x0;
void register_external_TimerBrowser_send_timer_timer_timeout_listener(void (*_listener)(struct TimerBrowser_Instance *, uint8_t)){
external_TimerBrowser_send_timer_timer_timeout_listener = _listener;
}
void register_TimerBrowser_send_timer_timer_timeout_listener(void (*_listener)(struct TimerBrowser_Instance *, uint8_t)){
TimerBrowser_send_timer_timer_timeout_listener = _listener;
}
void TimerBrowser_send_timer_timer_timeout(struct TimerBrowser_Instance *_instance, uint8_t id){
if (TimerBrowser_send_timer_timer_timeout_listener != 0x0) TimerBrowser_send_timer_timer_timeout_listener(_instance, id);
if (external_TimerBrowser_send_timer_timer_timeout_listener != 0x0) external_TimerBrowser_send_timer_timer_timeout_listener(_instance, id);
;
}



