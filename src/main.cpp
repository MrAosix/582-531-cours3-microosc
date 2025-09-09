#include <Arduino.h>
#include <MicroOscSlip.h>

#define MA_BROCHE_ANGLE 32
#define MA_BROCHE_BOUTON 39

MicroOscSlip<128> monOsc(&Serial);

void setup() {
  Serial.begin(115200);
  pinMode( MA_BROCHE_BOUTON , INPUT );

}

void loop() {
  int maLectureAnalogique = analogRead(MA_BROCHE_ANGLE);
  int maLectureBouton = digitalRead( MA_BROCHE_BOUTON );
  //Serial.println(maLectureBouton);
  monOsc.sendInt( "/bouton" , maLectureBouton);
  monOsc.sendInt( "/analog" , maLectureAnalogique);
  delay(100);

}