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

  setDebugMessageLevel(4);  // Nivel de logs 0 - 4
  ArduinoCloud.printDebugInfo();

  pinMode(RELE_ONE_PIN, OUTPUT);
}

void loop() {
  ArduinoCloud.update();

  if (isTick()) {
    releOne.checkStatus();

    isRele01CloseRM = releOne.getIsClose();

    saveTick();
  }
}
