################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/3-DC_Motor/DC_MOTOR_program.c 

OBJS += \
./HAL/3-DC_Motor/DC_MOTOR_program.o 

C_DEPS += \
./HAL/3-DC_Motor/DC_MOTOR_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/3-DC_Motor/%.o: ../HAL/3-DC_Motor/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


