/****************************************************************************
Fichero: murallas_30.c
Autor: Riberales
Creación: 8/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("suroeste");
    SetDirec2("norte");

    ::create();



    AddExit("suroeste",HAB_MURALLAS_ANNUFAM("murallas_31"));
    AddExit("norte",HAB_MURALLAS_ANNUFAM("murallas_29"));
    AddItem(PNJ_CIUDAD_ANNUFAM("murallas/arquero"),REFRESH_DESTRUCT,1);

}
