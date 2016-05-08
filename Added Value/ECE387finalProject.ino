//Mark Sullivan
#include "pitches.h"
#include <Wire.h>
#include <Adafruit_LSM303.h>


Adafruit_LSM303 lsm;

int maxX = 0;
int maxY = 0;
int maxZ = 0;
int minX = 0;
int minY = 0;
int minZ = 0;

int melodyUp[] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5};
int melodyDown[] = {NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5};
int melodyRight[] = {NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6, NOTE_C6};
int melodyLeft[] = {NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4};

int noteDuration = 1000 / 8;

void setup() {
  Serial.begin(9600);

  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM303. Check your wiring!");
    while (1);
  }

}

void loop() {
  //read in values of accelerometer every loop
  lsm.read();
  //check threshold values to see if sword swung in certain direction
  if ((int)lsm.accelData.y > 600 && (int)lsm.accelData.z < 850) {
    Serial.println("UP");
    for (int thisNote = 0; thisNote < 5; thisNote++) {

      tone(8, melodyUp[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * .2;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
    }
    //delay so it doesn't repeatedly play same sound when swung
    delay(1000);
  }
  if ((int)lsm.accelData.y < 100 && (int)lsm.accelData.z > 1000) {
    Serial.println("DOWN");
    for (int thisNote = 0; thisNote < 5; thisNote++) {

      tone(8, melodyDown[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * .2;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
    }
    delay(1000);
  }
  if ((int)lsm.accelData.x > 360) {
    Serial.println("Right");
    for (int thisNote = 0; thisNote < 5; thisNote++) {

      tone(8, melodyRight[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * .2;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
    }
    delay(1000);
  }
  if ((int)lsm.accelData.x < -365) {
    Serial.println("Left");
    for (int thisNote = 0; thisNote < 5; thisNote++) {

      tone(8, melodyLeft[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * .2;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
    }
    delay(1000);
  }


// Code for testig
  //  Serial.print((int)lsm.accelData.x);
  //  Serial.print(" ");
  //  Serial.print((int)lsm.accelData.y);
  //  Serial.print(" ");
  //  Serial.println((int)lsm.accelData.z);

  //  if((int)lsm.accelData.x>maxX)
  //    maxX = (int)lsm.accelData.x;
  //  if((int)lsm.accelData.x<minX)
  //    minX = (int)lsm.accelData.x;
  //  if((int)lsm.accelData.y>maxY)
  //    maxY = (int)lsm.accelData.y;
  //  if((int)lsm.accelData.y<minY)
  //    minY = (int)lsm.accelData.y;
  //  if((int)lsm.accelData.z>maxZ)
  //    maxZ = (int)lsm.accelData.z;
  //  if((int)lsm.accelData.z<minZ)
  //    minZ = (int)lsm.accelData.z;
  //
  //  Serial.print(maxX);
  //  Serial.print(",");
  //  Serial.print(minX);
  //  Serial.print(" ");
  //  Serial.print(maxY);
  //  Serial.print(",");
  //  Serial.print(minY);
  //  Serial.print(" ");
  //  Serial.print(maxZ);
  //  Serial.print(",");
  //  Serial.println(minZ);




}
