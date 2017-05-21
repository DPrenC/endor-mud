/**************************************************************************
fichero: minas17.c
Autor: Riberales
Creación: 11/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("mitad de una galería");
    SetIntLong("Estás internado en las minas de Kha-annu, en el segundo "
               "nivel de las susodichas. La roca de esta zona está tan "
               "sumamente picada que sería casi un milagro encontrar un trozo "
               "de hierro siquiera. La galería sigue de este a oeste.\n");

    DetalleParedes();
    AddExit("este",HAB_SEGUNDA_MINAS("minas18"));
    AddExit("oeste",HAB_SEGUNDA_MINAS("minas16"));
    AddGuardia();
}

