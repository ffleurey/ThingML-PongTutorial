/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing VelocityController
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef VelocityController_H_
#define VelocityController_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : VelocityController
 *****************************************************************************/

// Definition of the instance struct:
struct VelocityController_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_ctrl_in;
uint16_t id_clock;
uint16_t id_controls;
// Variables for the current instance state
int VelocityController_SC_State;
// Variables for the properties of the instance
int16_t TimerController_XMAX_var;
int16_t TimerController_posX_var;
int16_t TimerController_XMIN_var;
int16_t TimerController_YMAX_var;
int16_t TimerController_posY_var;
uint8_t VelocityController_timerID_var;
int16_t TimerController_dy_var;
int16_t TimerController_YMIN_var;
int16_t TimerController_dx_var;

};
// Declaration of prototypes outgoing messages:
void VelocityController_SC_OnEntry(int state, struct VelocityController_Instance *_instance);
void VelocityController_handle_ctrl_in_velocity(struct VelocityController_Instance *_instance, int16_t dx, int16_t dy);
void VelocityController_handle_ctrl_in_fire(struct VelocityController_Instance *_instance, uint8_t id);
void VelocityController_handle_clock_timer_timeout(struct VelocityController_Instance *_instance, uint8_t id);
// Declaration of callbacks for incoming messages:
void register_VelocityController_send_clock_timer_start_listener(void (*_listener)(struct VelocityController_Instance *, uint8_t, uint32_t));
void register_external_VelocityController_send_clock_timer_start_listener(void (*_listener)(struct VelocityController_Instance *, uint8_t, uint32_t));
void register_VelocityController_send_clock_timer_cancel_listener(void (*_listener)(struct VelocityController_Instance *, uint8_t));
void register_external_VelocityController_send_clock_timer_cancel_listener(void (*_listener)(struct VelocityController_Instance *, uint8_t));
void register_VelocityController_send_controls_position_listener(void (*_listener)(struct VelocityController_Instance *, int16_t, int16_t));
void register_external_VelocityController_send_controls_position_listener(void (*_listener)(struct VelocityController_Instance *, int16_t, int16_t));
void register_VelocityController_send_controls_fire_listener(void (*_listener)(struct VelocityController_Instance *, uint8_t));
void register_external_VelocityController_send_controls_fire_listener(void (*_listener)(struct VelocityController_Instance *, uint8_t));

// Definition of the states:
#define VELOCITYCONTROLLER_SC_STATE 0
#define VELOCITYCONTROLLER_SC_RUNNING_STATE 1



#ifdef __cplusplus
}
#endif

#endif //VelocityController_H_
