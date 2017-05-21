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

  SetIntShort("el este de la c�mara gigante");
  SetIntLong("Est�s en la parte este de una sala ovalada muy grande. Las "
    "paredes son marrones y el techo amarillo. El suelo esta lleno de "
    "piedrecitas.\n");
  AddExit("oeste",CAOSHAB"gigante_00");
  AddExit("este",CAOSHAB"gigante_04");
  AddExit("nordeste",CAOSHAB"apos_sur_00");
  AddExit("norte",CAOSHAB"gigante_02");
  AddExit("noroeste",CAOSHAB"gigante_01");
  AddExit("sur",CAOSHAB"camaras_00");
}
