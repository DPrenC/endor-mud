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

  SetIntShort("el noreste de la c�mara gigante");
  SetIntLong("Est�s en la parte norte de una sala ovalada muy grande. Las "
    "paredes son marrones y el techo amarillo. El suelo esta lleno de "
    "piedrecitas.\n");
  AddExit("norte",CAOSHAB"cieno_00");
  AddExit("suroeste",CAOSHAB"gigante_00");
  AddExit("sur",CAOSHAB"gigante_03");
  AddExit("oeste",CAOSHAB"gigante_01");
  AddExit("este",CAOSHAB"apos_sur_00");
}
