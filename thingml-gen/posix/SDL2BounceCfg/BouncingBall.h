/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing BouncingBall
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef BouncingBall_H_
#define BouncingBall_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : BouncingBall
 *****************************************************************************/

// Definition of the instance struct:
struct BouncingBall_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_clock;
uint16_t id_ball;
// Variables for the current instance state
int BouncingBall_SC_State;
// Variables for the properties of the instance
int16_t BouncingBall_MAX_var;
int16_t BouncingBall_bx_var;
int16_t BouncingBall_by_var;
int16_t BouncingBall_dx_var;
int16_t BouncingBall_dy_var;
uint8_t Constants_XSIZE_var;
uint8_t Constants_YSIZE_var;
uint8_t BouncingBall_SC_BOUNCE_lastX_var;
uint8_t BouncingBall_SC_BOUNCE_lastY_var;

};
// Declaration of prototypes outgoing messages:
void BouncingBall_SC_OnEntry(int state, struct BouncingBall_Instance *_instance);
void BouncingBall_handle_ball_bounce(struct BouncingBall_Instance *_instance);
void BouncingBall_handle_ball_stop(struct BouncingBall_Instance *_instance);
void BouncingBall_handle_clock_timer_timeout(struct BouncingBall_Instance *_instance, uint8_t id);
// Declaration of callbacks for incoming messages:
void register_BouncingBall_send_ball_updateBall_listener(void (*_listener)(struct BouncingBall_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_external_BouncingBall_send_ball_updateBall_listener(void (*_listener)(struct BouncingBall_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));

// Definition of the states:
#define BOUNCINGBALL_SC_STATE 0
#define BOUNCINGBALL_SC_STOP_STATE 1
#define BOUNCINGBALL_SC_BOUNCE_STATE 2



#ifdef __cplusplus
}
#endif

#endif //BouncingBall_H_
