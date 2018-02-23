int i=8,j=5;
void setup() 
{
  for(;i<11&j<8;i++)
  {
    pinMode(i,OUTPUT);
    pinMode(j,INPUT);
    j++;
  }
}

void loop() 
{
  if(digitalRead(5)== HIGH||digitalRead(6)== HIGH||digitalRead(7)== HIGH)
    {for(i=8;i<11;i++)
      digitalWrite(i,HIGH);  
     delay(10000);
     for(i=8;i<11;i++)
      digitalWrite(i,LOW);  
    } 
}

