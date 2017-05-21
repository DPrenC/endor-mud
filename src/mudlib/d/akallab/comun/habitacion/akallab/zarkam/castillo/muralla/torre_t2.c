/*
DESCRIPCION : (tipo) parte baja de una torre del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/torre_t2.c
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
 SetIntShort("la parte baja de una torre");
 str= "Estas en la parte baja de una de las torres del castillo. Desde aqui parte una "
      "escalera de caracol hacia los pisos superiores. El interior de la torre esta "
      "iluminado mediante varias antorchas colocadas en la pared.\n";

 switch (nsalidas){
   case 0: str+= "No hay salida al exterior de la torre.\n";break;
   case 1: str+= "Una puerta te permite salir al exterior de la torre.\n";break;
   default: str+="Varias puertas te permiten salir al exterior de la torre.\n";break;
 }

 SetIntLong(str);

 AddDetail(({"puerta"}),
   "Es una gruesa puerta de madera. Permite salir al exterior de la torre.\n");

 AddDetail(({"escalera"}),
   "Es una escalera de caracol. Su forma de helice permite que ocupe poco sitio en "
   "el interior de la torre. Sus peldanyos, unos gruesos bloques de piedra que se "
   "apoyan sobre la pared de la torre y sobre la columna central, parecen algo "
   "desgastados por el uso.\n");

 AddDetail(({"antorchas"}), "Su luz es tenue, pero basta para iluminar el interior de la torre.\n");

 AddDetail(({"torre"}),QueryIntLong());

 if (guardias!=0) AddItem(PNJ("z_castillo/guardia"), REFRESH_DESTRUCT, guardias);

 SetIntNoise("Oyes el viento que sopla en el exterior.\n");
 SetIntSmell("Hmm.. huele a humedo.\n");
 SetLocate("castillo de Zarkam");
 SetIndoors(1);
 SetIntBright(30);
}
