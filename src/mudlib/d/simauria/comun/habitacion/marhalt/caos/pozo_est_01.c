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
    "son de un color entre amarillento y marrón, pero salvo eso no hay nada "
    "de interés.\n");
  AddExit("sudeste",CAOSHAB"pozo_est_00");
  AddExit("sur",CAOSHAB"pozo_est_02");
}
