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

  SetIntShort("el sur de la forja");
  SetIntLong("Est�s en la parte sur de una habitacion irregular. Sus paredes "
    "y techo son de color marr�n oscuro. A tus pies hay un pico y la pared "
    "del oeste parece haber sido picada para extraer minerales. Al norte hay "
    "una forja, al noroeste observas un agujero en el suelo. Hay armas y "
    "armaduras a medio hacer por toda la estancia.\n");
  SetIntSmell("No hueles nada destacable, s�lo el olor t�pico de las "
    "forjas.\n");
  SetIntNoise("No escuchas nada interesante, salvo el chasquido del fuego de "
    "la forja.\n");
  AddDetail(({"forja"}),
    "Est� m�s al norte.\n");
  AddDetail(({"agujero","pozo"}),
    "Est� al Noroeste de tu situaci�n.\n");
  AddDetail(({"arma","armas","escudo","escudos","armadura","armaduras"}),
    "Est�n a medio hacer, por lo que no merece la pena molestarse en "
    "cogerlas.\n");
  AddDetail(({"pico"}),
    "El pico est� en perfecto estado de conservaci�n. Los habitantes de la "
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
