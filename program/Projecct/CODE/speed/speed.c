//#include "Speedpid.h"
#include "LPC546XX_ctimer.h"
#include "LPC546XX_iocon.h"
#include "LPC546XX_gpio.h"
#include "speed.h"
//#include "SEEKFREE_OLED.h"

//±àÂëÆ÷³õÊ¼»¯
void speed_init(void) {
    ctimer_count_init(speedL);
    ctimer_count_init(speedR);
    gpio_init(dirL, GPI, 0, PULLUP);
    gpio_init(dirR, GPI, 0, PULLUP);
}

int16 speed_get(bool Channel) {
	int16 res = ctimer_count_read(Channel ? speedL : speedR);
	ctimer_count_clean(Channel ? speedL : speedR);
	if (gpio_get(Channel ? dirL : dirR) ^ Channel)
		res = -res;
	return res;
}

