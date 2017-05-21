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

  SetIntShort("la zona norte de los aposentos");
  SetIntLong("La habitaci�n tiene diversas tallas, adornos y dibujos "
    "finamente trabajados, muchos de ellos son sangrientos y en cierto modo "
    "hasta repulsivos.\n"
    "La habitaci�n s�lo tiene un catre, por lo que se puede presuponer que "
    "esta es posiblemente la habitacion del jefe de los habitantes de las "
    "cavernas.\n"
    "El catre se encuentra al este, y a tu lado hay un par de armarios.\n");
  AddExit("sur",CAOSHAB"apos_nor_00");
  AddExit("este",CAOSHAB"apos_nor_02");
}
