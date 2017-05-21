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

  SetIntShort("un pozo negro");
  SetIntLong("Estás en una habitación de forma ovalada, las paredes son "
    "marrones con franjas blancas, y el suelo se encuentra completamente "
    "cubierto de una delgada capa formada por una sustancia negra.\n"
    "En la parte sur hay una gran charca de aguas negras.\n");
  AddDetail(({"charca","agua","aguas estancadas"}),
    "Cuando observas detenidamente la charca descubres que en el fondo "
    "están los esqueletos de dos hombres. Algo brilla en uno de ellos.\n");
  AddDetail(({"brillo","esqueletos","esqueleto"}),
    "Cuando miras detenidamente el brillo descubres que es una espada "
    "ancha enfundada en una vaina enjoyada.\n");
  AddExit("norte",CAOSHAB"pozo_est_01");
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
  AddItem(CAOSPNJ"ogro",REFRESH_DESTRUCT);
}
