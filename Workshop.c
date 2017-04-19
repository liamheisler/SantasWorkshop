/*
  Santa's Workshop program.
  
  TODO:
   -check all pins
   -separate into cogs
*/
#include "simpletools.h"                      // Include simple tools
#include "servo.h" 

//BUTTON PINS
#define marbleToggleID 15
#define trainToggleID 13
#define galleryButtonID 11
#define treeButtonID 9
//#define treeLights 8

//SERVO PINS
#define marbleServo 17
#define trainServo 16
#define galleryElfServo 15 
#define galleryWheelServo 14
#define treeServo 13

//SERVO STEP SIZES
#define treeStepSize 20

//SERVO SPEEDS
#define marbleSpeed 35
#define trainSpeed -35
#define galleryWheelSpeed 20 //needs to be determined via testing

//SERVO ANGLES
#define treeAngleA 0
#define treeAngleB 1800
#define galleryElfAngle 900

int marbleToggle;
int trainToggle;
int galleryInitButton;
int treeButton;
int ducksSwitch;

void handleOperations(int marbleInput, int trainInput, int galleryInput, int treeInput);
void operateMarbleLift(void); 
void operateTrain(void);
void operateGallery(void);
void operateTree(void); 
void systemHalt(void); 
void setMotorSpeeds(void); 

int main()                                    // Main function
{ 
  while(1)
  {
    //setMotorSpeeds(); 
    handleOperations(marbleToggleID, trainToggleID, galleryButtonID, treeButtonID); 
    pause(200); 
    print("%c", CLREOL); 
  }  
}
void handleOperations(int marbleInput, int trainInput, int shooterInput, int treeInput) 
{
  //char state = 'h'; 
  marbleToggle = input(marbleInput);
  trainToggle = input(trainInput);
  galleryInitButton = input(shooterInput);
  treeButton = input(treeInput); 
  ducksSwitch = input(7); 
  
  int total = 0; 
  total = marbleToggle + trainToggle + galleryInitButton + treeButton; 
  
  if(marbleToggle == 1) 
  {
    operateMarbleLift();
    //servo_speed(marbleServo, marbleSpeed); 
  }
  else if(marbleToggle == 0) 
  {
    servo_disable(marbleServo);   
  }
  if(trainToggle == 1) 
  {
    operateTrain();
  }
  else if(trainToggle == 0) 
  {
    servo_disable(trainServo);   
  }
  if(galleryInitButton == 1) 
  {
    operateGallery();
  }
  else if(galleryInitButton == 0) 
  {
    // add more  
  }    
  if(treeButton == 1) 
  {
    operateTree();
  }
  else if(treeButton == 0) 
  {
    servo_disable(treeServo);   
  }
  /*else if(total == 0)
  {
    systemHalt();  
  } */
  print("%cmarble: %d || train: %d || shooter: %d || tree: %d || mSwitch: %d || total: %d\n",  HOME, marbleToggle, trainToggle, galleryInitButton, treeButton, ducksSwitch, total);  
}

//methods handling each system
void operateMarbleLift() 
{
  print("marble method called \n"); 
  servo_speed(marbleServo, 55); 
}
void operateTrain() 
{
  print("train method called \n"); 
  servo_speed(trainServo, trainSpeed); 
}
void operateGallery() 
{
  print("gallery method called \n"); 
  //ducksSwitch = input(gallerySwitch);
  
  servo_angle(galleryElfServo, galleryElfAngle);
  pause(50); 
  servo_speed(galleryWheelServo, galleryWheelSpeed);
   
  if(ducksSwitch == 1) 
  {
    //LIGHT LEDs, PLAY BELL SOUND  
  }
}
//use set ramp functions to handle how slow the tree rotates
void operateTree() 
{
  int pauseTime = 1200; 
  print("tree method called \n"); 
  servo_angle(treeServo, treeAngleA);
  pause(pauseTime); 
  servo_angle(treeServo, treeAngleB); 
  //pause(pauseTime);
}
void systemHalt() 
{
  print("system halted \n");
  servo_disable(marbleServo); 
  servo_disable(trainServo);
  servo_disable(galleryElfServo); 
  servo_disable(galleryWheelServo); 
  servo_disable(treeServo); 
}

void setMotorSpeeds() 
{
  servo_setramp(treeServo, treeStepSize); 
}