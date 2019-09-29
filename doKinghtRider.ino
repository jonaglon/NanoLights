void doKingtRiderLights() {
  int thing = (timey/10) % 200;
  int theLed = sineWaveLUT[thing];

  setPixel(theLed-11, 2, 0, 0, 0);
  setPixel(theLed-10, 10, 0, 0, 0);
  setPixel(theLed-9, 20, 0, 0, 0);
  setPixel(theLed-8, 40, 0, 0, 0);
  setPixel(theLed-7, 60, 0, 0, 0);
  setPixel(theLed-6, 90, 0, 0, 0);
  setPixel(theLed-5, 130, 0, 0, 0);
  setPixel(theLed-4, 180, 0, 0, 0);
  setPixel(theLed-3, 210, 0, 0, 0);
  setPixel(theLed-2, 255, 0, 0, 0);
  setPixel(theLed-1, 255, 0, 0, 0);
  setPixel(theLed, 255, 0, 0, 0);
  setPixel(theLed+1, 255, 0, 0, 0);
  setPixel(theLed+2, 255, 0, 0, 0);
  setPixel(theLed+3, 210, 0, 0, 0);
  setPixel(theLed+4, 180, 0, 0, 0);
  setPixel(theLed+5, 130, 0, 0, 0);
  setPixel(theLed+6, 90, 0, 0, 0);
  setPixel(theLed+7, 60, 0, 0, 0);
  setPixel(theLed+8, 40, 0, 0, 0);
  setPixel(theLed+9, 20, 0, 0, 0);
  setPixel(theLed+10, 10, 0, 0, 0);
  setPixel(theLed+11, 2, 0, 0, 0);
}

void doKingtRiderLightsRainbow1() {
  int sinLookupTablePos = slowTimey % 200;
  int theLed = sineWaveLUT[sinLookupTablePos];

  SetRgbwWheelVars(slowTimey%255);

  setPixel(theLed-11, 2, wheelR, wheelG, wheelB);
  setPixel(theLed-10, 10, wheelR, wheelG, wheelB);
  setPixel(theLed-9, 20, wheelR, wheelG, wheelB);
  setPixel(theLed-8, 40, wheelR, wheelG, wheelB);
  setPixel(theLed-7, 60, wheelR, wheelG, wheelB);
  setPixel(theLed-6, 90, wheelR, wheelG, wheelB);
  setPixel(theLed-5, 130, wheelR, wheelG, wheelB);
  setPixel(theLed-4, 180, wheelR, wheelG, wheelB);
  setPixel(theLed-3, 210, wheelR, wheelG, wheelB);
  setPixel(theLed-2, 255, wheelR, wheelG, wheelB);
  setPixel(theLed-1, 255, wheelR, wheelG, wheelB);
  setPixel(theLed, 255, wheelR, wheelG, wheelB);
  setPixel(theLed+1, 255, wheelR, wheelG, wheelB);
  setPixel(theLed+2, 255, wheelR, wheelG, wheelB);
  setPixel(theLed+3, 210, wheelR, wheelG, wheelB);
  setPixel(theLed+4, 180, wheelR, wheelG, wheelB);
  setPixel(theLed+5, 130, wheelR, wheelG, wheelB);
  setPixel(theLed+6, 90, wheelR, wheelG, wheelB);
  setPixel(theLed+7, 60, wheelR, wheelG, wheelB);
  setPixel(theLed+8, 40, wheelR, wheelG, wheelB);
  setPixel(theLed+9, 20, wheelR, wheelG, wheelB);
  setPixel(theLed+10, 10, wheelR, wheelG, wheelB);
  setPixel(theLed+11, 2, wheelR, wheelG, wheelB);
}

void doKingtRiderLightsRainbow2() {
  int slowishTimey = timey/5;
  int sinLookupTablePos = slowishTimey % 200;
  int theLed = sineWaveLUT[sinLookupTablePos];

  SetRgbwWheelVars((slowishTimey+0)%255);
  setPixel(theLed-11, 2, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+10)%255);
  setPixel(theLed-10, 10, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+20)%255);
  setPixel(theLed-9, 20, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+30)%255);
  setPixel(theLed-8, 40, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+40)%255);
  setPixel(theLed-7, 60, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+50)%255);
  setPixel(theLed-6, 90, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+60)%255);
  setPixel(theLed-5, 130, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+70)%255);
  setPixel(theLed-4, 180, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+80)%255);
  setPixel(theLed-3, 210, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+90)%255);
  setPixel(theLed-2, 255, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+100)%255);
  setPixel(theLed-1, 255, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+110)%255);
  setPixel(theLed, 255, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+120)%255);
  setPixel(theLed+1, 255, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+130)%255);
  setPixel(theLed+2, 255, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+140)%255);
  setPixel(theLed+3, 210, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+150)%255);
  setPixel(theLed+4, 180, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+160)%255);
  setPixel(theLed+5, 130, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+170)%255);
  setPixel(theLed+6, 90, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+180)%255);
  setPixel(theLed+7, 60, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+190)%255);
  setPixel(theLed+8, 40, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+200)%255);
  setPixel(theLed+9, 20, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+210)%255);
  setPixel(theLed+10, 10, wheelR, wheelG, wheelB);
  SetRgbwWheelVars((slowishTimey+220)%255);
  setPixel(theLed+11, 2, wheelR, wheelG, wheelB);
}

