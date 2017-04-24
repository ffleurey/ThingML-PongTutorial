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
uint16_t id_ia;
uint16_t id_game;
// Variables for the current instance state
int SimpleBrick_SC_State;
// Variables for the properties of the instance
int16_t SimpleBrick_dx_var;
uint8_t * SimpleBrick_fgcolor_var;
uint16_t SimpleBrick_fgcolor_var_size;
int16_t SimpleBrick_prevBX_var;
int16_t SimpleBrick_XMAX_var;
int16_t SimpleBrick_YMAX_var;
uint8_t SimpleBrick_BRICK_HEIGHT_var;
int16_t SimpleBrick_SCALE_var;
int8_t SimpleBrick_SC_LAUNCH_countdown_var;
uint8_t SimpleBrick_YDISPSIZE_var;
uint8_t * SimpleBrick_bricks_var;
uint16_t SimpleBrick_bricks_var_size;
int16_t SimpleBrick_pady_var;
uint8_t * SimpleBrick_bgcolor_var;
uint16_t SimpleBrick_bgcolor_var_size;
int16_t SimpleBrick_by_var;
int16_t SimpleBrick_LEFT_var;
int16_t SimpleBrick_padx_var;
uint8_t SimpleBrick_lives_var;
int16_t SimpleBrick_BOTTOM_var;
uint8_t SimpleBrick_BRICK_ROWS_var;
uint8_t SimpleBrick_level_var;
int16_t SimpleBrick_prevPY_var;
int16_t SimpleBrick_padlen_var;
int16_t SimpleBrick_RIGHT_var;
int16_t SimpleBrick_dy_var;
int16_t SimpleBrick_bx_var;
int16_t SimpleBrick_prevPX_var;
int16_t SimpleBrick_TOP_var;
int16_t SimpleBrick_prevBY_var;
uint8_t SimpleBrick_XDISPSIZE_var;
int16_t SimpleBrick_br_var;
int16_t SimpleBrick_score_var;

};
// Declaration of prototypes outgoing messages:
void SimpleBrick_SC_OnEntry(int state, struct SimpleBrick_Instance *_instance);
void SimpleBrick_handle_display_displayReady(struct SimpleBrick_Instance *_instance);
void SimpleBrick_handle_clock_timer_timeout(struct SimpleBrick_Instance *_instance, uint8_t id);
void SimpleBrick_handle_controller_position(struct SimpleBrick_Instance *_instance, int16_t x, int16_t y);
void SimpleBrick_handle_game_lostBall(struct SimpleBrick_Instance *_instance);
void SimpleBrick_handle_game_nextLevel(struct SimpleBrick_Instance *_instance);
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
void register_SimpleBrick_send_ia_updateIA_listener(void (*_listener)(struct SimpleBrick_Instance *, int16_t, int16_t, int16_t, int16_t));
void register_external_SimpleBrick_send_ia_updateIA_listener(void (*_listener)(struct SimpleBrick_Instance *, int16_t, int16_t, int16_t, int16_t));
void register_SimpleBrick_send_ia_lostBall_listener(void (*_listener)(struct SimpleBrick_Instance *));
void register_external_SimpleBrick_send_ia_lostBall_listener(void (*_listener)(struct SimpleBrick_Instance *));
void register_SimpleBrick_send_ia_hitBall_listener(void (*_listener)(struct SimpleBrick_Instance *));
void register_external_SimpleBrick_send_ia_hitBall_listener(void (*_listener)(struct SimpleBrick_Instance *));
void register_SimpleBrick_send_game_lostBall_listener(void (*_listener)(struct SimpleBrick_Instance *));
void register_external_SimpleBrick_send_game_lostBall_listener(void (*_listener)(struct SimpleBrick_Instance *));
void register_SimpleBrick_send_game_nextLevel_listener(void (*_listener)(struct SimpleBrick_Instance *));
void register_external_SimpleBrick_send_game_nextLevel_listener(void (*_listener)(struct SimpleBrick_Instance *));

// Definition of the states:
#define SIMPLEBRICK_SC_STATE 0
#define SIMPLEBRICK_SC_INIT_STATE 1
#define SIMPLEBRICK_SC_LAUNCH_STATE 2
#define SIMPLEBRICK_SC_PLAY_STATE 3
#define SIMPLEBRICK_SC_LOSTBALL_STATE 4
#define SIMPLEBRICK_SC_NEXTLEVEL_STATE 5
#define SIMPLEBRICK_SC_GAMEOVER_STATE 6


/*****************************************************************************
 * Headers for type : ArduinoDisplay
 *****************************************************************************/


// BEGIN: Code from the c_header annotation ArduinoDisplay

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#define TFT_CS     10
#define TFT_RST    9
#define TFT_DC     8
// END: Code from the c_header annotation ArduinoDisplay

