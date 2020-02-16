#include"sys.h"

int main(void) {
	sys_init();
	for (;;) {
		sys_run();
	}
}
