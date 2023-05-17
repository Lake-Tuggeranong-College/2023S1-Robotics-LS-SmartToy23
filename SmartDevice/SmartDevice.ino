// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// SD Card - Confirm Pin
#define SDpin 10

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Open serial communications and wait for port to open:
  while (!Serial) {
    delay(1);  // wait for serial port to connect. Needed for native USB port only
  }

  // SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(SDpin)) {
    Serial.println("initialization failed!");
    while (1)
      ;
  }
}

void loop() {
  // put your main code here, to run repeatedly:




delay (250);
  
}


/*
 when movement sensor detects movement,turns on green light and spins the fan otherwise turns on red light
 @params none
 @return none 
 */
 void wakeUpDevice () {

 }
 
/*
checks whether it is above 13 degrees celsius if yes returns it is warm if no returns it is cold
 @params none
 @return none 
 */
 void weatherCheck(){

 
 }
 /*
when movement is not detected for a minute piezo buzzer is sounded to say goodbye
 @params none
 @return none 
 */
 void goodBye () {

 }
 }
