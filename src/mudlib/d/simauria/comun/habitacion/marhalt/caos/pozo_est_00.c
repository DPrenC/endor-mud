/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitaci�n base, corrijo mogoll�n de typos y m�s
*****************************************************************************/

#include "path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
  ::create();

  SetIntShort("un pasillo");
  SetIntLong("Te encuentras en el pasillo entre dos estancias. Las paredes "
    "son de color marr�n, pero salvo eso no hay nada de inter�s.\n");
  SetIntSmell("Hueles como a podrido desde la parte suroeste.\n");
  AddExit("suroeste",CAOSHAB"cieno_05");
  AddExit("noroeste",CAOSHAB"pozo_est_01");
}
