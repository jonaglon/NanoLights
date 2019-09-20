void doKingtRiderLights() {
  int thing = (timey/10) % 200;
  int theLed = sineWaveLUT[thing];

  if (testMode) {
    Serial.print("thing:");
    Serial.print(thing);
    Serial.print("   theLed:");
    Serial.println(theLed);
  }
  
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

