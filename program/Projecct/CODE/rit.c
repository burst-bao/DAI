#include "LPC546XX_pit.h"

void RIT_IRQHandler() { // �һ��������������ʱ���������ʱ���ҵ�
  PIT_FLAG_CLEAR;
}
