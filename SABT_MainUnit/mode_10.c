/**
 * @file mode_10.c
 * @brief Mode 10 code - Learn and practice contracted Braille
 * @author Poornima Kaniarasu (pkaniara)
 */

#include "globals.h"
#include "Modes.h"
#include "audio.h"
#include "common.h"
#include "script_eng_contraction.h"
#include "mp3s.h"

#define NUM_SUB_MODES 3

char expected_dot;
char *sub_mode[NUM_SUB_MODES] = {"PCON","PABR","DICT"};
static int game_mode = 0;
static int word_num_inset = 20;
static int set = 0;
struct dir_Structure *location;
static char fname[12];
static glyph_t* g1;
static glyph_t* g2;

static char cell1_pattern;
static char cell2_pattern;


/**
 * @brief  Given a char, in cell, play the corresponding number sound file
 *          NOTE: Deprecated
 * @return Void
 */

void play_requested_dot(char play_dot) {
    char req_mp3[10];
    sprintf((char*)req_mp3, "dot_%c", play_dot);
    play_mp3(NULL,req_mp3);
}

void mode_10_main() {

 switch(current_state) {
    case mode_10_INITIAL:
        play_welcome();
        play_submode_choice();
    game_mode = 0;
    current_state = mode_10_SELECT_MODE; 
    got_input = false;
    break;

    case mode_10_SELECT_MODE:
        break;
 
    case mode_10_INIT:
        switch(game_mode){
            case 0:
                break;
            case 1:
                // Welcomes the user to the submode 2
                play_direction(MP3_UNDER_DEVEL);
                break;
            case 2:
                // Welcomes the user to the submode 1
                play_direction(MP3_UNDER_DEVEL);
                break;
            }
        current_state = mode_10_REQUEST_WRITE;
        break;

    case mode_10_REQUEST_WRITE:
        play_direction(MP3_PLEASE_WRITE);
        current_state = mode_10_REQUEST_INPUT;
        if (word_num_inset == 36) {
            set = set + 1;
            word_num_inset = 0;
        }
        else
            word_num_inset = word_num_inset + 1;
        break;

    case mode_10_REQUEST_INPUT:
      switch(game_mode){
        case 0:
            // to write <word><set>_<num> please press
            sprintf(fname, "c_%d_w_%d.mp3", set, word_num_inset-1);
            log_msg("%s", fname);
            
            bool e = convert_file_name ((unsigned char*)fname); //convert file_name into FAT format
            if (e)
                return;
            location = find_files(GET_FILE,(unsigned char*)fname);
            
            if (!location) {
                if (word_num_inset == 36){
                    set = set + 1;
                    word_num_inset = 0;
                }
                else
                    word_num_inset = word_num_inset + 1;
                return;
            }
            play_mp3(NULL, fname);
            play_direction(MP3_PRESS_DOTS);
                    
            current_state = mode_10_SPELL_PATTERN;
            break;

        case 1: // not yet implemented
            break;
        case 2: // not yet implemented
            break;
      }
      break;

    case mode_10_SPELL_PATTERN:
        if (fname[1] != '0'){
            g1 = &contraction_pattern[CHARTOINT(fname[0])];   // Stores the preceding pattern for the cell
            play_dot_sequence(g1);
            play_direction(MP3_NEXT_CELL);
        }
        else g1 = NULL;
        int sym;
        if (strlen(fname) == 6)
            sym = 10*CHARTOINT(fname[4]) + CHARTOINT(fname[5]);
        else
            sym = CHARTOINT(fname[4]);          // Stores the alphabet/symbol glyph
        g2 = &contraction_glyphs[sym-1];
        play_dot_sequence(g2);
        current_state = mode_10_CELL1;
        io_init();
        break;
        
    case mode_10_CELL1:
        if (!g1) {
            current_state = mode_10_CELL2;
            break;
        }
        cell = get_cell();
        cell1_pattern = GET_CELL_PATTERN(cell);
        cell_control = GET_CELL_CONTROL(cell);
        if (cell1_pattern == NO_DOTS)
            break;
        switch (cell_control) {
            case WITH_ENTER:
                log_msg("ENTER");
                current_state = mode_10_CHECK;          
                break;
            case WITH_LEFT:
                log_msg("LEFT");
                play_direction(MP3_NEXT_CELL);
                current_state = mode_10_CELL2;
                break;
            case WITH_RIGHT:
                log_msg("RIGHT");
                play_lang_audio(MP3_BLANK);
                cell1_pattern = NO_DOTS;        
                break;
            case WITH_CANCEL:
                log_msg("User pressed CANCEL");
                break;
        }
        break;

    
    case mode_10_CELL2:      
        cell = get_cell();
        cell2_pattern = GET_CELL_PATTERN(cell);
        cell_control = GET_CELL_CONTROL(cell);

        if (cell2_pattern == NO_DOTS)
            break;

        switch (cell_control) {
            case WITH_ENTER:
                log_msg("ENTER");
                current_state = mode_10_CHECK;          
                break;
        case WITH_LEFT:
            log_msg("LEFT");
            break;
        case WITH_RIGHT:
            log_msg("RIGHT");
            if (cell2_pattern && g1) {     
                play_mode_audio(MP3_CELL_1); 
                play_cell((unsigned char)cell1_pattern);
                play_mode_audio(MP3_CELL_2); 
                cell2_pattern = NO_DOTS;
            }
            else {
                play_lang_audio(MP3_BLANK);
                cell1_pattern = NO_DOTS;
                cell2_pattern = NO_DOTS;
                current_state = mode_10_CELL1;
          }       
          break;

        case WITH_CANCEL:
          log_msg("User pressed CANCEL");
          break;
        }
        break;

    case mode_10_CHECK:
        if (g1==NULL || cell1_pattern == g1->pattern) {
            if (cell2_pattern == g2->pattern) {
                play_feedback(MP3_GOOD);
                current_state = mode_10_REQUEST_WRITE;
            }
            else {
                play_feedback(MP3_NO);
                play_feedback(MP3_TRY_AGAIN);
                cell1_pattern = NO_DOTS;
                cell2_pattern = NO_DOTS;
                current_state = mode_10_REQUEST_INPUT;
            }
        }        
        break;

    default:
        log_msg("Invalid state_t %d", current_state);
        quit_mode();
        break;
    }
}

