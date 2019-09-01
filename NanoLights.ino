#include <Adafruit_NeoPixel.h>

#define PIN      4
#define N_LEDS 144

int timey, cycle, animLength;
byte currentTwinklePattern = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRBW + NEO_KHZ800);
 
void setup() {
  pinMode(6, INPUT);
  digitalWrite(6, HIGH);
  
  cycle=0;
  animLength=16384; 
  strip.begin();

  setupNewTwinklePattern(currentTwinklePattern);
}
 
void loop() {
  setTimes();
  allOff();
  checkButton();
  doLights();
  strip.show();
}

void doLights() {
  doTwinkles();
}

bool buttonPressed = false;
void checkButton() {
  int buttonState = digitalRead(6);
  if (buttonState==0 && buttonPressed==false) {
    buttonPressed = true;
    currentTwinklePattern=(currentTwinklePattern+1)%7;
    setupNewTwinklePattern(currentTwinklePattern);
  } else if (buttonState!=0 && buttonPressed==true) {
    buttonPressed = false;    
  }
}

int quickAbsolute(int number) {
  if (number < 0)
    return number * (-1);
  else
    return number;
}

 
static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      // strip.setPixelColor(i  , c); // Draw new pixel
      // strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.setPixelColor(i  , 0, 0, 0, 255); // Draw new pixel
      strip.setPixelColor(i-4, 0, 0, 0); // Erase pixel a few steps back
      strip.show();
      delay(25);
  }
}

void setTimes() {
  timey = millis();
  cycle = timey / animLength;
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
