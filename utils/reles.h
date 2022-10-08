#include "../config/relesconfig.h"
#include "../constants/global.h"

Rele releOne(RELE_ONE_PIN, RELE_01_CLOSE_MINUTES, RELE_01_OPEN_MINUTES);

void onReleOneSwitchChange() {
  releOne.updateStatus(isRele01CloseRM);
}

void onReleOneCloseMinutesChange() {
  releOne.setCloseMinutes(RELE_01_CLOSE_MINUTES);
}

void onReleOneOpenMinutesChange() {
  releOne.setOpenMinutes(RELE_01_OPEN_MINUTES);
}