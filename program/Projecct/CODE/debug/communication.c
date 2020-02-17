//#include "LPC546XX_pit.h"
//#include "SEEKFREE_OLED.h"
#include "LPC546XX_uart.h"
#include "LPC546XX_gpio.h"
#include "LPC546XX_iocon.h"
#include "motor.h"
#include "communication.h"
#include "magnet.h"

txPack_t com_txPackage;
rxPack_t com_rxPackage;

void com_init(void) { //¿∂—¿≥ı ºªØ
	uart_init(hc05uart, hc05boundrate, hc05TXD, hc05RXD);
	uart_rx_irq(hc05uart, 1);
	NVIC_SetPriority(FLEXCOMM0_IRQn, com_priority);
}

__STATIC_INLINE uint8_t CalculateParity(uint8* buf, uint8 cnt) {
	uint8_t i, ret = 0;
	for (i = 0; i < cnt; ++i)
		ret += buf[i];
	return ret;
}

__STATIC_INLINE void PackRxByte(uint8 dat) {
	static uint8 cnt, buf[rxPackSize];
	if (cnt > rxPackSize)  // error
		--cnt;
	else if (dat == 0xA5) // new pack
		cnt = 0;
	else if (dat == 0x5A) { // pack end
		if (CalculateParity(buf, cnt - 2) == buf[cnt - 1])
			memcpy(&com_rxPackage, buf, rxPackSize);
	}
	else buf[cnt++] = dat;
}

void FLEXCOMM0_IRQHandler(void) {
	uint8 rx;
	if (uart_query(hc05uart, &rx)) {
		PackRxByte(rx);
	}
}

void com_schedule(void) {
	uart_putchar(hc05uart, 0xA5);
	uart_putbuff(hc05uart, (uint8*)&com_txPackage, txPackSize);
	uart_putchar(hc05uart, CalculateParity((uint8*)&com_txPackage, txPackSize));
	uart_putchar(hc05uart, 0x5A);
}
