#ifndef SPEEDPID_H
#define SPEEDPID_H

#include "board.h"

typedef struct {
    float Kp, Ki, Kd;
} pid_t;

void pid_init(void);
void pid_speedRealize(void);
void pid_steerRealize(void);
uint32 pid_getDuty(bool channel);

#endif
