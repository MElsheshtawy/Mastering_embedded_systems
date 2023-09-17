#by mohamed elsheshtawy
CC= arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g
INCS= -I 
LIBS= 
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)
Project_name = TIVA_C__toggle_led

all: $(Project_name).bin
	@echo "===build is done ya basha==="
	
#startup.o: startup.s 
#	$(CC)as.exe $(CFLAGS) $< -o $@
	
%.o: %.c 
	$(CC)gcc.exe -mthumb $(CFLAGS)  -c $< -o $@

$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linkerscript.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf
	
$(Project_name).bin: $(Project_name).elf 
	$(CC)objcopy.exe -O binary $< $@
	
clean: 
	rm -rf *.o *~ *.elf *.hex
	@echo "Clean ya basha"	