/***
Fichero: celda3.c
Autor: kastwey@simauria
Descripci�n: Celda del s�tano de celdas del puesto de guardias de Siempreunidos.
Creaci�n: 06/12/2004
***/

#include "path.h"

inherit HAB_PUESTO("puesto_guardias/celdas/celdas_base");

create()
{
    ::create();
    AddExit("sur", HAB_PUESTO("puesto_guardias/celdas/pasillo3"));
}
