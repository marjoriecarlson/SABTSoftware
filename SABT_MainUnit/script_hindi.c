#include "script_hindi.h"

// Hindi script array
glyph_t glyphs_hindi[SCRIPT_HINDI_LENGTH] = {
	{HIN_A, "A", NULL, NULL},		// 0
	{HIN_AA, "AA", NULL, NULL},		// 1
	{HIN_I, "I", NULL, NULL},		// 2
	{HIN_II, "II", NULL, NULL},		// 3
	{HIN_U, "U", NULL, NULL},		// 4
	{HIN_UU, "UU", NULL, NULL},		// 5
	{HIN_RU_1, "RU", NULL, &glyphs_hindi[7]},  // 6
	{HIN_RU_2, "NCEL", &glyphs_hindi[6] ,NULL}, // 7

	{HIN_EE, "EE", NULL, NULL},		// 8
	{HIN_AI, "AI", NULL, NULL},		// 9
	{HIN_OO, "OO", NULL, NULL},		// 10
	{HIN_AU, "AU", NULL, NULL},		// 11
	{HIN_AM, "AM", NULL, NULL},		// 12
	{HIN_AHA, "AHA", NULL, NULL},	// 13

	{HIN_KA, "KA", NULL, NULL},		// 14
	{HIN_KHA, "KHA", NULL, NULL},	// 15
	{HIN_GA, "GA", NULL, NULL},		// 16
	{HIN_GHA, "GHA", NULL, NULL},	// 17
	{HIN_NNA, "NNA", NULL, NULL},	// 18

	{HIN_CHA, "CHA", NULL, NULL},	// 19
	{HIN_CHHA, "CHHA", NULL, NULL},	// 20
	{HIN_JA, "JA", NULL, NULL},		// 21
	{HIN_JHA, "JHA", NULL, NULL},	// 22
	{HIN_NYAA, "NYAA", NULL, NULL},	// 23

	{HIN_TTA, "TTA", NULL, NULL},	// 24
	{HIN_TTHA, "TTHA", NULL, NULL},	// 25
	{HIN_DDA, "DDA", NULL, NULL},	// 26
	{HIN_DDHA, "DDHA", NULL, NULL},	// 27
	{HIN_GNA, "GNA", NULL, NULL},	// 28

	{HIN_TA, "TA", NULL, NULL},		// 29
	{HIN_THA, "THA", NULL, NULL},	// 30
	{HIN_DA, "DA", NULL, NULL},		// 31
	{HIN_DHA, "DHA", NULL, NULL},	// 32
	{HIN_NA, "NA", NULL, NULL},		// 33

	{HIN_PA, "PA", NULL, NULL},		// 34
	{HIN_PHA, "PHA", NULL, NULL},	// 35
	{HIN_BA, "BA", NULL, NULL},		// 36
	{HIN_BHA, "BHA", NULL, NULL},	// 37
	{HIN_MA, "MA", NULL, NULL},		// 38

	{HIN_YA, "YA", NULL, NULL},		// 39
	{HIN_RA, "RA", NULL, NULL},		// 40
	{HIN_LA, "LA", NULL, NULL},		// 41
	{HIN_VA, "VA", NULL, NULL},		// 42

	{HIN_SHA, "SHA", NULL, NULL},	// 43
	{HIN_SHHA, "SHHA", NULL, NULL},	// 44
	{HIN_SA, "SA", NULL, NULL},		// 45
	{HIN_HA, "HA", NULL, NULL},		// 46

	{HIN_KSHA, "KSHA", NULL, NULL},								// 47
	{HIN_TRA_1, "TRA", NULL, &glyphs_hindi[49]},				// 48
	{HIN_TRA_2, "NCEL", &glyphs_hindi[48], &glyphs_hindi[50]},	// 49
	{HIN_TRA_3, "NCEL", &glyphs_hindi[49], NULL},				// 50
	{HIN_JNA, "JNA", NULL, NULL},								// 51
	{HIN_SHRA_1, "SHRA", NULL, &glyphs_hindi[53]},				// 52
	{HIN_SHRA_2, "NCEL", &glyphs_hindi[52], &glyphs_hindi[54]},// 53
	{HIN_SHRA_3, "NCEL", &glyphs_hindi[53], NULL}				// 54
};

int letters_hindi[SCRIPT_HINDI_NUM_LETTERS] = {
	0,  1,  2,  3,  4,  5,  6,       8,  9,
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
	30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
	40, 41, 42, 43, 44, 45, 46, 47, 48,
	    51, 52 };

script_t script_hindi = {
	SCRIPT_HINDI_LENGTH,
	SCRIPT_HINDI_NUM_LETTERS,
	0,
	SCRIPT_HINDI_FILESET,
	glyphs_hindi,
	letters_hindi
};

