/**
 * @file audio.h
 * @brief Declarations for functions to play mp3s
 * @author Vivek Nair (viveknair@cmu.edu), Marjorie Carlson (marjorie@cmu.edu)
 */

#ifndef _AUDIO_H_
#define _AUDIO_H_

#include <stdbool.h>
#include "datastructures.h"
#include "mp3s.h"

extern bool playlist_empty;
extern char* lang_prefix;
extern char* mode_fileset;


bool play_mp3(char* fileset, char* mp3);
void play_next_mp3(void);
void clear_playlist(void);

// these use the old glyph data structure
void play_glyph(glyph_t *this_glyph);
void play_dot_sequence(glyph_t *this_glyph);
void play_word(word_node_t *this_word);
void play_line(glyph_t** line);

// switch to using these!
void play_dot(char dot); // plays a dot's number in the current language.
void play_cell(cell_t pattern); // plays dot seq of bit pattern
void play_number(long number);
void play_string(char* word, int word_len);
void play_silence(int milliseconds);


// these play the specified mp3 from the SD card
void play_mode_audio(char* filename); // play m[current_mode]_[filename].mp3
void play_lang_audio(char* filename); // play [first letter of curr language]_[filename].mp3
void play_system_audio(char* filename); // play sys_[filename].mp3
void play_direction(char* filename); // play d_[filename].mp3
void play_feedback(char* filename); // play f_[filename].mp3
void play_vocabulary(char* filename); // play v_[filename].mp3

// specific, frequently used mp3s
void play_welcome(); // play this mode's welcome mp3
void play_submode_choice(); // play this mode's submode mp3
void play_tada(); // play the "tada" noise

#endif /* _AUDIO_H_ */
