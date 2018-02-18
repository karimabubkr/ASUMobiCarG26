  int ledr=4;
  int ledw=6;
  int ledg=5; 
  int ledy=7; 
  
  
  
  void setup(){
pinMode(ledr,OUTPUT);
pinMode(ledw,OUTPUT);
pinMode(ledg,OUTPUT);
pinMode(ledy,OUTPUT);

}

void loop() {
  

  
  while(1)
    {
      digitalWrite(ledr,HIGH);
      delay(1000);
      digitalWrite(ledr,LOW);
    digitalWrite(ledw,HIGH);
    delay(1000);
    digitalWrite(ledw,LOW);
    digitalWrite(ledg,HIGH);
    delay(1000);
    digitalWrite(ledg,LOW);
    digitalWrite(ledy,HIGH);
    delay(1000);
    digitalWrite(ledy,LOW);
    
  
}
 
 
  

}
