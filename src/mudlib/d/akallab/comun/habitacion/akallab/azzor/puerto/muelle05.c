 /*
DESCRIPCION : frente a la taberna de Sally en el puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/muelle04.c
MODIFICACION: 07-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include "moving.h"
#include AK_MACRO
inherit ROOM;

#define BARCA (AZ_PUERTO("pesca05"))

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
   "Al oeste de aquí se halla la taberna de Sally la gorda, una de las más "
   "conocidas, del puerto: buen precio, buen ambiente, bebida no muy aguada "
   "y broncas frecuentes... La taberna es un edificio bajo con pórtico "
   "como la mayoría de los del puerto. La dársena continúa hacia de Sur a Norte "
   "en dirección a la fortaleza de Azzor. Junto al muelle hay una barca de pesca "
   "amarrada\n");

 AddDetail(({"taberna","edificio"}),
  "Queda al oeste de aquí. ¡Deja de pensartelo, entra y tómate algo en ella!\n");

#include "puerto_detail.h"

 AddExit("norte",AZ_PUERTO("muelle04"));
 AddExit("oeste",AZ_PUERTO("portico05"));
 AddExit("sur",AZ_PUERTO("muelle06"));
 AddExit("barca",SF(ir_barca));
}
