// SD Card Module
#include <SPI.h>
#include <SD.h>
// Traffic Lights - LED Outputs
#define ledRed A2
#define ledYellow A1
#define ledGreen A0
// Servo
#include <Servo.h>
Servo myservo;
//Potentiometer
#define pot A3
// Piezo Buzzer
#define piezoPin 8
// Sonar - HC-SR04
#define echoPin A5//attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 2//attach pin D3 Arduino to pin Trig of HC-SR04
// Line Sensor
#define lineSensorPin 3
// Crash Sensor / Button
#define crashSensor 7


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
    //while (1)
      //;
  }

  // Real Time Clock (RTC)
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("initialization done.");
  //logEvent("System Initialisation...");


  // Traffic Lights - LED Outputs
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);

  // Servo
#include <Servo.h>
  Servo myservo;

  //Potentiometer
  pinMode(pot, INPUT);


  // Piezo Buzzer
  pinMode(piezoPin, OUTPUT);

  // Sonar - HC-SR04
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

  // Line Sensor
  pinMode(lineSensorPin, OUTPUT);

  // Crash Sensor / Button
  pinMode(crashSensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  goodBye();
  wakeUpDevice ();



  delay (250);

}

/*
  when movement sensor detects movement,turns on green light and spins the fan otherwise turns on red light
  @params none
  @return none
*/
void wakeUpDevice () {
int lineSensorValue = digitalRead(lineSensorPin);
  if (lineSensorValue == 0) {
    Serial.println("high");
    digitalWrite(ledGreen, HIGH);
    delay(2000);
    digitalWrite(ledGreen , LOW);
  } else {
    digitalWrite(ledGreen , LOW);
  }
}

/*
  checks whether it is above 13 degrees celsius if yes returns it is warm if no returns it is cold
  @params none
  @return none
*/
void weatherCheck() {


}
/*
  when movement is not detected for a minute piezo buzzer is sounded to say goodbye
  @params none
  @return none
*/
void goodBye () {
  int crashSensorValue = digitalRead(crashSensor);
  if (crashSensorValue == 0) {
    Serial.println("high");
    digitalWrite(ledRed, HIGH);
  } else {
    digitalWrite(ledRed, LOW);
  }

}
