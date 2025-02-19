################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/I2C_LCD.c \
../Core/Src/autoModeFSM.c \
../Core/Src/button.c \
../Core/Src/displayLCD.c \
../Core/Src/global.c \
../Core/Src/main.c \
../Core/Src/manualModeFSM.c \
../Core/Src/modifyModeFSM.c \
../Core/Src/scheduler.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/trafficLight.c 

OBJS += \
./Core/Src/I2C_LCD.o \
./Core/Src/autoModeFSM.o \
./Core/Src/button.o \
./Core/Src/displayLCD.o \
./Core/Src/global.o \
./Core/Src/main.o \
./Core/Src/manualModeFSM.o \
./Core/Src/modifyModeFSM.o \
./Core/Src/scheduler.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/trafficLight.o 

C_DEPS += \
./Core/Src/I2C_LCD.d \
./Core/Src/autoModeFSM.d \
./Core/Src/button.d \
./Core/Src/displayLCD.d \
./Core/Src/global.d \
./Core/Src/main.d \
./Core/Src/manualModeFSM.d \
./Core/Src/modifyModeFSM.d \
./Core/Src/scheduler.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/trafficLight.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/I2C_LCD.cyclo ./Core/Src/I2C_LCD.d ./Core/Src/I2C_LCD.o ./Core/Src/I2C_LCD.su ./Core/Src/autoModeFSM.cyclo ./Core/Src/autoModeFSM.d ./Core/Src/autoModeFSM.o ./Core/Src/autoModeFSM.su ./Core/Src/button.cyclo ./Core/Src/button.d ./Core/Src/button.o ./Core/Src/button.su ./Core/Src/displayLCD.cyclo ./Core/Src/displayLCD.d ./Core/Src/displayLCD.o ./Core/Src/displayLCD.su ./Core/Src/global.cyclo ./Core/Src/global.d ./Core/Src/global.o ./Core/Src/global.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/manualModeFSM.cyclo ./Core/Src/manualModeFSM.d ./Core/Src/manualModeFSM.o ./Core/Src/manualModeFSM.su ./Core/Src/modifyModeFSM.cyclo ./Core/Src/modifyModeFSM.d ./Core/Src/modifyModeFSM.o ./Core/Src/modifyModeFSM.su ./Core/Src/scheduler.cyclo ./Core/Src/scheduler.d ./Core/Src/scheduler.o ./Core/Src/scheduler.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/trafficLight.cyclo ./Core/Src/trafficLight.d ./Core/Src/trafficLight.o ./Core/Src/trafficLight.su

.PHONY: clean-Core-2f-Src

