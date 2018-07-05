/*
 * 
 * the string sent through the bluetooth module 
 * is printed on the serial monitor.
 * 
 * 
*/

//left motors
int enl = 5;//enable left
int pin6 = 6;//B2
int pin7 = 7;//B1
//right motors
int enr = 10;//enable left
int pin8 = 8;//A2
int pin9 = 9;//A1

String input;
int distance_recieved = 0;

void setup(){

  Serial.begin(9600);
  }


void loop() {

  if(Serial.available()){
    
    while(Serial.available()){
      
        delay(5);             
        char inChar = (char)Serial.read();
        delay(5);
        input += inChar;
        delay(5);
    }
    
    // print the sent string
    Serial.println(input);

    // change the string to integer
    distance_recieved = input.toInt();
    input = "";
  }
        



}
