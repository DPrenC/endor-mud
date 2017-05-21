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

  SetIntShort("el puente de la c�mara del lago");
  SetIntLong("Te encuentras frente al puente que lleva hacia el sur. Lo "
    "�nico destacable es el puente.\n"
    "La c�mara del lago continua hacia el oeste; hacia el este esta el lago, "
    "y en direcci�n Nordeste la entrada a la c�mara.\n");
  AddDetail(({"puente"}),W(
    "El puente esta muy h�medo y parece muy resbaladizo.\n"));
  AddExit("nordeste",CAOSHAB"lago_00");
  AddExit("oeste",CAOSHAB"lago_05");
  AddExit("sur",CAOSHAB"banyos_00");
  AddExit("este",CAOSHAB"lago_03");
}
