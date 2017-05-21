/**************************************************************************
Fichero: pepino.c
Autor: Riberales.
Creaci�n: 27-09-05
Descripci�n: Un se�or pepino.
[t] 22/02/2009: Uso la versi�n con array de SetFoodMsgs en lugar de SetFoodMsg2.
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
