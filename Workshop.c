/*
  Santa's Workshop program.
  
  TODO:
   -check all pins
   -separate into cogs
*/
#include "simpletools.h"                      // Include simple tools
#include "servo.h" 

//BUTTON PINS
#define marble 9
#define train 11
#define shooter 13
#define tree 15

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
#define marbleSpeed 50
#define trainSpeed -35
#define galleryWheelSpeed 20 //needs to be determined via testing

//SERVO ANGLES
#define treeAngleA 0
#define treeAngleB 1800

int marbleToggle;
int trainToggle;
int shooterButton;
int treeButton;
String state;  

int main()                                    // Main function
{ 
  state = ""; 
  while(1)
  {
    checkInputs(marble, train, shooter, tree); 
    
    if(checkInputs() == 1)
    {
      operateMabrleLift();    
      state = "marbleLift";    
    }
    if(checkInputs() == 2) 
    {
      operateTrain(); 
      state = "train"; 
    }
    if(checkInputs() == 3) 
    {
      operateGallery(); 
      state = "gallery";
    }
    if(checkInputs() == 4)
    {
      operateTree(); 
      state = "tree"; 
    }
    if(checkInputs() == 5) 
    {
      systemHalt();   
      state = "halted"; 
    }
    
    print("marble: %d || train: %d || shooter: %d || tree: %d || state: %s \n",  marbleToggle, trainToggle, shooterButton, treeButton, state); 
    pause(100); 
  }  
}

int checkInputs(int marbleInput, int trainInput, int shooterInput, int treeInput) 
{
  marbleToggle = input(marbleInput);
  trainToggle = input(trainInput);
  shooterButton = input(shooterInput);
  treeButton = input(treeInput); 
  
  if(marbleToggle == 1) 
  {
    return 1; 
  }
  if(trainToggle == 1) 
  {
    return 2; 
  }
  if(shooterButton == 1) 
  {
    return 3; 
  }
  if(tree == 1) 
  {
    return 4;   
  }
  else 
  {
    return 5;   
  }
}

//methods handling each system
void operateMarbleLift() 
{
  servo_speed(marbleServ, marbleSpeed); 
}
void operateTrain() 
{
  servo_speed(trainServ, trainSpeed); 
}
void operateGallery() 
{
  //need to work out logically
}
//use set ramp functions to handle how slow the tree rotates
void operateTree() 
{
  servo_setramp(treeServ, treeStepSize); 
  
  servo_angle(treeServ, treeAngleA);
  pause(300); 
  servo_angle(treeServ, treeAngleB); 
  pause(300); 
}
void systemHalt() 
{
  servo_disable(marbleServ); 
  servo_disable(trainServ);
  servo_disable(galleryServA); 
  servo_disable(galleryServB); 
  servo_disable(treeServ); 
}
