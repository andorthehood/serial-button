const int BUTTON_PIN = 2;
const int STATUS_LED_1 = 8;
const int STATUS_LED_2 = 5;
const unsigned long DEBOUNCE_DELAY = 50;

int lastButtonState = HIGH;
int buttonState = HIGH;
unsigned long lastDebounceTime = 0;
String serialInput = "";

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(STATUS_LED_1, OUTPUT);
  pinMode(STATUS_LED_2, OUTPUT);
  digitalWrite(STATUS_LED_1, LOW);
  digitalWrite(STATUS_LED_2, LOW);
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
      if (serialInput == "LED1ON") {
        digitalWrite(STATUS_LED_1, HIGH);
      } else if (serialInput == "LED1OFF") {
        digitalWrite(STATUS_LED_1, LOW);
      } else if (serialInput == "LED2ON") {
        digitalWrite(STATUS_LED_2, HIGH);
      } else if (serialInput == "LED2OFF") {
        digitalWrite(STATUS_LED_2, LOW);
      }
      serialInput = "";
    } else {
      serialInput += c;
    }
  }
}
