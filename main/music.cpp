#include "music.h"

void play_music(int* melody, int notes) {
  int divider, noteDuration = 0;
  int wholenote = (60000 * 4) / tempo;

  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;  // increases the duration in half for dotted notes
    }
    tone(buzzer_pin, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(buzzer_pin);
  }
}

//Song 1
int happybirthday[] = {
  NOTE_C4,
  4,
  NOTE_C4,
  8,
  NOTE_D4,
  -4,
  NOTE_C4,
  -4,
  NOTE_F4,
  -4,
  NOTE_E4,
  -2,
  NOTE_C4,
  4,
  NOTE_C4,
  8,
  NOTE_D4,
  -4,
  NOTE_C4,
  -4,
  NOTE_G4,
  -4,
  NOTE_F4,
  -2,
  NOTE_C4,
  4,
  NOTE_C4,
  8,

  NOTE_C5,
  -4,
  NOTE_A4,
  -4,
  NOTE_F4,
  -4,
  NOTE_E4,
  -4,
  NOTE_D4,
  -4,
  NOTE_AS4,
  4,
  NOTE_AS4,
  8,
  NOTE_A4,
  -4,
  NOTE_F4,
  -4,
  NOTE_G4,
  -4,
  NOTE_F4,
  -2,
};

void play_happybirthday() {
  int notes = sizeof(happybirthday) / sizeof(happybirthday[0]) / 2;
  play_music(happybirthday, notes);
}

int harrypotter[] = {
  REST,
  2,
  NOTE_D4,
  4,
  NOTE_G4,
  -4,
  NOTE_AS4,
  8,
  NOTE_A4,
  4,
  NOTE_G4,
  2,
  NOTE_D5,
  4,
  NOTE_C5,
  -2,
  NOTE_A4,
  -2,
  NOTE_G4,
  -4,
  NOTE_AS4,
  8,
  NOTE_A4,
  4,
  NOTE_F4,
  2,
  NOTE_GS4,
  4,
  NOTE_D4,
  -1,
  NOTE_D4,
  4,

  NOTE_G4,
  -4,
  NOTE_AS4,
  8,
  NOTE_A4,
  4,  //10
  NOTE_G4,
  2,
  NOTE_D5,
  4,
  NOTE_F5,
  2,
  NOTE_E5,
  4,
  NOTE_DS5,
  2,
  NOTE_B4,
  4,
  NOTE_DS5,
  -4,
  NOTE_D5,
  8,
  NOTE_CS5,
  4,
  NOTE_CS4,
  2,
  NOTE_B4,
  4,
  NOTE_G4,
  -1,
  NOTE_AS4,
  4,

  NOTE_D5,
  2,
  NOTE_AS4,
  4,  //18
  NOTE_D5,
  2,
  NOTE_AS4,
  4,
  NOTE_DS5,
  2,
  NOTE_D5,
  4,
  NOTE_CS5,
  2,
  NOTE_A4,
  4,
  NOTE_AS4,
  -4,
  NOTE_D5,
  8,
  NOTE_CS5,
  4,
  NOTE_CS4,
  2,
  NOTE_D4,
  4,
  NOTE_D5,
  -1,
  REST,
  4,
  NOTE_AS4,
  4,

  NOTE_D5,
  2,
  NOTE_AS4,
  4,  //26
  NOTE_D5,
  2,
  NOTE_AS4,
  4,
  NOTE_F5,
  2,
  NOTE_E5,
  4,
  NOTE_DS5,
  2,
  NOTE_B4,
  4,
  NOTE_DS5,
  -4,
  NOTE_D5,
  8,
  NOTE_CS5,
  4,
  NOTE_CS4,
  2,
  NOTE_AS4,
  4,
  NOTE_G4,
  -1,
};

//Song 2
void play_harrypotter() {
  int notes = sizeof(harrypotter) / sizeof(harrypotter[0]) / 2;
  play_music(harrypotter, notes);
}


void MUSICplay(int tracknumber) {
  switch (tracknumber) {
    case HAPPYBIRTHDAY:
      play_happybirthday();
      break;
    case HARRYPOTTER:
      play_harrypotter();
      break;
    default:
      break;
  }
}