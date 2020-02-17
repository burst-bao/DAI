//#include "LPC546XX_systick.h"
//#include "SEEKFREE_OLED.h"
//#include "LPC546XX_pint.h"
//#include "LPC546XX_pit.h"
//#include "LPC546XX_pll.h"
//#include "pid.h"
//#include "menu.h"
//#include "board.h"
//#include "magnet.h"
//#include "speed.h"
//#include "communication.h"

//#define oledyrange 6 //当前页面显示的最大项数

//typedef struct menu/*定义一个菜单*/ {
//	uint8* title;
//	uint8 itemCount;//项目总数
////	u8 rangefrom; //当前页面显示的第一项
//	uint8 range; //当前页面显示的最大项数
//	uint8 selected;//当前的光标选择项
//	uint8* menuItemString[15];//菜单项目字符串组
//	struct menu** subMenus;//子菜单
//	struct menu* parent;//上级菜单 ,如果是顶级则为null
//	void (**func_NoPressed)();//选择相应项未按确定键也执行的函数
//	void (**func_Pressed)();//选择相应项按确定键后执行的函数 
//} Menu;
//Menu MainMenu = { //定义主菜单
//	.title = "HOMEPAGE",
//	.itemCount = 5,
//	.range = oledyrange,
//	.selected = 1,//总共5项，当前选择第1项
//	.menuItemString = {
//		"TarSpeedL           ",
//		"TarSPeedR           ",
//		"SetPID              ",
//		"Display             ",
//		"MagMaxCollect       "
//	}
//};
//Menu SetpidMenu = {//设置速度菜单
//  "SETPID",
//  6,oledyrange,1,
//  {
//		"SPEEDKP             ",
//		"SPEEDKI             ",
//		"SPEEDKD             ",
//		"MAGKP               ",
//		"MAGKI               ",
//		"MAGKD               "
//  }
//};
//Menu DisplayMenu = {//显示菜单
//  "DISPLAY",
//  12,oledyrange,1,
//  {
//		"Mag1                ",
//		"Mag2                ",
//		"Mag3                ",
//		"Mag1                ",
//		"Mag2                ",
//		"Mag3                ",
//		"MOTPWM1             ",
//		"MOTPWM2             ",
//		"MOTPWM3             ",
//		"MOTPWM4             ",
//		"SPEEDL              ",
//		"SPEEDR              "
//  }
//};
//Menu* currentMenu;//当前的菜单


//void display(void) {
//	uint8 i, rangefrom, color;
//	rangefrom = (currentMenu->selected < currentMenu->range) ?
//		0 : (currentMenu->selected - currentMenu->range);//当前页面显示的第一项的实际项数 从0开始计
//	for (i = 0; (i < currentMenu->range) && (i < currentMenu->itemCount); i++)
//	{
//		color = (i == currentMenu->selected - rangefrom - 1) ? 1 : 0;
//		oled_p6x8str(2, i + 2, currentMenu->menuItemString[i + rangefrom], color);
//		currentMenu->func_NoPressed[i + rangefrom](i + 2, color);
//	}
//	if (i < currentMenu->range)
//		for (; i < currentMenu->range; i++)
//			oled_p6x8str(2, i + 2, "                    ", 0);

//	if (hc05_rxPack.speedPID_enabled) {
//		oled_p6x8str(97, 0, "START", 1);
//	}
//	else
//		oled_p6x8str(97, 0, "STOP ", 1);
//}

///**************************************MainMenu开始*************************************************/
//void displayTargetSpeedL(uint8 line, uint8 color) {
//	oled_printf_float(2 + 6 * 10, line, getTargetSpeedL(), 3, 1, color);
//}

//void displayTargetSpeedR(uint8 line, uint8 color) {
//	oled_printf_float(2 + 6 * 10, line, getTargetSpeedR(), 3, 1, color);
//}

