#include "sg90.h"
#include "LPC546XX_ctimer.h"

//�����ʼ��
void sg90_init(void) {
    ctimer_pwm_init(sg90X, 50, 750);
    ctimer_pwm_init(sg90Y, 50, 750);
}

//�����ת�̶��Ƕ�
void sg90_setDegree(bool axis, uint8 degree) {
    if (degree > 180)
        return;
    ctimer_pwm_duty(axis ? sg90X : sg90Y, 
        10000u * (uint16)degree / 1800);
}
