void doKingtRiderLights() {
  int thing = slowTime % 50;
  int theLed = sineWaveLUT[thing];

  if (testMode) {
    Serial.print("thing:");
    Serial.print(thing);
    Serial.print("   theLed:");
    Serial.println(theLed);
  }
  
  setPixel(theLed, 255, 0, 0, 0);
}

