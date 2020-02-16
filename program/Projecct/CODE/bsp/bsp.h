#ifndef BSP_H
#define BSP_H
#include "common.h"
#include <stdbool.h>

uint8* int2str(uint32 num);

#define LEFT true
#define RIGHT false
#define FORWARD true
#define BACKWARD false
#define menu_Interval 100
#define speedPID_Interval 10 // ms
#define mag_Interval 35
#define hc05_Interval 40
#define MotorMax 8000//不加u，对于各种数据，比如float，都适用
#define MotorMin 1000

//引脚定义

//舵机
#define sg90X TIMER4_PWMCH0_A6
#define sg90Y TIMER0_PWMCH0_A30

//蓝牙hc05
#define hc05TXD UART0_TX_A25
#define hc05RXD UART0_RX_A24
#define hc05uart USART_0

//直流电机*2
#define motorL0 TIMER1_PWMCH0_A18
#define motorL1 TIMER1_PWMCH1_A20
#define motorR0 TIMER2_PWMCH0_B5
#define motorR1 TIMER2_PWMCH1_B4
#define motorPinL0 A18
#define motorPinL1 A20
#define motorPinR0 B5
#define motorPinR1 B4

//1024编码器测速
#define speedR TIMER0_COUNT1_A2
#define speedL TIMER3_COUNT0_A4
#define dirR A3  
#define dirL A5
 
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
#endif

//eeprom address
#define TargetSpeedL_Address 0
#define TargetSpeedR_Address 1
#define SpeedKp_Address 2
#define SpeedKi_Address 3
#define SpeedKd_Address 4
#define MagKp_Address 5
#define MagKi_Address 6
#define MagKd_Address 7
#define MagMax0_Address 8
#define MagMax1_Address 9
#define MagMax2_Address 10
#define Position_transit0_Address 11
#define Position_transit1_Address 12
