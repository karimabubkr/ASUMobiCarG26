
int flame_input = A0 ; // Analog output pin of flame sensor is put in A0 analog pin
int r1 = 5 , l1 = 6 , r2 = 7 , l2 = 8 ; // r1 is right back , l1 is left back , r2 is right front , l2 is left front


void forward_analog( int Speed )
{
  analogWrite( r1 , Speed );
  analogWrite( l1 , Speed );
  analogWrite( r2 , Speed );
  analogWrite( l2 , Speed );
  
}



void Stop()
{
  digitalWrite( r1 , LOW );
  digitalWrite( l1 , LOW );
  digitalWrite( r2 , LOW );
  digitalWrite( l2 , LOW );
}



void setup() {
  // put your setup code here, to run once:

  pinMode( flame_input , INPUT );
  
  pinMode( r1 , OUTPUT );
  pinMode( l1 , OUTPUT );
  pinMode( r2 , OUTPUT );
  pinMode( l2 , OUTPUT );

}

void loop() {
  // put your main code here, to run repeatedly:

  if ( 25 < flame_input <= 255 )
  {
    forward_analog( flame_input );
    delay( 1500 );
  }

  Stop();
  
}
