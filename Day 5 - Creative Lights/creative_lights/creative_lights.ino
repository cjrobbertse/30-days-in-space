#include "Arduino.h"  // include information about our HERO

const byte CABIN_LIGHTS_PIN = 10;
const byte STORAGE_LIGHTS_PIN = 11;
const byte COCKPIT_LIGHTS_PIN = 12;

const byte CABIN_LIGHTS_SWITCH_PIN = 2;
const byte STORAGE_LIGHTS_SWITCH_PIN = 3;
const byte COCKPIT_LIGHTS_SWITCH_PIN = 4;



void setup() {
  pinMode(CABIN_LIGHTS_PIN, OUTPUT);
  pinMode(STORAGE_LIGHTS_PIN, OUTPUT);
  pinMode(COCKPIT_LIGHTS_PIN, OUTPUT);

  pinMode(CABIN_LIGHTS_SWITCH_PIN, INPUT);
  pinMode(STORAGE_LIGHTS_SWITCH_PIN, INPUT);
  pinMode(COCKPIT_LIGHTS_SWITCH_PIN, INPUT);
}

void loop() {
  if (digitalRead(CABIN_LIGHTS_SWITCH_PIN) == HIGH) {
    digitalWrite(CABIN_LIGHTS_PIN, HIGH);
    digitalWrite(STORAGE_LIGHTS_PIN, LOW);
    digitalWrite(COCKPIT_LIGHTS_PIN, LOW);
  } else if (digitalRead(STORAGE_LIGHTS_SWITCH_PIN) == HIGH) {
    digitalWrite(CABIN_LIGHTS_PIN, LOW);
    digitalWrite(STORAGE_LIGHTS_PIN, HIGH);
    digitalWrite(COCKPIT_LIGHTS_PIN, LOW);
  } else if (digitalRead(COCKPIT_LIGHTS_SWITCH_PIN) == HIGH) {
    digitalWrite(CABIN_LIGHTS_PIN, LOW);
    digitalWrite(STORAGE_LIGHTS_PIN, LOW);
    digitalWrite(COCKPIT_LIGHTS_PIN, HIGH);
  } else {
    digitalWrite(CABIN_LIGHTS_PIN, LOW);
    digitalWrite(STORAGE_LIGHTS_PIN, LOW);
    digitalWrite(COCKPIT_LIGHTS_PIN, LOW);
  }
}
