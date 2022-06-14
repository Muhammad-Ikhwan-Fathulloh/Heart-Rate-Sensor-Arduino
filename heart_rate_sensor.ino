#include "declaration.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  startSensor();
}

void loop() {
  readSensor();
}
