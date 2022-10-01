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
	servo.write(servoPos);
	Serial.begin(9600);
}

void loop(){
	int xPos = analogRead(VRx);
	int yPos = analogRead(VRy);
	
	/*
	Serial.print("X position: ");
	Serial.println(xPos);
	Serial.print("Y position: ");
	Serial.println(yPos);
	*/

	// Servo position control
	// Map the x position on the joystick
	// from 0-1023	(ADC read value)
	// to 0-180		(angle)
	servo.write((int)xPos/5.68);

	// Stepper Motor speed control
	// Linearly ramps up speed with potentiometer reading
	// Dead zone between 502 and 522
	// Min speed is 0
	// Max speed is 15
	if (yPos >= 522){
		stepper.setSpeed((int)15.0/(1023-522)*(yPos-522));
		stepper.step(10);
	}
	else if (yPos <= 502){
		stepper.setSpeed((int)(-15.0/502)*yPos+15);
		stepper.step(-10);
	}
	else {
		stepper.setSpeed(0);
	}
}
