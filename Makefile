SHELL      := /bin/bash
FQBN       := esp32:esp32:esp32
BUILD_PATH := ./build
SRCINO     := PiezoPiano.ino
HEADERS    := Pitches.h
ELF        := $(BUILD_PATH)/$(SRCINO).elf
SERIAL_DEV := /dev/ttyUSB0
BAUD_RATE  := 115200

all: $(ELF)

$(ELF): $(SRCINO) $(HEADERS)
	arduino-cli compile --verbose --build-path $(BUILD_PATH) -b $(FQBN) -p $(SERIAL_DEV) .

upload: $(ELF)
	arduino-cli upload --verbose -b $(FQBN) -p $(SERIAL_DEV) --input-dir $(BUILD_PATH)

clean:
	rm -vfr $(BUILD_PATH)/* IndexHtml.h

monitor:
	minicom --device=$(SERIAL_DEV) --baudrate=$(BAUD_RATE)
