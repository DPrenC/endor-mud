/**************************************************************************
fichero: minas14.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("una encrucijada de galer�as");
    SetIntLong("Has arribado a un punto de la galer�a donde se junta con "
               "varias formando un complejo cruce de t�neles y galer�as. "
               "Observas unas antorchas que te permiten advertir las "
               "m�ltiples salidas, hacia el norte, el nordeste, el sudeste y "
               "el suroeste.\n");

    DetalleParedes();
    DetalleAntorchas();

    AddExit("norte",HAB_SEGUNDA_MINAS("minas13"));
    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas15"));
    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas16"));
    AddExit("nordeste",HAB_SEGUNDA_MINAS("minas22"));
    AddItem(OTRO_MINAS("carretilla_vacia"),REFRESH_DESTRUCT,random(2));
    AddItem(PNJ_MINAS("minero_segunda"),REFRESH_DESTRUCT);
    AddGuardia();
}

