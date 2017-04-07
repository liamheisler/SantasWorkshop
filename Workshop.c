/*
  Santa's Workshop program.
  
  TODO:
   -check all pins (DONE)
   -separate into cogs
   -install buttons on control panel & wire all
   -better method distribution of tasks
*/
#include "simpletools.h"                      // Include simple tools
#include "servo.h" 

//BUTTON PINS
#define marble 15
#define train 13
#define shooter 11
#define tree 9

//SERVO PINS
//FIND BETTER NAMES FOR GALLERY SERVOS ONCE ALL IS ASSEMBLED AND READY FOR TESTING
#define marbleServ 17
#define trainServ 16
#define galleryServA 15 
#define galleryServB 14
#define treeServ 13

//SERVO STEP SIZES
#define treeStepSize 20

//SERVO SPEEDS
#define marbleSpeed 40
#define trainSpeed -35
#define galleryWheelSpeed 20 //needs to be determined via testing

//SERVO ANGLES
#define treeAngleA 0
#define treeAngleB 1800

//MISC VARS
#define pauseTime 1200

int marbleToggle;
int trainToggle;
int galleryButton;
int treeButton;

void handleOperations(int marbleInput, int trainInput, int shooterInput, int treeInput);
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
    handleOperations(marble, train, shooter, tree); 
    pause(200); 
    print("%c", CLREOL); 
  }  
}
void handleOperations(int marbleInput, int trainInput, int shooterInput, int treeInput) 
{
  //char state = 'h'; 
  marbleToggle = input(marbleInput);
  trainToggle = input(trainInput);
  galleryButton = input(shooterInput);
  treeButton = input(treeInput); 
  
  int total = 0; 
  total = marbleToggle + trainToggle + galleryButton + treeButton; 
  
  if(marbleToggle == 1) 
  {
    operateMarbleLift();
    //servo_speed(marbleServ, marbleSpeed); 
  }
  else if(marbleToggle == 0) 
  {
    servo_disable(marbleServ);   
  }
  if(trainToggle == 1) 
  {
    operateTrain();
  }
  else if(trainToggle == 0) 
  {
    servo_disable(trainServ);   
  }
  if(galleryButton == 1) 
  {
    operateGallery();
  }
  else if(galleryButton == 0) 
  {
    // add more  
  }    
  if(treeButton == 1) 
  {
    operateTree();
  }
  else if(treeButton == 0) 
  {
    servo_disable(treeServ);   
  }
  /*else if(total == 0)
  {
    systemHalt();  
  } */
  print("%cmarble: %d || train: %d || shooter: %d || tree: %d || total: %d\n",  HOME, marbleToggle, trainToggle, galleryButton, treeButton, total);  
}

//methods handling each system
void operateMarbleLift() 
{
  print("marble method called \n"); 
  servo_speed(marbleServ, 70); 
}
void operateTrain() 
{
  print("train method called \n"); 
  servo_speed(trainServ, trainSpeed); 
}
void operateGallery() 
{
  print("gallery method called \n"); 
  //need to work out logically
}
//use set ramp functions to handle how slow the tree rotates
void operateTree() 
{ 
  print("tree method called \n"); 
  servo_angle(treeServ, treeAngleA);
  pause(pauseTime); 
  servo_angle(treeServ, treeAngleB); 
  pause(pauseTime);
}
//only use when/if kill switch is installed
//if we're able to, we can use the power button as kill switch and power control
void systemHalt() 
{
  print("system halted \n");
  servo_disable(marbleServ); 
  servo_disable(trainServ);
  servo_disable(galleryServA); 
  servo_disable(galleryServB); 
  servo_disable(treeServ); 
}

void setMotorSpeeds() 
{
  servo_setramp(treeServ, treeStepSize); 
}
