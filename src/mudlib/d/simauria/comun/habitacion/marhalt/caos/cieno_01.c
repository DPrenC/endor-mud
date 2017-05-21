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
    "son de color amarillento, pero salvo eso no hay nada de inter�s.\n"
    "El pasillo continua al sur, y hacia el norte y nordeste se abre una "
    "estancia.\n");
  SetIntSmell("Hueles como a podrido desde la parte norte.\n");
  AddExit("norte",CAOSHAB"cieno_02");
  AddExit("nordeste",CAOSHAB"cieno_05");
  AddExit("sur",CAOSHAB"cieno_00");
}
