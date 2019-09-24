#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include "arduinoFFT.h"
#define RELAY 0

Adafruit_MCP23017 mcp1;
Adafruit_MCP23017 mcp2;
Adafruit_MCP23017 mcp3;
Adafruit_MCP23017 mcp4;
arduinoFFT FFT = arduinoFFT();

//void offAbove(int col,int val);
//void onBelow(int col,int val);
void cercle1(bool state);
void cercle2(bool state);
void cercle3(bool state);
void cercle4(bool state);
void cercle5(bool state);
void cercle6(bool state);
void cercle7(bool state);
void cercle8(bool state);
void cercle9(bool state);
void cercle10(bool state);
///*
//These values can be changed in order to evaluate the functions
//*/
//const uint16_t samples = 64; //This value MUST ALWAYS be a power of 2
//const double signalFrequency = 1000;
//const double samplingFrequency = 5000;
//const uint8_t amplitude = 100;
///*
//These are the input and output vectors
//Input vectors receive computed results from FFT
//*/
//double vReal[samples];
//double vImag[samples];
//
//#define SCL_INDEX 0x00
//#define SCL_TIME 0x01
//#define SCL_FREQUENCY 0x02
//#define SCL_PLOT 0x03

void setup() {
  mcp1.begin(7);      // use default address 0
  mcp1.pinMode(0, OUTPUT);//do not turn on all the pins in one command, it can draw too much current in the port expander
  mcp1.pinMode(1, OUTPUT);
  mcp1.pinMode(2, OUTPUT);
  mcp1.pinMode(3, OUTPUT);
  mcp1.pinMode(4, OUTPUT);
  mcp1.pinMode(5, OUTPUT);
  mcp1.pinMode(6, OUTPUT);
  mcp1.pinMode(7, OUTPUT);
  mcp1.pinMode(8, OUTPUT);
  mcp1.pinMode(9, OUTPUT);
  mcp1.pinMode(10, OUTPUT);
  mcp1.pinMode(11, OUTPUT);
  mcp1.pinMode(12, OUTPUT);
  mcp1.pinMode(13, OUTPUT);
  mcp1.pinMode(14, OUTPUT);
  mcp1.pinMode(15, OUTPUT);
    mcp2.begin(6);      // use default address 0
  mcp2.pinMode(0, OUTPUT);
  mcp2.pinMode(1, OUTPUT);
  mcp2.pinMode(2, OUTPUT);
  mcp2.pinMode(3, OUTPUT);
  mcp2.pinMode(4, OUTPUT);
  mcp2.pinMode(5, OUTPUT);
  mcp2.pinMode(6, OUTPUT);
  mcp2.pinMode(7, OUTPUT);
  mcp2.pinMode(8, OUTPUT);
  mcp2.pinMode(9, OUTPUT);
  mcp2.pinMode(10, OUTPUT);
  mcp2.pinMode(11, OUTPUT);
  mcp2.pinMode(12, OUTPUT);
  mcp2.pinMode(13, OUTPUT);
  mcp2.pinMode(14, OUTPUT);
  mcp2.pinMode(15, OUTPUT);
    mcp3.begin(0);      // use default address 0
  mcp3.pinMode(0, OUTPUT);
  mcp3.pinMode(1, OUTPUT);
  mcp3.pinMode(2, OUTPUT);
  mcp3.pinMode(3, OUTPUT);
  mcp3.pinMode(4, OUTPUT);
  mcp3.pinMode(5, OUTPUT);
  mcp3.pinMode(6, OUTPUT);
  mcp3.pinMode(7, OUTPUT);
  mcp3.pinMode(8, OUTPUT);
  mcp3.pinMode(9, OUTPUT);
  mcp3.pinMode(10, OUTPUT);
  mcp3.pinMode(11, OUTPUT);
  mcp3.pinMode(12, OUTPUT);
  mcp3.pinMode(13, OUTPUT);
  mcp3.pinMode(14, OUTPUT);
  mcp3.pinMode(15, OUTPUT);
    mcp4.begin(4);      // use default address 0
  mcp4.pinMode(0, OUTPUT);
  mcp4.pinMode(1, OUTPUT);
  mcp4.pinMode(2, OUTPUT);
  mcp4.pinMode(3, OUTPUT);
  mcp4.pinMode(4, OUTPUT);
  mcp4.pinMode(5, OUTPUT);
  mcp4.pinMode(6, OUTPUT);
  mcp4.pinMode(7, OUTPUT);
  mcp4.pinMode(8, OUTPUT);
  mcp4.pinMode(9, OUTPUT);
  mcp4.pinMode(10, OUTPUT);
  mcp4.pinMode(11, OUTPUT);
  mcp4.pinMode(12, OUTPUT);
  mcp4.pinMode(13, OUTPUT);
  mcp4.pinMode(14, OUTPUT);
  mcp4.pinMode(15, OUTPUT);
  // nitialize serial communication at 9600 bits per second:
  //Serial.begin(9600);
  pinMode(RELAY,OUTPUT); //pin 0 is the relay
  digitalWrite(RELAY,HIGH);//turn on relay after port expanders set
  //randomSeed(analogRead(0));
}

