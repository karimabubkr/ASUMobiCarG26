


int led = 13;
int pin6=6;//B2
int pin7=7;//B1
int pin8=8;//A2
int pin9=9;//A1
int trigPin=12;
int echoPin=13;
int maximumrange=15;
long duration,distance;

char BluetoothData;

void setup() {
pinMode(led,OUTPUT);
pinMode(pin6,OUTPUT);
pinMode(pin7,OUTPUT);
pinMode(pin8,OUTPUT);
pinMode(pin9,OUTPUT);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);
}


void Stop()
{
digitalWrite(led,LOW);
digitalWrite(pin6,LOW);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,LOW);

}
  void turn_left()
  {
digitalWrite(led,HIGH);
digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);
  }
    void forward(){
digitalWrite(led,HIGH);
digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,HIGH);

    }
void backward(){ 

digitalWrite(led,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);

}
  void turn_right()
  {
digitalWrite(led,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);
digitalWrite(pin9,HIGH);
  }

void cal()
{  
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(3); 

 digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH);
 digitalWrite(echoPin,LOW);
 distance = duration/58.2;
}
void loop()
{
if (Serial.available()>0)
{

BluetoothData=Serial.read();


if(BluetoothData=='B')
{
 backward();
}

if(BluetoothData=='F'){
  cal();
  if(distance>=maximumrange)
  {
     forward();

}

else if(distance<maximumrange)
  {
   Stop();
  }

  }
  if(BluetoothData=='L')
  {
    
 cal();
 
   
  if(distance>=maximumrange)
  { 
    
  turn_left();
  }
  else if (distance<maximumrange){

   Stop();
}
}
if(BluetoothData=='R')
{
    cal();
  if(distance>=maximumrange)
  {
    turn_right();
  }
  
  else if (distance<maximumrange){

  Stop();
}
}
if(BluetoothData=='S')
{
  Stop();
}

}
}











