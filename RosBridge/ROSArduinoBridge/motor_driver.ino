/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE
 
#if defined CytronMdd10A
  

  void initMotorController(){
    pinMode(left_dir, OUTPUT);
    pinMode(left_pwm, OUTPUT);
    pinMode(right_dir, OUTPUT);
    pinMode(right_pwm, OUTPUT);
  }

  void setMotorSpeed(int i, int spd){
    unsigned int x = 0;
    if(spd < 0){
      spd = -spd;
      x = 1;
    }else if(spd > 255){
      spd = 255;
    }

    if(i == LEFT){
      if (x == 0){
        digitalWrite(left_dir, HIGH);
        analogWrite(left_pwm, spd);
      }
      else if (x ==1){
         digitalWrite(left_dir, LOW);
        analogWrite(left_pwm, spd);
      }

    }
    if(i == RIGHT){
      if(x == 0){
        digitalWrite(right_dir, LOW);
        analogWrite(right_pwm, spd);
      }
      else if(x == 1){
        digitalWrite(right_dir, HIGH);
        analogWrite(right_pwm, spd);
      }

    }
  }

  void setMotorSpeeds(int leftSpeed, int rightSpeed){
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }

#else
  #error A motor driver must be selected!
#endif

#endif