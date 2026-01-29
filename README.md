# serial-button

Arduino sketch that sends serial messages when a button is pressed or released.

## Prerequisites

- [arduino-cli](https://docs.arduino.cc/arduino-cli/installation/)

## Behavior

- Sends `DOWN` over serial when button is pressed
- Sends `UP` over serial when button is released
- Built-in LED turns on when receiving `ON` via serial
- Built-in LED turns off when receiving `OFF` via serial
- Includes 50ms debounce

## Wiring

- Button one side -> Pin 2
- Button other side -> GND

Uses internal pull-up resistor, no external resistor needed.

## Makefile targets

```bash
make install           # Install Arduino core tools
make build_and_upload  # Compile and upload to board
make list              # List connected boards
make monitor           # Open serial monitor for testing
make on                # Send ON command to turn LED on
make off               # Send OFF command to turn LED off
```

## Configuration

Edit `Makefile` variables as needed:

| Variable | Default | Description |
|----------|---------|-------------|
| FQBN | arduino:megaavr:uno2018 | Fully qualified board name |
| PORT | /dev/cu.usbmodem2102 | Serial port |
| CORE | arduino:megaavr | Core to install |