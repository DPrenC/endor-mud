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
    "son de color verde, pero salvo eso no hay nada de interés.\n");
  SetIntNoise("Escuchas el rumor de un río por el este.\n");
  AddExit("este",CAOSHAB"musgosa_02");
  AddExit("oeste",CAOSHAB"pozo_oes_01");
}
