

  
  
  
  int ledr=4;
  int x;
  void setup(){
pinMode(ledr,OUTPUT);

}

void loop() {
  

for(x=0;x<=255;x++)
    {
      analogWrite(ledr,x);
      delay(50);
    }  
  
    for(x=255;x>=0;x--)
    {
      analogWrite(ledr,x);
      delay(50);
    }
}
