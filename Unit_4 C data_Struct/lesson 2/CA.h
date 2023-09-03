#ifndef CA_H_
#define CA_H_
#include "state.h"

//States
enum{
	CA_State_Waiting,
	CA_State_Driving
}CA_State_ID;

//States Functions CA
STATE_define(CA_State_Waiting);
STATE_define(CA_State_Driving);

// State Pointer to function
extern void (*CA_state)();

#endif