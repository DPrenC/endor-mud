/***
Fichero: pasillo2.c
Autor: kastwey@simauria
Descripci�n: Pasillo 2 del s�tano del puesto de guardia de Siempreunidos.
Creaci�n: 06/12/2004
***/

#include "path.h"

inherit HAB_PUESTO("puesto_guardias/celdas/pasillos_base");

create()
{
    ::create();
    AddExit("oeste", HAB_PUESTO("puesto_guardias/celdas/pasillo3"));
    AddExit("este", HAB_PUESTO("puesto_guardias/celdas/pasillo1"));
    AddExit("norte", HAB_PUESTO("puesto_guardias/celdas/celda2"));
}
