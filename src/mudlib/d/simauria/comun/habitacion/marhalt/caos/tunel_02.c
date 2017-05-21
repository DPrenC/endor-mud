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

  SetIntShort("un túnel");
  SetIntLong("Te encuentras en un túnel muy húmedo. La altura de la estancia "
    "es de unos 4 metros.\n");
  SetIntNoise("Escuchas el ruido de algo muy grande caminando en algún "
    "túnel muy cercano a este que debe circular por arriba o por abajo.\n");
  AddExit("sur",CAOSHAB"tunel_01");
}
