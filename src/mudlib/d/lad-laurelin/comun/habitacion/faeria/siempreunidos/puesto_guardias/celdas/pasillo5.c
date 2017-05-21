/***
Fichero: pasillo5.c
Autor: kastwey@simauria
Descripción: Pasillo 5 del sótano del puesto de guardia de Siempreunidos.
Creación: 06/12/2004
***/

#include "path.h"

inherit HAB_PUESTO("puesto_guardias/celdas/pasillos_base");

create()
{
    ::create();
    AddExit("norte", HAB_PUESTO("puesto_guardias/celdas/celda5"));
    AddExit("este", HAB_PUESTO("puesto_guardias/celdas/pasillo4"));
    AddExit("oeste", HAB_PUESTO("puesto_guardias/celdas/pasillo6"));
}
