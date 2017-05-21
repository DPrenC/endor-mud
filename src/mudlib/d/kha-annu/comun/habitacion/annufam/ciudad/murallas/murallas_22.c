/****************************************************************************
Fichero: murallas_22.c
Autor: Riberales
Creación: 8/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("sudeste");
    SetDirec2("noroeste");

    ::create();



    AddExit("sudeste",HAB_MURALLAS_ANNUFAM("murallas_23"));
    AddExit("noroeste",HAB_MURALLAS_ANNUFAM("murallas_21"));

}
