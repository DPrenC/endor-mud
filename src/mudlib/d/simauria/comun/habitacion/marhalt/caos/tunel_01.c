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
    "son de color marr�n claro, pero salvo eso no hay nada de inter�s.\n");
  SetIntNoise("Escuchas el ruido de algo muy grande caminando en alg�n t�nel "
    "muy cercano a este y que circula por debajo, de eso no hay duda "
    "posible.\n");
  AddExit("sur",CAOSHAB"tunel_00");
  AddExit("norte",CAOSHAB"tunel_02");
}
