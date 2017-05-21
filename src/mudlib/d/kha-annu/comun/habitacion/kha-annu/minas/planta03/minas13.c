/**************************************************************************
fichero: minas13.c
Autor: Riberales
Creaci�n: 26/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("un cruce en las minas");
    SetIntLong("Has aparecido en un cruce de t�neles en las minas de "
               "Kha-annu. Te parece observar que los caminos m�s amplios son "
               "los del nordeste y noroeste, mientras que divisas uno algo "
               "m�s estrecho al sudeste.\n");

    DetalleParedes();
    AddItem(OTRO_MINAS("carretilla_vacia"));
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT);


    AddExit("nordeste",HAB_TERCERA_MINAS("minas14"));
    AddExit("sudeste",HAB_TERCERA_MINAS("minas15"));
    AddExit("noroeste",HAB_TERCERA_MINAS("minas12"));
    AddGuardia();
}

