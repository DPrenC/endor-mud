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

  SetIntShort("los baños");
  SetIntLong("Te encuentras en una sala ovoidal de priedra rojiza. Ves tres "
    "agujeros circulares llenos de agua cenagosa. Hay cuatro estatuas, dos "
    "de ellas al este y dos al oeste, que representan a varones humanos "
    "vistiendo armadura.\n");
  SetIntSmell("Sólo hueles el cieno del agua.\n");
  AddDetail(({"agujero","agujeros","agua","agua cenagosa","cieno"}),
    "No son más que charcas de agua cenagosa y maloliente.\n");
  AddDetail(({"estatuas","estatua"}),
    "Están al este y al oeste.\n");
  AddExit("norte",CAOSHAB"lago_04");
  AddExit("oeste",CAOSHAB"banyos_02");
  AddExit("este",CAOSHAB"banyos_01");
}
