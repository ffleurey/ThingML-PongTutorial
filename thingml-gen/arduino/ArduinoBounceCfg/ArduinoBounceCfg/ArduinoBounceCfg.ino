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


/*****************************************************************************
 * Headers for type : ArduinoBounceApp
 *****************************************************************************/


// BEGIN: Code from the c_header annotation ArduinoBounceApp

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#define TFT_CS     10
#define TFT_RST    9
#define TFT_DC     8
// END: Code from the c_header annotation ArduinoBounceApp

// Definition of the instance struct:
struct ArduinoBounceApp_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_clock;
uint16_t id_ball;
// Variables for the current instance state
int BounceApp_SC_State;
// Variables for the properties of the instance
uint16_t ArduinoBounceApp_color_var;
uint8_t Constants_XSIZE_var;
uint8_t Constants_YSIZE_var;

};
// Declaration of prototypes outgoing messages:
void BounceApp_SC_OnEntry(int state, struct ArduinoBounceApp_Instance *_instance);
void ArduinoBounceApp_handle_ball_updateBall(struct ArduinoBounceApp_Instance *_instance, uint8_t oldx, uint8_t oldy, uint8_t newx, uint8_t newy);
void ArduinoBounceApp_handle_clock_timer_timeout(struct ArduinoBounceApp_Instance *_instance, uint8_t id);
// Declaration of callbacks for incoming messages:
void register_ArduinoBounceApp_send_clock_timer_start_listener(void (*_listener)(struct ArduinoBounceApp_Instance *, uint8_t, uint32_t));
void register_external_ArduinoBounceApp_send_clock_timer_start_listener(void (*_listener)(struct ArduinoBounceApp_Instance *, uint8_t, uint32_t));
void register_ArduinoBounceApp_send_clock_timer_cancel_listener(void (*_listener)(struct ArduinoBounceApp_Instance *, uint8_t));
void register_external_ArduinoBounceApp_send_clock_timer_cancel_listener(void (*_listener)(struct ArduinoBounceApp_Instance *, uint8_t));
void register_ArduinoBounceApp_send_ball_bounce_listener(void (*_listener)(struct ArduinoBounceApp_Instance *));
void register_external_ArduinoBounceApp_send_ball_bounce_listener(void (*_listener)(struct ArduinoBounceApp_Instance *));
void register_ArduinoBounceApp_send_ball_stop_listener(void (*_listener)(struct ArduinoBounceApp_Instance *));
void register_external_ArduinoBounceApp_send_ball_stop_listener(void (*_listener)(struct ArduinoBounceApp_Instance *));

// Definition of the states:
#define BOUNCEAPP_SC_STATE 0
#define BOUNCEAPP_SC_WELCOME_STATE 1
#define BOUNCEAPP_SC_BOUNCING_STATE 2


//timer2
// Definition of Enumeration  Color
#define COLOR_BLACK 0x0000
#define COLOR_WHITE 0xFFFF


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

#define MAX_INSTANCES 18
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
 * Implementation for type : BouncingBall
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void BouncingBall_SC_OnExit(int state, struct BouncingBall_Instance *_instance);
//Prototypes: Message Sending
void BouncingBall_send_ball_updateBall(struct BouncingBall_Instance *_instance, uint8_t oldx, uint8_t oldy, uint8_t newx, uint8_t newy);
//Prototypes: Function
uint8_t f_BouncingBall_getBallX(struct BouncingBall_Instance *_instance, uint16_t bx);
uint8_t f_BouncingBall_getBallY(struct BouncingBall_Instance *_instance, uint16_t by);
// Declaration of functions:
// Definition of function getBallX
uint8_t f_BouncingBall_getBallX(struct BouncingBall_Instance *_instance, uint16_t bx) {
;long l = bx;
l = l * (_instance->Constants_XSIZE_var - 8);
l = l / (_instance->BouncingBall_MAX_var + 1) + 4;
return l;
}
// Definition of function getBallY
uint8_t f_BouncingBall_getBallY(struct BouncingBall_Instance *_instance, uint16_t by) {
;long l = by;
l = l * (_instance->Constants_YSIZE_var - 8);
l = l / (_instance->BouncingBall_MAX_var + 1) + 4;
return l;
}

// Sessions functionss:


