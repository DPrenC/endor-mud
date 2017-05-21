/* SIMAURIA
   ========
*/

// NIGHTFALL
// =========

#ifndef _SECURE_WIZLEVELS_
#define _SECURE_WIZLEVELS_
/*
 * secure/wizlevels.h
 *
 * This file defines some useful macros to determine the level of
 * a wizard in terms of ability to do certain wizard things.
 * See also doc/concepts/levels. The grouping below is taken from there.
 *
 * Wizlevel Group Remarks
 *  0       1-5  Players, Abilities determined through player object properties
 *10-19      7   Learner, "Pilgrims"
 *20-29      8   Wizard (20 = normal, 25 = domain member, 28 = retired arch)
 *30-39      9   Domain Lord (30 = Vice Lord, 35 = Lord)
 *40-49     10   Archmage,-wizard (40 = Vice AW, 45 = AW)
 *70        11?  Counciler
 * xxx      xx   God
 */
#include "/secure/config.h"

#define LEARNER_MIN_LEVEL 35

#define BEGINNER_RLVL  1
#define HLP_RLVL      100

#define LEARNER_LVL 10
#define WIZARD_LVL  20
#define MEMBER_LVL  25
#define VICE_LVL    30
#define LORD_LVL    35
#define ARCH_LVL    45
#define CON_LVL     70
#define GOD_LVL     80

// nuevos niveles para endor-mud
#define MAIA_LVL     10
#define HERALDO_LVL     45
#define VALA_LVL     70
#define ARATAR_LVL     80

/* user is an object which is to be checked */
/* for example, use IS_WIZARD(this_player()) to check */
/* if a player is a wizard. */

#define IS_BEGINNER(user) (!query_wiz_level(user) && BEGINNER_RLVL >(int) ((user)->QueryRealLevel()))
#define IS_HLP(user) (query_wiz_level(user) || HLP_RLVL <= (int) ((user)->QueryRealLevel()))
#define IS_JAN(user) IS_HLP(user)

#define IS_LEARNER(user) (query_wiz_level(user) >= LEARNER_LVL)
#define IS_WIZARD(user) (query_wiz_level(user) >= WIZARD_LVL)
#define IS_VICE(user) (query_wiz_level(user) >= VICE_LVL)
#define IS_LORD(user) (query_wiz_level(user) >= LORD_LVL)
#define IS_ARCH(user) (query_wiz_level(user) >= ARCH_LVL)
#define IS_CON(user) (query_wiz_level(user) >= CON_LVL)
#define IS_GOD(user) (query_wiz_level(user) >= GOD_LVL)

// niveles nuevos para endor-mud
#define IS_MAIA(user) (query_wiz_level(user) >= MAIA_LVL)
#define IS_HERALDO(user) (query_wiz_level(user) >= HERALDO_LVL)
#define IS_VALA(user) (query_wiz_level(user) >= VALA_LVL)
#define IS_ARATAR(user) (query_wiz_level(user) >= ARATAR_LVL)
#endif
