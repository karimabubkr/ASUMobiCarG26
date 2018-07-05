/*
*
* phase 1 (ultrasonic with easu driving)
* phase 2 (line follower)
*
*
*/

//left motors
int enl = 5;//enable left
int pin6 = 6;//B2
int pin7 = 7;//B1
//right motors
int enr = 10;//enable left
int pin8 = 8;//A2
int pin9 = 9;//A1

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

  //linefollower
  pinMode(PinL, INPUT);
  pinMode(PinC, INPUT);
  pinMode(PinR, INPUT);
  digitalWrite(enl,HIGH);
  digitalWrite(enr,HIGH);

  //bluetooth
  Serial.begin(9600);
  // Driving functions
  void Stop(){
  digitalWrite(pin6,LOW);
  digitalWrite(pin7,LOW);
  digitalWrite(pin8,LOW);
  digitalWrite(pin9,LOW);
  }
  
  void turn_left(){
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
  
  void turn_right(){
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


}
void loop() {
  BluetoothData = Serial.read();
  digitalWrite(enl,HIGH);
  digitalWrite(enr,HIGH);
  //line follower
  if(BluetoothData=='W'){
    follow_line();
  }

  if(BluetoothData=='w'){
    Stop();
  }


