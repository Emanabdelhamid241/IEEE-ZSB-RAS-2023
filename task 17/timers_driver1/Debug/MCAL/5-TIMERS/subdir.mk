################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/5-TIMERS/TIMERS_program.c 

OBJS += \
./MCAL/5-TIMERS/TIMERS_program.o 

C_DEPS += \
./MCAL/5-TIMERS/TIMERS_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/5-TIMERS/%.o: ../MCAL/5-TIMERS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


