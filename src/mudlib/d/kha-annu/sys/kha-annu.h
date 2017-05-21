/* Ficheros estandar con las definiciones estandar  */

#ifndef __KHA_ANNU_PATH_H__
#define __KHA_ANNU_PATH_H__

#define DOMINIO "kha-annu"
/* include para las definiciones estándares de todos los dominios */
#include <domain.h>

#include <cerradura.h>
#include <lock.h>
#include <door.h>


// habitación estándar del dominio
#define KHA_ROOM        DOM_STD "kha_room"

// servidor de climas
#define SERVER          "/obj/nightday"
// hasta que no se arregle el SunLight del chronos...

// Ciudades del dominio de Kha-annu

#define CAPITAL         HABITACION "kha-annu/"
#define ANNUKI          HABITACION "annuki/"
#define ANNUFAM         HABITACION "annufam/"
#define ANNUBI          HABITACION "annubi/"
#define CAMINO          HABITACION "caminos/kha-kenton/"
#define CAMINO_NORTE    HABITACION "caminos/kha-kho/"

// afueras de kha-annu
#define AFUERAS_KHA     CAPITAL "afueras/"
#define CARASURD        AFUERAS_KHA "carasurd/"
#define CARASUR         AFUERAS_KHA "carasur/"
#define CARNORTE        AFUERAS_KHA "carnorte/"
#define CEMENTERIO      AFUERAS_KHA "cementerio/"
#define MONTANYA        AFUERAS_KHA "montanya/"


// Lugares utiles en Kha-annu Capital.
#define CIUDAD          CAPITAL "ciudad/"
#define INGE            CIUDAD "ingenieria/"
#define META            CIUDAD "metalurgia/"
#define VIVIENDAS       CIUDAD "viviendas/"
#define POSADAS  CIUDAD "posadas/"
#define TIENDAS         CIUDAD "tiendas/"

#define CASTILLO        CAPITAL "castillo/"
#define PISO1           CASTILLO "piso1/"
#define PISO2           CASTILLO "piso2/"
#define DUNGEONS        CASTILLO "mazmorra/"
#define CLOACAS         CASTILLO "cloaca/"
#define MINAS           CAPITAL "minas/"
#define MPISO1          MINAS "piso1/"

#define PUERTANOR       CIUDAD "puertanor/"
#define PUERTASUR       CIUDAD "puertasur/" //Gorthem again


//Definicion de los pisos de la Mazmorra de Fran (por Gorthem)

#define MPISO2          MINAS "piso2/"
#define MPISO3          MINAS "piso3/"
#define MPISO4          MINAS "piso4/"
#define MPISO5          MINAS "piso5/"

// Definicion de objetos comunes (PNJS, ARMAS, ARMADURAS, OBJETOS MAGICOS...)

#define MONS            COMUN "pnj/"
#define MONS2           MONS "mons/"
#define KBASE    DOM_STD "kbase"
#define GBASE   DOM_STD "gbase"


// caravana khandor
#define KHANDOR(x)      CARAVANA("khandor/" + x)


// include para la zona de annufam (quitada para la versión CVS... aún le
// queda)
#include "annufam.h"

// include para la zona de las minas de Riberales
#include "minas.h"

//Define para que pille el genero de las armas.

#define P_THING_GENDER P_GENDER
#endif
