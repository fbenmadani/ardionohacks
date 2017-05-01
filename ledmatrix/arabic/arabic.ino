/* arabic Led Matrix
 * BENMADANI FAYCAL 2017
 * Demonstrates how to Display a word on LedMatrix Using MAX7219s over SPI port
 */

#include <avr/pgmspace.h>
#include <LedControl.h>
 
const int numDevices = 4;      // number of MAX7219s used

unsigned long bufferLong [14] = {0}; 
// Pin 50 is connected to the DATA IN-pin of the first MAX7221
// Pin 52 is connected to the CLK-pin of the first MAX7221
// Pin 53 is connected to the LOAD(/CS)-pin of the first MAX7221 

LedControl lc=LedControl(50,52,53,numDevices);
////////////////////////////////////////////////////////////////


const uint64_t DAYS[] PROGMEM = {
  
  
  0x0000bfa8a4a3a0a1,
  0x0200ff2911800000,
  0x8000ff0a0a000000,
  0x3844828080000000

};
const int DAYS_LEN = sizeof(DAYS)/8;

void displayImage(uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
lc.setLed(0, i, j, bitRead(row, j));
    }
  }
}

void displayWord(uint64_t image, int position) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
lc.setLed(position, i, j, bitRead(row, j));
    }
  }
}

///

//ALGERIA WORD

const byte ALGERIA[][8] = {
{
  B00000101,
  B00000101,
  B00000101,
  B11000101,
  B00100101,
  B11111101,
  B00000000,
  B10000000
},{
  B00000000,
  B01000000,
  B00000000,
  B01000001,
  B01000000,
  B01111111,
  B01000000,
  B10000000
},{
  B00100010,
  B01001010,
  B00110010,
  B00101010,
  B00001010,
  B11111010,
  B00000000,
  B00000000
},{
  B00000000,
  B00000000,
  B00000000,
  B00000100,
  B00000100,
  B00000111,
  B00001000,
  B00110000
}
};
const byte SYRIA[][8] = {
 {
  B00000000,
  B00000000,
  B00000000,
  B00010101,
  B00010101,
  B11111111,
  B00000000,
  B00000000
},{
  B00000000,
  B00000000,
  B00000000,
  B00011100,
  B00010100,
  B00011111,
  B00001000,
  B00110000
},{
  B00000000,
  B00000000,
  B00000000,
  B00000100,
  B00000100,
  B00000100,
  B00001000,
  B00110000
},{
  B00100000,
  B00100000,
  B00100000,
  B00100001,
  B00100001,
  B00111111,
  B00000000,
  B00000101
}
  
  };
// 



void setup(){
    for (int x=0; x<numDevices; x++){
        lc.shutdown(x,false);       //The MAX72XX is in power-saving mode on startup
        lc.setIntensity(x,8);       // Set the brightness to default value
        lc.clearDisplay(x);         // and clear the display
    }
}

int i = 0;
int j= 0;
 
void loop(){ 

for (int i = 0;i<=4;i++){

  for(int j = 0;j<=7;j++) 
  {
    lc.setRow(i,j,ALGERIA[i][j]);
  }  
}
  delay (3000);
for (int i = 0;i<=4;i++){

  for(int j = 0;j<=7;j++) 
  {
    
    lc.setRow(i,j,SYRIA[i][j]);
  }  
}
 delay (5000);

}


