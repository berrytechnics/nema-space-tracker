#include <AccelStepper.h>

   // Motor and driver pins
   const int STEP_PIN = 3;
   const int DIR_PIN = 2;
   const int MS1_PIN = 5;
   const int MS2_PIN = 6;
   const int MS3_PIN = 7;
   const int ENABLE_PIN = 8;

   // Switch pins
   const int NS_SWITCH_PIN = 4;
   const int TARGET_SWITCH_PIN = 9; 

   // Motor specs
   const float STEP_ANGLE = 1.8;  // NEMA 17 motor step angle
   const int MICROSTEPS = 16;     // Set to 16 microsteps for smoother motion
   const float GEAR_RATIO = 1;    // Direct drive, so gear ratio is 1

   // Calculate steps per revolution
   const int STEPS_PER_REVOLUTION = 360 / STEP_ANGLE * MICROSTEPS * GEAR_RATIO;

   // Earth's rotation rate (degrees per hour)
   const float EARTH_ROTATION_RATE = 15.0;

   // Planetary tracking rate adjustment
   const float PLANET_RATE_ADJUSTMENT = 0.083;  // Degrees per hour, varies by planet and date (Jupiter as example)

   // Calculate steps per hour for sidereal and planetary tracking
   const long SIDEREAL_STEPS_PER_HOUR = (long)(EARTH_ROTATION_RATE / (STEP_ANGLE / MICROSTEPS / GEAR_RATIO) * 3600);
   const long PLANETARY_STEPS_PER_HOUR = (long)((EARTH_ROTATION_RATE - PLANET_RATE_ADJUSTMENT) / (STEP_ANGLE / MICROSTEPS / GEAR_RATIO) * 3600);

   // Initialize the stepper motor
   AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

   void setup() {
     // Set up microstepping pins
     pinMode(MS1_PIN, OUTPUT);
     pinMode(MS2_PIN, OUTPUT);
     pinMode(MS3_PIN, OUTPUT);
     pinMode(ENABLE_PIN, OUTPUT);
     
     // Set microstepping to 1/16
     digitalWrite(MS1_PIN, HIGH);
     digitalWrite(MS2_PIN, HIGH);
     digitalWrite(MS3_PIN, HIGH);
     
     // Enable the motor driver
     digitalWrite(ENABLE_PIN, LOW);
     
     // Set initial motor speed (steps per second)
     stepper.setMaxSpeed(SIDEREAL_STEPS_PER_HOUR / 3600.0);
     stepper.setSpeed(SIDEREAL_STEPS_PER_HOUR / 3600.0);
     
     // Optional: Set acceleration for smoother starts and stops
     // Adjust this value as needed for your direct drive setup
     stepper.setAcceleration(50);

     // Set up switch pins
     pinMode(NS_SWITCH_PIN, INPUT_PULLUP);
     pinMode(TARGET_SWITCH_PIN, INPUT_PULLUP);

     Serial.begin(9600);
     Serial.println("Direct Drive Deep Space and Planetary Object Tracker initialized");
     Serial.print("Sidereal steps per hour: ");
     Serial.println(SIDEREAL_STEPS_PER_HOUR);
     Serial.print("Planetary steps per hour: ");
     Serial.println(PLANETARY_STEPS_PER_HOUR);
   }

   void loop() {
     // Check switch states
     bool isNorthernHemisphere = digitalRead(NS_SWITCH_PIN) == HIGH;
     bool isDeepSpaceObject = digitalRead(TARGET_SWITCH_PIN) == HIGH;
     
     // Calculate tracking rate based on target type
     long stepsPerHour = isDeepSpaceObject ? SIDEREAL_STEPS_PER_HOUR : PLANETARY_STEPS_PER_HOUR;
     
     // Set motor speed and direction based on hemisphere and target
     float speed = stepsPerHour / 3600.0;
     if (!isNorthernHemisphere) {
       speed = -speed;  // Reverse direction for Southern Hemisphere
     }
     stepper.setSpeed(speed);

     // Run the motor
     stepper.runSpeed();

     // Optional: Print current status every 10 seconds
     static unsigned long lastPrintTime = 0;
     if (millis() - lastPrintTime > 10000) {
       Serial.print("Position: ");
       Serial.print(stepper.currentPosition());
       Serial.print(" | Hemisphere: ");
       Serial.print(isNorthernHemisphere ? "Northern" : "Southern");
       Serial.print(" | Target: ");
       Serial.println(isDeepSpaceObject ? "Deep Space" : "Planetary");
       lastPrintTime = millis();
     }
   }