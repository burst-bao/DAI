/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2018,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��179029047
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		IPS
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴common.h��VERSION�궨��
 * @Software 		IAR 7.8 or MDK 5.24a
 * @Target core		LPC54606J512BD100
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2019-04-12
 * @note		
					���߶��壺
					------------------------------------ 
						ģ��ܽ�            ��Ƭ���ܽ�
						SCL                 �鿴IPS_SCL�궨�������     Ӳ��SPI���Ų��������л�
						SDA                 �鿴IPS_SDA�궨�������     Ӳ��SPI���Ų��������л�
						RES                 �鿴IPS_REST_PIN�궨�������    
						DC                  �鿴IPS_DC_PIN�궨�������  
						CS                  �鿴IPS_CS�궨�������      Ӳ��SPI���Ų��������л�
						
						��Դ����
						BL  3.3V��Դ������������ţ�Ҳ���Խ�PWM���������ȣ�
						VCC 3.3V��Դ
						GND ��Դ��
						���ֱ���135*240
					------------------------------------ 

 ********************************************************************************************************************/


#ifndef _SEEKFREE_IPS_H
#define _SEEKFREE_IPS_H


#include "common.h"


//-----------------���Ŷ���------------------------------
#define IPS_SPIN        SPI_4           //����ʹ�õ�SPI��
#define IPS_SCL         SPI4_SCK_B19    //����SPI_SCK����
#define IPS_SDA         SPI4_MOSI_B21   //����SPI_MOSI����
#define IPS_SDA_IN      SPI4_MISO_B20   //����SPI_MISO����  TFTû��MISO���ţ�����������Ȼ��Ҫ���壬��spi�ĳ�ʼ��ʱ��Ҫʹ��
#define IPS_CS          SPI4_CS0_B9     //����SPI_CS����
                        
#define IPS_BL_PIN      B7	            //Һ���������Ŷ���
#define IPS_REST_PIN    B8              //Һ����λ���Ŷ���
#define IPS_DC_PIN 	    B10	            //Һ������λ���Ŷ���

#define IPS_DC(x)       gpio_set(IPS_DC_PIN,x);
#define IPS_REST(x)     gpio_set(IPS_REST_PIN,x);


//-----------------Һ����С����------------------------------
#define IPS_SIZE        0           //1.14�� IPSҺ��
//#define IPS_SIZE        1           //1.3��  IPSҺ��(��δ�Ƴ�)

#if  (0 == IPS_SIZE)
#define X_MAX   135
#define Y_MAX   240

#elif  (1 == IPS_SIZE)
#define X_MAX   240
#define Y_MAX   240

#else
#error "IPS_SIZE �������"
     
#endif



//-----------------������ɫ------------------------------
#define IPS_RED     	0XF800      //��ɫ
#define IPS_GREEN   	0X07E0      //��ɫ
#define IPS_BLUE    	0X001F      //��ɫ
#define IPS_BRED    	0XF81F  
#define IPS_GRED    	0XFFE0      //��ɫ
#define IPS_GBLUE   	0X07FF      //
#define IPS_BLACK   	0X0000      //��ɫ
#define IPS_WHITE   	0XFFFF      //��ɫ
#define IPS_YELLOW  	0xFFE0      //��ɫ


//����д�ֱʵ���ɫ
#define IPS_PENCOLOR    IPS_RED

//���屳����ɫ
#define IPS_BGCOLOR     IPS_WHITE



//������ʾ����
//0 ����ģʽ
//1 ����ģʽ  ��ת180
//2 ����ģʽ
//3 ����ģʽ  ��ת180
#define IPS_DISPLAY_DIR 3

#if (0==IPS_DISPLAY_DIR || 1==IPS_DISPLAY_DIR)
#define	IPS_X_MAX	X_MAX	//Һ��X�����
#define IPS_Y_MAX	Y_MAX   //Һ��Y�����
     
#elif (2==IPS_DISPLAY_DIR || 3==IPS_DISPLAY_DIR)
#define	IPS_X_MAX	Y_MAX	//Һ��X�����
#define IPS_Y_MAX	X_MAX   //Һ��Y�����
     
#else
#error "IPS_DISPLAY_DIR �������"
     
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