//void modTargetSpeedL(uint8 line, uint8 color) {
//	pit_deinit();
//	oled_printf_float_and_ch(2 + 6 * 10, line, getTargetSpeedL(), 3, 1, 2, '_', color);
//	while (!PINT_FALL_FLAG_READ(PINT_BACK)) {
//		if (PINT_FALL_FLAG_READ(PINT_UP)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_UP);
//			modifyTargetSpeedL(10);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getTargetSpeedL(), 3, 1, 2, '_', color);
//		}
//		if (PINT_FALL_FLAG_READ(PINT_DOWN)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_DOWN);
//			modifyTargetSpeedL(-10);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getTargetSpeedL(), 3, 1, 2, '_', color);
//		}
//	}
//	PINT_FALL_FLAG_CLEAR(PINT_BACK);
//	pit_init_ms(menu_interval);
//}

//void modTargetSpeedR(uint8 line, uint8 color) {
//	pit_deinit();
//	oled_printf_float_and_ch(2 + 6 * 10, line, getTargetSpeedR(), 3, 1, 2, '_', color);
//	while (!PINT_FALL_FLAG_READ(PINT_BACK)) {
//		if (PINT_FALL_FLAG_READ(PINT_UP)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_UP);
//			modifyTargetSpeedR(10);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getTargetSpeedR(), 3, 1, 2, '_', color);
//		}
//		if (PINT_FALL_FLAG_READ(PINT_DOWN)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_DOWN);
//			modifyTargetSpeedR(-10);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getTargetSpeedR(), 3, 1, 2, '_', color);
//		}
//	}
//	PINT_FALL_FLAG_CLEAR(PINT_BACK);
//	pit_init_ms(menu_interval);
//}

//void MagMax_flag_toggle(uint8 line, uint8 color) {
//	hc05_rxPack.MagMax_enabled = !hc05_rxPack.MagMax_enabled;
//}

//void MagMaxCollect_displayStatus(uint8 line, uint8 color) {
//	if (hc05_rxPack.MagMax_enabled) {
//		oled_p6x8str(2 + 6 * 12, line, "START", color);
//	}
//	else
//		oled_p6x8str(2 + 6 * 12, line, "STOP ", color);
//}

///**************************************MainMenu结束*************************************************/


///**************************************SetPIDMenu开始**********************************************/
//void displaySpeedKp(uint8 line, uint8 color) {
//	oled_printf_float(2 + 6 * 10, line, getSpeedKp(), 2, 2, color);
//}

//void displaySpeedKi(uint8 line, uint8 color) {
//	oled_printf_float(2 + 6 * 10, line, getSpeedKi(), 2, 2, color);
//}

//void displaySpeedKd(uint8 line, uint8 color) {
//	oled_printf_float(2 + 6 * 10, line, getSpeedKd(), 2, 2, color);
//}

//void modSpeedKp(uint8 line, uint8 color) {
//	pit_deinit();
//	oled_printf_float_and_ch(2 + 6 * 10, line, getSpeedKp(), 2, 2, -1, '_', color);
//	while (!PINT_FALL_FLAG_READ(PINT_BACK)) {
//		if (PINT_FALL_FLAG_READ(PINT_UP)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_UP);
//			modifySpeedKp(0.1);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getSpeedKp(), 2, 2, -1, '_', color);
//		}
//		if (PINT_FALL_FLAG_READ(PINT_DOWN)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_DOWN);
//			modifySpeedKp(-0.1);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getSpeedKp(), 2, 2, -1, '_', color);
//		}
//	}
//	PINT_FALL_FLAG_CLEAR(PINT_BACK);
//	pit_init_ms(menu_interval);
//}

