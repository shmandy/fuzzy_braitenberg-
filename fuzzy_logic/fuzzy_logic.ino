/*
 * 
 * Braitenberg Vehicle
 * Using Fuzzy Logic
 * Team 8 - Curie
 * 
 */
 
#include "Servo.h"

#define SERIAL;   // Comment to disable serial monitor

// Pin Definitions:
#define servoLeft 9
#define servoRight 10
#define sensorRight 2
#define sensorLeft 1
#define DELAY 1000 // Serial Delay

// Variables:
Servo leftServo;
Servo rightServo;
int leftValue = 0;
int rightValue = 0;
int centerValue = 0;
String sensorString = ""; 


// Setup Loop:
void setup() {
  #ifdef SERIAL
    Serial.begin(9600);
  #endif

  // Configure Servos
  leftServo.attach(servoLeft);
  rightServo.attach(servoRight);
}
 
void loop() {

  // Read Sensors:
  rightValue = analogRead(sensorRight);
  leftValue = analogRead(sensorLeft);

  // Serial Monitoring:
  #ifdef SERIAL
    Serial.println(rightValue);
    Serial.println(leftValue);
    delay(DELAY);
  #endif

  //here is where we will actually write the values to the servos (membership function or debug)
  leftServo.detach();
  rightServo.detach();

}
