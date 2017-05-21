/**************************************************************************
fichero: minas26.c
Autor: Riberales
Creaci�n: 27/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"


inherit HAB_SEGUNDA_MINAS("segunda_base");

create()
{
    ::create();

    SetIntShort("un enrevesado t�nel");
    SetIntLong("Est�s en un t�nel de las minas, un tanto m�s enrevesado "
               "que el resto si eso es posible. Aqu� hay bastantes marcas de "
               "carretilla, por lo que no ser�a raro ver a alg�n enano "
               "trabajando por las cercan�as.\n");


    DetalleParedes();

    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas27"));
    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas25"));
    AddItem(OTRO_MINAS("carretilla_vacia"));
    AddGuardia();
}


