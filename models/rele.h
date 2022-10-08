unsigned int seconds2Minutes(unsigned int seconds) {
  return seconds / ONE_MINUTE_SECONDS;
}

class Rele {
 private:
  byte relePin;
  unsigned int closeMinutes;
  unsigned int openMinutes;

  unsigned int currentCloseSecs;
  unsigned int currentOpenSecs;
  bool isClose;

 public:
  Rele(byte relePin, int closeMinutes, int openMinutes) {
    this->relePin = relePin;
    this->closeMinutes = closeMinutes;
    this->openMinutes = openMinutes;
    openRele();
  }

  void initTimers() {
    currentCloseSecs = 0;
    currentOpenSecs = 0;
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
      if (seconds2Minutes(currentCloseSecs) >= closeMinutes) {
        openRele();
      }
    } else {
      ++currentOpenSecs;
      if (seconds2Minutes(currentOpenSecs) >= openMinutes) {
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
};
