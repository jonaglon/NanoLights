#include <Adafruit_NeoPixel.h>

#define PIN      4

unsigned long timey;
int cycle, animLength, slowTime;
const int numLeds = 144;
byte currentPattern = 5;

const bool testMode = false;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, PIN, NEO_GRBW + NEO_KHZ800);

// JR TODO - some stuffs to do next

// Find out why twinkles are flashing, suspect overflow 32768 soemwheere in twinkle codez
// Fades
// Sort ouf twinkle settings so the 6 patters are killer
// Rainbos. Man if you could find that signey rainbow that'd be killer]



void setup() {
  pinMode(6, INPUT);
  digitalWrite(6, HIGH);
  cycle=0;
  animLength=32768; 
  strip.begin();
  strip.setBrightness(3);
  setupNewTwinklePattern(currentPattern);
  if (testMode) {
    Serial.begin(9600);
  }
}
 
void loop() {
  setTimes();
  allOff();
  checkButton();
  doLights();
  //allOn(0, 0, 0, 255);
  //doFades();
  strip.show();
}


void setTimes() {
  timey = millis();
  slowTime = timey / 100;
  cycle = timey / animLength;

}

void doLights() {
  doTwinkles();
  //doKingtRiderLights();
}

bool buttonPressed = false;
void checkButton() {
  int buttonState = digitalRead(6);
  if (buttonState==0 && buttonPressed==false) {
    buttonPressed = true;
    currentPattern=(currentPattern+1)%7;
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

  twinkle() : ledNum(0), rCol(0), gCol(0), bCol(0), start(0), lengthy(0), widthy(0), fadeIn(0), fadeOut(0), speedy(0), sideFade(0), hasTwinked(0) { }

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

/*int sineWaveLUT[50] = {
72,72,72,73,73,74,74,75,75,75,
76,76,77,77,78,78,79,79,79,80,
80,81,81,82,82,82,83,83,84,84,
85,85,85,86,86,87,87,88,88,88,
89,89,90,90,91,91,91,92,92,93 );   */

const byte sineWaveLUT[512] = {
72,72,72,73,73,74,74,75,75,75,
76,76,77,77,78,78,79,79,79,80,
80,81,81,82,82,82,83,83,84,84,
85,85,85,86,86,87,87,88,88,88,
89,89,90,90,91,91,91,92,92,93,
93,94,94,94,95,95,96,96,96,97,
97,98,98,98,99,99,100,100,101,101,
101,102,102,102,103,103,104,104,104,105,
105,106,106,106,107,107,108,108,108,109,
109,109,110,110,111,111,111,112,112,112,
113,113,113,114,114,114,115,115,116,116,
116,117,117,117,118,118,118,119,119,119,
120,120,120,121,121,121,121,122,122,122,
123,123,123,124,124,124,125,125,125,125,
126,126,126,127,127,127,127,128,128,128,
128,129,129,129,129,130,130,130,130,131,
131,131,131,132,132,132,132,133,133,133,
133,134,134,134,134,134,135,135,135,135,
135,136,136,136,136,136,137,137,137,137,
137,137,138,138,138,138,138,138,139,139,
139,139,139,139,139,140,140,140,140,140,
140,140,140,141,141,141,141,141,141,141,
141,141,141,142,142,142,142,142,142,142,
142,142,142,142,142,142,142,143,143,143,
143,143,143,143,143,143,143,143,143,143,
143,143,143,143,143,143,143,143,143,143,
143,143,143,143,143,143,143,143,143,143,
143,143,143,143,143,143,142,142,142,142,
142,142,142,142,142,142,142,142,142,142,
141,141,141,141,141,141,141,141,141,140,
140,140,140,140,140,140,140,139,139,139,
139,139,139,139,138,138,138,138,138,138,
138,137,137,137,137,137,136,136,136,136,
136,135,135,135,135,135,134,134,134,134,
134,133,133,133,133,133,132,132,132,132,
131,131,131,131,130,130,130,130,129,129,
129,129,128,128,128,127,127,127,127,126,
126,126,126,125,125,125,124,124,124,123,
123,123,123,122,122,122,121,121,121,120,
120,120,119,119,119,118,118,118,117,117,
117,116,116,116,115,115,115,114,114,114,
113,113,113,112,112,111,111,111,110,110,
110,109,109,108,108,108,107,107,107,106,
106,105,105,105,104,104,103,103,103,102,
102,102,101,101,100,100,99,99,99,98,
98,97,97,97,96,96,95,95,95,94,
94,93,93,92,92,92,91,91,90,90,
90,89,89,88,88,87,87,87,86,86,
85,85,84,84,84,83,83,82,82,81,
81,80,80,80,79,79,78,78,77,77,
77,76,76,75,75,74,74,73,73,73,
72, 72 };

