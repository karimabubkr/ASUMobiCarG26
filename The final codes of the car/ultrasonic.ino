/*
 * 
 * ultrasonic only
 * 
*/

int led = 13;
//left motors
int enl = 5;//enable left
int pin6 = 6;//B2
int pin7 = 7;//B1
//right motors
int enr = 10;//enable left
int pin8 = 8;//A2
int pin9 = 9;//A1

int trig_pin = 12;
int echo_pin = 13;
long echotime;
float distance;

//bluetooth 
char BluetoothData;

void setup(){
  pinMode(led,OUTPUT);
  //motor
  pinMode(pin6,OUTPUT);
  pinMode(pin7,OUTPUT);
  pinMode(pin8,OUTPUT);
  pinMode(pin9,OUTPUT);
  pinMode(enl,OUTPUT);
  pinMode(enr,OUTPUT);
  
  digitalWrite(enl,HIGH);
  digitalWrite(enr,HIGH);

  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  digitalWrite(trig_pin,LOW);
  
  Serial.begin(9600);
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
  BluetoothData = Serial.read();

  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);

  echotime = pulseIn(echo_pin,HIGH);
  distance = 0.0001*((float)echotime*340.0)/2.0;
  Serial.println(distance);

  if (distance<40) {
    Stop();
    delay(500);
    backward();
    delay(400);
    Stop();
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
  

}
