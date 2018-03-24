const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  13;       // the number of the LED pin
int buttonState = 0;          // variable for reading the pushbutton status

// ================= SETUP =================
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

// ================ LOOP ===================
void loop() {

  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);       // turn LED on:
  }
  else {
    digitalWrite(ledPin, LOW);        // turn LED off:
  }
}
