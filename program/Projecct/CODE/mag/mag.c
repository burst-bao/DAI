/*********电磁检测*********/
#include "LPC546XX_adc.h"
//#include "SEEKFREE_OLED.h"
#include "LPC546XX_eeprom.h"
#include "mag.h"
#include "hc05.h"

TMagPID MagPID;
float MagMax_float[3];  //电感标定 采集值
static float mag_float[3];
static float mag_raw[3];
float mag_speedpid_float;

//#define   MovFilter_layers    5 //滑动滤波层数

//int16  AD_valu[3],AD_V[3][MovFilter_layers],chazhi,chazhi_old;
//float  AD[3],sensor_to_one[3];
//float  Slope_AD_1;  // 用于坡道检测
//int16  Position_transit[2];  //记录过渡点归一化的值
//int16  AD_sum[3]; 
//int16  AD_MAX_NUM;   //
//int16  position = 2,position_back = 1;
//float  max_value,AD_0_max,AD_1_max,AD_2_max,AD_3_max;

inline static uint16 ad_ave(ADCCH_enum ch, ADCRES_enum resolution,uint8 ave_times)
{
	uint8 i;
	uint16 ad_sum=0;
	for(i=0;i<ave_times;i++)
    ad_sum+=adc_convert(ch,resolution);
	return ad_sum/ave_times;
}

void Mag_init(void) {
    adc_init(mag_ADC1);
    adc_init(mag_ADC2);
    adc_init(mag_ADC3);
    adc_init(mag_ADC4);
    adc_init(mag_ADC5);
	
    MagPID.err=0.0;           
    MagPID.err_last=0.0;       
    MagPID.err_sum=0.0;       
    MagPID.output=0.0; 
//    MagPID.Kp=0.0;
//	MagPID.Ki=0.0;
//	MagPID.Kd=0.0;  //定义比例、积分、微分系数
}

void SetMinAndMax_enable(bool en) {
   	hc05_rxPack.MagMax_enabled = en;
}

float mag_get(uint8_t n) {
    return mag_float[n];
}

static inline void CorrectMagDuty(float *Duty) { 
	if (*Duty > 1000)
		*Duty = 1000;
	if (*Duty < -1000)
		*Duty = -1000;
}

//void MagMax_Recalibrate(void)
//{
//  uint16  i,j;
//  static int16   Position_transit_raw[2];
//  float sensor_1,sensor_2;
//	static bool flag_disabled=true;
//  if(hc05_rxPack.MagMax_enabled){
//	  if(flag_disabled){
//		  MagMax_float[0] = MagMax_float[1] = MagMax_float[2] = 0;
//			flag_disabled=false;
//		}
//		AD_valu[0] = ad_ave(mag_ADC1,ADC_12BIT,6);    
//		AD_valu[1] = ad_ave(mag_ADC2,ADC_12BIT,6);   
//		AD_valu[2] = ad_ave(mag_ADC4,ADC_12BIT,6);
//		for(j=0;j<3;j++){      
//			 if(AD_valu[j] > MagMax_float[j]){
//					MagMax_float[j] = AD_valu[j];
//					if(j==0)    Position_transit_raw[0] =  AD_valu[1];  //0号电感最大时1号电感的值
//				  if(j==2)    Position_transit_raw[1] =  AD_valu[1];  //2号电感最大时1号电感的值
//		  }
//		}
////    delayms(1);           //延时    
//  }
//	else{
//				 /******************************记录的过渡点归一化*********************************/
//		 if(!flag_disabled){
//			 sensor_1 = (float)Position_transit_raw[0]/(float)MagMax_float[1]; 
//			 if(sensor_1 <= 0.0)  sensor_1 = 0.001;
//			 if(sensor_1 >= 1.0)  sensor_1 = 1.0; 
//			 
//			 sensor_2 = (float)Position_transit_raw[1]/(float)MagMax_float[1]; 
//			 if(sensor_2 <= 0.0)  sensor_2 = 0.001;
//			 if(sensor_2 >= 1.0)  sensor_2 = 1.0; 
//			 
//			 Position_transit[0] = (int16)(100 * sensor_1);
//			 Position_transit[1] = (int16)(100 * sensor_2); 
//			 
//			 //电感标定的最大值写入flash
//			 eeprom_write_word(MagMax0_Address,(uint32*)&MagMax_float[0]);
//			 eeprom_write_word(MagMax1_Address,(uint32*)&MagMax_float[1]);
//			 eeprom_write_word(MagMax2_Address,(uint32*)&MagMax_float[2]);
//			 
//			 //过渡点归一化值写入flash
//			 eeprom_write_word(Position_transit0_Address,(uint32*)&Position_transit[0]);
//			 eeprom_write_word(Position_transit1_Address,(uint32*)&Position_transit[1]);
//			 flag_disabled=true;
//		 }
//		}
//}


