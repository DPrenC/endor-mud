/****************************************************************************
Fichero: arena15.c
Autor: Kastwey
Fecha: 19/02/2006
Descripci�n: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("En este punto, el bosque se vuelve realmente espeso. Hacia el norte, "
               "una tupida red de vegetaci�n te impide ir en esa direcci�n. "
               "Sin embargo, puedes ver un estrecho paso al noroeste que te permite "
               "avanzar hasta el l�mite norte de la isla. Puedes continuar cerca de la "
               "costa si vas al este o al oeste, o adentrarte m�s en este bosque en "
               "direcci�n sur.\n");


    AddExit("oeste","arena18");
    AddExit("este","arena16");
    AddExit("noroeste","arena20");
    AddExit("sur","arena13");
    AddExit("sudeste","arena14");

}


