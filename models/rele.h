int seconds2Minutes(unsigned int seconds) {
  return seconds / ONE_MINUTE_SECONDS;
}

class Rele {
 private:
  byte relePin;
  int closeMinutes;
  int openMinutes;

  unsigned int currentCloseSecs;
  unsigned int currentOpenSecs;
  bool isClose;
  int stateMinutes;

 public:
  Rele(byte relePin, int closeMinutes, int openMinutes) {
    this->relePin = relePin;
    this->closeMinutes = closeMinutes;
    this->openMinutes = openMinutes;
    closeRele();
  }

  void initTimers() {
    currentCloseSecs = 0;
    currentOpenSecs = 0;
    stateMinutes = 0;
  }

  void closeRele() {
    isClose = true;
    initTimers();
    digitalWrite(relePin, CLOSE_SWITCH);
  }

  void openRele() {
    isClose = false;
    initTimers();
    digitalWrite(relePin, OPEN_SWITCH);
  }

  void checkStatus() {
    if (isClose) {
      ++currentCloseSecs;
      stateMinutes = seconds2Minutes(currentCloseSecs);
      if (stateMinutes >= closeMinutes) {
        openRele();
      }
    } else {
      ++currentOpenSecs;
      stateMinutes = seconds2Minutes(currentOpenSecs);
      if (stateMinutes >= openMinutes) {
        closeRele();
      }
    }
  }

  void updateStatus(bool isClose) {
    if (isClose) {
      closeRele();
    } else {
      openRele();
    }
  }

  bool getIsClose() {
    return isClose;
  }

  void setCloseMinutes(int closeMinutes) {
    this->closeMinutes = closeMinutes;
  }

  void setOpenMinutes(int openMinutes) {
    this->openMinutes = openMinutes;
  }

  int getStateMinutes() {
    return stateMinutes;
  }
};
