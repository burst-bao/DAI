#include "LPC546XX_ctimer.h"
#include "LPC546XX_iocon.h"
#include "LPC546XX_gpio.h"
#include "communication.h"
#include "board.h"
#include "speed.h"
#include "motor.h"
#include "pid.h"

void speed_init(void) { //编码器初始化
    ctimer_count_init(speedL);
    ctimer_count_init(speedR);
    gpio_init(dirL, GPI, 0, NOPULL);
    gpio_init(dirR, GPI, 0, NOPULL);
}

__STATIC_INLINE int16 GetRawSpeed(bool Channel) {
	int32 res = ctimer_count_read(Channel ? speedL : speedR);
	ctimer_count_clean(Channel ? speedL : speedR);
	if (gpio_get(Channel ? dirL : dirR) ^ Channel)
		res = -res;
	return res;
}

__STATIC_INLINE float ConvertSpeedUnit(uint32 rawSpeed) {
	return (float)rawSpeed * 9 / 1024 / speed_interval * 1000; // 单位cm/s
}

void speed_schedule(void) {
	com_txPackage.rightSpeed = ConvertSpeedUnit(GetRawSpeed(RIGHT));
	com_txPackage.leftSpeed = ConvertSpeedUnit(GetRawSpeed(LEFT));

	if (com_rxPackage.speedPID_enabled) {
		pid_speedRealize();
		//if((SpeedPID.MotorR_pwmduty[3]>6000&&SpeedPID.TargetSpeedR<20)||(SpeedPID.MotorL_pwmduty[3]>6000&&SpeedPID.TargetSpeedL<20))
		//  hc05_rxPack.speedPID_enabled=false;
		//else{
		motor_set(FORWARD, RIGHT, pid_getDuty(RIGHT));
		motor_set(FORWARD, LEFT, pid_getDuty(LEFT));
		//		}
		//			motor_set(FORWARD, LEFT, hc05_rxPack.TargetSpeedR);
		//			motor_set(FORWARD, RIGHT, hc05_rxPack.TargetSpeedR);
	}
	else {
		motor_stop();
	}
}
