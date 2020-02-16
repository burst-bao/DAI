/*********电磁检测*********/
#ifndef MAG_H
#define MAG_H

#include "bsp.h"

#ifdef __cplusplus__
extern "C" {
#endif

	typedef struct {
		float err,            //左轮当前速度与设定速度的偏差
			err_last,       //左轮上一次偏差
			err_sum,       //左轮偏差之和
			output;  //输出给左电机的控制量

		float Kp, Ki, Kd;  //定义比例、积分、微分系数
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
