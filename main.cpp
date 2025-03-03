#include <Arduino.h>

// This is the library for the TB6612 that contains the class Motor and all the
// functions
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <SparkFun_TB6612.h>
#include <DabbleESP32.h>

// Pins for all inputs, keep in mind the PWM defines must be on PWM pins
// the default pins listed are the ones used on the Redbot (ROB-12097) with
// the exception of STBY which the Redbot controls with a physical switch
#define AIN1 16
#define BIN1 5
#define AIN2 4
#define BIN2 18
#define PWMA 2
#define PWMB 19
#define STBY 17
 
// these constants are used to allow you to make your motor configuration 
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
const int offsetB = 1;
 
// Initializing motors.  The library will allow you to initialize as many
// motors as you have memory for.  If you are using functions like forward
// that take 2 motors as arguements you can either write new functions or
// call the function more than once.
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);
 
void setup()
{
 //Nothing here
 Dabble.begin("MyEsp32");  
 Serial.begin(115200);
 Serial.println("Dabble Begin");
}
 
 
void loop()
{
   Dabble.processInput();        
   //Use of the drive function which takes as arguements the speed
   //and optional duration.  A negative speed will cause it to go
   //backwards.  Speed can be from -255 to 255.  Also use of the 
   //brake function which takes no arguements.

   if (GamePad.isUpPressed())         // Di len
  {
    forward(motor1, 255);
    forward(motor2, -255);
    Serial.println("Forward");
    //brake(motor1, motor2);
    Serial.println("stop");
  }

  if (GamePad.isDownPressed())
  {
    back(motor1, -255);
    back(motor2, 255);
    Serial.println("Back");
    //brake(motor1, motor2);
    Serial.println("stop");
  }

  if (GamePad.isLeftPressed())
  {
    left(motor1, motor2, 255);
    Serial.println("Left");
    //brake(motor1, motor2);
    Serial.println("stop");
  }

  if (GamePad.isRightPressed())
  {
    right(motor1, motor2, 255);
    Serial.println("Right");
    //brake(motor1, motor2);
    Serial.println("stop");
  }

  if (GamePad.isSquarePressed())
  {

  }

  if (GamePad.isCirclePressed())
  {

  }

  if (GamePad.isCrossPressed())
  {
    brake(motor1, motor2);
    Serial.println("Brake");
  }

  if (GamePad.isTrianglePressed())
  {

  }

  if (GamePad.isStartPressed())
  {

  }

  if (GamePad.isSelectPressed())
  {

  }

  else 
  {
    brake(motor1, motor2);
  }
   
}

void test(){
   
   
   //Use of the drive function which takes as arguements the speed
   //and optional duration.  A negative speed will cause it to go
   //backwards.  Speed can be from -255 to 255.  Also use of the 
   //brake function which takes no arguements.
   
   //Use of the forward function, which takes as arguements two motors
   //and optionally a speed.  If a negative number is used for speed
   //it will go backwards
   if (GamePad.isUpPressed())
  {
   forward(motor1, 150);
   forward(motor2,-150);
   delay(1000);
  }
   //Use of the back function, which takes as arguments two motors 
   //and optionally a speed.  Either a positive number or a negative
   //number for speed will cause it to go backwards
   if(GamePad.isDownPressed())
   {
   back(motor1, -150);
   back(motor2, 150);
   delay(1000);
   }
   
   //Use of the brake function which takes as arguments two motors.
   //Note that functions do not stop motors on their own.
   if (GamePad.isCrossPressed())
   {
   brake(motor1, motor2);
   delay(1000);
   }

   //Use of the left and right functions which take as arguements two
   //motors and a speed.  This function turns both motors to move in 
   //the appropriate direction.  For turning a single motor use drive.
   if(GamePad.isLeftPressed())
   {
   left(motor1, motor2, 150);
   delay(1000);
   }

   if(GamePad.isRightPressed())
   {
   right(motor1, motor2, 150);
   delay(1000);
   }
   
   //Use of brake again.
   brake(motor1, motor2);
   delay(1000);
}
