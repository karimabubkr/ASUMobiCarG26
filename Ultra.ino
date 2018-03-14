const byte Trig = 7;
const byte Echo = 8;
float distance ;
unsigned long period;
void setup() {
 pinMode(Trig,OUTPUT);
 pinMode(Echo,INPUT);
 Serial.begin(9600);
}
void loop() {
digitalWrite(Trig,LOW);
digitalWrite(Trig,HIGH);
delayMicroseconds(10);
digitalWrite(Trig,LOW);
period = pulseIn(Echo,HIGH);
distance = float(period)*0.017;             //distace = (period/2*10^6)*340*100 cm 
Serial.println(distance);
delay(60);

}
