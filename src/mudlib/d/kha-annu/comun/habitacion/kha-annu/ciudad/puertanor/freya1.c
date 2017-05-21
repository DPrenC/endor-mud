//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   freya1.c                          *
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

 SetIntShort("la calle Freya");
 SetIntLong(
 "Esta es la calle que lleva hasta la parte principal de Kha-annu.\n"
 "Nada mas comenzar a andar ves unas grandes puertas como las de la "
 "entrada pero estas estan permanente abiertas.\n"
 "Un monton de faroles alumbran la calle.\n");

 SetIndoors(1);
 SetIntBright(60);
 SetIntNoise("Oyes el bullicio de la ciudad al final de la calle.\n");
 SetIntSmell("No huele a nada raro.\n");

 AddDetail(({"calles","calle"}),
"Esta calle alumbrada por falores deciende hacia las profundidades "
"de la montaña.\n");
 AddDetail(({"puertas","puerta"}),
"Las puertas son identicas a las de la entrada a Kha-annu. Estas\n",
"puertas se utilizan para defender los niveles de al ciudad en caso\n",
"de guerra. En epoca de paz siempre estan abiertas.\n");

 AddExit("sur",("freya2"));
 AddExit("norte",("hall5"));

 AddItem(MONS+"guardia2",REFRESH_DESTRUCT,2);

 }
