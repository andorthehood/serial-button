# FQBN = arduino:megaavr:uno2018
FQBN = arduino:avr:nano
# PORT = /dev/cu.usbmodem2102
PORT = /dev/cu.usbserial-AB0JQKVM
# CORE = arduino:megaavr
CORE = arduino:avr

SKETCH = serial-button.ino

# Compile and upload sketch to the board
build_and_upload:
	arduino-cli compile --fqbn $(FQBN) $(SKETCH)
	arduino-cli upload -p $(PORT) --fqbn $(FQBN) $(SKETCH)

# List connected Arduino boards
list:
	arduino-cli board list

# Install Arduino core tools for the target board
install:
	arduino-cli core install $(CORE)

# Open serial monitor for testing (run in separate terminal)
monitor:
	screen -S arduino $(PORT) 9600

# Send LED1ON command to turn LED 1 on (requires monitor running)
led1on:
	screen -S arduino -X stuff $$'LED1ON\r'

# Send LED1OFF command to turn LED 1 off (requires monitor running)
led1off:
	screen -S arduino -X stuff $$'LED1OFF\r'

# Send LED2ON command to turn LED 2 on (requires monitor running)
led2on:
	screen -S arduino -X stuff $$'LED2ON\r'

# Send LED2OFF command to turn LED 2 off (requires monitor running)
led2off:
	screen -S arduino -X stuff $$'LED2OFF\r'
