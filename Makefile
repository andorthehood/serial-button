FQBN = arduino:megaavr:uno2018
PORT = /dev/cu.usbmodem2102
SKETCH = serial-button.ino
CORE = arduino:megaavr

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

# Open serial monitor for testing
monitor:
	arduino-cli monitor -p $(PORT)