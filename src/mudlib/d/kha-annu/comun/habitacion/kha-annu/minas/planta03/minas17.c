/**************************************************************************
fichero: minas17.c
Autor: Riberales
Creaci�n: 27/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("una galer�a");
    SetIntLong("Te encuentras en una galer�a de las minas enanas. La "
               "monoton�a se adue�a del lugar, no sin antes dejar sitio a la "
               "humedad y al fr�o. El t�nel sigue de "
               "suroeste a nordeste, donde divisas un aumento de "
               "luminosidad.\n");

    DetalleParedes();

    AddItem(OTRO_MINAS("carretilla_vacia"));

    AddExit("suroeste",HAB_TERCERA_MINAS("minas16"));
    AddExit("nordeste",HAB_TERCERA_MINAS("minas18"));
    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT);
}
