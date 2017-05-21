/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el cruze del camino del Norte");

SetIntLong(
"Estas en el cruze del camino del norte de Kha-annu, al sur, con el camino "
"de la frontera, al nordeste, y el viejo camino de Kho-pingen, que se pierde en "
"las montañas, al noroeste. Hay una roca con una inscripcion.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele al aire limpio de las montañas.\n");
 AddExit("noroeste",(CAMINO_NORTE+"caminor17"));
 AddExit("sudeste",(CAMINO_NORTE+"caminor11"));
 AddExit("nordeste",(CAMINO_NORTE+"caminor12"));
AddReadMsg(({"roca","inscripcion"}),
"Lees en la roca:\n"
"Recuerda viajero, que estas en Kha-annu, la tierra de los enanos.\n"
"Si eres amigo toma el camino del sur, si eres enemigo elige por que parte "
"del norte quieres encontrar la muerte.\n");

 SetLocate("camino_norte");
}