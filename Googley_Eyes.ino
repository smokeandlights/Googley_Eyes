#include <WEMOS_Matrix_LED.h>

MLED mled(5); //set intensity=5

void setup() {
  // put your setup code here, to run once:


}

void loop() {
  int pupilXpos = 3; //pupil position. I want to map this to a joystick or other control later
  int pupilYpos = 3;

  for (int x = 2; x < 6; x++) {      //Drawing the eye ball
    for (int y = 0; y < 8; y++) {
      mled.dot(x , y);
    }
  }
  for (int y = 1; y < 7; y++) {
    mled.dot(1, y);
    mled.dot(6, y);
  }
  for (int y = 2; y < 6; y++) {
    mled.dot(0, y);
    mled.dot(7, y);
  }

  mled.dot(pupilXpos, pupilYpos, 0); //drawing the pupil
  mled.dot((pupilXpos + 1), pupilYpos, 0);
  mled.dot(pupilXpos, (pupilYpos + 1), 0);
  mled.dot((pupilXpos + 1), (pupilYpos + 1), 0);


  mled.display(); //refresh the display
}
