#ifndef SPEEDPID_H
#define SPEEDPID_H

#include "bsp.h"

#ifdef __cplusplus__
extern "C" {
#endif
	

typedef struct{
    float RealSpeedL,      //左轮真实速度
	      TargetSpeedL,
          errL,            //左轮当前速度与设定速度的偏差
          errL_last,       //左轮上一次偏差
          errL_pre,       //左轮上两次偏差
	      IncrementSpeedL; //左轮需要增加的速度
	uint16 MotorL_pwmduty[4];  //输出给左电机的控制量
	
   	float RealSpeedR,      //右轮
	      TargetSpeedR,
          errR,            
          errR_last,
          errR_pre,       //右轮上两次偏差
	      IncrementSpeedR;
	uint16 MotorR_pwmduty[4];
	
    float Kp, Ki, Kd;  //定义比例、积分、微分系数
} TSpeedPID;

extern TSpeedPID SpeedPID;
void speedPID_init(void);
//void speedPID_enable(bool en);
void speedPID_set(bool Channel, int16 Speed);
float speedPID_getReal(bool Channel);
void WL_PID_realize(void);
void WR_PID_realize(void);
void speedPID_schedule(void);
float speedPID_K(uint8_t mod, float val);
float getSpeedKp(void);
float getSpeedKi(void);
float getSpeedKd(void);
void modifySpeedKp(float val);
void modifySpeedKi(float val);
void modifySpeedKd(float val);
uint16 getMotPWM(bool Channel,uint8 order);
float getTargetSpeedL(void);
float getTargetSpeedR(void);
void modifyTargetSpeedL(float val);
void modifyTargetSpeedR(float val);

#ifdef __cplusplus__
}
#endif

#endif
