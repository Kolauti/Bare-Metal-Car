CC=arm-none-eabi-gcc
MACH=cortex-m3
INCLUDE=include/
LINKER=linker/
SOURCE=source/
STARTUP=startup/
SYSCALLS=syscalls/
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T $(LINKER)stm32_ls.ld -Wl,-Map=final.map

all:main.o usart.o carMotorCtrl.o exti.o stm32_startup.o syscalls.o final.elf

main.o:$(SOURCE)main.c
	$(CC) $(CFLAGS) -o $@ $^ -I$(INCLUDE)

usart.o:$(SOURCE)usart.c
	$(CC) $(CFLAGS) -o $@ $^ -I$(INCLUDE)

carMotorCtrl.o:$(SOURCE)carMotorCtrl.c
	$(CC) $(CFLAGS) -o $@ $^ -I$(INCLUDE)

exti.o:$(SOURCE)exti.c
	$(CC) $(CFLAGS) -o $@ $^ -I$(INCLUDE)

stm32_startup.o:$(STARTUP)stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

syscalls.o:$(SYSCALLS)syscalls.c
	$(CC) $(CFLAGS) -o $@ $^
	
final.elf:main.o usart.o carMotorCtrl.o exti.o stm32_startup.o syscalls.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -rf *.o *.elf

socd:
	openocd -f ./STM32F103C6-OpenOcd.cfg

sgdb:
	arm-none-eabi-gdb
