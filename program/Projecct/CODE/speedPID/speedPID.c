//#include "SEEKFREE_OLED.h"
//#include "LPC546XX_adc.h"
#include "LPC546XX_eeprom.h"
#include "speed.h"
#include "mag.h"
#include "math.h"
#include "hc05.h"
#include "speedPID.h"
#include "motor.h"

TSpeedPID SpeedPID;
/*ͨ���������ø�ʹ��λ���Ծ����Ƿ�ʼPID����*/

void speedPID_init(void) {
	SpeedPID.RealSpeedL = 0;     //������ʵ�ٶ�
	SpeedPID.errL = 0;           //���ֵ�ǰ�ٶ����趨�ٶȵ�ƫ��
	SpeedPID.errL_last = 0;      //������һ��ƫ��
	SpeedPID.IncrementSpeedL = 0;//������Ҫ���ӵ��ٶ�
	SpeedPID.MotorL_pwmduty[0] = MotorMin; //����������Ŀ�����
	SpeedPID.MotorL_pwmduty[1] = MotorMin; //����������Ŀ�����
	SpeedPID.MotorL_pwmduty[2] = MotorMin; //����������Ŀ�����
	SpeedPID.RealSpeedR = 0;     //����
	SpeedPID.errR = 0;
	SpeedPID.errR_last = 0;
	SpeedPID.IncrementSpeedR = 0;
	SpeedPID.MotorR_pwmduty[0] = MotorMin; //����������Ŀ�����
	SpeedPID.MotorR_pwmduty[1] = MotorMin; //����������Ŀ�����
	SpeedPID.MotorR_pwmduty[2] = MotorMin; //����������Ŀ�����
}

void speedPID_set(bool Channel, int16 Speed) {
	if (Channel)
		SpeedPID.TargetSpeedL = Speed;
	else
		SpeedPID.TargetSpeedR = Speed;
}

void speedPID_enable(bool en) {
	hc05_rxPack.speedPID_enabled = en;
}

static inline void CorrectSpeedDuty(uint16* Duty) {
	if (*Duty > MotorMax)
		*Duty = MotorMax;
	if (*Duty < MotorMin)
		*Duty = MotorMin;
}

inline static float ConvertSpeedUnit(float rawSpeed) {
	return rawSpeed * 9 / 1024 / speedPID_Interval * 1000; // ��λcm/s
}


//���ֵ���
void WL_PID_realize(void) {
	SpeedPID.MotorL_pwmduty[0] = SpeedPID.MotorL_pwmduty[1];
	SpeedPID.MotorL_pwmduty[1] = SpeedPID.MotorL_pwmduty[2];
	SpeedPID.errL = SpeedPID.TargetSpeedL - SpeedPID.RealSpeedL;
	SpeedPID.IncrementSpeedL = SpeedPID.Kp * (SpeedPID.errL - SpeedPID.errL_last) +
		SpeedPID.Ki * SpeedPID.errL +
		SpeedPID.Kd * (SpeedPID.errL_pre - 2 * SpeedPID.errL_last + SpeedPID.errL);
	SpeedPID.MotorL_pwmduty[2] += SpeedPID.IncrementSpeedL - MagPID.output;
	CorrectSpeedDuty(&SpeedPID.MotorL_pwmduty[2]);
	SpeedPID.MotorL_pwmduty[3] = (SpeedPID.MotorL_pwmduty[0] +
		SpeedPID.MotorL_pwmduty[1] +
		SpeedPID.MotorL_pwmduty[2]) / 3;
	SpeedPID.errL_pre = SpeedPID.errL_last;
	SpeedPID.errL_last = SpeedPID.errL;
}

