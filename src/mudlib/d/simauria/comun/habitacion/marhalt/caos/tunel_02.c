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

  SetIntShort("un t�nel");
  SetIntLong("Te encuentras en un t�nel muy h�medo. La altura de la estancia "
    "es de unos 4 metros.\n");
  SetIntNoise("Escuchas el ruido de algo muy grande caminando en alg�n "
    "t�nel muy cercano a este que debe circular por arriba o por abajo.\n");
  AddExit("sur",CAOSHAB"tunel_01");
}
