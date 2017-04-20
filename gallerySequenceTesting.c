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
int x = 1; 

void simpleAngle(void);
void testSeq(void);
void resetAngle(void); 

int main()                                    // Main function
{
  //simpleAngle(); 
  //testSeq(); 
  while(x == 1) 
  {
    testSeq();
    //simpleAngle();    
  } 
}

void simpleAngle() 
{
  int pauseTime = 3000;
  servo_angle(12, 900);
  print("at 90 \n"); 
  pause(pauseTime);
  resetAngle();  
  pause(pauseTime);   
}

void testSeq() 
{
  resetWheel(); 
  resetElf(); 
  print("%c%d", HOME, input(9)); 
  if(input(9) == 1)
  {
  int x = 0; 
  //galleryMSwitch = input(galleryMSwitchID);
  print("sequence started \n"); 
  resetWheel(); 
  resetElf();  
  print("at 180 \n");
  pause(2000); 
  servo_angle(12, 900);
  print("at 90 \n"); 
  pause(500); 
  x = 1; 
  
  while(x == 1) 
  {
    servo_speed(14, -20); 
    if(input(7) == 1) 
    {
      servo_disable(14); 
      high(26);
      high(27);  
      pause(1000); 
      servo_speed(14, -10);  
      break;
    }
    //counter++; 
  }
  }
  else
  {
    servo_disable(12);
    servo_disable(14);   
  }    
}
void resetAngle() 
{
  servo_angle(12, 1800); 
  print("at 180 \n");  
}
void checkMSwitch() 
{
  while(1) 
  {
    int mSwitch = input(galleryMSwitchID);   
  }  
}
void resetWheel()
{
  if(input(7) == 1) 
  {
    servo_speed(14, -10);
    pause(100); 
    servo_disable(14);   
  }  
}

void resetElf() 
{
  servo_angle(12, 1800);   
}
