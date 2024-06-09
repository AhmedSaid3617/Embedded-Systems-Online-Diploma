CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m4 -gdwarf-2 -g -O0
INCS = -I .
LIBS = 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
PROJECT_NAME = tiva_c_blink

all: $(PROJECT_NAME).bin


%.o: %.c
	$(CC)gcc $< -c $(INCS) -o $@ $(CFLAGS)

%.o: %.s
	$(CC)as $< -o $@ $(CFLAGS)

$(PROJECT_NAME).elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T linker_script.ld $(AsOBJ) $(OBJ) -o $@ -Map="map_file.map"
	cp $(PROJECT_NAME).elf $(PROJECT_NAME).axf

$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy -O binary $< $@

clean:
	rm *.elf 
	rm *.bin
	rm *.o