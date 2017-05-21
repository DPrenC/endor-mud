/***
Fichero: pasillo1.c
Autor: kastwey@simauria
Descripción: Pasillo 1 del sótano del puesto de guardia de Siempreunidos.
Creación: 06/12/2004
***/

#include "path.h"

inherit HAB_PUESTO("puesto_guardias/celdas/pasillos_base");

create()
{
    ::create();
    SetIntShort("la sala de las celdas");
    SetIntLong(W("Te encuentras en una gran sala subterránea.\n"
    "Es una estancia rectangular. A lo largo de una de las paredes, puedes ver numerosas celdas que parecen vacías.\n"
    "La humedad reinante en el lugar, ha hecho que por toda superficie visible crezca una gruesa pátina de musgo.\n"
    "Hacia el oeste transcurre el pasillo, y hacia el norte puedes ver la primera celda.\n"));
    AddExit("oeste", HAB_PUESTO("puesto_guardias/celdas/pasillo2"));
    AddExit("arriba", HAB_PUESTO("puesto_guardias/puesto_escaleras"));
    AddExit("norte", HAB_PUESTO("puesto_guardias/celdas/celda1"));
}