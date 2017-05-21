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

  SetIntShort("el este de los baños");
  SetIntLong("Te encuentras en la parte este de los baños. Aquí se "
    "encuentran dos de las estatuas.\n");
  SetIntSmell("Hueles el fétido olor del agua cenagosa.\n");
  AddDetail(({"estatuas","estatua"}),
    "Las dos estatuas están algo estropeadas.\n"
    "Una esta poco estropeada, solo le faltan la cabeza y el brazo "
    "izquierdo; la otra esta intacta hasta el pecho con los brazos "
    "tirados por el suelo.\n");
  AddExit("oeste",CAOSHAB"banyos_00");
  AddExit("este",CAOSHAB"hemisferio_00");
}
