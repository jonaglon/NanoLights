#include <Adafruit_NeoPixel.h>

#include <Adafruit_NeoPixel.h>

#define PIN      4

unsigned long timey, slowTimey;
int cycle, animLength, slowTime;
const int numLeds = 144;
byte currentPattern = 0;
byte numPatterns = 14;
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
// re tryFades using longs and see what happens
// FIx twinkle colour thing - why twinkles flash?, suspect overflow 32768 soemwheere in twinkle codez, long could sort?
// Revisit the rainbows, they aint working proper I dont fink
//****Hope you really did find tht grreat one and make that owrk.
// Sort ouf twinkle settings so the 6 patters are killer



void setup() {
  pinMode(6, INPUT);
  digitalWrite(6, HIGH);
  cycle=0;
  animLength=32768; 
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

  if (currentPattern < 2) {
    doRainbows2();
  } else if (currentPattern < 8) {
    doTwinkles();
  } else if (currentPattern < 9) {
    doFades();
  } else if (currentPattern < 10) {
    doKingtRiderLights();
  } else if (currentPattern < 11) {
    doKingtRiderLightsRainbow1();
  } else if (currentPattern < 12) {
    doRainbows1();
  } else if (currentPattern < 13) {
    doKingtRiderLightsRainbow2();
  } else if (currentPattern < 14) {
    for (int i = 0; i < numLeds; i++)
      strip.setPixelColor(i, 0, 0, 0, 0);
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
  short lengthy;
  short widthy;
  short fadeIn;
  short fadeOut;
  short speedy;
  short sideFade;
  bool hasTwinked;

  twinkle(short aLedNum, byte aRCol, byte aGCol, byte aBCol, byte aToRCol, byte aToGCol, byte aToBCol, int aStart, short aLengthy, short aWidthy, short aFadeIn, short aFadeOut, short aSpeedy, short aSideFade, bool aHasTwinked) :
    ledNum(aLedNum), rCol(aRCol), gCol(aGCol), bCol(aBCol), rToCol(aToRCol), gToCol(aToGCol), bToCol(aToBCol), start(aStart), lengthy(aLengthy), widthy(aWidthy), fadeIn(aFadeIn), fadeOut(aFadeOut), speedy(aSpeedy), sideFade(aSideFade), hasTwinked(aHasTwinked) {  }

  twinkle() : ledNum(0), rCol(0), gCol(0), bCol(0), rToCol(0), gToCol(0), bToCol(0), start(0), lengthy(0), widthy(0), fadeIn(0), fadeOut(0), speedy(0), sideFade(0), hasTwinked(0) { }

};

const int numTwinks = 40;
twinkle myTwinkles[numTwinks];
const int usedTwinkleCount[] = {40, 40, 40, 40, 40, 40, 40, 40};

const uint8_t PROGMEM gamma8[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

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

