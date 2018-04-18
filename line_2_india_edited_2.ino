int rightmotor1=13;
int leftmotor1=12;
int rightmotor2=8;
int leftmotor2=7;


int sensorleft=4;
int sensorcenter_1=2;
int sensorcenter_2=3; /* this sensor will be the most front one that senses if the line still exists forward or not in order to complete moving forward ( if the line exists ) or 
                          turn left or right with the line ( if the line is then curved to right or left ) */
int sensorright=1;


int sl , sc1 , sc2 , sr ; /* variables that read the input voltages on sensors */

int f_sl=0 , f_sc1=0 , f_sc2=0 , f_sr=0 ; /* feedback variables for sensors that enables me to know the last state of the car action taken and these are used specially for thin lines */

//////////////////////////////////////

void setup()
{

  pinMode(rightmotor1,OUTPUT);
  pinMode(leftmotor1,OUTPUT);
  pinMode(rightmotor2,OUTPUT);
  pinMode(leftmotor2,OUTPUT);

  pinMode(sensorleft,INPUT);
  pinMode(sensorcenter_1,INPUT);
  pinMode(sensorcenter_2,INPUT);
  pinMode(sensorright,INPUT);

}
///////////////////////////////////////////////////

void loop()
{
  sl=digitalRead(sensorleft);
  sc1=digitalRead(sensorcenter_1);
  sc2=digitalRead(sensorcenter_2);
  sr=digitalRead(sensorright);

  /////////////////////////////////////////////////////////////////////
  if(sl==1 && sc1==1 && sr==1)   //if all are white then continue doing the last state
  {
    if ( f_sl == 1 ) // continue turning left
    {
      digitalWrite(rightmotor1,1);
    digitalWrite(rightmotor2,0);
    digitalWrite(leftmotor1,0);
    digitalWrite(leftmotor2,0);
    f_sl = 1;
    f_sc1 = 0;
    f_sc2 = 0;
    f_sr = 0;
    }

    else if ( f_sc1==1 && f_sc2==1 ) // continue moving forward
    {
      digitalWrite(rightmotor1,1);
    digitalWrite(rightmotor2,0);
    digitalWrite(leftmotor1,1);
    digitalWrite(leftmotor2,0);
    f_sl = 0;
    f_sc1 = 1;
    f_sc2 = 1;
    f_sr = 0;
    
    }

    else if ( f_sr == 1 ) // continue turning right
    {
      digitalWrite(rightmotor1,0);
      digitalWrite(rightmotor2,0);
      digitalWrite(leftmotor1,1);
      digitalWrite(leftmotor2,0);
    f_sl = 0;
    f_sc1 = 0;
    f_sc2 = 0;
    f_sr = 1;
    
    }
    
  }

  ////////////////////////////////////////////////////////////////////////////
  if( ( (sl==0 && sc1==1 && sr==1) || (sl==0 && sc1==0 && sr==1) ) && (sc2==1) )   //left turn
  {
    digitalWrite(rightmotor1,1);
    digitalWrite(rightmotor2,0);
    digitalWrite(leftmotor1,0);
    digitalWrite(leftmotor2,0);
    f_sl = 1;
    f_sc1 = 0;
    f_sc2 = 0;
    f_sr = 0;
  }
  
  else if ( ( (sl==0 && sc1==1 && sr==1) || (sl==0 && sc1==0 && sr==1) ) && (sc2==0) ) // continue forward
  {
    digitalWrite(rightmotor1,1);
    digitalWrite(rightmotor2,0);
    digitalWrite(leftmotor1,1);
    digitalWrite(leftmotor2,0);
    f_sl = 0;
    f_sc1 = 1;
    f_sc2 = 1;
    f_sr = 0;
  }
  
  
  else
    if( ( (sl==1 && sc1==1 && sr==0) || (sl==1 && sc1==0 && sr==0) ) && ( sc2==1 ) )  //right turn
    {
      digitalWrite(rightmotor1,0);
      digitalWrite(rightmotor2,0);
      digitalWrite(leftmotor1,1);
      digitalWrite(leftmotor2,0);
    f_sl = 0;
    f_sc1 = 0;
    f_sc2 = 0;
    f_sr = 1;
    
    }
    else if ( ( (sl==1 && sc1==1 && sr==0) || (sl==1 && sc1==0 && sr==0) ) && ( sc2==0 ) ) // continue forward
    {
      
    digitalWrite(rightmotor1,1);
    digitalWrite(rightmotor2,0);
    digitalWrite(leftmotor1,1);
    digitalWrite(leftmotor2,0);
    f_sl = 0;
    f_sc1 = 1;
    f_sc2 = 1;
    f_sr = 0;
    
    }
 
    else
      if( (sl==1 && sc1==0 && sr==1) || ( sc1==0 && sc2==0 ) )  //go forward straight
      {
        digitalWrite(rightmotor1,1);
        digitalWrite(rightmotor2,0);
        digitalWrite(leftmotor1,1);
        digitalWrite(leftmotor2,0);
        f_sl = 0;
        f_sc1 = 1;
        f_sc2 = 1;
        f_sr = 0;
      }
    else
      if( (sl==0 && sc1==0 && sr==0) && ( sc2==1 ) ) //stop
        {
          digitalWrite(rightmotor1,0);
          digitalWrite(rightmotor2,0);
          digitalWrite(leftmotor1,0);
          digitalWrite(leftmotor2,0);
          f_sl = 0;
          f_sc1 = 0;
          f_sc2 = 0;
          f_sr = 0;
        }

  ///////////////////////////////////////////////////////////////////
    
}