//void Mag_Read(void)
//{
//     int16  i,j,k,temp;
//     int16  ad_valu[3][5],ad_valu1[3],ad_sum[3];
//     
//     for(i=0;i<5;i++)
//     {
//         ad_valu[0][i]=ad_ave(mag_ADC1,ADC_12BIT,7);     // ADC0 通道 
//         ad_valu[1][i]=ad_ave(mag_ADC2,ADC_12BIT,7);     // ADC0 通道 
//         ad_valu[2][i]=ad_ave(mag_ADC4,ADC_12BIT,7);     // ADC0 通道
//     }
//  /*******************************冒泡排序********************************/
//     for(i=0;i<3;i++)     //3个电感     
//     {
//        for(j=0;j<4;j++)  //五个数据排序
//        {
//           for(k=0;k<4-j;k++)
//           {
//              if(ad_valu[i][k] > ad_valu[i][k+1])  //前面的比后面的大  则进行交换
//              {
//                 temp = ad_valu[i][k+1];
//                 ad_valu[i][k+1] = ad_valu[i][k];
//                 ad_valu[i][k] = temp;
//              }
//           }
//        }
//     }
//     for(i=0;i<5;i++)    //求中间三项的和
//     {
//        ad_sum[i] = ad_valu[i][1] + ad_valu[i][2] + ad_valu[i][3];       
//        ad_valu1[i] = ad_sum[i] / 3;
//     }
//  /********************************滑动平均滤波********************************/
//     for(i = 0;i < MovFilter_layers-1;i ++)
//     {
//         AD_V[0][i] = AD_V[0][i + 1];
//         AD_V[1][i] = AD_V[1][i + 1];
//         AD_V[2][i] = AD_V[2][i + 1];
//     }
//     for(i=0;i<3;i++)
//     {
//         AD_V[i][MovFilter_layers-1] =  ad_valu1[i];
//     }
//    
//     for(i = 0;i < MovFilter_layers;i ++)
//     {
//         AD_sum[0] += AD_V[0][i];
//         AD_sum[1] += AD_V[1][i];
//         AD_sum[2] += AD_V[2][i];
//     }
//     for(i=0;i<3;i++)  //求平均
//     {
//         AD_valu[i] = AD_sum[i] / MovFilter_layers;
//         AD_sum[i] = 0;   
//     }    
//     for(i=0;i<3;i++) 
//    {
//       sensor_to_one[i] = (float)AD_valu[i]/(float)MagMax_float[i]; 
//       if(sensor_to_one[i]<=0.0)  sensor_to_one[i]=0.001;
//       if(sensor_to_one[i]>1.0)  sensor_to_one[i]=1.0; 
//       
//       mag_float[i] = 100 * sensor_to_one[i];     //AD[i]为归一化后的值  范围为0-100
//    }      
//}

void Mag_PID_realize(void) {
//		oled_printf_float(2, 5, MagPID.Motor_pwmduty,5,3);
    MagPID.err = mag_speedpid_float;
	  MagPID.err_sum += MagPID.err;
//    MagPID.Increment = MagPID.Kp*(MagPID.err - MagPID.err_last) + 
//                       MagPID.Ki*MagPID.err +
//                       MagPID.Kd*(MagPID.err_pre - 2*MagPID.err_last + MagPID.err);
	    MagPID.output = MagPID.Kp*MagPID.err + 
                         MagPID.Ki*MagPID.err_sum +
                         MagPID.Kd*(MagPID.err - MagPID.err_last);
	  CorrectMagDuty(&MagPID.output);
    MagPID.err_last = MagPID.err;
}

