/***
Fichero: bosque_03.c
Autor: kastwey@simauria
Descripción: bosque de siempreunidos.
Creación: 18/12/2004
***/

#include "path.h"

inherit HAB_BOSQUE_PUESTO("bosque_base");

create()
{
    ::create();
    SetIntLong(::QueryIntLong() +
    "Aquí el bosque se extiende en todas direcciones. Hacia el norte te adentras aún más en este bosque, mientras que al sur está la entrada que comunica con el pueblo.\n");
    SetOficina(HAB_BOSQUE_PUESTO("bosque_01"));
    AddExit("oeste","bosque_02");
    AddExit("noroeste","bosque_05");
    AddExit("este","bosque_04");
    AddExit("nordeste","bosque_07");
    AddExit("sur","bosque_01");
    AddExit("norte","bosque_06");
}