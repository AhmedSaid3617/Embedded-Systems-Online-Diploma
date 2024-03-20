CC = arm-none-eabi-
CFLAGS = -mcpu=arm926ej-s
INCS = -I .
LIBS = 
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)

all: learn_in_depth.bin


%.o: %.c
	$(CC)gcc $< -c $(INCS) -g -o $@ $(CFLAGS)

%.o: %.s
	$(CC)as $< -o $@ $(CFLAGS)

learn_in_depth.elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T linker_script.ld $(AsOBJ) $(OBJ) -o $@ -Map="map_file.map"

learn_in_depth.bin: learn_in_depth.elf
	$(CC)objcopy -O binary $< $@

clean_all:
	rm *.elf 
	rm *.bin
	rm *.o