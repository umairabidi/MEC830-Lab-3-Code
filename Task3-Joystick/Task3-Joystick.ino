#include <Stepper.h>
#include <Servo.h>


int servoPin = 4;
int Button1 = A3;
int Button2 = A5;
int VRx = A6;
int VRy = A7;

Servo servo;
Stepper stepper(2048, 8, 6, 7, 5);

void setup(){
	servo.attach(servoPin);
	servo.write(90);
	stepper.setSpeed(1);
	pinMode(VRx, INPUT);
	pinMode(VRy, INPUT);
}

void loop(){
	int xPos = analogRead(VRx);
	int yPos = analogRead(VRy);

	// Servo position control
	// Map the x position on the joystick
	// from 0-1023	(ADC read value)
	// to 0-180		(angle)
	servo.write((int)xPos/5.68);
	
	// Stepper Motor speed control
	// Linearly ramps up speed with potentiometer reading
	// Dead zone between 524 and 544
	// Min speed is 1
	// Max speed is 15
	
	if (yPos >= 544){
		stepper.setSpeed((long)(14.0/(1023-544)*(yPos-544)+1));
		stepper.step(10);
	}
	else if (yPos <= 524){
		stepper.setSpeed((long)((-14.0/524)*yPos+15));
		stepper.step(-10);
	}
	
}
