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

  SetIntShort("el noreste de la estancia del arroyo");
  SetIntLong("Te encuentras en la parte norte de una gran estancia "
    "rectangular. En el centro de la estancia ves una especie de charca. "
    "Puedes distinguir siete estatuas de color verde jaspeado, una de ellas "
    "a tu lado.\n");
  SetIntNoise("Escuchas el suave rumor del movimiento subterraneo de las "
    "aguas en la charca.\n");
  AddDetail(({"estatuas"}),
    "Una estatua esta a tu lado, otra se encuentra hacia el oeste, dos al "
    "sur y las otras tres al sureste.\n");
  AddDetail(({"estatua"}),
    "La estatua está en buen estado. Cuando te fijas en su rostro notas "
    "una expresion de terror más allá de lo imaginable. Te percatas que "
    "todas las estatuas están como huyendo de algo que viniese de la zona "
    "sur, menos una en el centro de la charca en postura desafiante mirando "
    "a dicha pared.\n");
  AddExit("noroeste",CAOSHAB"hemisferio_01");
  AddExit("oeste",CAOSHAB"arroyo_00");
  AddExit("sur",CAOSHAB"arroyo_03");
  AddExit("suroeste",CAOSHAB"arroyo_01");
  AddExit("nordeste",CAOSHAB"tunel_00");
}
