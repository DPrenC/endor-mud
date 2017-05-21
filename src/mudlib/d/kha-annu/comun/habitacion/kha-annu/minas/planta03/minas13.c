/**************************************************************************
fichero: minas13.c
Autor: Riberales
Creación: 26/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("un cruce en las minas");
    SetIntLong("Has aparecido en un cruce de túneles en las minas de "
               "Kha-annu. Te parece observar que los caminos más amplios son "
               "los del nordeste y noroeste, mientras que divisas uno algo "
               "más estrecho al sudeste.\n");

    DetalleParedes();
    AddItem(OTRO_MINAS("carretilla_vacia"));
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT);


    AddExit("nordeste",HAB_TERCERA_MINAS("minas14"));
    AddExit("sudeste",HAB_TERCERA_MINAS("minas15"));
    AddExit("noroeste",HAB_TERCERA_MINAS("minas12"));
    AddGuardia();
}

