#include "./config/relesConfig.h"
#include "./config/thingProperties.h"
#include "./constants/global.h"
#include "./models/rele.h"
#include "./utils/reles.h"
#include "./utils/tick.h"

void setup() {
  Serial.begin(9600);

  delay(2000);
  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(0);  // Nivel de logs 0 - 4
  ArduinoCloud.printDebugInfo();

  pinMode(RELE_ONE_PIN, OUTPUT);
  pinMode(RELE_TWO_PIN, OUTPUT);
  pinMode(RELE_THREE_PIN, OUTPUT);
  pinMode(RELE_FOUR_PIN, OUTPUT);
  pinMode(RELE_FIVE_PIN, OUTPUT);
  pinMode(RELE_SEVEN_PIN, OUTPUT);
  pinMode(RELE_EIGHT_PIN, OUTPUT);

  rtc.setTime(0, 13, 13, 13, 12, 2000);
}

void loop() {
  ArduinoCloud.update();

  if (isTick()) {
    releOne.checkStatus(diffTime);
    releTwo.checkStatus(diffTime);
    releThree.checkStatus(diffTime);
    releFour.checkStatus(diffTime);
    releFive.checkStatus(diffTime);
    releEight.checkStatus(diffTime);

    uploadRelesState();
    uploadRelesMinutes();

    saveTick();
  }
}
