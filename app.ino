#include <ESP32Time.h>

#include "./config/relesConfig.h"
#include "./config/thingProperties.h"
#include "./constants/global.h"
#include "./models/rele.h"
#include "./utils/reles.h"
#include "./utils/tick.h"

ESP32Time rtc(3600);

void setup() {
  Serial.begin(9600);

  delay(2000);
  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(4);  // Nivel de logs 0 - 4
  ArduinoCloud.printDebugInfo();

  pinMode(RELE_ONE_PIN, OUTPUT);
  pinMode(RELE_TWO_PIN, OUTPUT);
  pinMode(RELE_THREE_PIN, OUTPUT);
  pinMode(RELE_FOUR_PIN, OUTPUT);
  pinMode(RELE_FIVE_PIN, OUTPUT);
  pinMode(RELE_SEVEN_PIN, OUTPUT);
  pinMode(RELE_EIGHT_PIN, OUTPUT);

  rtc.setTime(0, 13, 13, 13, 1, 2000);
}

void loop() {
  ArduinoCloud.update();

  if (isTick(rtc)) {
    checkRelesStatus(getDiff());

    if (ArduinoCloud.connected()) {
      uploadRelesState();
      uploadRelesMinutes();
    }

    Serial.print("- Tick: ");
    Serial.println(getDiff());

    saveTick();
  }
}
