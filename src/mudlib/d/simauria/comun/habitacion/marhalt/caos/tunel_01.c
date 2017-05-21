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
    "son de color marrón claro, pero salvo eso no hay nada de interés.\n");
  SetIntNoise("Escuchas el ruido de algo muy grande caminando en algún túnel "
    "muy cercano a este y que circula por debajo, de eso no hay duda "
    "posible.\n");
  AddExit("sur",CAOSHAB"tunel_00");
  AddExit("norte",CAOSHAB"tunel_02");
}
