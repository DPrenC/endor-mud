/****************************************************************************
Fichero: murallas_10.c
Autor: Riberales
Creación: 7/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("norte");
    SetDirec2("sur");

    ::create();



    AddExit("norte",HAB_MURALLAS_ANNUFAM("murallas_11"));
    AddExit("sur",HAB_MURALLAS_ANNUFAM("murallas_09"));
    AddItem(PNJ_CIUDAD_ANNUFAM("murallas/vigia"),REFRESH_DESTRUCT,1);
}
