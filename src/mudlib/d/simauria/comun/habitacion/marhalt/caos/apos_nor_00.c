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

  SetIntShort("los aposentos");
  SetIntLong("La habitaci�n tiene diversas tallas, adornos y dibujos "
    "finamente trabajados, muchos de ellos son sangrientos y en cierto modo "
    "hasta repulsivos. La habitaci�n s�lo tiene un catre y dos armarios, por "
    "lo que se puede presuponer que esta es la habitaci�n del jefe de los "
    "habitantes de las cavernas.\n");
  AddDetail(({"catre"}),
    "Se encuentra al nordeste.\n");
  AddDetail(({"armario","armarios"}),
    "Est�n al norte.\n");
  AddExit("oeste",CAOSHAB"gig_apos_02");
  AddExit("norte",CAOSHAB"apos_nor_01");
  AddExit("nordeste",CAOSHAB"apos_nor_02");
  AddItem(CAOSPNJ"girlak",REFRESH_DESTRUCT);
  AddItem(CAOSPNJ"murda",REFRESH_DESTRUCT);
}
