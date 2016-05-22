#ifndef __PID_H
#define __PID_H

#ifdef __cplusplus
 extern "C" {
#endif
 

typedef struct{
				float kp;
	      float kd;
	      float Ki;
  float last_err_value,i_error,MAX,MIN;
}PIDdata;

void pid_init(void);
float pid_value_loop(float setpoint,float current,float delta_time,PIDdata *s);

#ifdef __cplusplus
}
#endif

#endif /* __MISC_H */
