#ifndef __SYSTICK_H
#define __SYSTICK_H
#include "stm32f10x_it.h"
void SysTick_Init( void );
void Delay_Us( __IO u32 us );
void Delay_Ms( __IO u32 ms ) ;

void Systick_Delay_us( __IO u32 nTime ) ;

#endif