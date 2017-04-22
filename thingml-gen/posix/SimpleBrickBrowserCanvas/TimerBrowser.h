/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing TimerBrowser
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef TimerBrowser_H_
#define TimerBrowser_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : TimerBrowser
 *****************************************************************************/

// Definition of the instance struct:
struct TimerBrowser_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_timer;
// Variables for the current instance state
int TimerBrowser_SoftTimer_State;
// Variables for the properties of the instance
Array TimerBrowser_Timeouts_var;

};
// Declaration of prototypes outgoing messages:
void TimerBrowser_SoftTimer_OnEntry(int state, struct TimerBrowser_Instance *_instance);
void TimerBrowser_handle_timer_timer_start(struct TimerBrowser_Instance *_instance, uint8_t id, uint32_t time);
void TimerBrowser_handle_timer_timer_cancel(struct TimerBrowser_Instance *_instance, uint8_t id);
// Declaration of callbacks for incoming messages:
void register_TimerBrowser_send_timer_timer_timeout_listener(void (*_listener)(struct TimerBrowser_Instance *, uint8_t));
void register_external_TimerBrowser_send_timer_timer_timeout_listener(void (*_listener)(struct TimerBrowser_Instance *, uint8_t));

// Definition of the states:
#define TIMERBROWSER_SOFTTIMER_STATE 0
#define TIMERBROWSER_SOFTTIMER_DEFAULT_STATE 1



#ifdef __cplusplus
}
#endif

#endif //TimerBrowser_H_
