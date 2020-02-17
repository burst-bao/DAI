#include "LPC546XX_mrt.h"
#include "LPC546XX_pll.h"
#include "pid.h"
#include "board.h"
#include "communication.h"
#include "magnet.h"
#include "mrt.h"
#include "menu.h"
#include "speed.h"

// 此文件无需更改

void mrt_init(void) {
	mrt_pit_init_ms(MRT_CH0, MRT_CH0_INTERVAL);
	mrt_pit_init_ms(MRT_CH1, MRT_CH1_INTERVAL);
	mrt_pit_init_ms(MRT_CH2, MRT_CH2_INTERVAL);
	mrt_pit_init_ms(MRT_CH3, MRT_CH3_INTERVAL);
	NVIC_SetPriority(MRT0_IRQn, mrt_priority);
}

void MRT0_IRQHandler() {
	if (MRT_FLAG_READ(MRT_CH0) == 1) {
		MRT_FLAG_CLR(MRT_CH0);
//		MRT_CH0_SCHEDULE();
	}

	if (MRT_FLAG_READ(MRT_CH1) == 1) {
		MRT_FLAG_CLR(MRT_CH1);
		MRT_CH1_SCHEDULE();
	}

	if (MRT_FLAG_READ(MRT_CH2) == 1) {
		MRT_FLAG_CLR(MRT_CH2);
		MRT_CH2_SCHEDULE();
	}

	if (MRT_FLAG_READ(MRT_CH3) == 1) {
		MRT_FLAG_CLR(MRT_CH3);
		MRT_CH3_SCHEDULE();
	}
}
