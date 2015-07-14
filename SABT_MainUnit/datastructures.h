/**
 * @file datastructures.h
 * @brief Structures for single glyphs and scripts
 * @author Vivek Nair (viveknair@cmu.edu)
 */

#ifndef _DATASTRUCTURES_H_
#define _DATASTRUCTURES_H_

#include <stdbool.h>

#define DOTS0      0b000000
#define DOTS1      0b000001
#define DOTS2      0b000010
#define DOTS12     0b000011
#define DOTS3      0b000100
#define DOTS13     0b000101
#define DOTS23     0b000110
#define DOTS123    0b000111
#define DOTS4      0b001000
#define DOTS14     0b001001
#define DOTS24     0b001010
#define DOTS124    0b001011
#define DOTS34     0b001100
#define DOTS134    0b001101
#define DOTS234    0b001110
#define DOTS1234   0b001111
#define DOTS5      0b010000
#define DOTS15     0b010001
#define DOTS25     0b010010
#define DOTS125    0b010011
#define DOTS35     0b010100
#define DOTS135    0b010101
#define DOTS235    0b010110
#define DOTS1235   0b010111
#define DOTS45     0b011000
#define DOTS145    0b011001
#define DOTS245    0b011010
#define DOTS1245   0b011011
#define DOTS345    0b011100
#define DOTS1345   0b011101
#define DOTS2345   0b011110
#define DOTS12345  0b011111
#define DOTS6      0b100000
#define DOTS16     0b100001
#define DOTS26     0b100010
#define DOTS126    0b100011
#define DOTS36     0b100100
#define DOTS136    0b100101
#define DOTS236    0b100110
#define DOTS1236   0b100111
#define DOTS046    0b101000
#define DOTS146    0b101001
#define DOTS246    0b101010
#define DOTS1246   0b101011
#define DOTS346    0b101100
#define DOTS1346   0b101101
#define DOTS2346   0b101110
#define DOTS12346  0b101111
#define DOTS56     0b110000
#define DOTS156    0b110001
#define DOT256     0b110010
#define DOTS1256   0b110011
#define DOTS356    0b110100
#define DOTS1356   0b110101
#define DOTS2356   0b110110
#define DOTS12356  0b110111
#define DOTS456    0b111000
#define DOTS1456   0b111001
#define DOTS2456   0b111010
#define DOTS12456  0b111011
#define DOTS3456   0b111100
#define DOTS13456  0b111101
#define DOTS23456  0b111110
#define DOTS123456 0b111111

#define UNIVERSAL 0
#define ENGLISH   1
#define HINDI     2
#define KANNADA   3

 #define MAX_WORD_LENGTH     15
 #define MAX_WORDLIST_LENGTH 10
 #define MAX_MP3_NAME_LENGTH  5
 #define MAX_FILESET_LENGTH	  5

typedef struct glyph glyph_t;

// Stores information about single glyph; used to build scripts
struct glyph {
	char pattern;			/* 0bxxxxxx 6-bit pattern Braille representation */
	char sound[MAX_MP3_NAME_LENGTH];			/* BBBB in AAA_BBBB.mp3 soundfile */
	glyph_t* prev;			/* Pointer to previous glyph in linked list */
	glyph_t* next;			/* Pointer to next glyph in linked list */
};

typedef struct cell {
	char pattern;			/* 0bxxxxxx 6-bit pattern Braille representation */
} cell_t;

typedef struct letter {
	char name[MAX_MP3_NAME_LENGTH];
	char lang_enum;
	cell_t* cells;
	int num_cells;
} letter_t;

typedef struct word {
	char name[MAX_WORD_LENGTH];
	int length_name;
	letter_t* letters;
	int num_letters;
	char lang_enum;
	int curr_letter;
	int curr_glyph;
} word_t; 

typedef struct alphabet {
	letter_t* letters;
	int num_letters;
	char lang_enum;
	// other info can eventually go in here
} alphabet_t;

typedef struct wordlist {
	word_t* words;
	int* order;
	int num_words;
	int index;
} wordlist_t;

// Structure representing a script (alphabet) - deprecated
typedef struct script_old {
	int length;				/* Length of first cell glyph array */
	int index;				/* Current index */
	char fileset[MAX_FILESET_LENGTH];		/* Fileset on SD card; 4 characters long */
	glyph_t* glyphs; 		/* Pointer to array of first cell glyphs */
} script_old_t;

// Structure representing a script/alphabet.
// Now represents both the glyphs and the letters, which may be more than
// one glyph each.

typedef struct script {
	int length;				          /* Length of glyph array */
	int num_letters;			      /* Number of actual letters (<length) */
	int index;			         	  /* Current index */
	char fileset[MAX_FILESET_LENGTH]; /* Fileset on SD card; 4 characters long */
	glyph_t* glyphs; 		          /* Pointer to array of glyphs */
	int* letters;		              /* Pointer to array of valid indices into glyphs */
} script_t;


typedef struct word_node {
	glyph_t* data;
	struct word_node* next;	
} word_node_t;

// Cell functions
void print_cell_pattern(cell_t* cell);
bool cell_equals(cell_t* cell1, cell_t* cell2);
bool glyph_equals(glyph_t* g1, glyph_t* g2); // deprecated

// Letter functions
bool letter_equals(letter_t* letter1, letter_t* letter2);
letter_t* get_eng_letter_by_char(char c);
void print_letter(letter_t* letter);

// Word functions
void initialize_english_word(char* string, letter_t* letter_array, int num_letters, word_t* word);
int parse_string_into_eng_word(char* string, word_t* word);
void word_to_cell_array(word_t* word, cell_t* arr);
void decrement_word_index(word_t* word);
void increment_word_index(word_t* word);
void get_next_cell_in_word(word_t* word, cell_t* next_cell);
char* get_lang(word_t* word);
void print_word(word_t* word);

#ifdef DEBUGMODE
#else
void speak_word(word_t* word);
void speak_letters_in_word(word_t* word);
void speak_letters_so_far(word_t* word);
#endif

// Wordlist functions
void initialize_wordlist(word_t* words, int num_words, wordlist_t* list);
void strings_to_wordlist(char** strings, int num_strings, wordlist_t* list); // BUGGY
void print_words_in_list(wordlist_t* wl);
void get_next_word_in_wordlist(wordlist_t* wl, word_t** next_word);

int random_between(int i, int j);
void shuffle(int len, int* int_array);
void unshuffle(int len, int* int_array);

#endif /* _DATASTRUCTURES_H_ */