//void modSpeedKi(uint8 line, uint8 color) {
//	pit_deinit();
//	oled_printf_float_and_ch(2 + 6 * 10, line, getSpeedKi(), 2, 2, -1, '_', color);
//	while (!PINT_FALL_FLAG_READ(PINT_BACK)) {
//		if (PINT_FALL_FLAG_READ(PINT_UP)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_UP);
//			modifySpeedKi(0.1);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getSpeedKi(), 2, 2, -1, '_', color);
//		}
//		if (PINT_FALL_FLAG_READ(PINT_DOWN)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_DOWN);
//			modifySpeedKi(-0.1);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getSpeedKi(), 2, 2, -1, '_', color);
//		}
//	}
//	PINT_FALL_FLAG_CLEAR(PINT_BACK);
//	pit_init_ms(menu_interval);
//}

//void modSpeedKd(uint8 line, uint8 color) {
//	pit_deinit();
//	oled_printf_float_and_ch(2 + 6 * 10, line, getSpeedKd(), 2, 2, -1, '_', color);
//	while (!PINT_FALL_FLAG_READ(PINT_BACK)) {
//		if (PINT_FALL_FLAG_READ(PINT_UP)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_UP);
//			modifySpeedKd(0.1);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getSpeedKd(), 2, 2, -1, '_', color);
//		}
//		if (PINT_FALL_FLAG_READ(PINT_DOWN)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_DOWN);
//			modifySpeedKd(-0.1);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getSpeedKd(), 2, 2, -1, '_', color);
//		}
//	}
//	PINT_FALL_FLAG_CLEAR(PINT_BACK);
//	pit_init_ms(menu_interval);
//}

//void displayMagKp(uint8 line, uint8 color) {
//	oled_printf_float(2 + 6 * 10, line, getMagKp(), 2, 2, color);
//}

//void displayMagKi(uint8 line, uint8 color) {
//	oled_printf_float(2 + 6 * 10, line, getMagKi(), 2, 2, color);
//}

//void displayMagKd(uint8 line, uint8 color) {
//	oled_printf_float(2 + 6 * 10, line, getMagKd(), 2, 2, color);
//}

//void modMagKp(uint8 line, uint8 color) {
//	pit_deinit();
//	oled_printf_float_and_ch(2 + 6 * 10, line, getMagKp(), 2, 2, -1, '_', color);
//	while (!PINT_FALL_FLAG_READ(PINT_BACK)) {
//		if (PINT_FALL_FLAG_READ(PINT_UP)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_UP);
//			modifyMagKp(0.1);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getMagKp(), 2, 2, -1, '_', color);
//		}
//		if (PINT_FALL_FLAG_READ(PINT_DOWN)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_DOWN);
//			modifyMagKp(-0.1);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getMagKp(), 2, 2, -1, '_', color);
//		}
//	}
//	PINT_FALL_FLAG_CLEAR(PINT_BACK);
//	pit_init_ms(menu_interval);
//}

//void modMagKi(uint8 line, uint8 color) {
//	pit_deinit();
//	oled_printf_float_and_ch(2 + 6 * 10, line, getMagKi(), 2, 2, -1, '_', color);
//	while (!PINT_FALL_FLAG_READ(PINT_BACK)) {
//		if (PINT_FALL_FLAG_READ(PINT_UP)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_UP);
//			modifyMagKi(0.1);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getMagKi(), 2, 2, -1, '_', color);
//		}
//		if (PINT_FALL_FLAG_READ(PINT_DOWN)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_DOWN);
//			modifyMagKi(-0.1);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getMagKi(), 2, 2, -1, '_', color);
//		}
//	}
//	PINT_FALL_FLAG_CLEAR(PINT_BACK);
//	pit_init_ms(menu_interval);
//}

//void modMagKd(uint8 line, uint8 color) {
//	pit_deinit();
//	oled_printf_float_and_ch(2 + 6 * 10, line, getMagKd(), 2, 2, -1, '_', color);
//	while (!PINT_FALL_FLAG_READ(PINT_BACK)) {
//		if (PINT_FALL_FLAG_READ(PINT_UP)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_UP);
//			modifyMagKd(0.1);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getMagKd(), 2, 2, -1, '_', color);
//		}
//		if (PINT_FALL_FLAG_READ(PINT_DOWN)) {
//			systick_delay_ms(10);
//			PINT_FALL_FLAG_CLEAR(PINT_DOWN);
//			modifyMagKd(-0.1);
//			oled_printf_float_and_ch(2 + 6 * 10, line, getMagKd(), 2, 2, -1, '_', color);
//		}
//	}
//	PINT_FALL_FLAG_CLEAR(PINT_BACK);
//	pit_init_ms(menu_interval);
//}


