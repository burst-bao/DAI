#ifndef STORE_H
#define STORE_H

#include "LPC546XX_eeprom.h"

__STATIC_INLINE void store_init(void) {
	eeprom_init();
}

void store_read(void);
//void store_write(void);

#endif
