//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   gorin2.c                          *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 02.08.98                  *
//* Modificacion: 02.08.98              *
//* Agradecimientos:                    *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

#include "./path.h"
inherit KHA_ROOM;
create() {
 ::create();

 SetIntShort("la calle Gorin");
 SetIntLong(
 "La calle continua al norte, un poco mas para alla te parece ver una "
 "esquina. Detras tuyo quedan las puertas de este nivel y el hall de "
 "la entrada, al norte la grandeza de la capital de los enanos.\n"
 "Un monton de faroles alumbran la calle.\n");

 SetIndoors(1);
 SetIntBright(60);
 SetIntNoise("Oyes el bullicio de la ciudad al final de la calle.\n");
 SetIntSmell("No huele a nada raro.\n");

 AddDetail(({"calles","calle"}),
"Esta calle alumbrada por falores deciende hacia las profundidades "
"de la montaña.\n");
 AddDetail(({"puertas","puerta"}),
"Las puertas son identicas a las de la entrada a Kha-annu. Estas "
"puertas se utilizan para defender los niveles de al ciudad en caso "
"de guerra. En epoca de paz siempre estan abiertas.\n" );

 AddExit("norte",CIUDAD+"baldur6");
 AddExit("sur",("gorin1"));

 AddItem(MONS+"guardia",REFRESH_DESTRUCT,2);
 SetLocate("Kha-annu");
 }

