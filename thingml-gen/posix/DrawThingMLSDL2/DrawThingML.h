/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing DrawThingML
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef DrawThingML_H_
#define DrawThingML_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : DrawThingML
 *****************************************************************************/

// Definition of the instance struct:
struct DrawThingML_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_display;
// Variables for the current instance state
int DrawThingML_State;
// Variables for the properties of the instance
uint8_t DrawThingML_YDISPSIZE_var;
uint8_t DrawThingML_XDISPSIZE_var;

};
// Declaration of prototypes outgoing messages:
void DrawThingML_OnEntry(int state, struct DrawThingML_Instance *_instance);
void DrawThingML_handle_display_displayReady(struct DrawThingML_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_DrawThingML_send_display_create_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t));
void register_external_DrawThingML_send_display_create_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t));
void register_DrawThingML_send_display_fillRect_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_external_DrawThingML_send_display_fillRect_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_DrawThingML_send_display_drawRect_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_external_DrawThingML_send_display_drawRect_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_DrawThingML_send_display_clear_listener(void (*_listener)(struct DrawThingML_Instance *));
void register_external_DrawThingML_send_display_clear_listener(void (*_listener)(struct DrawThingML_Instance *));
void register_DrawThingML_send_display_setColor_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_DrawThingML_send_display_setColor_listener(void (*_listener)(struct DrawThingML_Instance *, uint8_t, uint8_t, uint8_t));
void register_DrawThingML_send_display_update_listener(void (*_listener)(struct DrawThingML_Instance *));
void register_external_DrawThingML_send_display_update_listener(void (*_listener)(struct DrawThingML_Instance *));

// Definition of the states:
#define DRAWTHINGML_STATE 0
#define DRAWTHINGML_NULL_DRAW_STATE 1



#ifdef __cplusplus
}
#endif

#endif //DrawThingML_H_
