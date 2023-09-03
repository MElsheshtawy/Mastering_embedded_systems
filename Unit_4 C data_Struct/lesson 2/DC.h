#ifndef DC_H_
#define DC_H_
#include "state.h"

//states
enum{
	DC_idle,
	DC_busy
}DC_State_ID;


//States Functions CA
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_Init();

// State Pointer to function
extern void (*DC_state)();


#endif