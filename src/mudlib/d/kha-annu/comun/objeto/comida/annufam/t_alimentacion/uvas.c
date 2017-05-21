/**************************************************************************
Fichero: uvas.c
Autor: Riberales.
Creación: 27-09-05
Descripción: Un racimo de uvas.
[t] 22/02/2009: Uso la versión con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Un racimo de uvas");
    SetLong("Es un racimo de deliciosas uvas verdes.");
    SetIds(({"uvas","racimo","racimo de uvas"}));
    SetWeight(55);
    SetValue(30);

    SetFoodMsgs(({"Vas comiéndote las uvas una a una.\n", "@@Pl_Name@@ se come un racimo de uvas.\n"}));
//    SetFoodMsgs("Vas comiéndote las uvas una a una.\n");
//    SetFoodMsg2("se come un racimo de uvas.\n");
    SetFoodStuff(13);
    SetFoodHeal(5);
}
