//Libraries
#include <FastLED.h>//https://github.com/FastLED/FastLED

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

//Variables
bool gReverseDirection  = true;

//Objects
CRGB leds[NUM_LEDS];

const int toDraw[10][10][3]=
{
{{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
{{255, 255, 255}, {255, 255, 255}, {0, 216, 13}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {6, 0, 216}, {255, 255, 255}, {255, 255, 255}},
{{255, 255, 255}, {255, 255, 255}, {0, 216, 13}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {6, 0, 216}, {255, 255, 255}, {255, 255, 255}},
{{255, 255, 255}, {255, 255, 255}, {0, 216, 13}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {6, 0, 216}, {255, 255, 255}, {255, 255, 255}},
{{255, 255, 255}, {255, 255, 255}, {0, 216, 13}, {216, 45, 0}, {216, 45, 0}, {216, 45, 0}, {216, 45, 0}, {6, 0, 216}, {255, 255, 255}, {255, 255, 255}},
{{255, 255, 255}, {255, 255, 255}, {0, 216, 13}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {6, 0, 216}, {255, 255, 255}, {255, 255, 255}},
{{255, 255, 255}, {255, 255, 255}, {0, 216, 13}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {6, 0, 216}, {255, 255, 255}, {255, 255, 255}},
{{255, 255, 255}, {255, 255, 255}, {0, 216, 13}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {6, 0, 216}, {255, 255, 255}, {255, 255, 255}},
{{255, 255, 255}, {255, 255, 255}, {0, 216, 13}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {6, 0, 216}, {255, 255, 255}, {255, 255, 255}},
{{255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}, {255, 255, 255}},
};

// int corresArray[10][10]=
// {
//   {0,1,2,3,4,5,6,7,8,9},
//   {19,18,17,16,15,14,13,12,11,10},
//   {20,21,22,23,24,25,26,27,28,29},
//   {39,38,37,36,35,34,33,32,31,30},
//   {40,41,42,43,44,45,46,47,48,49},
//   {59,58,57,56,55,54,53,52,51,50},
//   {60,61,62,63,64,65,66,67,68,69},
//   {79,78,77,76,75,74,73,72,71,70},
//   {80,81,82,83,84,85,86,87,88,89},
//   {99,98,97,96,95,94,93,92,91,90},
// };
  
int ** generateCorresArray(int width, int height) {
    int **corresArray;
    corresArray = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        corresArray[i] = (int *)malloc(width * sizeof(int));
    }
    
    int row, col, value = 0;

    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
            if (row % 2 == 0) {
                // if row is even, count up
                corresArray[row][col] = value++;
            } else {
                // if row is odd, count down
                corresArray[row][width-1-col] = value++;
            }
        }
    }
    return corresArray;
}
int width = 10;
int height = 10;
int **corresArray = generateCorresArray(width, height);


void setup() {
  //Init Serial USB
  Serial.begin(9600);
  Serial.println(F("Initialize System"));
  //Init led strips
  FastLED.addLeds<LED_TYPE, stripPin, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
  ledScenario();
}

void loop() {
}

void ledScenario() { /* function ledScenario */
  for (int y = 0; y<10; y++){
    for (int x = 0; x<10; x++){
      // Serial.println("(" + String(toDraw[y][x][0]) + "," + String(toDraw[y][x][1]) + "," + String(toDraw[y][x][2]) + ")");
      leds[corresArray[y][x]].setRGB(toDraw[y][x][0],toDraw[y][x][1],toDraw[y][x][2]);
    }    
  }
  FastLED.show();
}



