#include"sys.h"
//	volatile uint32 timeee1;
//	volatile uint32 timeee2;

//typedef struct {
//    uint8 a;//2 bytes
//	  uint16 b;//2 bytes(��uint8һ��ռ4 bytes)
//	  uint32 c;//4 bytes
//}TestStructAlign1;

//typedef struct {
//    uint8 a;//4 bytes
//	  uint32 c;//4 bytes
//	  uint16 b;//4 bytes
//}TestStructAlign2;

//volatile uint8 size1;
//volatile uint8 size2;

int main(void) {
	sys_init();
	for (;;) {
		sys_run();
	}
}
///************�����ֽڶ���***********/
//  size1=sizeof(TestStructAlign1);
//	size2=sizeof(TestStructAlign2);
//	while(1);
///***************************************/
		
		
///************�����Ƿ���FPU***********/
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

