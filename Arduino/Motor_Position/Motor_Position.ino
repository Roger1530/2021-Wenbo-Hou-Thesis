

int rotation_value = 100; //value of rotation from local web
//-----------------------position control
#define pin_a  5   //for encoder pulse A
#define pin_b  3   //for encoder pulse B
#define pin_dir  12 //for H-bridge: motor direction
#define pin_pwm  10 //for H-bridge: motor speed
int encoder_r = 0;
int encoder_f = 0;
int position_pv = 0;
int position_sv = 0;
int m_direction = 0;


void setup(){
  //---------declaration for position control
  pinMode(pin_a,INPUT_PULLUP);
  pinMode(pin_b,INPUT_PULLUP);
  pinMode(pin_dir,OUTPUT);
  pinMode(pin_pwm,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(pin_a), detect_a_r, RISING);

  digitalWrite(pin_pwm,0);  //stop motor
  //digitalWrite(pin_bwd,0);  //stop motor
  
  // Serial port for debugging purposes
  Serial.begin(9600);
}
 
void loop(){
  Serial.print("rotation_value ");
  Serial.println(rotation_value);
  
  analogWrite(pin_pwm,100); //set motor speed 
  //position_sv = (1024 - rotation_value)/10; //unit: % (e.g. 0% ~ 0dg; 100% ~ 360dg)
  position_sv = rotation_value; //unit: % (e.g. 0% ~ 0dg; 100% ~ 360dg)
  position_pv = ((encoder_r+encoder_f)/2); //unit: %; encoder pulse per revolution: 200ppr
  Serial.print("Position: ");
  Serial.println(position_pv);
  if(position_pv-position_sv < 0){
      digitalWrite(pin_dir,1);
      //digitalWrite(pin_bwd,0);
    }
    else{
      if(position_pv-position_sv > 0){
        digitalWrite(pin_dir,0);
        //digitalWrite(pin_bwd,1);
      }
      else{
        //stop motor if position between +0 ~ -0
        digitalWrite(pin_pwm,0);  //stop motor
        //digitalWrite(pin_bwd,0);  //stop motor
      }
    }
}

void detect_a_r() 
{
  m_direction = digitalRead(pin_b); //read direction of motor
  if(!m_direction){
    encoder_r += 1;   //increasing encoder at forward run
    Serial.println("++1");
  }
  else{
    encoder_r += -1;  //decreasing encoder at backward run
    Serial.println("+-1");
  }
  attachInterrupt(digitalPinToInterrupt(pin_a), detect_a_f, FALLING); //change interrupt to Falling edge
}

void detect_a_f() 
{
  m_direction = digitalRead(pin_b); //read direction of motor
  if(m_direction){
    encoder_f += 1; //increasing encoder at forward run
    Serial.println("-+1");
  }
  else{
    encoder_f += -1; //decreasing encoder at backward run
    Serial.println("--1");
  }
  attachInterrupt(digitalPinToInterrupt(pin_a), detect_a_r, RISING);  //change interrupt to Rising edge
}
