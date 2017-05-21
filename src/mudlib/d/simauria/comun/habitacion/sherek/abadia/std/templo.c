/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/std/templo.c
Autor: Yalin
Fecha: 04/06/2009 00:27
Descripción: Base para las rooms del templo de la abadía.
****************************************************************************/

#include "path.h"
inherit SHERAB("std/int");

create()
{
    ::create();
    SetIntShort("el templo de la diosa Sherek");
    SetIntLong("Estás en zona de obras... Todo está en construcción, apenas terminada la obra de "
        "piedra.\nSólo ves piedra plana por paredes y techo. Aún deben venir los pulidores, los "
        "pintores, los decoradores, los tallistas y grabadores... ¡Y según se cuenta, hay mucho "
        "trabajo pendiente por todos los dominios! Tal vez habría que traer algunos..., ciudadanos "
        "de la aldea de Sloch...\n");
}
        