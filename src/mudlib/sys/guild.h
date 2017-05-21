/**
 * SIMAURIA '/sys/guild.h'
 */

#ifndef _GUILD_
#define _GUILD_

#include <properties.h>
#include <gremios.h>

#define G_GUILDOBJ    "/obj/lib/guildobj"

#define G_MEMBER     1
#define G_LEADER     2
#define G_VICELEADER 3
#define G_CREATOR    4
#define G_MINSTATS ([P_CON:1,P_STR:1,P_DEX:1,P_INT:1, P_WIS:1, "Cha":1])
#define G_MAXSTATS ([P_CON:30,P_STR:30,P_DEX:30,P_INT:30, P_WIS:30, "Cha":30])

#define DEBUG_MAX_XP
//----

#define MAX_LEVEL_DIF	7 // Maxima diferencia aceptable de nivel al matar
#define FACTOR_EXP_SIN_GREMIO 0.6 // si no tienes gremio das menos xp
#define FACTOR_EXP	17.5 //pa q sea float
#define FACTOR_NIV	1.3 //esto es raiz 4 de 2 y viene +- del D&D3
#define MAX_XP		10000
#define NIVEL_MAXIMO	2000

//para quien use el antiguo G_COSTS
#define OLD_G_COSTS ([50:508000000,\
        49:476000000, 48:445000000, 47:415000000, 46:386000000, 45:358000000,\
        44:331000000, 43:305000000, 42:280000000, 41:256000000, 40:233000000,\
        39:211000000, 38:190000000, 37:170000000, 36:151000000, 35:133000000,\
        34:116000000, 33:100000000, 32: 85000000, 31: 71000000, 30: 58000000,\
        29: 46000000, 28: 35000000, 27: 25000000, 26: 17085937, 25: 11390625,\
        24:  7593750, 23:  5062500, 22:  3375000, 21:  2250000, 20:  1500000,\
        19:   998506, 18:   665671, 17:   443781, 16:   295854, 15:   197236,\
        14:   131491, 13:    87661, 12:    58441, 11:    38961, 10:    25974,\
         9:    17316,  8:    11544,  7:     7696,  6:     5131,  5:     3421,\
         4:     2281,  3:     1521,  2:     1014,  1:        0])

#define Q_LEVEL   0
#define Q_CREATOR 1
#define Q_SHORT   2
#define Q_LONG    3

#define MEMBER_ID       0
#define MEMBER_TIME 	1
#define MEMBER_LEVEL 	2
#define MEMBER_STAT 	3
#define MEMBER_ENTRIES 	4 // Number of entries in the mapping

#define MBR_MSG_NAME    0
#define MBR_MSG_DATE    1
#define MBR_MSG_TEXT    2
#define MBR_MSG_ENTRIES 3

#define BANISH_ID       0
#define BANISH_TIME 	1
#define BANISH_BANISHER	2
#define BANISH_REASON 	3
#define BANISH_ENTRIES  4

#define ERR_NOPLAYER	"No existe ese jugador.\n"
#define ERR_NONAME	"No has puesto ningún nombre.\n"
#define ERR_NOALLOW	"No puedes banear a nadie.\n"
#define ERR_ALREADY	"Ese jugador ya está baneado.\n"
#define ERR_NOT_BANISHED "Ese jugador no está baneado.\n"
#define ERR_UNKNOWN      "Error desconocido al insertar el baneo"
#define NO_ERR		"Ok.\n"

#define ADV_OK 		0
#define ADV_NOT_XP 	1
#define ADV_NOT_LEVEL 	2
#define ADV_OTHER_FIRST	3
#define ADV_TOO_HIGH 	4

#endif
