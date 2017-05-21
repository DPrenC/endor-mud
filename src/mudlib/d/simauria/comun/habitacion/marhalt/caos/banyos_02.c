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

  SetIntShort("el oeste de los baños");
  SetIntLong("Te encuentras en la parte oeste de los baños. Aqui se "
    "encuentran dos estatuas.\n");
  SetIntSmell("Hueles el fétido olor del agua cenagosa.\n");
  AddDetail(({"estatuas","estatua"}),
    "Las dos estatuas estan muy estropeadas, sólo les quedan intactos "
    "los pies y los tobillos, el resto del cuerpo está hecho añicos por "
    "el suelo.\n");
  AddExit("este",CAOSHAB"banyos_00");
}
