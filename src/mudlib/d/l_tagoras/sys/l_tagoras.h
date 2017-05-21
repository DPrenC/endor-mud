/*
FICHERO      : ~./sys/l_tagoras.h
DESCRIPCION  : Contiene abreviaciones, paths, valores y objetos pertenecientes
               al dominio de Tagoras.
MODIFICACION :
[t] Tagoras
                        
16-09-08 [t] Creacion
*/

#ifndef __L_TAGORAS_H__
#define __L_TAGORAS_H__

/* Nombre del dominio */

#define DOMINIO  "l_tagoras"

/* include standard para todos los dominios */
#include <domain.h>    // estructura de dominios standard
#include <weather.h>    // funciones pal clima

/*
.-----------------------------------------------------------------------.
|  PARTE PARTICULAR PARA ESTE DOMINIO                                   |
'-----------------------------------------------------------------------'
*/

#define SIM_ROOM        DOM_STD "sim_room"  // habitacion simauria
#define SERVER          DOM_STD "clima" // Servidor de Clima

//#define ARMA(x)			"/d/l_tagoras/comun/objeto/arma/" + x
//#define PROT(x)			"/d/l_tagoras/comun/objeto/proteccion/" + x
#define PATH_TO_BASE(x)		"/d/l_tagoras/comun/habitacion/" + x

#define BASE_ITEM_DARWEN	"/d/l_tagoras/comun/objeto/otro/item_darwen"
#define ITEM_DARWEN(x)		"/d/l_tagoras/comun/objeto/otro/" + x
#define PNJ_DARWEN(x)		"/d/l_tagoras/comun/pnj/" + x

#define BASE_PERFUME		"/d/l_tagoras/comun/objeto/otro/perfume_botella"

#define ADVANCED_EFFECT		"/d/l_tagoras/comun/objeto/otro/advanced_effect"
#define EFFECT_WOUNDS		"/d/l_tagoras/comun/objeto/otro/effect_wounds"

/*
.-------------------------------------------------------------------.
|              FUNCIONES DE LIBRERIA                                |
|  Y SOLO FUNCIONES DE LIBRERÍA, NADA DE DEFINES DE DOMINIOS OK?    |
'-------------------------------------------------------------------'
*/

//    [z] Espero no petar mucho a los demás.
#define CATP        capitalize(this_player()->QueryRealName())

#endif /* __L_TAGORAS_H */
