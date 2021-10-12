################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Buffahiti_Assignment_4.c \
../source/mtb.c \
../source/pwm.c \
../source/semihost_hardfault.c \
../source/statemachine.c \
../source/switch.c \
../source/systick.c \
../source/touch.c 

OBJS += \
./source/Buffahiti_Assignment_4.o \
./source/mtb.o \
./source/pwm.o \
./source/semihost_hardfault.o \
./source/statemachine.o \
./source/switch.o \
./source/systick.o \
./source/touch.o 

C_DEPS += \
./source/Buffahiti_Assignment_4.d \
./source/mtb.d \
./source/pwm.d \
./source/semihost_hardfault.d \
./source/statemachine.d \
./source/switch.d \
./source/systick.d \
./source/touch.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Buffahiti_Assignment_4\board" -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Buffahiti_Assignment_4\source" -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Buffahiti_Assignment_4" -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Buffahiti_Assignment_4\drivers" -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Buffahiti_Assignment_4\CMSIS" -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Buffahiti_Assignment_4\utilities" -I"C:\Users\hwsin\Documents\MCUXpressoIDE_11.2.0_4120\workspace\Buffahiti_Assignment_4\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

