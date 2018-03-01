
/* This program makes an electronic circuit acts as an indicator through 4 green LEDs indicating how much
  of a certain potentiometer ( in percentage ) is being used but in ranges of each quarter in this potentiometer
  i.e ( from 0% to 25%  or  from 25% to 50%  or  ... etc  ) and the Vcc is set to 5 volts
 */

int i ;

void setup() {
  // put your setup code here, to run once:

  for ( i = 4 ; i < 8 ; i++ )
  {
    pinMode( i , OUTPUT );
  }

  pinMode( A1 , INPUT );


}


void loop() {
  // put your main code here, to run repeatedly:

  float analog_voltage ;
  float real_voltage ;

  analog_voltage = analogRead( A1 );
  real_voltage = 5.0 * ( analog_voltage / 1023.0 );

  if ( real_voltage == 5 )
  {
    i = 4 ;
    while( i < 8 )
    {
      digitalWrite( i , LOW );
      i++ ;
      
    }
    
  }

  
  
    if ( ( real_voltage >= 3.75 )&&( real_voltage < 5 ) )
    {
      digitalWrite( 4 , HIGH );
      digitalWrite( 5 , LOW );
      digitalWrite( 6 , LOW );
      digitalWrite( 7 , LOW );
    }
    else if ( ( real_voltage >= 2.5 )&&( real_voltage < 3.75 ) )
    {
      digitalWrite( 4 , HIGH );
      digitalWrite( 5 , HIGH );
      digitalWrite( 6 , LOW );
      digitalWrite( 7 , LOW );
    }
    else if ( ( real_voltage >= 1.25 )&&( real_voltage < 2.5 ) )
    {
      digitalWrite( 4 , HIGH );
      digitalWrite( 5 , HIGH );
      digitalWrite( 6 , HIGH );
      digitalWrite( 7 , LOW );
    }
    else if ( ( real_voltage >= 0 )&&( real_voltage < 1.25 ) )
    {
      digitalWrite( 4 , HIGH );
      digitalWrite( 5 , HIGH );
      digitalWrite( 6 , HIGH );
      digitalWrite( 7 , HIGH );
    }

   
  delay( 5 );

}
