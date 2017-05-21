/*
DESCRIPCION : puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/pesca03.c
MODIFICACION:
17-09-07 [Angor] Creacion
*/

#include "path.h"
#include "moving.h"
#include AK_MACRO
inherit PORT;

#define MUELLE (AZ_PUERTO("muelle03"))

int ir_muelle(){
  write("Desembarcas y subes al muelle.\n");
  say(NOMBRE+" desembarca y sube al muelle.\n",TP);
  tell_room(MUELLE ,NOMBRE+" desembarca de una barca amarrada junto al muelle.\n");
  TP->move(MUELLE ,M_SILENT);
  //tell_object(TP, MUELLE->QueryIntLong());
  //tell_object(TP, MUELLE->Exits(0,TP) );
  return 1;
}

create(){
 ::create();
SetIntShort("una barca de pesca");
 SetIntLong(
  "Est�s a bordo de una barca de pesca de mediano tama�o amarrada al muelle del puerto. "
  "Pese al cabo que une la proa con el muelle, la barca da ligeros bandazos con debido "
  "a las olas. El foque est� libre y la vela mayor sujeta la botavara bajada. En el "
  "suelo de la barca hay varias redes enrolladas y en la popa, junto al tim�n, varios "
  "cubos con fuerte olor a pescado.\n");

#include "pesca_detail.ic"

  AddExit("muelle",SF(ir_muelle));
  AddItem(PNJ_AZZOR("pescador_barca"),REFRESH_DESTRUCT);
}
