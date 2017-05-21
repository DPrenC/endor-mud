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
  SetIntLong("Te encuentras dentro de una cámara no muy grande, de apenas "
    "unos nueve metros cuadrados, pero con más de siete metros de altura. "
    "No hay nada destacable dentro de la cámara.\n");
  AddExit("oeste",CAOSHAB"gigante_03");
}
