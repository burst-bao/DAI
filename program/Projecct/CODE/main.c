#include "bsp.h"
#include "mag.h"
#include "rit.h"
#include "hc05.h"
#include "menu.h"
#include "speed.h"
#include "motor.h"
#include "button.h"
#include "speedPID.h"
#include "headfile.h"
#include "mrt.h"
#include "memory.h"
//	volatile uint32 timeee1;
//	volatile uint32 timeee2;

//typedef struct {
//    uint8 a;//2 bytes
//	  uint16 b;//2 bytes(和uint8一起占4 bytes)
//	  uint32 c;//4 bytes
//}TestStructAlign1;
//test2
//typedef struct {
//    uint8 a;//4 bytes
//	  uint32 c;//4 bytes
//	  uint16 b;//4 bytes
//}TestStructAlign2;

//volatile uint8 size1;
//volatile uint8 size2;

int main(void) { 
	get_clk();
//    switch_init();
	memory_init();
	motor_init();
	speed_init();
	speedPID_init();
	Mag_init();
	oled_init();
	button_init();
  menu_init();
	mrt_init();
	hc05_init();
  EnableInterrupts;
	while(1);
///************测试字节对齐***********/
//  size1=sizeof(TestStructAlign1);
//	size2=sizeof(TestStructAlign2);
//	while(1);
///***************************************/
		
		
///************测试是否开启FPU***********/
//  uint32 i = 0;
//  float num_f = 0;
//  float a = 3.1415926;
//  float b = 87.6;
//  float c = 76.987;
//  systick_timing_ms(90);
//  systick_start();
//  timeee1=systick_getval_us(); 
//  for(i=0;i<100000;i++)
//  num_f = a * b / c;
//  timeee2=systick_getval_us(); 
//  oled_uint16(2,6,timeee2-timeee1);
//  while(1); 
//    while (1)
//    {   
//    printf("Hello Arm");
//    }
///***************************************/

}
