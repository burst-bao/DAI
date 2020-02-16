#include"switch.h"
#include"LPC546XX_gpio.h"
#include"LPC546XX_iocon.h"

//���뿪�غ궨�����ţ����鶨�岻�ܷŵ��ܵ�bsp���棬Ҫ��Ȼ���ظ�����
PIN_enum switchList[8] = {A14, B27, A13, B13, A9, A8, B26, B12};

//��ʼ��
void switch_init(void) {
    for (int i = 0; i < 8; ++i)
        iocon_init(switchList[i], ALT0 | DIGITAL | FILTEROFF | PULLUP);
}

//��ȡ����״̬
uint8 switch_readByte(void) {
    uint8 res = 0;
    for (int i = 0; i < 8; ++i) {
        res |= gpio_get(switchList[i]);
        res <<= 1;
    }
    return res;
}
