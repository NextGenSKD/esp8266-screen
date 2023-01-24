#include <Arduino.h>
#define LED_PIN 5
#define LED_NUM 256
#include <FastLED.h>
#include "arial_font_8.h"

CRGB leds[LED_NUM];

int counter = 0;
int col_b;
int col_r;
int col_g;
byte combi = 0;
byte combi1 = 1;
byte combi2 = 0;
int uskor =1;
bool c_flag = true;
bool combi_flag = true;
byte bright = 64;
bool test = false;
bool stars = false;
byte counterbyte;
byte x;
byte y;
bool char_bit;

int SCR1[40][8] = 
{
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  0, 0, 0, 0, 0, 0, 0, 99 },
    {  99, 99, 99, 99, 99, 99, 99, 99 }
};


char text[] = "123 Test TEST !!! 1234567890   ";



void debug()   {
// Debug info
  Serial.print("\r Counter:");
  Serial.print(counter);
  Serial.print(" c_flag:");
  Serial.print(c_flag);
  Serial.print(" combi:");
  Serial.print(combi);
  Serial.print(" combi1:");
  Serial.print(combi1);
  Serial.print(" combi2:");
  Serial.print(combi2);
  Serial.print(" combi_flag:");
  Serial.print(combi_flag);
  Serial.print(" uskor:");
  Serial.print(uskor);



  // End Debug
  }  

void print_symbol (int start_position, int symbolnum)
      {
        int txt_char=(int)text[symbolnum]-FONT_ARIAL_8_START_CHAR;
      if (txt_char>850) {txt_char=-848;}
    Serial.print("\r TXT_CHAR ");
  Serial.print(txt_char);
     Serial.print(" Start position ");
  Serial.print(start_position);
  int x=start_position;//*FONT_ARIAL_8_CHAR_HEIGHT;
  for (byte l=0;l<8;l++)
  {
    byte charbitmap = (byte)font_arial_8[txt_char*FONT_ARIAL_8_CHAR_WIDTH+l];
  
    for (byte o=0;o<=7;o++) {  
  
    char_bit=charbitmap&1<<o;
    if (char_bit)
    {       
        SCR1[x+o][l]=(0x88<<16)+(0x88<<8)+0x00;
    } else 
    {       SCR1[x+o][l]=(0x22<<16)+(0x0<<8)+(0x00);
    }
    }}
}

void scroll_screen()
{
   for (int x=0;x<=38;x++)
    {
      
      for (int y=0;y<=7;y++)
      { SCR1[x][y]=SCR1[x+1][y];
        //SCR1[x+1][y] = 0;
    }}
}

void setup() {
  Serial.begin(921600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(20);
  Serial.println("SETUP! Success!");

}

void loop() {

for (int i=0;i<sizeof(text)-1;i++)
{
 print_symbol(31,i);

for (int u=0;u<8;u++)
  {

//print screen on device
   for (int x=0;x<=31;)
    {
      
      for (int y=0;y<=7;)
      { leds[x*8+y]=SCR1[x][y];
        y++;
              }
      x++;
      for (int y=8;y>=0;)
      { leds[x*8+y]=SCR1[x][7-y];
      y--;
      }
      x++;
    } 
  FastLED.show();
  delay (50);
  FastLED.clear();

  scroll_screen();


  }


}}