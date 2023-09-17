#include "../Headers/mainalgo.h"

// Declaring variables
short alarmstat = 0;
int pressure_threshhold = 20;
int pressure_val = 0;

void check_pressure(){
    if(pressure_val<= pressure_threshhold){
        alarmstat=1;
    }
    else{
        alarmstat = 0;
    }
}