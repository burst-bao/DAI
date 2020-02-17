#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "board.h"
#include "pid.h"

typedef struct {
	uint8 mag_b[3], reserved;
	float leftSpeed, rightSpeed, mag_speedpid_f;
} txPack_t;

typedef struct {
	bool speedPID_enabled, steerPID_enabled, magMax_enabled;
	/*通过串口设置该使能位，以决定是否开启采集（每个电感的最大最小值，
	该操作在每次跑车之前开启并关闭，目的是为磁场强度归一化做铺垫）*/
	pid_t speedPID, steerPID;
	float targetSpeed;
} rxPack_t;

static const uint8 rxPackSize = sizeof(rxPack_t),
txPackSize = sizeof(txPack_t);

extern rxPack_t com_rxPackage;
extern txPack_t com_txPackage;

void com_init(void);
void com_schedule(void);

#endif
