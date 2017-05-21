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
  AddExit("oeste",CAOSHAB"hemisferio_00");
  AddExit("sur",CAOSHAB"arroyo_00");
  AddExit("sudeste",CAOSHAB"arroyo_04");
}
