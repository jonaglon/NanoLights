void doRainbows1() {
  SetRgbwWheelVars(slowTimey%255);
  for (int pixNum = 0; pixNum < numLeds; pixNum++) {
    setPixel(pixNum, wheelR, wheelG, wheelB);
  }  
}

void doRainbows2() {
  for (int pixNum = 0; pixNum < numLeds; pixNum++) {
    SetRgbwWheelVars((slowTimey+pixNum)%255);
    setPixel(pixNum, wheelR, wheelG, wheelB);
  }  
}

void doRainbows3() {
  for (int pixNum = 0; pixNum < numLeds; pixNum = pixNum+2) {
    SetRgbwWheelVars((slowTimey+pixNum)%255);
    setPixel(pixNum, wheelR, wheelG, wheelB);
  }  
}

// do a 20 rainbow strip moving along the strip
void doRainbows4() {
  int ledAdd = vSlowTimey%numLeds;
  for (int pixNum = 0; pixNum < 20; pixNum++) {
    SetRgbwWheelVars((slowTimey+pixNum)%255);
    setPixel((pixNum+ledAdd)%numLeds, wheelR, wheelG, wheelB);
    setPixel((pixNum+ledAdd+36)%numLeds, wheelR, wheelG, wheelB);
    setPixel((pixNum+ledAdd+72)%numLeds, wheelR, wheelG, wheelB);
    setPixel((pixNum+ledAdd+108)%numLeds, wheelR, wheelG, wheelB);
  }  
  for (int pixNum = 0; pixNum < numLeds; pixNum = pixNum+2) {
    SetRgbwWheelVars((slowTimey+pixNum)%255);
    setPixel(pixNum, wheelR, wheelG, wheelB);
  }  
}
