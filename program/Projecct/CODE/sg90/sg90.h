#ifndef SG90_H
#define SG90_H

#include "common.h"
#include "bsp.h"


#ifdef __cplusplus__
extern "C" {
#endif

void sg90_init(void);
void sg90_setDegree(bool axis, uint8 degree);

#ifdef __cplusplus__
}
#endif

#endif
