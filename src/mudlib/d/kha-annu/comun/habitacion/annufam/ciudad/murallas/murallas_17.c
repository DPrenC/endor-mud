/****************************************************************************
Fichero: murallas_17.c
Autor: Riberales
Creaci�n: 8/10/2005
Descripci�n: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("nordeste");
    SetDirec2("suroeste");

    ::create();



    AddExit("nordeste",HAB_MURALLAS_ANNUFAM("murallas_18"));
    AddExit("suroeste",HAB_MURALLAS_ANNUFAM("murallas_16"));
}
