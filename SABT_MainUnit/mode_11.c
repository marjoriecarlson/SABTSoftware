/**
 * @file mode_11.c
 * @brief Mode 11 code - Everyday Noises Game
 * @author Poornima Kaniarasu (pkaniara)
 */

#include "globals.h"
#include "Modes.h"
#include "audio.h"
#include "datastructures.h"
#include "common.h"
#include "letter_globals.h"
#include "script_common.h"
#include "script_english.h"
#include "mode_sound_game.h"
#include "mp3s.h"



const char *noise_list[MAX_INDEX + 1] = {"aeroplane", "rain", "bell", "doorbell", "horn", "auto",
    "truck", "train", "siren", "phone", "clock", NULL};

const char* noise_sounds[MAX_INDEX + 1] = {"aer", "rai", "bel", "doo", "hor", "aut",
    "tru", "tra", "sir", "pho", "clo", NULL};

void mode_11_reset(void) {
    mode_sound_game_reset(noise_list, noise_sounds);
}

void mode_11_main(void) {
    mode_sound_game_main();
}