/* mbed Microcontroller Library
 *******************************************************************************
 * Copyright (c) 2014, STMicroelectronics
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */
#ifndef MBED_DEVICE_H
#define MBED_DEVICE_H

///*
#define DEVICE_PORTIN           1
#define DEVICE_PORTOUT          1
#define DEVICE_PORTINOUT        1

#define DEVICE_INTERRUPTIN      1

#define DEVICE_ANALOGIN         1
#define DEVICE_ANALOGOUT        1 

#define DEVICE_SERIAL           1

#define DEVICE_I2C              0
#define DEVICE_I2CSLAVE         0

#define DEVICE_SPI              1
#define DEVICE_SPISLAVE         0

#define DEVICE_RTC              1

#define DEVICE_PWMOUT           1

#define DEVICE_SLEEP            0

//=======================================

#define DEVICE_SEMIHOST         0
#define DEVICE_LOCALFILESYSTEM  0

#define DEVICE_DEBUG_AWARENESS  0

#define DEVICE_STDIO_MESSAGES   0

#define DEVICE_ERROR_RED        0
//*/

#define DEVICE_ID_LENGTH       24

/*
#define ARM_MATH_CM3
//#define __CMSIS_RTOS
//#define COMPONENT_NSPE 1
//#define COMPONENT_PSA_SRV_EMUL 1
//#define COMPONENT_PSA_SRV_IMPL 1
#define __CORTEX_M3
#define DEVICE_ANALOGIN 1
#define DEVICE_CAN 0
#define DEVICE_FLASH 1
#define DEVICE_I2C 0
#define DEVICE_I2C_ASYNCH 0
#define DEVICE_I2CSLAVE 0
#define DEVICE_INTERRUPTIN 1
#define DEVICE_PORTIN 1
#define DEVICE_PORTINOUT 1
#define DEVICE_PORTOUT 1
#define DEVICE_PWMOUT 1
#define DEVICE_RTC 0
#define DEVICE_SERIAL 1
#define DEVICE_SERIAL_ASYNCH 1
#define DEVICE_SERIAL_FC 1
#define DEVICE_SLEEP 0
#define DEVICE_SPI 1
#define DEVICE_SPI_ASYNCH 0
#define DEVICE_SPISLAVE 0
#define DEVICE_STDIO_MESSAGES 0
#define DEVICE_USTICKER 1
#define __MBED__ 1
//#define MBED_BUILD_TIMESTAMP 1571582958.85
//#define __MBED_CMSIS_RTOS_CM
#define MBED_DEBUG
#define MBED_TRAP_ERRORS_ENABLED 1
//#define NDEBUG
#define TARGET_CORTEX
#define TARGET_CORTEX_M
#define TARGET_FAMILY_STM32
#define TARGET_FF_ARDUINO
#define TARGET_FF_MORPHO
#define TARGET_LIKE_CORTEX_M3
#define TARGET_LIKE_MBED
#define TARGET_M3
#define TARGET_NAME NUCLEO_F103RB
#define TARGET_NUCLEO_F103RB
#define TARGET_RELEASE
#define TARGET_STM
#define TARGET_STM32F1
#define TARGET_STM32F103RB
#define TOOLCHAIN_GCC
#define TOOLCHAIN_GCC_ARM
#define TRANSACTION_QUEUE_SIZE_SPI 2
*/

#define TARGET_CORTEX
#define TARGET_CORTEX_M
#define TARGET_FAMILY_STM32
//#define TARGET_FF_ARDUINO
//#define TARGET_FF_MORPHO
#define TARGET_LIKE_CORTEX_M4
#define TARGET_LIKE_MBED
#define TARGET_M4
//#define TARGET_NAME NUCLEO_F103RB

#define TARGET_ARCH_MAX

//#define TARGET_RELEASE
#define TARGET_STM
#define TARGET_STM32F4

//!! from TARGET_STM32F103RB to TARGET_STM32F103RC
#define TARGET_STM32F407VE

#define TOOLCHAIN_GCC
#define TOOLCHAIN_GCC_ARM
#define TRANSACTION_QUEUE_SIZE_SPI 2

#include "objects.h"

#endif
