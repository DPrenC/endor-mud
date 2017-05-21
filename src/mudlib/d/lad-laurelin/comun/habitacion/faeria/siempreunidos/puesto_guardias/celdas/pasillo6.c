/***
Fichero: pasillo6.c
Autor: kastwey@simauria
Descripción: Pasillo 6 del sótano del puesto de guardia de Siempreunidos.
Creación: 06/12/2004
***/

#include "path.h"

inherit HAB_PUESTO("puesto_guardias/celdas/pasillos_base");

create()
{
    ::create();
    SetIntLong(W("Te encuentras al final del pasillo de las celdas.\n"
    "Al norte puedes ver la última de las seis, mientras que al este continúa el pasillo.\n"
    "Al igual que en el resto de la sala, aquí sigue existiendo musgo por todos lados.\n"));
    AddExit("este", HAB_PUESTO("puesto_guardias/celdas/pasillo5"));
    AddExit("norte", HAB_PUESTO("puesto_guardias/celdas/celda6"));
}
