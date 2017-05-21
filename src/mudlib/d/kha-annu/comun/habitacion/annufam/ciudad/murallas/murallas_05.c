/****************************************************************************
Fichero: murallas_05.c
Autor: Riberales
Creaci�n: 7/10/2005
Descripci�n: Una room en la muralla de Annufam.
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
