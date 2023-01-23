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

int SCR1[32][8] = 
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
    {  0, 0, 0, 0, 0, 0, 0, 99 }
};


char text[] = "1234";



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

void setup() {
  Serial.begin(921600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(20);
  Serial.println("SETUP! Success!");

}

void loop() {

for (int i=0;i<sizeof(text)-1;i++)
{
  byte txt_char=text[i]-FONT_ARIAL_8_START_CHAR;
  
  for (byte l=0;l<=8;l++)
  {
    byte charbitmap = (byte)font_arial_8[txt_char*FONT_ARIAL_8_CHAR_HEIGHT+l];
  
    for (byte o=0;o<=7;o++) {  
    x=i*FONT_ARIAL_8_CHAR_WIDTH;
    y=l;
    char_bit=charbitmap&1<<o;
    if (char_bit)
    {       
      SCR1[x+o][y]=(0x00<<16)+(0xaa<<8)+0xaa;
    
    } else 
    {       SCR1[x+o][y]=0;
    }

   //delay(100);
  Serial.print("\r Text_char_ansi_number: ");
  Serial.print(txt_char);
  Serial.print(" char_count: ");
  Serial.print(i);
  Serial.print(" char_line: ");
  Serial.print(l);
  Serial.print(" char_bit: ");
  Serial.print(o);
  Serial.print(" x: ");
  Serial.print(x+o);
  Serial.print(" y: ");
  Serial.print(y);
  Serial.print(" charbitmap: ");
  Serial.print(charbitmap);
  Serial.print(" charbit: ");
  Serial.print(char_bit);

  Serial.print("    ");


    }
    }

  }








/* for (int x=0;x<=31;x++)
    {
      for (int y=0;y<=7;y++)
      {SCR1[x][y]=(0xaa<<16)+(0xaa<<8)+0xaa;}
    } 
    /**/

//print
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

    // Stars
    if (stars) {       
      for (int i=0;i<=10;i++)   {
          leds[random(LED_NUM)] = 128+(128<<8)+(128<<16);
            }
        }   //end start  
      
        //For test brightness     
      if (test) {
         for (int i=0;i<=LED_NUM;i++) 
          { //if (counterbyte<=)
            
            //leds[i] = col_b+(col_r<<8)+(col_g<<16);} 
            leds[i] = counterbyte+(255-counterbyte<<8)+(i<<16);} 
                }
        // end test brightness
  FastLED.show();
   //delay(100);
  //debug();
  FastLED.clear();
  counterbyte++;
 

}