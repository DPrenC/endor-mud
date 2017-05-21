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

    SetIntShort("la zona noreste de los aposentos");
    SetIntLong("La habitación tiene diversas tallas, adornos y dibujos "
    "finamente trabajados, muchos de ellos son sangrientos y en cierto modo "
    "hasta repulsivos. La habitación sólo tiene un catre, por lo que se puede "
    "presuponer que esta es posiblemente la habitación del jefe de los "
    "habitantes de las cavernas.\n"
    "El catre se encuentra a tu lado, y al oeste hay un par de armarios.\n");
    AddExit("suroeste",CAOSHAB"apos_nor_00");
    AddExit("oeste",CAOSHAB"apos_nor_01");
    AddExit("norte",CAOSHAB"forja_00");
    AddItem(CAOSPNJ"erraa",REFRESH_DESTRUCT);
    AddItem(CAOSPNJ"gerli",REFRESH_DESTRUCT);
}
