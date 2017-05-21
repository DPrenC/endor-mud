/**************************************************************************
fichero: minas17.c
Autor: Riberales
Creación: 27/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("una galería");
    SetIntLong("Te encuentras en una galería de las minas enanas. La "
               "monotonía se adueña del lugar, no sin antes dejar sitio a la "
               "humedad y al frío. El túnel sigue de "
               "suroeste a nordeste, donde divisas un aumento de "
               "luminosidad.\n");

    DetalleParedes();

    AddItem(OTRO_MINAS("carretilla_vacia"));

    AddExit("suroeste",HAB_TERCERA_MINAS("minas16"));
    AddExit("nordeste",HAB_TERCERA_MINAS("minas18"));
    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT);
}
