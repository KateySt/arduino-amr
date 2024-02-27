#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

//libraries
#include <Arduino.h>

// RCT
#define CLK_TIME 14   
#define DAT_TIME 16 
#define RST_TIME 10 

// MOTOR
#define SPEED 140    
#define TURN_SPEED 160    
#define speedPinR 9   
#define RightMotorDirPin1  8   
#define RightMotorDirPin2  9                                 
#define LeftMotorDirPin1  4  
#define LeftMotorDirPin2  5   
#define speedPinL 10 

#define speedPinRB 11   
#define RightMotorDirPin1B  2   
#define RightMotorDirPin2B 3    
#define LeftMotorDirPin1B 6   
#define LeftMotorDirPin2B 7 
#define speedPinLB 12  

// LDR
#define ldrlt 20 //LDR top left - BOTTOM LEFT 
#define ldrrt 21 //LDR top rigt - BOTTOM RIGHT
#define ldrld 19 //LDR down left - TOP LEFT
#define ldrrd 18 //ldr down rigt - TOP RIGHT

#endif // PIN_CONFIG_H
