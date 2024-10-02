# NEMA-17 Space Tracker - Deep Space Object Tracking

## Overview

This project implements a star tracker for astrophotography using an Arduino, a NEMA 17 stepper motor, and an A4988 stepper motor driver. The system is designed to counteract Earth's rotation, allowing for long-exposure photographs of deep space objects.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno)
- NEMA 17 bipolar stepper motor
  - 59Ncm (83.6oz.in) holding torque
  - 1.65"x1.65"x1.89" 4-wire
  - Rated current: 2.0A
  - Resistance: 1.4ohms
- A4988 Stepper Motor Driver
- Power supply capable of providing at least 2A at 12V
- Appropriate wiring and connectors

## Software Dependencies

- Arduino IDE
- AccelStepper library

## Pin Configuration

| Component | Arduino Pin |
| --------- | ----------- |
| STEP      | 3           |
| DIR       | 2           |
| MS1       | 5           |
| MS2       | 6           |
| MS3       | 7           |
| ENABLE    | 8           |

## Setup Instructions

1. Install the AccelStepper library in your Arduino IDE.
2. Connect the A4988 driver to the Arduino as per the pin configuration table.
3. Connect the NEMA 17 stepper motor to the A4988 driver.
4. Power the A4988 driver with a suitable power supply.
5. Upload the provided code to your Arduino board.

## Code Structure

- `setup()`: Initializes the stepper motor, sets up microstepping, and configures motor speed.
- `loop()`: Continuously runs the motor at the calculated speed for tracking.

## Key Parameters

- `STEP_ANGLE`: The step angle of the motor (default: 1.8 degrees)
- `MICROSTEPS`: Microstepping configuration (default: 16)
- `GEAR_RATIO`: Any additional gearing (default: 1, no additional gearing)
- `EARTH_ROTATION_RATE`: Earth's rotation rate in degrees per hour (15.0)

## Customization

- Adjust `MICROSTEPS` to change the microstepping configuration.
- Modify `GEAR_RATIO` if you're using any external gearing.
- Fine-tune `EARTH_ROTATION_RATE` for more precise tracking if needed.

## Debugging

The code includes optional serial output for debugging. Open the Serial Monitor in the Arduino IDE to view:

- Initialization confirmation
- Steps per revolution
- Steps per hour
- Current position (printed every 10 seconds during operation)

## Safety Considerations

- Ensure proper cooling for the A4988 driver.
- Adjust the current limit on the A4988 to match your motor's specifications.
- Use an appropriate power supply for your motor.

## Future Improvements

- Implement a user interface for real-time speed adjustments.
- Add support for different tracking rates (solar, lunar, etc.).
- Integrate limit switches for safety.
- Implement a "park" position for easy setup and takedown.

## Contributing

Contributions to improve the code or extend its functionality are welcome. Please submit pull requests or open issues on the project repository.

## License

This project is licensed under the MIT License with an additional attribution requirement. See the LICENSE file for details.
Copyright (c) [year] [your name]
Permission is granted to use, copy, modify, and distribute this software for any purpose with or without fee, provided that the above copyright notice and this permission notice appear in all copies, and that clear and visible credit is given to the original author in any use, distribution, or modification of this software.
THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
