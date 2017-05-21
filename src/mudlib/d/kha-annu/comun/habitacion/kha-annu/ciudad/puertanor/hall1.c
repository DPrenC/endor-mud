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
 "Estas dentro de Kha-annu, en la parte norte. Aqui hay un gran hall lleno "
 "de bullicio, enanos que entran y salen de la ciudad, guardias, algun tendero "
 "viajeros ...\n"
 "Al sur puedes ver una gran calle excavada en la roca que penetra en la "
 "montaña hacia el sur de Kha-annu.\n");
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

 AddExit("sur",("hall5"));
 AddExit("oeste",("hall2"));
 AddExit("sudeste",("hall6"));
 AddExit("este",("hall3"));
 AddExit("norte",PUERTANOR+"entrada");

 SetLocate("Kha-annu");

 }

