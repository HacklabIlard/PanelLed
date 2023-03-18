//Libraries
//https://github.com/FastLED/FastLED
#include <FastLED.h>

//Constants
#define NUM_STRIPS 1
#define NUM_LEDS 100
#define BRIGHTNESS 10
#define LED_TYPE WS2812B
#define COLOR_ORDER BRG//RGB
#define FASTLED_ALLOW_INTERRUPTS 0
#define FASTLED_INTERRUPT_RETRY_COUNT 1
#define FRAMES_PER_SECOND 60
#define COOLING 55
#define SPARKING 120

//Parameters
const int stripPin  = 3;

//Objects
CRGB leds[NUM_LEDS];

int xy2i(int x, int y) {
  int i;
  if ( y % 2 == 0) {
    return i = y * 10 + x;
  } else {
    return i = (10 * (y + 1)) - 1 - x;
  }
}

int toDrawA[10][10][3]=
{
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}},
{{0, 0, 0}, {0, 0, 0}, {255, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
};


String command;

String colorArray[5];


int  l;
int cR, cG, cB;

const int NUM_ROWS = 10;
const int NUM_COLS = 10;


void displayImage(int toDraw[10][10][3]) {

  FastLED.clear();

  for ( int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      l = xy2i(x, y);
      cR = toDraw[y][x][0];
      cG = toDraw[y][x][1];
      cB = toDraw[y][x][2]; 
      leds[l].setRGB(cR, cG, cB);
    }
  }
  FastLED.show();
}

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<LED_TYPE, stripPin, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );

  FastLED.clear();   
  FastLED.show();   
}


int alpha2color(int old_value) {
  int new_value = int((old_value - 97) * (255.0 / 25.0)); 
  return new_value;
}


void loop() {
  
  while (Serial.available() == 0) {} 

  FastLED.clear();   
  FastLED.show();   

  byte buffer[300];

  Serial.readBytes(buffer, 300);


  int index = 0;
  for (int row = 0; row < NUM_ROWS; row++) {
    for (int col = 0; col < NUM_COLS; col++) {
      int r = buffer[index++];
      int v = buffer[index++];
      int b = buffer[index++];

      int l = xy2i(col, row);
      leds[l] = CRGB( r, b, v);

    }
  }
  FastLED.show();  

  
}
