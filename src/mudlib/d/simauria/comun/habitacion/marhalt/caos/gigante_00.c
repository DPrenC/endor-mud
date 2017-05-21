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

  SetIntShort("la c�mara gigante");
  SetIntLong("Est�s en la parte central de una sala ovalada muy grande. Las "
    "paredes son marrones y el techo amarillo. El suelo esta lleno de "
    "piedrecitas.\n");
  AddDetail(({"piedras","piedrecitas"}),
    "Son peque�as y redondas, ideales para jugar a las canicas o a los "
    "chinos.\n");
  AddExit("noroeste",CAOSHAB"estatuas_01");
  AddExit("norte",CAOSHAB"gigante_01");
  AddExit("nordeste",CAOSHAB"gigante_02");
  AddExit("este",CAOSHAB"gigante_03");
  AddExit("sudeste",CAOSHAB"camaras_00");
  AddExit("suroeste",CAOSHAB"broos_00");
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
}
