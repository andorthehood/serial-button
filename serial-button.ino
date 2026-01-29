const int BUTTON_PIN = 2;
const unsigned long DEBOUNCE_DELAY = 50;

int lastButtonState = HIGH;
int buttonState = HIGH;
unsigned long lastDebounceTime = 0;
String serialInput = "";

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == LOW) {
        Serial.println("DOWN");
      } else {
        Serial.println("UP");
      }
    }
  }

  lastButtonState = reading;

  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n' || c == '\r') {
      if (serialInput == "ON") {
        digitalWrite(LED_BUILTIN, HIGH);
      } else if (serialInput == "OFF") {
        digitalWrite(LED_BUILTIN, LOW);
      }
      serialInput = "";
    } else {
      serialInput += c;
    }
  }
}
