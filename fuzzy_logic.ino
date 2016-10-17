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
#define sensorRight 0
#define sensorLeft 1
#define sensorCenter 2

// Direction Defintions:
enum DIR
{
  STOP,
  FORWARD,
  BACKWORD_SLOW,
  BACKWORD,
  TURN_RIGHT,
  TURN_LEFT
};

// Variables:
Servo leftServo;
Servo rightServo;
int leftValue = 0;
int rightValue = 0;
int centerValue = 0;

DIR currentDirection = STOP;
DIR nextDirection = STOP;

 
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
  centerValue = analogRead(sensorCenter);
  rightValue = analogRead(sensorRight);
  leftValue = analogRead(sensorLeft);

  // Serial Monitoring:
  #ifdef SERIAL
    Serial.println("Center: " + centerValue);
    Serial.println("Left: " + leftValue);
    Serial.println("Right: " + rightValue);
  #endif

  // Servo Movement Control:

  
  
  
  
  
  if(nextDirection != STOP) // If Stopped:
  {
    if(!leftSerevo.attached)
      leftServo.attach(servoLeft);
    if(!rightSerevo.attached)
      rightServo.attach(servoRight);
  }
  
  // Direction Control
  switch(nextDirection)
  {
      case: STOP // Stop
      {
        leftServo.detach();
        rightServo.detach(); 
      }
      break;

      case: FORWARD // Forward
      {
   
        leftServo.write(140);
        rightServo.write(140);
      }

      case: BACKWARD // Backward Fast
      {
         leftServo.write(0);
         rightServo.write(0);
      }
      
      case: BACKWARD_SLOW // Backward Slow
      {
         leftServo.write(80);
         rightServo.write(80);
      }

      case: TURN_RIGHT   // Turn Right
      {
         leftServo.write(140);
         rightServo.detach();
      }

      case: TURN_LEFT // Turn Left
      {
         rightServo.write(140);
         leftServo.detach();
      }
      
      default: // Stop
      {
        leftServo.detach();
        rightServo.detach();
      }
      break;
  }

}
