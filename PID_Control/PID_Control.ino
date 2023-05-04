#define enM1a 2
#define enM1b 3
#define m1pwm 5
#define m1dir 4

int pos = 0;



long prevT = 0;
float eprev = 0;
float eint = 0;

float kp = 0.9;
float ki = 0;
float kd = 0.1;


void setup() {
  Serial.begin(9600);
  pinMode(m1pwm, OUTPUT);
  pinMode(m1dir, OUTPUT);
  pinMode(enM1a, INPUT);
  pinMode(enM1b, INPUT);
  attachInterrupt(digitalPinToInterrupt(enM1a), encoder, RISING);

}

void loop() {
  int tar = 1000;
  long curT = micros();
  float delT = ((float)(curT-prevT))/1.0e6;
  prevT = curT;

  int e = pos-tar;

  int edev = (e-eprev)/delT;

  int eint = eint+(e*delT);

  float u = kp*e+kd*edev+ki*eint;

  ms(u);

  eprev = e;
  
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
    digitalWrite(m1dir, LOW);
    analogWrite(m1pwm, s1);
    }else{
      digitalWrite(m1dir, HIGH);
      analogWrite(m1pwm, s1);
      }
  }