void mode_10_reset() {
    game_mode = 0;
    word_num_inset = 0;
    set = 0;
    current_state = mode_10_INITIAL;
    cell1_pattern = NO_DOTS;
    cell2_pattern = NO_DOTS;
    g1 = NULL;
    g2 = NULL;
}

void mode_10_call_mode_yes_answer(void) {
    if (current_state == mode_10_SELECT_MODE)
        current_state = mode_10_INIT;
}

void mode_10_call_mode_no_answer(void) {   
    mode_10_reset(); // Pressing CANCEL exits to submode menu
}

void mode_10_input_dot(char this_dot) {
    last_dot = this_dot;
    play_requested_dot(this_dot); 
}

void mode_10_input_cell(char this_cell) {
    if (last_dot != 0) {
        cell = this_cell;
        got_input = true;
    }
}

void mode_10_call_mode_left() {
    if (current_state == mode_10_SELECT_MODE) {
        game_mode += 1;
        if (game_mode > NUM_SUB_MODES-1)
            game_mode = 0;
        play_mp3("mode_10", sub_mode[game_mode]);  // @todo what are these?
    }       
}

void mode_10_call_mode_right() {
    if (current_state == mode_10_SELECT_MODE) {
        game_mode -= 1;
        if (game_mode < 0)
            game_mode = NUM_SUB_MODES-1;
        play_mp3("mode_10", sub_mode[game_mode]);
    }
}
