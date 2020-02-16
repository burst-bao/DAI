/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：179029047
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		IPS
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看common.h内VERSION宏定义
 * @Software 		IAR 7.8 or MDK 5.24a
 * @Target core		LPC54606J512BD100
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-04-12
 * @note		
					接线定义：
					------------------------------------ 
						模块管脚            单片机管脚
						SCL                 查看IPS_SCL宏定义的引脚     硬件SPI引脚不可随意切换
						SDA                 查看IPS_SDA宏定义的引脚     硬件SPI引脚不可随意切换
						RES                 查看IPS_REST_PIN宏定义的引脚    
						DC                  查看IPS_DC_PIN宏定义的引脚  
						CS                  查看IPS_CS宏定义的引脚      硬件SPI引脚不可随意切换
						
						电源引脚
						BL  3.3V电源（背光控制引脚，也可以接PWM来控制亮度）
						VCC 3.3V电源
						GND 电源地
						最大分辨率135*240
					------------------------------------ 

 ********************************************************************************************************************/


#ifndef _SEEKFREE_IPS_H
#define _SEEKFREE_IPS_H


#include "common.h"


//-----------------引脚定义------------------------------
#define IPS_SPIN        SPI_4           //定义使用的SPI号
#define IPS_SCL         SPI4_SCK_B19    //定义SPI_SCK引脚
#define IPS_SDA         SPI4_MOSI_B21   //定义SPI_MOSI引脚
#define IPS_SDA_IN      SPI4_MISO_B20   //定义SPI_MISO引脚  TFT没有MISO引脚，但是这里任然需要定义，在spi的初始化时需要使用
#define IPS_CS          SPI4_CS0_B9     //定义SPI_CS引脚
                        
#define IPS_BL_PIN      B7	            //液晶背光引脚定义
#define IPS_REST_PIN    B8              //液晶复位引脚定义
#define IPS_DC_PIN 	    B10	            //液晶命令位引脚定义

#define IPS_DC(x)       gpio_set(IPS_DC_PIN,x);
#define IPS_REST(x)     gpio_set(IPS_REST_PIN,x);


//-----------------液晶大小定义------------------------------
#define IPS_SIZE        0           //1.14寸 IPS液晶
//#define IPS_SIZE        1           //1.3寸  IPS液晶(暂未推出)

#if  (0 == IPS_SIZE)
#define X_MAX   135
#define Y_MAX   240

#elif  (1 == IPS_SIZE)
#define X_MAX   240
#define Y_MAX   240

#else
#error "IPS_SIZE 定义错误"
     
#endif



//-----------------常用颜色------------------------------
#define IPS_RED     	0XF800      //红色
#define IPS_GREEN   	0X07E0      //绿色
#define IPS_BLUE    	0X001F      //蓝色
#define IPS_BRED    	0XF81F  
#define IPS_GRED    	0XFFE0      //灰色
#define IPS_GBLUE   	0X07FF      //
#define IPS_BLACK   	0X0000      //黑色
#define IPS_WHITE   	0XFFFF      //白色
#define IPS_YELLOW  	0xFFE0      //黄色


//定义写字笔的颜色
#define IPS_PENCOLOR    IPS_RED

//定义背景颜色
#define IPS_BGCOLOR     IPS_WHITE



//定义显示方向
//0 竖屏模式
//1 竖屏模式  旋转180
//2 横屏模式
//3 横屏模式  旋转180
#define IPS_DISPLAY_DIR 3

#if (0==IPS_DISPLAY_DIR || 1==IPS_DISPLAY_DIR)
#define	IPS_X_MAX	X_MAX	//液晶X方宽度
#define IPS_Y_MAX	Y_MAX   //液晶Y方宽度
     
#elif (2==IPS_DISPLAY_DIR || 3==IPS_DISPLAY_DIR)
#define	IPS_X_MAX	Y_MAX	//液晶X方宽度
#define IPS_Y_MAX	X_MAX   //液晶Y方宽度
     
#else
#error "IPS_DISPLAY_DIR 定义错误"
     
#endif


void ips_init(void);
void ips_clear(uint16 color);
void ips_drawpoint(uint16 x,uint16 y,uint16 color);
void ips_showchar(uint16 x,uint16 y,uint8 dat);
void ips_showstr(uint16 x,uint16 y,uint8 dat[]);
void ips_showint8(uint16 x,uint16 y,int8 dat);
void ips_showuint8(uint16 x,uint16 y,uint8 dat);
void ips_showint16(uint16 x,uint16 y,int16 dat);
void ips_showuint16(uint16 x,uint16 y,uint16 dat);
void ips_showint32(uint16 x,uint16 y,int32 dat,uint8 num);
void ips_showfloat(uint16 x,uint16 y,double dat,uint8 num,uint8 pointnum);
void ips_displayimage032(uint8 *p, uint16 width, uint16 height);
void ips_displayimage032_zoom(uint8 *p, uint16 width, uint16 height, uint16 dis_width, uint16 dis_height);
void ips_displayimage7725(uint8 *p, uint16 width, uint16 height);
void ips_display_chinese(uint16 x, uint16 y, uint8 size, const uint8 *p, uint8 number, uint16 color);

#endif
