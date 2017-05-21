/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  viejo de Kho-pingen");

SetIntLong(
"Estas en un camino que se rodea las montañas que hay delante tuyo. El camino "
"esta muy sucio, lleno de tierra suelta y la maleza ya ha empezao a borrarlo "
"arrancando de la tierra los adoquines que lo marcaban. Hay una piedra grande "
"junto el camino.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele un poco a tierra y polvo.\n");

 AddDetail(({"arbol","arboles"}),
 "Algunos arboles rodean el camino, no tienen nada de especial.\n");
 AddDetail(({"roca","piedra"}),
 "Es una roca con una inscripcion que tal vez puedas leer.\n");
 AddExit("noroeste",(CAMINO_NORTE+"caminor18"));
 AddExit("sudeste",(CAMINO_NORTE+"cruce"));
  AddReadMsg(({"roca","inscripcion"}),
  "La roca tiene una inscripcion que parece que alguien intento borrar:\n"
  "Bie*ve*i** a l** m*** de Kh*-pi*gen\n");

 SetLocate("camino_norte");
}