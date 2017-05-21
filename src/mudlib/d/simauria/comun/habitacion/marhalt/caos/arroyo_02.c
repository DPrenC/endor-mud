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

  SetIntShort("el sur de la estancia del arroyo");
  SetIntLong("Te encuentras en la zona sur de la estancia del arroyo, tanto "
    "el suelo como la pared presentan amplias ondulaciones, como si "
    "estuvieran hechos de alg�n material l�quido que se hubiera congelado"
    " tan r�pidamente que no hubiera tenido tiempo de alisarse.\n");
  SetIntNoise("Escuchas unos golpecitos desde el otro lado de la pared.\n");
  AddDetail(({"pared","ondulaciones"}),
    "Cuando miras m�s de cerca la pared ves toda una serie de seres "
    "fosilizados (sobretodo humanos). Adem�s crees haber o�do algo.\n");
  AddExit("norte",CAOSHAB"arroyo_01");
  AddExit("este",CAOSHAB"arroyo_estatuas");
  AddExit("nordeste",CAOSHAB"arroyo_03");
}
