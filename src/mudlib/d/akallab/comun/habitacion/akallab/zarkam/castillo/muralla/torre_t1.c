/*
DESCRIPCION : (tipo) parte media de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/torre_t0.c
MODIFICACION: 26-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

int guardias;  //numero de guardias
int nsalidas;  //numero de salidas

create() {
 string str;

 ::create();
SetIntShort("el interior de una torre");
 str= "Estas en el interior de una de las torres del castillo. Una escalera de caracol "
      "permite subir y bajar a otros pisos de la torre. Las antorchas colocadas en la "
      "pared iluminan el interior de la torre con una luz tenue pero suficiente.\n";

 switch (nsalidas){
   case 0: str+= "Observas que en este nivel de la torre no hay ninguna salida al exterior.\n";break;
   case 1: str+= "Observas que en este nivel de la torre hay una salida que te permite salir al "
                 "exterior.\n";break;
   default: str+="Observas que en este nivel de la torre hay "+nsalidas+" salidas que te permiten salir "
                 "al exterior.\n";break;
 }

 SetIntLong(str);

 AddDetail(({"escalera"}),
   "Es una escalera de caracol. Su forma de helice permite que ocupe poco sitio en "
   "el interior de la torre. Sus peldanyos, unos gruesos bloques de piedra que se "
   "apoyan sobre la pared de la torre y sobre la columna central, parecen algo "
   "desgastados por el uso.\n");

 AddDetail(({"antorchas"}), "Su luz ilumina el interior de la torre.\n");

 AddDetail(({"torre"}),QueryIntLong());

 if (guardias!=0) AddItem(PNJ("z_castillo/guardia"), REFRESH_DESTRUCT, guardias);

 SetIntNoise("Oyes el viento que sopla en el exterior.\n");
 SetIntSmell("Hmm.. huele a humedo.\n");
 SetLocate("castillo de Zarkam");
 SetIndoors(1);
 SetIntBright(30);
}
