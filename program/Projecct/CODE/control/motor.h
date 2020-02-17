#ifndef MOTOR_H
#define MOTOR_H

#include "board.h"

void motor_init(void);
void motor_stop(void);
void motor_set(bool forward, bool left, uint32 duty);

#endif
