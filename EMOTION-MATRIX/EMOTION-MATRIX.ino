
#include "LedControl.h"
#include "binary.h"

LedControl lc=LedControl(21,27,32,1);
int buttonpin1=34;
int buttonpin2=33;
int buttonpin3=15;
int buttonpin4=16;
int buttonstate1=0;
int buttonstate2=0;
int buttonstate3=0;
int buttonstate4=0;

byte hf[8]= {B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100};
byte nf[8]={B00111100, B01000010,B10100101,B10000001,B10111101,B10000001,B01000010,B00111100};
byte sf[8]= {B00111100,B01000010,B10100101,B10000001,B10011001,B10100101,B01000010,B00111100};
byte rf[8]= {B00111100,B01000010,B10100101,B10011001,B10100101,B10011001,B01000010,B00111100};

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
  pinMode(buttonpin1,INPUT);  
  pinMode(buttonpin2,INPUT); 
  pinMode(buttonpin3,INPUT);  
  pinMode(buttonpin4,INPUT); 
}
void sad() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, sf[i]);
  }
  delay(1000);
}
void neutral() {

  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, nf[i]);
  }
  delay(1000);
}

void happy() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, hf[i]);
  }
  delay(1000);
}

void surprised() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, rf[i]);
  }
  delay(1000);
}

void loop() {
  buttonstate1 = digitalRead(buttonpin1);
  if (buttonstate1 == HIGH) {
    happy();
  }
  buttonstate2 = digitalRead(buttonpin2);
  if (buttonstate2 == HIGH) {
    sad();
  }
 
  buttonstate3 = digitalRead(buttonpin3);
  if (buttonstate3 == HIGH) {
    neutral();
  }

  buttonstate4 = digitalRead(buttonpin4);
  if (buttonstate4 == HIGH) {
    surprised();
  }
  if (buttonstate1 == LOW||buttonstate2==LOW||buttonstate3==LOW||buttonstate4==LOW) {
    lc.clearDisplay(0);
  }
}


extern "C" void app_main() {
  setup();
  while (true) {
    loop();
  }
}



