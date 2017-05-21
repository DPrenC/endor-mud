//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   hall6.c                           *
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
 "Llegas a el ultimo rincon del hall, todo sigue igual de tallado y "
 "decorado por un gusto enanil exquisito.\n"
 "Al norte y al oeste otras partes del hall. Al oeste la entrada a la ciudad.\n");

 SetIndoors(1);
 SetIntBright(60);
 SetIntNoise("Oye el bullicio de la ciudad de la puerta del oeste.\n");
 SetIntSmell("No huele a nada raro.\n");

 AddDetail(({"calles","calle"}),
"Esta calle alumbrada por falores deciende hacia las profundidades "
"de la montanya.\n");
 AddExit("oeste",("hall5"));
 AddExit("norte",("hall3"));
 AddExit("noroeste",("hall1"));

 AddItem(MONS+"paseante",REFRESH_DESTRUCT,1);

 }

