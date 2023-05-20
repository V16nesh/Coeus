#define enM1a 2
#define enM1b 11
#define enM2a 3
#define enM2b 12
#define m1pwm 5
#define m1dir 4
#define m2pwm 6
#define m2dir 7

boolean x = true;

int p1=0;
int i1=0;
int d1=0;

int p2=0;
int i2=0;
int d2=0;

int error1=0;
int preverror1=0;

int error2=0;
int preverror2=0;

float kp1=10;
float kd1=9;
float ki1=0;

float kp2=10;
float kd2=10;
float ki2=0;

int posa = 0;
int posb = 0;

void setup() {
  Serial.begin(9600);
  pinMode(m1pwm, OUTPUT);
  pinMode(m1dir, OUTPUT);
  pinMode(m2pwm, OUTPUT);
  pinMode(m2dir, OUTPUT);
  pinMode(enM2a, INPUT);
  pinMode(enM2b, INPUT);
  pinMode(enM1a, INPUT);
  pinMode(enM1b, INPUT);
  attachInterrupt(digitalPinToInterrupt(enM2a), encoder2, RISING);
  attachInterrupt(digitalPinToInterrupt(enM1a), encoder1, RISING);


}

void loop() {
  while(x){
    for(int i=0; i<200;i++){
      Serial.print(posa);
      Serial.print(" ");
      Serial.println(posb);
      pid(450,450);
    }
 for(int i=0; i<100;i++){
      Serial.print(posa);
      Serial.print(" ");
      Serial.println(posb);
      pid(100,800);
    }
   for(int i=0; i<100;i++){
      Serial.print(posa);
      Serial.print(" ");
      Serial.println(posb);
      pid(450,450);
    }for(int i=0; i<200;i++){
      Serial.print(posa);
      Serial.print(" ");
      Serial.println(posb);
      pid(-450,-450);
    }
    motorspeed(0,0);
    x = false;
  } 
}

void motorspeed(int x, int y){
  if(x<0){
    if(x<-255){
      x =-255;
      }
    x = -x;
    digitalWrite(m1dir, LOW);
    analogWrite(m1pwm, x);
    }else{
      digitalWrite(m1dir, HIGH);
      analogWrite(m1pwm, x);
      }
   if(y<0){
    if(y<-255){
      y =-255;
      }
    y =-y;
    digitalWrite(m2dir, HIGH);
    analogWrite(m2pwm, y);
    }else{
      digitalWrite(m2dir, LOW);
      analogWrite(m2pwm, y);
      }
     
  }

void pid(int u, int v){
  error1 = u-posa;
  p1=error1;
  i1=i1+error1;
  d1 = error1-preverror1;

  error2 = v-posb;
  p2=error2;
  i2=i2+error2;
  d2 = error2-preverror2;

  int pid1 = kp1*p1+kd1*d1+ki1*i1;
    if(pid1>255){
    pid1=255;
    }
  if(pid1<-255){
    pid1=-255;
  }

  int pid2 = kp2*p2+kd2*d2+ki2*i2;
    if(pid2>255){
    pid2=255;
    }
  if(pid2<-255){
    pid2=-255;
  }

  motorspeed(pid1, pid2);
  
  
  }

void encoder2(){
  int b = digitalRead(enM2b);
  if(b>0){
    posb++;
    }
    else{
      posb--;
      }
  }

void encoder1(){
  int a = digitalRead(enM1b);
  if(a>0){
    posa--;
    }
    else{
      posa++;
      }
  }
