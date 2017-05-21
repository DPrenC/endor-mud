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

  SetIntShort("un pasillo");
  SetIntLong("Te encuentras en un extremo de un pasillo gris de unos 13 "
    "metros de altura.\n");
  SetIntNoise("Escuchas el rumor de un r�o por el este.\n");
  AddExit("oeste",CAOSHAB"grieta_03");
  AddExit("este",CAOSHAB"musgosa_01");
}
