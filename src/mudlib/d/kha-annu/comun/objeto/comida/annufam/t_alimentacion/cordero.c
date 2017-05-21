/**************************************************************************
Fichero: cordero.c
Autor: Riberales.
Creación: 27-09-05
Descripción: Una chuleta de cordero.
[t] 22/02/2009: Uso la versión con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Una chuleta de cordero");
    SetLong("Es una deliciosa chuleta de cordero adobada.");
    SetIds(({"chuleta","chuleta de cordero"}));
    SetWeight(250);
    SetValue(130);

    SetFoodMsgs(({"Te comes la chuleta con gran voracidad.\n", "@@Pl_Name@@ se come una chuleta de cordero.\n"}));
//    SetFoodMsgs("TE comes la chuleta con gran voracidad.\n");
//    SetFoodMsg2("se come una chuleta de cordero.\n");
    SetFoodStuff(22);
    SetFoodHeal(10);
}