// new stuff

// used in multicell letters
#define HALANT 		DOT_4
#define ABBREV 		DOT_5
#define RA 			DOT_1 | DOT_2 | DOT_3 | DOT_5
#define TA 			DOT_2 | DOT_3 | DOT_4 | DOT_5
#define SHA 		DOT_1 | DOT_4 | DOT_6

// one-cell letters
cell_t a_cell_h   	= DOT_1;
cell_t aa_cell     	= DOT_3 | DOT_4 | DOT_5;
cell_t i_cell_h		= DOT_2 | DOT_4;
cell_t ii_cell	   	= DOT_3 | DOT_5;
cell_t u_cell_h   	= DOT_1 | DOT_3 | DOT_6;
cell_t uu_cell     	= DOT_1 | DOT_2 | DOT_5 | DOT_6;

cell_t e_cell_h		= DOT_1 | DOT_5;
cell_t ai_cell		= DOT_3 | DOT_4;
cell_t o_cell_h 	= DOT_1 | DOT_3 | DOT_5;
cell_t au_cell 		= DOT_2 | DOT_4 | DOT_6;
cell_t am_cell		= DOT_5 | DOT_6;
cell_t aha_cell		= DOT_6;

cell_t ka_cell 		= DOT_1 | DOT_3;
cell_t kha_cell 	= DOT_4 | DOT_6;
cell_t ga_cell 		= DOT_1 | DOT_2 | DOT_4 | DOT_5;
cell_t gha_cell 	= DOT_1 | DOT_2 | DOT_6;
cell_t nna_cell 	= DOT_3 | DOT_4 | DOT_6;

cell_t cha_cell 	= DOT_1 | DOT_4;
cell_t chha_cell 	= DOT_1 | DOT_6;
cell_t ja_cell 		= DOT_2 | DOT_4 | DOT_5;
cell_t jha_cell 	= DOT_3 | DOT_5 | DOT_6;
cell_t nyaa_cell 	= DOT_2 | DOT_5;

cell_t tta_cell 	= DOT_2 | DOT_3 | DOT_4 | DOT_5 | DOT_6;
cell_t ttha_cell	= DOT_2 | DOT_4 | DOT_5 | DOT_6;
cell_t dda_cell 	= DOT_1 | DOT_2 | DOT_4 | DOT_6;
cell_t ddha_cell	= DOT_1 | DOT_2 | DOT_3 | DOT_4 | DOT_5 | DOT_6;
cell_t gna_cell		= DOT_3 | DOT_4 | DOT_5 | DOT_6;

cell_t ta_cell 		= TA;
cell_t tha_cell 	= DOT_1 | DOT_4 | DOT_5 | DOT_6;
cell_t da_cell 		= DOT_1 | DOT_4 | DOT_5;
cell_t dha_cell 	= DOT_2 | DOT_3 | DOT_4 | DOT_6;
cell_t na_cell 		= DOT_1 | DOT_3 | DOT_4 | DOT_5;

cell_t pa_cell 		= DOT_1 | DOT_2 | DOT_3 | DOT_4;
cell_t pha_cell 	= DOT_2 | DOT_3 | DOT_5;
cell_t ba_cell 		= DOT_1 | DOT_2;
cell_t bha_cell		= DOT_4 | DOT_5;
cell_t ma_cell 		= DOT_1 | DOT_3 | DOT_4;

cell_t ya_cell		= DOT_1 | DOT_3 | DOT_4 | DOT_5 | DOT_6;
cell_t ra_cell		= RA;
cell_t la_cell		= DOT_1 | DOT_2 | DOT_3;
cell_t va_cell		= DOT_1 | DOT_2 | DOT_3 | DOT_6;

cell_t sha_cell		= SHA;
cell_t shha_cell	= DOT_1 | DOT_2 | DOT_3 | DOT_4 | DOT_6;
cell_t sa_cell		= DOT_2 | DOT_3 | DOT_4;
cell_t ha_cell		= DOT_1 | DOT_2 | DOT_5;

cell_t ksha_cell	= DOT_1 | DOT_2 | DOT_3 | DOT_4 | DOT_5;
cell_t jna_cell		= DOT_1 | DOT_5 | DOT_6;

// multicell letters

cell_t ru_cells[2] 		= {ABBREV, RA};
cell_t tra_cells[3]		= {HALANT, TA, RA};
cell_t shra_cells[3]	= {ABBREV, SHA, RA};

#define HIND_A 		{"a", &a_cell_h, 1, HINDI}
#define HIND_AA 	{"aa", &aa_cell, 1, HINDI}
#define HIND_I 		{"i", &i_cell_h, 1, HINDI}
#define HIND_II 	{"ii", &ii_cell, 1, HINDI}
#define HIND_U 		{"u", &u_cell_h, 1, HINDI}
#define HIND_UU		{"uu", &uu_cell, 1, HINDI}

