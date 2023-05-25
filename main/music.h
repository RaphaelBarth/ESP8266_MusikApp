#include "notes.h"
#include <Arduino.h>

#ifndef MUSIC_H
#define MUSIC_H

#define HAPPYBIRTHDAY 0
#define HARRYPOTTER 1

const int tempo = 144;
const int buzzer_pin = 5;

void MUSICplay(int tracknumber);

#endif  //MUSIC_H