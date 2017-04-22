/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing SimpleBrick
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef SimpleBrick_H_
#define SimpleBrick_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : SimpleBrick
 *****************************************************************************/

// Definition of the instance struct:
struct SimpleBrick_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_clock;
uint16_t id_display;
uint16_t id_controller;
uint16_t id_game;
// Variables for the current instance state
int SimpleBrick_SC_State;
// Variables for the properties of the instance
int16_t SimpleBrick_br_var;
uint8_t SimpleBrick_XDISPSIZE_var;
uint16_t SimpleBrick_SCALE_var;
int16_t SimpleBrick_padx_var;
int16_t SimpleBrick_padlen_var;
int16_t SimpleBrick_prevPX_var;
int16_t SimpleBrick_prevPY_var;
int16_t SimpleBrick_prevBX_var;
uint8_t SimpleBrick_lives_var;
uint8_t SimpleBrick_BRICK_ROWS_var;
uint8_t SimpleBrick_YDISPSIZE_var;
int16_t SimpleBrick_BOTTOM_var;
uint8_t * SimpleBrick_bgcolor_var;
uint16_t SimpleBrick_bgcolor_var_size;
uint16_t SimpleBrick_XMAX_var;
uint8_t * SimpleBrick_fgcolor_var;
uint16_t SimpleBrick_fgcolor_var_size;
int16_t SimpleBrick_bx_var;
int16_t SimpleBrick_pady_var;
int16_t SimpleBrick_by_var;
int8_t SimpleBrick_SC_LAUNCH_countdown_var;
uint8_t SimpleBrick_BRICK_HEIGHT_var;
int16_t SimpleBrick_score_var;
int16_t SimpleBrick_dy_var;
int16_t SimpleBrick_prevBY_var;
int16_t SimpleBrick_RIGHT_var;
int16_t SimpleBrick_dx_var;
uint16_t SimpleBrick_YMAX_var;
int16_t SimpleBrick_LEFT_var;
int16_t SimpleBrick_TOP_var;
uint8_t * SimpleBrick_bricks_var;
uint16_t SimpleBrick_bricks_var_size;

};
// Declaration of prototypes outgoing messages:
void SimpleBrick_SC_OnEntry(int state, struct SimpleBrick_Instance *_instance);
void SimpleBrick_handle_controller_position(struct SimpleBrick_Instance *_instance, int16_t x, int16_t y);
void SimpleBrick_handle_clock_timer_timeout(struct SimpleBrick_Instance *_instance, uint8_t id);
void SimpleBrick_handle_display_displayReady(struct SimpleBrick_Instance *_instance);
void SimpleBrick_handle_game_lostBall(struct SimpleBrick_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_SimpleBrick_send_clock_timer_start_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint32_t));
void register_external_SimpleBrick_send_clock_timer_start_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint32_t));
void register_SimpleBrick_send_clock_timer_cancel_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t));
void register_external_SimpleBrick_send_clock_timer_cancel_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t));
void register_SimpleBrick_send_display_create_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t));
void register_external_SimpleBrick_send_display_create_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t));
void register_SimpleBrick_send_display_fillRect_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_external_SimpleBrick_send_display_fillRect_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_SimpleBrick_send_display_drawRect_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_external_SimpleBrick_send_display_drawRect_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t));
void register_SimpleBrick_send_display_clear_listener(void (*_listener)(struct SimpleBrick_Instance *));
void register_external_SimpleBrick_send_display_clear_listener(void (*_listener)(struct SimpleBrick_Instance *));
void register_SimpleBrick_send_display_setColor_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_SimpleBrick_send_display_setColor_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t));
void register_SimpleBrick_send_display_setBGColor_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t));
void register_external_SimpleBrick_send_display_setBGColor_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t));
void register_SimpleBrick_send_display_drawInteger_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t));
void register_external_SimpleBrick_send_display_drawInteger_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t));
void register_SimpleBrick_send_display_update_listener(void (*_listener)(struct SimpleBrick_Instance *));
void register_external_SimpleBrick_send_display_update_listener(void (*_listener)(struct SimpleBrick_Instance *));
void register_SimpleBrick_send_game_lostBall_listener(void (*_listener)(struct SimpleBrick_Instance *));
void register_external_SimpleBrick_send_game_lostBall_listener(void (*_listener)(struct SimpleBrick_Instance *));

// Definition of the states:
#define SIMPLEBRICK_SC_STATE 0
#define SIMPLEBRICK_SC_INIT_STATE 1
#define SIMPLEBRICK_SC_LAUNCH_STATE 2
#define SIMPLEBRICK_SC_PLAY_STATE 3
#define SIMPLEBRICK_SC_LOSTBALL_STATE 4
#define SIMPLEBRICK_SC_GAMEOVER_STATE 5



#ifdef __cplusplus
}
#endif

#endif //SimpleBrick_H_
