#include <Arduino.h>
#include <TeensyStep.h>

Stepper motor(20, 21);       // STEP pin: 2, DIR pin: 3
StepControl controller;    // Use default settings

void setup()
{
}

void loop()
{
  motor.setTargetRel(1000);  // Set target position to 1000 steps from current position
  controller.move(motor);    // Do the move
  delay(500);
}
