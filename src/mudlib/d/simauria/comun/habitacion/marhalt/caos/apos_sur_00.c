/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitación base, corrijo mogollón de typos y más
*****************************************************************************/

#include "path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
  ::create();

  SetIntShort("un pasillo");
  SetIntLong("Te encuentras en el pasillo entre dos estancias. Las paredes "
    "son de color amarillento, pero salvo eso no hay nada de interés.\n");
  AddExit("suroeste",CAOSHAB"gigante_03");
  AddExit("nordeste",CAOSHAB"apos_sur_01");
  AddExit("oeste",CAOSHAB"gigante_02");
}
