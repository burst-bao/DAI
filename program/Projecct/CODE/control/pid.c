//#include "SEEKFREE_OLED.h"
#include "speed.h"
#include "magnet.h"
#include "pid.h"
#include "motor.h"
#include "board.h"
#include "communication.h"

#define FILTER_SIZE 3

struct pid_speed_t {
	float Err, ErrLast, ErrPre;
	unsigned Duty, FilterBuf[FILTER_SIZE];
} static pid_leftCtrl, pid_rightCtrl;

struct pid_steer_t {
	float Err, ErrLast, ErrSum;
	unsigned Output;
} static pid_steeringCtrl;

void pid_init(void) { // nothing to do
}

__STATIC_INLINE void Limiting(unsigned* val, uint16 min, uint16 max) { //限幅
	if (*val > max)
		*val = max;
	else if (*val < min)
		*val = min;
}

__STATIC_INLINE void DutyFilter(struct pid_speed_t* p, float val) {
	uint_fast8_t i;
	for (i = 0; i < FILTER_SIZE - 1; ++i)
		p->FilterBuf[i] = p->FilterBuf[i + 1];
	p->FilterBuf[FILTER_SIZE - 1] += val;
	p->Duty = 0;
	for (i = 0; i < FILTER_SIZE; ++i)
		p->Duty += p->FilterBuf[i];
	p->Duty /= FILTER_SIZE;
}

__STATIC_INLINE void pid_speedRealizeSingle(struct pid_speed_t* p, float realSpeed) {
	p->Err = com_rxPackage.targetSpeed - realSpeed;
	float increment = com_rxPackage.speedPID.Kp * (p->Err - p->ErrLast) +
                      com_rxPackage.speedPID.Ki * p->Err +
                      com_rxPackage.speedPID.Kd * (p->Err + p->ErrPre - 2 * p->ErrLast);
	p->ErrPre = p->ErrLast;
	p->ErrLast = p->Err;

	if (com_rxPackage.speedPID_enabled && com_rxPackage.steerPID_enabled)
		increment -= pid_steeringCtrl.Output;
	DutyFilter(p, increment);
	Limiting(&p->Duty, motorMin, motorMax);
}

void pid_speedRealize(void) {
	pid_speedRealizeSingle(&pid_leftCtrl, com_txPackage.leftSpeed);
	pid_speedRealizeSingle(&pid_rightCtrl, com_txPackage.rightSpeed);
}

void pid_steerRealize(void) {
	pid_steeringCtrl.Err = com_txPackage.mag_speedpid_f;
	pid_steeringCtrl.ErrSum += pid_steeringCtrl.Err;
	//    MagPID.Increment = MagPID.Kp*(MagPID.err - MagPID.err_last) + 
	//                       MagPID.Ki*MagPID.err +
	//                       MagPID.Kd*(MagPID.err_pre - 2*MagPID.err_last + MagPID.err);
	pid_steeringCtrl.Output = com_rxPackage.steerPID.Kp * pid_steeringCtrl.Err +
                              com_rxPackage.steerPID.Ki * pid_steeringCtrl.ErrSum +
                              com_rxPackage.steerPID.Kd * (pid_steeringCtrl.Err - pid_steeringCtrl.ErrLast);
//	Limiting(&pid_steeringCtrl.Output, steerMin, steerMax);
	pid_steeringCtrl.ErrLast = pid_steeringCtrl.Err;
}

uint32 pid_getDuty(bool channel) {
	return channel ? pid_leftCtrl.Duty : pid_rightCtrl.Duty;
}
