unsigned long previousMillis;
unsigned long currentMillis;
unsigned long diffTime;

void saveTick() {
  previousMillis = currentMillis;
}

bool isTick() {
  currentMillis = millis();
  diffTime = currentMillis - previousMillis;
  return diffTime >= TICK_MILLIS;
}