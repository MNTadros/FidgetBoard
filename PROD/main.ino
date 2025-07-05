int BUT1 = 0;
int BUT2 = 1;
int BUT3 = 2;

int LED1 = 3;
int LED2 = 4;
int LED3 = 5;
int LED4 = 10;
int LED5 = 9;
int LED6 = 8;

int fadeValue = 0;
int fadeAmount = 5;
unsigned long previousMillis = 0;
const long interval = 30;

void setup()
{
  // All of the Cherry MX Switches are inputs
  pinMode(BUT1, INPUT);
  pinMode(BUT2, INPUT);
  pinMode(BUT3, INPUT);

  // All of the LEDs are outputs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
}

void loop()
{
  bool b1 = digitalRead(BUT1);
  bool b2 = digitalRead(BUT2);
  bool b3 = digitalRead(BUT3);

  if (b1)
  {
    // BUTTON 1: All LEDs ON
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, HIGH);
  }
  else if (b2)
  {
    // BUTTON 2: Cycle LEDs 1-3 ON, 4-6 OFF and toggle on interval
    static unsigned long lastToggle = 0;
    static bool state = false;
    if (millis() - lastToggle >= 500)
    {
      lastToggle = millis();
      state = !state;
      digitalWrite(LED1, state);
      digitalWrite(LED2, state);
      digitalWrite(LED3, state);
      digitalWrite(LED4, !state);
      digitalWrite(LED5, !state);
      digitalWrite(LED6, !state);
    }
  }
  else if (b3)
  {
    // BUTTON 3: Alternate LED pattern toggle
    static unsigned long lastToggle = 0;
    static bool state = false;
    if (millis() - lastToggle >= 500)
    {
      lastToggle = millis();
      state = !state;
      digitalWrite(LED1, state);
      digitalWrite(LED2, !state);
      digitalWrite(LED3, state);
      digitalWrite(LED4, !state);
      digitalWrite(LED5, state);
      digitalWrite(LED6, state);
    }
  }
  else
  {
    // DEFAULT: All LEDs fade in and out together
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
      previousMillis = currentMillis;
      analogWrite(LED1, fadeValue);
      analogWrite(LED2, fadeValue);
      analogWrite(LED3, fadeValue);
      analogWrite(LED4, fadeValue);
      analogWrite(LED5, fadeValue);
      analogWrite(LED6, fadeValue);

      fadeValue += fadeAmount;
      if (fadeValue <= 0 || fadeValue >= 255)
      {
        fadeAmount = -fadeAmount;
      }
    }
  }
}
