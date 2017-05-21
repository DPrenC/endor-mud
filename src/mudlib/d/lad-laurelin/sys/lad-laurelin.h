/******************************************************************************
*                                                                             *
*        Archivo: lad-laurelin.h                                              *
*   Descripcion: Archivo de sistema de lad-laurelin (paths y abreviaturas)    *
*                                                                             *
*        [g] Guybrush                                                         *
*        [t] Theuzifan                                                        *
*        [m] Mirill                                                           *
*        [Ch] Chantiel                                                        *
*        [j] Jorus                                                            *
*        [h] Nyh                                                              *
*                                                                             *
*        29-10-97 [g] Creacion.                                               *
*         17/02/98 [m] Creacion de nuevas variables a peticion de Chantiel.   *
*        19/02/98 [g] [u] ... y la pena que me da que lo haya hecho.          *
*                  Corregido y reestructurado salvajemente. NO SE PONEN       *
*                  TABS a principio de linea en un .h!!!                      *
*        26-03-98 [w] Cambiado un path, de thiinkelginn a tiin, chantiel.     *
*        14-05-98 [Ch] Creacion de nuevas variables a petiocion de Chantiel   *
*                      y actualizadas por izet                                *
*        03-06-98 [Ch] Creacion de nuevas variables para Thiinkdhil           *
*        09-11-98 [Ch] Creacion de nuevas variables para PNJs de Tiinkdhil    *
*        02-12-98 [Ch] Borrado y Recolocacion de algunas de las variables     *
*                      de Tiinkdhil al path.h que esta en el directorio:      *
*                      /d/lad-laurelin/comun/habitacion/tiinkdhil/            *
*        16/03/99 [g] Cambia las defs para Mithondrin, y reestructura un      *
*                     poco el archivo.                                        *
*        09/05/00 [j] Añado la definicion de MALCANTAR para las               *
*                     alcantarillas de Kellios                                *
*        10/05/00 [m] Cambio la definición de MALCANTAR para que rule y       *
*                     quito los ^M.                                           *
*        16/05/00 [g] Yo meto aquí cosas.                                     *
*        17/05/00 [j] Como prometi añado las def para los nuevos              *
*                     subdirectorios y directorios.                           *
*        17-12-04 [h] Pongo muchos parentesis que aunque no sean necesarios   *
*                     hacen la cosa mas mejor.                                *
*                     Tambien añado los defines para la nueva zona de la      *
*                     Faeria que esta codeando Kastwey.                       *
******************************************************************************/

#ifndef __LAURELIN_H
#define __LAURELIN_H

/* Nombre del dominio */
#define DOMINIO  "lad-laurelin"

/* include standard para todos los dominios */
#include <domain.h>    // estructura de dominios standard

/*
,----------------------------------------------------------------------------,
|  PARTE PARTICULAR PARA ESTE DOMINIO                                        |
'----------------------------------------------------------------------------'
*/
// ----- Standards Globales --------------------------------------------------
#define LAD_ROOM_EX         (DOM_STD "lad_room_ex")// habitacion lad-laurelin
                                                     // con emotes.
#define LAD_ROOM            (DOM_STD "lad_room")   // habitacion lad-laurelin
#define LAD_SHOP            (DOM_STD "lad_shop")   // tienda lad-laurelin
#define LAD_PUB             (DOM_STD "lad_pub")    // pub lad-laurelin
#define SERVER          (DOM_STD + "clima") // Servidor de Clima
// ---------------------------------------------------------------------------

// ---- Caravanas ---------------------------------------------------------
#define NAHLIN(x)           CARAVANA("nahlin/" + x)

// ---------------------------------------------------------------------------

// ---- Lad-Laurelin ---------------------------------------------------------
#define MITHONDRIN          (HABITACION "mithondrin/")
#define ATBALNIN            (HABITACION "atbalnin/")
#define TIINKDHIL           (HABITACION "tiinkdhil/")
#define VANGARDIL           (HABITACION "vangardil/")
#define ANDALO              (HABITACION "andalo/")
// ---------------------------------------------------------------------------

// ---- Atbalnin -----------------------------------------------------------

#define ATB_B(x)            (ATBALNIN + "bosque/" + x)
#define ATB_C(x)            (ATBALNIN + "cueva/" + x)
#define ATB_P(x)            (ATBALNIN + "puentes/" + x)
#define ATB_CI(x)           (ATBALNIN + "ciudad/" + x)
#define ATB_TI(x)           (ATBALNIN + "tiendas/" + x)
#define ATB_CL(x)           (ATBALNIN + "claro/" + x)
#define ATB_I(x)            (ATBALNIN + "islote/" + x)
#define ATB_BI(x)           (ATBALNIN + "biblioteca/" + x)


