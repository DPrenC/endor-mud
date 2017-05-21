/**************************************************************************
fichero: minas18.c
Autor: Riberales
Creaci�n: 31/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("un cruce de t�neles");
    SetIntLong("Has arribado a otro de los innumerables cruces de galer�as y "
               "t�neles de las minas de Kha-annu. Una antorcha en la pared "
               "oeste te permite divisar las salidas, y parece que las que van"
               " al norte y al sudeste son las m�s anchas, siendo el del "
               "suroeste un t�nel bastante estrecho.\n");

    DetalleParedes();
    DetalleAntorchas();
    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT,random(2));


    AddExit("norte",HAB_PRIMERA_MINAS("minas19"));
    AddExit("sudeste",HAB_PRIMERA_MINAS("minas17"));
    AddExit("suroeste",HAB_PRIMERA_MINAS("minas31"));

    AddItem(PNJ_MINAS("minero_primera"),REFRESH_DESTRUCT);
    AddGuardia();
}

