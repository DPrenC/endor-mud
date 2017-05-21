/**************************************************************************
fichero: minas13.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un t�nel en las minas de Kha-annu");
    SetIntLong("Te encuentras en uno de los m�ltiples t�neles de las minas "
               "enanas. Todo sigue siendo igual de mon�tono: Roca, roca, y "
               "roca. Al oeste te parece ver luz en lo que piensas que es un "
               "cruce, mientras que esta galer�a sigue hacia el sur.\n");

    DetalleParedes();

    AddExit("oeste",HAB_SEGUNDA_MINAS("minas12"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas14"));
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
    AddGuardia();
}

