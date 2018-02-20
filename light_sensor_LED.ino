// example "light sensor led"
/*
using photoresistor to sense the light intensity and lightsing led with the crossponding measured intensity.
*/

// defining led pin with pulse width modulation "PWD"
const int led = 3; 

//defining photoresistor analoge pin.
const int light = A0;

//variable to store light level.
int lightLvl;


void setup() {
  //defining the led pin as output.
  pinMode(led,OUTPUT);
}


void loop() {
  //storing the value from the analog pinn of the photoresistor
  lightLvl = analogRead(light);

  //channging the analoge value of the photoresistor volt to digital value
  lightLvl = map(lightLvl, 0, 900, 0, 255 );

  //constrains the lightLvl to be within range of [0:255].
  lightLvl = constrain(lightLvl, 0, 255);

  //lights the led with intensity that crossponds the value of the photoresistor
  analogWrite(led, lightLvl);
}
