/*
 * 
 * version 1.0
 * digital
 * Line follower only. 
 * 
 * 
*/

int led = 13;
//left motors
int pin6 = 6;//B2
int pin7 = 7;//B1
//right motors
int pin8 = 8;//A2
int pin9 = 9;//A1
//lineFollower
const int PinL = 2;
const int PinC = 3;
const int PinR = 4;
int LS = 0;
int CS = 0;
int RS = 0;


void setup(){
  pinMode(led,OUTPUT);
  //motor
  pinMode(pin6,OUTPUT);
  pinMode(pin7,OUTPUT);
  pinMode(pin8,OUTPUT);
  pinMode(pin9,OUTPUT);
  //linefollower
  pinMode(PinL, INPUT);
  pinMode(PinC, INPUT);
  pinMode(PinR, INPUT);
  }

// Driving functions
void Stop(){
digitalWrite(led,LOW);
digitalWrite(pin6,LOW);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,LOW);
}

void turn_left(){
digitalWrite(led,HIGH);
digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,LOW);
}
  
void forward(){
digitalWrite(led,HIGH);
digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);
}

void backward(){ 
digitalWrite(led,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);
digitalWrite(pin9,HIGH);
}

void turn_right(){
digitalWrite(led,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,LOW);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);
}

void loop() {
  LS = digitalRead(PinL);
  CS = digitalRead(PinC);
  RS = digitalRead(PinR);
  //high means white    
  //low means black
  int b = HIGH;
  int w = LOW;
  //forward
  //H-L-H or L-L-L or L-H-L
  if( (LS == w && CS == b && RS == w ) || ( LS == b && CS == b && RS == b ) || ( LS == b && CS == w && RS == b ) ){
      forward();
      delay(10);
  }
  
  //right
  //H-H-L or H-L-L
  if( (LS == w && CS == w && RS == b ) || ( LS == w && CS == b && RS == b ) ){
      turn_right();  
      delay(10);
  }

  //left
  //L-H-H or L-L-H
  if( (LS == b && CS == w && RS == w ) || ( LS == b && CS == b && RS == w ) ){
      turn_left();
      delay(10);
  }
  
  //stop
  //H-H-H
  if( (LS == w && CS == w && RS == w ) ){
      Stop();
      delay(10);

  }
  
  delay(10);

}