#define HIND_E 		{"e", &e_cell_h, 1, HINDI}
#define HIND_AI 	{"ai", &ai_cell, 1, HINDI}
#define HIND_O 		{"o", &o_cell_h, 1, HINDI}
#define HIND_AU 	{"au", &au_cell, 1, HINDI}
#define HIND_AM 	{"am", &am_cell, 1, HINDI}
#define HIND_AHA 	{"aha", &aha_cell, 1, HINDI}

#define HIND_KA 	{"ka", &ka_cell, 1, HINDI}
#define HIND_KHA 	{"kha", &kha_cell, 1, HINDI}
#define HIND_GA 	{"ga", &ga_cell, 1, HINDI}
#define HIND_GHA 	{"gha", &gha_cell, 1, HINDI}
#define HIND_NNA 	{"nna", &nna_cell, 1, HINDI}

#define HIND_CHA 	{"cha", &cha_cell, 1, HINDI}
#define HIND_CHHA 	{"chha", &chha_cell, 1, HINDI}
#define HIND_JA		{"ja", &ja_cell, 1, HINDI}
#define HIND_JHA	{"jha", &jha_cell, 1, HINDI}
#define HIND_NYAA 	{"nyaa", &nyaa_cell, 1, HINDI}

#define HIND_TTA 	{"tta", &tta_cell, 1, HINDI}
#define HIND_TTHA 	{"ttha", &ttha_cell, 1, HINDI}
#define HIND_DDA 	{"dda", &dda_cell, 1, HINDI}
#define HIND_DDHA 	{"ddha", &ddha_cell, 1, HINDI}
#define HIND_GNA 	{"gna", &gna_cell, 1, HINDI}

#define HIND_TA 	{"ta", &ta_cell, 1, HINDI}
#define HIND_THA 	{"tha", &tha_cell, 1, HINDI}
#define HIND_DA 	{"da", &da_cell, 1, HINDI}
#define HIND_DHA 	{"dha", &dha_cell, 1, HINDI}
#define HIND_NA 	{"na", &na_cell, 1, HINDI}

#define HIND_PA 	{"pa", &pa_cell, 1, HINDI}
#define HIND_PHA 	{"pha", &pha_cell, 1, HINDI}
#define HIND_BA 	{"ba", &ba_cell, 1, HINDI}
#define HIND_BHA 	{"bha", &bha_cell, 1, HINDI}
#define HIND_MA 	{"ma", &ma_cell, 1, HINDI}

#define HIND_YA 	{"ya", &ya_cell, 1, HINDI}
#define HIND_RA 	{"ra", &ra_cell, 1, HINDI}
#define HIND_LA 	{"la", &la_cell, 1, HINDI}
#define HIND_VA 	{"va", &va_cell, 1, HINDI}

#define HIND_SHA 	{"sha", &sha_cell, 1, HINDI}
#define HIND_SHHA 	{"shha", &shha_cell, 1, HINDI}
#define HIND_SA 	{"sa", &sa_cell, 1, HINDI}
#define HIND_HA 	{"ha", &ha_cell, 1, HINDI}

// A few of the combination consonants.
// This is not an exhaustive list.
#define HIND_KSHA 	{"ksha", &ksha_cell, 1, HINDI}
#define HIND_TRA 	{"tra", tra_cells, 3, HINDI}
#define HIND_JNA 	{"jna", &jna_cell, 1, HINDI}
#define HIND_SHRA 	{"shra", shra_cells, 3, HINDI}
#define HIND_RU		{"ru", ru_cells, 2, HINDI}

letter_t hindi_letters[50] = {
	HIND_A, HIND_AA, HIND_I, HIND_II, HIND_U,
	HIND_UU, HIND_E, HIND_AI, HIND_O, HIND_AU,
	HIND_AM, HIND_AHA,
	HIND_KA, HIND_KHA, HIND_GA, HIND_GHA, HIND_NNA,
	HIND_CHA, HIND_CHHA, HIND_JA, HIND_JHA, HIND_NYAA,
	HIND_TTA, HIND_TTHA, HIND_DDA, HIND_DDHA, HIND_GNA,
	HIND_TA, HIND_THA, HIND_DA, HIND_DHA, HIND_NA,
	HIND_PA, HIND_PHA, HIND_BA, HIND_BHA, HIND_MA,
    HIND_YA, HIND_RA, HIND_LA, HIND_VA,
    HIND_SHA, HIND_SHHA, HIND_SA, HIND_HA,
    HIND_KSHA, HIND_TRA, HIND_JNA, HIND_SHRA, HIND_RU };

alphabet_t hindi_alphabet = {hindi_letters, 50, HINDI};
