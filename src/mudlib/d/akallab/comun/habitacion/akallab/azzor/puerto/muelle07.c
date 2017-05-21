 /*
DESCRIPCION : parte del muelle de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/muelle07.c
MODIFICACION: 09-09-07 [Angor@Simauria] Creacion
*/

#include "path.h"
#include "moving.h"
#include AK_MACRO
inherit ROOM;

#define BARCA (AZ_PUERTO("pesca07"))

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
   "El muelle del puerto de Azzor comienza aquí a girar lentamente "
   "hacia el sudeste, camino de la entrada del puerto. De la fachada del "
   "estrecho edificio que se encuentra al oeste cuelga un rótulo "
   "indicando que allí se halla una sede del gremio de aventureros. Junto al muelle "
   "hay una barca de pesca amarrada.\n");

#include "puerto_detail.h"

 AddDetail(({"gremio", "rotulo", "rótulo"}),
  "Es una plancha de madera con el símbolo del gremio de los aventureros.\n");

 //AddExit("sudeste",AZ_PUERTO("muelle08"));
 AddExit("oeste",AZ_PUERTO("portico07"));
 AddExit("norte",AZ_PUERTO("muelle06"));
 //AddExit("este",AZ_PUERTO("pesca07"));
 AddExit("barca",SF(ir_barca));
}