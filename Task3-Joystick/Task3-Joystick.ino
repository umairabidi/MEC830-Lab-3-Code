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
	Serial.print("X position: ");
	Serial.println(xPos);
	Serial.print("Y position: ");
	Serial.println(yPos);
	
	// Map the x position on the joystick
	// from 0-1023	(ADC read value)
	// to 0-180		(angle)
	// The middle position of the joystick corresponds to
	// the middle of the Servo's rotation (90°)
	servo.write((int)xPos/5.685);