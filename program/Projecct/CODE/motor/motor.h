#ifndef MOTOR_H
#define MOTOR_H
#define MOTOR_FREQ 8000//���������źŵĸ���Ҷ�����ֽ�����ۣ�����ѡ��3.66��4��5��6.66��10��20��kHz������20kHz�����Ͽ��ԣ����ǻ����ӿ�����ģ���ѡ��13~17kHz֮��

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
