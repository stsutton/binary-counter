/*
Binary Counter

Created by Sterling Sutton on September 17th, 2023
*/

int ledPins[] = { 53, 52, 51, 50, 49, 48, 47, 46, 29, 28, 27, 26, 25, 24, 23, 22 };
int numLedPins = sizeof(ledPins) / sizeof(ledPins[0]);  // Get length of ledPins[]
int count = 0;

void setup() {
  for (int i = 0; i < numLedPins; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  long lastPlaceValue = 1;
  for (int i = 0; i < numLedPins; i++) {
  long placeValue = long_int_pow(2, i + 1);
    
  if (count % placeValue > lastPlaceValue - 1) {
    digitalWrite(ledPins[i], HIGH);
  }
  else {
    digitalWrite(ledPins[i], LOW);
  }

  lastPlaceValue = placeValue;
  }
  delay(10);
  count++;
}

long long_int_pow(int base, int exp) {
  if (exp > 0) {
    return base * long_int_pow(base, exp - 1);
  }
  else {
    return 1;
  }
}
