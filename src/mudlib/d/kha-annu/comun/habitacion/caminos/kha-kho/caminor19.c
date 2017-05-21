/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("el camino  viejo de Kho-pingen");

SetIntLong(
"Estas en un valle rodeado completamente de montañas que no te dejan ver "
"mas que algo que parece ser un camino hacia el este. Este lucar es un poco "
"frio puesto que apenas hay vegetación, y la roca gris a tu alrededor no "
"contribuye a mejorar el paisaje.\n"
"El valle continua al oeste.\n");
 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes el ruidillo de los pajaros.\n");
 SetIntSmell("Huele un poco a tierra y polvo.\n");

 AddDetail(({"vegetacion","arbustos"}),
 "Algunos matojos rodean el camino, nada de especial.\n");
 AddExit("oeste",(CAMINO_NORTE+"caminor20"));
 AddExit("este",(CAMINO_NORTE+"caminor18"));

 SetLocate("camino_norte");
}