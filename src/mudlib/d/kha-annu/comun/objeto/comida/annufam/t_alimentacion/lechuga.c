/**************************************************************************
Fichero: lechuga.c
Autor: Riberales.
Creación: 09-09-05
Descripción: Una lechuga, de mi huerto.
[t] 22/02/2009: Uso la versión con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Una lechuga");
    SetLong("Una lechuga muy fresca y muy verde. Seguro que está "
            "buenísima.\n");
    SetIds(({"lechuga"}));
    SetWeight(44);
    SetValue(30);

    SetFoodMsgs(({"Empiezas a deshojar la lechuga y a comértela.\n", "@@Pl_Name@@ se come una lechuga.\n"}));
//    SetFoodMsgs("Empiezas a deshojar la lechuga y a comértela.\n");
//    SetFoodMsg2("se come una lechuga.\n");
    SetFoodStuff(18);
    SetFoodHeal(6);
}
