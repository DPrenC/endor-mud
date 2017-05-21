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

  SetIntShort("el sur de la forja");
  SetIntLong("Estás en la parte sur de una habitacion irregular. Sus paredes "
    "y techo son de color marrón oscuro. A tus pies hay un pico y la pared "
    "del oeste parece haber sido picada para extraer minerales. Al norte hay "
    "una forja, al noroeste observas un agujero en el suelo. Hay armas y "
    "armaduras a medio hacer por toda la estancia.\n");
  SetIntSmell("No hueles nada destacable, sólo el olor típico de las "
    "forjas.\n");
  SetIntNoise("No escuchas nada interesante, salvo el chasquido del fuego de "
    "la forja.\n");
  AddDetail(({"forja"}),
    "Está más al norte.\n");
  AddDetail(({"agujero","pozo"}),
    "Está al Noroeste de tu situación.\n");
  AddDetail(({"arma","armas","escudo","escudos","armadura","armaduras"}),
    "Están a medio hacer, por lo que no merece la pena molestarse en "
    "cogerlas.\n");
  AddDetail(({"pico"}),
    "El pico está en perfecto estado de conservación. Los habitantes de la "
    "caverna deben utilizarlo para extraer minerales de la pared del "
    "oeste.\n");
  AddDetail(({"pared","pared oeste","pared picada","pared del oeste"}),
    "Ves que la pared del oeste es una rica veta de mineral ferroso, que los "
    "habitantes de la caverna extraen para forjar armas y armaduras en la "
    "forja del norte.\n");
  AddExit("norte",CAOSHAB"forja_02");
  AddExit("oeste",CAOSHAB"forja_00");
  AddExit("noroeste",CAOSHAB"forja_01");
}