//���ֵ���
void WR_PID_realize(void) {
	SpeedPID.MotorR_pwmduty[0] = SpeedPID.MotorR_pwmduty[1];
	SpeedPID.MotorR_pwmduty[1] = SpeedPID.MotorR_pwmduty[2];
	SpeedPID.errR = SpeedPID.TargetSpeedR - SpeedPID.RealSpeedR;
	SpeedPID.IncrementSpeedR = SpeedPID.Kp * (SpeedPID.errR - SpeedPID.errR_last) +
		SpeedPID.Ki * SpeedPID.errR +
		SpeedPID.Kd * (SpeedPID.errR_pre - 2 * SpeedPID.errR_last + SpeedPID.errR);
	SpeedPID.MotorR_pwmduty[2] += SpeedPID.IncrementSpeedR + MagPID.output;
	CorrectSpeedDuty(&SpeedPID.MotorR_pwmduty[2]);
	SpeedPID.MotorR_pwmduty[3] = (SpeedPID.MotorR_pwmduty[0] +
		SpeedPID.MotorR_pwmduty[1] +
		SpeedPID.MotorR_pwmduty[2]) / 3;
	SpeedPID.errR_pre = SpeedPID.errR_last;
	SpeedPID.errR_last = SpeedPID.errR;
}
void speedPID_schedule(void) {
	SpeedPID.RealSpeedR = ConvertSpeedUnit(speed_get(RIGHT));
	hc05_txPack.speedR = SpeedPID.RealSpeedR;
	SpeedPID.RealSpeedL = ConvertSpeedUnit(speed_get(LEFT));
	hc05_txPack.speedL = SpeedPID.RealSpeedL;

	if (hc05_rxPack.speedPID_enabled) {
		WL_PID_realize();
		WR_PID_realize();
		//if((SpeedPID.MotorR_pwmduty[3]>6000&&SpeedPID.TargetSpeedR<20)||(SpeedPID.MotorL_pwmduty[3]>6000&&SpeedPID.TargetSpeedL<20))
		//  hc05_rxPack.speedPID_enabled=false;
		//else{
		motor_set(FORWARD, RIGHT, SpeedPID.MotorR_pwmduty[3]);
		motor_set(FORWARD, LEFT, SpeedPID.MotorL_pwmduty[3]);
		//		}
		//			motor_set(FORWARD, LEFT, hc05_rxPack.TargetSpeedR);
		//			motor_set(FORWARD, RIGHT, hc05_rxPack.TargetSpeedR);
	}
	else {
		motor_stop();
		SpeedPID.MotorL_pwmduty[0] = MotorMin; //����������Ŀ�����
		SpeedPID.MotorL_pwmduty[1] = MotorMin; //����������Ŀ�����
		SpeedPID.MotorL_pwmduty[2] = MotorMin; //����������Ŀ�����
		SpeedPID.MotorL_pwmduty[3] = MotorMin; //����������Ŀ�����

		SpeedPID.MotorR_pwmduty[0] = MotorMin; //����������Ŀ�����
		SpeedPID.MotorR_pwmduty[1] = MotorMin; //����������Ŀ�����
		SpeedPID.MotorR_pwmduty[2] = MotorMin; //����������Ŀ�����
		SpeedPID.MotorR_pwmduty[3] = MotorMin; //����������Ŀ�����
	}
}

float speedPID_getReal(bool Channel) {
	return Channel ? SpeedPID.RealSpeedL : SpeedPID.RealSpeedR;
}

//float speedPID_K(uint8_t mod, float val) {
//    switch (mod) {
//        case 1:
//            return SpeedPID.Kp += val;
//        case 2:
//            return SpeedPID.Ki += val;
//        case 3:
//            return SpeedPID.Kd += val;
//    }
//    return 0;
//}

float getSpeedKp() {
	return SpeedPID.Kp;
}

float getSpeedKi() {
	return SpeedPID.Ki;
}

float getSpeedKd() {
	return SpeedPID.Kd;
}

void modifySpeedKp(float val) {
	SpeedPID.Kp += val;
	eeprom_write_word(SpeedKp_Address, (uint32*)&SpeedPID.Kp);
}

void modifySpeedKi(float val) {
	SpeedPID.Ki += val;
	eeprom_write_word(SpeedKi_Address, (uint32*)&SpeedPID.Ki);
}

void modifySpeedKd(float val) {
	SpeedPID.Kd += val;
	eeprom_write_word(SpeedKd_Address, (uint32*)&SpeedPID.Kd);
}

uint16 getMotPWM(bool Channel, uint8 order) {
	return Channel ? SpeedPID.MotorL_pwmduty[order] : SpeedPID.MotorR_pwmduty[order];
}

float getTargetSpeedL() {
	return SpeedPID.TargetSpeedL;
}

float getTargetSpeedR() {
	return SpeedPID.TargetSpeedR;
}

void modifyTargetSpeedL(float val) {
	SpeedPID.TargetSpeedL += val;
	eeprom_write_word(TargetSpeedL_Address, (uint32*)&SpeedPID.TargetSpeedL);
}

void modifyTargetSpeedR(float val) {
	SpeedPID.TargetSpeedR += val;
	eeprom_write_word(TargetSpeedR_Address, (uint32*)&SpeedPID.TargetSpeedR);
}



