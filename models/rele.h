int seconds2Minutes(unsigned int seconds) {
  return seconds / ONE_MINUTE_SECONDS;
}

class Rele {
 private:
  byte relePin;
  int closeMinutes;
  int openMinutes;

  bool isClose;
  int currentStateMinutes;
  unsigned int currentStateSecs;

  bool isFirstCurrentStateMinutesUpdate;

 public:
  Rele(byte relePin, int closeMinutes, int openMinutes) {
    this->relePin = relePin;
    this->closeMinutes = closeMinutes;
    this->openMinutes = openMinutes;
    this->openRele();
    this->isFirstCurrentStateMinutesUpdate = true;
  }

  void initTimers() {
    currentStateSecs = 0;
    currentStateMinutes = 0;
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

  void checkStatus(int diffTime) {
    currentStateSecs += diffTime;
    currentStateMinutes = seconds2Minutes(currentStateSecs);

    if (isClose) {
      if (currentStateMinutes >= closeMinutes) {
        openRele();
      }
    } else {
      if (currentStateMinutes >= openMinutes) {
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

  int getCurrentStateMinutes() {
    return currentStateMinutes;
  }

  void setCurrentStateMinutes(int currentStateMinutes) {
    if (isFirstCurrentStateMinutesUpdate) {
      this->currentStateMinutes = currentStateMinutes;
      this->currentStateSecs = this->currentStateMinutes * ONE_MINUTE_SECONDS;
      this->isFirstCurrentStateMinutesUpdate = false;
    }
  }
};
