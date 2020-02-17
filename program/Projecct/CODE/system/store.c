#include "pid.h"
#include "store.h"
#include "magnet.h"
#include "communication.h"

void store_read(void) {
	com_rxPackage.targetSpeed = EEPROM_READ_WORD(float, TargetSpeed_Address);
	com_rxPackage.speedPID.Kp = EEPROM_READ_WORD(float, SpeedKp_Address);
	com_rxPackage.speedPID.Ki = EEPROM_READ_WORD(float, SpeedKi_Address);
	com_rxPackage.speedPID.Kd = EEPROM_READ_WORD(float, SpeedKd_Address);
	com_rxPackage.steerPID.Kp = EEPROM_READ_WORD(float, SteerKp_Address);
	com_rxPackage.steerPID.Ki = EEPROM_READ_WORD(float, SteerKi_Address);
	com_rxPackage.steerPID.Kd = EEPROM_READ_WORD(float, SteerKd_Address);
	mag_max_f[0] = EEPROM_READ_WORD(float, MagMax0_Address);
	mag_max_f[1] = EEPROM_READ_WORD(float, MagMax1_Address);
	mag_max_f[2] = EEPROM_READ_WORD(float, MagMax2_Address);
}

void store_write(void) {

}
