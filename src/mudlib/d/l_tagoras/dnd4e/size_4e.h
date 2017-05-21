#include <size.h>

/*
Size Example Space Reach
Tiny Rat 1/2* 0
Small Goblin 1 1
Medium Human 1 1
Large Troll 2 × 2 1.2
Huge Death titan 3 × 3 2.3
Gargantuan Ancient dragon 4 × 4 or larger 3.4
*/
#define S_TINY			101
#define S_SMALL			102
#define S_MEDIUM		103
#define S_LARGE			104
#define S_HUGE			105
#define S_GARGANTUAN	106

// Compatibiliidad
#define SIZE_SIM_DND4E ([\
	P_SIZE_GENERIC:	S_MEDIUM,\
	P_SIZE_SMALL:	S_SMALL,\
	P_SIZE_MEDIUM:	S_MEDIUM,\
	P_SIZE_LARGE:	S_LARGE,\
	P_SIZE_HUGE:	S_HUGE,\
])

#define SIZE_DND4E_SIM ([\
	S_TINY:			P_SIZE_SMALL,\
	S_SMALL:		P_SIZE_SMALL,\
	S_MEDIUM:		P_SIZE_MEDIUM,\
	S_LARGE:		P_SIZE_LARGE,\
	S_HUGE:			P_SIZE_HUGE,\
	S_GARGANTUAN:	P_SIZE_HUGE,\
])
