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
  SetIntLong("Te encuentras en un pasillo entre 2 habitaciones, las paredes "
    "son de color gris jaspeado de unos 6 metros de altura. Al este el túnel "
    "da a una pared descendente de 18 metros de altura pero la cantidad de "
    "salientes facilita mucho el descenso.\n");
  AddDetail(({"pared","pared descendente"}),
    "Cuando te fijas en la pared te percatas que alguien ha ido arrancando, "
    "poco a poco, trozos de la pared para igualar los apenas 6 metros de "
    "esta parte del túnel con los 24 de la parte inferior. No sabes que"
    " criatura puede haber sido, pero tienes muy claro que es muy grande.\n");
  AddExit("oeste",CAOSHAB"grieta_01");
  AddExit("este",CAOSHAB"grieta_03");
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
}
