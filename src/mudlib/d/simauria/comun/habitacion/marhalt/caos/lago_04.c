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

  SetIntShort("el puente de la cámara del lago");
  SetIntLong("Te encuentras frente al puente que lleva hacia el sur. Lo "
    "único destacable es el puente.\n"
    "La cámara del lago continua hacia el oeste; hacia el este esta el lago, "
    "y en dirección Nordeste la entrada a la cámara.\n");
  AddDetail(({"puente"}),W(
    "El puente esta muy húmedo y parece muy resbaladizo.\n"));
  AddExit("nordeste",CAOSHAB"lago_00");
  AddExit("oeste",CAOSHAB"lago_05");
  AddExit("sur",CAOSHAB"banyos_00");
  AddExit("este",CAOSHAB"lago_03");
}
