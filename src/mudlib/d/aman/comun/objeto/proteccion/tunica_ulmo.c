/*
Fichero: tunica_ulmo.c
Autor: Aul�
Fecha: 21/07/2013
Descripci�n: la t�nica de Ulmo, Se�or de las Aguas.
Inventada por m�, solo se la ve un poco en uno de los relatos de Tolkien.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_TUNICA, 1, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("t�nnnnnnnica de las mareas");
    SetLong(
    "Esta amplia y larga t�nica es el atav�o principal de Ulmo, Se�or de las Aguas.\n"
    "El pesado tejido tiene el color verde oscuro de las grandes olas que rugen bajo el "
    "poder de las grandes tempestades marinas y el movimiento de sus pliegues recuerda el "
    "del oleaje.\n");
    SetIds(({"tunica", "t�nica", "oleaje","tunica_ulmo"}));
      SetValue(3000000);
  SetMagic(1);

 SetNoDrop("Ser�a un sacrilegio tirar un objeto sagrado como este.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "la t�nica del Se�or de las Aguas.\n");
}