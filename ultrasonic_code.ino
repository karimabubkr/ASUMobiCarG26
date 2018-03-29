int trigPin=12;
int echoPin=13;
int Time, distance;
void setup()
{
    Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
 

}

void loop() {
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(3); 
 digitalWrite(trigPin, LOW); 
 Time = pulseIn(echoPin, HIGH);
 digitalWrite(echoPin,LOW);
 
distance = (Time/29)/2;
  Serial.print(distance);   
  Serial.println(" cm ");
  delay(50);

}
