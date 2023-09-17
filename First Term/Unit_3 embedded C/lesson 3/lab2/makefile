#by mohamed elsheshtawy
CC= arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2 
INCS= -I 
LIBS= 
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)

all: Cortex_M3.bin
	@echo "===build is done==="
	
#startup.o: startup.s 
#	$(CC)as.exe $(CFLAGS) $< -o $@
	
%.o: %.c 
	$(CC)gcc.exe -mthumb $(CFLAGS)  -c $< -o $@

Cortex_M3.elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linkerscript.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map
	
Cortex_M3.bin: Cortex_M3.elf 
	$(CC)objcopy.exe -O binary $< $@
	
clean: 
	rm -rf *.o *~ *.elf *.hex
	@echo "everything is clean"	