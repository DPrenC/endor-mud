/****************************************************************************
Fichero: tunica_guildmaster.c
Autor: Kastwey
Fecha: 29/03/2006
Descripci�n: La t�nica de la gran kisala
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
    SetShort("una t�nica");
    SetLong("Es una t�nica de color rosa p�lido, que cubre medio tronco, y llega "
            "hasta mitad de las piernas. En el pecho, observas un s�mbolo consistente "
            "en una K y una S entrelazadas.\n");
    AddId(({"tunica", "t�nica"}));
    SetWeight(450);
}

