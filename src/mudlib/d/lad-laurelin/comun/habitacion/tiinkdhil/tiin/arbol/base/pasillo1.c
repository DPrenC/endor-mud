/*
DESCRIPCION  : entrada al 'arbol de la vida'

FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/

NOTAS:falta un salida la que lleva a alguna ciudad, no
se cual es el archivo.

SUGERENCIAS: hacer que cuando alguien entre al arbol le
lleguen voces con algun extraño cantico.

MODIFICADO POR AVENGELYNE, LA MUJER FATAL

*/

#include "./path.h"

#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
  SetIntShort("el pasillo del árbol de la vida");
  SetIntLong(
"Te encuentras en una de las entradas del 'árbol de la vida, al norte\n"
"puedes ver un camino que conduce a alguna parte; al sur te adentras en\n"
"las profundidades del árbol; al oeste ves una habitación.\n"
);
AddDetail (({"","",""}),"");

SetIntBright(20);
SetIntSmell(
"Puedes distinguir perfectamente el olor a savia y a\n"
"humedad.\n"
);

SetIntNoise(
"Escuchas un extranyo canto que proviene del interior del\n"
"arbol. Parece que te esta invitando a entrar.\n"
);



SetLocate("Arbol");
SetIndoors (1); /* 0 exterior; 1 interior */

AddExit("oeste",TABASE("puesto1"));
AddExit("sur",TABASE("interior2"));
AddExit("norte",TCSUELO("cruce2"));
}