// ---- Mithondrin -----------------------------------------------------------
#define KELLIOS(x)          (MITHONDRIN "kellios/"+x)
#define KPNJALC(x)          PNJ( "mithondrin/alcantarillas/"+x )
#define KELLMAZ(x)          KELLIOS( "mazmorras/"+x )
#define KELLPI1(x)          KELLIOS( "piso1/"+x )
#define KELLPI2(x)          KELLIOS( "piso2/"+x )
#define KELLPI3(x)          KELLIOS( "piso3/"+x )
#define KELLPI4(x)          KELLIOS( "piso4/"+x )
#define KELLPAL(x)          KELLIOS( "palacio/"+x )
#define MCAMINO(x)          (MITHONDRIN "camino/"+x)
#define MBOSQUE(x)          (MITHONDRIN "bosque/"+x)
#define MPLAYA(x)           (MITHONDRIN "playa/"+x)
#define MPUERTO(x)          (MITHONDRIN "puerto/"+x)
#define MALCANTAR(x)        (MITHONDRIN "kellios/alcantarillas/"+x)
#define MCOSTA(x)           (MITHONDRIN "acantilado/"+x)
#define MESPECIAL(x)        (MITHONDRIN "bosque/especial/"+x)
// ---------------------------------------------------------------------------

// ---- Tinnkdhil ------------------------------------------------------------
// PNJs especificos de Tiinkdhil.
#define TIIN_PNJ        (COMUN "pnj/tiin/")
// Tiinkdhil y alrededores
#define TBOSQUE(x)      (TIINKDHIL + "bosque/"+x)
#define TLAGO           (TIINKDHIL + "lago/")
#define TDUNGEON1       (TIINKDHIL + "dungeon1/")
//  Zona de Alura
#define ALULAGO(x)      (TIINKDHIL + "lago/"+x)
#define ALUTIIN(x)      (TIINKDHIL + "tiin/"+x)
#define ALUKHAN(x)      ("/d/kha-annu/comun/habitacion/kha-annu/afueras/carasurd/"+x)
#define ALUPNJ(x)       (COMUN "pnj/tiin/lago/"+x)
#define ALUOBJ(x)       (COMUN "objeto/"+x)
// Ciudad de Tiinkdhil
#define TCEMEN(x)	TIINKDHIL "tiin/cementerio/"+x
#define TCIUDAD		TIINKDHIL "tiin/ciudad/"
#define	TCSUELO(x)	TCIUDAD   "suelo/"+x
#define TCPISO1(x)	TCIUDAD   "piso1/"+x
#define TCPNJ(x)        TIIN_PNJ  "ciudad/"+x
#define TBPNJ		TIIN_PNJ + "bosque/"

// Arbol de la Vida
#define TARBOL		TIINKDHIL  "tiin/arbol/"
#define TASOTANO(x)  	TARBOL     "sotano/"+x
#define TABASE(x)	TARBOL     "base/"+x
#define TAPISO1(x)	TARBOL     "piso1/"+x
#define TAPISO2(x)	TARBOL     "piso2/"+x
#define TAPNJ(x)        TIIN_PNJ   "arbol/"+x

// Lago Dehim
#define TLPLAYA(x)      TLAGO    "playa/"+x
#define TLBOSQUE(x)     TLAGO    "bosque/"+x   
#define TLTEMPLO(x)     TLAGO    "templo/"+x
#define TLCAMPO1(x)     TLAGO    "campo1/"+x
#define TLCAMPO2(x)     TLAGO    "campo2/"+x
#define TLPNJ(x)        TIIN_PNJ "lago/"+x

//---{ Dungeon de Dular (4 niveles)}---//

#define TDNIVEL1        TDUNGEON1 "nivel1/"
#define TDNIVEL2        TDUNGEON1 "nivel2/"
#define TDNIVEL3        TDUNGEON1 "nivel3/"
#define TDNIVEL4        TDUNGEON1 "nivel4/"
#define TDPNJ(x)        TIIN_PNJ  "dungeon/"+x

// Nivel 1
#define TDPRIN1(x)      TDNIVEL1 "principal/"+x
#define TDSUB11(x)      TDNIVEL1 "subnivel1/"+x 
#define TDSUB12(x)      TDNIVEL1 "subnivel2/"+x 
#define TDSUB13(x)      TDNIVEL1 "subnivel3/"+x
#define TDRUI1(x)       TDNIVEL1 "ruinas1/"+x

//Nivel 2
#define TDPRIN2(x)      TDNIVEL2 +x

//Nivel 3
#define TDPRIN3(x)      TDNIVEL3 +x

// ---------------------------------------------------------------------------

// ---- Atbalnin -------------------------------------------------------------
#define ATCIUDAD(x)         (ATBALNIN "ciudad/"+x)
// ---------------------------------------------------------------------------

// ---- Vangardil ------------------------------------------------------------
#define VANCIUDAD(x)        (VANGARDIL "ciudad/"+x)
// ---------------------------------------------------------------------------

// ---- Andalo ---------------------------------------------------------------
#define ANCIUDAD(x)         (ANDALO "ciudad/"+x)
// ---------------------------------------------------------------------------
// defines para faeria
#include "faeria.h"

// quest de gardil
#define QUEST_GARDIL(x)     (QUEST "gardil/" + x)




#endif /* __LAURELIN_H */