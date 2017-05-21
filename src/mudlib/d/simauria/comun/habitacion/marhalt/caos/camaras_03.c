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

  SetIntShort("una cámara pequeña");
  SetIntLong("Te encuentras dentro de una cámara no muy grande. No hay nada "
    "destacable aqui.\n");
  AddExit("sur",CAOSHAB"camaras_02");
}