int micValue=0;
int micIntensity=0;
const unsigned long interval=50;  //50ms -> 20Hz
//unsigned long sustain=200;

unsigned long previousMillis = 0;
int x=0,xactuel=0;
int maxSignal=0;
int count=0;

void loop() {
  unsigned long currentMillis = millis();
  
  micValue = analogRead(A5);//microphone
  micIntensity=abs(micValue-520);
  if(micIntensity > maxSignal){
    maxSignal=micIntensity;
  }

  
  //Serial.println(intensity);
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    //turn off the old one
//    mcp1.digitalWrite(15-x,LOW);
//    mcp1.digitalWrite(x1,LOW);
//    mcp2.digitalWrite(15-x2,LOW);
//    mcp2.digitalWrite(x3,LOW);
//    mcp3.digitalWrite(15-x4,LOW);
//    mcp3.digitalWrite(x5,LOW);
//    mcp4.digitalWrite(15-x4,LOW);
//    mcp4.digitalWrite(x5,LOW);
////////////////////////////////////////////////////
    xactuel=x;
    x=map(maxSignal,0,512,0,10);
    
    int i=0;
    if(x > xactuel){
      for(i=xactuel;i<=x;++i){
        switch (i){
          case 1:
            cercle1(HIGH);
            break;
          case 2:
            cercle2(HIGH);
            break;
          case 3:
            cercle3(HIGH);
            break;
          case 4:
            cercle4(HIGH);
            break;
          case 5:
            cercle5(HIGH);
            break;
          case 6:
            cercle6(HIGH);
            break;
          case 7:
            cercle7(HIGH);
            break;
          case 8:
            cercle8(HIGH);
            break;
          case 9:
            cercle9(HIGH);
            break;
          case 10:
            cercle10(HIGH);
            break;
        }
      }
    }
    else if(x < xactuel){
      for(i=xactuel;i>=x;--i){
        switch (i){    
          case 1:
            cercle1(LOW);
            break;
          case 2:
            cercle2(LOW);
            break;
          case 3:
            cercle3(LOW);
            break;
          case 4:
            cercle4(LOW);
            break;
          case 5:
            cercle5(LOW);
            break;
          case 6:
            cercle6(LOW);
            break;
          case 7:
            cercle7(LOW);
            break;
          case 8:
            cercle8(LOW);
            break;
          case 9:
            cercle9(LOW);
            break;
          case 10:
            cercle10(LOW);
            break;
        }
      }
    }
    else{
      
    }

    //turn on new ones
//    mcp1.digitalWrite(15-x,HIGH);
//    mcp1.digitalWrite(x1,HIGH);
//    mcp2.digitalWrite(15-x2,HIGH);
//    mcp2.digitalWrite(x3,HIGH);
//    mcp3.digitalWrite(15-x4,HIGH);
//    mcp3.digitalWrite(x5,HIGH);
//    mcp4.digitalWrite(15-x4,HIGH);
//    mcp4.digitalWrite(x5,HIGH);

    
    maxSignal=0;//reset for new period
  }
}

