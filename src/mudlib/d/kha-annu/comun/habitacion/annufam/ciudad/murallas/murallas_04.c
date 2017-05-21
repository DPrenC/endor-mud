/****************************************************************************
Fichero: murallas_04.c
Autor: Riberales
Creación: 7/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("noroeste");
    SetDirec2("este");

    ::create();



    AddExit("noroeste",HAB_MURALLAS_ANNUFAM("murallas_05"));
    AddExit("este",HAB_MURALLAS_ANNUFAM("murallas_03"));
    AddItem(PNJ_CIUDAD_ANNUFAM("murallas/arquero"),REFRESH_DESTRUCT,1);

}
