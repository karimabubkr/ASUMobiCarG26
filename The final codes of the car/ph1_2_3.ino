//left motors
int enl = 5;//enable left
int pin6 = 6;//B2
int pin7 = 7;//B1
//right motors
int enr = 10;//enable left
int pin8 = 8;//A2
int pin9 = 9;//A1

//ultrasonic
int trig_pin = A0;
int echo_pin = A1;
long echotime;
float distance;

//lineFollower
const int PinL = 11;
const int PinC = 12;
const int PinR = 13;
int LS = 0;
int CS = 0;
int RS = 0;

//bluetooth 
char BluetoothData;

void setup(){
  //motor
  pinMode(pin6,OUTPUT);
  pinMode(pin7,OUTPUT);
  pinMode(pin8,OUTPUT);
  pinMode(pin9,OUTPUT);
  pinMode(enl,OUTPUT);
  pinMode(enr,OUTPUT);

  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  digitalWrite(trig_pin,LOW);

  //linefollower
  pinMode(PinL, INPUT);
  pinMode(PinC, INPUT);
  pinMode(PinR, INPUT);
  digitalWrite(enl,HIGH);
  digitalWrite(enr,HIGH);

  //bluetooth
  Serial.begin(9600);
  }
// Driving functions
void Stop(){
digitalWrite(pin6,LOW);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,LOW);
}

void turn_right(){
digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,LOW);
}
  
void forward(){
digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);
}

void backward(){ 
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);
digitalWrite(pin9,HIGH);
}

void turn_left(){
digitalWrite(pin6,LOW);
digitalWrite(pin7,LOW);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);
}

//line follower fuction
void follow_line(){  
  BluetoothData = Serial.read();
  while(1){
    BluetoothData = Serial.read();
    if(BluetoothData=='w'){
     break;
      }

  
    int laststate;
    LS = digitalRead(PinL);
    CS = digitalRead(PinC);
    RS = digitalRead(PinR);
    //high means white    
    //low means black
    int b = HIGH;
    int w = LOW;
 
    //forward
    //bwb or bbb or wbw
    if( (LS == w && CS == b && RS == w ) || ( LS == b && CS == b && RS == b ) || ( LS == b && CS == w && RS == b ) ){
      if(BluetoothData=='w'){
     break;
      }
        Stop();
        delay(40);
        forward();
        delay(15);
        laststate=1;
    }
    
    //right
    //wwb or wbb
    if( (LS == w && CS == w && RS == b ) || ( LS == w && CS == b && RS == b ) ){
      if(BluetoothData=='w'){
     break;
      }
        Stop();
        delay(40);
        turn_left();  
        delay(15);
        laststate=2;
    }
    
    //left
    //bww or bbw
    if( (LS == b && CS == w && RS == w ) || ( LS == b && CS == b && RS == w ) ){
      if(BluetoothData=='w'){
     break;
      }
        Stop();
        delay(40);
        turn_right();
        delay(15);
        laststate=0;
    }  
    //laststate
    //www
    if( (LS == w && CS == w && RS == w ) ){
      if(BluetoothData=='w'){
     break;
      }
        if(laststate==2){
           if(BluetoothData=='w'){
     break;
      }
          Stop();
          delay(40);
          turn_left();      
          delay(15);
          }       
        else if (laststate==1){
           if(BluetoothData=='w'){
     break;
      }
          Stop();
          delay(40);
          forward();      
          delay(15);
          } 
        else if(laststate==0){
           if(BluetoothData=='w'){
     break;
      }
          Stop();
          delay(40);
          turn_right();      
          
          delay(15);
          }
      }
  }

}

void phase1(){
  BluetoothData = Serial.read();
  while(1){
    BluetoothData = Serial.read();
    if(BluetoothData=='u'){
     break;
     }
      digitalWrite(trig_pin,HIGH);
      delayMicroseconds(10);
      digitalWrite(trig_pin,LOW);
      
      echotime = pulseIn(echo_pin,HIGH);
      distance = 0.0001*((float)echotime*340.0)/2.0;
      Serial.println(distance);
      
      if (distance<40) {
        if(BluetoothData=='u'){
          break;
       }
        Stop();
        delay(500);
        backward();
        delay(400);
        Stop();
      }
      BluetoothData = Serial.read();
      if(BluetoothData=='u'){
        break;
        }
   
      //easy drive  
      if(BluetoothData=='B'){
       backward();
      }
      
      if(BluetoothData=='F'){
        forward();
      }
      
      if(BluetoothData=='L'){
        turn_left();
      }
      
      if(BluetoothData=='R'){
          turn_right();
      }
          
      if(BluetoothData=='S'){
        Stop();
        }
      if(BluetoothData=='u')
        break;
      
    }
}

//shapes functions
void shapes(){
  delay(10000);
  //Rectangle shape function
  analogWrite(enl,160);
  analogWrite(enr,160);
 
  forward(); //long
  delay(1150); 
  Stop();
  delay(150);
  turn_right(); //turn
  delay(490); 
  Stop();
  delay(150);
  forward(); //short
  delay(640);
  Stop();
  delay(150);
  turn_right(); //turn
  delay(490);
  Stop();  
  delay(150);
  forward(); //long
  delay(1150);
  Stop(); 
  delay(150);
  turn_right(); //turn
  delay(490);
  Stop(); 
  delay(150);
  forward(); //short
  delay(640);
  Stop();
  delay(150);
  turn_right(); //turn
  delay(490);
  Stop();
  delay(25000);
  
// circle Right shape function
  forward();
  delay(30);
  
  analogWrite(enl,180);
  analogWrite(enr,40);

  digitalWrite(pin6,HIGH);
  digitalWrite(pin7,LOW);
  digitalWrite(pin8,HIGH);
  digitalWrite(pin9,LOW);
  delay(3510);

  Stop();
  delay(25000);
 
//inf shape function
  forward();
  delay(50);
  
  analogWrite(enl,180);
  analogWrite(enr,40);

  digitalWrite(pin6,HIGH);
  digitalWrite(pin7,LOW);
  digitalWrite(pin8,HIGH);
  digitalWrite(pin9,LOW);
  delay(3350);
 
  
  analogWrite(enr,160);    //left circle
  analogWrite(enl,50);

  digitalWrite(pin6,HIGH);
  digitalWrite(pin7,LOW);
  digitalWrite(pin8,HIGH);
  digitalWrite(pin9,LOW);
  delay(2600);
  Stop(); 
 
}


void loop() {
  BluetoothData = Serial.read();
  digitalWrite(enl,HIGH);
  digitalWrite(enr,HIGH);
  //line follower
  if(BluetoothData=='W'){
    follow_line();
  }
 // if(BluetoothData=='U'){
    phase1();
  //}
  
   if(BluetoothData=='X'){
    shapes();
  }

  if(BluetoothData=='u'||'w'||'x'){
    Stop();
  }

}
