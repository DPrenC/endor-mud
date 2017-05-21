/****************************************************************************
Fichero: murallas_25.c
Autor: Riberales
Creación: 8/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("sur");
    SetDirec2("norte");

    ::create();



    AddExit("sur",HAB_MURALLAS_ANNUFAM("murallas_26"));
    AddExit("norte",HAB_MURALLAS_ANNUFAM("murallas_24"));


}
