/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v5.0
processor: LPC54608J512
package_id: LPC54608J512ET180
mcu_data: ksdk2_0
processor_version: 0.0.24
board: LPCXpresso54608
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: D6, peripheral: FLEXCOMM3, signal: SCK, pin_signal: PIO0_0/CAN1_RD/FC3_SCK/CTIMER0_MAT0/SCT0_GPI0/PDM0_CLK}
  - {pin_num: E9, peripheral: FLEXCOMM3, signal: TXD_SCL_MISO, pin_signal: PIO0_2/FC3_TXD_SCL_MISO/CTIMER0_CAP1/SCT0_OUT0/SCT0_GPI2/EMC_D(0)}
  - {pin_num: A10, peripheral: FLEXCOMM3, signal: RXD_SDA_MOSI, pin_signal: PIO0_3/FC3_RXD_SDA_MOSI/CTIMER0_MAT1/SCT0_OUT1/SCT0_GPI3/EMC_D(1)}
  - {pin_num: B13, peripheral: FLEXCOMM0, signal: RXD_SDA_MOSI, pin_signal: PIO0_29/FC0_RXD_SDA_MOSI/CTIMER2_MAT3/SCT0_OUT8/TRACEDATA(2)}
  - {pin_num: A2, peripheral: FLEXCOMM0, signal: TXD_SCL_MISO, pin_signal: PIO0_30/FC0_TXD_SCL_MISO/CTIMER0_MAT0/SCT0_OUT9/TRACEDATA(1)}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M4F */
void BOARD_InitPins(void)
{
    /* Enables the clock for the IOCON block. 0 = Disable; 1 = Enable.: 0x01u */
    CLOCK_EnableClock(kCLOCK_Iocon);

    IOCON->PIO[0][0] = ((IOCON->PIO[0][0] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT00 (pin D6) is configured as FC3_SCK. */
                        | IOCON_PIO_FUNC(PIO00_FUNC_ALT2)

                        /* Select Analog/Digital mode.
                         * : Digital mode. */
                        | IOCON_PIO_DIGIMODE(PIO00_DIGIMODE_DIGITAL));

    IOCON->PIO[0][2] = ((IOCON->PIO[0][2] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT02 (pin E9) is configured as FC3_TXD_SCL_MISO. */
                        | IOCON_PIO_FUNC(PIO02_FUNC_ALT1)

                        /* Select Analog/Digital mode.
                         * : Digital mode. */
                        | IOCON_PIO_DIGIMODE(PIO02_DIGIMODE_DIGITAL));

    IOCON->PIO[0][29] = ((IOCON->PIO[0][29] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT029 (pin B13) is configured as FC0_RXD_SDA_MOSI. */
                         | IOCON_PIO_FUNC(PIO029_FUNC_ALT1)

                         /* Select Analog/Digital mode.
                          * : Digital mode. */
                         | IOCON_PIO_DIGIMODE(PIO029_DIGIMODE_DIGITAL));

    IOCON->PIO[0][3] = ((IOCON->PIO[0][3] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT03 (pin A10) is configured as FC3_RXD_SDA_MOSI. */
                        | IOCON_PIO_FUNC(PIO03_FUNC_ALT1)

                        /* Select Analog/Digital mode.
                         * : Digital mode. */
                        | IOCON_PIO_DIGIMODE(PIO03_DIGIMODE_DIGITAL));

    IOCON->PIO[0][30] = ((IOCON->PIO[0][30] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT030 (pin A2) is configured as FC0_TXD_SCL_MISO. */
                         | IOCON_PIO_FUNC(PIO030_FUNC_ALT1)

                         /* Select Analog/Digital mode.
                          * : Digital mode. */
                         | IOCON_PIO_DIGIMODE(PIO030_DIGIMODE_DIGITAL));
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
