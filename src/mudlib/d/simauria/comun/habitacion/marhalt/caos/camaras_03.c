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

  SetIntShort("una c�mara peque�a");
  SetIntLong("Te encuentras dentro de una c�mara no muy grande. No hay nada "
    "destacable aqui.\n");
  AddExit("sur",CAOSHAB"camaras_02");
}
