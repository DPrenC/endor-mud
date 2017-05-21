/**
 * ENDOR-MUD '/sys/xp.h'
 */

#ifndef __XP_H__
#define __XP_H__
// defines para obtener xp en diferentes acciones.
#include <colours.h>

#define TEXTO_XP(x)     ANSI_BLUE+"Has conseguido "+x+" puntos de experiencia.\n"+ANSI_NORMAL
#define TEXTO_XP_BREVE(x)     ANSI_BLUE+"Sumas "+x+" XP.\n"+ANSI_NORMAL
#define EXPLORED_MUY_FACIL   200
#define EXPLORED_FACIL       500
#define EXPLORED_NORMAL      1000
#define EXPLORED_DIFICIL     1500
#define EXPLORED_MUY_DIFICIL 2000

#define XP_BASICO       10
#define XP_1       (XP_BASICO*XP_BASICO)
#define XP_2       (XP_1*2)



#endif
