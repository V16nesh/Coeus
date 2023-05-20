#ifdef ARDUINO_ENC_COUNTER
  #define LEFT_ENC_PIN_A PA0 
  #define LEFT_ENC_PIN_B PE0  
  #define RIGHT_ENC_PIN_A PF5 
  #define RIGHT_ENC_PIN_B PE1  
#endif
   
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();
