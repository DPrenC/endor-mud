/****************************************************************************
Fichero: murallas_01.c
Autor: Riberales
Creación: 7/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("este");
    SetDirec2("oeste");

    ::create();



    AddExit("oeste",HAB_MURALLAS_ANNUFAM("murallas_02"));
    AddExit("este",HAB_MURALLAS_ANNUFAM("murallas_00"));
    AddItem(PNJ_CIUDAD_ANNUFAM("murallas/vigia"),REFRESH_DESTRUCT,1);
    AddItem(PNJ_CIUDAD_ANNUFAM("murallas/patrullero"),REFRESH_DESTRUCT,1);
}
