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

  SetIntShort("el norte de la cámara del lago");
  SetIntLong("Te encuentras en la parte norte del lago interior. Puedes "
    "ver más fragmentos de conchas por el suelo, pero nada destacable.\n"
    "La playa continua hacia el este, la entrada está al oeste, y al "
    "suroeste se encuentra el lago.\n");
  AddExit("oeste",CAOSHAB"lago_00");
  AddExit("suroeste",CAOSHAB"lago_03");
  AddExit("este",CAOSHAB"lago_02");
}
