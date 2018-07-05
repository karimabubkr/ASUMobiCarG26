/*
 * Final version 1.0
 * Easy Driving only 
*/

//left motors
int enl = 5;//enable left
int pin6 = 6;//B2
int pin7 = 7;//B1
//right motors
int enr = 10;//enable left
int pin8 = 8;//A2
int pin9 = 9;//A1

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
  
  digitalWrite(enl,HIGH);
  digitalWrite(enr,HIGH);
  
  Serial.begin(9600);
  }

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


void loop() {
  BluetoothData = Serial.read();
  
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
  

}
