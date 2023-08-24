#include <stdint.h>

#define STACK_Start_SP 0x20001000
extern int main(void);
extern unsigned int _stack_top;
void Reset_Handler(void);
void Default_Handler()
{
    Reset_Handler();
}

void NMI_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;
void H_fault_Handler(void) __attribute__ ((weak, alias ("Default_Handler")));;

// booking 1024 bytes located by .bss through un-initialized array of int with 256 elements (256 * 4 = 1024)
static unsigned long Stack_top[256];


void (* const g_p_fn_Vectors[])()__attribute__((section(".vectors"))) =
{
	(void (*)()) ((unsigned long) Stack_top + sizeof(Stack_top)),
	&Reset_Handler, 
	&NMI_Handler, 
	&H_fault_Handler
};
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;
extern unsigned int _E_TEXT;

void Reset_Handler(void)
{
    int i;
    unsigned int DATA_size = (unsigned char *)&_E_DATA - (unsigned char *)&_S_DATA;
    unsigned char *P_src = (unsigned char *)&_E_TEXT;
    unsigned char *P_dst = (unsigned char *)&_S_DATA;
    for (i = 0; i < DATA_size; i++)
    {
        *((unsigned char *)P_dst++) = *((unsigned char *)P_src++);
    }
    unsigned int bss_size = (unsigned char *)&_E_BSS - (unsigned char *)&_S_BSS;
    P_dst = (unsigned char *)&_S_BSS;
    for (i = 0; i < bss_size; i++)
    {
        *((unsigned char *)P_dst++) = (unsigned char)0;
    }
    main();
}