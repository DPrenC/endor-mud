/*
** Los #defines del Gremio de Guerreros
** Autor: Nemesis@Simauria, Ago'99
** Cambios:
*/


#ifndef _WGUILD_
#define _WGUILD_

#include "./path.h"

#define WHOME "/guilds/guerreros/"
#define WMASTER WHOME "gmaster"
#define WARRIORS WHOME "gguild"
#define HELM WHOME "guercasco"
#define BARBSERVER WHOME "barbserver"
//#define BANDAGE WHOME "bandage"
#define GMASTER WHOME "drix"
#define JAN_OBJ "/guilds/guerreros/jan_obj/"

// Guildquests:
// De momento, sólo 2: el del ghoul a nivel 8 y el
//del "Secreto del Acero" a nivel 30 o así.

/*
#define Q_GHOUL "kill_ghoul"
#define Q_ACERO "secreto_acero"
*/

#define COST_SCREAM 20

#define MET_SIMPLES ({M_HIERRO_TXT, M_COBRE_TXT, M_BRONCE_TXT})

/* Niveles a los que se aprenden los skills.
   Otra manera de dar alicientes a los miembros del Gremio podría ser darles
   un arma especial a nivel 40.
   Nuevos Skills: Afilado: pa subir el WC de las armas (+1)
                  Blindaje: pa subir el AC de las armaduras (+1)
                  Por supuesto, sólo una vez y de uso personal e
                  intransferible.
*/

// Niveles "definitivos"

#define NVL_IDENTIFICAR 1

//A partir de aquí no se conserva ningun skill
//Nivel 5
#define NVL_VARA        5
#define NVL_CUCHILLO    5
#define NVL_CADENA      5
//Nivel 6
#define NVL_REPARAR 6
//Nivel 7
#define NVL_MAZA    7
#define NVL_ESPADA  7
//Nivel 8
#define NVL_VENDAJE 8
// NOTA: Es posible que este skill se intercambie con SK_MANGUAL a nivel 15.
#define NVL_PARADA  8
//Nivel 9
#define NVL_LANZA   9
#define NVL_HACHA   9
//Nivel 10
#define NVL_ESGRIMA 10
#define NVL_RPR_NORMAL 10
//Nivel 14
#define NVL_MANOPLA 14
//Nivel 15
#define NVL_CRITICO 15
#define NVL_MANGUAL 15
//Nivel 17
#define NVL_LATIGO  17
//Nivel 20
#define NVL_ALABARDA 20
//Nivel 25
#define NVL_RPR_AVANZADO 25
//Nivel 30
#define NVL_BARBARO  30
//Nivel 35
#define NVL_SINARMAS 35

#endif
