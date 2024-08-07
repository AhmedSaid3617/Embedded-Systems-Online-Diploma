#include <stdint.h>

extern uint32_t _stack_top;
extern uint32_t _E_text;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_bss;
extern uint32_t _E_bss;

extern int main(void);
void Reset_Handler(){
    // Copy data from .data section to RAM
    uint32_t data_size = (uint32_t*)&_E_DATA - (uint32_t*)&_S_DATA;
    uint32_t* p_src = (uint32_t*)&_E_text;
    uint32_t* p_dst = (uint32_t*)&_S_DATA;

    for (int i = 0; i < data_size; i++)
    {
        *(p_dst++) = *(p_src++);
    }
    
    uint32_t bss_size = (uint32_t*)&_E_DATA - (uint32_t*)&_S_DATA;
    p_dst = (uint32_t*)&_S_bss;
    for (int i = 0; i < bss_size; i++)
    {
        *p_dst++ = 0;
    }
    
    main();

}
void Default_Handler(void){
    Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void H_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Bus_Fault(void) __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));

__attribute__((section(".vectors")))
uint32_t vectors[] = {
    (uint32_t) &_stack_top,
    (uint32_t) &Reset_Handler,
    (uint32_t) &H_fault_Handler,
    (uint32_t) &MM_Fault_Handler,
    (uint32_t) &Bus_Fault,
    (uint32_t) &Usage_Fault_Handler
};