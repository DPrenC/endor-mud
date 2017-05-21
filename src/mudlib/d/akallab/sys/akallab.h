 /*
FICHERO      : /d/akallab/sys/akallab.h
DESCRIPCION  : Contiene abreviaciones, paths, valores y objetos pertenecientes
               al dominio de Akallab.
MODIFICACION :

[a] Angor@Simauria

20-05-97 [a]  Creacion.
01-06-97 [a]  Adaptacion al modelo standard de Simauria
25-05-98 [a]  Varias modificaciones
02-10-98 [a]  Reorganizacion de directorios de Zarkam
08-10-98 [a]  Declaradas las zonas del subdominio de Kuntz
30-10-98 [a]  Declaradas las zonas del subdominio de Azzor
11-11-98 [a]  Declaradas las zonas del subdominio de Akkbar
15-08-01 [a]  Ultima actualizacion
18-11-04 [Gw] Añadidos los defines del Domain Manager
*/

//  .----------------.
//  | PARTE STANDARD |
//  `----------------'

#ifndef __AKALLAB_H
#define __AKALLAB_H

// Nombre del dominio
#define DOMINIO  "akallab"      // Este es el dominio de Akallab

// include standard para todos los dominios
#include <domain.h>    // paths y directorios standard de dominios

//  .------------------------------------.
//  | PARTE PARTICULAR PARA ESTE DOMINIO |
//  `------------------------------------'

// Parametros comunes para todo el dominio
#define AK_LUZ        50

// Habitaciones estandar para todo el dominio


#define AK_ROOM        DOM_STD "ak_room"
#define AK_SERVER      DOM_STD "clima" // Servidor de Clima
#define AK_BANCO       DOM_STD "banco"
#define AK_FONDA       DOM_STD "fonda"
#define AK_MACRO       RAIZ "sys/macros.h"
#define BOSQUE_BASE    DOM_STD "bosque_base"

#define PUERTA_CIUDAD  DOM_STD "ciudad/puerta_ciudad"

// Objetos estandar de este dominio
#define AK_PNJ         DOM_STD "pnj_base"
#define AK_SOLDADO     PNJ("ejercito/std/soldado")


// caravanas y barcos del dominio
#define CAR_ZARKAM(x)  CARAVANA("zarkam/" + x)
#define BAR_AUDAZ(x)   BARCO("audaz/" + x)
#define BAR_TEMPEST(x) BARCO("tempestad/" + x)
#define BAR_TORMENTA(x) BARCO("tormenta/" + x)

// Directorios con codigo de habitaciones

// Dominios o regiones de los orcos
#define AKALLAB_      HABITACION "akallab/"
#define BEZOUR_       HABITACION "bezour/"
#define ARZGUIR_      HABITACION "arzguir/"
#define ARZHAM_       HABITACION "arzham/"

// Subdominios de la region de Akallab
#define AKALLAB       AKALLAB_ "akallab/"
#define AKKBAR        AKALLAB_ "akkbar/"
#define KUNTZ         AKALLAB_ "kuntz/"
#define ZARKAM        AKALLAB_ "zarkam/"
#define AZZOR         AKALLAB_ "azzor/"

// Zonas del subdominio de Kuntz
#define K_CAMINO(x)   KUNTZ "camino/"+x
#define K_CUEVA(x)    KUNTZ "cueva/"+x
#define K_TIENDA(x)   KUNTZ "tienda/"+x

// Zonas del subdominio de Zarkam
#define Z_BOSQUE(x)     ZARKAM "bosque/"+x
#define Z_CAMINO(x)     ZARKAM "camino/"+x
#define Z_CAMPOS(x)     ZARKAM "campo/"+x
#define Z_CASTILLO(x)   ZARKAM "castillo/"+x
#define Z_CEMENTERIO(x) ZARKAM "cementerio/"+x
#define Z_CIUDAD(x)     ZARKAM "ciudad/"+x
#define Z_CLOACA(x)     ZARKAM "cloaca/"+x
#define Z_GREMIO(x)     ZARKAM "gremio/"+x
#define Z_MERCADO(x)    ZARKAM "mercado/"+x
#define Z_MINAS(x)      ZARKAM "minas/"+x
#define Z_POSADA(x)     ZARKAM "posada/"+x
#define Z_TIENDA(x)     ZARKAM "tienda/"+x

// Zonas del subdominio de Azzor
#define AZ_TABERNA(x)   AZZOR "taberna/"+x
#define AZ_POSADA(x)    AZZOR "posada/"+x
#define AZ_PUERTO(x)    AZZOR "puerto/"+x
#define AZ_CAMINO(x)    AZZOR "camino/"+x
#define AZ_CIUDAD(x)    AZZOR "ciudad/"+x
#define AZ_FORTALEZA(x) AZZOR "fortaleza/"+x
#define AZ_GREMIO(x)    AZZOR "gremio/"+x
#define AZ_TIENDA(x)    AZZOR "tienda/"+x
#define AZ_MURALLA_PO(x) AZZOR "ciudad/muralla/po/"+x
#define BOSQUE_MORAK(x) AZZOR "bosque_morak/"+x
#define BOSQUE_TALEK(x) AZZOR "bosque_talek/"+x
#define NARAD(x)        AZZOR "narad/"+x
#define GADDARO(x)      AZZOR "gaddaro/"+x

// Zonas del subdominio de Akkbar
#define AKKBAR_CAMINO(x)  AKKBAR "camino/"+x

// Subdominios de la region de Bezour
#define MORHUGOK(x)     BEZOUR_ "morhugok/"+x

// Directorios (no estandar) con codigo de objetos
#define MAPA(x)       OBJETO "mapa/"+x
#define LIBRO(x)      OBJETO "libro/"+x
#define POCION(x)     OBJETO "pocion/"+x
#define DOC(x)        COMUN  "doc/"+x
#define HUESO_DIR(x)  OBJETO "hueso/"+x
#define MUEBLE(x)     OBJETO "mueble/"+x


// pnjs
#define PNJ_AKALLAB(x)  PNJ("akallab/" + x) // subdominio de Akallab
#define PNJ_AZZOR(x)    PNJ_AKALLAB("azzor/" + x) // zona de Akallab
#define PNJ_GADDARO(x)  PNJ_AKALLAB("gaddaro/" + x)
#define PNJ_NARAD(x)    PNJ_AKALLAB("narad/" + x)
#define PNJ_Z_CIUDAD(x) PNJ("z_ciudad/" + x)

// control de diversas cosas
#define ASESINATO DOM_STD     "ctrl_asesinato"
#define FILTRO_PNJ_ZONA RAIZ "sys/filtro_pnj_zona.h"
#endif /* __AKALLAB_H */

