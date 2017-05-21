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

  SetIntShort("el noreste de la c�mara del lago");
  SetIntLong("Te encuentras en la parte nordeste de la c�mara del lago "
    "interior. Ves m�s fragmentos de conchas por el suelo, pero nada "
    "destacable.\n");
  AddExit("oeste",CAOSHAB"lago_01");
}
