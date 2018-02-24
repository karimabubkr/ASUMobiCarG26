int i = 0;
int led = 3;
int button1 = 9;
int button2 = 10;

void setup() {
  pinMode(button1, INPUT);   
  pinMode(button2, INPUT); 
  pinMode(led, OUTPUT);

}

void loop() {
  analogWrite(led, i);  // analogWrite values from 0 to 255

  //brighting
  if (digitalRead(button1)==LOW)
  {
    if (i<255)
    {
      i++;
      delay(30);
      }
  }

  //dimming
  if (digitalRead(button2)==LOW)
  {
    if (i>0)
    {
      i--;// 
      delay(30);
    }
  }
}
