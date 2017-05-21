/***
Fichero: pasillo3.c
Autor: kastwey@simauria
Descripci�n: Pasillo 3 del s�tano del puesto de guardia de Siempreunidos.
Creaci�n: 06/12/2004
***/

#include "path.h"

inherit HAB_PUESTO("puesto_guardias/celdas/pasillos_base");

create()
{
    ::create();
    AddExit("oeste", HAB_PUESTO("puesto_guardias/celdas/pasillo4"));
    AddExit("este", HAB_PUESTO("puesto_guardias/celdas/pasillo2"));
    AddExit("norte", HAB_PUESTO("puesto_guardias/celdas/celda3"));
}
