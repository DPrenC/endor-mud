/****************************************************************************
Fichero: murallas_05.c
Autor: Riberales
Creación: 7/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("noroeste");
    SetDirec2("sudeste");

    ::create();



    AddExit("noroeste",HAB_MURALLAS_ANNUFAM("murallas_06"));
    AddExit("sudeste",HAB_MURALLAS_ANNUFAM("murallas_04"));

}
