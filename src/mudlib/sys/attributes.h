/* SIMAURIA '/sys/attributes.h'
   ----------------------------
   [t] Theuzifan@simauria
   [w] Woo@simauria
   [h] Nyh@Simauria
   [i] Izet@Simauria

   27-10-98 [t] Anyado la propiedad P_OLDGUILD y A_OLDGUILD
   31-10-98 [w] Anyadida las propiedades de los TP.
   07-02-01 [h] Añado A_OWN_LONG
   29-04-01 [i] Añadido A_HIDDEN.
*/

#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H 1

#include <properties.h>

/* If we know we deal with a softcoded attribute. */
#define SOFTCODED 1

/*===========================================================================
 * The default and interchangeable attributes.
 */

// Not builtin in /std/living
#define A_DESCRIPTION   P_DESCRIPTION
#define A_FROG          P_FROG
#define A_GHOST         P_GHOST
#define A_GUILD         P_GUILD
#define A_OLDGUILD      P_OLDGUILD
#define A_SIZE          P_SIZE

// --- /std/living/body
#define A_CORPSE        P_CORPSE
#define A_HP            P_HP
#define A_MAX_HP        P_MAX_HP
#define A_RATE_HP       P_RATE_HP
#define A_POISON        P_POISON
#define A_MAX_POISON    P_MAX_POISON
#define A_RATE_POISON   P_RATE_POISON
#define A_SP            P_SP
#define A_MAX_SP        P_MAX_SP
#define A_RATE_SP       P_RATE_SP
#define A_WHIMPY        P_WHIMPY
#define A_XP            P_XP
#define A_TP            P_TP
#define A_MAX_TP        P_MAX_TP
#define A_RATE_TP       P_MAX_TP

// --- /std/living/combat ---
#define A_ARMOURS       P_ARMOURS
#define A_COMBAT_STYLE  P_COMBAT_STYLE
#define A_DEFENSE       P_DEFENSE
#define A_WEAPONS       P_WEAPONS

// --- /std/living/description ---
#define A_ACTIONS       P_ACTIONS
#define A_ADS           P_ADS
#define A_ALIGN         P_ALIGN
#define A_GENDER        P_GENDER
#define A_HIDDEN        P_HIDDEN // [i]
#define A_IDS           P_IDS
#define A_INVIS         P_INVIS
#define A_INT_LONG      P_INT_LONG
#define A_INT_NOISE     P_INT_NOISE
#define A_INT_SMELL     P_INT_SMELL
#define A_INT_SHORT     P_INT_SHORT
#define A_IVISION       P_IVISION
#define A_LEVEL         P_LEVEL
#define A_LONG          P_LONG
#define A_OWN_LONG	P_OWN_LONG  // [Nyh]
#define A_LSTATE        P_LSTATE
#define A_MAGIC_DEFENSE P_MAGIC_DEFENSE
#define A_MMSGIN        P_MMSGIN
#define A_MMSGOUT       P_MMSGOUT
#define A_MSGIN         P_MSGIN
#define A_MSGOUT        P_MSGOUT
#define A_NAME          P_NAME
#define A_NOISE         P_NOISE
#define A_RACE          P_RACE
#define A_SHORT         P_SHORT
#define A_SMELL         P_SMELL
#define A_UVISION       P_UVISION

// --- /std/living/enemies ---
#define A_AGGRESSIVE    P_AGGRESSIVE
#define A_ATTACK_CHANCE P_ATTACK_CHANCE

// --- /std/living/hands ---
#define A_FREE_HANDS    P_FREE_HANDS
#define A_HANDS         P_HANDS

// --- /std/living/moving
#define A_GO_CHANCE     P_GO_CHANCE

// --- /std/living/stats
#define A_CHA           "Cha"
#define A_CON           P_CON
#define A_DEX           P_DEX
//#define A_GNO           P_GNO
#define A_INT           P_INT
#define A_STR           P_STR
#define A_WIS           P_WIS

#define STATS ({ A_CON, A_DEX, A_INT, A_STR, A_CHA, A_WIS })

// --- /std/npc/body
#define A_ALCOHOL       P_ALCOHOL
#define A_DEG_ALCOHOL   P_DEG_ALCOHOL
#define A_DEG_DRINK     P_DEG_DRINK
#define A_DEG_FOOD      P_DEG_FOOD
#define A_DRINK         P_DRINK
#define A_FOOD          P_FOOD
#define A_MAX_ALCOHOL   P_MAX_ALCOHOL
#define A_MAX_DRINK     P_MAX_DRINK
#define A_MAX_FOOD      P_MAX_FOOD
#define A_RATE_ALCOHOL  P_RATE_ALCOHOL

// --- /std/npc/view
#define A_BRIEF         P_BRIEF
#define A_OBVIOUS       P_OBVIOUS

//---------------------------------------------------------------------------

/* The presay of the living.
 * softcoded - string
 */
#define A_PRESAY        "Presay"

/* The title of the living.
 * softcoded - string
 */
#define A_TITLE         "Title"

//===========================================================================
// An array with the names of all default (builtin) attributes.

#define LIVING_ATTRS \
 (({ A_HP, A_MAX_HP, A_RATE_HP \
   , A_POISON, A_MAX_POISON, A_RATE_POISON \
   , A_SP, A_MAX_SP, A_RATE_SP \
   , A_TP, A_MAX_TP, A_RATE_TP \
   , A_WHIMPY, A_XP \
   , A_ARMOURS, A_COMBAT_STYLE, A_DEFENSE, A_WEAPONS \
   , A_ACTIONS, A_ADS, A_ALIGN, A_GENDER, A_LSTATE, A_IDS, A_INVIS \
   , A_INT_LONG, A_INT_NOISE, A_INT_SMELL, A_INT_SHORT \
   , A_IVISION, A_LEVEL, A_LONG, A_MAGIC_DEFENSE \
   , A_MMSGIN, A_MMSGOUT, A_MSGIN, A_MSGOUT \
   , A_NAME, A_NOISE, A_RACE, A_SHORT, A_SMELL \
   , A_UVISION, A_AGGRESSIVE, A_ATTACK_CHANCE \
   , A_FREE_HANDS, A_HANDS, A_GO_CHANCE \
   , A_ALCOHOL, A_DEG_ALCOHOL, A_DEG_DRINK, A_DEG_FOOD \
   , A_DRINK, A_FOOD, A_MAX_ALCOHOL, A_MAX_DRINK, A_MAX_FOOD \
   , A_RATE_ALCOHOL \
   , A_BRIEF, A_OBVIOUS \
   })+STATS)

#endif
