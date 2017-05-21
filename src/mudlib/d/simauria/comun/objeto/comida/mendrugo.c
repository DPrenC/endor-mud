/****************************************************************************
Fichero: mendrugo.c
Autor: Ratwor
Fecha: 09/12/2007
Descripción: un mendrugo de pan.
****************************************************************************/

#include <properties.h>
inherit FOOD;

create() {

    ::create();

    SetShort("un mendrugo de pan");
    SetLong("Es un trozo de pan bastante duro.\n");
    AddId(({"pan", "mendrugo", "mendrugo de pan", "pan duro"}));
    SetFoodKind("food");
    SetFoodMsgs("Buf que duro está, como para partirse los piños.\n");
    SetFoodStuff(10);
    SetFoodHeal(5);
    SetWeight(150);
    SetValue(10);
    SetSize(P_SIZE_SMALL);
}

