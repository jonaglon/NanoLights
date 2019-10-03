void doRainbows1() {
  SetRgbwWheelVars(slowTimey%255);
  for (int pixNum = 0; pixNum < numLeds; pixNum++) {
    setPixel(pixNum, wheelR, wheelG, wheelB, 0);
  }  
}

void doRainbows2() {
  for (int pixNum = 0; pixNum < numLeds; pixNum++) {
    SetRgbwWheelVars((vSlowTimey+pixNum)%255);
    setPixel(pixNum, wheelR, wheelG, wheelB, 0);
  }  
}

void doRainbows3() {
  // int thing = vSlowTimey%4;
  for (int pixNum = 0; pixNum < numLeds; pixNum = pixNum+2) {
    SetRgbwWheelVars((slowTimey+pixNum)%255);
    setPixel(pixNum, wheelR, wheelG, wheelB, 0);
  }  
}

