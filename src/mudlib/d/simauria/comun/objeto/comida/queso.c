/****************************************************************************
Fichero: queso.c
Autor: Ratwor
Fecha: 09/12/2007
Descripción: un mendrugo de pan.
****************************************************************************/

#include <properties.h>
inherit FOOD;

create() {

    ::create();

    SetShort("un trozo de queso");
    SetLong("Es un trozo de queso mohoso, no tiene buen aspecto.\n");
    SetFoodKind("food");
    AddId(({"queso", "trozo de queso", "queso mohoso"}));
    SetFoodMsgs("Tiene un raro sabor rancio.\n");
    SetFoodStuff(8);
    SetFoodHeal(5);
    SetWeight(150);
    SetValue(20);
    SetSize(P_SIZE_SMALL);
}

