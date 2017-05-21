/*
Fichero: tunica_ulmo.c
Autor: Aulë
Fecha: 21/07/2013
Descripción: la túnica de Ulmo, Señor de las Aguas.
Inventada por mí, solo se la ve un poco en uno de los relatos de Tolkien.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_TUNICA, 1, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("túnnnnnnnica de las mareas");
    SetLong(
    "Esta amplia y larga túnica es el atavío principal de Ulmo, Señor de las Aguas.\n"
    "El pesado tejido tiene el color verde oscuro de las grandes olas que rugen bajo el "
    "poder de las grandes tempestades marinas y el movimiento de sus pliegues recuerda el "
    "del oleaje.\n");
    SetIds(({"tunica", "túnica", "oleaje","tunica_ulmo"}));
      SetValue(3000000);
  SetMagic(1);

 SetNoDrop("Sería un sacrilegio tirar un objeto sagrado como este.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "la túnica del Señor de las Aguas.\n");
}