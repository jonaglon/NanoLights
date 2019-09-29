#include <Adafruit_NeoPixel.h>
#define PIN 4

unsigned long timey, slowTimey, animLength;
int cycle;
const int numLeds = 144;
byte currentPattern = 0;
byte numPatterns = 13;
byte wheelR;
byte wheelG;
byte wheelB;

const bool testMode = false;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, PIN, NEO_GRBW + NEO_KHZ800);

// JR TODO - some stuffs to do next

//  o   Fix knightrider code for 1 Led
//  o   Make one cool kr pattern
//  o   do all patterns, kinght,fades,off,twinks
//  o   
//  o Rainbowses:
//    o Make normal adafriut rainbow work
//    o make your rainbow work
//  
// fix shit pattern
// fix when twinks all stop workking thung happens
// use the exciting pattern matyue!
// re tryFades using longs and see what happens
// FIx twinkle colour thing - why twinkles flash?, suspect overflow 32768 soemwheere in twinkle codez, long could sort?
// Revisit the rainbows, they aint working proper I dont fink
//****Hope you really did find tht grreat one and make that owrk.
// Sort ouf twinkle settings so the 6 patters are killer



void setup() {
  pinMode(6, INPUT);
  digitalWrite(6, HIGH);
  cycle=0;
  animLength=32864; // 8192; 
  strip.begin();
  strip.setBrightness(5);
  if (testMode) {
    Serial.begin(9600);
  }
}
 
void loop() {
  setTimes();
  checkButton();
  doLights();
}


void setTimes() {
  timey = millis();
  slowTimey = timey / 10;
  cycle = timey / animLength;
}

void doLights() {
  allOff();

  if (currentPattern < 1) {
    for (int i = 0; i < numLeds; i++)
      strip.setPixelColor(i, 0, 0, 0, 0);
  } else if (currentPattern < 8) {
    doTwinkles();
  } else if (currentPattern < 9) {
    doFades();
  } else if (currentPattern < 10) {
    doKingtRiderLights();
  } else if (currentPattern < 11) {
    doKingtRiderLightsRainbow1();
  } else if (currentPattern < 12) {
    doKingtRiderLightsRainbow2();
  } else if (currentPattern < 13) {
    doRainbows1();
  } else if (currentPattern < 14) {
    doRainbows2();
  }
  strip.show();
}

bool buttonPressed = false;
void checkButton() {
  int buttonState = digitalRead(6);
  if (buttonState==0 && buttonPressed==false) {
    buttonPressed = true;
    currentPattern=(currentPattern+1)%(numPatterns+1);
    setupNewTwinklePattern(currentPattern);
  } else if (buttonState!=0 && buttonPressed==true) {
    buttonPressed = false;    
  }
}

struct twinkle {
  short ledNum;
  byte rCol;
  byte gCol;
  byte bCol;
  byte rToCol;
  byte gToCol;
  byte bToCol;
  int start;
  int lengthy;
  short widthy;
  int fadeIn;
  int fadeOut;
  short speedy;
  short sideFade;
  bool hasTwinked;

  twinkle(short aLedNum, byte aRCol, byte aGCol, byte aBCol, byte aToRCol, byte aToGCol, byte aToBCol, int aStart, int aLengthy, int aWidthy, int aFadeIn, int aFadeOut, short aSpeedy, short aSideFade, bool aHasTwinked) :
    ledNum(aLedNum), rCol(aRCol), gCol(aGCol), bCol(aBCol), rToCol(aToRCol), gToCol(aToGCol), bToCol(aToBCol), start(aStart), lengthy(aLengthy), widthy(aWidthy), fadeIn(aFadeIn), fadeOut(aFadeOut), speedy(aSpeedy), sideFade(aSideFade), hasTwinked(aHasTwinked) {  }

  twinkle() : ledNum(0), rCol(0), gCol(0), bCol(0), rToCol(0), gToCol(0), bToCol(0), start(0), lengthy(0), widthy(0), fadeIn(0), fadeOut(0), speedy(0), sideFade(0), hasTwinked(0) { }

};

const int numTwinks = 45;
twinkle myTwinkles[numTwinks];
const int usedTwinkleCount[] = {45, 45, 45, 45, 45, 45, 45, 45};

const byte sineWaveLUT[200] = {
72,74,77,79,81,83,85,88,90,92,
94,96,99,101,103,105,107,109,111,112,
114,116,118,120,121,123,124,126,127,129,
130,132,133,134,135,136,137,138,139,140,
140,141,142,142,143,143,143,144,144,144,
144,144,144,144,143,143,143,142,142,141,
140,140,139,138,137,136,135,134,133,132,
130,129,127,126,124,123,121,120,118,116,
114,112,111,109,107,105,103,101,99,96,
94,92,90,88,85,83,81,79,77,74,
72,70,67,65,63,61,59,56,54,52,
50,48,45,43,41,39,37,35,33,32,
30,28,26,24,23,21,20,18,17,15,
14,12,11,10,9,8,7,6,5,4,
4,3,2,2,1,1,1,0,0,0,
0,0,0,0,1,1,1,2,2,3,
4,4,5,6,7,8,9,10,11,12,
14,15,17,18,20,21,23,24,26,28,
30,32,33,35,37,39,41,43,45,48,
50,52,54,56,59,61,63,65,67,70 };

