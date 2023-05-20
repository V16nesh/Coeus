
#ifdef CytronMdd10A
  #define left_dir 4
  #define left_pwm 5
  #define right_dir 7
  #define right_pwm 6
#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);