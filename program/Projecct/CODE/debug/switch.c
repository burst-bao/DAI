#include"switch.h"
#include"LPC546XX_gpio.h"
#include"LPC546XX_iocon.h"

//拨码开关宏定义引脚，数组定义不能放到总的bsp里面，要不然会重复定义
PIN_enum switchList[8] = {A14, B27, A13, B13, A9, A8, B26, B12};

//初始化
void switch_init(void) {
    for (int i = 0; i < 8; ++i)
        iocon_init(switchList[i], ALT0 | DIGITAL | FILTEROFF | PULLUP);
}

//读取开关状态
uint8 switch_readByte(void) {
    uint8 res = 0;
    for (int i = 0; i < 8; ++i) {
        res |= gpio_get(switchList[i]);
        res <<= 1;
    }
    return res;
}