///**************************************SetPIDMenu结束**********************************************/


///**************************************displayMenu开始*********************************************/
//void displaySpeedL(uint8 line, uint8 color) {
//	oled_printf_float(2 + 6 * 10, line, speed_get(LEFT), 2, 2, color);
//}

//void displaySpeedR(uint8 line, uint8 color) {
//	oled_printf_float(2 + 6 * 10, line, speed_get(RIGHT), 2, 2, color);
//}

//void displayMag1Bar(uint8 line, uint8 color) {
//	uint8 i;
//	for (i = 2 + 6 * 4; (i - (2 + 6 * 1)) < getMag(0); i++)
//		oled_putpixel(i, line, 0x7f);
//}

//void displayMag2Bar(uint8 line, uint8 color) {
//	uint8 i;
//	for (i = 2 + 6 * 4; (i - (2 + 6 * 1)) < getMag(1); i++)
//		oled_putpixel(i, line, 0x7f);
//}

//void displayMag3Bar(uint8 line, uint8 color) {
//	uint8 i;
//	for (i = 2 + 6 * 4; (i - (2 + 6 * 1)) < getMag(2); i++)
//		oled_putpixel(i, line, 0x7f);
//}

//void displayMag1Num(uint8 line, uint8 color) {
//	oled_printf_float(2 + 6 * 10, line, getMag(0), 3, 1, color);
//}

//void displayMag2Num(uint8 line, uint8 color) {
//	oled_printf_float(2 + 6 * 10, line, getMag(1), 3, 1, color);
//}

//void displayMag3Num(uint8 line, uint8 color) {
//	oled_printf_float(2 + 6 * 10, line, getMag(2), 3, 1, color);
//}

//void displayMotPWM1(uint8 line, uint8 color) {
//	oled_uint16(2 + 6 * 8, line, getMotPWM(LEFT, 0), color);
//	oled_uint16(2 + 6 * 14, line, getMotPWM(RIGHT, 0), color);
//}

//void displayMotPWM2(uint8 line, uint8 color) {
//	oled_uint16(2 + 6 * 8, line, getMotPWM(LEFT, 1), color);
//	oled_uint16(2 + 6 * 14, line, getMotPWM(RIGHT, 1), color);
//}

//void displayMotPWM3(uint8 line, uint8 color) {
//	oled_uint16(2 + 6 * 8, line, getMotPWM(LEFT, 2), color);
//	oled_uint16(2 + 6 * 14, line, getMotPWM(RIGHT, 2), color);
//}

//void displayMotPWM4(uint8 line, uint8 color) {
//	oled_uint16(2 + 6 * 8, line, getMotPWM(LEFT, 3), color);
//	oled_uint16(2 + 6 * 14, line, getMotPWM(RIGHT, 3), color);
//}

///**************************************displayMenu结束*********************************************/
//void func() {}

//void menu_init() {
//	//MainMenu开始
//	MainMenu.subMenus = malloc(sizeof(&MainMenu) * MainMenu.itemCount);
//	MainMenu.subMenus[0] = NULL;
//	MainMenu.subMenus[1] = NULL;
//	MainMenu.subMenus[2] = &SetpidMenu;
//	MainMenu.subMenus[3] = &DisplayMenu;
//	MainMenu.subMenus[4] = NULL;

//	MainMenu.func_Pressed = malloc(4 * MainMenu.itemCount);
//	MainMenu.func_Pressed[0] = &modTargetSpeedL;
//	MainMenu.func_Pressed[1] = &modTargetSpeedR;
//	MainMenu.func_Pressed[2] = &func;
//	MainMenu.func_Pressed[3] = &func;
//	MainMenu.func_Pressed[4] = &MagMax_flag_toggle;

