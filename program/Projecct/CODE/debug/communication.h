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
	/*ͨ���������ø�ʹ��λ���Ծ����Ƿ����ɼ���ÿ����е������Сֵ��
	�ò�����ÿ���ܳ�֮ǰ�������رգ�Ŀ����Ϊ�ų�ǿ�ȹ�һ�����̵棩*/
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
