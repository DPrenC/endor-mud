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

  SetIntShort("la parte este de la entrada");
  SetIntLong("Te encuentras en la parte este de la entrada de la caverna, "
    "justo delante de una silueta con forma de águila. Alguien ha intentado "
    "borrarla pero no ha tenido éxito.\n"
    "Hacia el oeste pueden verse unas inscripciones en la pared. La caverna "
    "continua hacia el Sudeste.\n");
  AddDetail(({"figura","silueta","aguila","silueta con forma de aguila",
    "águila","silueta con forma de águila"}),
    "Un conjunto de motas blancas que forman la silueta de un águila.\n");
  AddDetail(({"inscripciones"}),
    "Están en la parte oeste.\n");
  AddExit("oeste",CAOSHAB"entrada_02");
  AddExit("sudeste",CAOSHAB"lago_00");
}
