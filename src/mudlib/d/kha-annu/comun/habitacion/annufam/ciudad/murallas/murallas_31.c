/****************************************************************************
Fichero: murallas_31.c
Autor: Riberales
Creación: 8/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("suroeste");
    SetDirec2("nordeste");

    ::create();



    AddExit("suroeste",HAB_MURALLAS_ANNUFAM("murallas_32"));
    AddExit("nordeste",HAB_MURALLAS_ANNUFAM("murallas_30"));
}
