
int led = 13;
int pin6=6;//B2
int pin7=7;//B1
int pin8=8;//A2
int pin9=9;//A1

char BluetoothData;

void setup() {
pinMode(led,OUTPUT);
pinMode(pin6,OUTPUT);
pinMode(pin7,OUTPUT);
pinMode(pin8,OUTPUT);
pinMode(pin9,OUTPUT);
Serial.begin(9600);
}


void loop() {



if (Serial.available()){

BluetoothData=Serial.read();


if(BluetoothData=='L'){ 

digitalWrite(led,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);
}

if (BluetoothData=='R'){
digitalWrite(led,HIGH);
digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,HIGH);



}
if(BluetoothData=='F')
{
digitalWrite(led,HIGH);
digitalWrite(pin6,HIGH);
digitalWrite(pin7,LOW);
digitalWrite(pin8,HIGH);
digitalWrite(pin9,LOW);
}
if(BluetoothData=='B')
{
digitalWrite(led,HIGH);
digitalWrite(pin6,LOW);
digitalWrite(pin7,HIGH);
digitalWrite(pin8,LOW);
digitalWrite(pin9,HIGH);
}
if(BluetoothData=='S')
{
digitalWrite(led,LOW);
digitalWrite(pin6,LOW);
digitalWrite(pin7,LOW);
digitalWrite(pin8,LOW);
digitalWrite(pin9,LOW);
}

}




}
