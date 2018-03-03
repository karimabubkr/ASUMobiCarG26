int yellow =13;
int green =12;
int red =11;
void setup()
{
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
}
void loop()
{
 digitalWrite(yellow,HIGH);
 digitalWrite(red,LOW);
 digitalWrite(green,LOW);
 delay(2000);
 digitalWrite(yellow,LOW);
 digitalWrite(red,HIGH);
 digitalWrite(green,LOW);
 delay(2000);
 digitalWrite(yellow,LOW);
 digitalWrite(red,LOW);
 digitalWrite(green,HIGH);
}
 
