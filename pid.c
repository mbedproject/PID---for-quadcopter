
#include "pid.h"

PIDdata pitch_pid;
PIDdata roll_pid;
PIDdata yaw_pid;

void pid_init()
{
  pitch_pid.i_error=0;
  pitch_pid.kd = 0.000000;
  pitch_pid.Ki = 0.06;
  pitch_pid.kp = 1.0;
  pitch_pid.MAX = 500;
  pitch_pid.MIN = -500;
  
  roll_pid.i_error=0;
  roll_pid.kd = 0.000000;
  roll_pid.Ki = 0.06;
  roll_pid.kp = 1.0;
  roll_pid.MAX = 500;
  roll_pid.MIN = -500;
  
  yaw_pid.i_error=0.00000;
  yaw_pid.kd = 00.00000;
  yaw_pid.Ki = 00.000;
  yaw_pid.kp = 1.0;
  yaw_pid.MAX = 500;
  yaw_pid.MIN = -500;
  

  
}

float pid_value_loop(float setpoint,float current,float delta_time,PIDdata *s)
{
  float error,p_term,i_term,d_term,out;
  
  //current error
  error = (int)setpoint - (int) current;
  
  //p
  p_term = s->kp * error;
  
  //I
  s->i_error  = error * delta_time + s->i_error;

  i_term = s->Ki *s->i_error;
  
  //D
  d_term =  s->kd *((error - s->last_err_value)/delta_time);

  //save data 
  s->last_err_value = error;
  
  out = (p_term + i_term + d_term);
  
    if( s->MAX < out){
          out=s->MAX;s->i_error=0;
        }
    else if(out<s->MIN){
          out = s->MIN;s->i_error=0;
        }
    
  return out;  
}


