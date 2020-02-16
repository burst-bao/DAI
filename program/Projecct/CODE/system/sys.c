#include "headfile.h"
#include "bsp.h"
#include "mag.h"
#include "rit.h"
#include "hc05.h"
#include "menu.h"
#include "speed.h"
#include "motor.h"
#include "button.h"
#include "speedPID.h"
#include "mrt.h"
#include "memory.h"

void sys_init(void) {
	get_clk();
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
}

void sys_run(void) {

}
