#include <stdint.h>
#include <stdio.h>

#include "../Headers/driver.h"
#include "../Headers/alarm.h"
#include "../Headers/mainalgo.h"
#include "../Headers/pressuresensor.h"
int main (){
	GPIO_INITIALIZATION();
	while (1)
	{
        //read pressure
        Read_send_pressure();
        check_pressure();
        check_alarm();
        Delay(100000);
	}

}