//void offAbove(int col, int val){
//  int i=0;
//  if(col==1){
//    for(i=val+1;i<16;++i){
//      mcp1.digitalWrite(15-i,LOW);
//    }
//  }
//  if(col==2){
//    for(i=val+1;i<16;++i){
//      mcp1.digitalWrite(i,LOW);
//    }
//  }
//  if(col==3){
//    for(i=val+1;i<16;++i){
//      mcp2.digitalWrite(15-i,LOW);
//    }
//  }
//  if(col==4){
//    for(i=val+1;i<16;++i){
//      mcp2.digitalWrite(i,LOW);
//    }
//  }
//  if(col==5){
//    for(i=val+1;i<16;++i){
//      mcp3.digitalWrite(15-i,LOW);
//    }
//  }
//  if(col==6){
//    for(i=val+1;i<16;++i){
//      mcp3.digitalWrite(i,LOW);
//    }
//  }
//}
//void onBelow(int col, int val){
//  int i=0;
//  if(col==1){
//    for(i=val;i>=0;--i){
//      mcp1.digitalWrite(15-i,HIGH);
//    }
//  }
//  if(col==2){
//    for(i=val;i>=0;--i){
//      mcp1.digitalWrite(i,HIGH);
//    }
//  }
//  if(col==3){
//    for(i=val;i>=0;--i){
//      mcp2.digitalWrite(15-i,HIGH);
//    }
//  }
//  if(col==4){
//    for(i=val;i>=0;--i){
//      mcp2.digitalWrite(i,HIGH);
//    }
//  }
//  if(col==5){
//    for(i=val;i>=0;--i){
//      mcp3.digitalWrite(15-i,HIGH);
//    }
//  }
//  if(col==6){
//    for(i=val;i>=0;--i){
//      mcp3.digitalWrite(i,HIGH);
//    }
//  }
//}

void cercle1(bool state){
  mcp2.digitalWrite(3,state);
  mcp2.digitalWrite(4,state);
  mcp3.digitalWrite(11,state);
  mcp3.digitalWrite(12,state);
}
void cercle2(bool state){
  mcp2.digitalWrite(11,state);
  mcp2.digitalWrite(12,state);
  mcp2.digitalWrite(2,state);
  mcp2.digitalWrite(5,state);
  mcp3.digitalWrite(13,state);
  mcp3.digitalWrite(10,state);
  mcp3.digitalWrite(4,state);
  mcp3.digitalWrite(3,state);
}
void cercle3(bool state){
  mcp2.digitalWrite(13,state);
  mcp2.digitalWrite(10,state);
  mcp3.digitalWrite(2,state);
  mcp3.digitalWrite(5,state);
}
void cercle4(bool state){
  mcp1.digitalWrite(3,state);
  mcp1.digitalWrite(4,state);
  mcp2.digitalWrite(1,state);
  mcp2.digitalWrite(6,state);
  mcp3.digitalWrite(14,state);
  mcp3.digitalWrite(9,state);
  mcp4.digitalWrite(11,state);
  mcp4.digitalWrite(12,state);
}
void cercle5(bool state){
  mcp1.digitalWrite(2,state);
  mcp1.digitalWrite(5,state);
  mcp2.digitalWrite(14,state);
  mcp2.digitalWrite(9,state);
  mcp3.digitalWrite(6,state);
  mcp3.digitalWrite(1,state);
  mcp4.digitalWrite(10,state);
  mcp4.digitalWrite(13,state);
}
void cercle6(bool state){
  mcp1.digitalWrite(1,state);
  mcp1.digitalWrite(6,state);
  mcp4.digitalWrite(14,state);
  mcp4.digitalWrite(9,state);
}
void cercle7(bool state){
  mcp1.digitalWrite(12,state);
  mcp1.digitalWrite(11,state);
  mcp2.digitalWrite(7,state);
  mcp2.digitalWrite(0,state);
  mcp3.digitalWrite(8,state);
  mcp3.digitalWrite(15,state);
  mcp4.digitalWrite(4,state);
  mcp4.digitalWrite(3,state);
}
void cercle8(bool state){
  mcp1.digitalWrite(10,state);
  mcp1.digitalWrite(13,state);
  mcp2.digitalWrite(8,state);
  mcp2.digitalWrite(15,state);
  mcp3.digitalWrite(7,state);
  mcp3.digitalWrite(0,state);
  mcp4.digitalWrite(5,state);
  mcp4.digitalWrite(2,state);
}
void cercle9(bool state){
  mcp1.digitalWrite(9,state);
  mcp1.digitalWrite(14,state);
  mcp1.digitalWrite(7,state);
  mcp1.digitalWrite(0,state);
  mcp4.digitalWrite(8,state);
  mcp4.digitalWrite(15,state);
  mcp4.digitalWrite(6,state);
  mcp4.digitalWrite(1,state);
}
void cercle10(bool state){
  mcp1.digitalWrite(8,state);
  mcp1.digitalWrite(15,state);
  mcp4.digitalWrite(7,state);
  mcp4.digitalWrite(0,state);
}
