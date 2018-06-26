#include "Stepper.h"
#include "bcm2835.h"
#include <unistd.h>

#define STEPS_PER_REVOLUTION 512 //512 steps per revolution

int main()
{
  // Initialize stepper on pins 27, 22, 23, & 24, with the steps per revolution
  Stepper motor(STEPS_PER_REVOLUTION, 27, 22, 23, 24);
  // Set the speed
  motor.setSpeed(20);
  while (1)
  {
    // Step the motor one revolution clockwise
    motor.step(STEPS_PER_REVOLUTION);
	  // Sleep to make moves independent
    usleep(1000000);
    // Step the motor one revolution counterclockwise
    motor.step(-STEPS_PER_REVOLUTION);
	  // Sleep to make moves independent
    usleep(1000000);
  }
}
