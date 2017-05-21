//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   hall1.c                           *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 01.08.98                  *
//* Modificacion: 01.08.98              *
//* Agradecimientos:                    *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

#include "./path.h"
inherit KHA_ROOM;
create() {
 ::create();

 SetIntShort("el hall de Kha-annu");
 SetIntLong(
 "Estas dentro de Kha-annu. Aqui hay un gran hall lleno de bullicio, "
 "enanos que entran y salen de la ciudad, guardias, algun tendero ...\n"
 "Al norte puedes ver una gran calle excavada en la roca.\n"
 "Al sur la salida de Kha-annu.\n");
 SetIndoors(1);
 SetIntBright(60);
 SetIntNoise("Oyes el bullicio tipico de la entrada de la ciudad.\n");
 SetIntSmell("Un monton de olores se mezclan en tu nariz.\n");

 AddDetail(({"calle"}),
 "Excavada en la roca ves al fondo una calle que se pierde en las "
 "profundidadesde la montanya.\n");

 AddDetail(({"tenderos"}),
 "Hay algunos comerciantes por ahi, tendras que acercarte a ellos.\n");

 AddItem(MONS+"puerguar",REFRESH_DESTRUCT,1);

 AddExit("norte",("hall5"));
 AddExit("oeste",("hall2"));
 AddExit("noroeste",("hall4"));
 AddExit("este",("hall3"));
 AddExit("nordeste",("hall6"));
 AddExit("sur",PUERTASUR+"entrada");
 SetLocate("Kha-annu");
 }

