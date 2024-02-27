#include <Servo.h> 
#include <RtcDS1302.h>
#include "RobotFunctions.h"
#include "PinConfig.h"

Servo horizontal; // horizontal servo
int servoh = 180; 
int servohLimitHigh = 175;
int servohLimitLow = 5;

// 65 degrees MAX
Servo vertical; // vertical servo
int servov = 45; 
int servovLimitHigh = 100;
int servovLimitLow = 1;

ThreeWire myWire(DAT_TIME, CLK_TIME, RST_TIME);        // DAT, CLK, RST
RtcDS1302<ThreeWire> Rtc(myWire);    // RTC Object
bool isMorning = false;
int currentHour = 0;

void init_GPIO()
{
  horizontal.attach(1);
  vertical.attach(0);
  horizontal.write(180);
  vertical.write(45);  
  
  pinMode(RightMotorDirPin1, OUTPUT); 
  pinMode(RightMotorDirPin2, OUTPUT); 
  pinMode(speedPinL, OUTPUT);  
 
  pinMode(LeftMotorDirPin1, OUTPUT);
  pinMode(LeftMotorDirPin2, OUTPUT); 
  pinMode(speedPinR, OUTPUT);
  pinMode(RightMotorDirPin1B, OUTPUT); 
  pinMode(RightMotorDirPin2B, OUTPUT); 
  pinMode(speedPinLB, OUTPUT);  
 
  pinMode(LeftMotorDirPin1B, OUTPUT);
  pinMode(LeftMotorDirPin2B, OUTPUT); 
  pinMode(speedPinRB, OUTPUT);

  Rtc.Begin();

  RtcDateTime currentTime = RtcDateTime(__DATE__ , __TIME__);
  Rtc.SetDateTime(currentTime);
  currentHour = Rtc.GetDateTime().Hour();
}

void setup()
{
  init_GPIO();
}
void loop(){
currentHour = Rtc.GetDateTime().Hour();
isMorning = (currentHour >= 6 && currentHour < 18);
RtcDateTime now = Rtc.GetDateTime();

int lt = analogRead(ldrlt); // top left
int rt = analogRead(ldrrt); // top right
int ld = analogRead(ldrld); // down left
int rd = analogRead(ldrrd); // down right
int dtime = 10; // dtime=diffirence time
int tol = 90; // tol=toleransi

int avt = (lt + rt) / 2; // average value top
int avd = (ld + rd) / 2; // average value down
int avl = (lt + ld) / 2; // average value left
int avr = (rt + rd) / 2; // average value right

int dvert = avt - avd; // check the diffirence of up and down
int dhoriz = avl - avr;// check the diffirence og left and rigt

// if (isMorning) {
  if (-1*tol > dvert || dvert > tol) 
 {
 if (avt > avd)
 {
 servov = ++servov;
 if (servov > servovLimitHigh)
 {servov = servovLimitHigh;}
 }
 else if (avt < avd)
 {servov= --servov;
 if (servov < servovLimitLow)
 { servov = servovLimitLow;}
 }
 vertical.write(servov);
 }
 
if (-1*tol > dhoriz || dhoriz > tol) // check if the diffirence is in the tolerance else change horizontal angle
 {
 if (avl > avr)
 {
 servoh = --servoh;
 if (servoh < servohLimitLow)
 {
 servoh = servohLimitLow;
 }
 }
 else if (avl < avr)
 {
 servoh = ++servoh;
 if (servoh > servohLimitHigh)
 {
 servoh = servohLimitHigh;
 }
 }
 else if (avl == avr)
 {

 stop_Stop();
 
 delay(5000);
 }
 horizontal.write(servoh);
 }
 
if (avt < avd) {
    go_advance(TURN_SPEED);
  } else if (avl < avr) {
    right_turn(TURN_SPEED);
  } else if (avl > avr) {
    left_turn(TURN_SPEED);
  } else if (avt > avd) {
    go_back(TURN_SPEED);
  } else {
    stop_Stop();
  }
/*} else {
    // Evening behavior
    vertical.write(45); 
    horizontal.write(180);
    stop_Stop();
  }
*/
    
 delay(dtime);
}
