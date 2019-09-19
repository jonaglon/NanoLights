int fadeLength = 20000;
int myCycle = 0;

void doFades() {  

  myCycle = (timey / fadeLength)%6;

  if (myCycle == 0) {
    doFading(245,140,7,245,7,225);
  } else if (myCycle == 1) {
    doFading(245,7,225,2, 133, 142);
  } else if (myCycle == 2) {
    doFading(2, 133, 142,0,2,40);
  } else if (myCycle == 3) {
    doFading(0,2,40,82,104,2);
  } else if (myCycle == 4) {
    doFading(82,104,2,80,20,70);
  } else {
    doFading(80,20,70,150,30,0);
  }
}

void doCycles() {  

  myCycle = (timey / fadeLength)%6;
  
  if (myCycle == 0) {
    doColour(245,140,7);
  } else if (myCycle == 1) {
    doColour(245,7,225);
  } else if (myCycle == 2) {
    doColour(2, 133, 142);
  } else if (myCycle == 3) {
    doColour(0,2,40);
  } else if (myCycle == 4) {    
    doColour(82,104,2);
  } else {    
    doColour(80,20,70);
  }
}
 

void doFading(int firstR, int firstG, int firstB, int secondR, int secondG, int secondB) {
  int myTimey = timey % fadeLength;

  int newRed = firstR + ((((secondR-firstR)*10000)/fadeLength) * myTimey)/10000;
  int newGreen = firstG + ((((secondG-firstG)*10000)/fadeLength) * myTimey)/10000;
  int newBlue = firstB + ((((secondB-firstB)*10000)/fadeLength) * myTimey)/10000;

  if (testMode) {
    Serial.print("    myCycle:");
    Serial.print(myCycle);
    Serial.print("    myTimey:");
    Serial.print(myTimey);    
    Serial.print("    newRed:");
    Serial.print(newRed);    
    Serial.print("    newGreen:");
    Serial.print(newGreen);    
    Serial.print("    newBlue:");
    Serial.println(newBlue);    
  }

  for (int pixNum = 0; pixNum < numLeds; pixNum++) {
    // setLedDirect(pixNum, newRed, newGreen, newBlue, 0);
    setPixel(pixNum, newRed, newGreen, newBlue, 0);
  }
}

void doColour(byte r, byte g, byte b) {
  for (int pixNum = 0; pixNum < numLeds; pixNum++) {
    setPixel(pixNum, r, g, b, 0);
  }
}

void doColour(byte r, byte g, byte b, byte w) {
  for (int pixNum = 0; pixNum < numLeds; pixNum++) {
    setPixel(pixNum, r, g, b, w);
  }
}


