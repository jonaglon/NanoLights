void changeLightPattern(int newPatternNum) {

  if (newPatternNum == 0) {
    setupNewTwinklePattern(0);
  } else if (newPatternNum == 1) {
    setupNewTwinklePattern(1);
  } else if (newPatternNum == 2) {
    setupNewTwinklePattern(2);
  } else if (newPatternNum == 3) {
    setupNewTwinklePattern(3);
  } else if (newPatternNum == 4) {
    setupNewTwinklePattern(4);
  } else if (newPatternNum == 5) {
    setupNewTwinklePattern(5);
  } else if (newPatternNum == 6) {
    setupNewTwinklePattern(6);
  }
}


void allOff() {
  for(int j = 0; j < strip.numPixels(); j++) {
    strip.setPixelColor(j, 0, 0, 0, 0);
  }
}
