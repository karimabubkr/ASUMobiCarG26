#include <TimerOne.h>
const byte MOTOR_A = 3;  // Motor 2 Interrupt Pin - INT 1 - Right Motor
const byte MOTOR_B = 2;  // Motor 1 Interrupt Pin - INT 0 - Left Motor

// Constant for steps in disk
const float stepcount = 20.00;  // 20 Slots

// Constant for wheel diameter
const float wheeldiameter = 66.10; // In mm

// Integers for pulse counters
volatile int counter_A = 0;
volatile int counter_B = 0;

char bluetoothdata;
long val=0;
// Motor A

int enA = 10;
int in1 = 9;
int in2 = 8;

// Motor B

int enB = 5;
int in3 = 7;
int in4 = 6;

// Interrupt Service Routines

// Motor A pulse count ISR
void ISR_countA()  
{
  counter_A++; 
} 

// Motor B pulse count ISR
void ISR_countB()  
{
  counter_B++; 
}

// Function to convert from centimeters to steps
int CMtoSteps(float cm) {

  int result;  
  float circumference = (wheeldiameter * 3.14) / 10; // Calculate wheel circumference in cm
  float cm_step = circumference / stepcount;  // CM per Step
  
  float f_result = cm / cm_step; 
  result = (int) f_result; 
  
  return result; 

}

// Function to Move Forward
void MoveForward(int steps, int mspeed) 
{
   counter_A = 0;  
   counter_B = 0;  
   
   // Set Motor A forward
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);

   // Set Motor B forward
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   
   
   while (steps > counter_A && steps > counter_B) {
   
    if (steps > counter_A) {
    analogWrite(enA, mspeed);
    } else {
    analogWrite(enA, 0);
    }
    if (steps > counter_B) {
    analogWrite(enB, mspeed);
    } else {
    analogWrite(enB, 0);
    }
   }
    
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  counter_A = 0;  
  counter_B = 0;  

}

// Function to Move in Reverse
void MoveReverse(int steps, int mspeed) 
{
   counter_A = 0;  
   counter_B = 0;  
   
   // Set Motor A reverse
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  // Set Motor B reverse
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   
   
   while (steps > counter_A && steps > counter_B) {
   
    if (steps > counter_A) {
    analogWrite(enA, mspeed);
    } else {
    analogWrite(enA, 0);
    }
    if (steps > counter_B) {
    analogWrite(enB, mspeed);
    } else {
    analogWrite(enB, 0);
    }
    }
    
  
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  counter_A = 0;  
  counter_B = 0;  

}



void setup() 
{
  // Attach the Interrupts to their ISR's
  attachInterrupt(digitalPinToInterrupt (MOTOR_A), ISR_countA, RISING);  // Increase counter A 
  attachInterrupt(digitalPinToInterrupt (MOTOR_B), ISR_countB, RISING);  // Increase counter B 

} 


void loop()
{  
  
if ( Serial.available () > 0 ) 
{

  bluetoothdata = Serial.read();
  if(bluetoothdata!='f' && bluetoothdata!='b')
  {
  val = atol(bluetoothdata); // Convert character into number
  }
 

 if(bluetoothdata=='f')
 {
  MoveForward(CMtoSteps(val), 255);  
 }
 if(bluetoothdata=='b')
 {
  MoveReverse(CMtoSteps(val), 255); 
 }   
}
}
