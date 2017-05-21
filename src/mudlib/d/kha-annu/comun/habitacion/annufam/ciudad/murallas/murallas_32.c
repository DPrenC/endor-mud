/****************************************************************************
Fichero: murallas_32.c
Autor: Riberales
Creación: 8/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("oeste");
    SetDirec2("nordeste");

    ::create();



    AddExit("oeste",HAB_MURALLAS_ANNUFAM("murallas_33"));
    AddExit("nordeste",HAB_MURALLAS_ANNUFAM("murallas_31"));

    AddItem(PNJ_CIUDAD_ANNUFAM("murallas/arquero"),REFRESH_DESTRUCT,1);
}
