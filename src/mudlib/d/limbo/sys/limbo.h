 /*
FICHERO      : /d/limbo/sys/limbo.h
DESCRIPCION  : Contiene abreviaciones, paths, valores y objetos pertenecientes
               al dominio de Limbo.
MODIFICACION :

[a] Angor@Simauria

07-01-98 [a] Creacion.
23-03-99 [a] Anyadidas macros
*/
#include <domain.h>        // paths y directorios standard de dominios

/*
.-----------------------------------------------------------------------.
|  PARTE STANDARD                                                       |
'-----------------------------------------------------------------------'
*/

/* Nombre del dominio */

#define DOMINIO  "limbo"      // Este es el dominio de la isla Limbo

/* include standard para todos los dominios */


/*
.-----------------------------------------------------------------------.
|  PARTE PARTICULAR PARA ESTE DOMINIO                                   |
'-----------------------------------------------------------------------'
*/

#define LI_ROOM            DOM_STD "li_room"        // room.c especial

/* Directorios con codigo de habitaciones */

/* subdominio de la isla Limbo (por ahora no hay mas) */
#define ISLA           HABITACION "limbo/"
#define LIMBO(x)       ISLA "limbo/"+x         // Caminos y demas..
#define TEMPLO(x)      ISLA "templo/"+x        // Zona del templo de Asthar
#define TORRE(x)       ISLA "torrewiz/"+x      // Torre de wizards
#define STONE(x)       ISLA "stonehenge/"+x    // Portales de teletransporte

//Subzonas del parque de newbies
#define BOSQUE(x)      ISLA "newbie/bosque/"+x // Parque para newbies
#define MINA(x)        ISLA "newbie/mina/"+x   // Mina del parque de newbies

