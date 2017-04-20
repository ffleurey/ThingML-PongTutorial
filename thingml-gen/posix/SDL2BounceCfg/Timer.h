/*****************************************************/
//                    POSIX Timer
/*****************************************************/
#include <stdint.h>

#include "SDL2BounceApp.h"
#include "BouncingBall.h"


#define NB_SOFT_TIMERS 4

struct Timer_Instance {
    uint16_t listener_id;
    /*INSTANCE_INFORMATION*/
};

void Timer_setup(struct Timer_Instance *_instance);
void Timer_loop(struct Timer_Instance *_instance);

void externalMessageEnqueue(uint8_t * msg, uint8_t msgSize, uint16_t listener_id);

// Forwarding of messages Timer::SDL2BounceApp::clock::timer_start
void forward_Timer_SDL2BounceApp_send_clock_timer_start(struct SDL2BounceApp_Instance *_instance, uint8_t id, uint32_t time);
// Forwarding of messages Timer::SDL2BounceApp::clock::timer_cancel
void forward_Timer_SDL2BounceApp_send_clock_timer_cancel(struct SDL2BounceApp_Instance *_instance, uint8_t id);

