#include <Arduino.h>
#include <TeensyStep.h>
#include <TMC2130Stepper.h>

TMC2130Stepper motor_config(14, 21, 20, 10, 11, 12, 13);
Stepper motor(20, 21);       // STEP pin: 2, DIR pin: 3
StepControl controller;    // Use default settings

uint32_t step = 48, max_speed = step;
int32_t acceleration = max_speed;

void setup() {
    // Configure the driver
    motor_config.begin(); // Initiate pins and registeries
	motor_config.SilentStepStick2130(600); // Set stepper current to 600mA
	motor_config.microsteps(0); // Set microstep to 16
    // motor_config.stealthChop(true);

    // Configure the speed profile
    motor.setMaxSpeed(max_speed);
	motor.setAcceleration(acceleration);

    // Enable the driver
	digitalWrite(14, LOW);

    motor.setTargetRel(step);  // Set target position to 1000 steps from current position
    controller.move(motor);    // Do the move

}

void loop() {

}
