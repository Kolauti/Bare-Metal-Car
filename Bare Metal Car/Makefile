CC=arm-none-eabi-gcc
MACH=cortex-m3
INCLUDE=include/
LINKER=linker/
SOURCE=source/
STARTUP=startup/
SYSCALLS=syscalls/
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T $(LINKER)stm32_ls.ld -Wl,-Map=final.map
LDFLAGS_SH= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T $(LINKER)stm32_ls.ld -Wl,-Map=final.map

all:main.o usart.o stm32_startup.o syscalls.o final.elf

semi:main.o usart.o stm32_startup.o syscalls.o final_sh.elf

main.o:$(SOURCE)main.c
	$(CC) $(CFLAGS) -o $@ $^ -I$(INCLUDE)

usart.o:$(SOURCE)usart.c
	$(CC) $(CFLAGS) -o $@ $^ -I$(INCLUDE)

stm32_startup.o:$(STARTUP)stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

syscalls.o:$(SYSCALLS)syscalls.c
	$(CC) $(CFLAGS) -o $@ $^
	
final.elf:main.o stm32_startup.o syscalls.o
	$(CC) $(LDFLAGS) -o $@ $^
	
final_sh.elf:$main.o stm32_startup.o
	$(CC) $(LDFLAGS_SH) -o $@ $^

clean:
	rm -rf *.o *.elf

socd:
	openocd -f ./STM32F103C6-OpenOcd.cfg

sgdb:
	arm-none-eabi-gdb
