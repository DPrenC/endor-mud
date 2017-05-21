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
  SetIntLong("Te encuentras en el pasillo entre dos estancias. Las paredes "
    "son de color verde jaspeado, pero salvo eso no hay nada de inter�s.\n"
    "Las �nicas salidas est�n hacia una gran c�mara al norte y noroeste, "
    "y continuando el pasillo hacia el sudeste.\n");
  AddExit("norte",CAOSHAB"gigante_03");
  AddExit("noroeste",CAOSHAB"gigante_00");
  AddExit("sudeste",CAOSHAB"camaras_01");
}
