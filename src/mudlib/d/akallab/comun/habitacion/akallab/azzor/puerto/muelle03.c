 /*
DESCRIPCION : frente a la taberna del Tuerto en el puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/muelle02.c
MODIFICACION: 07-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include "moving.h"
#include AK_MACRO
inherit ROOM;

#define BARCA (AZ_PUERTO("pesca03"))

int ir_barca(){
  write("Bajas del muelle a la barca de pesca.\n");
  say(NOMBRE+" baja del muelle a una barca de pesca.\n",TP);
  tell_room(BARCA ,NOMBRE+" baja del muelle a esta barca.\n");
  TP->move(BARCA ,M_SILENT);
  //tell_object(TP, BARCA->QueryIntLong());
  //tell_object(TP, BARCA->Exits(0,TP));
  return 1;
}

create(){
 ::create();
SetIntShort("el puerto de Azzor");
 SetIntLong(
   "'Si quieres un trago y pasarlo bien, ¡Ve a la taberna del Tuerto!' \n"
   "No recuerdas exactamete quien te lo dijo pero no importa. Esa "
   "taberna se encuentra en el bajo y viejo edificio que queda al oeste "
   "de aquí. En la dársena puedes observar la multitud de barcos fondeados. "
   "Junto al muelle hay una barca de pesca amarrada\n");

#include "puerto_detail.h"

 AddDetail(({"taberna","edificio"}),
 "Queda al oeste de aquí.\n");

 AddExit("norte",AZ_PUERTO("muelle02"));
 AddExit("oeste",AZ_PUERTO("portico03"));
 AddExit("barca",SF(ir_barca));
 AddExit("sur",AZ_PUERTO("muelle00"));
 AddItem(PNJ_AZZOR("hakor"), REFRESH_DESTRUCT, 1);
}
