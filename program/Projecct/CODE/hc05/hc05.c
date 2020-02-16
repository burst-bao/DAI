//#include "LPC546XX_pit.h"
//#include "SEEKFREE_OLED.h"
#include "LPC546XX_uart.h"
#include "LPC546XX_gpio.h"
#include "LPC546XX_iocon.h"
#include "Speedpid.h"
#include "motor.h"
#include "hc05.h"
#include "mag.h"

txPack_t hc05_txPack;
rxPack_t hc05_rxPack;

void hc05_init(void) { //蓝牙初始化
	gpio_init(A27, GPO, 0, NOPULL);
  uart_init(hc05uart, 9600, hc05TXD, hc05RXD);
	uart_rx_irq(hc05uart, 1);
	NVIC_SetPriority(FLEXCOMM0_IRQn, 1);
}

//感觉看起来很复杂,有时间优化一下。。。
void rx_onefloat(float* para_updated,int8* order,uint8* sizecount,uint8 dat){
		*((uint8*)&hc05_rxPack+(*order)*4+(*sizecount))=dat;
	(*sizecount)++;
	if((*sizecount)==4){
		*para_updated=*((float *)&hc05_rxPack+(*order));
		(*order)++;
		(*sizecount)=0;
		}
}

void FLEXCOMM0_IRQHandler(void) {
//	static uint8 testdat;
	static int8 order=-1;
	static uint8 sizecount=0;
	uint8 dat; 
	if(uart_query(hc05uart, &dat)){
		if((order==-1)&&(dat==0xA5))
			order=0;
		else if((order>=0)&&(order<=sizeof(hc05_rxPack)/4)){
		  switch(order){
			  case 0:
					hc05_rxPack.speedPID_enabled=(bool)((dat>>0)&0x01);
					hc05_rxPack.MagPID_enabled=(bool)((dat>>1)&0x01);
					hc05_rxPack.MagMax_enabled=(bool)((dat>>2)&0x01);
//				  testdat=dat;
				  order++;
				  order++;
					break;
				case 2:
					rx_onefloat(&SpeedPID.Kp,&order,&sizecount,dat);
				  if(SpeedPID.Kp<0) SpeedPID.Kp=0;
				  break;
				case 3:
					rx_onefloat(&SpeedPID.Ki,&order,&sizecount,dat);
				  if(SpeedPID.Ki<0) SpeedPID.Ki=0;
				  break;
				case 4:
					rx_onefloat(&SpeedPID.Kd,&order,&sizecount,dat);
				  if(SpeedPID.Kd<0) SpeedPID.Kd=0;
				  break;
				case 5:
					rx_onefloat(&MagPID.Kp,&order,&sizecount,dat);
				  if(MagPID.Kp<0.1f) MagPID.Kp=0;
				  break;
				case 6:
					rx_onefloat(&MagPID.Ki,&order,&sizecount,dat);
				  if(MagPID.Ki<0.1f) MagPID.Ki=0;
				  break;
				case 7:
					rx_onefloat(&MagPID.Kd,&order,&sizecount,dat);
				  if(MagPID.Kd<0.1f) MagPID.Kd=0;
				  break;
				case 8:
					rx_onefloat(&SpeedPID.TargetSpeedL,&order,&sizecount,dat);
				  if(SpeedPID.TargetSpeedL<0) SpeedPID.TargetSpeedL=0;
				  break;
				case 9:
					rx_onefloat(&SpeedPID.TargetSpeedR,&order,&sizecount,dat);
				  if(SpeedPID.TargetSpeedR<0) SpeedPID.TargetSpeedR=0;
				  break;
				case 10:
					order++;
				  break;
		  }
		}
		else if((order==sizeof(hc05_rxPack)/4+1)&&(dat==0x5A))
		order=-1;
	}
}



uint8_t CalculateParity(txPack_t hc05_txPack){
    uint8_t i, ret = 0;
    for (i = 0; i < sizeof(hc05_txPack); ++i)
        ret += *((uint8_t *)&hc05_txPack + i);
    return ret;
}

void hc05_schedule(void) {
	uart_putchar(hc05uart, 0xA5);
	/*除了bool都可以发*/
	uart_putbuff(hc05uart, (uint8_t *)&hc05_txPack, sizeof(hc05_txPack));
	uart_putchar(hc05uart, CalculateParity(hc05_txPack));
	uart_putchar(hc05uart, 0x5A);
}



