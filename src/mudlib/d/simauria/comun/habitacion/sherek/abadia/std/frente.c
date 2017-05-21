/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/std/frente.c
Autor: Yalin
Fecha: 15/05/2009 11:27
Descripción: Base para las rooms del bloque de entrada de la abadía.
****************************************************************************/

#include "path.h"
inherit SHERAB("std/int");

create()
{
    ::create();
    SetIntShort("el pasillo de entrada");
    SetIntLong("Estás en zona de obras... Todo está en construcción, apenas terminada la obra de "
        "piedra.\nSólo ves piedra plana por paredes y techo. Aún deben venir los pulidores, los "
        "pintores, los decoradores, los tallistas y grabadores... ¡Y según se cuenta, hay mucho "
        "trabajo pendiente por todos los dominios! Tal vez habría que traer algunos..., ciudadanos "
        "de la aldea de Sloch...\n");
}
        