// Definition of the instance struct:
struct ArduinoDisplay_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_display;
// Variables for the current instance state
int Display_SC_State;
// Variables for the properties of the instance
uint16_t ArduinoDisplay_XFRAMESIZE_var;
uint8_t Display_bg_r_var;
uint8_t Display_bg_b_var;
uint8_t Display_fg_b_var;
uint16_t ArduinoDisplay_YFRAMESIZE_var;
uint8_t Display_bg_g_var;
uint8_t Display_fg_r_var;
uint16_t ArduinoDisplay_color_var;
uint8_t Display_fg_g_var;

};
// Declaration of prototypes outgoing messages:
void Display_SC_OnEntry(int state, struct ArduinoDisplay_Instance *_instance);
void ArduinoDisplay_handle_display_clear(struct ArduinoDisplay_Instance *_instance);
void ArduinoDisplay_handle_display_create(struct ArduinoDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize);
void ArduinoDisplay_handle_display_drawRect(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void ArduinoDisplay_handle_display_drawInteger(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void ArduinoDisplay_handle_display_setColor(struct ArduinoDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void ArduinoDisplay_handle_display_fillRect(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void ArduinoDisplay_handle_display_destroy(struct ArduinoDisplay_Instance *_instance);
void ArduinoDisplay_handle_display_setBGColor(struct ArduinoDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void ArduinoDisplay_handle_display_update(struct ArduinoDisplay_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_ArduinoDisplay_send_display_displayReady_listener(void (*_listener)(struct ArduinoDisplay_Instance *));
void register_external_ArduinoDisplay_send_display_displayReady_listener(void (*_listener)(struct ArduinoDisplay_Instance *));
void register_ArduinoDisplay_send_display_displayError_listener(void (*_listener)(struct ArduinoDisplay_Instance *));
void register_external_ArduinoDisplay_send_display_displayError_listener(void (*_listener)(struct ArduinoDisplay_Instance *));

// Definition of the states:
#define DISPLAY_SC_STATE 0
#define DISPLAY_SC_WAIT_STATE 1
#define DISPLAY_SC_RUNNING_STATE 2
#define DISPLAY_SC_DESTROYED_STATE 3


//timer2

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


/* Adds and instance to the runtime and returns its id */
uint16_t add_instance(void * instance_struct);
/* Returns the instance with id */
void * instance_by_id(uint16_t id);

/* Returns the number of byte currently in the fifo */
int fifo_byte_length();
/* Returns the number of bytes currently available in the fifo */
int fifo_byte_available();
/* Returns true if the fifo is empty */
int fifo_empty();
/* Return true if the fifo is full */
int fifo_full();
/* Enqueue 1 byte in the fifo if there is space
   returns 1 for sucess and 0 if the fifo was full */
int fifo_enqueue(byte b);
/* Enqueue 1 byte in the fifo without checking for available space
   The caller should have checked that there is enough space */
int _fifo_enqueue(byte b);
/* Dequeue 1 byte in the fifo.
   The caller should check that the fifo is not empty */
byte fifo_dequeue();

#define MAX_INSTANCES 9
#define FIFO_SIZE 256

/*********************************
 * Instance IDs and lookup
 *********************************/

void * instances[MAX_INSTANCES];
uint16_t instances_count = 0;

void * instance_by_id(uint16_t id) {
  return instances[id];
}

uint16_t add_instance(void * instance_struct) {
  instances[instances_count] = instance_struct;
  return instances_count++;
}

/******************************************
 * Simple byte FIFO implementation
 ******************************************/

byte fifo[FIFO_SIZE];
int fifo_head = 0;
int fifo_tail = 0;

// Returns the number of byte currently in the fifo
int fifo_byte_length() {
  if (fifo_tail >= fifo_head)
    return fifo_tail - fifo_head;
  return fifo_tail + FIFO_SIZE - fifo_head;
}

// Returns the number of bytes currently available in the fifo
int fifo_byte_available() {
  return FIFO_SIZE - 1 - fifo_byte_length();
}

// Returns true if the fifo is empty
int fifo_empty() {
  return fifo_head == fifo_tail;
}

// Return true if the fifo is full
int fifo_full() {
  return fifo_head == ((fifo_tail + 1) % FIFO_SIZE);
}

// Enqueue 1 byte in the fifo if there is space
// returns 1 for sucess and 0 if the fifo was full
int fifo_enqueue(byte b) {
  int new_tail = (fifo_tail + 1) % FIFO_SIZE;
  if (new_tail == fifo_head) return 0; // the fifo is full
  fifo[fifo_tail] = b;
  fifo_tail = new_tail;
  return 1;
}

// Enqueue 1 byte in the fifo without checking for available space
// The caller should have checked that there is enough space
int _fifo_enqueue(byte b) {
  fifo[fifo_tail] = b;
  fifo_tail = (fifo_tail + 1) % FIFO_SIZE;
  return 0; // Dummy added by steffend
}

// Dequeue 1 byte in the fifo.
// The caller should check that the fifo is not empty
byte fifo_dequeue() {
  if (!fifo_empty()) {
    byte result = fifo[fifo_head];
    fifo_head = (fifo_head + 1) % FIFO_SIZE;
    return result;
  }
  return 0;
}

/*****************************************************************************
 * Implementation for type : BasicIAController
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void BasicIAController_SC_OnExit(int state, struct BasicIAController_Instance *_instance);
//Prototypes: Message Sending
void BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y);
void BasicIAController_send_controls_fire(struct BasicIAController_Instance *_instance, uint8_t id);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void BasicIAController_SC_OnEntry(int state, struct BasicIAController_Instance *_instance) {
switch(state) {
case BASICIACONTROLLER_SC_STATE:{
_instance->BasicIAController_SC_State = BASICIACONTROLLER_SC_FOLLOWING_STATE;
BasicIAController_SC_OnEntry(_instance->BasicIAController_SC_State, _instance);
break;
}
case BASICIACONTROLLER_SC_FOLLOWING_STATE:{
BasicIAController_send_controls_position(_instance, _instance->BasicIAController_ctrlx_var, 0);
break;
}
default: break;
}
}

// On Exit Actions:
void BasicIAController_SC_OnExit(int state, struct BasicIAController_Instance *_instance) {
switch(state) {
case BASICIACONTROLLER_SC_STATE:{
BasicIAController_SC_OnExit(_instance->BasicIAController_SC_State, _instance);
break;}
case BASICIACONTROLLER_SC_FOLLOWING_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void BasicIAController_handle_game_updateIA(struct BasicIAController_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady) {
if(!(_instance->active)) return;
//Region SC
uint8_t BasicIAController_SC_State_event_consumed = 0;
if (_instance->BasicIAController_SC_State == BASICIACONTROLLER_SC_FOLLOWING_STATE) {
if (BasicIAController_SC_State_event_consumed == 0 && 1) {
BasicIAController_SC_OnExit(BASICIACONTROLLER_SC_FOLLOWING_STATE, _instance);
_instance->BasicIAController_SC_State = BASICIACONTROLLER_SC_FOLLOWING_STATE;
if(ballx > padx + 300) {
_instance->BasicIAController_ctrlx_var = _instance->BasicIAController_ctrlx_var + 4;

} else {
if(ballx < padx - 300) {
_instance->BasicIAController_ctrlx_var = _instance->BasicIAController_ctrlx_var - 4;

}

}
if(_instance->BasicIAController_ctrlx_var <  -100) {
_instance->BasicIAController_ctrlx_var =  -100;

} else {
if(_instance->BasicIAController_ctrlx_var > 100) {
_instance->BasicIAController_ctrlx_var = 100;

}

}
BasicIAController_SC_OnEntry(BASICIACONTROLLER_SC_FOLLOWING_STATE, _instance);
BasicIAController_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
void (*external_BasicIAController_send_controls_position_listener)(struct BasicIAController_Instance *, int16_t, int16_t)= 0x0;
void (*BasicIAController_send_controls_position_listener)(struct BasicIAController_Instance *, int16_t, int16_t)= 0x0;
void register_external_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t)){
external_BasicIAController_send_controls_position_listener = _listener;
}
void register_BasicIAController_send_controls_position_listener(void (*_listener)(struct BasicIAController_Instance *, int16_t, int16_t)){
BasicIAController_send_controls_position_listener = _listener;
}
void BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y){
if (BasicIAController_send_controls_position_listener != 0x0) BasicIAController_send_controls_position_listener(_instance, x, y);
if (external_BasicIAController_send_controls_position_listener != 0x0) external_BasicIAController_send_controls_position_listener(_instance, x, y);
;
}
void (*external_BasicIAController_send_controls_fire_listener)(struct BasicIAController_Instance *, uint8_t)= 0x0;
void (*BasicIAController_send_controls_fire_listener)(struct BasicIAController_Instance *, uint8_t)= 0x0;
void register_external_BasicIAController_send_controls_fire_listener(void (*_listener)(struct BasicIAController_Instance *, uint8_t)){
external_BasicIAController_send_controls_fire_listener = _listener;
}
void register_BasicIAController_send_controls_fire_listener(void (*_listener)(struct BasicIAController_Instance *, uint8_t)){
BasicIAController_send_controls_fire_listener = _listener;
}
void BasicIAController_send_controls_fire(struct BasicIAController_Instance *_instance, uint8_t id){
if (BasicIAController_send_controls_fire_listener != 0x0) BasicIAController_send_controls_fire_listener(_instance, id);
if (external_BasicIAController_send_controls_fire_listener != 0x0) external_BasicIAController_send_controls_fire_listener(_instance, id);
;
}



#define timer2_NB_SOFT_TIMER 4
uint32_t timer2_timer[timer2_NB_SOFT_TIMER];
uint32_t  timer2_prev_1sec = 0;



void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id);

uint8_t timer2_interrupt_counter = 0;
SIGNAL(TIMER2_OVF_vect) {
TCNT2 = 5;
timer2_interrupt_counter++;
if(timer2_interrupt_counter >= 0) {
timer2_interrupt_counter = 0;
}
}



struct timer2_instance_type {
    uint16_t listener_id;
    /*INSTANCE_INFORMATION*/
} timer2_instance;

void timer2_setup() {
	// Run timer2 interrupt up counting at 250kHz 
		 TCCR2A = 0;
		 TCCR2B = 1<<CS22 | 0<<CS21 | 0<<CS20;
		
		 //Timer2 Overflow Interrupt Enable
		 TIMSK2 |= 1<<TOIE2;


	timer2_prev_1sec = millis() + 1000;
}

void timer2_set_listener_id(uint16_t id) {
	timer2_instance.listener_id = id;
}

void timer2_timer_start(uint8_t id, uint32_t ms) {
if(id <timer2_NB_SOFT_TIMER) {
timer2_timer[id] = ms + millis();
}
}

void timer2_timer_cancel(uint8_t id) {
if(id <timer2_NB_SOFT_TIMER) {
timer2_timer[id] = 0;
}
}

void timer2_timeout(uint8_t id) {
uint8_t enqueue_buf[3];
enqueue_buf[0] = (1 >> 8) & 0xFF;
enqueue_buf[1] = 1 & 0xFF;
enqueue_buf[2] = id;
externalMessageEnqueue(enqueue_buf, 3, timer2_instance.listener_id);
}





void timer2_read() {
    uint32_t tms = millis();
    uint8_t t;
for(t = 0; t < 4; t++) {
if((timer2_timer[t] > 0) && (timer2_timer[t] < tms)) {
timer2_timer[t] = 0;
timer2_timeout(t);
}
}

    if (timer2_prev_1sec < tms) {
        timer2_prev_1sec += 1000;
    }
    
}
// Forwarding of messages timer2::SimpleBrick::clock::timer_start
void forward_timer2_SimpleBrick_send_clock_timer_start(struct SimpleBrick_Instance *_instance, uint8_t id, uint32_t time){
timer2_timer_start(id, time);}

// Forwarding of messages timer2::SimpleBrick::clock::timer_cancel
void forward_timer2_SimpleBrick_send_clock_timer_cancel(struct SimpleBrick_Instance *_instance, uint8_t id){
timer2_timer_cancel(id);}

/*****************************************************************************
 * Implementation for type : SimpleBrick
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void SimpleBrick_SC_OnExit(int state, struct SimpleBrick_Instance *_instance);
//Prototypes: Message Sending
void SimpleBrick_send_clock_timer_start(struct SimpleBrick_Instance *_instance, uint8_t id, uint32_t time);
void SimpleBrick_send_clock_timer_cancel(struct SimpleBrick_Instance *_instance, uint8_t id);
void SimpleBrick_send_display_create(struct SimpleBrick_Instance *_instance, uint8_t xsize, uint8_t ysize);
void SimpleBrick_send_display_fillRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void SimpleBrick_send_display_drawRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void SimpleBrick_send_display_clear(struct SimpleBrick_Instance *_instance);
void SimpleBrick_send_display_setColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void SimpleBrick_send_display_setBGColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void SimpleBrick_send_display_drawInteger(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void SimpleBrick_send_display_update(struct SimpleBrick_Instance *_instance);
void SimpleBrick_send_ia_updateIA(struct SimpleBrick_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady);
void SimpleBrick_send_ia_lostBall(struct SimpleBrick_Instance *_instance);
void SimpleBrick_send_ia_hitBall(struct SimpleBrick_Instance *_instance);
void SimpleBrick_send_game_lostBall(struct SimpleBrick_Instance *_instance);
void SimpleBrick_send_game_nextLevel(struct SimpleBrick_Instance *_instance);
//Prototypes: Function
void f_SimpleBrick_initColors(struct SimpleBrick_Instance *_instance);
void f_SimpleBrick_resetBall(struct SimpleBrick_Instance *_instance);
void f_SimpleBrick_eraseBall(struct SimpleBrick_Instance *_instance);
void f_SimpleBrick_drawBall(struct SimpleBrick_Instance *_instance);
void f_SimpleBrick_erasePad(struct SimpleBrick_Instance *_instance);
void f_SimpleBrick_drawPad(struct SimpleBrick_Instance *_instance);
void f_SimpleBrick_drawCountDown(struct SimpleBrick_Instance *_instance, uint8_t c);
void f_SimpleBrick_drawWalls(struct SimpleBrick_Instance *_instance);
uint8_t f_SimpleBrick_bitIsSet(struct SimpleBrick_Instance *_instance, uint8_t variable, uint8_t bit);
uint8_t f_SimpleBrick_setBit(struct SimpleBrick_Instance *_instance, uint8_t variable, uint8_t bit);
uint8_t f_SimpleBrick_unsetBit(struct SimpleBrick_Instance *_instance, uint8_t variable, uint8_t bit);
void f_SimpleBrick_createBricks(struct SimpleBrick_Instance *_instance);
uint8_t f_SimpleBrick_bricksLeft(struct SimpleBrick_Instance *_instance);
void f_SimpleBrick_drawBrick(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y);
void f_SimpleBrick_removeBrick(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y);
uint8_t f_SimpleBrick_collideBrick(struct SimpleBrick_Instance *_instance, int16_t xpos, int16_t ypos);
void f_SimpleBrick_drawScore(struct SimpleBrick_Instance *_instance);
void f_SimpleBrick_drawLives(struct SimpleBrick_Instance *_instance);
// Declaration of functions:
// Definition of function initColors
void f_SimpleBrick_initColors(struct SimpleBrick_Instance *_instance) {
_instance->SimpleBrick_bgcolor_var[0] = 53;
_instance->SimpleBrick_bgcolor_var[1] = 40;
_instance->SimpleBrick_bgcolor_var[2] = 120;
_instance->SimpleBrick_fgcolor_var[0] = 107;
_instance->SimpleBrick_fgcolor_var[1] = 94;
_instance->SimpleBrick_fgcolor_var[2] = 174;
SimpleBrick_send_display_setBGColor(_instance, _instance->SimpleBrick_bgcolor_var[0]
, _instance->SimpleBrick_bgcolor_var[1]
, _instance->SimpleBrick_bgcolor_var[2]
);
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_fgcolor_var[0]
, _instance->SimpleBrick_fgcolor_var[1]
, _instance->SimpleBrick_fgcolor_var[2]
);
}
// Definition of function resetBall
void f_SimpleBrick_resetBall(struct SimpleBrick_Instance *_instance) {
_instance->SimpleBrick_bx_var = _instance->SimpleBrick_padx_var - _instance->SimpleBrick_br_var / _instance->SimpleBrick_SCALE_var;
_instance->SimpleBrick_by_var = _instance->SimpleBrick_pady_var - _instance->SimpleBrick_br_var / _instance->SimpleBrick_SCALE_var;
_instance->SimpleBrick_dx_var = _instance->SimpleBrick_XMAX_var / 98;
_instance->SimpleBrick_dy_var =  -_instance->SimpleBrick_XMAX_var / 65;
}
// Definition of function eraseBall
void f_SimpleBrick_eraseBall(struct SimpleBrick_Instance *_instance) {
;uint8_t bs = (_instance->SimpleBrick_br_var * 2) / _instance->SimpleBrick_SCALE_var;
if(_instance->SimpleBrick_prevBX_var > 0) {
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_bgcolor_var[0]
, _instance->SimpleBrick_bgcolor_var[1]
, _instance->SimpleBrick_bgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_prevBX_var, _instance->SimpleBrick_prevBY_var, bs, bs);

}
}
// Definition of function drawBall
void f_SimpleBrick_drawBall(struct SimpleBrick_Instance *_instance) {
;uint8_t bs = (_instance->SimpleBrick_br_var * 2) / _instance->SimpleBrick_SCALE_var;
f_SimpleBrick_eraseBall(_instance);
_instance->SimpleBrick_prevBX_var = (_instance->SimpleBrick_bx_var - _instance->SimpleBrick_br_var) / _instance->SimpleBrick_SCALE_var;
_instance->SimpleBrick_prevBY_var = (_instance->SimpleBrick_by_var - _instance->SimpleBrick_br_var) / _instance->SimpleBrick_SCALE_var;
SimpleBrick_send_display_setColor(_instance, 183, 199, 111);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_prevBX_var, _instance->SimpleBrick_prevBY_var, bs, bs);
}
// Definition of function erasePad
void f_SimpleBrick_erasePad(struct SimpleBrick_Instance *_instance) {
;uint8_t ps = _instance->SimpleBrick_padlen_var / _instance->SimpleBrick_SCALE_var;
if(_instance->SimpleBrick_prevPX_var > 0) {
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_bgcolor_var[0]
, _instance->SimpleBrick_bgcolor_var[1]
, _instance->SimpleBrick_bgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_prevPX_var, _instance->SimpleBrick_prevPY_var, ps, 4);

}
}
// Definition of function drawPad
void f_SimpleBrick_drawPad(struct SimpleBrick_Instance *_instance) {
;uint8_t ps = _instance->SimpleBrick_padlen_var / _instance->SimpleBrick_SCALE_var;
f_SimpleBrick_erasePad(_instance);
_instance->SimpleBrick_prevPX_var = (_instance->SimpleBrick_padx_var - (_instance->SimpleBrick_padlen_var / 2)) / _instance->SimpleBrick_SCALE_var;
_instance->SimpleBrick_prevPY_var = _instance->SimpleBrick_pady_var / _instance->SimpleBrick_SCALE_var;
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_fgcolor_var[0]
, _instance->SimpleBrick_fgcolor_var[1]
, _instance->SimpleBrick_fgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_prevPX_var, _instance->SimpleBrick_prevPY_var, ps, 4);
}
// Definition of function drawCountDown
void f_SimpleBrick_drawCountDown(struct SimpleBrick_Instance *_instance, uint8_t c) {
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_fgcolor_var[0]
, _instance->SimpleBrick_fgcolor_var[1]
, _instance->SimpleBrick_fgcolor_var[2]
);
if(c > 0) {
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_fgcolor_var[0]
, _instance->SimpleBrick_fgcolor_var[1]
, _instance->SimpleBrick_fgcolor_var[2]
);
SimpleBrick_send_display_setBGColor(_instance, _instance->SimpleBrick_bgcolor_var[0]
, _instance->SimpleBrick_bgcolor_var[1]
, _instance->SimpleBrick_bgcolor_var[2]
);
SimpleBrick_send_display_drawInteger(_instance, 80 - 6, 90, c, 1, 4);

} else {
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_bgcolor_var[0]
, _instance->SimpleBrick_bgcolor_var[1]
, _instance->SimpleBrick_bgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, 80 - 6, 90, 12, 20);

}
}
// Definition of function drawWalls
void f_SimpleBrick_drawWalls(struct SimpleBrick_Instance *_instance) {
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_fgcolor_var[0]
, _instance->SimpleBrick_fgcolor_var[1]
, _instance->SimpleBrick_fgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_LEFT_var / _instance->SimpleBrick_SCALE_var - 1, _instance->SimpleBrick_TOP_var / _instance->SimpleBrick_SCALE_var - 1, (_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / _instance->SimpleBrick_SCALE_var + 1, 1);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_LEFT_var / _instance->SimpleBrick_SCALE_var - 1, _instance->SimpleBrick_BOTTOM_var / _instance->SimpleBrick_SCALE_var - 1, (_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / _instance->SimpleBrick_SCALE_var + 1, 1);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_LEFT_var / _instance->SimpleBrick_SCALE_var - 1, _instance->SimpleBrick_TOP_var / _instance->SimpleBrick_SCALE_var, 1, (_instance->SimpleBrick_BOTTOM_var - _instance->SimpleBrick_TOP_var) / _instance->SimpleBrick_SCALE_var);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_RIGHT_var / _instance->SimpleBrick_SCALE_var - 1, _instance->SimpleBrick_TOP_var / _instance->SimpleBrick_SCALE_var, 1, (_instance->SimpleBrick_BOTTOM_var - _instance->SimpleBrick_TOP_var) / _instance->SimpleBrick_SCALE_var);
}
// Definition of function bitIsSet
uint8_t f_SimpleBrick_bitIsSet(struct SimpleBrick_Instance *_instance, uint8_t variable, uint8_t bit) {
return ((1 << bit) & variable) != 0;
}
// Definition of function setBit
uint8_t f_SimpleBrick_setBit(struct SimpleBrick_Instance *_instance, uint8_t variable, uint8_t bit) {
return variable | (1 << bit);
}
// Definition of function unsetBit
uint8_t f_SimpleBrick_unsetBit(struct SimpleBrick_Instance *_instance, uint8_t variable, uint8_t bit) {
return variable & ~(1 << bit);
}
// Definition of function createBricks
void f_SimpleBrick_createBricks(struct SimpleBrick_Instance *_instance) {
;int8_t y = 0;
while(y < _instance->SimpleBrick_BRICK_ROWS_var) {
_instance->SimpleBrick_bricks_var[y] = 0xFF;
;int8_t x = 0;
while(x < 8) {
if(f_SimpleBrick_bitIsSet(_instance, _instance->SimpleBrick_bricks_var[y]
, x)) {
f_SimpleBrick_drawBrick(_instance, x, y);

}
x = x + 1;

}
y = y + 1;

}
}
// Definition of function bricksLeft
uint8_t f_SimpleBrick_bricksLeft(struct SimpleBrick_Instance *_instance) {
;uint8_t result = 0;
;int8_t y = 0;
while(y < _instance->SimpleBrick_BRICK_ROWS_var) {
;int8_t x = 0;
while(x < 8) {
if(f_SimpleBrick_bitIsSet(_instance, _instance->SimpleBrick_bricks_var[y]
, x)) {
result = result + 1;

}
x = x + 1;

}
y = y + 1;

}
return result;
}
// Definition of function drawBrick
void f_SimpleBrick_drawBrick(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y) {
;int16_t bx = _instance->SimpleBrick_LEFT_var + ((_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 8) * x;
;int16_t by = _instance->SimpleBrick_TOP_var + 20 * _instance->SimpleBrick_SCALE_var + _instance->SimpleBrick_BRICK_HEIGHT_var * y * _instance->SimpleBrick_SCALE_var;
SimpleBrick_send_display_setColor(_instance, 155, 103, 89);
SimpleBrick_send_display_fillRect(_instance, bx / _instance->SimpleBrick_SCALE_var + 1, by / _instance->SimpleBrick_SCALE_var + 1, ((_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 8) / _instance->SimpleBrick_SCALE_var - 2, _instance->SimpleBrick_BRICK_HEIGHT_var - 2);
SimpleBrick_send_display_setColor(_instance, 100, 56, 43);
SimpleBrick_send_display_drawRect(_instance, bx / _instance->SimpleBrick_SCALE_var + 1, by / _instance->SimpleBrick_SCALE_var + 1, ((_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 8) / _instance->SimpleBrick_SCALE_var - 2, _instance->SimpleBrick_BRICK_HEIGHT_var - 2);
}
// Definition of function removeBrick
void f_SimpleBrick_removeBrick(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y) {
;int16_t bx = _instance->SimpleBrick_LEFT_var + ((_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 8) * x;
;int16_t by = _instance->SimpleBrick_TOP_var + 20 * _instance->SimpleBrick_SCALE_var + _instance->SimpleBrick_BRICK_HEIGHT_var * y * _instance->SimpleBrick_SCALE_var;
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_bgcolor_var[0]
, _instance->SimpleBrick_bgcolor_var[1]
, _instance->SimpleBrick_bgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, bx / _instance->SimpleBrick_SCALE_var + 1, by / _instance->SimpleBrick_SCALE_var + 1, ((_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 8) / _instance->SimpleBrick_SCALE_var - 2, _instance->SimpleBrick_BRICK_HEIGHT_var - 2);
_instance->SimpleBrick_bricks_var[y] = f_SimpleBrick_unsetBit(_instance, _instance->SimpleBrick_bricks_var[y]
, x);
}
// Definition of function collideBrick
uint8_t f_SimpleBrick_collideBrick(struct SimpleBrick_Instance *_instance, int16_t xpos, int16_t ypos) {
;int8_t bry = (ypos - _instance->SimpleBrick_TOP_var - 20 * _instance->SimpleBrick_SCALE_var) / (_instance->SimpleBrick_BRICK_HEIGHT_var * _instance->SimpleBrick_SCALE_var);
;uint8_t result = 0;
if(bry >= 0 && bry < _instance->SimpleBrick_BRICK_ROWS_var) {
;int8_t brx = (xpos - _instance->SimpleBrick_LEFT_var) / ((_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 8);
if(f_SimpleBrick_bitIsSet(_instance, _instance->SimpleBrick_bricks_var[bry]
, brx)) {
f_SimpleBrick_removeBrick(_instance, brx, bry);
result = 1;

}

}
return result;
}
// Definition of function drawScore
void f_SimpleBrick_drawScore(struct SimpleBrick_Instance *_instance) {
SimpleBrick_send_display_setColor(_instance, 158, 209, 130);
SimpleBrick_send_display_drawInteger(_instance, 98, 2, _instance->SimpleBrick_score_var, 5, 2);
}
// Definition of function drawLives
void f_SimpleBrick_drawLives(struct SimpleBrick_Instance *_instance) {
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_bgcolor_var[0]
, _instance->SimpleBrick_bgcolor_var[1]
, _instance->SimpleBrick_bgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, 22, 4, 36, 6);
SimpleBrick_send_display_setColor(_instance, 183, 199, 111);
;uint8_t i = 0;
while(i < _instance->SimpleBrick_lives_var) {
SimpleBrick_send_display_fillRect(_instance, 22 + i * 15, 4, 6, 6);
i = i + 1;

}
}

// Sessions functionss:


// On Entry Actions:
void SimpleBrick_SC_OnEntry(int state, struct SimpleBrick_Instance *_instance) {
switch(state) {
case SIMPLEBRICK_SC_STATE:{
_instance->SimpleBrick_SC_State = SIMPLEBRICK_SC_INIT_STATE;
SimpleBrick_SC_OnEntry(_instance->SimpleBrick_SC_State, _instance);
break;
}
case SIMPLEBRICK_SC_INIT_STATE:{
SimpleBrick_send_display_create(_instance, _instance->SimpleBrick_XDISPSIZE_var, _instance->SimpleBrick_YDISPSIZE_var);
break;
}
case SIMPLEBRICK_SC_LAUNCH_STATE:{
SimpleBrick_send_clock_timer_start(_instance, 0, 33);
_instance->SimpleBrick_SC_LAUNCH_countdown_var = 30 * 3;
f_SimpleBrick_drawScore(_instance);
f_SimpleBrick_drawLives(_instance);
SimpleBrick_send_display_update(_instance);
break;
}
case SIMPLEBRICK_SC_PLAY_STATE:{
SimpleBrick_send_clock_timer_start(_instance, 0, 33);
break;
}
case SIMPLEBRICK_SC_LOSTBALL_STATE:{
SimpleBrick_send_clock_timer_start(_instance, 0, 1000);
_instance->SimpleBrick_lives_var = _instance->SimpleBrick_lives_var - 1;
f_SimpleBrick_eraseBall(_instance);
f_SimpleBrick_erasePad(_instance);
f_SimpleBrick_drawLives(_instance);
SimpleBrick_send_display_update(_instance);
break;
}
case SIMPLEBRICK_SC_NEXTLEVEL_STATE:{
SimpleBrick_send_clock_timer_start(_instance, 0, 1000);
_instance->SimpleBrick_level_var = _instance->SimpleBrick_level_var + 1;
f_SimpleBrick_eraseBall(_instance);
f_SimpleBrick_erasePad(_instance);
f_SimpleBrick_drawLives(_instance);
f_SimpleBrick_createBricks(_instance);
SimpleBrick_send_display_update(_instance);
break;
}
case SIMPLEBRICK_SC_GAMEOVER_STATE:{
SimpleBrick_send_clock_timer_start(_instance, 0, 500);
_instance->SimpleBrick_lives_var = _instance->SimpleBrick_lives_var - 1;
f_SimpleBrick_eraseBall(_instance);
f_SimpleBrick_erasePad(_instance);
SimpleBrick_send_display_setColor(_instance, 255, 255, 255);
SimpleBrick_send_display_drawRect(_instance, 10, 46, 140, 50);
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_fgcolor_var[0]
, _instance->SimpleBrick_fgcolor_var[1]
, _instance->SimpleBrick_fgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, 11, 47, 138, 48);
SimpleBrick_send_display_setBGColor(_instance, _instance->SimpleBrick_fgcolor_var[0]
, _instance->SimpleBrick_fgcolor_var[1]
, _instance->SimpleBrick_fgcolor_var[2]
);
SimpleBrick_send_display_setColor(_instance, 158, 209, 130);
SimpleBrick_send_display_drawInteger(_instance, 23, 56, _instance->SimpleBrick_score_var, 5, 6);
SimpleBrick_send_display_update(_instance);
break;
}
default: break;
}
}

// On Exit Actions:
void SimpleBrick_SC_OnExit(int state, struct SimpleBrick_Instance *_instance) {
switch(state) {
case SIMPLEBRICK_SC_STATE:{
SimpleBrick_SC_OnExit(_instance->SimpleBrick_SC_State, _instance);
break;}
case SIMPLEBRICK_SC_INIT_STATE:{
break;}
case SIMPLEBRICK_SC_LAUNCH_STATE:{
break;}
case SIMPLEBRICK_SC_PLAY_STATE:{
break;}
case SIMPLEBRICK_SC_LOSTBALL_STATE:{
break;}
case SIMPLEBRICK_SC_NEXTLEVEL_STATE:{
break;}
case SIMPLEBRICK_SC_GAMEOVER_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void SimpleBrick_handle_display_displayReady(struct SimpleBrick_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t SimpleBrick_SC_State_event_consumed = 0;
if (_instance->SimpleBrick_SC_State == SIMPLEBRICK_SC_INIT_STATE) {
if (SimpleBrick_SC_State_event_consumed == 0 && 1) {
SimpleBrick_SC_OnExit(SIMPLEBRICK_SC_INIT_STATE, _instance);
_instance->SimpleBrick_SC_State = SIMPLEBRICK_SC_LAUNCH_STATE;
SimpleBrick_send_display_clear(_instance);
f_SimpleBrick_initColors(_instance);
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_bgcolor_var[0]
, _instance->SimpleBrick_bgcolor_var[1]
, _instance->SimpleBrick_bgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, 0, 0, _instance->SimpleBrick_XDISPSIZE_var, _instance->SimpleBrick_YDISPSIZE_var);
SimpleBrick_send_display_setColor(_instance, _instance->SimpleBrick_fgcolor_var[0]
, _instance->SimpleBrick_fgcolor_var[1]
, _instance->SimpleBrick_fgcolor_var[2]
);
SimpleBrick_send_display_fillRect(_instance, 0, 0, _instance->SimpleBrick_XDISPSIZE_var, 1);
SimpleBrick_send_display_fillRect(_instance, 0, 0, 18, 14);
SimpleBrick_send_display_fillRect(_instance, 90 - 28, 0, 28, 14);
SimpleBrick_send_display_fillRect(_instance, _instance->SimpleBrick_XDISPSIZE_var - 18, 0, 18, 14);
f_SimpleBrick_drawWalls(_instance);
f_SimpleBrick_createBricks(_instance);
SimpleBrick_SC_OnEntry(SIMPLEBRICK_SC_LAUNCH_STATE, _instance);
SimpleBrick_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SimpleBrick_handle_clock_timer_timeout(struct SimpleBrick_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SC
uint8_t SimpleBrick_SC_State_event_consumed = 0;
if (_instance->SimpleBrick_SC_State == SIMPLEBRICK_SC_LAUNCH_STATE) {
if (SimpleBrick_SC_State_event_consumed == 0 && id == 0 && _instance->SimpleBrick_SC_LAUNCH_countdown_var == 0) {
SimpleBrick_SC_OnExit(SIMPLEBRICK_SC_LAUNCH_STATE, _instance);
_instance->SimpleBrick_SC_State = SIMPLEBRICK_SC_PLAY_STATE;
f_SimpleBrick_drawCountDown(_instance, 0);
f_SimpleBrick_resetBall(_instance);
SimpleBrick_send_display_update(_instance);
SimpleBrick_SC_OnEntry(SIMPLEBRICK_SC_PLAY_STATE, _instance);
SimpleBrick_SC_State_event_consumed = 1;
}
else if (SimpleBrick_SC_State_event_consumed == 0 && id == 0 && _instance->SimpleBrick_SC_LAUNCH_countdown_var > 0) {
SimpleBrick_send_clock_timer_start(_instance, 0, 33);
f_SimpleBrick_drawPad(_instance);
f_SimpleBrick_drawCountDown(_instance, _instance->SimpleBrick_SC_LAUNCH_countdown_var / 30 + 1);
_instance->SimpleBrick_SC_LAUNCH_countdown_var = _instance->SimpleBrick_SC_LAUNCH_countdown_var - 1;
SimpleBrick_send_display_update(_instance);
SimpleBrick_SC_State_event_consumed = 1;
}
}
else if (_instance->SimpleBrick_SC_State == SIMPLEBRICK_SC_PLAY_STATE) {
if (SimpleBrick_SC_State_event_consumed == 0 && id == 0) {
_instance->SimpleBrick_bx_var = _instance->SimpleBrick_bx_var + _instance->SimpleBrick_dx_var;
_instance->SimpleBrick_by_var = _instance->SimpleBrick_by_var + _instance->SimpleBrick_dy_var;
;uint16_t wl = _instance->SimpleBrick_LEFT_var + _instance->SimpleBrick_br_var;
;uint16_t wr = _instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_br_var;
;uint16_t wt = _instance->SimpleBrick_TOP_var + _instance->SimpleBrick_br_var;
;uint16_t wb = _instance->SimpleBrick_BOTTOM_var - _instance->SimpleBrick_br_var;
if(_instance->SimpleBrick_bx_var < wl) {
_instance->SimpleBrick_dx_var =  -_instance->SimpleBrick_dx_var;
_instance->SimpleBrick_bx_var = 2 * wl - _instance->SimpleBrick_bx_var;

} else {
if(_instance->SimpleBrick_bx_var > wr) {
_instance->SimpleBrick_dx_var =  -_instance->SimpleBrick_dx_var;
_instance->SimpleBrick_bx_var = 2 * wr - _instance->SimpleBrick_bx_var;

}

}
if(_instance->SimpleBrick_by_var < wt) {
_instance->SimpleBrick_dy_var =  -_instance->SimpleBrick_dy_var;
_instance->SimpleBrick_by_var = 2 * wt - _instance->SimpleBrick_by_var;

} else {
if(_instance->SimpleBrick_by_var > wb) {
SimpleBrick_send_game_lostBall(_instance);

}

}
if(_instance->SimpleBrick_dy_var > 0) {
if(_instance->SimpleBrick_by_var > _instance->SimpleBrick_pady_var - _instance->SimpleBrick_br_var && _instance->SimpleBrick_by_var < _instance->SimpleBrick_pady_var + _instance->SimpleBrick_br_var) {
if(_instance->SimpleBrick_bx_var > _instance->SimpleBrick_padx_var - _instance->SimpleBrick_padlen_var / 2 && _instance->SimpleBrick_bx_var < _instance->SimpleBrick_padx_var + _instance->SimpleBrick_padlen_var / 2) {
_instance->SimpleBrick_dy_var =  -_instance->SimpleBrick_dy_var;
_instance->SimpleBrick_by_var = 2 * (_instance->SimpleBrick_pady_var - _instance->SimpleBrick_br_var) - _instance->SimpleBrick_by_var;
_instance->SimpleBrick_dx_var = _instance->SimpleBrick_dx_var / 4 + (_instance->SimpleBrick_bx_var - _instance->SimpleBrick_padx_var) / 4;

}

}

}
;uint8_t collision = f_SimpleBrick_collideBrick(_instance, _instance->SimpleBrick_bx_var - _instance->SimpleBrick_br_var, _instance->SimpleBrick_by_var - _instance->SimpleBrick_br_var) || f_SimpleBrick_collideBrick(_instance, _instance->SimpleBrick_bx_var + _instance->SimpleBrick_br_var, _instance->SimpleBrick_by_var - _instance->SimpleBrick_br_var) || f_SimpleBrick_collideBrick(_instance, _instance->SimpleBrick_bx_var + _instance->SimpleBrick_br_var, _instance->SimpleBrick_by_var + _instance->SimpleBrick_br_var) || f_SimpleBrick_collideBrick(_instance, _instance->SimpleBrick_bx_var - _instance->SimpleBrick_br_var, _instance->SimpleBrick_by_var + _instance->SimpleBrick_br_var);
if(collision) {
_instance->SimpleBrick_dy_var =  -_instance->SimpleBrick_dy_var;
_instance->SimpleBrick_score_var = _instance->SimpleBrick_score_var + 10;
f_SimpleBrick_drawScore(_instance);
if(f_SimpleBrick_bricksLeft(_instance) == 0) {
SimpleBrick_send_game_nextLevel(_instance);

}

}
f_SimpleBrick_drawBall(_instance);
f_SimpleBrick_drawPad(_instance);
SimpleBrick_send_ia_updateIA(_instance, _instance->SimpleBrick_bx_var, _instance->SimpleBrick_by_var, _instance->SimpleBrick_padx_var, _instance->SimpleBrick_pady_var);
SimpleBrick_send_display_update(_instance);
SimpleBrick_send_clock_timer_start(_instance, 0, 33);
SimpleBrick_SC_State_event_consumed = 1;
}
}
else if (_instance->SimpleBrick_SC_State == SIMPLEBRICK_SC_LOSTBALL_STATE) {
if (SimpleBrick_SC_State_event_consumed == 0 && id == 0 && _instance->SimpleBrick_lives_var > 0) {
SimpleBrick_SC_OnExit(SIMPLEBRICK_SC_LOSTBALL_STATE, _instance);
_instance->SimpleBrick_SC_State = SIMPLEBRICK_SC_LAUNCH_STATE;
SimpleBrick_SC_OnEntry(SIMPLEBRICK_SC_LAUNCH_STATE, _instance);
SimpleBrick_SC_State_event_consumed = 1;
}
else if (SimpleBrick_SC_State_event_consumed == 0 && id == 0 && _instance->SimpleBrick_lives_var == 0) {
SimpleBrick_SC_OnExit(SIMPLEBRICK_SC_LOSTBALL_STATE, _instance);
_instance->SimpleBrick_SC_State = SIMPLEBRICK_SC_GAMEOVER_STATE;
SimpleBrick_SC_OnEntry(SIMPLEBRICK_SC_GAMEOVER_STATE, _instance);
SimpleBrick_SC_State_event_consumed = 1;
}
}
else if (_instance->SimpleBrick_SC_State == SIMPLEBRICK_SC_NEXTLEVEL_STATE) {
if (SimpleBrick_SC_State_event_consumed == 0 && id == 0) {
SimpleBrick_SC_OnExit(SIMPLEBRICK_SC_NEXTLEVEL_STATE, _instance);
_instance->SimpleBrick_SC_State = SIMPLEBRICK_SC_LAUNCH_STATE;
SimpleBrick_SC_OnEntry(SIMPLEBRICK_SC_LAUNCH_STATE, _instance);
SimpleBrick_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SimpleBrick_handle_controller_position(struct SimpleBrick_Instance *_instance, int16_t x, int16_t y) {
if(!(_instance->active)) return;
//Region SC
uint8_t SimpleBrick_SC_State_event_consumed = 0;
//End Region SC
//End dsregion SC
//Session list: 
if (1) {
;int32_t center = (_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var - _instance->SimpleBrick_padlen_var);
center = x * center;
center = center / 200;
_instance->SimpleBrick_padx_var = _instance->SimpleBrick_LEFT_var + center + (_instance->SimpleBrick_RIGHT_var - _instance->SimpleBrick_LEFT_var) / 2;
SimpleBrick_SC_State_event_consumed = 1;
}
}
void SimpleBrick_handle_game_lostBall(struct SimpleBrick_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t SimpleBrick_SC_State_event_consumed = 0;
if (_instance->SimpleBrick_SC_State == SIMPLEBRICK_SC_PLAY_STATE) {
if (SimpleBrick_SC_State_event_consumed == 0 && 1) {
SimpleBrick_SC_OnExit(SIMPLEBRICK_SC_PLAY_STATE, _instance);
_instance->SimpleBrick_SC_State = SIMPLEBRICK_SC_LOSTBALL_STATE;
SimpleBrick_SC_OnEntry(SIMPLEBRICK_SC_LOSTBALL_STATE, _instance);
SimpleBrick_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void SimpleBrick_handle_game_nextLevel(struct SimpleBrick_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t SimpleBrick_SC_State_event_consumed = 0;
if (_instance->SimpleBrick_SC_State == SIMPLEBRICK_SC_PLAY_STATE) {
if (SimpleBrick_SC_State_event_consumed == 0 && 1) {
SimpleBrick_SC_OnExit(SIMPLEBRICK_SC_PLAY_STATE, _instance);
_instance->SimpleBrick_SC_State = SIMPLEBRICK_SC_NEXTLEVEL_STATE;
SimpleBrick_SC_OnEntry(SIMPLEBRICK_SC_NEXTLEVEL_STATE, _instance);
SimpleBrick_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
void (*external_SimpleBrick_send_clock_timer_start_listener)(struct SimpleBrick_Instance *, uint8_t, uint32_t)= 0x0;
void (*SimpleBrick_send_clock_timer_start_listener)(struct SimpleBrick_Instance *, uint8_t, uint32_t)= 0x0;
void register_external_SimpleBrick_send_clock_timer_start_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint32_t)){
external_SimpleBrick_send_clock_timer_start_listener = _listener;
}
void register_SimpleBrick_send_clock_timer_start_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint32_t)){
SimpleBrick_send_clock_timer_start_listener = _listener;
}
void SimpleBrick_send_clock_timer_start(struct SimpleBrick_Instance *_instance, uint8_t id, uint32_t time){
if (SimpleBrick_send_clock_timer_start_listener != 0x0) SimpleBrick_send_clock_timer_start_listener(_instance, id, time);
if (external_SimpleBrick_send_clock_timer_start_listener != 0x0) external_SimpleBrick_send_clock_timer_start_listener(_instance, id, time);
;
}
void (*external_SimpleBrick_send_clock_timer_cancel_listener)(struct SimpleBrick_Instance *, uint8_t)= 0x0;
void (*SimpleBrick_send_clock_timer_cancel_listener)(struct SimpleBrick_Instance *, uint8_t)= 0x0;
void register_external_SimpleBrick_send_clock_timer_cancel_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t)){
external_SimpleBrick_send_clock_timer_cancel_listener = _listener;
}
void register_SimpleBrick_send_clock_timer_cancel_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t)){
SimpleBrick_send_clock_timer_cancel_listener = _listener;
}
void SimpleBrick_send_clock_timer_cancel(struct SimpleBrick_Instance *_instance, uint8_t id){
if (SimpleBrick_send_clock_timer_cancel_listener != 0x0) SimpleBrick_send_clock_timer_cancel_listener(_instance, id);
if (external_SimpleBrick_send_clock_timer_cancel_listener != 0x0) external_SimpleBrick_send_clock_timer_cancel_listener(_instance, id);
;
}
void (*external_SimpleBrick_send_display_create_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t)= 0x0;
void (*SimpleBrick_send_display_create_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_SimpleBrick_send_display_create_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t)){
external_SimpleBrick_send_display_create_listener = _listener;
}
void register_SimpleBrick_send_display_create_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t)){
SimpleBrick_send_display_create_listener = _listener;
}
void SimpleBrick_send_display_create(struct SimpleBrick_Instance *_instance, uint8_t xsize, uint8_t ysize){
if (SimpleBrick_send_display_create_listener != 0x0) SimpleBrick_send_display_create_listener(_instance, xsize, ysize);
if (external_SimpleBrick_send_display_create_listener != 0x0) external_SimpleBrick_send_display_create_listener(_instance, xsize, ysize);
;
}
void (*external_SimpleBrick_send_display_fillRect_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*SimpleBrick_send_display_fillRect_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_SimpleBrick_send_display_fillRect_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_SimpleBrick_send_display_fillRect_listener = _listener;
}
void register_SimpleBrick_send_display_fillRect_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
SimpleBrick_send_display_fillRect_listener = _listener;
}
void SimpleBrick_send_display_fillRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
if (SimpleBrick_send_display_fillRect_listener != 0x0) SimpleBrick_send_display_fillRect_listener(_instance, x, y, width, height);
if (external_SimpleBrick_send_display_fillRect_listener != 0x0) external_SimpleBrick_send_display_fillRect_listener(_instance, x, y, width, height);
;
}
void (*external_SimpleBrick_send_display_drawRect_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*SimpleBrick_send_display_drawRect_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_SimpleBrick_send_display_drawRect_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_SimpleBrick_send_display_drawRect_listener = _listener;
}
void register_SimpleBrick_send_display_drawRect_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
SimpleBrick_send_display_drawRect_listener = _listener;
}
void SimpleBrick_send_display_drawRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
if (SimpleBrick_send_display_drawRect_listener != 0x0) SimpleBrick_send_display_drawRect_listener(_instance, x, y, width, height);
if (external_SimpleBrick_send_display_drawRect_listener != 0x0) external_SimpleBrick_send_display_drawRect_listener(_instance, x, y, width, height);
;
}
void (*external_SimpleBrick_send_display_clear_listener)(struct SimpleBrick_Instance *)= 0x0;
void (*SimpleBrick_send_display_clear_listener)(struct SimpleBrick_Instance *)= 0x0;
void register_external_SimpleBrick_send_display_clear_listener(void (*_listener)(struct SimpleBrick_Instance *)){
external_SimpleBrick_send_display_clear_listener = _listener;
}
void register_SimpleBrick_send_display_clear_listener(void (*_listener)(struct SimpleBrick_Instance *)){
SimpleBrick_send_display_clear_listener = _listener;
}
void SimpleBrick_send_display_clear(struct SimpleBrick_Instance *_instance){
if (SimpleBrick_send_display_clear_listener != 0x0) SimpleBrick_send_display_clear_listener(_instance);
if (external_SimpleBrick_send_display_clear_listener != 0x0) external_SimpleBrick_send_display_clear_listener(_instance);
;
}
void (*external_SimpleBrick_send_display_setColor_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*SimpleBrick_send_display_setColor_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_SimpleBrick_send_display_setColor_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)){
external_SimpleBrick_send_display_setColor_listener = _listener;
}
void register_SimpleBrick_send_display_setColor_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)){
SimpleBrick_send_display_setColor_listener = _listener;
}
void SimpleBrick_send_display_setColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
if (SimpleBrick_send_display_setColor_listener != 0x0) SimpleBrick_send_display_setColor_listener(_instance, r, g, b);
if (external_SimpleBrick_send_display_setColor_listener != 0x0) external_SimpleBrick_send_display_setColor_listener(_instance, r, g, b);
;
}
void (*external_SimpleBrick_send_display_setBGColor_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void (*SimpleBrick_send_display_setBGColor_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_SimpleBrick_send_display_setBGColor_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)){
external_SimpleBrick_send_display_setBGColor_listener = _listener;
}
void register_SimpleBrick_send_display_setBGColor_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, uint8_t)){
SimpleBrick_send_display_setBGColor_listener = _listener;
}
void SimpleBrick_send_display_setBGColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
if (SimpleBrick_send_display_setBGColor_listener != 0x0) SimpleBrick_send_display_setBGColor_listener(_instance, r, g, b);
if (external_SimpleBrick_send_display_setBGColor_listener != 0x0) external_SimpleBrick_send_display_setBGColor_listener(_instance, r, g, b);
;
}
void (*external_SimpleBrick_send_display_drawInteger_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)= 0x0;
void (*SimpleBrick_send_display_drawInteger_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)= 0x0;
void register_external_SimpleBrick_send_display_drawInteger_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)){
external_SimpleBrick_send_display_drawInteger_listener = _listener;
}
void register_SimpleBrick_send_display_drawInteger_listener(void (*_listener)(struct SimpleBrick_Instance *, uint8_t, uint8_t, int16_t, uint8_t, uint8_t)){
SimpleBrick_send_display_drawInteger_listener = _listener;
}
void SimpleBrick_send_display_drawInteger(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale){
if (SimpleBrick_send_display_drawInteger_listener != 0x0) SimpleBrick_send_display_drawInteger_listener(_instance, x, y, v, digits, scale);
if (external_SimpleBrick_send_display_drawInteger_listener != 0x0) external_SimpleBrick_send_display_drawInteger_listener(_instance, x, y, v, digits, scale);
;
}
void (*external_SimpleBrick_send_display_update_listener)(struct SimpleBrick_Instance *)= 0x0;
void (*SimpleBrick_send_display_update_listener)(struct SimpleBrick_Instance *)= 0x0;
void register_external_SimpleBrick_send_display_update_listener(void (*_listener)(struct SimpleBrick_Instance *)){
external_SimpleBrick_send_display_update_listener = _listener;
}
void register_SimpleBrick_send_display_update_listener(void (*_listener)(struct SimpleBrick_Instance *)){
SimpleBrick_send_display_update_listener = _listener;
}
void SimpleBrick_send_display_update(struct SimpleBrick_Instance *_instance){
if (SimpleBrick_send_display_update_listener != 0x0) SimpleBrick_send_display_update_listener(_instance);
if (external_SimpleBrick_send_display_update_listener != 0x0) external_SimpleBrick_send_display_update_listener(_instance);
;
}
void (*external_SimpleBrick_send_ia_updateIA_listener)(struct SimpleBrick_Instance *, int16_t, int16_t, int16_t, int16_t)= 0x0;
void (*SimpleBrick_send_ia_updateIA_listener)(struct SimpleBrick_Instance *, int16_t, int16_t, int16_t, int16_t)= 0x0;
void register_external_SimpleBrick_send_ia_updateIA_listener(void (*_listener)(struct SimpleBrick_Instance *, int16_t, int16_t, int16_t, int16_t)){
external_SimpleBrick_send_ia_updateIA_listener = _listener;
}
void register_SimpleBrick_send_ia_updateIA_listener(void (*_listener)(struct SimpleBrick_Instance *, int16_t, int16_t, int16_t, int16_t)){
SimpleBrick_send_ia_updateIA_listener = _listener;
}
void SimpleBrick_send_ia_updateIA(struct SimpleBrick_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady){
if (SimpleBrick_send_ia_updateIA_listener != 0x0) SimpleBrick_send_ia_updateIA_listener(_instance, ballx, bally, padx, pady);
if (external_SimpleBrick_send_ia_updateIA_listener != 0x0) external_SimpleBrick_send_ia_updateIA_listener(_instance, ballx, bally, padx, pady);
;
}
void (*external_SimpleBrick_send_ia_lostBall_listener)(struct SimpleBrick_Instance *)= 0x0;
void (*SimpleBrick_send_ia_lostBall_listener)(struct SimpleBrick_Instance *)= 0x0;
void register_external_SimpleBrick_send_ia_lostBall_listener(void (*_listener)(struct SimpleBrick_Instance *)){
external_SimpleBrick_send_ia_lostBall_listener = _listener;
}
void register_SimpleBrick_send_ia_lostBall_listener(void (*_listener)(struct SimpleBrick_Instance *)){
SimpleBrick_send_ia_lostBall_listener = _listener;
}
void SimpleBrick_send_ia_lostBall(struct SimpleBrick_Instance *_instance){
if (SimpleBrick_send_ia_lostBall_listener != 0x0) SimpleBrick_send_ia_lostBall_listener(_instance);
if (external_SimpleBrick_send_ia_lostBall_listener != 0x0) external_SimpleBrick_send_ia_lostBall_listener(_instance);
;
}
void (*external_SimpleBrick_send_ia_hitBall_listener)(struct SimpleBrick_Instance *)= 0x0;
void (*SimpleBrick_send_ia_hitBall_listener)(struct SimpleBrick_Instance *)= 0x0;
void register_external_SimpleBrick_send_ia_hitBall_listener(void (*_listener)(struct SimpleBrick_Instance *)){
external_SimpleBrick_send_ia_hitBall_listener = _listener;
}
void register_SimpleBrick_send_ia_hitBall_listener(void (*_listener)(struct SimpleBrick_Instance *)){
SimpleBrick_send_ia_hitBall_listener = _listener;
}
void SimpleBrick_send_ia_hitBall(struct SimpleBrick_Instance *_instance){
if (SimpleBrick_send_ia_hitBall_listener != 0x0) SimpleBrick_send_ia_hitBall_listener(_instance);
if (external_SimpleBrick_send_ia_hitBall_listener != 0x0) external_SimpleBrick_send_ia_hitBall_listener(_instance);
;
}
void (*external_SimpleBrick_send_game_lostBall_listener)(struct SimpleBrick_Instance *)= 0x0;
void (*SimpleBrick_send_game_lostBall_listener)(struct SimpleBrick_Instance *)= 0x0;
void register_external_SimpleBrick_send_game_lostBall_listener(void (*_listener)(struct SimpleBrick_Instance *)){
external_SimpleBrick_send_game_lostBall_listener = _listener;
}
void register_SimpleBrick_send_game_lostBall_listener(void (*_listener)(struct SimpleBrick_Instance *)){
SimpleBrick_send_game_lostBall_listener = _listener;
}
void SimpleBrick_send_game_lostBall(struct SimpleBrick_Instance *_instance){
if (SimpleBrick_send_game_lostBall_listener != 0x0) SimpleBrick_send_game_lostBall_listener(_instance);
if (external_SimpleBrick_send_game_lostBall_listener != 0x0) external_SimpleBrick_send_game_lostBall_listener(_instance);
;
}
void (*external_SimpleBrick_send_game_nextLevel_listener)(struct SimpleBrick_Instance *)= 0x0;
void (*SimpleBrick_send_game_nextLevel_listener)(struct SimpleBrick_Instance *)= 0x0;
void register_external_SimpleBrick_send_game_nextLevel_listener(void (*_listener)(struct SimpleBrick_Instance *)){
external_SimpleBrick_send_game_nextLevel_listener = _listener;
}
void register_SimpleBrick_send_game_nextLevel_listener(void (*_listener)(struct SimpleBrick_Instance *)){
SimpleBrick_send_game_nextLevel_listener = _listener;
}
void SimpleBrick_send_game_nextLevel(struct SimpleBrick_Instance *_instance){
if (SimpleBrick_send_game_nextLevel_listener != 0x0) SimpleBrick_send_game_nextLevel_listener(_instance);
if (external_SimpleBrick_send_game_nextLevel_listener != 0x0) external_SimpleBrick_send_game_nextLevel_listener(_instance);
;
}



/*****************************************************************************
 * Implementation for type : ArduinoDisplay
 *****************************************************************************/


// BEGIN: Code from the c_global annotation ArduinoDisplay
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
// END: Code from the c_global annotation ArduinoDisplay

// Declaration of prototypes:
//Prototypes: State Machine
void Display_SC_OnExit(int state, struct ArduinoDisplay_Instance *_instance);
//Prototypes: Message Sending
void ArduinoDisplay_send_display_displayReady(struct ArduinoDisplay_Instance *_instance);
void ArduinoDisplay_send_display_displayError(struct ArduinoDisplay_Instance *_instance);
//Prototypes: Function
void f_ArduinoDisplay_initDisplay(struct ArduinoDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize);
void f_ArduinoDisplay_destroyDisplay(struct ArduinoDisplay_Instance *_instance);
void f_ArduinoDisplay_clearScreen(struct ArduinoDisplay_Instance *_instance);
void f_ArduinoDisplay_setColor(struct ArduinoDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b);
void f_ArduinoDisplay_drawRect(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void f_ArduinoDisplay_fillRect(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void f_ArduinoDisplay_updateDisplay(struct ArduinoDisplay_Instance *_instance);
void f_ArduinoDisplay_drawDigit(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t d, uint8_t size);
void f_ArduinoDisplay_drawInteger(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale);
void f_ArduinoDisplay_clearInteger(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t digits, uint8_t scale);
// Declaration of functions:
// Definition of function initDisplay
void f_ArduinoDisplay_initDisplay(struct ArduinoDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize) {
tft.initR(INITR_BLACKTAB);
		tft.fillScreen(ST7735_BLACK);
		tft.setRotation(3);
}
// Definition of function destroyDisplay
void f_ArduinoDisplay_destroyDisplay(struct ArduinoDisplay_Instance *_instance) {
f_ArduinoDisplay_clearScreen(_instance);
}
// Definition of function clearScreen
void f_ArduinoDisplay_clearScreen(struct ArduinoDisplay_Instance *_instance) {
tft.fillScreen(ST7735_BLACK);
}
// Definition of function setColor
void f_ArduinoDisplay_setColor(struct ArduinoDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b) {
_instance->ArduinoDisplay_color_var = tft.Color565(r, g, b);
}
// Definition of function drawRect
void f_ArduinoDisplay_drawRect(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
tft.drawRect(x,y,width,height,_instance->ArduinoDisplay_color_var);
}
// Definition of function fillRect
void f_ArduinoDisplay_fillRect(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
tft.fillRect(x,y,width,height,_instance->ArduinoDisplay_color_var);
}
// Definition of function updateDisplay
void f_ArduinoDisplay_updateDisplay(struct ArduinoDisplay_Instance *_instance) {
}
// Definition of function drawDigit
void f_ArduinoDisplay_drawDigit(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t d, uint8_t size) {
if(d < 1) {
f_ArduinoDisplay_fillRect(_instance, x, y, size, 5 * size);
f_ArduinoDisplay_fillRect(_instance, x, y, 3 * size, size);
f_ArduinoDisplay_fillRect(_instance, x + 2 * size, y, size, 5 * size);
f_ArduinoDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);

} else {
if(d < 2) {
f_ArduinoDisplay_fillRect(_instance, x + size, y, size, 5 * size);

} else {
if(d < 3) {
f_ArduinoDisplay_fillRect(_instance, x, y, size * 3, size);
f_ArduinoDisplay_fillRect(_instance, x + 2 * size, y, size, 3 * size);
f_ArduinoDisplay_fillRect(_instance, x, y + 2 * size, 3 * size, size);
f_ArduinoDisplay_fillRect(_instance, x, y + 2 * size, size, 3 * size);
f_ArduinoDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);

} else {
if(d < 4) {
f_ArduinoDisplay_fillRect(_instance, x, y, size * 3, size);
f_ArduinoDisplay_fillRect(_instance, x + 2 * size, y, size, 5 * size);
f_ArduinoDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);
f_ArduinoDisplay_fillRect(_instance, x + size, y + 2 * size, 2 * size, size);

} else {
if(d < 5) {
f_ArduinoDisplay_fillRect(_instance, x, y, size, 3 * size);
f_ArduinoDisplay_fillRect(_instance, x, y + 2 * size, 3 * size, size);
f_ArduinoDisplay_fillRect(_instance, x + 2 * size, y, size, 5 * size);

} else {
if(d < 6) {
f_ArduinoDisplay_fillRect(_instance, x, y, size * 3, size);
f_ArduinoDisplay_fillRect(_instance, x, y, size, 3 * size);
f_ArduinoDisplay_fillRect(_instance, x, y + 2 * size, 3 * size, size);
f_ArduinoDisplay_fillRect(_instance, x + 2 * size, y + 2 * size, size, 3 * size);
f_ArduinoDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);

} else {
if(d < 7) {
f_ArduinoDisplay_fillRect(_instance, x, y, size * 3, size);
f_ArduinoDisplay_fillRect(_instance, x, y, size, 5 * size);
f_ArduinoDisplay_fillRect(_instance, x, y + 2 * size, 3 * size, size);
f_ArduinoDisplay_fillRect(_instance, x + 2 * size, y + 2 * size, size, 3 * size);
f_ArduinoDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);

} else {
if(d < 8) {
f_ArduinoDisplay_fillRect(_instance, x, y, 3 * size, size);
f_ArduinoDisplay_fillRect(_instance, x + 2 * size, y, size, 5 * size);

} else {
if(d < 9) {
f_ArduinoDisplay_fillRect(_instance, x, y, size, 5 * size);
f_ArduinoDisplay_fillRect(_instance, x, y, 3 * size, size);
f_ArduinoDisplay_fillRect(_instance, x + 2 * size, y, size, 5 * size);
f_ArduinoDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);
f_ArduinoDisplay_fillRect(_instance, x, y + 2 * size, 3 * size, size);

} else {
f_ArduinoDisplay_fillRect(_instance, x, y, size, 3 * size);
f_ArduinoDisplay_fillRect(_instance, x, y, 3 * size, size);
f_ArduinoDisplay_fillRect(_instance, x + 2 * size, y, size, 5 * size);
f_ArduinoDisplay_fillRect(_instance, x, y + 4 * size, 3 * size, size);
f_ArduinoDisplay_fillRect(_instance, x, y + 2 * size, 3 * size, size);

}

}

}

}

}

}

}

}

}
}
// Definition of function drawInteger
void f_ArduinoDisplay_drawInteger(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale) {
f_ArduinoDisplay_clearInteger(_instance, x, y, digits, scale);
;int16_t val = v;
;uint8_t d = digits;
while(d > 0) {
f_ArduinoDisplay_drawDigit(_instance, x + (d - 1) * 4 * scale, y, val % 10, scale);
val = val / 10;
d = d - 1;

}
}
// Definition of function clearInteger
void f_ArduinoDisplay_clearInteger(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t digits, uint8_t scale) {
f_ArduinoDisplay_setColor(_instance, _instance->Display_bg_r_var, _instance->Display_bg_g_var, _instance->Display_bg_b_var);
f_ArduinoDisplay_fillRect(_instance, x, y, (digits * 4 - 1) * scale, 5 * scale);
f_ArduinoDisplay_setColor(_instance, _instance->Display_fg_r_var, _instance->Display_fg_g_var, _instance->Display_fg_b_var);
}

// Sessions functionss:


// On Entry Actions:
void Display_SC_OnEntry(int state, struct ArduinoDisplay_Instance *_instance) {
switch(state) {
case DISPLAY_SC_STATE:{
_instance->Display_SC_State = DISPLAY_SC_WAIT_STATE;
Display_SC_OnEntry(_instance->Display_SC_State, _instance);
break;
}
case DISPLAY_SC_WAIT_STATE:{
break;
}
case DISPLAY_SC_RUNNING_STATE:{
ArduinoDisplay_send_display_displayReady(_instance);
break;
}
case DISPLAY_SC_DESTROYED_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Display_SC_OnExit(int state, struct ArduinoDisplay_Instance *_instance) {
switch(state) {
case DISPLAY_SC_STATE:{
Display_SC_OnExit(_instance->Display_SC_State, _instance);
break;}
case DISPLAY_SC_WAIT_STATE:{
break;}
case DISPLAY_SC_RUNNING_STATE:{
break;}
case DISPLAY_SC_DESTROYED_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void ArduinoDisplay_handle_display_clear(struct ArduinoDisplay_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_ArduinoDisplay_clearScreen(_instance);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void ArduinoDisplay_handle_display_create(struct ArduinoDisplay_Instance *_instance, uint8_t xsize, uint8_t ysize) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_WAIT_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
Display_SC_OnExit(DISPLAY_SC_WAIT_STATE, _instance);
_instance->Display_SC_State = DISPLAY_SC_RUNNING_STATE;
f_ArduinoDisplay_initDisplay(_instance, xsize, ysize);
Display_SC_OnEntry(DISPLAY_SC_RUNNING_STATE, _instance);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void ArduinoDisplay_handle_display_drawRect(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_ArduinoDisplay_drawRect(_instance, x, y, width, height);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void ArduinoDisplay_handle_display_drawInteger(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_ArduinoDisplay_drawInteger(_instance, x, y, v, digits, scale);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void ArduinoDisplay_handle_display_setColor(struct ArduinoDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
_instance->Display_fg_r_var = r;
_instance->Display_fg_g_var = g;
_instance->Display_fg_b_var = b;
f_ArduinoDisplay_setColor(_instance, r, g, b);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void ArduinoDisplay_handle_display_fillRect(struct ArduinoDisplay_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_ArduinoDisplay_fillRect(_instance, x, y, width, height);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void ArduinoDisplay_handle_display_destroy(struct ArduinoDisplay_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
Display_SC_OnExit(DISPLAY_SC_RUNNING_STATE, _instance);
_instance->Display_SC_State = DISPLAY_SC_DESTROYED_STATE;
f_ArduinoDisplay_destroyDisplay(_instance);
Display_SC_OnEntry(DISPLAY_SC_DESTROYED_STATE, _instance);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void ArduinoDisplay_handle_display_setBGColor(struct ArduinoDisplay_Instance *_instance, uint8_t r, uint8_t g, uint8_t b) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
_instance->Display_bg_r_var = r;
_instance->Display_bg_g_var = g;
_instance->Display_bg_b_var = b;
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void ArduinoDisplay_handle_display_update(struct ArduinoDisplay_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t Display_SC_State_event_consumed = 0;
if (_instance->Display_SC_State == DISPLAY_SC_RUNNING_STATE) {
if (Display_SC_State_event_consumed == 0 && 1) {
f_ArduinoDisplay_updateDisplay(_instance);
Display_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
void (*external_ArduinoDisplay_send_display_displayReady_listener)(struct ArduinoDisplay_Instance *)= 0x0;
void (*ArduinoDisplay_send_display_displayReady_listener)(struct ArduinoDisplay_Instance *)= 0x0;
void register_external_ArduinoDisplay_send_display_displayReady_listener(void (*_listener)(struct ArduinoDisplay_Instance *)){
external_ArduinoDisplay_send_display_displayReady_listener = _listener;
}
void register_ArduinoDisplay_send_display_displayReady_listener(void (*_listener)(struct ArduinoDisplay_Instance *)){
ArduinoDisplay_send_display_displayReady_listener = _listener;
}
void ArduinoDisplay_send_display_displayReady(struct ArduinoDisplay_Instance *_instance){
if (ArduinoDisplay_send_display_displayReady_listener != 0x0) ArduinoDisplay_send_display_displayReady_listener(_instance);
if (external_ArduinoDisplay_send_display_displayReady_listener != 0x0) external_ArduinoDisplay_send_display_displayReady_listener(_instance);
;
}
void (*external_ArduinoDisplay_send_display_displayError_listener)(struct ArduinoDisplay_Instance *)= 0x0;
void (*ArduinoDisplay_send_display_displayError_listener)(struct ArduinoDisplay_Instance *)= 0x0;
void register_external_ArduinoDisplay_send_display_displayError_listener(void (*_listener)(struct ArduinoDisplay_Instance *)){
external_ArduinoDisplay_send_display_displayError_listener = _listener;
}
void register_ArduinoDisplay_send_display_displayError_listener(void (*_listener)(struct ArduinoDisplay_Instance *)){
ArduinoDisplay_send_display_displayError_listener = _listener;
}
void ArduinoDisplay_send_display_displayError(struct ArduinoDisplay_Instance *_instance){
if (ArduinoDisplay_send_display_displayError_listener != 0x0) ArduinoDisplay_send_display_displayError_listener(_instance);
if (external_ArduinoDisplay_send_display_displayError_listener != 0x0) external_ArduinoDisplay_send_display_displayError_listener(_instance);
;
}






/*****************************************************************************
 * Definitions for configuration : SimpleBrickArduino
 *****************************************************************************/

uint8_t array_bb_SimpleBrick_fgcolor_var[3];
uint8_t array_bb_SimpleBrick_bricks_var[5];
uint8_t array_bb_SimpleBrick_bgcolor_var[3];
//Declaration of instance variables
//Instance bb
// Variables for the properties of the instance
struct SimpleBrick_Instance bb_var;
// Variables for the sessions of the instance
//Instance disp
// Variables for the properties of the instance
struct ArduinoDisplay_Instance disp_var;
// Variables for the sessions of the instance
//Instance ctrl
// Variables for the properties of the instance
struct BasicIAController_Instance ctrl_var;
// Variables for the sessions of the instance


// Enqueue of messages SimpleBrick::ia::updateIA
void enqueue_SimpleBrick_send_ia_updateIA(struct SimpleBrick_Instance *_instance, int16_t ballx, int16_t bally, int16_t padx, int16_t pady){
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_ia >> 8) & 0xFF );
_fifo_enqueue( _instance->id_ia & 0xFF );

// parameter ballx
union u_ballx_t {
int16_t p;
byte bytebuffer[2];
} u_ballx;
u_ballx.p = ballx;
_fifo_enqueue(u_ballx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_ballx.bytebuffer[0] & 0xFF );

// parameter bally
union u_bally_t {
int16_t p;
byte bytebuffer[2];
} u_bally;
u_bally.p = bally;
_fifo_enqueue(u_bally.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bally.bytebuffer[0] & 0xFF );

// parameter padx
union u_padx_t {
int16_t p;
byte bytebuffer[2];
} u_padx;
u_padx.p = padx;
_fifo_enqueue(u_padx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_padx.bytebuffer[0] & 0xFF );

// parameter pady
union u_pady_t {
int16_t p;
byte bytebuffer[2];
} u_pady;
u_pady.p = pady;
_fifo_enqueue(u_pady.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_pady.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages SimpleBrick::game::lostBall
void enqueue_SimpleBrick_send_game_lostBall(struct SimpleBrick_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_game & 0xFF );
}
}
// Enqueue of messages SimpleBrick::game::nextLevel
void enqueue_SimpleBrick_send_game_nextLevel(struct SimpleBrick_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_game >> 8) & 0xFF );
_fifo_enqueue( _instance->id_game & 0xFF );
}
}
// Enqueue of messages ArduinoDisplay::display::displayReady
void enqueue_ArduinoDisplay_send_display_displayReady(struct ArduinoDisplay_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );
}
}
// Enqueue of messages ArduinoDisplay::display::displayError
void enqueue_ArduinoDisplay_send_display_displayError(struct ArduinoDisplay_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_display >> 8) & 0xFF );
_fifo_enqueue( _instance->id_display & 0xFF );
}
}
// Enqueue of messages BasicIAController::controls::position
void enqueue_BasicIAController_send_controls_position(struct BasicIAController_Instance *_instance, int16_t x, int16_t y){
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_controls >> 8) & 0xFF );
_fifo_enqueue( _instance->id_controls & 0xFF );

// parameter x
union u_x_t {
int16_t p;
byte bytebuffer[2];
} u_x;
u_x.p = x;
_fifo_enqueue(u_x.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[0] & 0xFF );

// parameter y
union u_y_t {
int16_t p;
byte bytebuffer[2];
} u_y;
u_y.p = y;
_fifo_enqueue(u_y.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[0] & 0xFF );
}
}


//New dispatcher for messages
void dispatch_position(uint16_t sender, int16_t param_x, int16_t param_y) {
if (sender == ctrl_var.id_controls) {
SimpleBrick_handle_controller_position(&bb_var, param_x, param_y);

}
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_displayError(uint16_t sender) {
if (sender == disp_var.id_display) {

}
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_drawRect(uint16_t sender, uint8_t param_x, uint8_t param_y, uint8_t param_width, uint8_t param_height) {
if (sender == bb_var.id_display) {
ArduinoDisplay_handle_display_drawRect(&disp_var, param_x, param_y, param_width, param_height);

}
if (sender == bb_var.id_game) {

}

}

void sync_dispatch_SimpleBrick_send_display_drawRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
dispatch_drawRect(_instance->id_display, x, y, width, height);
}

//New dispatcher for messages
void dispatch_drawInteger(uint16_t sender, uint8_t param_x, uint8_t param_y, int16_t param_v, uint8_t param_digits, uint8_t param_scale) {
if (sender == bb_var.id_display) {
ArduinoDisplay_handle_display_drawInteger(&disp_var, param_x, param_y, param_v, param_digits, param_scale);

}
if (sender == bb_var.id_game) {

}

}

void sync_dispatch_SimpleBrick_send_display_drawInteger(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, int16_t v, uint8_t digits, uint8_t scale){
dispatch_drawInteger(_instance->id_display, x, y, v, digits, scale);
}

//New dispatcher for messages
void dispatch_updateIA(uint16_t sender, int16_t param_ballx, int16_t param_bally, int16_t param_padx, int16_t param_pady) {
if (sender == bb_var.id_ia) {
BasicIAController_handle_game_updateIA(&ctrl_var, param_ballx, param_bally, param_padx, param_pady);

}
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_nextLevel(uint16_t sender) {
if (sender == bb_var.id_game) {
SimpleBrick_handle_game_nextLevel(&bb_var);

}

}


//New dispatcher for messages
void dispatch_setBGColor(uint16_t sender, uint8_t param_r, uint8_t param_g, uint8_t param_b) {
if (sender == bb_var.id_display) {
ArduinoDisplay_handle_display_setBGColor(&disp_var, param_r, param_g, param_b);

}
if (sender == bb_var.id_game) {

}

}

void sync_dispatch_SimpleBrick_send_display_setBGColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
dispatch_setBGColor(_instance->id_display, r, g, b);
}

//New dispatcher for messages
void dispatch_timer_start(uint16_t sender, uint8_t param_id, uint32_t param_time) {
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_missBall(uint16_t sender) {
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_lostBall(uint16_t sender) {
if (sender == bb_var.id_ia) {

}
if (sender == bb_var.id_game) {
SimpleBrick_handle_game_lostBall(&bb_var);

}

}


//New dispatcher for messages
void dispatch_displayReady(uint16_t sender) {
if (sender == disp_var.id_display) {
SimpleBrick_handle_display_displayReady(&bb_var);

}
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_clear(uint16_t sender) {
if (sender == bb_var.id_display) {
ArduinoDisplay_handle_display_clear(&disp_var);

}
if (sender == bb_var.id_game) {

}

}

void sync_dispatch_SimpleBrick_send_display_clear(struct SimpleBrick_Instance *_instance){
dispatch_clear(_instance->id_display);
}

//New dispatcher for messages
void dispatch_create(uint16_t sender, uint8_t param_xsize, uint8_t param_ysize) {
if (sender == bb_var.id_display) {
ArduinoDisplay_handle_display_create(&disp_var, param_xsize, param_ysize);

}
if (sender == bb_var.id_game) {

}

}

void sync_dispatch_SimpleBrick_send_display_create(struct SimpleBrick_Instance *_instance, uint8_t xsize, uint8_t ysize){
dispatch_create(_instance->id_display, xsize, ysize);
}

//New dispatcher for messages
void dispatch_fire(uint16_t sender, uint8_t param_id) {
if (sender == ctrl_var.id_controls) {

}
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_timer_timeout(uint16_t sender, uint8_t param_id) {
if (sender == bb_var.id_game) {

}
if (sender == timer2_instance.listener_id) {
SimpleBrick_handle_clock_timer_timeout(&bb_var, param_id);

}

}


//New dispatcher for messages
void dispatch_timer_cancel(uint16_t sender, uint8_t param_id) {
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_hitBall(uint16_t sender) {
if (sender == bb_var.id_ia) {

}
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_setColor(uint16_t sender, uint8_t param_r, uint8_t param_g, uint8_t param_b) {
if (sender == bb_var.id_display) {
ArduinoDisplay_handle_display_setColor(&disp_var, param_r, param_g, param_b);

}
if (sender == bb_var.id_game) {

}

}

void sync_dispatch_SimpleBrick_send_display_setColor(struct SimpleBrick_Instance *_instance, uint8_t r, uint8_t g, uint8_t b){
dispatch_setColor(_instance->id_display, r, g, b);
}

//New dispatcher for messages
void dispatch_fillRect(uint16_t sender, uint8_t param_x, uint8_t param_y, uint8_t param_width, uint8_t param_height) {
if (sender == bb_var.id_display) {
ArduinoDisplay_handle_display_fillRect(&disp_var, param_x, param_y, param_width, param_height);

}
if (sender == bb_var.id_game) {

}

}

void sync_dispatch_SimpleBrick_send_display_fillRect(struct SimpleBrick_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height){
dispatch_fillRect(_instance->id_display, x, y, width, height);
}

//New dispatcher for messages
void dispatch_destroy(uint16_t sender) {
if (sender == bb_var.id_game) {

}

}


//New dispatcher for messages
void dispatch_update(uint16_t sender) {
if (sender == bb_var.id_display) {
ArduinoDisplay_handle_display_update(&disp_var);

}
if (sender == bb_var.id_game) {

}

}

void sync_dispatch_SimpleBrick_send_display_update(struct SimpleBrick_Instance *_instance){
dispatch_update(_instance->id_display);
}

//New dispatcher for messages
void dispatch_velocity(uint16_t sender, int16_t param_dx, int16_t param_dy) {
if (sender == bb_var.id_game) {

}

}


int processMessageQueue() {
if (fifo_empty()) return 0; // return 0 if there is nothing to do

uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 3:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_lostBall = 2;
dispatch_lostBall((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 5:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_displayReady = 2;
dispatch_displayReady((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 7:{
byte mbuf[8 - 2];
while (mbufi < (8 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_position = 2;
union u_position_x_t {
int16_t p;
byte bytebuffer[2];
} u_position_x;
u_position_x.bytebuffer[1] = mbuf[mbufi_position + 0];
u_position_x.bytebuffer[0] = mbuf[mbufi_position + 1];
mbufi_position += 2;
union u_position_y_t {
int16_t p;
byte bytebuffer[2];
} u_position_y;
u_position_y.bytebuffer[1] = mbuf[mbufi_position + 0];
u_position_y.bytebuffer[0] = mbuf[mbufi_position + 1];
mbufi_position += 2;
dispatch_position((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_position_x.p /* x */ ,
 u_position_y.p /* y */ );
break;
}
case 6:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_displayError = 2;
dispatch_displayError((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 1:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_timer_timeout = 2;
union u_timer_timeout_id_t {
uint8_t p;
byte bytebuffer[1];
} u_timer_timeout_id;
u_timer_timeout_id.bytebuffer[0] = mbuf[mbufi_timer_timeout + 0];
mbufi_timer_timeout += 1;
dispatch_timer_timeout((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_timer_timeout_id.p /* id */ );
break;
}
case 2:{
byte mbuf[12 - 2];
while (mbufi < (12 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_updateIA = 2;
union u_updateIA_ballx_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_ballx;
u_updateIA_ballx.bytebuffer[1] = mbuf[mbufi_updateIA + 0];
u_updateIA_ballx.bytebuffer[0] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
union u_updateIA_bally_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_bally;
u_updateIA_bally.bytebuffer[1] = mbuf[mbufi_updateIA + 0];
u_updateIA_bally.bytebuffer[0] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
union u_updateIA_padx_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_padx;
u_updateIA_padx.bytebuffer[1] = mbuf[mbufi_updateIA + 0];
u_updateIA_padx.bytebuffer[0] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
union u_updateIA_pady_t {
int16_t p;
byte bytebuffer[2];
} u_updateIA_pady;
u_updateIA_pady.bytebuffer[1] = mbuf[mbufi_updateIA + 0];
u_updateIA_pady.bytebuffer[0] = mbuf[mbufi_updateIA + 1];
mbufi_updateIA += 2;
dispatch_updateIA((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_updateIA_ballx.p /* ballx */ ,
 u_updateIA_bally.p /* bally */ ,
 u_updateIA_padx.p /* padx */ ,
 u_updateIA_pady.p /* pady */ );
break;
}
case 4:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_nextLevel = 2;
dispatch_nextLevel((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
}
return 1;
}

void forward_SimpleBrick_send_clock_timer_cancel(struct SimpleBrick_Instance *_instance, uint8_t id){
if(_instance->id_clock == bb_var.id_clock) {
forward_timer2_SimpleBrick_send_clock_timer_cancel(_instance, id);
}
}
void forward_SimpleBrick_send_clock_timer_start(struct SimpleBrick_Instance *_instance, uint8_t id, uint32_t time){
if(_instance->id_clock == bb_var.id_clock) {
forward_timer2_SimpleBrick_send_clock_timer_start(_instance, id, time);
}
}

//external Message enqueue
void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id) {
if ((msgSize >= 2) && (msg != NULL)) {
uint8_t msgSizeOK = 0;
switch(msg[0] * 256 + msg[1]) {
case 1:
if(msgSize == 3) {
msgSizeOK = 1;}
break;
}

if(msgSizeOK == 1) {
if ( fifo_byte_available() > (msgSize + 2) ) {
	uint8_t i;
	for (i = 0; i < 2; i++) {
		_fifo_enqueue(msg[i]);
	}
	_fifo_enqueue((listener_id >> 8) & 0xFF);
	_fifo_enqueue(listener_id & 0xFF);
	for (i = 2; i < msgSize; i++) {
		_fifo_enqueue(msg[i]);
	}
}
}
}
}

void initialize_configuration_SimpleBrickArduino() {
// Initialize connectors
register_external_SimpleBrick_send_clock_timer_start_listener(&forward_SimpleBrick_send_clock_timer_start);
register_external_SimpleBrick_send_clock_timer_cancel_listener(&forward_SimpleBrick_send_clock_timer_cancel);
register_SimpleBrick_send_display_create_listener(&sync_dispatch_SimpleBrick_send_display_create);
register_SimpleBrick_send_display_fillRect_listener(&sync_dispatch_SimpleBrick_send_display_fillRect);
register_SimpleBrick_send_display_drawRect_listener(&sync_dispatch_SimpleBrick_send_display_drawRect);
register_SimpleBrick_send_display_clear_listener(&sync_dispatch_SimpleBrick_send_display_clear);
register_SimpleBrick_send_display_setColor_listener(&sync_dispatch_SimpleBrick_send_display_setColor);
register_SimpleBrick_send_display_setBGColor_listener(&sync_dispatch_SimpleBrick_send_display_setBGColor);
register_SimpleBrick_send_display_drawInteger_listener(&sync_dispatch_SimpleBrick_send_display_drawInteger);
register_SimpleBrick_send_display_update_listener(&sync_dispatch_SimpleBrick_send_display_update);
register_SimpleBrick_send_ia_updateIA_listener(&enqueue_SimpleBrick_send_ia_updateIA);
register_SimpleBrick_send_game_lostBall_listener(&enqueue_SimpleBrick_send_game_lostBall);
register_SimpleBrick_send_game_nextLevel_listener(&enqueue_SimpleBrick_send_game_nextLevel);
register_ArduinoDisplay_send_display_displayReady_listener(&enqueue_ArduinoDisplay_send_display_displayReady);
register_ArduinoDisplay_send_display_displayError_listener(&enqueue_ArduinoDisplay_send_display_displayError);
register_BasicIAController_send_controls_position_listener(&enqueue_BasicIAController_send_controls_position);

// Init the ID, state variables and properties for external connector timer2

// Network Initialization

timer2_instance.listener_id = add_instance(&timer2_instance);

timer2_setup();

// End Network Initialization

// Init the ID, state variables and properties for instance ctrl
ctrl_var.active = true;
ctrl_var.id_game = add_instance( (void*) &ctrl_var);
ctrl_var.id_controls = add_instance( (void*) &ctrl_var);
ctrl_var.BasicIAController_SC_State = BASICIACONTROLLER_SC_FOLLOWING_STATE;
ctrl_var.BasicIAController_ctrlx_var = 0;

BasicIAController_SC_OnEntry(BASICIACONTROLLER_SC_STATE, &ctrl_var);
// Init the ID, state variables and properties for instance disp
disp_var.active = true;
disp_var.id_display = add_instance( (void*) &disp_var);
disp_var.Display_SC_State = DISPLAY_SC_WAIT_STATE;
disp_var.Display_bg_r_var = 0;
disp_var.Display_bg_b_var = 0;
disp_var.Display_fg_b_var = 0;
disp_var.Display_bg_g_var = 0;
disp_var.Display_fg_r_var = 0;
disp_var.ArduinoDisplay_color_var = ST7735_BLACK;
disp_var.Display_fg_g_var = 0;

Display_SC_OnEntry(DISPLAY_SC_STATE, &disp_var);
// Init the ID, state variables and properties for instance bb
bb_var.active = true;
bb_var.id_clock = add_instance( (void*) &bb_var);
bb_var.id_display = add_instance( (void*) &bb_var);
bb_var.id_controller = add_instance( (void*) &bb_var);
bb_var.id_ia = add_instance( (void*) &bb_var);
bb_var.id_game = add_instance( (void*) &bb_var);
bb_var.SimpleBrick_SC_State = SIMPLEBRICK_SC_INIT_STATE;
bb_var.SimpleBrick_dx_var = 160 * 64 / 98;
bb_var.SimpleBrick_prevBX_var =  -1;
bb_var.SimpleBrick_XMAX_var = 160 * 64;
bb_var.SimpleBrick_YMAX_var = 128 * 64;
bb_var.SimpleBrick_BRICK_HEIGHT_var = 9;
bb_var.SimpleBrick_SCALE_var = 64;
bb_var.SimpleBrick_YDISPSIZE_var = 128;
bb_var.SimpleBrick_pady_var = 128 * 64 - 6 * 64;
bb_var.SimpleBrick_by_var = 128 * 64;
bb_var.SimpleBrick_LEFT_var = 1 * 64;
bb_var.SimpleBrick_padx_var = 128 * 64 / 2;
bb_var.SimpleBrick_lives_var = 3;
bb_var.SimpleBrick_BOTTOM_var = 128 * 64 + 8 * 64;
bb_var.SimpleBrick_BRICK_ROWS_var = 5;
bb_var.SimpleBrick_level_var = 1;
bb_var.SimpleBrick_prevPY_var =  -1;
bb_var.SimpleBrick_padlen_var = 160 * 64 / 6;
bb_var.SimpleBrick_RIGHT_var = 160 * 64 - 1 * 64;
bb_var.SimpleBrick_dy_var =  -160 * 64 / 65;
bb_var.SimpleBrick_bx_var = 160 * 64 / 2;
bb_var.SimpleBrick_prevPX_var =  -1;
bb_var.SimpleBrick_TOP_var = 14 * 64;
bb_var.SimpleBrick_prevBY_var =  -1;
bb_var.SimpleBrick_XDISPSIZE_var = 160;
bb_var.SimpleBrick_br_var = 3 * 64;
bb_var.SimpleBrick_score_var = 0;
bb_var.SimpleBrick_fgcolor_var = array_bb_SimpleBrick_fgcolor_var;
bb_var.SimpleBrick_fgcolor_var_size = 3;
bb_var.SimpleBrick_bricks_var = array_bb_SimpleBrick_bricks_var;
bb_var.SimpleBrick_bricks_var_size = 5;
bb_var.SimpleBrick_bgcolor_var = array_bb_SimpleBrick_bgcolor_var;
bb_var.SimpleBrick_bgcolor_var_size = 3;

SimpleBrick_SC_OnEntry(SIMPLEBRICK_SC_STATE, &bb_var);
}




void setup() {
initialize_configuration_SimpleBrickArduino();

}

void loop() {

// Network Listener
timer2_read();
// End Network Listener


    processMessageQueue();
}
