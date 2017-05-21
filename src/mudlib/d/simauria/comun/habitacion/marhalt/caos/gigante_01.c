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

  SetIntShort("el norte de la cámara gigante");
  SetIntLong("Estás en la parte noroeste de una sala ovalada muy grande."
    " Las paredes son marrones y el techo amarillo. El suelo esta lleno de "
    "piedrecitas.\n");
  AddExit("sur",CAOSHAB"gigante_00");
  AddExit("sudeste",CAOSHAB"gigante_03");
  AddExit("este",CAOSHAB"gigante_02");
  AddExit("norte",CAOSHAB"gig_apos_00");
}