// On Entry Actions:
void BouncingBall_SC_OnEntry(int state, struct BouncingBall_Instance *_instance) {
switch(state) {
case BOUNCINGBALL_SC_STATE:{
_instance->BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
BouncingBall_SC_OnEntry(_instance->BouncingBall_SC_State, _instance);
break;
}
case BOUNCINGBALL_SC_STOP_STATE:{
break;
}
case BOUNCINGBALL_SC_BOUNCE_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void BouncingBall_SC_OnExit(int state, struct BouncingBall_Instance *_instance) {
switch(state) {
case BOUNCINGBALL_SC_STATE:{
BouncingBall_SC_OnExit(_instance->BouncingBall_SC_State, _instance);
break;}
case BOUNCINGBALL_SC_STOP_STATE:{
break;}
case BOUNCINGBALL_SC_BOUNCE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void BouncingBall_handle_ball_bounce(struct BouncingBall_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BouncingBall_SC_State_event_consumed = 0;
if (_instance->BouncingBall_SC_State == BOUNCINGBALL_SC_STOP_STATE) {
if (BouncingBall_SC_State_event_consumed == 0 && 1) {
BouncingBall_SC_OnExit(BOUNCINGBALL_SC_STOP_STATE, _instance);
_instance->BouncingBall_SC_State = BOUNCINGBALL_SC_BOUNCE_STATE;
BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_BOUNCE_STATE, _instance);
BouncingBall_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BouncingBall_handle_ball_stop(struct BouncingBall_Instance *_instance) {
if(!(_instance->active)) return;
//Region SC
uint8_t BouncingBall_SC_State_event_consumed = 0;
if (_instance->BouncingBall_SC_State == BOUNCINGBALL_SC_BOUNCE_STATE) {
if (BouncingBall_SC_State_event_consumed == 0 && 1) {
BouncingBall_SC_OnExit(BOUNCINGBALL_SC_BOUNCE_STATE, _instance);
_instance->BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_STOP_STATE, _instance);
BouncingBall_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void BouncingBall_handle_clock_timer_timeout(struct BouncingBall_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SC
uint8_t BouncingBall_SC_State_event_consumed = 0;
if (_instance->BouncingBall_SC_State == BOUNCINGBALL_SC_BOUNCE_STATE) {
if (BouncingBall_SC_State_event_consumed == 0 && id == 1) {
_instance->BouncingBall_bx_var = _instance->BouncingBall_bx_var + _instance->BouncingBall_dx_var;
_instance->BouncingBall_by_var = _instance->BouncingBall_by_var + _instance->BouncingBall_dy_var;
if(_instance->BouncingBall_bx_var < 0) {
_instance->BouncingBall_dx_var =  -_instance->BouncingBall_dx_var;
_instance->BouncingBall_bx_var =  -_instance->BouncingBall_bx_var;

} else {
if(_instance->BouncingBall_bx_var > _instance->BouncingBall_MAX_var) {
_instance->BouncingBall_dx_var =  -_instance->BouncingBall_dx_var;
_instance->BouncingBall_bx_var = _instance->BouncingBall_bx_var - (_instance->BouncingBall_bx_var - _instance->BouncingBall_MAX_var);

}

}
if(_instance->BouncingBall_by_var < 0) {
_instance->BouncingBall_dy_var =  -_instance->BouncingBall_dy_var;
_instance->BouncingBall_by_var =  -_instance->BouncingBall_by_var;

} else {
if(_instance->BouncingBall_by_var > _instance->BouncingBall_MAX_var) {
_instance->BouncingBall_dy_var =  -_instance->BouncingBall_dy_var;
_instance->BouncingBall_by_var = _instance->BouncingBall_by_var - (_instance->BouncingBall_by_var - _instance->BouncingBall_MAX_var);

}

}
;uint8_t newX = f_BouncingBall_getBallX(_instance, _instance->BouncingBall_bx_var);
;uint8_t newY = f_BouncingBall_getBallY(_instance, _instance->BouncingBall_by_var);
BouncingBall_send_ball_updateBall(_instance, _instance->BouncingBall_SC_BOUNCE_lastX_var, _instance->BouncingBall_SC_BOUNCE_lastY_var, newX, newY);
_instance->BouncingBall_SC_BOUNCE_lastX_var = newX;
_instance->BouncingBall_SC_BOUNCE_lastY_var = newY;
BouncingBall_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
void (*external_BouncingBall_send_ball_updateBall_listener)(struct BouncingBall_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void (*BouncingBall_send_ball_updateBall_listener)(struct BouncingBall_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)= 0x0;
void register_external_BouncingBall_send_ball_updateBall_listener(void (*_listener)(struct BouncingBall_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
external_BouncingBall_send_ball_updateBall_listener = _listener;
}
void register_BouncingBall_send_ball_updateBall_listener(void (*_listener)(struct BouncingBall_Instance *, uint8_t, uint8_t, uint8_t, uint8_t)){
BouncingBall_send_ball_updateBall_listener = _listener;
}
void BouncingBall_send_ball_updateBall(struct BouncingBall_Instance *_instance, uint8_t oldx, uint8_t oldy, uint8_t newx, uint8_t newy){
if (BouncingBall_send_ball_updateBall_listener != 0x0) BouncingBall_send_ball_updateBall_listener(_instance, oldx, oldy, newx, newy);
if (external_BouncingBall_send_ball_updateBall_listener != 0x0) external_BouncingBall_send_ball_updateBall_listener(_instance, oldx, oldy, newx, newy);
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
// Forwarding of messages timer2::ArduinoBounceApp::clock::timer_start
void forward_timer2_ArduinoBounceApp_send_clock_timer_start(struct ArduinoBounceApp_Instance *_instance, uint8_t id, uint32_t time){
timer2_timer_start(id, time);}

// Forwarding of messages timer2::ArduinoBounceApp::clock::timer_cancel
void forward_timer2_ArduinoBounceApp_send_clock_timer_cancel(struct ArduinoBounceApp_Instance *_instance, uint8_t id){
timer2_timer_cancel(id);}

/*****************************************************************************
 * Implementation for type : ArduinoBounceApp
 *****************************************************************************/


// BEGIN: Code from the c_global annotation ArduinoBounceApp
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
// END: Code from the c_global annotation ArduinoBounceApp

// Declaration of prototypes:
//Prototypes: State Machine
void BounceApp_SC_OnExit(int state, struct ArduinoBounceApp_Instance *_instance);
//Prototypes: Message Sending
void ArduinoBounceApp_send_clock_timer_start(struct ArduinoBounceApp_Instance *_instance, uint8_t id, uint32_t time);
void ArduinoBounceApp_send_clock_timer_cancel(struct ArduinoBounceApp_Instance *_instance, uint8_t id);
void ArduinoBounceApp_send_ball_bounce(struct ArduinoBounceApp_Instance *_instance);
void ArduinoBounceApp_send_ball_stop(struct ArduinoBounceApp_Instance *_instance);
//Prototypes: Function
void f_ArduinoBounceApp_initDisplay(struct ArduinoBounceApp_Instance *_instance);
void f_ArduinoBounceApp_clearScreen(struct ArduinoBounceApp_Instance *_instance);
void f_ArduinoBounceApp_setColor(struct ArduinoBounceApp_Instance *_instance, uint16_t c);
void f_ArduinoBounceApp_drawRect(struct ArduinoBounceApp_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void f_ArduinoBounceApp_fillRect(struct ArduinoBounceApp_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height);
void f_ArduinoBounceApp_drawText(struct ArduinoBounceApp_Instance *_instance, uint8_t x, uint8_t y, uint8_t size, char * text);
// Declaration of functions:
// Definition of function initDisplay
void f_ArduinoBounceApp_initDisplay(struct ArduinoBounceApp_Instance *_instance) {
tft.initR(INITR_BLACKTAB);
		tft.fillScreen(ST7735_BLACK);
		tft.setRotation(3);
}
// Definition of function clearScreen
void f_ArduinoBounceApp_clearScreen(struct ArduinoBounceApp_Instance *_instance) {
tft.fillScreen(ST7735_BLACK);
}
// Definition of function setColor
void f_ArduinoBounceApp_setColor(struct ArduinoBounceApp_Instance *_instance, uint16_t c) {
_instance->ArduinoBounceApp_color_var = c;
}
// Definition of function drawRect
void f_ArduinoBounceApp_drawRect(struct ArduinoBounceApp_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
tft.drawRect(x,y,width,height,_instance->ArduinoBounceApp_color_var);
}
// Definition of function fillRect
void f_ArduinoBounceApp_fillRect(struct ArduinoBounceApp_Instance *_instance, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
tft.fillRect(x,y,width,height,_instance->ArduinoBounceApp_color_var);
}
// Definition of function drawText
void f_ArduinoBounceApp_drawText(struct ArduinoBounceApp_Instance *_instance, uint8_t x, uint8_t y, uint8_t size, char * text) {
tft.setCursor(x, y);
tft.setTextColor(_instance->ArduinoBounceApp_color_var, ST7735_BLACK);
tft.setTextSize(size);
tft.setTextWrap(true);
tft.print(text);
}

// Sessions functionss:


// On Entry Actions:
void BounceApp_SC_OnEntry(int state, struct ArduinoBounceApp_Instance *_instance) {
switch(state) {
case BOUNCEAPP_SC_STATE:{
_instance->BounceApp_SC_State = BOUNCEAPP_SC_WELCOME_STATE;
f_ArduinoBounceApp_initDisplay(_instance);
BounceApp_SC_OnEntry(_instance->BounceApp_SC_State, _instance);
break;
}
case BOUNCEAPP_SC_WELCOME_STATE:{
f_ArduinoBounceApp_clearScreen(_instance);
f_ArduinoBounceApp_setColor(_instance, COLOR_WHITE);
f_ArduinoBounceApp_fillRect(_instance, 0, 0, _instance->Constants_XSIZE_var, _instance->Constants_YSIZE_var);
f_ArduinoBounceApp_setColor(_instance, COLOR_BLACK);
f_ArduinoBounceApp_fillRect(_instance, 5, 5, _instance->Constants_XSIZE_var - 10, _instance->Constants_YSIZE_var - 10);
f_ArduinoBounceApp_setColor(_instance, COLOR_WHITE);
f_ArduinoBounceApp_drawText(_instance, 30, _instance->Constants_YSIZE_var / 2 - 10, 2, "Bounce !");
ArduinoBounceApp_send_clock_timer_start(_instance, 0, 2000);
break;
}
case BOUNCEAPP_SC_BOUNCING_STATE:{
f_ArduinoBounceApp_clearScreen(_instance);
f_ArduinoBounceApp_drawRect(_instance, 0, 0, _instance->Constants_XSIZE_var - 1, _instance->Constants_YSIZE_var - 1);
ArduinoBounceApp_send_ball_bounce(_instance);
ArduinoBounceApp_send_clock_timer_start(_instance, 1, 30);
break;
}
default: break;
}
}

// On Exit Actions:
void BounceApp_SC_OnExit(int state, struct ArduinoBounceApp_Instance *_instance) {
switch(state) {
case BOUNCEAPP_SC_STATE:{
BounceApp_SC_OnExit(_instance->BounceApp_SC_State, _instance);
break;}
case BOUNCEAPP_SC_WELCOME_STATE:{
break;}
case BOUNCEAPP_SC_BOUNCING_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void ArduinoBounceApp_handle_ball_updateBall(struct ArduinoBounceApp_Instance *_instance, uint8_t oldx, uint8_t oldy, uint8_t newx, uint8_t newy) {
if(!(_instance->active)) return;
//Region SC
uint8_t BounceApp_SC_State_event_consumed = 0;
if (_instance->BounceApp_SC_State == BOUNCEAPP_SC_BOUNCING_STATE) {
if (BounceApp_SC_State_event_consumed == 0 && 1) {
f_ArduinoBounceApp_setColor(_instance, COLOR_BLACK);
f_ArduinoBounceApp_fillRect(_instance, oldx - 3, oldy - 3, 6, 6);
f_ArduinoBounceApp_setColor(_instance, COLOR_WHITE);
f_ArduinoBounceApp_fillRect(_instance, newx - 2, newy - 3, 4, 6);
f_ArduinoBounceApp_fillRect(_instance, newx - 3, newy - 2, 6, 4);
BounceApp_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}
void ArduinoBounceApp_handle_clock_timer_timeout(struct ArduinoBounceApp_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region SC
uint8_t BounceApp_SC_State_event_consumed = 0;
if (_instance->BounceApp_SC_State == BOUNCEAPP_SC_WELCOME_STATE) {
if (BounceApp_SC_State_event_consumed == 0 && id == 0) {
BounceApp_SC_OnExit(BOUNCEAPP_SC_WELCOME_STATE, _instance);
_instance->BounceApp_SC_State = BOUNCEAPP_SC_BOUNCING_STATE;
BounceApp_SC_OnEntry(BOUNCEAPP_SC_BOUNCING_STATE, _instance);
BounceApp_SC_State_event_consumed = 1;
}
}
else if (_instance->BounceApp_SC_State == BOUNCEAPP_SC_BOUNCING_STATE) {
if (BounceApp_SC_State_event_consumed == 0 && id == 1) {
ArduinoBounceApp_send_clock_timer_start(_instance, 1, 30);
BounceApp_SC_State_event_consumed = 1;
}
}
//End Region SC
//End dsregion SC
//Session list: 
}

// Observers for outgoing messages:
void (*external_ArduinoBounceApp_send_clock_timer_start_listener)(struct ArduinoBounceApp_Instance *, uint8_t, uint32_t)= 0x0;
void (*ArduinoBounceApp_send_clock_timer_start_listener)(struct ArduinoBounceApp_Instance *, uint8_t, uint32_t)= 0x0;
void register_external_ArduinoBounceApp_send_clock_timer_start_listener(void (*_listener)(struct ArduinoBounceApp_Instance *, uint8_t, uint32_t)){
external_ArduinoBounceApp_send_clock_timer_start_listener = _listener;
}
void register_ArduinoBounceApp_send_clock_timer_start_listener(void (*_listener)(struct ArduinoBounceApp_Instance *, uint8_t, uint32_t)){
ArduinoBounceApp_send_clock_timer_start_listener = _listener;
}
void ArduinoBounceApp_send_clock_timer_start(struct ArduinoBounceApp_Instance *_instance, uint8_t id, uint32_t time){
if (ArduinoBounceApp_send_clock_timer_start_listener != 0x0) ArduinoBounceApp_send_clock_timer_start_listener(_instance, id, time);
if (external_ArduinoBounceApp_send_clock_timer_start_listener != 0x0) external_ArduinoBounceApp_send_clock_timer_start_listener(_instance, id, time);
;
}
void (*external_ArduinoBounceApp_send_clock_timer_cancel_listener)(struct ArduinoBounceApp_Instance *, uint8_t)= 0x0;
void (*ArduinoBounceApp_send_clock_timer_cancel_listener)(struct ArduinoBounceApp_Instance *, uint8_t)= 0x0;
void register_external_ArduinoBounceApp_send_clock_timer_cancel_listener(void (*_listener)(struct ArduinoBounceApp_Instance *, uint8_t)){
external_ArduinoBounceApp_send_clock_timer_cancel_listener = _listener;
}
void register_ArduinoBounceApp_send_clock_timer_cancel_listener(void (*_listener)(struct ArduinoBounceApp_Instance *, uint8_t)){
ArduinoBounceApp_send_clock_timer_cancel_listener = _listener;
}
void ArduinoBounceApp_send_clock_timer_cancel(struct ArduinoBounceApp_Instance *_instance, uint8_t id){
if (ArduinoBounceApp_send_clock_timer_cancel_listener != 0x0) ArduinoBounceApp_send_clock_timer_cancel_listener(_instance, id);
if (external_ArduinoBounceApp_send_clock_timer_cancel_listener != 0x0) external_ArduinoBounceApp_send_clock_timer_cancel_listener(_instance, id);
;
}
void (*external_ArduinoBounceApp_send_ball_bounce_listener)(struct ArduinoBounceApp_Instance *)= 0x0;
void (*ArduinoBounceApp_send_ball_bounce_listener)(struct ArduinoBounceApp_Instance *)= 0x0;
void register_external_ArduinoBounceApp_send_ball_bounce_listener(void (*_listener)(struct ArduinoBounceApp_Instance *)){
external_ArduinoBounceApp_send_ball_bounce_listener = _listener;
}
void register_ArduinoBounceApp_send_ball_bounce_listener(void (*_listener)(struct ArduinoBounceApp_Instance *)){
ArduinoBounceApp_send_ball_bounce_listener = _listener;
}
void ArduinoBounceApp_send_ball_bounce(struct ArduinoBounceApp_Instance *_instance){
if (ArduinoBounceApp_send_ball_bounce_listener != 0x0) ArduinoBounceApp_send_ball_bounce_listener(_instance);
if (external_ArduinoBounceApp_send_ball_bounce_listener != 0x0) external_ArduinoBounceApp_send_ball_bounce_listener(_instance);
;
}
void (*external_ArduinoBounceApp_send_ball_stop_listener)(struct ArduinoBounceApp_Instance *)= 0x0;
void (*ArduinoBounceApp_send_ball_stop_listener)(struct ArduinoBounceApp_Instance *)= 0x0;
void register_external_ArduinoBounceApp_send_ball_stop_listener(void (*_listener)(struct ArduinoBounceApp_Instance *)){
external_ArduinoBounceApp_send_ball_stop_listener = _listener;
}
void register_ArduinoBounceApp_send_ball_stop_listener(void (*_listener)(struct ArduinoBounceApp_Instance *)){
ArduinoBounceApp_send_ball_stop_listener = _listener;
}
void ArduinoBounceApp_send_ball_stop(struct ArduinoBounceApp_Instance *_instance){
if (ArduinoBounceApp_send_ball_stop_listener != 0x0) ArduinoBounceApp_send_ball_stop_listener(_instance);
if (external_ArduinoBounceApp_send_ball_stop_listener != 0x0) external_ArduinoBounceApp_send_ball_stop_listener(_instance);
;
}






/*****************************************************************************
 * Definitions for configuration : ArduinoBounceCfg
 *****************************************************************************/

//Declaration of instance variables
//Instance b2
// Variables for the properties of the instance
struct BouncingBall_Instance b2_var;
// Variables for the sessions of the instance
//Instance a
// Variables for the properties of the instance
struct ArduinoBounceApp_Instance a_var;
// Variables for the sessions of the instance
//Instance b4
// Variables for the properties of the instance
struct BouncingBall_Instance b4_var;
// Variables for the sessions of the instance
//Instance b1
// Variables for the properties of the instance
struct BouncingBall_Instance b1_var;
// Variables for the sessions of the instance
//Instance b3
// Variables for the properties of the instance
struct BouncingBall_Instance b3_var;
// Variables for the sessions of the instance
//Instance b5
// Variables for the properties of the instance
struct BouncingBall_Instance b5_var;
// Variables for the sessions of the instance


// Enqueue of messages BouncingBall::ball::updateBall
void enqueue_BouncingBall_send_ball_updateBall(struct BouncingBall_Instance *_instance, uint8_t oldx, uint8_t oldy, uint8_t newx, uint8_t newy){
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_ball >> 8) & 0xFF );
_fifo_enqueue( _instance->id_ball & 0xFF );

// parameter oldx
union u_oldx_t {
uint8_t p;
byte bytebuffer[1];
} u_oldx;
u_oldx.p = oldx;
_fifo_enqueue(u_oldx.bytebuffer[0] & 0xFF );

// parameter oldy
union u_oldy_t {
uint8_t p;
byte bytebuffer[1];
} u_oldy;
u_oldy.p = oldy;
_fifo_enqueue(u_oldy.bytebuffer[0] & 0xFF );

// parameter newx
union u_newx_t {
uint8_t p;
byte bytebuffer[1];
} u_newx;
u_newx.p = newx;
_fifo_enqueue(u_newx.bytebuffer[0] & 0xFF );

// parameter newy
union u_newy_t {
uint8_t p;
byte bytebuffer[1];
} u_newy;
u_newy.p = newy;
_fifo_enqueue(u_newy.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages ArduinoBounceApp::ball::bounce
void enqueue_ArduinoBounceApp_send_ball_bounce(struct ArduinoBounceApp_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_ball >> 8) & 0xFF );
_fifo_enqueue( _instance->id_ball & 0xFF );
}
}
// Enqueue of messages ArduinoBounceApp::ball::stop
void enqueue_ArduinoBounceApp_send_ball_stop(struct ArduinoBounceApp_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_ball >> 8) & 0xFF );
_fifo_enqueue( _instance->id_ball & 0xFF );
}
}


//New dispatcher for messages
void dispatch_updateBall(uint16_t sender, uint8_t param_oldx, uint8_t param_oldy, uint8_t param_newx, uint8_t param_newy) {
if (sender == b4_var.id_ball) {
ArduinoBounceApp_handle_ball_updateBall(&a_var, param_oldx, param_oldy, param_newx, param_newy);

}
if (sender == b1_var.id_ball) {
ArduinoBounceApp_handle_ball_updateBall(&a_var, param_oldx, param_oldy, param_newx, param_newy);

}
if (sender == b3_var.id_ball) {
ArduinoBounceApp_handle_ball_updateBall(&a_var, param_oldx, param_oldy, param_newx, param_newy);

}
if (sender == b5_var.id_ball) {
ArduinoBounceApp_handle_ball_updateBall(&a_var, param_oldx, param_oldy, param_newx, param_newy);

}
if (sender == b2_var.id_ball) {
ArduinoBounceApp_handle_ball_updateBall(&a_var, param_oldx, param_oldy, param_newx, param_newy);

}

}


//New dispatcher for messages
void dispatch_bounce(uint16_t sender) {
if (sender == a_var.id_ball) {
BouncingBall_handle_ball_bounce(&b4_var);
BouncingBall_handle_ball_bounce(&b1_var);
BouncingBall_handle_ball_bounce(&b3_var);
BouncingBall_handle_ball_bounce(&b5_var);
BouncingBall_handle_ball_bounce(&b2_var);

}

}


//New dispatcher for messages
void dispatch_stop(uint16_t sender) {
if (sender == a_var.id_ball) {
BouncingBall_handle_ball_stop(&b4_var);
BouncingBall_handle_ball_stop(&b1_var);
BouncingBall_handle_ball_stop(&b3_var);
BouncingBall_handle_ball_stop(&b5_var);
BouncingBall_handle_ball_stop(&b2_var);

}

}


//New dispatcher for messages
void dispatch_timer_timeout(uint16_t sender, uint8_t param_id) {
if (sender == timer2_instance.listener_id) {
BouncingBall_handle_clock_timer_timeout(&b3_var, param_id);

}
if (sender == timer2_instance.listener_id) {
ArduinoBounceApp_handle_clock_timer_timeout(&a_var, param_id);

}
if (sender == timer2_instance.listener_id) {
BouncingBall_handle_clock_timer_timeout(&b4_var, param_id);

}
if (sender == timer2_instance.listener_id) {
BouncingBall_handle_clock_timer_timeout(&b1_var, param_id);

}
if (sender == timer2_instance.listener_id) {
BouncingBall_handle_clock_timer_timeout(&b5_var, param_id);

}
if (sender == timer2_instance.listener_id) {
BouncingBall_handle_clock_timer_timeout(&b2_var, param_id);

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
case 2:{
byte mbuf[8 - 2];
while (mbufi < (8 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_updateBall = 2;
union u_updateBall_oldx_t {
uint8_t p;
byte bytebuffer[1];
} u_updateBall_oldx;
u_updateBall_oldx.bytebuffer[0] = mbuf[mbufi_updateBall + 0];
mbufi_updateBall += 1;
union u_updateBall_oldy_t {
uint8_t p;
byte bytebuffer[1];
} u_updateBall_oldy;
u_updateBall_oldy.bytebuffer[0] = mbuf[mbufi_updateBall + 0];
mbufi_updateBall += 1;
union u_updateBall_newx_t {
uint8_t p;
byte bytebuffer[1];
} u_updateBall_newx;
u_updateBall_newx.bytebuffer[0] = mbuf[mbufi_updateBall + 0];
mbufi_updateBall += 1;
union u_updateBall_newy_t {
uint8_t p;
byte bytebuffer[1];
} u_updateBall_newy;
u_updateBall_newy.bytebuffer[0] = mbuf[mbufi_updateBall + 0];
mbufi_updateBall += 1;
dispatch_updateBall((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_updateBall_oldx.p /* oldx */ ,
 u_updateBall_oldy.p /* oldy */ ,
 u_updateBall_newx.p /* newx */ ,
 u_updateBall_newy.p /* newy */ );
break;
}
case 3:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_bounce = 2;
dispatch_bounce((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 4:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_stop = 2;
dispatch_stop((mbuf[0] << 8) + mbuf[1] /* instance port*/);
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
}
return 1;
}

void forward_ArduinoBounceApp_send_clock_timer_start(struct ArduinoBounceApp_Instance *_instance, uint8_t id, uint32_t time){
if(_instance->id_clock == a_var.id_clock) {
forward_timer2_ArduinoBounceApp_send_clock_timer_start(_instance, id, time);
}
}
void forward_ArduinoBounceApp_send_clock_timer_cancel(struct ArduinoBounceApp_Instance *_instance, uint8_t id){
if(_instance->id_clock == a_var.id_clock) {
forward_timer2_ArduinoBounceApp_send_clock_timer_cancel(_instance, id);
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

void initialize_configuration_ArduinoBounceCfg() {
// Initialize connectors
register_external_ArduinoBounceApp_send_clock_timer_start_listener(&forward_ArduinoBounceApp_send_clock_timer_start);
register_external_ArduinoBounceApp_send_clock_timer_cancel_listener(&forward_ArduinoBounceApp_send_clock_timer_cancel);
register_BouncingBall_send_ball_updateBall_listener(&enqueue_BouncingBall_send_ball_updateBall);
register_ArduinoBounceApp_send_ball_bounce_listener(&enqueue_ArduinoBounceApp_send_ball_bounce);
register_ArduinoBounceApp_send_ball_stop_listener(&enqueue_ArduinoBounceApp_send_ball_stop);

// Init the ID, state variables and properties for external connector timer2
// Init the ID, state variables and properties for external connector timer2
// Init the ID, state variables and properties for external connector timer2
// Init the ID, state variables and properties for external connector timer2
// Init the ID, state variables and properties for external connector timer2
// Init the ID, state variables and properties for external connector timer2

// Network Initialization

timer2_instance.listener_id = add_instance(&timer2_instance);

timer2_setup();

// End Network Initialization

// Init the ID, state variables and properties for instance b2
b2_var.active = true;
b2_var.id_clock = add_instance( (void*) &b2_var);
b2_var.id_ball = add_instance( (void*) &b2_var);
b2_var.BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
b2_var.BouncingBall_MAX_var = 10000;
b2_var.BouncingBall_bx_var = 10000 / 2;
b2_var.BouncingBall_by_var = 10000 / 2;
b2_var.BouncingBall_dx_var = 155;
b2_var.BouncingBall_dy_var =  -138;
b2_var.Constants_XSIZE_var = 160;
b2_var.Constants_YSIZE_var = 128;
b2_var.BouncingBall_SC_BOUNCE_lastX_var = 200;
b2_var.BouncingBall_SC_BOUNCE_lastY_var = 200;

BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_STATE, &b2_var);
// Init the ID, state variables and properties for instance b4
b4_var.active = true;
b4_var.id_clock = add_instance( (void*) &b4_var);
b4_var.id_ball = add_instance( (void*) &b4_var);
b4_var.BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
b4_var.BouncingBall_MAX_var = 10000;
b4_var.BouncingBall_bx_var = 10000 / 2;
b4_var.BouncingBall_by_var = 10000 / 2;
b4_var.BouncingBall_dx_var = 192;
b4_var.BouncingBall_dy_var =  -62;
b4_var.Constants_XSIZE_var = 160;
b4_var.Constants_YSIZE_var = 128;
b4_var.BouncingBall_SC_BOUNCE_lastX_var = 200;
b4_var.BouncingBall_SC_BOUNCE_lastY_var = 200;

BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_STATE, &b4_var);
// Init the ID, state variables and properties for instance b5
b5_var.active = true;
b5_var.id_clock = add_instance( (void*) &b5_var);
b5_var.id_ball = add_instance( (void*) &b5_var);
b5_var.BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
b5_var.BouncingBall_MAX_var = 10000;
b5_var.BouncingBall_bx_var = 10000 / 2;
b5_var.BouncingBall_by_var = 10000 / 2;
b5_var.BouncingBall_dx_var = 78;
b5_var.BouncingBall_dy_var = 135;
b5_var.Constants_XSIZE_var = 160;
b5_var.Constants_YSIZE_var = 128;
b5_var.BouncingBall_SC_BOUNCE_lastX_var = 200;
b5_var.BouncingBall_SC_BOUNCE_lastY_var = 200;

BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_STATE, &b5_var);
// Init the ID, state variables and properties for instance b1
b1_var.active = true;
b1_var.id_clock = add_instance( (void*) &b1_var);
b1_var.id_ball = add_instance( (void*) &b1_var);
b1_var.BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
b1_var.BouncingBall_MAX_var = 10000;
b1_var.BouncingBall_bx_var = 10000 / 2;
b1_var.BouncingBall_by_var = 10000 / 2;
b1_var.BouncingBall_dx_var =  -105;
b1_var.BouncingBall_dy_var = 190;
b1_var.Constants_XSIZE_var = 160;
b1_var.Constants_YSIZE_var = 128;
b1_var.BouncingBall_SC_BOUNCE_lastX_var = 200;
b1_var.BouncingBall_SC_BOUNCE_lastY_var = 200;

BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_STATE, &b1_var);
// Init the ID, state variables and properties for instance b3
b3_var.active = true;
b3_var.id_clock = add_instance( (void*) &b3_var);
b3_var.id_ball = add_instance( (void*) &b3_var);
b3_var.BouncingBall_SC_State = BOUNCINGBALL_SC_STOP_STATE;
b3_var.BouncingBall_MAX_var = 10000;
b3_var.BouncingBall_bx_var = 10000 / 2;
b3_var.BouncingBall_by_var = 10000 / 2;
b3_var.BouncingBall_dx_var =  -85;
b3_var.BouncingBall_dy_var =  -257;
b3_var.Constants_XSIZE_var = 160;
b3_var.Constants_YSIZE_var = 128;
b3_var.BouncingBall_SC_BOUNCE_lastX_var = 200;
b3_var.BouncingBall_SC_BOUNCE_lastY_var = 200;

BouncingBall_SC_OnEntry(BOUNCINGBALL_SC_STATE, &b3_var);
// Init the ID, state variables and properties for instance a
a_var.active = true;
a_var.id_clock = add_instance( (void*) &a_var);
a_var.id_ball = add_instance( (void*) &a_var);
a_var.BounceApp_SC_State = BOUNCEAPP_SC_WELCOME_STATE;
a_var.ArduinoBounceApp_color_var = COLOR_BLACK;
a_var.Constants_XSIZE_var = 160;
a_var.Constants_YSIZE_var = 128;

BounceApp_SC_OnEntry(BOUNCEAPP_SC_STATE, &a_var);
}




void setup() {
initialize_configuration_ArduinoBounceCfg();

}

void loop() {

// Network Listener
timer2_read();
// End Network Listener


    processMessageQueue();
}
