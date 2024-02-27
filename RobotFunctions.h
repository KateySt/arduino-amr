#ifndef ROBOT_FUNCTIONS_H
#define ROBOT_FUNCTIONS_H

#include <Servo.h>

void right_shift(int speed_fl_fwd, int speed_rl_bck, int speed_rr_fwd, int speed_fr_bck);
void left_shift(int speed_fl_bck, int speed_rl_fwd, int speed_rr_bck, int speed_fr_fwd);
void go_advance(int speed);
void go_back(int speed);
void left_turn(int speed);
void right_turn(int speed);
void left_back(int speed);
void right_back(int speed);
void clockwise(int speed);
void counterclockwise(int speed);
void FR_fwd(int speed);
void FR_bck(int speed);
void FL_fwd(int speed);
void FL_bck(int speed);
void RR_fwd(int speed);
void RR_bck(int speed);
void RL_fwd(int speed);
void RL_bck(int speed);
void stop_Stop();

#endif 
