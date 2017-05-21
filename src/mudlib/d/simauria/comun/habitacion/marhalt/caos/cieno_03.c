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
    "son de color verde jaspeado, pero salvo eso no hay nada de inter�s.\n");
  SetIntSmell("Hueles como a podrido desde la parte sur.\n");
  SetIntNoise("Escuchas el rumor de un r�o por el norte.\n");
  AddExit("norte",CAOSHAB"musgosa_00");
  AddExit("sur",CAOSHAB"cieno_02");
}
