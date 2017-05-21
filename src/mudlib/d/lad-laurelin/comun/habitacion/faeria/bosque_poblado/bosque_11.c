/***
Fichero: bosque_11.c
Autor: kastwey@simauria
Descripci�n: Bosque de Siempreunidos.
Entrada al bosque m�gico de Faeria.
Creaci�n: 18/12/2004
***/

#include "path.h"

inherit HAB_BOSQUE_PUESTO("bosque_base");

create()
{
    ::create();
    SetIntLong(::QueryIntLong() +
    W("La configuraci�n en esta parte del bosque es algo particular.\n"
    "Al norte, un gigantesco �rbol, m�s grueso incluso que el resto de los �rboles que has visto por este bosque, te corta el paso, mientras que al este y al oeste, la vegetaci�n se vuelve tan espesa que caminar en esas direcciones te resultar�a totalmente impracticable.\n"));
    RemoveDetail("arbol");
    SetOficina(HAB_BOSQUE_PUESTO("bosque_09"));
    AddItem(OBJETO "otro/faeria/arbol_entrada",REFRESH_DESTRUCT,1);
    AddExit("sur","bosque_09");
    AddExit("sudeste","bosque_10");
    AddExit("suroeste","bosque_08");
}
