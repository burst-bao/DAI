#include "headfile.h"
#include "communication.h"
#include "board.h"
#include "magnet.h"
#include "menu.h"
#include "speed.h"
#include "motor.h"
#include "button.h"
#include "pid.h"
#include "mrt.h"
#include "store.h"

void sys_init(void) {
	get_clk();
	motor_init();
    store_init();
	pid_init();
	speed_init();
	magnet_init();
	oled_init();
	button_init();
	//menu_init();
	com_init();
	mrt_init(); // 最后初始化
	store_read();
	EnableInterrupts;
}

void sys_run(void) {
	__wfe();
}
