// Mohawk College - COMP-10184
//
// Light Dimmer
//
// I, Kalpa Wickramathunga (000378875), certify that this is my original work
//

#include <Arduino.h>

void setup() {
  // Configure the USB serial monitor
  Serial.begin(115200);

  // Configure pin D5 as a digital input - this is the push button
  pinMode(D5, INPUT);

  // Configure pin D4 as a digital output - this is the LED
  pinMode(D4, OUTPUT);

  // Set default PWM range
  analogWriteRange(1023);
}

int digitizedValue;

void loop() {
  digitizedValue = analogRead(A0);

  digitalWrite(D4, HIGH);

  if (digitalRead(D5) == 0) {
    for (int i = 0; i < digitizedValue; i++) {
      analogWrite(D4, digitizedValue);
    }
  } else if (digitalRead(D5) == 1) {
    digitalWrite(D4, HIGH);
  }

  delay(1);
}