//	MainMenu.func_NoPressed = malloc(4 * MainMenu.itemCount);
//	MainMenu.func_NoPressed[0] = &displayTargetSpeedL;
//	MainMenu.func_NoPressed[1] = &displayTargetSpeedR;
//	MainMenu.func_NoPressed[2] = &func;
//	MainMenu.func_NoPressed[3] = &func;
//	MainMenu.func_NoPressed[4] = &MagMaxCollect_displayStatus;

//	MainMenu.parent = NULL;//表示是顶级菜单
////MainMenu结束

////SetpidMenu开始
//	SetpidMenu.subMenus = malloc(sizeof(&SetpidMenu) * SetpidMenu.itemCount);
//	SetpidMenu.subMenus[0] =
//		SetpidMenu.subMenus[1] =
//		SetpidMenu.subMenus[2] =
//		SetpidMenu.subMenus[3] =
//		SetpidMenu.subMenus[4] =
//		SetpidMenu.subMenus[5] = NULL;

//	SetpidMenu.func_Pressed = malloc(4 * SetpidMenu.itemCount);
//	SetpidMenu.func_Pressed[0] = &modSpeedKp;
//	SetpidMenu.func_Pressed[1] = &modSpeedKi;
//	SetpidMenu.func_Pressed[2] = &modSpeedKd;
//	SetpidMenu.func_Pressed[3] = &modMagKp;
//	SetpidMenu.func_Pressed[4] = &modMagKi;
//	SetpidMenu.func_Pressed[5] = &modMagKd;

//	SetpidMenu.func_NoPressed = malloc(4 * SetpidMenu.itemCount);
//	SetpidMenu.func_NoPressed[0] = &displaySpeedKp;
//	SetpidMenu.func_NoPressed[1] = &displaySpeedKi;
//	SetpidMenu.func_NoPressed[2] = &displaySpeedKd;
//	SetpidMenu.func_NoPressed[3] = &displayMagKp;
//	SetpidMenu.func_NoPressed[4] = &displayMagKi;
//	SetpidMenu.func_NoPressed[5] = &displayMagKd;

//	SetpidMenu.parent = &MainMenu;//上一级菜单是MainMenu.进入查询子菜单后按返回键，将会显示这个菜单 项
////SetpidMenu结束

////DisplayMenu开始
//	DisplayMenu.subMenus = malloc(sizeof(&DisplayMenu) * DisplayMenu.itemCount);
//	DisplayMenu.subMenus[0] =
//		DisplayMenu.subMenus[1] =
//		DisplayMenu.subMenus[2] =
//		DisplayMenu.subMenus[3] =
//		DisplayMenu.subMenus[4] =
//		DisplayMenu.subMenus[5] =
//		DisplayMenu.subMenus[6] =
//		DisplayMenu.subMenus[7] =
//		DisplayMenu.subMenus[8] =
//		DisplayMenu.subMenus[9] =
//		DisplayMenu.subMenus[10] =
//		DisplayMenu.subMenus[11] = NULL;

//	DisplayMenu.func_Pressed = malloc(4 * DisplayMenu.itemCount);
//	DisplayMenu.func_Pressed[0] = &func;
//	DisplayMenu.func_Pressed[1] = &func;
//	DisplayMenu.func_Pressed[2] = &func;
//	DisplayMenu.func_Pressed[3] = &func;
//	DisplayMenu.func_Pressed[4] = &func;
//	DisplayMenu.func_Pressed[5] = &func;
//	DisplayMenu.func_Pressed[6] = &func;
//	DisplayMenu.func_Pressed[7] = &func;
//	DisplayMenu.func_Pressed[8] = &func;
//	DisplayMenu.func_Pressed[9] = &func;
//	DisplayMenu.func_Pressed[10] = &func;
//	DisplayMenu.func_Pressed[11] = &func;

