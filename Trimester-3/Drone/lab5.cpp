#include "PlutoPilot.h"

int32_t Bias_error;
int32_t Pluto_Heading;


  void onLoopStartAutoInsertion() {
  }

  void onLoopStopAutoInsertion() {
  }

  void plutoInit() {
    setUserLoopFrequency(100);
  }


  void onLoopStart () {
    onLoopStartAutoInsertion();
    Bias_error = (App.getAppHeading() - Angle.get(AG_YAW));
  }

  void plutoLoop () {
    Pluto_Heading = (App.getAppHeading() - Bias_error);
    if (Pluto_Heading < 0) {
      Pluto_Heading = (Pluto_Heading + 360);
    }
    DesiredAngle.set(AG_YAW, Pluto_Heading);
  }

  void onLoopFinish() {
    onLoopStopAutoInsertion();
  }