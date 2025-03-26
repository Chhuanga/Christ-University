#include "PlutoPilot.h"
#include <stdlib.h>
#include <time.h>
Interval Timer1;
int32_t Direction;
int32_t count;
int32_t mathRandomInt(int32_t a, int32_t b) {
  if (a > b) {
    // Swap a and b to ensure a is smaller.
    int32_t c = a;
    a = b;
    b = c;
  }
  return (rand() % b + a);
}
  void onLoopStartAutoInsertion() {
    Timer1.reset();
    LED.flightStatus(DEACTIVATE);
  }
  void onLoopStopAutoInsertion() {
    LED.flightStatus(ACTIVATE);
  }
  void plutoInit() {
    setUserLoopFrequency(100);
    srand(time(NULL)); // Initialize random seed
  }
  void onLoopStart () {
    onLoopStartAutoInsertion();
    Command.takeOff(100);
    Timer1.set(2000,true);
    count = 1;
  }
  void plutoLoop () {
    if (Timer1.check() && count < 4) {
      Direction = mathRandomInt(1, 8);

      // Set yaw angle based on direction (45° increments)
      int32_t yawAngle = (Direction - 1) * 45;
      DesiredAngle.set(AG_YAW, yawAngle);

      // Set LED pattern based on direction
      switch(Direction) {
        case 1: // N - 0°
          LED.set(RED, ON);
          LED.set(GREEN, ON);
          LED.set(BLUE, ON);
          break;
        case 2: // NE - 45°
          LED.set(RED, ON);
          LED.set(GREEN, ON);
          LED.set(BLUE, OFF);
          break;
        case 3: // E - 90°
          LED.set(RED, ON);
          LED.set(GREEN, OFF);
          LED.set(BLUE, OFF);
          break;
        case 4: // SE - 135°
          LED.set(RED, ON);
          LED.set(GREEN, OFF);
          LED.set(BLUE, ON);
          break;
        case 5: // S - 180°
          LED.set(RED, OFF);
          LED.set(GREEN, ON);
          LED.set(BLUE, OFF);
          break;
        case 6: // SW - 225°
          LED.set(RED, OFF);
          LED.set(GREEN, ON);
          LED.set(BLUE, ON);
          break;
        case 7: // W - 270°
          LED.set(RED, OFF);
          LED.set(GREEN, OFF);
          LED.set(BLUE, ON);
          break;
        case 8: // NW - 315°
          LED.set(RED, TOGGLE);
          LED.set(GREEN, TOGGLE);
          LED.set(BLUE, TOGGLE);
          break;
      }

      // Increment count only once per movement sequence
      if (Direction == 8) {
        count = (count + 1);
      }
    } else if (count >= 4) {
      Command.land(100);
      LED.set(RED, TOGGLE);
      LED.set(GREEN, TOGGLE);
      LED.set(BLUE, ON);
    }
  }
  void onLoopFinish() {
    onLoopStopAutoInsertion();
  }
