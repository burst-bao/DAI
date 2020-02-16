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

#include "LPC546XX_spi.h"
#include "SEEKFREE_FONT.h"
#include "LPC546XX_iocon.h"
#include "LPC546XX_gpio.h"
#include "LPC546XX_systick.h"
#include "SEEKFREE_IPS.h"


//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void ips_writeIndex(uint8 dat)			//д����
{	
    IPS_DC(0);
    spi_mosi(IPS_SPIN,IPS_CS,&dat,&dat,1,1);		

}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void ips_writeData(uint8 dat)			//д����
{
    IPS_DC(1);
    spi_mosi(IPS_SPIN,IPS_CS,&dat,&dat,1,1);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �ڲ����ã��û��������
//  @param      void 		    
//  @return     				
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void ips_writedata_16bit(uint16 dat)	//��Һ����дһ��16λ����
{
    uint8 dat1[2];
    dat1[0] = dat >> 8;
    dat1[1] = (uint8)dat;
    
    IPS_DC(1);
    spi_mosi(IPS_SPIN,IPS_CS,dat1,dat1,2,1); 	//д������  ��λ��ǰ  ��λ�ں�
}




//-------------------------------------------------------------------------------------------------------------------
//  @brief      1.14�� IPSҺ����ʼ��
//  @return     void
//  @since      v1.0
//  Sample usage:               
//-------------------------------------------------------------------------------------------------------------------
void ips_init(void)
{
    (void)spi_init(IPS_SPIN, IPS_CS, IPS_SCL, IPS_SDA, IPS_SDA_IN, 0, 50*1000*1000);//Ӳ��SPI��ʼ��
    
    gpio_init(IPS_BL_PIN,GPO,1,NOPULL);
    gpio_init(IPS_DC_PIN,GPO,0,NOPULL);
    gpio_init(IPS_REST_PIN,GPO,0,NOPULL);

    IPS_REST(0);
    systick_delay_ms(200);
    
    IPS_REST(1);
    systick_delay_ms(100);
	
    ips_writeIndex(0x36);
    
    if      (IPS_DISPLAY_DIR==0)    ips_writeData(0x00);
    else if (IPS_DISPLAY_DIR==1)    ips_writeData(0xC0);
    else if (IPS_DISPLAY_DIR==2)    ips_writeData(0x70);
    else                            ips_writeData(0xA0);
    
    ips_writeIndex(0x3A); 
    ips_writeData(0x05);

    ips_writeIndex(0xB2);
    ips_writeData(0x0C);
    ips_writeData(0x0C);
    ips_writeData(0x00);
    ips_writeData(0x33);
    ips_writeData(0x33); 

    ips_writeIndex(0xB7); 
    ips_writeData(0x35);  

    ips_writeIndex(0xBB);
    ips_writeData(0x37);

    ips_writeIndex(0xC0);
    ips_writeData(0x2C);

    ips_writeIndex(0xC2);
    ips_writeData(0x01);

    ips_writeIndex(0xC3);
    ips_writeData(0x12);   

    ips_writeIndex(0xC4);
    ips_writeData(0x20);  

    ips_writeIndex(0xC6); 
    ips_writeData(0x0F);    

    ips_writeIndex(0xD0); 
    ips_writeData(0xA4);
    ips_writeData(0xA1);

    ips_writeIndex(0xE0);
    ips_writeData(0xD0);
    ips_writeData(0x04);
    ips_writeData(0x0D);
    ips_writeData(0x11);
    ips_writeData(0x13);
    ips_writeData(0x2B);
    ips_writeData(0x3F);
    ips_writeData(0x54);
    ips_writeData(0x4C);
    ips_writeData(0x18);
    ips_writeData(0x0D);
    ips_writeData(0x0B);
    ips_writeData(0x1F);
    ips_writeData(0x23);

    ips_writeIndex(0xE1);
    ips_writeData(0xD0);
    ips_writeData(0x04);
    ips_writeData(0x0C);
    ips_writeData(0x11);
    ips_writeData(0x13);
    ips_writeData(0x2C);
    ips_writeData(0x3F);
    ips_writeData(0x44);
    ips_writeData(0x51);
    ips_writeData(0x2F);
    ips_writeData(0x1F);
    ips_writeData(0x1F);
    ips_writeData(0x20);
    ips_writeData(0x23);

    ips_writeIndex(0x21); 

    ips_writeIndex(0x11); 
    systick_delay_ms(120); 

    ips_writeIndex(0x29);
    ips_clear(IPS_BGCOLOR);
}



void ips_set_region(uint16 x1,uint16 y1,uint16 x2,uint16 y2)
{
	if(IPS_DISPLAY_DIR==0)
	{
		ips_writeIndex(0x2a);//�е�ַ����
		ips_writedata_16bit(x1+52);
		ips_writedata_16bit(x2+52);
		ips_writeIndex(0x2b);//�е�ַ����
		ips_writedata_16bit(y1+40);
		ips_writedata_16bit(y2+40);
		ips_writeIndex(0x2c);//������д
	}
	else if(IPS_DISPLAY_DIR==1)
	{
		ips_writeIndex(0x2a);//�е�ַ����
		ips_writedata_16bit(x1+53);
		ips_writedata_16bit(x2+53);
		ips_writeIndex(0x2b);//�е�ַ����
		ips_writedata_16bit(y1+40);
		ips_writedata_16bit(y2+40);
		ips_writeIndex(0x2c);//������д
	}
	else if(IPS_DISPLAY_DIR==2)
	{
		ips_writeIndex(0x2a);//�е�ַ����
		ips_writedata_16bit(x1+40);
		ips_writedata_16bit(x2+40);
		ips_writeIndex(0x2b);//�е�ַ����
		ips_writedata_16bit(y1+53);
		ips_writedata_16bit(y2+53);
		ips_writeIndex(0x2c);//������д
	}
	else
	{
		ips_writeIndex(0x2a);//�е�ַ����
		ips_writedata_16bit(x1+40);
		ips_writedata_16bit(x2+40);
		ips_writeIndex(0x2b);//�е�ַ����
		ips_writedata_16bit(y1+52);
		ips_writedata_16bit(y2+52);
		ips_writeIndex(0x2c);//������д
	}
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����������
//  @param      color     		��ɫ����
//  @return     void
//  @since      v1.0
//  Sample usage:               ips_clear(IPS_YELLOW);// ȫ������Ϊ��ɫ
//-------------------------------------------------------------------------------------------------------------------
void ips_clear(uint16 color)
{
    uint16 i,j;
	ips_set_region(0,0,IPS_X_MAX-1,IPS_Y_MAX-1);
    for(i=0;i<IPS_X_MAX;i++)
    {
        for (j=0;j<IPS_Y_MAX;j++)
	   	{
        	ips_writedata_16bit(color);	 			 
	    }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ������
//  @param      x     	        ����x��������
//  @param      y     	        ����y��������
//  @param      dat       	    ��Ҫ��ʾ����ɫ
//  @return     void
//  @since      v1.0
//  Sample usage:               ips_drawpoint(0,0,IPS_RED);  //����0,0��һ����ɫ�ĵ�
//-------------------------------------------------------------------------------------------------------------------
void ips_drawpoint(uint16 x,uint16 y,uint16 color)
{
    ips_set_region(x,y,x,y);
    ips_writedata_16bit(color);
}



//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ�ַ�
//  @param      x     	        ����x�������� ������Χ 0 -��IPS_X_MAX-1��
//  @param      y     	        ����y�������� ������Χ 0 -��IPS_Y_MAX-1��
//  @param      dat       	    ��Ҫ��ʾ���ַ�
//  @return     void
//  @since      v1.0
//  Sample usage:               ips_showchar(0,0,'x');//����0,0дһ���ַ�x
//-------------------------------------------------------------------------------------------------------------------
void ips_showchar(uint16 x,uint16 y,uint8 dat)
{
	uint8 i,j;
	uint8 temp;
    
	for(i=0; i<16; i++)
	{
		ips_set_region(x,y+i,x+7,y+i);
		temp = tft_ascii[dat-32][i];//��32��Ϊ��ȡģ�Ǵӿո�ʼȡ�� �ո���ascii�������32
		for(j=0; j<8; j++)
		{
			if(temp&0x01)	
            {
                ips_writedata_16bit(IPS_PENCOLOR);
            }
			else			ips_writedata_16bit(IPS_BGCOLOR);
			temp>>=1;
		}
	}
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ�ַ���
//  @param      x     	        ����x��������  ������Χ 0 -��IPS_X_MAX-1��
//  @param      y     	        ����y��������  ������Χ 0 -��IPS_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ���ַ���
//  @return     void
//  @since      v1.0
//  Sample usage:               ips_showstr(0,0,"seekfree");
//-------------------------------------------------------------------------------------------------------------------
void ips_showstr(uint16 x,uint16 y,uint8 dat[])
{
	uint16 j;
	
	j = 0;
	while(dat[j] != '\0')
	{
		ips_showchar(x+8*j,y*16,dat[j]);
		j++;
	}
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ8λ�з���
//  @param      x     	        ����x��������  ������Χ 0 -��IPS_X_MAX-1��
//  @param      y     	        ����y��������  ������Χ 0 -��IPS_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ�ı�������������int8
//  @return     void
//  @since      v1.0
//  Sample usage:               ips_showint8(0,0,x);//xΪint8����
//-------------------------------------------------------------------------------------------------------------------
void ips_showint8(uint16 x,uint16 y,int8 dat)
{
	uint8 a[3];
	uint8 i;
	if(dat<0)
	{
		ips_showchar(x,y*16,'-');
		dat = -dat;
	}
	else	ips_showchar(x,y*16,' ');
	
	a[0] = dat/100;
	a[1] = dat/10%10;
	a[2] = dat%10;
	i = 0;
	while(i<3)
	{
		ips_showchar(x+(8*(i+1)),y*16,'0' + a[i]);
		i++;
	}
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ8λ�޷���
//  @param      x     	        ����x�������� ������Χ 0 -��IPS_X_MAX-1��
//  @param      y     	        ����y�������� ������Χ 0 -��IPS_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ�ı�������������uint8
//  @return     void
//  @since      v1.0
//  Sample usage:               ips_showuint8(0,0,x);//xΪuint8����
//-------------------------------------------------------------------------------------------------------------------
void ips_showuint8(uint16 x,uint16 y,uint8 dat)
{
	uint8 a[3];
	uint8 i;
	
	a[0] = dat/100;
	a[1] = dat/10%10;
	a[2] = dat%10;
	i = 0;
	while(i<3)
	{
		ips_showchar(x+(8*i),y*16,'0' + a[i]);
		i++;
	}
	
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ16λ�з���
//  @param      x     	        ����x�������� ������Χ 0 -��IPS_X_MAX-1��
//  @param      y     	        ����y�������� ������Χ 0 -��IPS_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ�ı�������������int16
//  @return     void
//  @since      v1.0
//  Sample usage:               ips_showint16(0,0,x);//xΪint16����
//-------------------------------------------------------------------------------------------------------------------
void ips_showint16(uint16 x,uint16 y,int16 dat)
{
	uint8 a[5];
	uint8 i;
	if(dat<0)
	{
		ips_showchar(x,y*16,'-');
		dat = -dat;
	}
	else	ips_showchar(x,y*16,' ');

	a[0] = dat/10000;
	a[1] = dat/1000%10;
	a[2] = dat/100%10;
	a[3] = dat/10%10;
	a[4] = dat%10;
	
	i = 0;
	while(i<5)
	{
		ips_showchar(x+(8*(i+1)),y*16,'0' + a[i]);
		i++;
	}
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ16λ�޷���
//  @param      x     	        ����x�������� ������Χ 0 -��IPS_X_MAX-1��
//  @param      y     	        ����y�������� ������Χ 0 -��IPS_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ�ı�������������uint16
//  @return     void
//  @since      v1.0
//  Sample usage:               ips_showuint16(0,0,x);//xΪuint16����
//-------------------------------------------------------------------------------------------------------------------
void ips_showuint16(uint16 x,uint16 y,uint16 dat)
{
	uint8 a[5];
	uint8 i;

	a[0] = dat/10000;
	a[1] = dat/1000%10;
	a[2] = dat/100%10;
	a[3] = dat/10%10;
	a[4] = dat%10;
	
	i = 0;
	while(i<5)
	{
		ips_showchar(x+(8*i),y*16,'0' + a[i]);
		i++;
	}
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ32λ�з���(ȥ������������Ч��0)
//  @param      x     	        ����x�������� ������Χ 0 -��IPS_X_MAX-1��
//  @param      y     	        ����y�������� ������Χ 0 -��IPS_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ�ı�������������uint32
//  @param      num       	    ��Ҫ��ʾ��λ�� ���10λ  ������������
//  @return     void
//  @since      v1.0
//  Sample usage:               ips_showuint32(0,0,x,3);//x����Ϊint32 uint16 int16 uint8 int8����
//  Sample usage:               ��������ʾһ�� ��-����   ������ʾһ���ո�
//-------------------------------------------------------------------------------------------------------------------
void ips_showint32(uint16 x,uint16 y,int32 dat,uint8 num)
{
    int8    buff[34];
    uint8   length;
    
    if(10<num)      num = 10;
    
    num++;
    if(0>dat)   length = zf_sprintf( &buff[0],"%d",dat);//����
    else
    {
        buff[0] = ' ';
        length = zf_sprintf( &buff[1],"%d",dat);
        length++;
    }
    while(length < num)
    {
        buff[length] = ' ';
        length++;
    }
    buff[num] = '\0';

    ips_showstr(x, y, (uint8 *)buff);	//��ʾ����
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      Һ����ʾ������(ȥ������������Ч��0)
//  @param      x     	        ����x�������� ������Χ 0 -��IPS_X_MAX-1��
//  @param      y     	        ����y�������� ������Χ 0 -��IPS_Y_MAX/16-1��
//  @param      dat       	    ��Ҫ��ʾ�ı�������������float��double
//  @param      num       	    ����λ��ʾ����   ���10λ  
//  @param      pointnum        С��λ��ʾ����   ���6λ
//  @return     void
//  @since      v1.0
//  Sample usage:               ips_showfloat(0,0,x,2,3);//��ʾ������   ������ʾ2λ   С����ʾ��λ
//  @note                       �ر�ע�⵱����С��������ʾ��ֵ����д���ֵ��һ����ʱ��
//                              ���������ڸ��������ȶ�ʧ���⵼�µģ��Ⲣ������ʾ���������⣬
//                              �й���������飬�����аٶ�ѧϰ   ���������ȶ�ʧ���⡣
//                              ��������ʾһ�� ��-����   ������ʾһ���ո�
//-------------------------------------------------------------------------------------------------------------------
void ips_showfloat(uint16 x,uint16 y,double dat,uint8 num,uint8 pointnum)
{
    uint8   length;
	int8    buff[34];
	int8    start,end,point;

	if(6<pointnum)  pointnum = 6;
    if(10<num)      num = 10;
        
    if(0>dat)   length = zf_sprintf( &buff[0],"%f",dat);//����
    else
    {
        length = zf_sprintf( &buff[1],"%f",dat);
        length++;
    }
    point = length - 7;         //����С����λ��
    start = point - num - 1;    //������ʼλ
    end = point + pointnum + 1; //�������λ
    while(0>start)//����λ����  ĩβӦ�����ո�
    {
        buff[end] = ' ';
        end++;
        start++;
    }
    
    if(0>dat)   buff[start] = '-';
    else        buff[start] = ' ';
    
    buff[end] = '\0';

    ips_showstr(x, y, (uint8 *)buff);	//��ʾ����
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      �����(�Ҷ�����ͷ)Һ����ʾ����
//  @param      *p     			ͼ�������ַ
//  @param      width     	    ͼ����
//  @param      height     	    ͼ��߶�
//  @return     void
//  @since      v1.0
//  Sample usage:              
//  @note       ͼ��Ŀ���������Һ���Ŀ�ȣ����Զ�����������ʾ������������ʾȫ��Ұ
//-------------------------------------------------------------------------------------------------------------------
void ips_displayimage032(uint8 *p, uint16 width, uint16 height) 
{
    uint32 i,j;
                
    uint16 color = 0;
	uint16 temp = 0;
	
    uint16 coord_x = 0;
    uint16 coord_y = 0;
    
    coord_x = width>IPS_X_MAX?IPS_X_MAX:width;
    coord_y = height>IPS_Y_MAX?IPS_Y_MAX:height;
    ips_set_region(0,0,coord_x-1,coord_y-1);
    
    for(j=0;j<coord_y;j++)
    {
        for(i=0;i<coord_x;i++)
        {
            temp = *(p+j*width+i*width/coord_x);//��ȡ���ص�
            color=(0x001f&((temp)>>3))<<11;
            color=color|(((0x003f)&((temp)>>2))<<5);
            color=color|(0x001f&((temp)>>3));
            ips_writedata_16bit(color); 
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      �����(�Ҷ�����ͷ)Һ��������ʾ����
//  @param      *p     			ͼ�������ַ
//  @param      width     	    ͼ����
//  @param      height     	    ͼ��߶�
//  @param      dis_width       ͼ����ʾ���  0 -��IPS_X_MAX-1��
//  @param      dis_height      ͼ����ʾ�߶�  0 -��IPS_Y_MAX-1��
//  @return     void
//  @since      v1.0
//  Sample usage:              
//  @note       ͼ��Ŀ���������Һ���Ŀ�ȣ����Զ�����������ʾ������������ʾȫ��Ұ
//-------------------------------------------------------------------------------------------------------------------
void ips_displayimage032_zoom(uint8 *p, uint16 width, uint16 height, uint16 dis_width, uint16 dis_height)
{
    uint32 i,j;
                
    uint16 color = 0;
	uint16 temp = 0;

    ips_set_region(0,0,dis_width-1,dis_height-1);//������ʾ���� 
    
    for(j=0;j<dis_height;j++)
    {
        for(i=0;i<dis_width;i++)
        {
            temp = *(p+(j*120/dis_height)*width+i*width/dis_width);//��ȡ���ص�
            color=(0x001f&((temp)>>3))<<11;
            color=color|(((0x003f)&((temp)>>2))<<5);
            color=color|(0x001f&((temp)>>3));
            ips_writedata_16bit(color); 
        }
    }
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      С���(��ֵ������ͷ)Һ����ʾ����
//  @param      *p     			ͼ�������ַ
//  @param      width     	    ͼ����
//  @param      height     	    ͼ��߶�
//  @return     void
//  @since      v1.0
//  @note      	ͼ��ֱ�����Ҫ������120(��)*160(��)����       
//-------------------------------------------------------------------------------------------------------------------
void ips_displayimage7725(uint8 *p, uint16 width, uint16 height) 
{
    int i,j; 
	
    uint16 temp = 0;
    ips_set_region(0,0,width-1,height-1);
	for(i=0;i<height * (width/8);i++)
    {
        temp = *p;
        p++;
        for(j=0; j<8; j++)
        {
            if( (temp<<j)&0x80 )	ips_writedata_16bit(IPS_WHITE);
            else					ips_writedata_16bit(IPS_BLACK);
        }
    }
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      ������ʾ
//  @param      x       ������ 0-��IPS_X_MAX-1��
//  @param      y       ������ 0-��IPS_Y_MAX-1��
//  @param      size    ȡģ��ʱ�����õĺ��������С��Ҳ����һ������ռ�õĵ��󳤿�Ϊ���ٸ��㣬ȡģ��ʱ����Ҫ������һ���ġ�
//  @param      *p      ��Ҫ��ʾ�ĺ�������
//  @param      number  ��Ҫ��ʾ����λ
//  @param      color   ��ʾ��ɫ
//  @return     void
//  @since      v1.0
//  Sample usage:		ips_display_chinese(0,0,16,chinese_test[0],4,RED);//��ʾfont�ļ������ ʾ��
//  @Note       ʹ��PCtoLCD2002���ȡģ		    ���롢����ʽ��˳��   16*16
//-------------------------------------------------------------------------------------------------------------------
void ips_display_chinese(uint16 x, uint16 y, uint8 size, const uint8 *p, uint8 number, uint16 color)
{
    int i, j, k; 
    uint8 temp, temp1, temp2;
    const uint8 *p_data;
    
    temp2 = size/8;
    
    ips_set_region(x,y,number*size-1+x,y+size-1);
    
    for(i=0;i<size;i++)
    {
        temp1 = number;
        p_data = p+i*temp2;
        while(temp1--)
        {
            for(k=0;k<temp2;k++)
            {
                for(j=8;j>0;j--)
                {
                    temp = (*p_data>>(j-1)) & 0x01;
                    if(temp)    ips_writedata_16bit(color);
                    else        ips_writedata_16bit(IPS_BGCOLOR);
                }
                p_data++;
            }
            p_data = p_data - temp2 + temp2*size;
        }   
    }
}


