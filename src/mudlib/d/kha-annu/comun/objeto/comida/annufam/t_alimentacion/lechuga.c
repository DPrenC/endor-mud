/**************************************************************************
Fichero: lechuga.c
Autor: Riberales.
Creaci�n: 09-09-05
Descripci�n: Una lechuga, de mi huerto.
[t] 22/02/2009: Uso la versi�n con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Una lechuga");
    SetLong("Una lechuga muy fresca y muy verde. Seguro que est� "
            "buen�sima.\n");
    SetIds(({"lechuga"}));
    SetWeight(44);
    SetValue(30);

    SetFoodMsgs(({"Empiezas a deshojar la lechuga y a com�rtela.\n", "@@Pl_Name@@ se come una lechuga.\n"}));
//    SetFoodMsgs("Empiezas a deshojar la lechuga y a com�rtela.\n");
//    SetFoodMsg2("se come una lechuga.\n");
    SetFoodStuff(18);
    SetFoodHeal(6);
}
