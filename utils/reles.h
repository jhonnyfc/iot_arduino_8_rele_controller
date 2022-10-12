#include "../config/relesConfig.h"
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

Rele releTwo(RELE_TWO_PIN, RELE_02_CLOSE_MINUTES, RELE_02_OPEN_MINUTES);

void onReleTwoSwitchChange() {
  releTwo.updateStatus(isRele02CloseRM);
}

void onReleTwoCloseMinutesChange() {
  releTwo.setCloseMinutes(RELE_02_CLOSE_MINUTES);
}

void onReleTwoOpenMinutesChange() {
  releTwo.setOpenMinutes(RELE_02_OPEN_MINUTES);
}

Rele releThree(RELE_THREE_PIN, RELE_03_CLOSE_MINUTES, RELE_03_OPEN_MINUTES);

void onReleThreeSwitchChange() {
  releThree.updateStatus(isRele03CloseRM);
}

void onReleThreeCloseMinutesChange() {
  releThree.setCloseMinutes(RELE_03_CLOSE_MINUTES);
}

void onReleThreeOpenMinutesChange() {
  releThree.setOpenMinutes(RELE_03_OPEN_MINUTES);
}

Rele releFour(RELE_FOUR_PIN, RELE_04_CLOSE_MINUTES, RELE_04_OPEN_MINUTES);

void onReleFourSwitchChange() {
  releFour.updateStatus(isRele04CloseRM);
}

void onReleFourCloseMinutesChange() {
  releFour.setCloseMinutes(RELE_04_CLOSE_MINUTES);
}

void onReleFourOpenMinutesChange() {
  releFour.setOpenMinutes(RELE_04_OPEN_MINUTES);
}

Rele releFive(RELE_FIVE_PIN, RELE_05_CLOSE_MINUTES, RELE_05_OPEN_MINUTES);

void onReleFiveSwitchChange() {
  releFive.updateStatus(isRele05CloseRM);
}

void onReleFiveCloseMinutesChange() {
  releFive.setCloseMinutes(RELE_05_CLOSE_MINUTES);
}

void onReleFiveOpenMinutesChange() {
  releFive.setOpenMinutes(RELE_05_OPEN_MINUTES);
}

Rele releEight(RELE_EIGHT_PIN, RELE_08_CLOSE_MINUTES, RELE_08_OPEN_MINUTES);

void onReleEightSwitchChange() {
  releEight.updateStatus(isRele08CloseRM);
}

void onReleEightCloseMinutesChange() {
  releEight.setCloseMinutes(RELE_08_CLOSE_MINUTES);
}

void onReleEightOpenMinutesChange() {
  releEight.setOpenMinutes(RELE_08_OPEN_MINUTES);
}