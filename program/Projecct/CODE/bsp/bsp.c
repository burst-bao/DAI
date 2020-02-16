#include "bsp.h"

uint8* int2str(uint32 num) {
    static uint8 i = 0, res[10];
	do {
		res[i++] = num % 10 + 48;
	} while (num /= 10);
	res[i] = '\0';
	return res;
}
