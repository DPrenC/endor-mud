/****************************************************************************
Fichero: murallas_18.c
Autor: Riberales
Creación: 8/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("sudeste");
    SetDirec2("suroeste");

    ::create();



    AddExit("sudeste",HAB_MURALLAS_ANNUFAM("murallas_19"));
    AddExit("suroeste",HAB_MURALLAS_ANNUFAM("murallas_17"));
    AddItem(PNJ_CIUDAD_ANNUFAM("murallas/vigia"),REFRESH_DESTRUCT);
    AddItem(PNJ_CIUDAD_ANNUFAM("murallas/patrullero"),REFRESH_DESTRUCT,1+ random(2));

}
