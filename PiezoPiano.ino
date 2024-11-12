// vim: syntax=arduino autoindent expandtab tabstop=4 shiftwidth=4 softtabstop=4:

#include "Pitches.h"

#define BUZZZER_PIN  18 // ESP32 pin GPIO18 connected to piezo buzzer

#define TOUCH_THRESHOLD 20

static const int touchPins[7] = {32, 33, 27, 14, 12, 13, 15};

boolean touching[7] = {false, false, false, false, false, false, false};

void updateState() {
    int i, numTouched = 0;

    for (i = 0; i < 7; i++) {
        touching[i] = touchRead(touchPins[i]) < TOUCH_THRESHOLD;

        if (touching[i]) {
            numTouched += 1;
        }
    }

    if (numTouched == 0) {
        return;
    }

    if (touching[0]) {
        tone(BUZZZER_PIN, NOTE_A5, 8);
    }

    if (touching[1]) {
        tone(BUZZZER_PIN, NOTE_B5, 8);
    }

    if (touching[2]) {
        tone(BUZZZER_PIN, NOTE_C6, 8);
    }

    if (touching[3]) {
        tone(BUZZZER_PIN, NOTE_D6, 8);
    }

    if (touching[4]) {
        tone(BUZZZER_PIN, NOTE_E6, 8);
    }

    if (touching[5]) {
        tone(BUZZZER_PIN, NOTE_F6, 8);
    }

    if (touching[6]) {
        tone(BUZZZER_PIN, NOTE_G6, 8);
    }
}

void setup() {
}

void loop() {
    // update the current state if there are changes
    updateState();

    delay(10);
}
