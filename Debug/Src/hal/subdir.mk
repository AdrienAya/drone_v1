################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/hal/hal_adc.c \
../Src/hal/hal_dma.c \
../Src/hal/hal_gpio.c \
../Src/hal/hal_i2c.c \
../Src/hal/hal_i2s.c \
../Src/hal/hal_rcc.c \
../Src/hal/hal_spi.c \
../Src/hal/hal_systick.c \
../Src/hal/hal_tim.c \
../Src/hal/hal_uart.c 

OBJS += \
./Src/hal/hal_adc.o \
./Src/hal/hal_dma.o \
./Src/hal/hal_gpio.o \
./Src/hal/hal_i2c.o \
./Src/hal/hal_i2s.o \
./Src/hal/hal_rcc.o \
./Src/hal/hal_spi.o \
./Src/hal/hal_systick.o \
./Src/hal/hal_tim.o \
./Src/hal/hal_uart.o 

C_DEPS += \
./Src/hal/hal_adc.d \
./Src/hal/hal_dma.d \
./Src/hal/hal_gpio.d \
./Src/hal/hal_i2c.d \
./Src/hal/hal_i2s.d \
./Src/hal/hal_rcc.d \
./Src/hal/hal_spi.d \
./Src/hal/hal_systick.d \
./Src/hal/hal_tim.d \
./Src/hal/hal_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/hal/%.o Src/hal/%.su Src/hal/%.cyclo: ../Src/hal/%.c Src/hal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32H7SINGLE -DSTM32H753ZITx -DSTM32H7 -c -I../Inc -I"C:/Users/balbu/Desktop/STM32CubeIDE_2.0.0/STM32CubeIDE/drivers/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Device/ST/STM32H7xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-hal

clean-Src-2f-hal:
	-$(RM) ./Src/hal/hal_adc.cyclo ./Src/hal/hal_adc.d ./Src/hal/hal_adc.o ./Src/hal/hal_adc.su ./Src/hal/hal_dma.cyclo ./Src/hal/hal_dma.d ./Src/hal/hal_dma.o ./Src/hal/hal_dma.su ./Src/hal/hal_gpio.cyclo ./Src/hal/hal_gpio.d ./Src/hal/hal_gpio.o ./Src/hal/hal_gpio.su ./Src/hal/hal_i2c.cyclo ./Src/hal/hal_i2c.d ./Src/hal/hal_i2c.o ./Src/hal/hal_i2c.su ./Src/hal/hal_i2s.cyclo ./Src/hal/hal_i2s.d ./Src/hal/hal_i2s.o ./Src/hal/hal_i2s.su ./Src/hal/hal_rcc.cyclo ./Src/hal/hal_rcc.d ./Src/hal/hal_rcc.o ./Src/hal/hal_rcc.su ./Src/hal/hal_spi.cyclo ./Src/hal/hal_spi.d ./Src/hal/hal_spi.o ./Src/hal/hal_spi.su ./Src/hal/hal_systick.cyclo ./Src/hal/hal_systick.d ./Src/hal/hal_systick.o ./Src/hal/hal_systick.su ./Src/hal/hal_tim.cyclo ./Src/hal/hal_tim.d ./Src/hal/hal_tim.o ./Src/hal/hal_tim.su ./Src/hal/hal_uart.cyclo ./Src/hal/hal_uart.d ./Src/hal/hal_uart.o ./Src/hal/hal_uart.su

.PHONY: clean-Src-2f-hal

