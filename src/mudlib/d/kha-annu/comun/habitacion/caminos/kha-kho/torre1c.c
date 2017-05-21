/* Kha-mino del norte :-)
   Gorthem Nov 2000 */
#include "./path.h"

inherit KHA_ROOM;

create() {
 ::create();

SetIntShort("las almenas de la torre");

SetIntLong(
"Estas en las almenas de las torres. ¡Menuda vista! Desde aqui puedes ver "
"las toda la cordillera de Kha-annu con sus cumbres cubiertas de nieve que "
"queda al sur y al oeste de aqui. Dal norte se extiende un bonito valle con "
"un río que lleva hasta la mismisima Simauria.\n");

 SetIndoors(0);

 SetIntBright(25);

 SetIntNoise("Oyes ruidos en el piso inferior.\n");
 SetIntSmell("Huele a compañerismo.\n");

 AddDetail(({"camastro","camastros"}),
 "Son unos camatros de madera con un colchon de plumas. Sin duda los guardias "
 "duermen a gusto.\n");

 AddDetail(({"armarios","armario"}),
 "So unos pequeños armarios que no miden mas de un metro y medio, hechos de "
 "perfecta madera. Estan cerrados a cal y canto.\n");
 AddExit("abajo",(CAMINO_NORTE+"torre1b"));
}