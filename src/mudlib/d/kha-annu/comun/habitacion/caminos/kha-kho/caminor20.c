/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  viejo de Kho-pingen");

SetIntLong(
"Estas en un estrecho valle rodeado de altas montañas de paredes verticales.\n"
"No hay nada de vegetacion aqui y en el suelo hay algun que otro adoquin "
"desperdigado. justo al sur de aqui hay un estrecho paso por donde se pierde "
"lo que queda del camino.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele un poco a tierra y polvo.\n");
 AddExit("este",(CAMINO_NORTE+"khopin"));
 AddExit("sur",(CAMINO_NORTE+"caminor18"));

 SetLocate("camino_norte");
}