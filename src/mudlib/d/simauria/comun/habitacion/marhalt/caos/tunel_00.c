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
    "son de color amarillento, pero salvo eso no hay nada de inter�s.\n");
  SetIntNoise("Escuchas el ruido de algo muy grande caminando en alg�n t�nel "
    "muy cercano a este que debe circular por arriba o por abajo.\n");
  AddExit("suroeste",CAOSHAB"arroyo_04");
  AddExit("norte",CAOSHAB"tunel_01");
}
