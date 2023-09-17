#include "../Headers/pressuresensor.h"
extern int pressure_val;
void Read_send_pressure(){
    pressure_val = getPressureVal();
}