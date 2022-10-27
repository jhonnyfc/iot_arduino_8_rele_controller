#include <ESP32Time.h>

ESP32Time rtc;

int previousSeconds = 0;
int currentSeconds;
int diffTime;

void saveTick() {
  previousSeconds = currentSeconds;
}

bool isTick() {
  currentSeconds = rtc.getSecond();
  diffTime = currentSeconds - previousSeconds;

  if (diffTime < ZERO_SECONDS) {
    diffTime = ONE_MINUTE_SECONDS + diffTime;
  }

  return diffTime >= ONE_SECOND;
}