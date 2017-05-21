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

  SetIntShort("el oeste de los ba�os");
  SetIntLong("Te encuentras en la parte oeste de los ba�os. Aqui se "
    "encuentran dos estatuas.\n");
  SetIntSmell("Hueles el f�tido olor del agua cenagosa.\n");
  AddDetail(({"estatuas","estatua"}),
    "Las dos estatuas estan muy estropeadas, s�lo les quedan intactos "
    "los pies y los tobillos, el resto del cuerpo est� hecho a�icos por "
    "el suelo.\n");
  AddExit("este",CAOSHAB"banyos_00");
}
