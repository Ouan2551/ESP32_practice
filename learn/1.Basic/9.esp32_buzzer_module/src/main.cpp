#include <Arduino.h>

#include "pitches.h"
#define buzzer_pin 22

int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup() {
  for (int this_note = 0; this_note < 8; this_note++)
  {
    int noteDuration = 1000 / noteDurations[this_note]; // declare new noteDuration
    tone(buzzer_pin, melody[this_note], noteDuration);

    int pause_between_notes = noteDuration * 1.3;
    delay(pause_between_notes);
    noTone(buzzer_pin);
  }
}

void loop() {
}