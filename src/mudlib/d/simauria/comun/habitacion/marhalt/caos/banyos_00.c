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

  SetIntShort("los ba�os");
  SetIntLong("Te encuentras en una sala ovoidal de priedra rojiza. Ves tres "
    "agujeros circulares llenos de agua cenagosa. Hay cuatro estatuas, dos "
    "de ellas al este y dos al oeste, que representan a varones humanos "
    "vistiendo armadura.\n");
  SetIntSmell("S�lo hueles el cieno del agua.\n");
  AddDetail(({"agujero","agujeros","agua","agua cenagosa","cieno"}),
    "No son m�s que charcas de agua cenagosa y maloliente.\n");
  AddDetail(({"estatuas","estatua"}),
    "Est�n al este y al oeste.\n");
  AddExit("norte",CAOSHAB"lago_04");
  AddExit("oeste",CAOSHAB"banyos_02");
  AddExit("este",CAOSHAB"banyos_01");
}
