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
    setPixel(j, 0, 0, 0, 0);
  }
}


void allOn(byte r, byte g, byte b, byte w) {
  for(int j = 0; j < strip.numPixels(); j++) {
    setPixel(j, r, g, b, w);
  }
}


int quickAbsolute(int number) {
  if (number < 0)
    return number * (-1);
  else
    return number;
}

void setPixel(byte pixNum, byte r, byte g, byte b, byte w) {
  r = r < 0 ? 0 : r;
  g = g < 0 ? 0 : g;
  b = b < 0 ? 0 : b;
  w = w < 0 ? 0 : w;

  r = r > 255 ? 255 : r;
  g = g > 255 ? 255 : g;
  b = b > 255 ? 255 : b;
  w = w > 255 ? 255 : w;

  strip.setPixelColor(pixNum, r, g, b, w);
}

