
/* This code is designed so it acts on a circuit to make it behave as the stairs light circuit ,
 *  when you press a certain button ( push button or switch ) the light turns on for a while then 
 *  turns off automatically , the period i will make is 10 seconds
 */


  
 int x ;

void setup() {
  // put your setup code here, to run once:

  pinMode( 10 , INPUT );
  pinMode( 11 , OUTPUT );

}

void loop() {
  // put your main code here, to run repeatedly:

  x = digitalRead( 10 );

  if ( x == 1 )
  {
    digitalWrite( 11 , HIGH );
    delay( 10000 );
    digitalWrite( 11 , LOW );
    
  }
  

}
