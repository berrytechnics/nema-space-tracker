# NEMA-17 Space Tracker - Deep Space Object Tracking

- [Amazon Link - Driver](https://www.amazon.com/HiLetgo-Stepstick-Stepper-Printer-Compatible/dp/B07BND65C8/ref=sr_1_1?crid=1R0A486UGMPK8&dib=eyJ2IjoiMSJ9.NwHHTL_v3hVh14BfO0bCFBtrEtOerG4-XUY_qxqS2Af0axsJvgsgq9In2XXvEG5Rygz_oBfqjoVCQkYdAPIuq0AVG0ZvVZOg8RNT7_lwQZI2kyiRrgQjwHf7y6K2STsAbJYUbxVOFHVww5HqGA7e282SLrpbfgTm_wGxdbRHGEfLnotcEQRDqQuVpVWaooHOo0wMP-Sz8QjJi-ZElvB4wGYDogIU-T5L7PTnCii9sy0.UqYMrrWSjyXLGpuTNP7ORSbV57GJZysYoNZSwksDCl4&dib_tag=se&keywords=arduino+micro+stepper&qid=1727897497&sprefix=arduino+micro+stepper%2Caps%2C117&sr=8-1)
- [Amazon Link - Motor](https://www.amazon.com/STEPPERONLINE-Stepper-Bipolar-Connector-compatible/dp/B00PNEQKC0/ref=asc_df_B00PNEQKC0/?tag=hyprod-20&linkCode=df0&hvadid=692875362841&hvpos=&hvnetw=g&hvrand=7684193347413808363&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9026486&hvtargid=pla-2281435179298&psc=1&mcid=4894830c77ae3fceb92f9d529c2183b6&hvocijid=7684193347413808363-B00PNEQKC0-&hvexpln=73)
- [Amazon Link - Arduino](https://www.amazon.com/ELEGOO-Board-ATmega328P-ATMEGA16U2-Compliant/dp/B01EWOE0UU/ref=sr_1_2_sspa?crid=1OE093GDC1BPY&dib=eyJ2IjoiMSJ9.MazmhFfn-DF8W5oyX_S-tH7qkt_WuogERq_8M3-FTf5hnZG5eudwvsegtvpf1bp46PYO290YP4ZNtlydbQ5y7yS0PiBSRREqnP9rbG8V-ZI7_8Rz0jZb_GJirmrCIIMwCHUBEBQmyDixOi8tHo4qAP2rHhB8hlMz14rzQHhSwbKnwClVyPzcVMS3wcdg7pIieFo8tIZJLi2amE4vC_ljD-tph-7HacZTdrEsQR9ds80.8dWMAomkM5djbAGMIiUSPeTiqN9Fi3lWtQF3jUnsy6c&dib_tag=se&keywords=arduino+uno&qid=1727897619&sprefix=arduino+uno%2Caps%2C133&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)

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
