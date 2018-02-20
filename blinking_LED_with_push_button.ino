// example "Blinnking led with a push button"

/*
using a button if clicked then the led starts blinking, 
else the led satys off.
*/

const int led = 13; //defining led pin number.
const int button = 2; //defining button pin number.
int buttonVal; //to store the value of the button pin.


void setup() {
pinMode(led,OUTPUT); //defining the led pin as output.
pinMode(button,INPUT); //defining the button pin as input.
}

void loop() {
  buttonVal= digitalRead(button); 
  //storing the value of the button pin.

  //if the button is pushed
  if(buttonVal == HIGH){
    
    //turn on the light
    digitalWrite(led,HIGH); 

    //saty one second
    delay (1000); 
  
    //turn off the light
    digitalWrite(led,LOW); 

    //saty one second
    delay (1000); 
  }
  
  else{
    digitalWrite(led,LOW);
  }
}
