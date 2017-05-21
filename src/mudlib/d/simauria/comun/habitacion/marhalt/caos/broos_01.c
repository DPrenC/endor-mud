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
    "son de color marr�n, pero salvo eso no hay nada de inter�s.\n"
    "Las �nicas salidas est�n hacia una gran c�mara al suroeste y un pasillo "
    "hacia el este.\n");
  AddExit("norte",CAOSHAB"broos_00");
  AddExit("este",CAOSHAB"broos_02");
//AddExit("suroeste",CAOSHAB"pasillograntemplo-guaridadelosbroos");
}
