#include"button.h"
#include"LPC546XX_pint.h"
//#include"LPC546XX_gpio.h"
//#include"LPC546XX_iocon.h"

//void button_init(void) {
//    gpio_init(btn0, GPI, 1, PULLUP);
//    gpio_init(btn1, GPI, 1, PULLUP);
//    gpio_init(btn2, GPI, 1, PULLUP);
//    gpio_init(btn3, GPI, 1, PULLUP);
//    gpio_init(btn4, GPI, 1, PULLUP);
//}


void button_init(void) {
	pint_init(PINT_OK, btnOk, FALLING);
	pint_init(PINT_UP, btnUp, FALLING);
	pint_init(PINT_DOWN, btnDown, FALLING);
	pint_init(PINT_BACK, btnBack, FALLING);
	pint_init(PINT_SS, btnSS, FALLING);
//	pint_init(PINT_OK, btn0, LOW);
//	pint_init(PINT_UP, btn2, LOW);
//	pint_init(PINT_DOWN, btn3, LOW);
//	pint_init(PINT_BACK, btn4, LOW);
//	pint_enable_irq(PINT_CH0);
//	pint_enable_irq(PINT_CH1);
//	pint_enable_irq(PINT_CH2);
//	pint_enable_irq(PINT_CH3);
//	pint_enable_irq(PINT_CH4);
}
//bool button_pressed(PIN_enum btn) {
//    return !gpio_get(btn);
//}

