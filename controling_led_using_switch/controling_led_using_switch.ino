#define sw 9
#define led_ 10

void led_on(uint8_t led);
void led_of(uint8_t led);

void setup()
{
  pinMode(sw, INPUT_PULLUP);
  pinMode(led_, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  uint8_t rw = digitalRead(sw);
  if(rw == 0)
  {
    led_on(led_);
  }
  else
  {
    led_of(led_);
  }
}

void led_on(uint8_t led)
{
  digitalWrite(led, HIGH);
  Serial.println("Led ON\n");
}
void led_of(uint8_t led)
{
  digitalWrite(led, LOW);
  Serial.println("Led OF\n");
}
