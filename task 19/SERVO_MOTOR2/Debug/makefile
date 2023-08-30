################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/6-WDT/subdir.mk
-include MCAL/5-TIMERS/subdir.mk
-include MCAL/3-GI/subdir.mk
-include MCAL/1-DIO/subdir.mk
-include HAL/5-SERVO_MOTOR/subdir.mk
-include HAL/4-STEPPER_MOTOR/subdir.mk
-include HAL/3-DC_Motor/subdir.mk
-include HAL/2-KPD/subdir.mk
-include HAL/1-LCD/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SERVO_MOTOR2.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: SERVO_MOTOR2.elf secondary-outputs

# Tool invocations
SERVO_MOTOR2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SERVO_MOTOR2.map -mmcu=atmega16 -o "SERVO_MOTOR2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SERVO_MOTOR2.lss: SERVO_MOTOR2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SERVO_MOTOR2.elf  >"SERVO_MOTOR2.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SERVO_MOTOR2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 SERVO_MOTOR2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SERVO_MOTOR2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
