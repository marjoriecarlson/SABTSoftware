/**
 * @file Globals.h
 * @brief global definitions for the MCU
 * @author Nick LaGrow (nlagrow)
 * @author Alex Etling (petling)
 * @author Kory Stiger (kstiger)
 */

#ifndef _GLOBALS_H_
#define _GLOBALS_H

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdint.h>
#include <stdbool.h> 
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "FAT32.h"
#include "USART_PC.h"
#include "SD_routines.h"
#include "VS1053.h"
#include "SPI.h"
#include "USART_Keypad.h"
#include "UI_Handle.h"
#include "PC_Handle.h"

#define F_CPU 8000000UL

volatile unsigned char number_of_modes;
volatile unsigned char ui_modes[10];

volatile unsigned char *g_file_to_play;
unsigned char g_file_name[FILE_NAME_LEN];
//used throughout the dict_process
unsigned char dict_file_name[FILE_NAME_LEN];

volatile char temp_cnt;

volatile bool playing_mp3;

//TODO remove
void set_last_dot(char dot);
void set_last_dot2(char dot);
void set_last_dot3(char dot);

#define PRINTF(msg) \
  usart_transmit_string_to_pc((unsigned char*)msg);
#define CHARTOINT(c)     ((c) - '0')

#endif /* _GLOBALS_H_ */
