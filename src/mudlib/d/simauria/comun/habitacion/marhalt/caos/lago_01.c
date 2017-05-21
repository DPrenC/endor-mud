/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitaci�n base, corrijo mogoll�n de typos y m�s
*****************************************************************************/

#include "path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
  ::create();

  SetIntShort("el norte de la c�mara del lago");
  SetIntLong("Te encuentras en la parte norte del lago interior. Puedes "
    "ver m�s fragmentos de conchas por el suelo, pero nada destacable.\n"
    "La playa continua hacia el este, la entrada est� al oeste, y al "
    "suroeste se encuentra el lago.\n");
  AddExit("oeste",CAOSHAB"lago_00");
  AddExit("suroeste",CAOSHAB"lago_03");
  AddExit("este",CAOSHAB"lago_02");
}
