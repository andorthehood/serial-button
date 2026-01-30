# serial-button

Arduino sketch that sends serial messages when a button is pressed or released.

## Prerequisites

- [arduino-cli](https://docs.arduino.cc/arduino-cli/installation/)

## Behavior

- Sends `DOWN` over serial when button is pressed
- Sends `UP` over serial when button is released
- LED 1 turns on when receiving `LED1ON` via serial
- LED 1 turns off when receiving `LED1OFF` via serial
- LED 2 turns on when receiving `LED2ON` via serial
- LED 2 turns off when receiving `LED2OFF` via serial
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
make led1on            # Send LED1ON command to turn LED 1 on
make led1off           # Send LED1OFF command to turn LED 1 off
make led2on            # Send LED2ON command to turn LED 2 on
make led2off           # Send LED2OFF command to turn LED 2 off
```

## Configuration

Edit `Makefile` variables as needed:

| Variable | Default | Description |
|----------|---------|-------------|
| FQBN | arduino:megaavr:uno2018 | Fully qualified board name |
| PORT | /dev/cu.usbmodem2102 | Serial port |
| CORE | arduino:megaavr | Core to install |
