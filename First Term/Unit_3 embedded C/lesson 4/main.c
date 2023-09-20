/* 
learn-in-depth-mohamed-elsheshtawy
toggle led on tiva-c kit
*/
#define SYSCTL_RCGC2_R (*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DIR_R (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R (*((volatile unsigned long*)0x4002551C))
#define GPIO_PORTF_DATA_R (*((volatile unsigned long*)0x400253FC))

int main(){
	SYSCTL_RCGC2_R=0x20;
	//delay to make sure portf is up and started
	volatile int delay;for(delay=0;delay<5000;delay++);
	GPIO_PORTF_DIR_R |= (1<<3); // direction is output for pin 3 portf
	GPIO_PORTF_DEN_R |= (1<<3);
	while(1)
	{
		GPIO_PORTF_DATA_R |= (1<<3);
		for(delay=0;delay<200000;delay++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay=0;delay<200000;delay++);

	}
	
	return 0;
}