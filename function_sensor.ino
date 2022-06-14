#include "declaration.h"

const int PulseWire = 0;       // 'S' Signal pin connected to A0
const int LED13 = 13;          // The on-board Arduino LED
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore

PulseSensorPlayground pulseSensor;  // Creates an object

void startSensor(){
  // Configure the PulseSensor object, by assigning our variables to it
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);       // Blink on-board LED with heartbeat
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and began seeing a signal
  if (pulseSensor.begin()) {
    Serial.println("PulseSensor object created!");
  }
}

void readSensor(){
  // put your main code here, to run repeatedly
  int tombol= 1;
  int count = 0;
  if(tombol == 1){
    count++;
    int myBPM = pulseSensor.getBeatsPerMinute();      // Calculates BPM
    
    if (pulseSensor.sawStartOfBeat()) {               // Constantly test to see if a beat happened
      Serial.println("♥  A HeartBeat Happened ! "); // If true, print a message
      Serial.print("BPM: ");
      Serial.println(myBPM);                        // Print the BPM value
      }
  
    delay(1000);
    
    if(count == 3){
      tombol= 0;
    }
  }
}
