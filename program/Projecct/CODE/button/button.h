#ifndef BUTTON_H
#define BUTTON_H

#include "bsp.h"
#ifdef __cplusplus__
extern "C" {
#endif

void button_init(void);
bool button_pressed(PIN_enum btn);

#ifdef __cplusplus__
}
#endif

#endif
