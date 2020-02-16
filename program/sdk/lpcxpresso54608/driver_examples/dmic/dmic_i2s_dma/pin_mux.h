/*
 * Copyright 2018 NXP
 * All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define IOCON_PIO_DIGITAL_EN 0x0100u    /*!<@brief Enables digital function */
#define IOCON_PIO_FUNC1 0x01u           /*!<@brief Selects pin function 1 */
#define IOCON_PIO_FUNC2 0x02u           /*!<@brief Selects pin function 2 */
#define IOCON_PIO_FUNC3 0x03u           /*!<@brief Selects pin function 3 */
#define IOCON_PIO_FUNC5 0x05u           /*!<@brief Selects pin function 5 */
#define IOCON_PIO_I2CDRIVE_HIGH 0x0400u /*!<@brief High drive: 20 mA */
#define IOCON_PIO_I2CFILTER_DI 0x0800u  /*!<@brief I2C 50 ns glitch filter disabled */
#define IOCON_PIO_I2CSLEW_I2C 0x00u     /*!<@brief I2C mode */
#define IOCON_PIO_INPFILT_OFF 0x0200u   /*!<@brief Input filter disabled */
#define IOCON_PIO_INPFILT_ON 0x00u      /*!<@brief Input filter enabled */
#define IOCON_PIO_INV_DI 0x00u          /*!<@brief Input function is not inverted */
#define IOCON_PIO_MODE_INACT 0x00u      /*!<@brief No addition pin function */
#define IOCON_PIO_OPENDRAIN_DI 0x00u    /*!<@brief Open drain is disabled */
#define IOCON_PIO_SLEW_FAST 0x0400u     /*!<@brief Fast mode, slew rate control is disabled */
#define IOCON_PIO_SLEW_STANDARD 0x00u   /*!<@brief Standard mode, output slew rate control is enabled */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M4F */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
