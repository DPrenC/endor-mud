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
 "Legas a el ultimo rincon del hall, todo sigue igual de tallado y "
 "decorado por un gusto enanil exquisito.\n"
 "Al sur u al oeste otras partes del hall.Al este la entrada a la ciudad.\n");

 SetIndoors(1);
 SetIntBright(60);
 SetIntNoise("Oye el bullicio de la ciudad de la puerta del este.\n");
 SetIntSmell("No huele a nada raro.\n");

 AddDetail(({"calles","calle"}),
"Esta calle alumbrada por falores deciende hacia las profundidades "
"de la montanya.\n");
 AddExit("norte",("gorin1"));
 AddExit("oeste",("hall5"));
 AddExit("sur",("hall3"));
 AddExit("suroeste",("hall1"));

 AddItem(MONS+"paseante",REFRESH_DESTRUCT,1);
 SetLocate("Kha-annu");
 }

