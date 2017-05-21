/****************************************************************************
Fichero: murallas_06.c
Autor: Riberales
Creación: 7/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("norte");
    SetDirec2("sudeste");

    ::create();



    AddExit("norte",HAB_MURALLAS_ANNUFAM("murallas_07"));
    AddExit("sudeste",HAB_MURALLAS_ANNUFAM("murallas_05"));
    AddItem(PNJ_CIUDAD_ANNUFAM("murallas/arquero"),REFRESH_DESTRUCT,1);

}
