/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing SDL2Display
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef SDL2Display_H_
#define SDL2Display_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : SDL2Display
 *****************************************************************************/


// BEGIN: Code from the c_header annotation SDL2Display

#include <SDL2/SDL.h>

// END: Code from the c_header annotation SDL2Display

// Definition of the instance struct:
struct SDL2Display_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_display;
uint16_t id_controls;
// Variables for the current instance state
int Display_SC_State;
// Variables for the properties of the instance
uint16_t SDL2Display_XFRAMESIZE_var;
uint8_t SDL2Display_scale_var;
int16_t SDL2Display_xctrl_var;
uint8_t Display_bg_b_var;
uint8_t Display_bg_r_var;
uint16_t SDL2Display_YFRAMESIZE_var;
uint8_t Display_bg_g_var;
uint8_t Display_fg_r_var;
uint8_t Display_fg_b_var;
uint8_t Display_fg_g_var;

};
// Declaration of prototypes outgoing messages:
void Display_SC_OnEntry(int state, struct SDL2Display_Instance *_instance);
void SDL2Display_handle_display_clear(struct SDL2Display_Instance *_instance);
void SDL2Display_handle_display_fillRect(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void SDL2Display_handle_display_update(struct SDL2Display_Instance *_instance);
void SDL2Display_handle_display_drawInteger(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void SDL2Display_handle_display_create(struct SDL2Display_Instance *_instance, uint8_t xsize, uint8_t ysize);
void SDL2Display_handle_display_destroy(struct SDL2Display_Instance *_instance);
void SDL2Display_handle_display_setColor(struct SDL2Display_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void SDL2Display_handle_display_drawRect(struct SDL2Display_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void SDL2Display_handle_display_setBGColor(struct SDL2Display_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
// Declaration of callbacks for incoming messages:
void register_SDL2Display_send_display_displayReady_listener(void (*_listener)(struct SDL2Display_Instance *));
void register_external_SDL2Display_send_display_displayReady_listener(void (*_listener)(struct SDL2Display_Instance *));
void register_SDL2Display_send_display_displayError_listener(void (*_listener)(struct SDL2Display_Instance *));
void register_external_SDL2Display_send_display_displayError_listener(void (*_listener)(struct SDL2Display_Instance *));
void register_SDL2Display_send_controls_position_listener(void (*_listener)(struct SDL2Display_Instance *, int16_t, int16_t));
void register_external_SDL2Display_send_controls_position_listener(void (*_listener)(struct SDL2Display_Instance *, int16_t, int16_t));
void register_SDL2Display_send_controls_fire_listener(void (*_listener)(struct SDL2Display_Instance *, uint8_t));
void register_external_SDL2Display_send_controls_fire_listener(void (*_listener)(struct SDL2Display_Instance *, uint8_t));

// Definition of the states:
#define DISPLAY_SC_STATE 0
#define DISPLAY_SC_WAIT_STATE 1
#define DISPLAY_SC_RUNNING_STATE 2
#define DISPLAY_SC_DESTROYED_STATE 3



#ifdef __cplusplus
}
#endif

#endif //SDL2Display_H_
