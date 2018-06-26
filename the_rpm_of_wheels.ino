#include <TimerOne.h>
const byte motor1=2;
const byte motor2=3;
unsigned int counter1=0;
unsigned int counter2=0;
float diskslots=20; //no. of slots of sensor disk
void ISR_count1()
{
  counter1++;
}
void ISR_count2()
{
  counter2++;
}
void ISR_timerone()
{
  Timer1.detachInterrupt(); //stop the timer
  Serial.print("motor1 speed:");
  float rotation1=(counter1/diskslots)*60; // RpM OF MOTOR1
  Serial.print(rotation1);
  counter1=0;
  Serial.print("motor2 speed:");
  float rotation2=(counter2/diskslots)*60; // RPM OF MOTOR2
  Serial.print(rotation2);
  counter2=0;
  Timer1.attachInterrupt(ISR_timerone);
}

void setup() {
  Serial.begin(9600);
  Timer1.initialize(1000000);
  attachInterrupt(0,ISR_count1,RISING);
  attachInterrupt(1,ISR_count2,RISING);
Timer1.attachInterrupt(ISR_timerone); //enable the timer

}

void loop() {
  // nothing

}
