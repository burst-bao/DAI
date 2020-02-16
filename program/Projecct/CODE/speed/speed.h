#ifndef SPEEDx_H
#define SPEEDx_H

#include "bsp.h"
//#include <math.h>

#ifdef __cplusplus__
extern "C" {
#endif

void speed_init(void);
int16 speed_get(bool Channel);

#ifdef __cplusplus__
}
#endif

#endif
