#include "LPC546XX_eeprom.h"
#include "memory.h"
#include "speedPID.h"
#include "mag.h"

void memory_init(void){
  eeprom_init();
  SpeedPID.TargetSpeedL = EEPROM_READ_WORD(float,TargetSpeedL_Address);
  SpeedPID.TargetSpeedR = EEPROM_READ_WORD(float,TargetSpeedR_Address);
  SpeedPID.Kp = EEPROM_READ_WORD(float,SpeedKp_Address);
  SpeedPID.Ki = EEPROM_READ_WORD(float,SpeedKi_Address);
  SpeedPID.Kd = EEPROM_READ_WORD(float,SpeedKd_Address);
  MagPID.Kp = EEPROM_READ_WORD(float,MagKp_Address);
  MagPID.Ki = EEPROM_READ_WORD(float,MagKi_Address);
  MagPID.Kd = EEPROM_READ_WORD(float,MagKd_Address);
  MagMax_float[0] = EEPROM_READ_WORD(float,MagMax0_Address);
  MagMax_float[1] = EEPROM_READ_WORD(float,MagMax1_Address);
  MagMax_float[2] = EEPROM_READ_WORD(float,MagMax2_Address);
}
