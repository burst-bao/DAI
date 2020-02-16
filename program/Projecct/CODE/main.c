#include"sys.h"

int main(void) {
    sys_init();
    for (;;) { // enter main loop
        sys_run();
    }
}
