#ifndef MOTOR_H
#define MOTOR_H
#define MOTOR_FREQ 8000//根据周期信号的傅里叶级数分解的理论，不能选择（3.66，4，5，6.66，10，20）kHz，超过20kHz理论上可以，但是会增加开关损耗，故选择13~17kHz之间

#include "common.h"
#include "bsp.h"


#ifdef __cplusplus__
extern "C" {
#endif

void motor_init(void);
void motor_stop(void);
void motor_set(bool forward, bool left, uint32 duty);

#ifdef __cplusplus__
}
#endif

#endif
