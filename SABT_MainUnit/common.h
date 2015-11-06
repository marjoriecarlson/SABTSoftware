/**
 * @file common.h
 * @brief Declarations for some common constants and functions used by multiple modes.
 * @author Vivek Nair (viveknair@cmu.edu), Marjorie Carlson (marjorie@cmu.edu)
 */

#ifndef _COMMON_H_
#define _COMMON_H_

#include "datastructures.h"
 #include "usart_pc.h"


// Handy common macros: sending one byte to the PC; logging a newline;
// computing an array length; converting a char to an int;
// modular increment/decrement for traversing lists. NOTE: what lists?

#define ARRAYLEN(x)  (sizeof(x) / sizeof((x)[0])) // used for wordlists
#define CHARTOINT(c)     ((c) - '0') // used for wordlists

void  reset_globals(); // resets lang, level, state, current dot/cell/letter
void  reset_stats(); // resets score, mistakes and curr_mistakes
void  quit_mode(void); // JUST resets is_mode_executing, index of curr mode.

int   timer_rand(void); // generates pseudorandom #

// array initialization -- used in modes 4 and 5
void  init_index_arr(int *index_arr, int arr_len);
void  init_char_arr(char* arr, int len);

#endif /* _COMMON_H_ */
