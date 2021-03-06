/****************************************************************************
Fichero: bregas_noble.c
Autor: Ratwor
Fecha: 28/11/2007
Descripci�n: parte del equipo del noble del castillo.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_GREBAS, 3, P_SIZE_GENERIC, M_ACERO);
    SetShort("unas grebas de acero");
    SetLong("Las grebas est�n formadas por tres piezas met�licas unidas con hebillas y "
    "tiras de cuero que protegen la pierna de la ingle al tobillo.\n"
    "No es una pieza muy com�n, solo utilizadas los caballeros y guerreros de la "
    "nobleza humana, as� como por la infanter�a pesada de algunas ciudades "
    "lo suficientemente ricas como para costearlas.\n");
    AddId(({"grebas de acero", "grebas", "acero"}));
    Set(P_GENDER, GENDER_FEMALE);
    Set(P_NUMBER, NUMBER_PLURAL);
    SetWeight(3600);
    SetValue(2000);
}