void mag_schedule(void) {
  uint8_t i;
//	MagMax_Recalibrate();
//	Mag_Read();
	  static bool flag_disabled=true;
    mag_raw[0] = ad_ave(mag_ADC1, ADC_12BIT,6);
	  mag_raw[1] = ad_ave(mag_ADC2, ADC_12BIT,6);
	  mag_raw[2] = ad_ave(mag_ADC4, ADC_12BIT,6);
	if (hc05_rxPack.MagMax_enabled) {
		
		if(flag_disabled){
			for(i=0;i<3;i++) {
				MagMax_float[i]=0;
			}
			flag_disabled=false;
		}
		for(i=0;i<3;i++) {
			if(MagMax_float[i]<mag_raw[i]) 
                MagMax_float[i]=mag_raw[i];
		}
		eeprom_write_word(MagMax0_Address,(uint32*)&MagMax_float[0]);
		eeprom_write_word(MagMax1_Address,(uint32*)&MagMax_float[1]);
		eeprom_write_word(MagMax2_Address,(uint32*)&MagMax_float[2]);
	}
	else{
	  flag_disabled=true;
	}

	for(i=0;i<3;i++) { //归一化
		mag_raw[i]=mag_raw[i]/MagMax_float[i];
		if(mag_raw[i]<0.001f)
			mag_raw[i]=0.001;
		if(mag_raw[i]>1.0f)
			mag_raw[i]=1.0;
		mag_float[i]=mag_raw[i]*100;
	}
	  hc05_txPack.mag_uint8[0]=(uint8)mag_float[0];
	  hc05_txPack.mag_uint8[1]=(uint8)mag_float[1];
	  hc05_txPack.mag_uint8[2]=(uint8)mag_float[2]; 
		/*曲率修正*/
//			mag_speedpid_float= (mag_float[0] - mag_float[2]) / ((mag_float[0]+ mag_float[1] + mag_float[2]) * mag_float[1]);//差比和
	mag_speedpid_float= 500*(sqrt(mag_float[0]) - sqrt(mag_float[2]))/ (mag_float[0]+ mag_float[1] + mag_float[2]);
    hc05_txPack.mag_speedpid_float=mag_speedpid_float;

		if (hc05_rxPack.speedPID_enabled&&hc05_rxPack.MagPID_enabled) 
		  Mag_PID_realize();
		else{
			MagPID.err=0.0;           
			MagPID.err_last=0.0;       
			MagPID.err_sum=0.0;    
			MagPID.output=0.0; 
		}
}

//float magPID_K(uint8_t mod, float val) {
//    switch (mod) {
//        case 1:
//            return MagPID.Kp += val;
//        case 2:
//            return MagPID.Ki += val;
//        case 3:
//            return MagPID.Kd += val;
//    }
//    return 0;
//}
float getMag(uint8 order){
	return mag_float[order];
}


float getMagKp(void){
	return MagPID.Kp;
}

float getMagKi(void){
	return MagPID.Ki;
}

float getMagKd(void){
	return MagPID.Kd;
}

void modifyMagKp(float val){
  MagPID.Kp += val;
	eeprom_write_word(MagKp_Address ,  (uint32*)&MagPID.Kp);
}

void modifyMagKi(float val){
  MagPID.Ki += val;
	eeprom_write_word(MagKi_Address ,  (uint32*)&MagPID.Ki);
}

void modifyMagKd(float val){
  MagPID.Kd += val;
	eeprom_write_word(MagKd_Address ,  (uint32*)&MagPID.Kd);
}


//void Date_analyse()
//{ 
//    int16  i,max_front=0,max_back; 
//    static int16 max_old = 1,max_crosstalk = 1;
//    static int16 position_last = 2;
//    float  sensor_1;
//    
//    Mag_Read();
//    
    /*********************归一化处理********************/
//    for(i=0;i<3;i++) 
//    {
//       sensor_to_one[i] = (float)AD_valu[i]/(float)MagMax_float[i]; 
//       if(sensor_to_one[i]<=0.0)  sensor_to_one[i]=0.001;
//       if(sensor_to_one[i]>1.0)  sensor_to_one[i]=1.0; 
//       
//       AD[i] = 100 * sensor_to_one[i];     //AD[i]为归一化后的值  范围为0-100
//    }      
//       /*******1号电感特殊归一化，用于坡道检测********/
//     sensor_1 = (float)AD_valu[1]/(float)MagMax_float[1];  
//     if(sensor_1 <= 0.0)  sensor_1 = 0.001;
//     Slope_AD_1 = 100 * sensor_1;
  ////////////////////////////////////////////////////////////////////
    
