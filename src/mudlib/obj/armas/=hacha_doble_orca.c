// Libreria de Armas de Simauria.
// Elaborada por [Gw]Greywolf, usando objetos creados por
// Woo, Angor, Nemesis, Kodex, Izet, Kintups y todos aquellos
// que han hecho algun arma en el mud. Gracias a ellos por
// su esfuerzo. Tambien son añadidas varias armas nuevas.
// Arma: Hacha Doble Orca
// Fichero: hacha_doble_orca.c
// Fecha de creación: 22/11/04 [Gw]

#include <mud.h>
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_HACHA,10,P_SIZE_MEDIUM,M_HIERRO);
 SetWeight(12500);
 SetShort("un hacha doble orca");
 SetIds(({"hacha","hacha doble","hacha orca","hacha doble orca"}));

 SetNumberHands(2);
 SetLong("\
Es un hacha de combate forjada por los mejores herreros orcos. Sus aspecto\n\
es un poco tosco pero es muy útil. Es de doble hoja metalica y bien afilada.\n");
}



