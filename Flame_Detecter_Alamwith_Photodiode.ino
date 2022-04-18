#define Photodiode A0// connect Photo diode to A0 Pin of Arduino as per the circuit
#define RED_LED 5// connect Red LED to Digital Pin 5 of Arduino as per the circuit
#define GREEN_LED 6//connect Green LED to Digital Pin 6 of Arduino as per the circuit
#define Buzzer 7//connect Buzzer to Digital Pin 7 of Arduino as per the circuit
#define Relay 8//connect Relay  to Digital Pin 8 of Arduino as per the circuit
int x, i;
void setup()
{
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Relay, OUTPUT);

  Serial.begin(9600);
}
void loop()
{
  x = analogRead(Photodiode);
  if (x > 50)// decrease the value of "x" to trigger alarm in a Low flame.
  {
  Serial.println(" Fire Detected!!!");
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(Relay, HIGH);
  for (i = 0; i < 5; i++)
  {

    digitalWrite(RED_LED, HIGH);
    tone(Buzzer, 1000);
    delay(500);

    digitalWrite(RED_LED, LOW);
    tone(Buzzer, 500);
    delay(500);
  }
}
else
{
  noTone(Buzzer);
  digitalWrite(Relay, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(500);
  digitalWrite(GREEN_LED, LOW);
  Serial.println("System Normal");
  delay(1000);
}
}
