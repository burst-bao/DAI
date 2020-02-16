#ifndef HC05_H
#define HC05_H

#include "bsp.h"

#ifdef __cplusplus__
extern "C" {
#endif

typedef struct {
	  uint8 mag_uint8[3],
	        reserved;
    float speedL, 
			    speedR,
		      mag_speedpid_float;
}txPack_t;

typedef struct {
	  bool speedPID_enabled,
/*ͨ���������ø�ʹ��λ���Ծ����Ƿ����ɼ���ÿ����е������Сֵ��
�ò�����ÿ���ܳ�֮ǰ�������رգ�Ŀ����Ϊ�ų�ǿ�ȹ�һ�����̵棩*/
	MagPID_enabled,	     
	MagMax_enabled;
    float speedKp,
			    speedKi,
		      speedKd,
		      magKp,
		      magKi,
		      magKd,
		      TargetSpeedL,
		      TargetSpeedR;
}rxPack_t;

extern rxPack_t hc05_rxPack;
extern txPack_t hc05_txPack;
void hc05_init(void);
void hc05send_float(float num);
uint8_t CalculateParity(txPack_t hc05_txPack);
void hc05_schedule(void);
void hc05_setbaud(void);
#ifdef __cplusplus__
}
#endif

#endif
