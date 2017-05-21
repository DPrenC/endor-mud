/* Fichero: capa_mandos.c
Autor: aulë
Fecha: 02/09/2014
Descripción: vestimenta de Mandos
*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_MANTO, 1, P_SIZE_LARGE, M_ESPECIAL);
SetShort("una capa gris con la capucha echada hacia atrás");
SetLong(
"Es una larga y amplia capa de fino tejido gris, exento de todo adorno. Posee una gran "
"capucha que cuelga hacia atrás. El tejido que la constituye parece tenue y volátil, "
"presintiéndose que alberga algún poder oculto.\n");
SetIds(({"manto", "capa", "capa de mandos", "ropa"}));
SetAds(({"de","tela", "gris", "tejido"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_SINGULAR);
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Sería un sacrilegio tirar un objeto sagrado como este.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "la capa del juez de los Valar.\n");
}