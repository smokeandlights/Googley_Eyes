#include <WEMOS_Matrix_LED.h> //https://github.com/wemos/WEMOS_Matrix_LED_Shield_Arduino_Library

MLED mled(8); //set intensity

void setup() {
}

void loop() {
  int pupilXpos = random(1, 6); //pupil position. I want to map this to a joystick or other control later
  int pupilYpos = random(1, 6);

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

  delay(500);

}
