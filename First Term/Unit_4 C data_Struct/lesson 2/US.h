#ifndef US_H_
#define US_H_
#include "state.h"

//States
enum{
	US_busy
}US_State_ID;

//States Functions CA
STATE_define(US_busy);

void US_Init();

// State Pointer to function
extern void (*US_state)();

#endif