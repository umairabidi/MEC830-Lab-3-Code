#include <Stepper.h>

// two button inputs
int Button1 = A3;
int Button2 = A5;

// Stepper motor instance of class Stepper
Stepper stepper(2048, 8, 6, 7, 5);

void setup() {
	stepper.setSpeed(20);
}

void loop() {
	if(!digitalRead(Button1)){
		stepper.step(256);
	}
	if(!digitalRead(Button2)){
		stepper.step(-256);
	}
}
