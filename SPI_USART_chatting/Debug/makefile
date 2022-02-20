################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/USART/subdir.mk
-include MCAL/TIMERS/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/DIO/subdir.mk
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
SPI_USART_chatting.lss \

FLASH_IMAGE += \
SPI_USART_chatting.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: SPI_USART_chatting.elf secondary-outputs

# Tool invocations
SPI_USART_chatting.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SPI_USART_chatting.map -mmcu=atmega32 -o "SPI_USART_chatting.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SPI_USART_chatting.lss: SPI_USART_chatting.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SPI_USART_chatting.elf  >"SPI_USART_chatting.lss"
	@echo 'Finished building: $@'
	@echo ' '

SPI_USART_chatting.hex: SPI_USART_chatting.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SPI_USART_chatting.elf  "SPI_USART_chatting.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SPI_USART_chatting.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SPI_USART_chatting.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SPI_USART_chatting.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
