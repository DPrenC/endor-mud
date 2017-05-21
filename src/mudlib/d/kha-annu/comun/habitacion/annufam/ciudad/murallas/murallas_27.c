/****************************************************************************
Fichero: murallas_26.c
Autor: Riberales
Creaci�n: 8/10/2005
Descripci�n: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("sur");
    SetDirec2("norte");

    ::create();

    AddExit("sur",HAB_MURALLAS_ANNUFAM("murallas_28"));
    AddExit("norte",HAB_MURALLAS_ANNUFAM("murallas_26"));
    AddItem(PNJ_CIUDAD_ANNUFAM("murallas/vigia"),REFRESH_DESTRUCT);
}
