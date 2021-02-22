#define pwm 10
#define dir 12

  

void setup() {
  // put your setup code here, to run once:
pinMode(pwm,OUTPUT);
pinMode(dir,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dir,LOW);
  digitalWrite(pwm,0);
}
