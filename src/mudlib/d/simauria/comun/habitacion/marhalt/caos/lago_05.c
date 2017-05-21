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

  SetIntShort("el oeste de la cámara del lago");
  SetIntLong("Te encuentras en la parte oeste de la cámara del lago "
    "interior. Ves más fragmentos de conchas por el suelo, pero nada "
    "destacable.\n");
  AddExit("este",CAOSHAB"lago_04");
}
