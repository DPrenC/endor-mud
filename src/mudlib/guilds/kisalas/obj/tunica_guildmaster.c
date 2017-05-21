/****************************************************************************
Fichero: tunica_guildmaster.c
Autor: Kastwey
Fecha: 29/03/2006
Descripción: La túnica de la gran kisala
****************************************************************************/


#include <properties.h>
#include <size.h>
#include <materials.h>
#include <combat.h>

inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_CLOAK, 1, P_SIZE_MEDIUM, M_TELA);
    SetShort("una túnica");
    SetLong("Es una túnica de color rosa pálido, que cubre medio tronco, y llega "
            "hasta mitad de las piernas. En el pecho, observas un símbolo consistente "
            "en una K y una S entrelazadas.\n");
    AddId(({"tunica", "túnica"}));
    SetWeight(450);
}

