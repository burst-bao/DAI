#include "LPC546XX_pit.h"
#include "menu.h"
#include "rit.h"

void RIT_IRQHandler() { // 我怀疑这个函数运行时间过长会让时序乱掉
  PIT_FLAG_CLEAR;
	menu_schedule();
}
