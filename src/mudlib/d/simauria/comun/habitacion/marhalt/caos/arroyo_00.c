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

  SetIntShort("el norte de la estancia del arroyo");
  SetIntLong("Te encuentras en la parte norte de una gran estancia "
    "rectangular. En el centro de la estancia ves una especie de charca. "
    "Puedes distinguir siete estatuas de color verde jaspeado, una de ellas "
    "a tu lado.\n");
  SetIntNoise("Escuchas en suave rumor del paso del agua en la charca del "
    "sur.\n");
  AddDetail(({"estatuas"}),
    "Una estatua esta a tu lado, otra se encuentra hacia el este, dos al sur "
    "y las otras tres al sureste.\n");
  AddDetail(({"estatua"}),
    "La estatua está en bastante buen estado. Cuando te fijas en su rostro "
    "notas una expresion de terror más alla de lo imaginable. Te percatas "
    "que todas las estatuas están como huyendo de algo que viniese de la "
    "zona sur, menos una en el centro de la charca en postura desafiante "
    "mirando a dicha pared.\n");
  AddExit("norte",CAOSHAB"hemisferio_01");
  AddExit("este",CAOSHAB"arroyo_04");
  AddExit("sur",CAOSHAB"arroyo_01");
  AddExit("sudeste",CAOSHAB"arroyo_03");
}
