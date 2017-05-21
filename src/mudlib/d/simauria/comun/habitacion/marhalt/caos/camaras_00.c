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
  SetIntLong("Te encuentras en el pasillo entre dos estancias. Las paredes "
    "son de color verde jaspeado, pero salvo eso no hay nada de interés.\n"
    "Las únicas salidas están hacia una gran cámara al norte y noroeste, "
    "y continuando el pasillo hacia el sudeste.\n");
  AddExit("norte",CAOSHAB"gigante_03");
  AddExit("noroeste",CAOSHAB"gigante_00");
  AddExit("sudeste",CAOSHAB"camaras_01");
}
