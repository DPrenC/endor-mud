/***
Fichero: bosque_11.c
Autor: kastwey@simauria
Descripción: Bosque de Siempreunidos.
Entrada al bosque mágico de Faeria.
Creación: 18/12/2004
***/

#include "path.h"

inherit HAB_BOSQUE_PUESTO("bosque_base");

create()
{
    ::create();
    SetIntLong(::QueryIntLong() +
    W("La configuración en esta parte del bosque es algo particular.\n"
    "Al norte, un gigantesco árbol, más grueso incluso que el resto de los árboles que has visto por este bosque, te corta el paso, mientras que al este y al oeste, la vegetación se vuelve tan espesa que caminar en esas direcciones te resultaría totalmente impracticable.\n"));
    RemoveDetail("arbol");
    SetOficina(HAB_BOSQUE_PUESTO("bosque_09"));
    AddItem(OBJETO "otro/faeria/arbol_entrada",REFRESH_DESTRUCT,1);
    AddExit("sur","bosque_09");
    AddExit("sudeste","bosque_10");
    AddExit("suroeste","bosque_08");
}
