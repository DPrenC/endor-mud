/****************************************************************************
Fichero: murallas_15.c
Autor: Riberales
Creación: 7/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("nordeste");
    SetDirec2("suroeste");

    ::create();



    AddExit("nordeste",HAB_MURALLAS_ANNUFAM("murallas_16"));
    AddExit("suroeste",HAB_MURALLAS_ANNUFAM("murallas_14"));
    AddItem(PNJ_CIUDAD_ANNUFAM("murallas/arquero"),REFRESH_DESTRUCT,1);
}
