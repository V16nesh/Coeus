#define m1pwm 5
#define m1dir 4
#define m2pwm 6
#define m2dir 7

void setup() {
  pinMode(m1pwm, OUTPUT);
  pinMode(m1dir, OUTPUT);
  pinMode(m2pwm, OUTPUT);
  pinMode(m2dir, OUTPUT);

}

void loop() {
  //motor 1: dir 1
  digitalWrite(m1dir, LOW);
  for(int i=0; i<255; i++){
    analogWrite(m1pwm, i);
    delay(50);
    }
  analogWrite(m1pwm, 0);

   //motor 1: dir 2
  digitalWrite(m1dir, HIGH);
  for(int i=0; i<255; i++){
    analogWrite(m1pwm, i);
    delay(50);
    }
  analogWrite(m1pwm, 0);

   //motor 2: dir 1
  digitalWrite(m2dir, LOW);
  for(int i=0; i<255; i++){
    analogWrite(m2pwm, i);
    delay(50);
    }
  analogWrite(m2pwm, 0);

   //motor 2: dir 2
  digitalWrite(m2dir, HIGH);
  for(int i=0; i<255; i++){
    analogWrite(m2pwm, i);
    delay(50);
    }
  analogWrite(m2pwm, 0);
  
  

}
