/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
    kPIN_MUX_DirectionInput = 0U,        /* Input direction */
    kPIN_MUX_DirectionOutput = 1U,       /* Output direction */
    kPIN_MUX_DirectionInputOrOutput = 2U /* Input or output direction */
} pin_mux_direction_t;

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

#define PIO00_DIGIMODE_DIGITAL 0x01u  /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO00_FUNC_ALT2 0x02u         /*!<@brief Selects pin function.: Alternative connection 2. */
#define PIO029_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO029_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO02_DIGIMODE_DIGITAL 0x01u  /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO02_FUNC_ALT1 0x01u         /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO030_DIGIMODE_DIGITAL 0x01u /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO030_FUNC_ALT1 0x01u        /*!<@brief Selects pin function.: Alternative connection 1. */
#define PIO03_DIGIMODE_DIGITAL 0x01u  /*!<@brief Select Analog/Digital mode.: Digital mode. */
#define PIO03_FUNC_ALT1 0x01u         /*!<@brief Selects pin function.: Alternative connection 1. */

/*! @name FC3_SCK (coord D6), U26[13]/J14[4]/P0_0-ISP_FC3_SCK
  @{ */
#define BOARD_ISP_FC3_SCK_PERIPHERAL FLEXCOMM3                    /*!<@brief Device name: FLEXCOMM3 */
#define BOARD_ISP_FC3_SCK_SIGNAL SCK                              /*!<@brief FLEXCOMM3 signal: SCK */
#define BOARD_ISP_FC3_SCK_PIN_NAME FC3_SCK                        /*!<@brief Pin name */
#define BOARD_ISP_FC3_SCK_LABEL "U26[13]/J14[4]/P0_0-ISP_FC3_SCK" /*!<@brief Label */
#define BOARD_ISP_FC3_SCK_NAME "ISP_FC3_SCK"                      /*!<@brief Identifier name */
                                                                  /* @} */

/*! @name FC0_RXD_SDA_MOSI (coord B13), U24[13]/P0_29-ISP_FC0_RXD
  @{ */
#define BOARD_ISP_FC0_RXD_PERIPHERAL FLEXCOMM0              /*!<@brief Device name: FLEXCOMM0 */
#define BOARD_ISP_FC0_RXD_SIGNAL RXD_SDA_MOSI               /*!<@brief FLEXCOMM0 signal: RXD_SDA_MOSI */
#define BOARD_ISP_FC0_RXD_PIN_NAME FC0_RXD_SDA_MOSI         /*!<@brief Pin name */
#define BOARD_ISP_FC0_RXD_LABEL "U24[13]/P0_29-ISP_FC0_RXD" /*!<@brief Label */
#define BOARD_ISP_FC0_RXD_NAME "ISP_FC0_RXD"                /*!<@brief Identifier name */
                                                            /* @} */

/*! @name FC0_TXD_SCL_MISO (coord A2), U24[12]/P0_30-ISP_FC0_TXD
  @{ */
#define BOARD_ISP_FC0_TXD_PERIPHERAL FLEXCOMM0              /*!<@brief Device name: FLEXCOMM0 */
#define BOARD_ISP_FC0_TXD_SIGNAL TXD_SCL_MISO               /*!<@brief FLEXCOMM0 signal: TXD_SCL_MISO */
#define BOARD_ISP_FC0_TXD_PIN_NAME FC0_TXD_SCL_MISO         /*!<@brief Pin name */
#define BOARD_ISP_FC0_TXD_LABEL "U24[12]/P0_30-ISP_FC0_TXD" /*!<@brief Label */
#define BOARD_ISP_FC0_TXD_NAME "ISP_FC0_TXD"                /*!<@brief Identifier name */
                                                            /* @} */

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
