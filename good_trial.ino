/*
 * 
 * version 2.1 
 * motor with enable
 * Line follower only.
 * 
*/

int led = 13;
//left motors
int enl = 5;//enable left
int pin6 = 6;//B2
int pin7 = 7;//B1
//right motors
int enr = 10;//enable right
int pin8 = 8;//A2
int pin9 = 9;//A1
//lineFollower
const int Penl = 2;
const int PenC = 3;
const int Penr = 4;
int LS = 0;
int CS = 0;
int RS = 0;
#define l 120
#define r 120

void setup(){
  pinMode(led,OUTPUT);
  //motor
  pinMode(pin6,OUTPUT);
  pinMode(pin7,OUTPUT);
  pinMode(pin8,OUTPUT);
  pinMode(pin9,OUTPUT);
  pinMode(enl,OUTPUT);
  pinMode(enr,OUTPUT);
  //linefollower
  pinMode(Penl, INPUT);
  pinMode(PenC, INPUT);
  pinMode(Penr, INPUT);
  }

// Driving functions
void Stop(){
digitalWrite(led,LOW);
digitalWrite(pin6,LOW);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,LOW);
analogWrite(enr,0);
analogWrite(enl,0);
}

void turn_left(){
digitalWrite(led,HIGH);
digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,LOW);
analogWrite(enr,r);
}
  
void forward(){
digitalWrite(led,HIGH);
digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
analogWrite(pin8,HIGH);
digitalWrite(pin9,LOW);
analogWrite(enr,r);
analogWrite(enl,l);
}

void backward(){ 
digitalWrite(led,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);
digitalWrite(pin9,HIGH);
analogWrite(enr,r);
analogWrite(enl,l);
}

void turn_right(){
digitalWrite(led,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,LOW);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);
analogWrite(enl,l);
}

void loop() {
  int laststate;
  LS = digitalRead(Penl);
  CS = digitalRead(PenC);
  RS = digitalRead(Penr);
  int b = HIGH;
  int w = LOW;
  //forward
  //H-L-H or L-L-L or L-H-L
  if( (LS == w && CS == b && RS == w ) || ( LS == b && CS == b && RS == b ) || ( LS == b && CS == w && RS == b ) ){
      forward();
      laststate=1;
      delay(50);
  }
  
  //right
  //H-H-L or H-L-L
  if( (LS == w && CS == w && RS == b ) || ( LS == w && CS == b && RS == b ) ){
      turn_right();  
      laststate=2;
      delay(50);
  }

  //left
  //L-H-H or L-L-H
  if( (LS == b && CS == w && RS == w ) || ( LS == b && CS == b && RS == w ) ){
      turn_left();
      laststate=0;
      delay(50);
  }
  
   //laststate
  //H-H-H
  if( (LS == w && CS == w && RS == w ) ){
      if(laststate==0)
        turn_right();
       else if (laststate==1)
        backward();
       else if(laststate==2)
        turn_left(); 
        delay(20);
  }
  


}
