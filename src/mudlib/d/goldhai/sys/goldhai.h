/**
 * GOLDHAI.Simauria 'goldhai.h'
 */

#ifndef _GOLDHAI_H
#define _GOLDHAI_H

#define DOMINIO             "goldhai"

#include <domain.h>

#define INC                 RAIZ "inc/"              // Direc. Includes
#define TEXTOS              RAIZ "docs/bibliotecas/" // Textos

#define GROOM               DOM_STD "groom"           // Room.c especial
#define MURALLA             DOM_STD "gmuralla"        // Muralla Glucksfall
#define GRAF                DOM_STD "graf"            // Sistema Graf
#define PUESTO              DOM_STD "puesto"          // Tiendas calle
#define GBOSQUE             DOM_STD "gbosque"         // Room bosque
#define GBATALLA            DOM_STD "gbatalla"        // Zona de batalla
#define GACANTILADO         DOM_STD "gacantilado"     // Zona de acantilado
#define GPLAYA              DOM_STD "gplaya"          // Zona de playa
#define GUARDIAN            DOM_STD "guardian"        // Guardianes

/* ############## barcos ############################ */

#define BENOSHAN(x)         BARCO("benoshan/" + x)
#define SOTHKORN(x)         BARCO("sothkorn/" + x)
#define BOTE_FANTASMA(x)    BARCO("bote_fantasma/" + x)


/* ############## DIRECTORIOS ESTANDAR ############## */

#define PLANTAS(x)          COMUN "objeto/hierba/"+x    // Plantas

/* ############## Kisala estándar ############## */
#define KISALA              DOM_STD "kisala"


/* ############## DIRECTORIOS DE ZONAS ############## */

#define ACANTILADO(x)       HABITACION "acantilado/"+x
#define BOSCURO(x)          HABITACION "bosque_oscuro/"+x
#define BNORTE(x)           HABITACION "bosque_norte/"+x
#define BWALD(x)            HABITACION "bosque_wald/"+x
#define CAMPTROLL (x)       HABITACION "campamento_troll/"+x
#define CAMPGIGANTE (x)     HABITACION "campamento_gigante/"+x
#define CAMPOS(x)           HABITACION "campos/"+x
#define CAVERNA(x)          HABITACION "cavernas/"+x
#define CEMENTERIO(x)       HABITACION "cementerio/"+x
#define CROWY(x)            HABITACION "crowy/"+x
#define FUNDICION(x)        HABITACION "fundicion/"+x
#define GLUCKSFALL(x)       HABITACION "glucksfall/"+x
#define GRANJA(x)           HABITACION "granja/"+x
#define LAGO(x)             HABITACION "lago/"+x
#define MANSION(x)          HABITACION "mansion/"+x
#define PUERTO(x)           HABITACION "puerto/"+x
#define RUINAS(x)           HABITACION "ruinas/"+x
#define TALTAS(x)           HABITACION "tierras_altas/"+x
#define TUNELES(x)          HABITACION "tuneles/"+x
#define PLAYA(x)            HABITACION "playa/"+x
#define BATALLA(x)          HABITACION "zona_batalla/"+x
#define PNJ_CROWY(x)        PNJ("crowy/" + x)




#endif
