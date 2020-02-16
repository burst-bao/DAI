#include "bsp.h"
#include "mag.h"
#include "rit.h"
#include "hc05.h"
#include "menu.h"
#include "speed.h"
#include "motor.h"
#include "button.h"
//#include "switch.h"
#include "speedPID.h"
#include "headfile.h"

/*ͨ���������ø�ʹ��λ���Ծ����Ƿ�ʼPID����*/
bool speedPID_enabled;
/*ͨ���������ø�ʹ��λ���Ծ����Ƿ�����λ������һ����е�ʵʱ�ɼ����ĵ������*/
bool hc05test_enabled;
/*ͨ���������ø�ʹ��λ���Ծ����Ƿ����ɼ���ÿ����е������Сֵ��
�ò�����ÿ���ܳ�֮ǰ�������رգ�Ŀ����Ϊ�ų�ǿ�ȹ�һ�����̵棩*/
bool SetMinAndMax_enabled;

int main(void) { 
    get_clk();
//    switch_init();
//    speed_init();
//    hc05_init();
	oled_init();
    menu_home();
//	motor_init();
//	button_init();
//	speedPID_init();
//	mag_adc_init();
//	pit_init_ms(1);
//    EnableInterrupts;
    
//	oled_p6x8str(2, 0, "speed:");
//	oled_p6x8str(2, 1, "mod  :");
//  oled_p6x8str(2, 2, "err  :");
//	oled_p6x8str(2, 3, "pwm  :");
//	oled_p6x8str(2, 4, "emadc:");
//	oled_p6x8str(2, 6, "Mapid:");
    
	while(1) {
		if (rit_scan_pid) {
            rit_scan_pid = false;
            speedPID_TaskSchedule();
        }
        if (rit_scan_mag) {
            rit_scan_mag = false;
            mag_TaskSchedule();
        }
    }
}
