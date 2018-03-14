const byte Trig = 7;
const byte Echo = 8;
const byte Buzzer = 9;
const byte limit=10; // minimum distance between the car & any block in front of it
float distance ;
unsigned long period;
void setup() {
 pinMode(Trig,OUTPUT);
 pinMode(Echo,INPUT);
 pinMode(Buzzer,OUTPUT);
}
void loop() {
digitalWrite(Trig,LOW);
digitalWrite(Trig,HIGH);
delayMicroseconds(10);
digitalWrite(Trig,LOW);
period = pulseIn(Echo,HIGH);
distance = float(period)*0.017;             //distace = (period/2*10^6)*340*100 cm 
if (distance<=limit)
  digitalWrite(Buzzer,HIGH);
else
  digitalWrite(Buzzer,LOW);
delay(60);

}
