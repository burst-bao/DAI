#include "LPC546XX_ctimer.h"
#include "LPC546XX_iocon.h"
#include "motor.h"

//电机初始化
void motor_init(void) {
    ctimer_pwm_init(motorL0, MOTOR_FREQ, 0);
    ctimer_pwm_init(motorL1, MOTOR_FREQ, 0);
    ctimer_pwm_init(motorR0, MOTOR_FREQ, 0);
    ctimer_pwm_init(motorR1, MOTOR_FREQ, 0);
    iocon_init_noalt(motorPinL0, ALT3 | DIGITAL | FILTEROFF | NOPULL | OD); // 为了开漏
    iocon_init_noalt(motorPinL1, ALT2 | DIGITAL | FILTEROFF | NOPULL | OD);
    iocon_init_noalt(motorPinR0, ALT3 | DIGITAL | FILTEROFF | NOPULL | OD);
    iocon_init_noalt(motorPinR1, ALT3 | DIGITAL | FILTEROFF | NOPULL | OD);
}

//电机旋转方向、速度
void motor_set(bool Direction, bool Channel, uint32 Duty) {
    if (Channel) 
        if (!Direction){
            ctimer_pwm_duty(motorL0, Duty);
            ctimer_pwm_duty(motorL1, 0);
				}
        else{
            ctimer_pwm_duty(motorL1, Duty);
            ctimer_pwm_duty(motorL0, 0);
				}
    else
        if (!Direction){
            ctimer_pwm_duty(motorR0, Duty);
            ctimer_pwm_duty(motorR1, 0);
				}
        else{
            ctimer_pwm_duty(motorR1, Duty);
            ctimer_pwm_duty(motorR0, 0);
				}
}

void motor_stop() {
	ctimer_pwm_duty(motorL1, 0);
	ctimer_pwm_duty(motorL0, 0);
	ctimer_pwm_duty(motorR1, 0);
	ctimer_pwm_duty(motorR0, 0);
}
