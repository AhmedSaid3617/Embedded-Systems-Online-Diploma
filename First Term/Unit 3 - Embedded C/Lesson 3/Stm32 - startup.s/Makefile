CC = arm-none-eabi-
CFLAGS = -mcpu=cortex-m3 -gdwarf-2
INCS = -I .
LIBS = 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)

all: learn_in_depth.bin


%.o: %.c
	$(CC)gcc $< -c $(INCS) -o $@ $(CFLAGS)

%.o: %.s
	$(CC)as $< -o $@ $(CFLAGS)

learn_in_depth.elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T linker_script.ld $(AsOBJ) $(OBJ) -o $@ -Map="map_file.map"

learn_in_depth.bin: learn_in_depth.elf
	$(CC)objcopy -O binary $< $@

clean:
	rm *.elf 
	rm *.bin
	rm *.o