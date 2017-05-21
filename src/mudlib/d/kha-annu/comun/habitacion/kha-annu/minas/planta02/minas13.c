/**************************************************************************
fichero: minas13.c
Autor: Riberales
Creación: 11/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un túnel en las minas de Kha-annu");
    SetIntLong("Te encuentras en uno de los múltiples túneles de las minas "
               "enanas. Todo sigue siendo igual de monótono: Roca, roca, y "
               "roca. Al oeste te parece ver luz en lo que piensas que es un "
               "cruce, mientras que esta galería sigue hacia el sur.\n");

    DetalleParedes();

    AddExit("oeste",HAB_SEGUNDA_MINAS("minas12"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas14"));
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
    AddGuardia();
}

