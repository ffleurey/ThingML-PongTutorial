/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing BrowserCanvasDisplay
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef BrowserCanvasDisplay_H_
#define BrowserCanvasDisplay_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : BrowserCanvasDisplay
 *****************************************************************************/

// Definition of the instance struct:
struct BrowserCanvasDisplay_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_vctrl;
uint16_t id_display;
// Variables for the current instance state
int Display_SC_State;
// Variables for the properties of the instance
uint8_t BrowserCanvasDisplay_SCALE_var;
Canvas BrowserCanvasDisplay_BufferCanvas_var;
uint16_t BrowserCanvasDisplay_YFRAMESIZE_var;
uint8_t Display_bg_b_var;
uint16_t BrowserCanvasDisplay_XFRAMESIZE_var;
uint8_t Display_bg_g_var;
CanvasContext BrowserCanvasDisplay_Display_var;
CanvasContext BrowserCanvasDisplay_Buffer_var;
uint8_t Display_fg_g_var;
uint8_t Display_fg_r_var;
uint8_t Display_fg_b_var;
uint8_t Display_bg_r_var;

};
// Declaration of prototypes outgoing messages:
void Display_SC_OnEntry(int state, struct BrowserCanvasDisplay_Instance *_instance);
void BrowserCanvasDisplay_handle_display_drawInteger(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void BrowserCanvasDisplay_handle_display_setBGColor(struct BrowserCanvasDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void BrowserCanvasDisplay_handle_display_drawRect(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void BrowserCanvasDisplay_handle_display_setColor(struct BrowserCanvasDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void BrowserCanvasDisplay_handle_display_clear(struct BrowserCanvasDisplay_Instance *_instance);
void BrowserCanvasDisplay_handle_display_create(struct BrowserCanvasDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize);
void BrowserCanvasDisplay_handle_display_destroy(struct BrowserCanvasDisplay_Instance *_instance);
void BrowserCanvasDisplay_handle_display_fillRect(struct BrowserCanvasDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void BrowserCanvasDisplay_handle_display_update(struct BrowserCanvasDisplay_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_BrowserCanvasDisplay_send_vctrl_fire_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *, uint8_t));
void register_external_BrowserCanvasDisplay_send_vctrl_fire_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *, uint8_t));
void register_BrowserCanvasDisplay_send_vctrl_velocity_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *, int16_t, int16_t));
void register_external_BrowserCanvasDisplay_send_vctrl_velocity_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *, int16_t, int16_t));
void register_BrowserCanvasDisplay_send_display_displayReady_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *));
void register_external_BrowserCanvasDisplay_send_display_displayReady_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *));
void register_BrowserCanvasDisplay_send_display_displayError_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *));
void register_external_BrowserCanvasDisplay_send_display_displayError_listener(void (*_listener)(struct BrowserCanvasDisplay_Instance *));

// Definition of the states:
#define DISPLAY_SC_STATE 0
#define DISPLAY_SC_WAIT_STATE 1
#define DISPLAY_SC_RUNNING_STATE 2
#define DISPLAY_SC_DESTROYED_STATE 3



#ifdef __cplusplus
}
#endif

#endif //BrowserCanvasDisplay_H_
