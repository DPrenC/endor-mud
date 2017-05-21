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

  SetIntShort("una c�mara mediana");
  SetIntLong("Te encuentras dentro de una c�mara bastante grande, de unos "
    "doce metros cuadrados, pero con m�s de siete metros de altura. No hay "
    "nada destacable dentro de la c�mara.\n");
  AddExit("oeste",CAOSHAB"camaras_01");
  AddExit("norte",CAOSHAB"camaras_03");
}
