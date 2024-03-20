CC = arm-none-eabi-
CFLAGS = -mcpu=arm926ej-s
INCS = -I .

all: learn_in_depth.bin


app.o: app.c
	$(CC)gcc $< -c $(INCS) -g -o $@ $(CFLAGS)

uart.o: uart.c
	$(CC)gcc $< -c $(INCS) -g -o $@ $(CFLAGS)

startup.o: startup.s
	$(CC)as $< -o $@ $(CFLAGS)

learn_in_depth.elf: startup.o app.o uart.o
	$(CC)ld -T linker_script.ld startup.o app.o uart.o -o $@ -Map="map_file.map"

learn_in_depth.bin: learn_in_depth.elf
	$(CC)objcopy -O binary $< $@

clean_all:
	rm *.elf 
	rm *.bin
	rm *.o