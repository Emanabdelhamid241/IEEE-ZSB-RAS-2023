################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
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
LCD_Driver22.lss \

FLASH_IMAGE += \
LCD_Driver22.hex \

EEPROM_IMAGE += \
LCD_Driver22.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: LCD_Driver22.elf secondary-outputs

# Tool invocations
LCD_Driver22.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LCD_Driver22.map -mmcu=atmega16 -o "LCD_Driver22.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LCD_Driver22.lss: LCD_Driver22.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LCD_Driver22.elf  >"LCD_Driver22.lss"
	@echo 'Finished building: $@'
	@echo ' '

LCD_Driver22.hex: LCD_Driver22.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LCD_Driver22.elf  "LCD_Driver22.hex"
	@echo 'Finished building: $@'
	@echo ' '

LCD_Driver22.eep: LCD_Driver22.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex LCD_Driver22.elf  "LCD_Driver22.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LCD_Driver22.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 LCD_Driver22.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LCD_Driver22.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
