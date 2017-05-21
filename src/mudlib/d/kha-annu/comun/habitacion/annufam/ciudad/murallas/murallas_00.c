/****************************************************************************
Fichero: murallas_00.c
Autor: Riberales
Creación: 7/10/2005
Descripción: Una room en la muralla de Annufam.
[t]: La dirección abajo pasa a mirallas_02.c para alinear las murallas con la ciudad
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
    SetDirec1("oeste");
    SetDirec2("este");


    ::create();
    SetIntLong(::QueryIntLong() + W("También puedes ver las escaleras que "
               "descienden por el interior de la torre hasta las puertas de "
               "la ciudad.\n"));

    AddExit("oeste",HAB_MURALLAS_ANNUFAM("murallas_01"));
    AddExit("este",HAB_MURALLAS_ANNUFAM("murallas_33"));
//    AddExit("abajo",SF(bajar));
}


