/**************************************************************************
Fichero: jabali.c
Autor: Riberales.
Creaci�n: 27-09-05
Descripci�n: Una chuleta de jabal�.
[t] 22/02/2009: Uso la versi�n con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Una chuleta de jabal�");
    SetLong("Es una chuleta de jabal� adobada, con muy buena pinta.");
    SetIds(({"chuleta","chuleta de jabal�","chuleta de jabali"}));
    SetWeight(220);
    SetValue(110);

    SetFoodMsgs(({"Te comes la chuleta de jabal�. �Estaba deliciosa!\n", "@@Pl_Name@@ se come una chuleta de jabal�.\n"}));
//    SetFoodMsgs("TE comes la chuleta de jaba�. �Estaba deliciosa!\n");
//    SetFoodMsg2("se come una chuleta de jabal�.\n");
    SetFoodStuff(19);
    SetFoodHeal(9);
}
