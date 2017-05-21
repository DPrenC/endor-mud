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
  SetIntLong("Te encuentras la entrada de una forja. Las paredes son de "
    "tono rojizo, pero salvo eso no hay nada de inter�s.\n"
    "El t�nel va en direcci�n sur, y la zona nordeste es una amplia forja.\n");
  AddExit("sur",CAOSHAB"apos_nor_02");
  AddExit("norte",CAOSHAB"forja_01");
  AddExit("este",CAOSHAB"forja_03");
  AddExit("nordeste",CAOSHAB"forja_02");
}
