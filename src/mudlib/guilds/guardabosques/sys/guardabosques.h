/* SIMAURIA '/guilds/guardabosques/sys/guardabosques.h'
   ====================================================

   20-10-99 [t] Creación
*/

#ifndef __GUARDABOSQUES_H__
#define __GUARDABOSQUES_H__

#include <properties.h>
#include <combat.h>
#include <spells.h>
#include <skills.h>
#include <moving.h>

#define BASE      	        PPATH "guardabosques/"
#define OBJETO(x)          	BASE "obj/"+x
#define PNJ(x)              BASE "pnj/" + x

#define LOG(x,y)        	write_file(GUILDLOGPATH "guardabosques/" + x, y)

#define TRAIN               BASE+"train/"
#define TRAIN_BASE          TRAIN "train_base"
#define TRANSMUTATED_STATE	"_transmutado"

#define magia (["convocar":     MAG_CONVOCAR,\
		        "corteza":      MAG_CORTEZA,\
		        "hierro":       MAG_HIERRO,\
		        "piedra":       MAG_PIEDRA,\
		        "calmar":       MAG_CALMAR,\
		        "sangre":       MAG_SANGRE,\
		        "transmutacion":MAG_TRANSMUTAR,\
		        "transmutación":MAG_TRANSMUTAR,\
		        "transmutar":   MAG_TRANSMUTAR,\
"miedo": MAG_MIEDO])

#endif
