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

  SetIntShort("el este de la estancia del arroyo");
  SetIntLong("Te encuentras en la parte este de una gran estancia "
    "rectangular. En el centro de la estancia ves una especie de charca. "
    "Puedes distinguir siete estatuas de color verde jaspeado, tres de ellas "
    "a tu lado.\n");
  AddDetail(({"estatua","estatuas"}),
    "La estatua est� en buen estado. Cuando te fijas en su rostro notas una "
    "expresion de terror m�s all� de lo imaginable. Te percatas que todas "
    "las estatuas est�n como huyendo de algo que viniese de la zona sur, "
    "menos una en el centro de la charca en postura desafiante mirando a "
    "dicha pared.\n");
  AddExit("sur",CAOSHAB"arroyo_estatuas");
  AddExit("oeste",CAOSHAB"arroyo_01");
  AddExit("suroeste",CAOSHAB"arroyo_02");
  AddExit("norte",CAOSHAB"arroyo_04");
  AddExit("noroeste",CAOSHAB"arroyo_00");
}