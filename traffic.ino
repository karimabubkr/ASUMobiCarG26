int yellow = 12;
int green = 13;
int red = 11;
void setup()
{
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}
  void loop()
  {
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    delay(3000); 
    
     digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    delay(3000);
    
     digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(3000);
  }
