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
    "son de color marrón, pero salvo eso no hay nada de interés.\n"
    "Las únicas salidas están hacia una gran cámara al suroeste y un pasillo "
    "hacia el este.\n");
  AddExit("norte",CAOSHAB"broos_00");
  AddExit("este",CAOSHAB"broos_02");
//AddExit("suroeste",CAOSHAB"pasillograntemplo-guaridadelosbroos");
}
