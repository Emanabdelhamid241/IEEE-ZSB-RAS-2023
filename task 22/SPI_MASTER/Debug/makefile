################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/8-SPI/subdir.mk
-include MCAL/7-UART/subdir.mk
-include MCAL/1-DIO/subdir.mk
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
SPI_MASTER.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: SPI_MASTER.elf secondary-outputs

# Tool invocations
SPI_MASTER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SPI_MASTER.map -mmcu=atmega16 -o "SPI_MASTER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SPI_MASTER.lss: SPI_MASTER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SPI_MASTER.elf  >"SPI_MASTER.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SPI_MASTER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 SPI_MASTER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SPI_MASTER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
