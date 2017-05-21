/****************************************************************************
Fichero: guanteletes_poder.c
Autor: Aulë
Fecha: 22/03/2013
Descripción: guanteletes para Tulkas.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_GUANTES, 5, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("los guanteletes del poder");
    SetLong("Se trata de un pesado par de guanteletes de combate.\n"
    "Todas y cada una de las múltiples piezas de metal dorado que los conforman "
    "están maravillosamente cinceladas y moldeadas a semejanza de las manos que "
    "guarnecen.\n"
    "Un suave brillo dorado emana de su pulida superficie denotando el gran poder que "
    "albergan.\n"
    "Este poderoso objeto fue forjado por Aulë, el vala Herrero, para Tulkas, el "
    "campeón de los Valar, que no usa otras armas que sus manos,y acrecentan su ya "
    "considerable fuerza.\n");
        SetIds(({ "guanteletes", "armadura","guanteletes_tulkas"}));
    SetAds(({"mithril","metalicos", "pesados", "de", "del", "poder"}));
      //SetAPperQP(0);
    SetWeight(2300);
    Set(P_GENDER, GENDER_MALE);
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Sería un sacrilegio tirar un objeto sagrado como este .\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "estos poderosos guanteletes.\n");
}
