void doRainbows1() {
  SetRgbwWheelVars(slowTimey%255);
  for (int pixNum = 0; pixNum < numLeds; pixNum++) {
    setPixel(pixNum, wheelR, wheelG, wheelB, 0);
  }  
}

void doRainbows2() {
  for (int pixNum = 0; pixNum < numLeds; pixNum++) {
    SetRgbwWheelVars((slowTimey)%255);
    setPixel(pixNum, wheelR+pixNum, wheelG+pixNum, wheelB+pixNum, 0);
  }  
}

