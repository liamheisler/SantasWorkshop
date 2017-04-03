/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
#include "servo.h"
#include "servodiffdrive.h"

//speeds
#define marbleLiftSpeed 50
#define upOverrideSpeed 70
#define downOverrideSpeed -60
#define trainSpeed -35
#define gallerySpeed 50
#define treeSpeed 50

//servo pins
#define marbleLift_Pin 17
#define train_Pin 12
#define tree_Pin 10 //CHECK 
#define gallery_Pin 9 //CHECK

//button pins
#define upOverrideButton_Pin 15
#define trainButton_Pin 10 //CHECK
#define galleryButton_Pin 6 //CHECK
//#define musicButton_Pin 5 //CHECK

/*
 * TODO:
 *  - add m. switch (gallery)
 *  - check speeds
 *  - check pins
 *  - music & WAV files
 */

int main()                                    // Main function
{
  //declare buttons
  int upOverrideButton;
  int trainButton;
  int galleryButton; 
  int musicButton; 
   
  while(1)
  {
    //init buttons
    upOverrideButton = input(upOverrideButton_Pin);    
    trainButton = input(trainButton_Pin);
    galleryButton = input(trainButton_Pin);
    //musicButton = input(musicButton_Pin); 
     
    // override normal speed, "up"
    if(upOverrideButton == 1) 
    { 
      operateMarbleLiftOvrr();  
    }
    //enable train
    else if(trainButton == 1) 
    {
      operateTrain();  
    }
    else if(galleryButton == 1) 
    {
      operateGallery(); 
    } 
    //run marble lift cont., tree cont. 
    else 
    {
      normalOperations();  
    }
  }  
}

void operateMarbleLiftOvrr() 
{
  servo_speed(marbleLift_Pin, -upOverrideSpeed); 
  servo_disable(train_Pin);
  servo_disable(tree_Pin); 
  servo_disable(gallery_Pin); 
}

void operateTrain() 
{
  servo_speed(train_Pin, trainSpeed); 
  servo_speed(marbleLift_Pin, marbleLiftSpeed); 
  servo_speed(tree_Pin, treeSpeed); 
}

void operateGallery() 
{
  servo_speed(gallery_Pin, gallerySpeed); 
  servo_speed(marbleLift_Pin, marbleLiftSpeed): 
  
  //m. switch
  if(5 == 3)
  {
    //do something
  }
}

void normalOperations() 
{
  servo_speed(marbleLift_Pin, marbleLiftSpeed);
  servo_speed(tree_Pin, treeSpeed); 
}