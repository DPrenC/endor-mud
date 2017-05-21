/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/std/frente.c
Autor: Yalin
Fecha: 15/05/2009 11:27
Descripci�n: Base para las rooms del bloque de entrada de la abad�a.
****************************************************************************/

#include "path.h"
inherit SHERAB("std/int");

create()
{
    ::create();
    SetIntShort("el pasillo de entrada");
    SetIntLong("Est�s en zona de obras... Todo est� en construcci�n, apenas terminada la obra de "
        "piedra.\nS�lo ves piedra plana por paredes y techo. A�n deben venir los pulidores, los "
        "pintores, los decoradores, los tallistas y grabadores... �Y seg�n se cuenta, hay mucho "
        "trabajo pendiente por todos los dominios! Tal vez habr�a que traer algunos..., ciudadanos "
        "de la aldea de Sloch...\n");
}
        