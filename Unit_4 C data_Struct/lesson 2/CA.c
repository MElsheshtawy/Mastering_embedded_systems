#include "CA.h"

int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

void (*CA_state)();

void US_Set_Distance(int d){
	CA_distance = d;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_State_Waiting)) : (CA_state = STATE(CA_State_Driving));

	printf("\nUS --------distance = %d-----------> CA\n", CA_distance);
}

STATE_define(CA_State_Waiting)
{
	CA_State_ID = CA_State_Waiting;
	printf("CA_Waiting State: distance = %d , speed = %d\n", CA_distance, CA_speed);

	CA_speed = 0;
	DC_Set_Speed(CA_speed);
}

STATE_define(CA_State_Driving)
{
	CA_State_ID = CA_State_Waiting;
	printf("CA_Driving State: distance = %d , speed = %d\n", CA_distance, CA_speed);

	CA_speed = 30;
	DC_Set_Speed(CA_speed);
}