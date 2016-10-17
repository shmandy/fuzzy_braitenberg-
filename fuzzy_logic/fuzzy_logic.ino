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
#define DELAY 1000 // Serial Delay


// Direction Defintions:
enum DIR
{
  STOP,
  FORWARD,
  BACKWARD_SLOW,
  BACKWARD,
  TURN_RIGHT,
  TURN_LEFT
};


// Init Enum:
DIR currentDirection = STOP;
DIR nextDirection = STOP;


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
  centerValue = analogRead(sensorCenter);
  rightValue = analogRead(sensorRight);
  leftValue = analogRead(sensorLeft);

  // Serial Monitoring:
  #ifdef SERIAL
    sensorString = "Center: " + centerValue;
    Serial.println(sensorString);
    sensorString = "Left: " + leftValue;
    Serial.println(sensorString);
    sensorString = "Right: " + rightValue;
    Serial.println(sensorString);
    delay(DELAY);
  #endif

  // Servo Movement Control:  
  if(nextDirection != STOP) // If Stopped:
  {
    if(!leftServo.attached())
      leftServo.attach(servoLeft);
    if(!rightServo.attached())
      rightServo.attach(servoRight);
  }
  
  // Direction Control
  switch(nextDirection)
  {
      case STOP: // Stop
      {
        leftServo.detach();
        rightServo.detach(); 
      }
      break;

      case FORWARD: // Forward
      {
   
        leftServo.write(140);
        rightServo.write(140);
      }
      break;
      
      case BACKWARD: // Backward Fast
      {
         leftServo.write(0);
         rightServo.write(0);
      }
      break;
      
      case BACKWARD_SLOW: // Backward Slow
      {
         leftServo.write(80);
         rightServo.write(80);
      }
      break;

      case TURN_RIGHT:   // Turn Right
      {
         leftServo.write(140); // Forward
         rightServo.write(80); // Backward
      }
      break;

      case TURN_LEFT: // Turn Left
      {
         rightServo.write(140); // Forward
         leftServo.write(80); // Backward
         
      }
      break;
      
      default: // Stop
      {
        leftServo.detach();
        rightServo.detach();
      }
      break;
  }

  // Simple
  

}
