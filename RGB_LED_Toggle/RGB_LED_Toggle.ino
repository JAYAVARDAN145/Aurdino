enum Led{RED=7,GREEN,BLUE};

int Leds[] = {RED,GREEN,BLUE};
void rgb_toggle();

void setup()
{
  Serial.begin(9600);
  for(int i=0;i<3;i++)
  pinMode(Leds[i], OUTPUT);
}
void loop()
{
  rgb_toggle();
}
void rgb_toggle()
{
  for(int i=0;i<3;i++)
  {
    Serial.print("Toggling LED on pin ");
    Serial.println(Leds[i]);
    digitalWrite(Leds[i], HIGH);
    delay(500);
    digitalWrite(Leds[i], LOW);
    delay(500);
  }
}

