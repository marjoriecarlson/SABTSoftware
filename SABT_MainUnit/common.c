/**
 * @file common.c
 * @brief Definitions for some common functions used by multiple modes.
 * @author Vivek Nair (viveknair@cmu.edu), Marjorie Carlson (marjorie@cmu.edu)
 */

#include <stdbool.h>
#include "globals.h"
#include "audio.h"
#include "common.h"
#include "script_common.h"
#include "script_hindi.h"
#include "script_kannada.h"
#include "script_english.h"
#include "script_digits.h"
#include "datastructures.h"
// #include "mode_15.h"

letter_t blank_letter = { "NULL", &no_cell, 0, LANGUAGE_NULL };

language_t set_language() {
  if (current_mode == 7) {
    mode_language = HINDI;
    lang_name = "HINDI";
    this_script = &script_hindi;
  }
  else if (current_mode == 12) {
    mode_language = KANNADA;
    lang_name = "KANNADA";
    this_script = &script_kannada;
  }
  else {
    mode_language = ENGLISH;
    lang_name = "ENGLISH";
    if (current_mode == 8)
        this_script = &script_digits;
    else
        this_script = &script_english;
  }
  this_script->index = -1;
  log_msg("Language: %s", lang_name);
  return mode_language;
}

 void reset_globals(){
    set_language();
    last_dot = NO_DOTS;
    submode = SUBMODE_NULL;
    level = DIFFICULTY_NULL;
    cell = cell_pattern = cell_control = 0;
    this_letter = blank_letter;
    current_state = INITIAL;
}

void reset_stats(){
    score = mistakes = curr_mistakes = 0;
}

/**
 * @brief Quits the current mode and returns to the main menu
 * @param void
 * @return void
 */
void quit_mode(void) {
    // @todo HACK TO FREE MEMORY MALLOCED IN MODE 15. RETEST THIS.
/*    if (current_mode == 15) {
        log_msg("Freeing dictionary.");
        free_wordlist(&mode_15_dict);
    } */
    is_a_mode_executing = false;
    index_of_current_mode = -1;
    play_system_audio(MP3_MM);
}

/**
 * @brief Generates a pseudo-random integer based on the system timer
 * @param void
 * @return int - Pseudo-random value
 * @BUG - Doesn't change between runs.
 */
int timer_rand(void) {
    #ifdef DEBUGMODE // crosscompiled on x86
        return rand();
    #else
        return TCNT1 * 53;
    #endif
}



/**
 * @brief Initialize an index array
 */
void init_index_arr(int *index_arr, int arr_len){
    for (int i = 0; i < arr_len; i++){
        index_arr[i] = i;
    }
}

void init_char_arr(char* arr, int len){
    for (int i = 0; i < len; i++){
        arr[i] = '\0';
    }
}
