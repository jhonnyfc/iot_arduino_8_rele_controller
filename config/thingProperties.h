#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

#include "../constants/arduino_secrets.h"

void onReleOneSwitchChange();
void onReleOneCloseMinutesChange();
void onReleOneOpenMinutesChange();

void initProperties() {
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(isRele01CloseRM, READWRITE, ON_CHANGE, onReleOneSwitchChange);
  ArduinoCloud.addProperty(RELE_01_CLOSE_MINUTES, READWRITE, ON_CHANGE, onReleOneCloseMinutesChange, 1);
  ArduinoCloud.addProperty(RELE_01_OPEN_MINUTES, READWRITE, ON_CHANGE, onReleOneOpenMinutesChange, 1);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
