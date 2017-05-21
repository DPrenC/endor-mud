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
  SetIntLong("Te encuentras en un pasillo entre 2 habitaciones, las paredes "
    "son de color gris jaspeado de unos 6 metros de altura, pero nada más de "
    "interés.\n");
  AddExit("oeste",CAOSHAB"grieta_00");
  AddExit("este",CAOSHAB"grieta_02");
}
