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

  SetIntShort("el pozo gris");
  SetIntLong("Te encuentras en una sala de forma aproximadamente circular de "
    "unos 5 metros de di�metro y 6 de altura. Las paredes son de color gris "
    "jaspeado, pero el suelo esta cubierto de un polvo gris-verdoso.\n");
  AddExit("norte",CAOSHAB"pozo_oes_02");
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
}
