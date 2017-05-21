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
    "son de color marrón y textura dura, pero salvo eso no hay nada de "
    "interés.\n");
  AddExit("oeste",CAOSHAB"arroyo_02");
  AddExit("norte",CAOSHAB"arroyo_03");
  AddExit("noroeste",CAOSHAB"arroyo_01");
  AddExit("sudeste",CAOSHAB"estatuas_00");
}
