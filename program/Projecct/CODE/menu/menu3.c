#include "mag.h"
#include "menu.h"
#include "speedPID.h"
#include "LPC546XX_adc.h"

#define btnOk btn0
#define btnUp btn2
#define btnDown btn3
#define btnBack btn4

uint8_t ActivePage, ActiveLine;
// 0-主页 1-修改参数 2-显示数据 3-加减 4-柱状图

void menu_move(int8_t dir) {
    if (ActivePage == 3 | ActivePage == 6) {
        oled_p6x8str(32, ActiveLine  + 1, "      ");
    }
    oled_p8x16str(0, ActiveLine , " ");
    
    ActiveLine += dir;
    if (ActiveLine < 1 || ActiveLine > 3)
        ActiveLine = 1;
    
    if (ActivePage == 3 | ActivePage == 6) {
        oled_p6x8str(32, ActiveLine + 1, "------");
    }
    oled_p8x16str(0, ActiveLine , ">");
}

void menu_home(void) { // Page 0
    oled_fill(0x00);
    oled_p8x16str(32, 0, "homepage");
    oled_p8x16str(16, 1, "setspeedpid");
    oled_p8x16str(16, 2, "displaydata");
    oled_p8x16str(16, 3, "setmagneticpid");
    menu_move(9);
    ActivePage = 0;
}

void menu_speedPID(void) { // Page 1
    oled_fill(0x00);
    oled_p8x16str(32, 0, "setspeedpid");
    oled_p8x16str(16, 1, "kp");
    oled_p8x16str(16, 2, "ki");
    oled_p8x16str(16, 3, "kd");
    ActivePage = 1;
}

void menu_data(void) { // Page 2
    oled_fill(0x00);
    oled_p8x16str(32, 0, "displaydata");
    oled_p8x16str(16, 1, "speedleft");
    oled_p8x16str(16, 2, "speedright");
    oled_p8x16str(16, 3, "adc");
    ActivePage = 2;
    menu_move(9);
}

void menu_mag(void) { // Page 4
    oled_fill(0x00);
    oled_p8x16str(50, 0, "adc");
    ActivePage = 4;
}

void menu_magneticPID(void) {
    oled_fill(0x00);
    oled_p8x16str(8, 0, "setmagneticpid");
    oled_p8x16str(16, 1, "kp");
    oled_p8x16str(16, 2, "ki");
    oled_p8x16str(16, 3, "kd");
    ActivePage = 5;
    menu_move(9);
}

void plotADCn(uint8_t n) {
    uint8_t i;
    oled_printf_int32(0, n , n, 1);
    uint8_t h = mag_get(n - 1);
    for (i = 1; i <= 100; ++i) { // [28,128]~[0,100]
        oled_putpixel(i + 28, n , i < h ? 0xff : 0);
    }
}

void menu_schedule(void) {
    switch (ActivePage) {
        case 0: // home page
            if (button_pressed(btnOk)) {
                if (ActiveLine == 1)
                    menu_speedPID();
                else if (ActiveLine == 2)
                    menu_data();
                else if (ActiveLine == 3)
                    menu_magneticPID();
            }
            if (button_pressed(btnUp)) {
                menu_move(-1);
                return;
            }
            if (button_pressed(btnDown)) {
                menu_move(1);
                return;
            }
            break;
        case 1: // set parameter
            oled_printf_float(32, 1, speedPID_K(1, 0), 3, 3);
            oled_printf_float(32, 2, speedPID_K(2, 0), 3, 3);
            oled_printf_float(32, 3, speedPID_K(3, 0), 3, 3);
            if (button_pressed(btnOk)) {
                ActivePage = 3;
                menu_move(0);
            }
            if (button_pressed(btnUp)) {
                menu_move(-1);
                return;
            }
            if (button_pressed(btnDown)) {
                menu_move(1);
                return;
            }
            if (button_pressed(btnBack)) {
                menu_home();
            }
            break;
        case 2: // display data
            oled_printf_float(64, 1, speedPID_getReal(LEFT), 4, 5);
            oled_printf_float(64, 2, speedPID_getReal(RIGHT), 4, 5);
				    oled_printf_float(64, 3, mag_speedpid_float, 4, 5);
            if (button_pressed(btnOk)) {
                if (ActiveLine == 3) {
                    menu_mag();
                }
            }
            if (button_pressed(btnUp)) {
                menu_move(-1);
                return;
            }
            if (button_pressed(btnDown)) {
                menu_move(1);
                return;
            }
            if (button_pressed(btnBack)) {
                menu_home();
            }
            break;
        case 3: // chenge var
            if (button_pressed(btnUp)) {
                oled_printf_float(32, ActiveLine, speedPID_K(ActiveLine, 1), 3, 3);
            }
            if (button_pressed(btnDown)) {
                oled_printf_float(32, ActiveLine, speedPID_K(ActiveLine, -1), 3, 3);
            }
            if (button_pressed(btnBack)) {
                menu_speedPID();
            }
            break;
        case 4:
            plotADCn(1);
            plotADCn(2);
            plotADCn(3);
            if (button_pressed(btnBack)) {
                menu_data();
            }
            break;
        case 5:
            oled_printf_float(32, 2, magPID_K(1, 0), 3, 3);
            oled_printf_float(32, 4, magPID_K(2, 0), 3, 3);
            oled_printf_float(32, 6, magPID_K(3, 0), 3, 3);
            if (button_pressed(btnOk)) {
                ActivePage = 6;
                menu_move(0);
            }
            if (button_pressed(btnUp)) {
                menu_move(-1);
                return;
            }
            if (button_pressed(btnDown)) {
                menu_move(1);
                return;
            }
            if (button_pressed(btnBack)) {
                menu_home();
            }
            break;
        case 6:
            if (button_pressed(btnUp)) {
                oled_printf_float(32, ActiveLine, magPID_K(ActiveLine, 1), 3, 3);
            }
            if (button_pressed(btnDown)) {
                oled_printf_float(32, ActiveLine, magPID_K(ActiveLine, -1), 3, 3);
            }
            if (button_pressed(btnBack)) {
                menu_magneticPID();
            }
            break;
        default:
            menu_home();
    }
}
