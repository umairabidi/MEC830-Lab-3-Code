#include <Stepper.h>
#define STEPS 2048

Stepper stepper(STEPS, 8, 7, 6, 5);

int potentiometer = A0;
int Button1 = A3;
int Button2 = A5;

int previous = 0;

void setup() {
	stepper.setSpeed(300);
}

void loop() {
	int val = analogRead(potentiometer);
	stepper.step(val - previous);
	previous = val;
}