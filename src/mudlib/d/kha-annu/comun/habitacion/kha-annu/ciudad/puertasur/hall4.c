//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   hall4.c                           *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 01.08.98                  *
//* Modificacion: 04.11.98              *
//* Agradecimientos:                    *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

#include "./path.h"
inherit KHA_ROOM;
create() {
 ::create();

 SetIntShort("el hall de Kha-annu");
 SetIntLong(
 "Llegas a otra esquina del hall de la puerta sur, justo al este esta la "
 "entrada a la bajada a Kha-annu. Tambien al sur hay un barracon.\n"
 "La construccion sigue siendo magnifica, esta claro que estas en Kha-annu.\n");

 SetIndoors(1);
 SetIntBright(60);
 SetIntNoise("Oyes un poco de todo.\n");
 SetIntSmell("Nada en especial.\n");

 AddDetail(({"calles","calle"}),
"Esta calle alumbrada por falores deciende hacia las profundidades "
"de la montanya.\n");
/*
 AddExit("oeste",("mina"));
*/
 AddExit("este",("hall5"));
 AddExit("sudeste",("hall1"));
 AddExit("sur",("hall2"));

 SetLocate("Kha-annu");
 AddItem(MONS+"minero",REFRESH_DESTRUCT,1);
 }

