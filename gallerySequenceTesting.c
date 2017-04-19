/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "servo.h"

//BUTTON PINS
/*
 * TODO:
 *  -check all pins
 */
#define galleryButtonID 11
#define galleryElfServo 15
#define galleryWheelServo 14
#define galleryMSwitchID 7

#define galleryWheelSpeed -25

int galleryButton;
int galleryMSwitch;
int galleryNewAngle;
int x = 0; 

void simpleAngle(void);
void testSeq(void);
void resetAngle(void); 

int main()                                    // Main function
{
  //simpleAngle(); 
  testSeq(); 
  while(x == 1) 
  {
    testSeq();
    //simpleAngle();    
  } 
}

void simpleAngle() 
{
  int pauseTime = 10000;
  servo_angle(12, 900);
  print("at 90 \n"); 
  pause(pauseTime);
  resetAngle();  
  pause(pauseTime);   
}

void testSeq() 
{
  resetAngle();
  pause(50); 
  servo_angle(12, 900); 
  pause(50); 
  
  servo_speed(galleryWheelServo, galleryWheelSpeed); 
  if(galleryMSwitch == 1) 
  {
    servo_disable(galleryWheelServo); 
    //flash LEDs, play sound  
  }
}
void resetAngle() 
{
  servo_angle(12, 1800); 
  print("at 180 \n");  
}