################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Modules/buttondriver.c \
../Drivers/Modules/leddriver.c 

OBJS += \
./Drivers/Modules/buttondriver.o \
./Drivers/Modules/leddriver.o 

C_DEPS += \
./Drivers/Modules/buttondriver.d \
./Drivers/Modules/leddriver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Modules/%.o Drivers/Modules/%.su: ../Drivers/Modules/%.c Drivers/Modules/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L010xB -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/Modules -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-Modules

clean-Drivers-2f-Modules:
	-$(RM) ./Drivers/Modules/buttondriver.d ./Drivers/Modules/buttondriver.o ./Drivers/Modules/buttondriver.su ./Drivers/Modules/leddriver.d ./Drivers/Modules/leddriver.o ./Drivers/Modules/leddriver.su

.PHONY: clean-Drivers-2f-Modules

