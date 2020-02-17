#ifndef BOARD_H
#define BOARD_H
#include"common.h"
#include<stdbool.h>

#define LEFT true
#define RIGHT false
#define FORWARD true
#define BACKWARD false
 
// NVIC
#define btn_priority 1
#define com_priority 2
#define mrt_priority 3

//蓝牙hc05
#define hc05KEY A27 // UNUSED
#define hc05TXD UART0_TX_A25
#define hc05RXD UART0_RX_A24
#define hc05uart USART_0
#define hc05boundrate 921600u

//直流电机*2
#define motorL0 TIMER1_PWMCH0_A18
#define motorL1 TIMER1_PWMCH1_A20
#define motorR0 TIMER2_PWMCH0_B5
#define motorR1 TIMER2_PWMCH1_B4
#define motorPinL0 A18
#define motorPinL1 A20
#define motorPinR0 B5
#define motorPinR1 B4
#define motorFreq 14561 //根据周期信号的傅里叶级数分解的理论，不能选择（3.66，4，5，6.66，10，20）kHz，超过20kHz理论上可以，但是会增加开关损耗，故选择13~17kHz之间
#define motorMax 8000 //不加u，对于各种数据，比如float，都适用
#define motorMin 3000 

//1024编码器测速
#define speedR TIMER0_COUNT1_A2
#define speedL TIMER3_COUNT0_A4
#define dirR A3  
#define dirL A5
 
// buttons pin
#define btn0 A19
#define btn1 B31
#define btn2 A0
#define btn3 B11
#define btn4 A30

#define btnOk btn0
#define btnUp btn1
#define btnDown btn2
#define btnBack btn3
#define btnSS btn4//Startup& Shutdown

#define PINT_OK PINT_CH0
#define PINT_UP PINT_CH1
#define PINT_DOWN PINT_CH2
#define PINT_BACK PINT_CH3
#define PINT_SS PINT_CH4//Startup& Shutdown

//电磁信号（ADC口）
#define mag_ADC1 ADC_CH0_A10//左1
#define mag_ADC2 ADC_CH3_A15//
#define mag_ADC3 ADC_CH4_A16//中
#define mag_ADC4 ADC_CH11_A23//右1
#define mag_ADC5 ADC_CH5_A31

//eeprom address
#define TargetSpeed_Address 0
#define SpeedKp_Address 2
#define SpeedKi_Address 3
#define SpeedKd_Address 4
#define SteerKp_Address 5
#define SteerKi_Address 6
#define SteerKd_Address 7
#define MagMax0_Address 8
#define MagMax1_Address 9
#define MagMax2_Address 10
#define Position_transit0_Address 11
#define Position_transit1_Address 12

// MRT channels
const static uint8_t menu_interval = 100,
                     speed_interval = 10,
                     magnet_interval = 35,
                     com_interval = 40; // ms
#define MRT_CH0_SCHEDULE menu_schedule
#define MRT_CH0_INTERVAL menu_interval
#define MRT_CH1_SCHEDULE com_schedule
#define MRT_CH1_INTERVAL com_interval
#define MRT_CH2_SCHEDULE magnet_schedule
#define MRT_CH2_INTERVAL magnet_interval
#define MRT_CH3_SCHEDULE speed_schedule
#define MRT_CH3_INTERVAL speed_interval

#define GET_RUN_TIM(func, time)                  \
	do {                                         \
		systick_timing_ms(90);                   \
		systick_start();                         \
		volatile uint32 t = systick_getval_ns(); \
		func();                                  \
		time = systick_getval_ns() - t;          \
	} while (0)										       

#endif // end of file
