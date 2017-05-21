/**************************************************************************
Fichero: pepino.c
Autor: Riberales.
Creación: 27-09-05
Descripción: Un señor pepino.
[t] 22/02/2009: Uso la versión con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Un pepino");
    SetLong("Es un verde, largo y gordo pepino.\n");
    SetIds(({"pepino"}));
    SetWeight(62);
    SetValue(17);

    SetFoodMsgs(({"Te comes un pepino.\n", "@@Pl_Name@@ se come un pepino.\n"}));
//    SetFoodMsgs("Te comes un pepino.\n");
//    SetFoodMsg2("se come un pepino.\n");

    SetFoodStuff(8);
    SetFoodHeal(2);
}
