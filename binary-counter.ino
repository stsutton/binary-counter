/*
Binary Counter

Created by Sterling Sutton on September 17th, 2023
*/

int ledPins[] = { 9, 8, 7, 6, 5, 4, 3, 2 };
int numLedPins = sizeof(ledPins) / sizeof(ledPins[0]);  // Get length of ledPins[]
int count = 0;

void setup() {
  for (int i = 0; i < numLedPins; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int lastPlaceValue = 1;
  for (int i = 0; i < numLedPins; i++) {
  int placeValue = int_pow(2, i + 1);
    
  if (count % placeValue > lastPlaceValue - 1) {
    digitalWrite(ledPins[i], HIGH);
  }
  else {
    digitalWrite(ledPins[i], LOW);
  }

  lastPlaceValue = placeValue;
  }
  delay(1000);
  count++;
}

int int_pow(int base, int exp) {
  if (exp > 0) {
    return base * int_pow(base, exp - 1);
  }
  else {
    return 1;
  }
}
