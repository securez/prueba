TARGET  = hello
SRCS    = main.c
MCU 	= atmega2561
MCUFREQ = 14745600
FORMAT 	= ihex
OPTIMIZE= -O2
DEFS	= 
LIBS    = 
AVRDUDE_FLAGS 		= -p $(MCU) -P /dev/ttyUSB1 -c avrispv2
AVRDUDE_WRITE_FLASH = -U flash:w:$(TARGET).hex


OBJS    = ${SRCS:.c=.o} 
DEPS    = ${SRCS:.c=.dep} 
XDEPS   = $(wildcard ${DEPS})

CC 		= avr-gcc
OBJCOPY = avr-objcopy
AVRSIZE = avr-size
AVRDUDE = avrdude

override LDFLAGS = -Wl,-Map=$(TARGET).map
override CFLAGS  = -g -Wall $(OPTIMIZE) -mmcu=$(MCU) -DF_CPU=$(MCUFREQ)

.PHONY: all clean distclean 


ifneq (${XDEPS},) 
include ${XDEPS} 
endif

all: $(TARGET).elf $(TARGET).hex

#download: $(TARGET).hex
#    avrdude $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH)
	
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -j .text -j .data -O $(FORMAT) $< $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) --output $@ $(LDFLAGS) $(LIBS)

$(OBJS): %.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@ $(DEFS)

$(DEPS): %.dep: %.c Makefile 
	$(CC) $(CFLAGS) -MM $< > $@
	
clean:
	-rm -f *~ *.o *.dep *.gdb $(TARGET) 

distclean: clean

size:
	avr-size -A $(TARGET).elf
