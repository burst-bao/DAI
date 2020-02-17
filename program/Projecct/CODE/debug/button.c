#include"button.h"
#include"LPC546XX_pint.h"
#include"LPC546XX_iocon.h"

void button_init(void) {
	pint_init(PINT_OK, btnOk, FALLING);
	pint_init(PINT_UP, btnUp, FALLING);
	pint_init(PINT_DOWN, btnDown, FALLING);
	pint_init(PINT_BACK, btnBack, FALLING);
	pint_init(PINT_SS, btnSS, FALLING);
}
