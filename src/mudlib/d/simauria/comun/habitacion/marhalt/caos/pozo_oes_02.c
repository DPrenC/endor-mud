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

  SetIntShort("una habitación en obras");
  SetIntLong("Te encuentras en el pasillo entre dos estancias. Las paredes "
    "son de color blanco, pero salvo eso no hay nada de interés.\n");
  AddExit("norte",CAOSHAB"pozo_oes_01");
  AddExit("sur",CAOSHAB"pozo_oes_03");
}
