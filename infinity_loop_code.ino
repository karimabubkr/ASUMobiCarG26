

/* Infinity loop motion clockwise at start */

/* r1 == front_right , r2 == back_right  , l1 == front_left , l2 == back_left */


int r1 = 13  , l1 = 12  , r2 = 8  , l2 = 7  ;
int t1 = 1400 , t2 = 2000 ;


void setup() {
  // put your setup code here, to run once:

  pinMode( r1 , OUTPUT );
  pinMode( l1 , OUTPUT );
  pinMode( r2 , OUTPUT );
  pinMode( l2 , OUTPUT );
  

}

void loop() {
  // put your main code here, to run repeatedly:


  // forward
  
  digitalWrite( r2 , HIGH );
  digitalWrite( l2 , HIGH );
  digitalWrite( r1 , HIGH );
  digitalWrite( l1 , HIGH );
  delay( t2 );




  // half circle motion clockwise

  digitalWrite( r2 , HIGH );
  digitalWrite( l2 , HIGH );
  digitalWrite( r1 , LOW );
  digitalWrite( l1 , HIGH );
  delay( t1 );



  // forward again

  digitalWrite( r2 , HIGH );
  digitalWrite( l2 , HIGH );
  digitalWrite( r1 , HIGH );
  digitalWrite( l1 , HIGH );
  delay( t2 );




  // half circle motion anti-clockwise

  digitalWrite( r2 , HIGH );
  digitalWrite( l2 , HIGH );
  digitalWrite( r1 , HIGH );
  digitalWrite( l1 , LOW );
  delay( t1 );

  


}
