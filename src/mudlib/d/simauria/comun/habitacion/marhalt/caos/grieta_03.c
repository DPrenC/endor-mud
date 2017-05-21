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

  SetIntShort("un pasillo");
  SetIntLong("Te encuentras en un pasillo entre 2 habitaciones, las "
    "paredes son de color gris de unos 24 metros de altura. Al oeste el "
    "túnel da a una pared de 18 metros de altura pero la cantidad de "
    "salientes facilita mucho la escalada.\n");
  AddDetail(({"pared","pared ascendente"}),
    "Cuando te fijas en la pared te percatas que alguien ha ido arrancando, "
    "poco a poco, trozos de la pared para igualar los apenas 6 metros de la "
    "parte superior del túnel con los 24 de esta parte. No sabes que "
    "criatura puede haber sido, pero tienes muy claro que es muy grande.\n");
  AddExit("oeste",CAOSHAB"grieta_02");
  AddExit("este",CAOSHAB"grieta_04");
}
