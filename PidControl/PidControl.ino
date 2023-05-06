#define enM1a 2
#define enM1b 3
#define m1pwm 5
#define m1dir 4

int pos = 0;
int p=0;
int i=0;
int d=0;



int error=0;
int preverror=0;




long prevT = 0;
float eprev = 0;
float eint = 0;

float kp = 10;
float ki = 0.001;
float kd = 2;


void setup() {
  Serial.begin(9600);
  pinMode(m1pwm, OUTPUT);
  pinMode(m1dir, OUTPUT);
  pinMode(enM1a, INPUT);
  pinMode(enM1b, INPUT);
  attachInterrupt(digitalPinToInterrupt(enM1a), encoder, RISING);

}

void loop() {
  int tar = 600;
  
  error = tar-pos;
  p=error;
  i=i+error;
  d = error-preverror;

  int pid = kp*p+kd*d+ki*i;
    if(pid>255){
    pid=255;
    }
  if(pid<-255){
    pid=-255;
  }
  ms(pid);
   Serial.print(tar);
  Serial.print(" ");
  Serial.print(pos);
  Serial.println();



}

void encoder(){
  int b = digitalRead(enM1b);
  if(b>0){
    pos++;
    }
    else{
      pos--;
      }
  }

void ms(int s1){
  if(s1<0){
    s1 = -s1;
    digitalWrite(m1dir, HIGH);
    analogWrite(m1pwm, s1);
    }else{
      digitalWrite(m1dir, LOW);
      analogWrite(m1pwm, s1);
      }
  }
