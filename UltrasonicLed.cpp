int cm = 0;
const int ledPin = 9;  

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(ledPin,OUTPUT);

}

void loop()
{
  cm = 0.01723 * readUltrasonicDistance(7, 6);
  byte val = 0;
  val = map(cm, 0, 400, 0, 255);
  analogWrite(ledPin, val);
  delay(8);
}
