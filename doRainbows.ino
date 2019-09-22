void doRainbows1 {
  for (int pixNum = 0; pixNum < numLeds; pixNum++) {
    SetRgbwWheelVars(slowTimey%255);
    setPixel(pixNum, wheelR, wheelG, wheelB, 0);
  }  
}

void doRainbows2 {
  int addNumber = 2;
  for (int pixNum = 0; pixNum < numLeds; pixNum++) {
    SetRgbwWheelVars(slowTimey%255);
    setPixel(pixNum, (wheelR+(pixNum*addNumber))%255, (wheelG+(pixNum*addNumber))%255, (wheelB+(pixNum*addNumber))%255, 0);
  }  
}

