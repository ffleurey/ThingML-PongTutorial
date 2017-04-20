/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing SDL2BounceApp
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef SDL2BounceApp_H_
#define SDL2BounceApp_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : SDL2BounceApp
 *****************************************************************************/


// BEGIN: Code from the c_header annotation SDL2BounceApp

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
// END: Code from the c_header annotation SDL2BounceApp

// Definition of the instance struct:
struct SDL2BounceApp_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_clock;
uint16_t id_ball;
// Variables for the current instance state
int BounceApp_SC_State;
// Variables for the properties of the instance
char * SDL2BounceApp_TTF_FONT_PATH_var;
uint16_t SDL2BounceApp_color_var;
uint8_t SDL2BounceApp_scale_var;
uint8_t Constants_XSIZE_var;
uint8_t Constants_YSIZE_var;

};
// Declaration of prototypes outgoing messages:
void BounceApp_SC_OnEntry(int state, struct SDL2BounceApp_Instance *_instance);
void SDL2BounceApp_handle_clock_timer_timeout(struct SDL2BounceApp_Instance *_instance, uint8_t id);
void SDL2BounceApp_handle_ball_updateBall(struct SDL2BounceApp_Instance *_instance, uint8_t oldx, uint8_t oldy, uint8_t newx, uint8_t newy);
// Declaration of callbacks for incoming messages:
void register_SDL2BounceApp_send_clock_timer_start_listener(void (*_listener)(struct SDL2BounceApp_Instance *, uint8_t, uint32_t));
void register_external_SDL2BounceApp_send_clock_timer_start_listener(void (*_listener)(struct SDL2BounceApp_Instance *, uint8_t, uint32_t));
void register_SDL2BounceApp_send_clock_timer_cancel_listener(void (*_listener)(struct SDL2BounceApp_Instance *, uint8_t));
void register_external_SDL2BounceApp_send_clock_timer_cancel_listener(void (*_listener)(struct SDL2BounceApp_Instance *, uint8_t));
void register_SDL2BounceApp_send_ball_bounce_listener(void (*_listener)(struct SDL2BounceApp_Instance *));
void register_external_SDL2BounceApp_send_ball_bounce_listener(void (*_listener)(struct SDL2BounceApp_Instance *));
void register_SDL2BounceApp_send_ball_stop_listener(void (*_listener)(struct SDL2BounceApp_Instance *));
void register_external_SDL2BounceApp_send_ball_stop_listener(void (*_listener)(struct SDL2BounceApp_Instance *));

// Definition of the states:
#define BOUNCEAPP_SC_STATE 0
#define BOUNCEAPP_SC_WELCOME_STATE 1
#define BOUNCEAPP_SC_BOUNCING_STATE 2



#ifdef __cplusplus
}
#endif

#endif //SDL2BounceApp_H_
