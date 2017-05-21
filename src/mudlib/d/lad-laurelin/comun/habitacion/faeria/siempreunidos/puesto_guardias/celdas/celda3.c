/***
Fichero: celda3.c
Autor: kastwey@simauria
Descripción: Celda del sótano de celdas del puesto de guardias de Siempreunidos.
Creación: 06/12/2004
***/

#include "path.h"

inherit HAB_PUESTO("puesto_guardias/celdas/celdas_base");

create()
{
    ::create();
    AddExit("sur", HAB_PUESTO("puesto_guardias/celdas/pasillo3"));
}
