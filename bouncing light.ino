int red = 4;
int blue = 5;
int yellow = 6;
int green = 7;
void setup()
{
  pinMode(red , OUTPUT);
  pinMode(blue , OUTPUT);
  pinMode(yellow , OUTPUT);
  pinMode(green , OUTPUT);
}
void loop ()
{  
  digitalWrite(red , HIGH);
  digitalWrite(blue , LOW);
  digitalWrite(yellow , LOW);
  digitalWrite(green , LOW);
  delay(1000);
  digitalWrite(red , LOW);
  digitalWrite(blue , HIGH);
  digitalWrite(yellow , LOW);
  digitalWrite(green , LOW);
  delay(1000);
  digitalWrite(red , LOW);
  digitalWrite(blue , LOW);
  digitalWrite(yellow , HIGH);
  digitalWrite(green , LOW);
  delay(1000);
  digitalWrite(red , LOW);
  digitalWrite(blue , LOW);
  digitalWrite(yellow , LOW);
  digitalWrite(green , HIGH);
  delay(1000);
  
   digitalWrite(red , LOW);
  digitalWrite(blue , LOW);
  digitalWrite(yellow , LOW);
  digitalWrite(green , HIGH);
  delay(1000);
  digitalWrite(red , LOW);
  digitalWrite(blue , LOW);
  digitalWrite(yellow , HIGH);
  digitalWrite(green , LOW);
  delay(1000);
  digitalWrite(red , LOW);
  digitalWrite(blue , HIGH);
  digitalWrite(yellow , LOW);
  digitalWrite(green , LOW);
  delay(1000);
  digitalWrite(red , HIGH);
  digitalWrite(blue , LOW);
  digitalWrite(yellow , LOW);
  digitalWrite(green , LOW);
  delay(1000);

}
