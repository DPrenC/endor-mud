/**************************************************************************
fichero: minas17.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("mitad de una galer�a");
    SetIntLong("Est�s internado en las minas de Kha-annu, en el segundo "
               "nivel de las susodichas. La roca de esta zona est� tan "
               "sumamente picada que ser�a casi un milagro encontrar un trozo "
               "de hierro siquiera. La galer�a sigue de este a oeste.\n");

    DetalleParedes();
    AddExit("este",HAB_SEGUNDA_MINAS("minas18"));
    AddExit("oeste",HAB_SEGUNDA_MINAS("minas16"));
    AddGuardia();
}

