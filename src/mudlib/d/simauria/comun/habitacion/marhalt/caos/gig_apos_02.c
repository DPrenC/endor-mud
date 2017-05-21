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
  SetIntLong("Te encuentras en un pasillo entre dos estancias. Las paredes "
    "son de tono rojizo, pero salvo eso no hay nada de interés.\n");
  AddExit("suroeste",CAOSHAB"gig_apos_01");
  AddExit("este",CAOSHAB"apos_nor_00");
}
