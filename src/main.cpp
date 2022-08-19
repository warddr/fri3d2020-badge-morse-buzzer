#include <Arduino.h>
#include <Badge2020_Buzzer.h>
#include <Wire.h>

#define BADGE2020_BUZZER 32
int dot = 100;
int dash = dot * 3;
int frequency = 700;

Badge2020_Buzzer buzzer;

void sendmorse(String morse) {
  buzzer.setFrequency(frequency);
  for (int i = 0; i < morse.length(); i++) {
    if (morse[i] == '.') {
      buzzer.setVolume(255);
      delay(dot);
      buzzer.setVolume(0);
      delay(dot);
    }
    else if (morse[i] == '-') {
      buzzer.setVolume(255);
      delay(dash);
      buzzer.setVolume(0);
      delay(dot);
    }
    else {
      delay(dot * 3);
    }
  }
}


void setup() {
}

void loop() {
  sendmorse("- . ... -   ");
}