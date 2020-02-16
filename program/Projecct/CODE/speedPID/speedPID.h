#ifndef SPEEDPID_H
#define SPEEDPID_H

#include "bsp.h"

#ifdef __cplusplus__
extern "C" {
#endif
	

typedef struct{
    float RealSpeedL,      //������ʵ�ٶ�
	      TargetSpeedL,
          errL,            //���ֵ�ǰ�ٶ����趨�ٶȵ�ƫ��
          errL_last,       //������һ��ƫ��
          errL_pre,       //����������ƫ��
	      IncrementSpeedL; //������Ҫ���ӵ��ٶ�
	uint16 MotorL_pwmduty[4];  //����������Ŀ�����
	
   	float RealSpeedR,      //����
	      TargetSpeedR,
          errR,            
          errR_last,
          errR_pre,       //����������ƫ��
	      IncrementSpeedR;
	uint16 MotorR_pwmduty[4];
	
    float Kp, Ki, Kd;  //������������֡�΢��ϵ��
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