//	DisplayMenu.func_NoPressed = malloc(4 * DisplayMenu.itemCount);
//	DisplayMenu.func_NoPressed[0] = &displayMag1Bar;
//	DisplayMenu.func_NoPressed[1] = &displayMag2Bar;
//	DisplayMenu.func_NoPressed[2] = &displayMag3Bar;
//	DisplayMenu.func_NoPressed[3] = &displayMag1Num;
//	DisplayMenu.func_NoPressed[4] = &displayMag2Num;
//	DisplayMenu.func_NoPressed[5] = &displayMag3Num;
//	DisplayMenu.func_NoPressed[6] = &displayMotPWM1;
//	DisplayMenu.func_NoPressed[7] = &displayMotPWM2;
//	DisplayMenu.func_NoPressed[8] = &displayMotPWM3;
//	DisplayMenu.func_NoPressed[9] = &displayMotPWM4;
//	DisplayMenu.func_NoPressed[10] = &displaySpeedL;
//	DisplayMenu.func_NoPressed[11] = &displaySpeedR;

//	DisplayMenu.parent = &MainMenu;
//	//DisplayMenu结束

//	currentMenu = &MainMenu;
//	oled_fill(0x00);
//	oled_p8x16str(2 * 6, 0, "HELLO WORLD", 0);
//	systick_delay_ms(500);
//	oled_p8x16str(0, 0, currentMenu->title, 0);
//	display();
//	pit_init_ms(menu_interval);
//}

//void button_ok(void) {
//	//void PIN_INT0_IRQHandler(void) {//ok
//	systick_delay_ms(10);
//	PINT_FALL_FLAG_CLEAR(PINT_OK);
//	if (currentMenu->subMenus[currentMenu->selected - 1] != NULL) {
//		currentMenu = currentMenu->subMenus[currentMenu->selected - 1];
//		oled_p8x16str(0, 0, currentMenu->title, 0);
//	}
//	else {
//		if (currentMenu->func_Pressed[currentMenu->selected - 1] != NULL)
//			currentMenu->func_Pressed[currentMenu->selected - 1](currentMenu->selected + 1, 1);//执行相应的函数
//	}
//}

//void button_up(void) {
//	//void PIN_INT1_IRQHandler(void) {//up
//	systick_delay_ms(10);
//	PINT_FALL_FLAG_CLEAR(PINT_UP);
//	if (currentMenu->selected == 1)
//		currentMenu->selected = currentMenu->itemCount;
//	else
//		currentMenu->selected--;
//}

//void button_down(void) {
//	//void PIN_INT2_IRQHandler(void) {//down
//	systick_delay_ms(10);
//	PINT_FALL_FLAG_CLEAR(PINT_DOWN);
//	if (currentMenu->selected == currentMenu->itemCount)
//		currentMenu->selected = 1;
//	else
//		currentMenu->selected++;
//}

//void button_back(void) {
//	//void PIN_INT3_IRQHandler(void) {//back
//	systick_delay_ms(10);
//	PINT_FALL_FLAG_CLEAR(PINT_BACK);
//	if (currentMenu->parent != NULL) {//父菜单不为空，将显示父菜单
//		currentMenu = currentMenu->parent;
//		oled_p8x16str(0, 0, currentMenu->title, 0);
//	}
//}

//void PIN_INT4_IRQHandler(void) {
//	systick_delay_ms(10);
//	PINT_FALL_FLAG_CLEAR(PINT_SS);
//	hc05_rxPack.speedPID_enabled = !hc05_rxPack.speedPID_enabled;
//}

//void menu_schedule(void) {
//	if (PINT_FALL_FLAG_READ(PINT_OK))
//		button_ok();
//	if (PINT_FALL_FLAG_READ(PINT_UP))
//		button_up();
//	if (PINT_FALL_FLAG_READ(PINT_DOWN))
//		button_down();
//	if (PINT_FALL_FLAG_READ(PINT_BACK))
//		button_back();
//	display();
//}
