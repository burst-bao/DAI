#include "LPC546XX_mrt.h"
#include "LPC546XX_pll.h"
#include "speedPID.h"
#include "hc05.h"
#include "mag.h"
#include "mrt.h"
//#include "LPC546XX_systick.h"
//#include "SEEKFREE_OLED.h"

//	volatile uint32 timeee1;
//	volatile uint32 timeee2;

void mrt_init(void){
	mrt_pit_init_ms(MRT_CH0,speedPID_Interval);
	mrt_pit_init_ms(MRT_CH1,hc05_Interval);
	mrt_pit_init_ms(MRT_CH2,mag_Interval);
//	mrt_pit_init_ms(MRT_CH3,menu_Interval);
}

void MRT0_IRQHandler() { 
	if(MRT_FLAG_READ(MRT_CH0)==1){
	MRT_FLAG_CLR(MRT_CH0);
//  systick_timing_ms(90);
//  systick_start();
//  timeee1=systick_getval_us(); 
	speedPID_schedule();
//  timeee2=systick_getval_us(); 
//  oled_uint16(2,7,timeee2-timeee1);
	}

	if(MRT_FLAG_READ(MRT_CH1)==1){
	MRT_FLAG_CLR(MRT_CH1);
//  systick_timing_ms(90);
//  systick_start();
//  timeee1=systick_getval_us(); 
  hc05_schedule();
//  timeee2=systick_getval_us(); 
//  oled_uint16(2+6*6,7,timeee2-timeee1);
	}
	if(MRT_FLAG_READ(MRT_CH2)==1){
	MRT_FLAG_CLR(MRT_CH2);
//  systick_timing_ms(90);
//  systick_start();
//  timeee1=systick_getval_us();
  mag_schedule();
//  timeee2=systick_getval_us();
//  oled_uint16(2+6*12,7,timeee2-timeee1);
	}
//	if(MRT_FLAG_READ(MRT_CH3)==1){
//	MRT_FLAG_CLR(MRT_CH3);
////  systick_timing_ms(90);
////  systick_start();
////  timeee1=systick_getval_us();
//  menu_schedule();
////  timeee2=systick_getval_us();
////  oled_uint16(2+6*12,7,timeee2-timeee1);
//	}
}


