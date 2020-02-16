/*********��ż��*********/
#ifndef MAG_H
#define MAG_H

#include "bsp.h"

#ifdef __cplusplus__
extern "C" {
#endif

	typedef struct {
		float err,            //���ֵ�ǰ�ٶ����趨�ٶȵ�ƫ��
			err_last,       //������һ��ƫ��
			err_sum,       //����ƫ��֮��
			output;  //����������Ŀ�����

		float Kp, Ki, Kd;  //������������֡�΢��ϵ��
	} TMagPID;

	extern TMagPID MagPID;
	extern float MagMax_float[3];
	extern float mag_speedpid_float;
	void Mag_init(void);
	void SetMinAndMax_enable(bool en);
	float mag_get(uint8_t n);
	void Mag_PID_realize(void);
	void mag_schedule(void);
	float magPID_K(uint8_t mod, float val);
	float getMag(uint8 order);
	float getMagKp(void);
	float getMagKi(void);
	float getMagKd(void);
	void modifyMagKp(float val);
	void modifyMagKi(float val);
	void modifyMagKd(float val);

#ifdef __cplusplus__
}
#endif

#endif
