#include "PlutoPilot.h"


  void onLoopStartAutoInsertion() {
    LED.flightStatus(DEACTIVATE);
  }

  void onLoopStopAutoInsertion() {
    LED.flightStatus(ACTIVATE);
  }

  void plutoInit() {
    setUserLoopFrequency(100);
  }


  void onLoopStart () {
    onLoopStartAutoInsertion();
  }

  void plutoLoop () {
    if (Angle.get(AG_YAW) >= 0 && Angle.get(AG_YAW) <= 60) {
      LED.set(GREEN,ON);
      LED.set(BLUE,ON);
      LED.set(RED,ON);
    }else if (Angle.get(AG_YAW) >= 60 && Angle.get(AG_YAW) <= 120) {
      LED.set(BLUE,ON);
      LED.set(GREEN,ON);
      LED.set(RED,OFF);
    }else if (Angle.get(AG_YAW) >= 120 && Angle.get(AG_YAW) <= 180) {
      LED.set(GREEN,ON);
      LED.set(RED,OFF);
      LED.set(BLUE,ON);
    }else if (Angle.get(AG_YAW) >= 180 && Angle.get(AG_YAW) <= 240) {
      LED.set(BLUE,OFF);
      LED.set(GREEN,ON);
      LED.set(RED,ON);
    }else if (Angle.get(AG_YAW) >= 240 && Angle.get(AG_YAW) <= 300) {
      LED.set(GREEN,ON);
      LED.set(BLUE,OFF);
      LED.set(RED,OFF);
    }else if (Angle.get(AG_YAW) >= 300 && Angle.get(AG_YAW) <= 360) {
      LED.set(BLUE,OFF);
      LED.set(GREEN,OFF);
      LED.set(RED,ON);
    }
  }

  void onLoopFinish() {
    onLoopStopAutoInsertion();
  }