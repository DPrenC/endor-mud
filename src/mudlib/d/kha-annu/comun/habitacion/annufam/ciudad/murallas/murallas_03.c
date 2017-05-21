/****************************************************************************
Fichero: murallas_03.c
Autor: Riberales
Creación: 7/10/2005
Descripción: Una room en la muralla de Annufam.
****************************************************************************/

#include "./path.h"


inherit HAB_MURALLAS_ANNUFAM("murallas_base");


public void create()
{
    SetDirec1("oeste");
    SetDirec2("este");

    ::create();



    AddExit("oeste",HAB_MURALLAS_ANNUFAM("murallas_04"));
    AddExit("este",HAB_MURALLAS_ANNUFAM("murallas_02"));

}
