unsigned int EncA=2;
unsigned int EncB=4;
unsigned int val=0;
unsigned int val2=0;
void setup() {
  // put your setup code here, to run once:
pinMode(EncA, INPUT_PULLUP);
pinMode(EncB, INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  val= digitalRead(EncA);
  val2= digitalRead(EncB);
  Serial.print(val);Serial.print(',');Serial.println(val2);
  digitalWrite(LED_BUILTIN, 0);
  delay(500);
}
