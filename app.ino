#include "./config/relesconfig.h"
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
  pinMode(RELE_EIGHT_PIN, OUTPUT);
}

void loop() {
  ArduinoCloud.update();

  if (isTick()) {
    releOne.checkStatus();
    releTwo.checkStatus();
    releThree.checkStatus();
    releFour.checkStatus();
    releFive.checkStatus();
    releEight.checkStatus();

    isRele01CloseRM = releOne.getIsClose();
    isRele02CloseRM = releTwo.getIsClose();
    isRele03CloseRM = releThree.getIsClose();
    isRele04CloseRM = releFour.getIsClose();
    isRele05CloseRM = releFive.getIsClose();
    isRele08CloseRM = releEight.getIsClose();

    saveTick();
  }
}
