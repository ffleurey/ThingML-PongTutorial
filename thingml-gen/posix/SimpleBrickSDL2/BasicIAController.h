/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing BasicIAController
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef BasicIAController_H_
#define BasicIAController_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : BasicIAController
 *****************************************************************************/

// Definition of the instance struct:
struct BasicIAController_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_game;
uint16_t id_controls;
// Variables for the current instance state
int BasicIAController_SC_State;
// Variables for the properties of the instance
int16_t BasicIAController_ctrlx_var;

};
// Declaration of prototypes outgoing messages:
void BasicIAController_SC_OnEntry(int state, struct BasicIAController_Instance *_instance);
void BasicIAController_handle_game_updateIA(struct BasicIAController_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady);
// Declaration of callbacks for incoming messages:
void register_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t));
void register_external_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t));
void register_BasicIAController_send_controls_fire_listener(void (*_listener)(struct BasicIAController_Instance *, uint8_t));
void register_external_BasicIAController_send_controls_fire_listener(void (*_listener)(struct BasicIAController_Instance *, uint8_t));

// Definition of the states:
#define BASICIACONTROLLER_SC_STATE 0
#define BASICIACONTROLLER_SC_FOLLOWING_STATE 1



#ifdef __cplusplus
}
#endif

#endif //BasicIAController_H_
