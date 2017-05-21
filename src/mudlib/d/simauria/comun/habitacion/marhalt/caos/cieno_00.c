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
    "ason de color amrillento, pero salvo eso no hay nada de inter�s.\n");
  AddExit("norte",CAOSHAB"cieno_01");
  AddExit("sur",CAOSHAB"gigante_02");
}
