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
// DC Motor & Motor Module - L298N
#include <L298N.h>


// Pin definition
const unsigned int IN1 = 5;
const unsigned int IN2 = 6;
const unsigned int EN = 9;

// Create one motor instance
L298N motor(EN, IN1, IN2);


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
  pinMode(lineSensorPin, INPUT);

  // Crash Sensor / Button
  pinMode(crashSensor, INPUT);

  // DC Motor & Motor Module - L298N
  motor.setSpeed(255);
}

void loop() {
  // put your main code here, to run repeatedly:
  goodBye();
  wakeUpDevice ();
  musicPlay();



  delay (250);

}

/*
  when line sensor detects movement,turns on green light and spins the fan
  @return none
*/
void wakeUpDevice () {
  int lineSensorValue = digitalRead(lineSensorPin);
  if (lineSensorValue == 0) {
    Serial.println("high");
    digitalWrite(ledGreen, HIGH);
    delay(1000);
    digitalWrite(ledGreen , LOW);
    Serial.println("Motor forward");
    motor.forward();
    delay(1000);
    Serial.println("Motor stop");

    motor.stop();
    delay(1000);
    Serial.println("Motor backward");

    motor.backward();
    delay(1000);
    motor.stop();
    Serial.println("Motor stop2");
  } else {
    digitalWrite(ledGreen , LOW);
  }
}

/*
  checks if movement is detected in sonar sensor. If it detects movement below 50, it will play piezo buzzer noise, changing with distance.
  @params none
  @return none
*/
void musicPlay() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  int distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  Serial.println("Eyes: ");
  Serial.println(distance);
  if (distance < 50) {
    Serial.println("high");
    digitalWrite(ledYellow, HIGH);
    tone(piezoPin, distance); // Send 1KHz sound signal...
    delay(100);
    noTone(piezoPin);
  } else {
    digitalWrite(ledYellow, LOW);
  }

}
/*
  if the crash sensor button is pressed, the red light turns on to say goodbye
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
