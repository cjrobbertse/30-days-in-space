#include "Arduino.h"  // include information about our HERO

const byte LIGHT_PIN_1 = 6;
const byte LIGHT_PIN_2 = 7;
const byte LIGHT_PIN_3 = 8;
const byte LIGHT_PIN_4 = 9;
const byte LIGHT_PIN_5 = 10;
const byte LIGHT_PIN_6 = 11;
const byte LIGHT_PIN_7 = 12;

const byte SWITCH_PIN_BIT_1 = 2;
const byte SWITCH_PIN_BIT_2 = 3;
const byte SWITCH_PIN_BIT_3 = 4;


int readBinaryString(char *s) {
  int result = 0;
  while(*s) {
    result <<= 1;
    if(*s++ == '1') result |= 1;
  }
  return result;
}


void setup() {
  pinMode(LIGHT_PIN_1, OUTPUT);
  pinMode(LIGHT_PIN_2, OUTPUT);
  pinMode(LIGHT_PIN_3, OUTPUT);
  pinMode(LIGHT_PIN_4, OUTPUT);
  pinMode(LIGHT_PIN_5, OUTPUT);
  pinMode(LIGHT_PIN_6, OUTPUT);
  pinMode(LIGHT_PIN_7, OUTPUT);


  pinMode(SWITCH_PIN_BIT_1, INPUT);
  pinMode(SWITCH_PIN_BIT_2, INPUT);
  pinMode(SWITCH_PIN_BIT_3, INPUT);
  
  Serial.begin(9600); // open the serial port at 9600 bps:

}


void loop() {

  char binaryInp[3] = {'0', '0', '0'};

  if (digitalRead(SWITCH_PIN_BIT_1) == HIGH) {
    binaryInp[0] = '1';
  } else {
    binaryInp[0] = '0';
  }
  if (digitalRead(SWITCH_PIN_BIT_2) == HIGH) {
    binaryInp[1] = '1';
  } else {
    binaryInp[1] = '0';
  }
  if (digitalRead(SWITCH_PIN_BIT_3) == HIGH) {
    binaryInp[2] = '1';
  } else {
    binaryInp[2] = '0';
  }
  Serial.println(binaryInp);

  int input_number = readBinaryString(binaryInp);
  Serial.println(input_number);

  switch (input_number) {
    case 1:
      digitalWrite(LIGHT_PIN_1, HIGH);
      digitalWrite(LIGHT_PIN_2, LOW);
      digitalWrite(LIGHT_PIN_3, LOW);
      digitalWrite(LIGHT_PIN_4, LOW);
      digitalWrite(LIGHT_PIN_5, LOW);
      digitalWrite(LIGHT_PIN_6, LOW);
      digitalWrite(LIGHT_PIN_7, LOW);
      break;
    case 2:
      digitalWrite(LIGHT_PIN_1, LOW);
      digitalWrite(LIGHT_PIN_2, HIGH);
      digitalWrite(LIGHT_PIN_3, LOW);
      digitalWrite(LIGHT_PIN_4, LOW);
      digitalWrite(LIGHT_PIN_5, LOW);
      digitalWrite(LIGHT_PIN_6, LOW);
      digitalWrite(LIGHT_PIN_7, LOW);
      break;
    case 3:
      digitalWrite(LIGHT_PIN_1, LOW);
      digitalWrite(LIGHT_PIN_2, LOW);
      digitalWrite(LIGHT_PIN_3, HIGH);
      digitalWrite(LIGHT_PIN_4, LOW);
      digitalWrite(LIGHT_PIN_5, LOW);
      digitalWrite(LIGHT_PIN_6, LOW);
      digitalWrite(LIGHT_PIN_7, LOW);
      break;
    case 4:
      digitalWrite(LIGHT_PIN_1, LOW);
      digitalWrite(LIGHT_PIN_2, LOW);
      digitalWrite(LIGHT_PIN_3, LOW);
      digitalWrite(LIGHT_PIN_4, HIGH);
      digitalWrite(LIGHT_PIN_5, LOW);
      digitalWrite(LIGHT_PIN_6, LOW);
      digitalWrite(LIGHT_PIN_7, LOW);
      break;
    case 5:
      digitalWrite(LIGHT_PIN_1, LOW);
      digitalWrite(LIGHT_PIN_2, LOW);
      digitalWrite(LIGHT_PIN_3, LOW);
      digitalWrite(LIGHT_PIN_4, LOW);
      digitalWrite(LIGHT_PIN_5, HIGH);
      digitalWrite(LIGHT_PIN_6, LOW);
      digitalWrite(LIGHT_PIN_7, LOW);
      break;\
    case 6:
      digitalWrite(LIGHT_PIN_1, LOW);
      digitalWrite(LIGHT_PIN_2, LOW);
      digitalWrite(LIGHT_PIN_3, LOW);
      digitalWrite(LIGHT_PIN_4, LOW);
      digitalWrite(LIGHT_PIN_5, LOW);
      digitalWrite(LIGHT_PIN_6, HIGH);
      digitalWrite(LIGHT_PIN_7, LOW);
      break;
    case 7:
      digitalWrite(LIGHT_PIN_1, LOW);
      digitalWrite(LIGHT_PIN_2, LOW);
      digitalWrite(LIGHT_PIN_3, LOW);
      digitalWrite(LIGHT_PIN_4, LOW);
      digitalWrite(LIGHT_PIN_5, LOW);
      digitalWrite(LIGHT_PIN_6, LOW);
      digitalWrite(LIGHT_PIN_7, HIGH);
      break;
    default:
      digitalWrite(LIGHT_PIN_1, LOW);
      digitalWrite(LIGHT_PIN_2, LOW);
      digitalWrite(LIGHT_PIN_3, LOW);
      digitalWrite(LIGHT_PIN_4, LOW);
      digitalWrite(LIGHT_PIN_5, LOW);
      digitalWrite(LIGHT_PIN_6, LOW);
      digitalWrite(LIGHT_PIN_7, LOW);
      break;
  }

  delay(2000);
}
