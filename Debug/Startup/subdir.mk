################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32h753zitx.s 

OBJS += \
./Startup/startup_stm32h753zitx.o 

S_DEPS += \
./Startup/startup_stm32h753zitx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -I"C:/Users/balbu/Desktop/STM32CubeIDE_2.0.0/STM32CubeIDE/drivers/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Device/ST/STM32H7xx" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32h753zitx.d ./Startup/startup_stm32h753zitx.o

.PHONY: clean-Startup

