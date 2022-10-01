#include <Servo.h>

Servo servo;
int potentiometer = A0;
int Button1 = A3;
int Button2 = A5;
int servoPin = 4;
int servoPos = 90;

void setup() {
	servo.attach(servoPin);
	servo.write(servoPos);	// initialize at the middle position
}

void loop() {

	if(!digitalRead(Button1)){
		servoPos+=45;
		servo.write(servoPos);
	}
	else if(!digitalRead(Button2)){
		servoPos-=45;
		servo.write(servoPos);
	}
	
	delay(200);	
}
