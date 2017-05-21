/****************************************************************************
Fichero: murallas_02.c
Autor: Riberales
Creación: 7/10/2005
Descripción: Una room en la muralla de Annufam.
[t] 27/02/2009: Centro las murallas
****************************************************************************/

#include "./path.h"
#include <moving.h>


inherit HAB_MURALLAS_ANNUFAM("murallas_base");

int bajar()
{
    write("Comienzas a descender las escaleras.\n");
    say(W(CAP(TNAME) + " se va bajando las escaleras.\n"));
    TP->move(HAB_MURALLAS_ANNUFAM("descansillo_a_murallas"),M_SILENT,"abajo");
    return 1;
}


public void create()
{
    SetDirec1("este");
    SetDirec2("oeste");

    ::create();



    AddExit("este",HAB_MURALLAS_ANNUFAM("murallas_01"));
    AddExit("oeste",HAB_MURALLAS_ANNUFAM("murallas_03"));
	AddExit("abajo",SF(bajar));

}
