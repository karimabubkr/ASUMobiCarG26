const int PinL = 2;
const int PinC = 3;
const int PinR = 4;
int LState = 0;
int CState = 0;
int RState = 0;
void setup() {
  Serial.begin(9600);
pinMode(PinL, INPUT);
pinMode(PinC, INPUT);
pinMode(PinR, INPUT);
}
void loop() {
LState = digitalRead(PinL);
CState = digitalRead(PinC);
RState = digitalRead(PinR);
if (LState == LOW) {Serial.print(" black1"); Serial.print(" "); }
if (LState == HIGH){Serial.print(" white1");Serial.print(" "); }
if (CState == LOW) {Serial.print(" black2"); Serial.print(" ");}
if (CState == HIGH) {Serial.print(" white2");Serial.print(" "); }
if (RState == LOW) {Serial.print(" black3"); Serial.print(" "); }
if (RState == HIGH) {Serial.println(" white3"); Serial.print(" ");}
Serial.println("****************************");
delay(1000);
}
