#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

#include "../constants/arduino_secrets.h"

void onReleOneSwitchChange();
void onReleOneCloseMinutesChange();
void onReleOneOpenMinutesChange();

void onReleTwoSwitchChange();
void onReleTwoCloseMinutesChange();
void onReleTwoOpenMinutesChange();

void onReleThreeSwitchChange();
void onReleThreeCloseMinutesChange();
void onReleThreeOpenMinutesChange();

void onReleFourSwitchChange();
void onReleFourCloseMinutesChange();
void onReleFourOpenMinutesChange();

void onReleFiveSwitchChange();
void onReleFiveCloseMinutesChange();
void onReleFiveOpenMinutesChange();

void onReleEightSwitchChange();
void onReleEightCloseMinutesChange();
void onReleEightOpenMinutesChange();

void initProperties() {
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);

  ArduinoCloud.addProperty(isRele01CloseRM, READWRITE, ON_CHANGE, onReleOneSwitchChange);
  ArduinoCloud.addProperty(RELE_01_CLOSE_MINUTES, READWRITE, ON_CHANGE, onReleOneCloseMinutesChange, 1);
  ArduinoCloud.addProperty(RELE_01_OPEN_MINUTES, READWRITE, ON_CHANGE, onReleOneOpenMinutesChange, 1);
  ArduinoCloud.addProperty(rele01StateMinutes, READ, ON_CHANGE, NULL);

  ArduinoCloud.addProperty(isRele02CloseRM, READWRITE, ON_CHANGE, onReleTwoSwitchChange);
  ArduinoCloud.addProperty(RELE_02_CLOSE_MINUTES, READWRITE, ON_CHANGE, onReleTwoCloseMinutesChange, 1);
  ArduinoCloud.addProperty(RELE_02_OPEN_MINUTES, READWRITE, ON_CHANGE, onReleTwoOpenMinutesChange, 1);
  ArduinoCloud.addProperty(rele02StateMinutes, READ, ON_CHANGE, NULL);

  ArduinoCloud.addProperty(isRele03CloseRM, READWRITE, ON_CHANGE, onReleThreeSwitchChange);
  ArduinoCloud.addProperty(RELE_03_CLOSE_MINUTES, READWRITE, ON_CHANGE, onReleThreeCloseMinutesChange, 1);
  ArduinoCloud.addProperty(RELE_03_OPEN_MINUTES, READWRITE, ON_CHANGE, onReleThreeOpenMinutesChange, 1);
  ArduinoCloud.addProperty(rele03StateMinutes, READ, ON_CHANGE, NULL);

  ArduinoCloud.addProperty(isRele04CloseRM, READWRITE, ON_CHANGE, onReleFourSwitchChange);
  ArduinoCloud.addProperty(RELE_04_CLOSE_MINUTES, READWRITE, ON_CHANGE, onReleFourCloseMinutesChange, 1);
  ArduinoCloud.addProperty(RELE_04_OPEN_MINUTES, READWRITE, ON_CHANGE, onReleFourOpenMinutesChange, 1);
  ArduinoCloud.addProperty(rele04StateMinutes, READ, ON_CHANGE, NULL);

  ArduinoCloud.addProperty(isRele05CloseRM, READWRITE, ON_CHANGE, onReleFiveSwitchChange);
  ArduinoCloud.addProperty(RELE_05_CLOSE_MINUTES, READWRITE, ON_CHANGE, onReleFiveCloseMinutesChange, 1);
  ArduinoCloud.addProperty(RELE_05_OPEN_MINUTES, READWRITE, ON_CHANGE, onReleFiveOpenMinutesChange, 1);
  ArduinoCloud.addProperty(rele05StateMinutes, READ, ON_CHANGE, NULL);

  ArduinoCloud.addProperty(isRele08CloseRM, READWRITE, ON_CHANGE, onReleEightSwitchChange);
  ArduinoCloud.addProperty(RELE_08_CLOSE_MINUTES, READWRITE, ON_CHANGE, onReleEightCloseMinutesChange, 1);
  ArduinoCloud.addProperty(RELE_08_OPEN_MINUTES, READWRITE, ON_CHANGE, onReleEightOpenMinutesChange, 1);
  ArduinoCloud.addProperty(rele08StateMinutes, READ, ON_CHANGE, NULL);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
