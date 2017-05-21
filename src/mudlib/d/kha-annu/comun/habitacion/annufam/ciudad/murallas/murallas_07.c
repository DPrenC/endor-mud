/****************************************************************************
Fichero: murallas_07.c
Autor: Riberales
Creaci�n: 7/10/2005
Descripci�n: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("norte");
    SetDirec2("sur");

    ::create();



    AddExit("norte",HAB_MURALLAS_ANNUFAM("murallas_08"));
    AddExit("sur",HAB_MURALLAS_ANNUFAM("murallas_06"));

}
