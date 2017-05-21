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
  SetIntLong("Te encuentras en un extremo de un pasillo gris de unos 13 "
    "metros de altura, donde la pared oeste forma una especie de pliege "
    "rocoso.\n");
  AddDetail(({"pared","pared oeste","pliegue","pliegue rocoso"}),
    "Cuando examinas el pliegue rocoso descubres que es una hendidura que "
    "da hacia el oeste a una gran estancia.\n");
  AddExit("oeste",CAOSHAB"lago_03");
  HideExit("oeste",1);
  AddExit("este",CAOSHAB"grieta_01");
}
