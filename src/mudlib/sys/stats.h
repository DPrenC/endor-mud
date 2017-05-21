/* Este archivo guarda las stats de cada gremio...
	[h] Nyh

 09-11-03 [h] Creación

*/

#include <attributes.h>
#include <gremios.h>

#ifndef _STATS_H
#define _STATS_H

#ifndef MAX_STAT
#define MAX_STAT	30
#endif
#define HLP_STAT	40
#define STAT_MIN	"Min"
#define STAT_MAX	"Max"
#define STAT_HLP	"HLP"

//#define STATS ({ P_STR, P_DEX, P_CON, P_INT }) //en atributes.h
#define STATS_TYPE ({ STAT_MIN, STAT_MAX, STAT_HLP })

#define STATS_BASE	([ \
		STAT_MIN:	([P_STR:  0, P_DEX:  0, P_CON:  0, P_INT:  0, "Cha": 0, P_WIS:  0 ]), \
		STAT_MAX:	([P_STR:  0, P_DEX:  0, P_CON:  0, P_INT:  0, "Cha": 0, P_WIS:  0 ]), \
		STAT_HLP:	([P_STR:  0, P_DEX:  0, P_CON:  0, P_INT:  0, "Cha": 0, P_WIS:  0 ]), \
		])
#define STATS_ASESINOS	([ \
		STAT_MIN:	([P_STR:  2, P_DEX:  3, P_CON:  1, P_INT:  2, "Cha": 1, P_WIS: 1 ]), \
		STAT_MAX:	([P_STR:  0, P_DEX:  5, P_CON: -5, P_INT:  0, "Cha": 1, P_WIS: -2  ]), \
		STAT_HLP:	([P_STR:  0, P_DEX:  5, P_CON: -5, P_INT:  0, "Cha": -2, P_WIS: 1  ]), \
		])
#define STATS_AVENTUREROS	([ \
		STAT_MIN:	([P_STR:  1, P_DEX:  1, P_CON:  1, P_INT:  1, "Cha": 1, P_WIS: 1 ]), \
		STAT_MAX:	([P_STR:-2, P_DEX:2, P_CON:2, P_INT:2, "Cha": 2, P_WIS: 1 ]), \
		STAT_HLP:	([P_STR:1, P_DEX:0, P_CON:2, P_INT:1, "Cha": 2, P_WIS: 1 ]), \
		])
#define STATS_CONJURADORES	([ \
		STAT_MIN:	([P_STR:  2, P_DEX:  3, P_CON:  1, P_INT:  3, "Cha": 1, P_WIS: 3  ]), \
		STAT_MAX:	([P_STR: -2, P_DEX:  0, P_CON: -3, P_INT:  5, "Cha": 0, P_WIS: 5  ]), \
		STAT_HLP:	([P_STR: -2, P_DEX:  0, P_CON: -3, P_INT:  5, "Cha": 0, P_WIS: 5  ]), \
		])
#define STATS_GUARDABOSQUES	([ \
		STAT_MIN:	([P_STR:  1, P_DEX:  2, P_CON:  1, P_INT:  2, "Cha": 1, P_WIS: 3  ]), \
		STAT_MAX:	([P_STR: -1, P_DEX:  1, P_CON: -3, P_INT:  3, "Cha": -1, P_WIS: 3  ]), \
		STAT_HLP:	([P_STR: -1, P_DEX:  1, P_CON: -3, P_INT:  3, "Cha": -1, P_WIS: 3  ]), \
		])
#define STATS_GUERREROS	([ \
		STAT_MIN:	([P_STR:  7, P_DEX:  4, P_CON:  6, P_INT:  1, "Cha": 1, P_WIS: 1  ]), \
		STAT_MAX:	([P_STR:  7, P_DEX: -1, P_CON:  4, P_INT:-10, "Cha": -3, P_WIS: -2  ]), \
		STAT_HLP:	([P_STR:  7, P_DEX: -1, P_CON:  4, P_INT:-10, "Cha": -3, P_WIS: -2  ]), \
		])
#define STATS_HECHICEROS	([ \
		STAT_MIN:	([P_STR:  1, P_DEX:  1, P_CON:  2, P_INT:  4, "Cha": 1, P_WIS: 4  ]), \
		STAT_MAX:	([P_STR:-10, P_DEX:  0, P_CON:-10, P_INT: 20, "Cha": -2, P_WIS: 20  ]), \
		STAT_HLP:	([P_STR:-10, P_DEX:  0, P_CON:-10, P_INT: 20 ]), \
		])
#define STATS_KISALAS	([ \
		STAT_MIN:	([P_STR:  2, P_DEX:  2, P_CON:  1, P_INT:  3, "Cha": 1, P_WIS: 2  ]), \
		STAT_MAX:	([P_STR: -2, P_DEX:  2, P_CON: -4, P_INT:  4, "Cha": -1, P_WIS: 3  ]), \
		STAT_HLP:	([P_STR: -2, P_DEX:  2, P_CON: -4, P_INT:  4, "Cha": -1, P_WIS: 3  ]), \
		])
#define STATS_EXPLORADORES	([ \
		STAT_MIN:	([P_STR:  1, P_DEX:  1, P_CON:  1, P_INT:  1, "Cha": 1, P_WIS: 1 ]), \
		STAT_MAX:	([P_STR:-2, P_DEX:2, P_CON:2, P_INT:2, "Cha": 2, P_WIS: 1 ]), \
		STAT_HLP:	([P_STR:1, P_DEX:0, P_CON:2, P_INT:1, "Cha": 2, P_WIS: 1 ]), \
		])
#define STATS_MAP ([ \
		GC_KISALAS:	 STATS_KISALAS,		\
		GC_GUERREROS:	 STATS_GUERREROS,	\
		GC_CONJURADORES: STATS_CONJURADORES,	\
		GC_GUARDABOSQUES:STATS_GUARDABOSQUES,	\
		GC_HECHICEROS:	 STATS_HECHICEROS,	\
		GC_ASESINOS:	 STATS_ASESINOS,	\
		GC_AVENTUREROS:	 STATS_AVENTUREROS,	\
		    GC_EXPLORADORES:	 STATS_EXPLORADORES,	\
		GC_EXPERTO:	 STATS_BASE,		\//pnj
		GC_LUCHADOR:	 STATS_GUERREROS,	\//pnj
		GC_NINGUNO:	 STATS_BASE,		\//pnj
		GC_MAGO:	 STATS_CONJURADORES,	\//pnj
		GC_TORPE:	 STATS_BASE,		\//pnj
		])

#endif
