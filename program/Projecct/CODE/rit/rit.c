#include "LPC546XX_pit.h"
#include "menu.h"
#include "rit.h"

void RIT_IRQHandler() { // �һ��������������ʱ���������ʱ���ҵ�
  PIT_FLAG_CLEAR;
	menu_schedule();
}
