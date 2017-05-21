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

  SetIntShort("el norte de la c�mara gigante");
  SetIntLong("Est�s en la parte noroeste de una sala ovalada muy grande."
    " Las paredes son marrones y el techo amarillo. El suelo esta lleno de "
    "piedrecitas.\n");
  AddExit("sur",CAOSHAB"gigante_00");
  AddExit("sudeste",CAOSHAB"gigante_03");
  AddExit("este",CAOSHAB"gigante_02");
  AddExit("norte",CAOSHAB"gig_apos_00");
}
