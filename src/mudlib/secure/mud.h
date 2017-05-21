/**
 * SIMAURIA '/secure/mud.h'
 */

#ifndef __MUD_H__
#define __MUD_H__

#include <config.h>

/* EFUNS */

#define TO          this_object()
#define TP          this_player()
#define PO          previous_object()
#define TI          this_interactive()
#define ENV(x)      environment(x)
#define CAP(x)      capitalize(x)
#define LOWER(x)    lower_case(x)
#define UPPER(x)	upper_case(x)

/* MANEJO DE JUGADORES */

#define NNAME(x)    x->QueryName()
#define NREAL(x)    x->QueryRealName()

#define PRESAY(x)   x->QueryPresay()
#define SHORT(x)    x->QueryShort()

#define TNAME       NNAME(TP)
#define TNREAL      NREAL(TP)

#define ISPLAYER(x) x->QueryIsPlayer()

/* LIBS */

#define STR           "/obj/lib/string"
#define NMB           "/obj/lib/number"
#define DATE          "/obj/lib/date"

/* MACROS */

#define W(x)        x // STR->wrap(x, 78)

/* the purpose of the next two macros is to avoid the hash-tick notation,
 * which would confuse emacs c-mode indent engine _sigh_
 */
#define SF(x)       #'x // ' // Emacs-Hack
#define SYM(x)      'x  // ' // Emacs-Hack
#define CL_PROGN    #', // ' // Emack-Hack. SF(,) peta de mala manera.

/* ESTANDARES */

#define UNIT           STDPATH "unit"
#define THING          STDPATH "thing"
#define SCHEDULER_ROOM STDPATH "scheduler_room"
#define ROOM           STDPATH "room"
#define DRINK          STDPATH "drink"
#define FOOD           STDPATH "food"
#define WEAPON         STDPATH "weapon"
#define ARMOUR         STDPATH "armour"
#define CONTAINER      STDPATH "container"
#define SHOP           STDPATH "shop"
#define STORE          STDPATH "store"
#define PUB            STDPATH "pub"
#define LAMP           STDPATH "lamp"
#define BANK           STDPATH "banco"
#define SECUREBOX      STDPATH "securebox"
#define GUILD          STDPATH "guild"

#define NPC            STDPATH "npc"
#define NPC_NOBEL            STDPATH "npc_nobel"
#define PLAYER         STDPATH "player"
#define WIZARD         STDPATH "wizard"

#define EFFECT         STDPATH "effect"

#define KEEPER         STDPATH "room/keeper"

/* PLANTILLAS DE PERSONAJES ESTANDAR */
#define GUARD          OBJECTPATH "template/guard"

/* OBJETOS */

#define TORCH          OBJECTPATH "antorcha"
#define HERB           OBJECTPATH "herb"
#define SHIP           OBJECTPATH "transporte/barco"
#define STAGECOACH     OBJECTPATH "transporte/diligencia"
#define CARAVAN        OBJECTPATH "transporte/caravana"

#define SPELLMONSTER    OBJECTPATH "monster/spellmonster"

#define SMITHY          ROOMPATH "herreria"

/* OBJETOS PARTICULARES */

#define ARMOURS(x)      ( OBJECTPATH "armours/" + x )
#define HERBS(x)        ( OBJECTPATH "herbs/"   + x )
#define WEAPONS(x)      ( OBJECTPATH "weapons/" + x )
#define RACES(x)        ( OBJECTPATH "race/"   + x )

/* HABITACIONES */

#define PORT            ROOMPATH "puerto"
#define CARAVAN_STOP    ROOMPATH "caravan_stop"     // parada caravana
#define STAGECOACH_STOP ROOMPATH "stagecoach_stop"  // parada diligencia

#define DESERT          ROOMPATH "desierto" // La usan las caravanas
#define OCEAN           ROOMPATH "mar"      // La usan los barcos


#endif

