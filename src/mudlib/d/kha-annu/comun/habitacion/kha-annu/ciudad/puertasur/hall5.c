//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   hall5.c                           *
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
 "Este es el final del hall, sigue habiendo gente de un lado a otro.\n"
 "Al norte ves la calle Gorin que desciende hacia las profundidades,\n");

 SetIndoors(1);
 SetIntBright(60);
 SetIntNoise("Oyes el bullicio de la ciudad que sale de la puerta.\n");
 SetIntSmell("No huele a nada raro.\n");

 AddDetail(({"calles","calle"}),
"Esta calle alumbrada por faroles deciende hacia las profundidades "
"de la montanya.\n");
 AddExit("norte",("gorin1"));
 AddExit("este",("hall6"));
 AddExit("sudeste",("hall3"));
 AddExit("sur",("hall1"));
 AddExit("oeste",("hall4"));
 AddExit("suroeste",("hall2"));

 SetLocate("Kha-annu");
 }

