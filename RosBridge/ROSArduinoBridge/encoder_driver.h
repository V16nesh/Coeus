#ifdef ARDUINO_ENC_COUNTER
  #define LEFT_ENC_PIN_A PD2
  #define LEFT_ENC_PIN_B PD3  
  #define RIGHT_ENC_PIN_A PC4 
  #define RIGHT_ENC_PIN_B PC5  
#endif
   
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();