//      for(i=0;i<3;i++)                 //找出最强的传感器
//      {  
//        if(AD[max_front]<AD[i])
//          max_front=i;
//      } 
//      max_value=AD[max_front]; 
//      
//      max_back = (AD[3]>AD[4])? 3:4;  //找后排最强电感
      
//      if(max_value < 43)            //丢线时最大值取旧值 
//      {
//        max_front=max_old;
//        max_value=AD[max_front]; 
//      }
//      else
//        max_old=max_front;
//      
//      if(abs(max_front - max_crosstalk) < 2)  //防串道
//      {
//           max_crosstalk = max_front;
//      }
//      else 
//           max_front = max_crosstalk;
//      AD_MAX_NUM = max_front;        //传送速度控制
//      
      /****************位置解算************************/
//      if(max_front==0 && (AD[1] <= Position_transit[0] - 1))  //已经偏离0号传感器   
//      {
//            position=0;  
//      }   
//      else if((max_front==0 && (AD[1] > Position_transit[0] + 1)) || (max_front==1 && (AD[0] - AD[2]) > 1))  //左侧位置  0-1号传感器之间
//      {    
//            position=1; 
//            AD_0_max = AD[0];  //记录下此时的0号传感器的值
//      }
//      else if((max_front==1 && (AD[2] - AD[0]) > 1) || (max_front==2 && (AD[1] > Position_transit[1] + 1)))  //右侧位置  1-2号传感器之间
//      {
//            position=2;
//            AD_2_max = AD[2];  //记录下此时的2号传感器的值
//      }
//      else if(max_front==2 && (AD[1] <= Position_transit[1] - 1))  //已经偏离3号传感器    
//      {        
//            position = 3;  
//      }  
      //~~~~~~~~~~~~~~~~~~~~~~~ 后排位置解算~~~~~~~~~~~~~~~~~~~//
//      if(max_back == 3 && AD[4] <= Position_transit[2] - 1)
//      { 
//           if(AD[4] <= Position_transit[2] - 22)
//              position_back = 0;
//           if(AD[4] >= Position_transit[2] - 20)
//              position_back = 1;
//      }
//      else  if(max_back == 3 && AD[4] > Position_transit[2] + 1 || max_back == 4 && AD[3] > Position_transit[3] + 1)
//      {
//           position_back = 2;
//      }
//      else if(max_back == 4 && AD[3] <= Position_transit[3] - 1)
//      {
//           if(AD[3] >= Position_transit[3] - 20)
//              position_back = 3;
//           if(AD[3] <= Position_transit[3] - 22)
//              position_back = 4;
//      }
      
//      if(abs(position - position_last) >= 2)  //位置防跳变
//           position = position_last;
//      position_last = position;
      
     //////弯道内和导线夹角过大导致后面转向不足，此时过渡点强制增大//////////////  
//      if(position == 0 && AD_0_max < 75)
//      {
//          AD_0_max = 75 + abs_f(75 - AD_0_max);    
//      }
//      else if(position == 3 && AD_2_max < 75)
//      {
//          AD_2_max = 75 + abs_f(75 - AD_2_max); 
//      }
//      
      /*************计算偏移量*************/
//      if(position == 0)   //左侧丢线  
//      {
//           chazhi = (int16)((AD[1] - abs_f(AD_0_max-AD[0]) - AD_0_max)*1.3)-25;
//      }
//      else if(position == 1 || position == 2) //处于中间位置
//      {
//               chazhi = (int16)(AD[2] - AD[0]);           
//      }
//      else if(position == 3)  //右侧丢线
//      {
//           chazhi = (int16)((abs_f(AD_2_max-AD[2]) + AD_2_max - AD[1] )*1.5)+30;
//      }
//      if(Stright_Flag)
//      {
//          chazhi = (int16)(((AD[2]-AD[0])-(AD[4]-AD[3])/10)*1.3);  //长直道用斜率控制舵机
//      }
//      if(UPhill_flag)  //上坡时 强制用两侧电感偏移量
//      {
//          chazhi = (int16)((AD[2] - AD[0])); 
//      }   
//}
