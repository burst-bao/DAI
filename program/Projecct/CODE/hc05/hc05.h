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
/*通过串口设置该使能位，以决定是否开启采集（每个电感的最大最小值，
该操作在每次跑车之前开启并关闭，目的是为磁场强度归一化做铺垫）*/
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
