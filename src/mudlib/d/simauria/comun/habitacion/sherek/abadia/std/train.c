/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/std/train.c
Autor: Yalin
Fecha: 08/06/2009 00:27
Descripci�n: Base para las rooms del �rea de entrenamiento de la abad�a.
****************************************************************************/

#include "path.h"
inherit SHERAB("std/int");

create()
{
    ::create();
    SetIntShort("el �rea de entrenamiento");
    SetIntLong("Est�s en zona de obras... Todo est� en construcci�n, apenas terminada la obra de "
        "piedra.\nS�lo ves piedra plana por paredes y techo. A�n deben venir los pulidores, los "
        "pintores, los decoradores, los tallistas y grabadores... �Y seg�n se cuenta, hay mucho "
        "trabajo pendiente por todos los dominios! Tal vez habr�a que traer algunos..., ciudadanos "
        "de la aldea de Sloch...\nEsto parece ser la zona donde entrenan los cuerpos militares.\n");
}
        