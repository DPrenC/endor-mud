/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  viejo de Kho-pingen");

SetIntLong(
"El camino, o lo que queda de el, discurre entre las montañas ascendiendo a "
"medida que avanzas hacia el oeste. Hacia el sudeste el camino desciende "
"buscando cerros más bajos. Excepto las montañas que rodean el camino, no "
"puedes ver mas alla.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele un poco a tierra y polvo.\n");

 AddDetail(({"arbol","arboles"}),
 "Algunos arboles rodean el camino, no tienen nada de especial.\n");
 AddExit("oeste",(CAMINO_NORTE+"caminor19"));
 AddExit("sudeste",(CAMINO_NORTE+"caminor17"));

 SetLocate("camino_norte");
}