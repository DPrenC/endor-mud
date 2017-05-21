/****************************************************************************
Fichero: arena15.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("En este punto, el bosque se vuelve realmente espeso. Hacia el norte, "
               "una tupida red de vegetación te impide ir en esa dirección. "
               "Sin embargo, puedes ver un estrecho paso al noroeste que te permite "
               "avanzar hasta el límite norte de la isla. Puedes continuar cerca de la "
               "costa si vas al este o al oeste, o adentrarte más en este bosque en "
               "dirección sur.\n");


    AddExit("oeste","arena18");
    AddExit("este","arena16");
    AddExit("noroeste","arena20");
    AddExit("sur","arena13");
    AddExit("sudeste","arena14");

}


