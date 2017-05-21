/****************************************************************************
Fichero: murallas_23.c
Autor: Riberales
Creación: 8/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("sur");
    SetDirec2("noroeste");

    ::create();



    AddExit("sur",HAB_MURALLAS_ANNUFAM("murallas_24"));
    AddExit("noroeste",HAB_MURALLAS_ANNUFAM("murallas_22"));
    AddItem(PNJ_CIUDAD_ANNUFAM("murallas/arquero"),REFRESH_DESTRUCT);

}
