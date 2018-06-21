int r1=13;
int l1=12;
int r2=8;
int l2=7;
int t5=100;//delay rotating to get 6 degrees
void setup()
{
  pinMode(r1,OUTPUT);
  pinMode(l1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(l2,OUTPUT);
}
void loop()
{
for(int i=1;i<=60;i++)
{
  digitalWrite(r1,1);
  digitalWrite(r2,1);
  digitalWrite(l1,0);
  digitalWrite(l2,0);
  delay(t5);
}
}
