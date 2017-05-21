/**************************************************************************
Fichero: jabali.c
Autor: Riberales.
Creación: 27-09-05
Descripción: Una chuleta de jabalí.
[t] 22/02/2009: Uso la versión con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Una chuleta de jabalí");
    SetLong("Es una chuleta de jabalí adobada, con muy buena pinta.");
    SetIds(({"chuleta","chuleta de jabalí","chuleta de jabali"}));
    SetWeight(220);
    SetValue(110);

    SetFoodMsgs(({"Te comes la chuleta de jabalí. ¡Estaba deliciosa!\n", "@@Pl_Name@@ se come una chuleta de jabalí.\n"}));
//    SetFoodMsgs("TE comes la chuleta de jabaí. ¡Estaba deliciosa!\n");
//    SetFoodMsg2("se come una chuleta de jabalí.\n");
    SetFoodStuff(19);
    SetFoodHeal(9);
}
