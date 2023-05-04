#define enM1a 2
#define enM1b 3

int pos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(enM1a, INPUT);
  pinMode(enM1b, INPUT);
  attachInterrupt(digitalPinToInterrupt(enM1a), encoder, RISING);

}

void loop() {
  Serial.println(pos);
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
