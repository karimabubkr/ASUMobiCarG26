int r1=13;
int l1=12;
int r2=8;
int l2=7;

int t1=3000; //delay walking forward till finishing the longer line
int t2=2500; //dealy walking forward till finishing the shorter one 
int t3=100;  //delay after stoping the car and before start rotating
int t4=1000; //delay rotating to get 90 degree

void setup()
{

  pinMode(r1,OUTPUT);
  pinMode(l1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(l2,OUTPUT);

}

void loop()
{
 //rectangular shape (clockwise)

 digitalWrite(r1,1);  //first line
 digitalWrite(l1,1);
 digitalWrite(r2,1);
 digitalWrite(l2,1);
 delay(t1);
 digitalWrite(r1,0); //finish it
 digitalWrite(r2,0);
 digitalWrite(l1,0);
 digitalWrite(l2,0);
 delay(t3);
 digitalWrite(l1,1); //rotating 90
 digitalWrite(l2,1);
 delay(t4);
 
 digitalWrite(r1,1);  //second line
 digitalWrite(l1,1);
 digitalWrite(r2,1);
 digitalWrite(l2,1);
 delay(t2);
 digitalWrite(r1,0); //finish it
 digitalWrite(r2,0);
 digitalWrite(l1,0);
 digitalWrite(l2,0);
 delay(t3);
 digitalWrite(l1,1); //rotating 90
 digitalWrite(l2,1);
 delay(t4);
 
 digitalWrite(r1,1);  //third line
 digitalWrite(l1,1);
 digitalWrite(r2,1);
 digitalWrite(l2,1);
 delay(t1);
 digitalWrite(r1,0); //finish it
 digitalWrite(r2,0);
 digitalWrite(l1,0);
 digitalWrite(l2,0);
 delay(t3);
 digitalWrite(l1,1); //rotating 90
 digitalWrite(l2,1);
 delay(t4);
 
 digitalWrite(r1,1);  //forth line
 digitalWrite(l1,1);
 digitalWrite(r2,1);
 digitalWrite(l2,1);
 delay(t2);
 digitalWrite(r1,0); //finish it
 digitalWrite(r2,0);
 digitalWrite(l1,0);
 digitalWrite(l2,0);
}
