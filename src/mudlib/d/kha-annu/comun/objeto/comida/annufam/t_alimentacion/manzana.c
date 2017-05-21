/**************************************************************************
Fichero: manzana.c
Autor: Riberales.
Creación: 27-09-05
Descripción: Una manzana verde.
[t] 22/02/2009: Uso la versión con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Una manzana");
    SetLong("Es una manzana de color verde, de aspecto apetitoso.\n");
    SetIds(({"manzana","manzana verde"}));
    SetWeight(45);
    SetValue(35);
    SetFoodMsgs(({"Te comes una manzana verde.\n", "@@Pl_Name@@ se come una manzana verde.\n"}));
//    SetFoodMsgs("Te comes una manzana verde.\n");
//    SetFoodMsg2("se come una manzana verde.\n");


    SetFoodStuff(10);
    SetFoodHeal(5);
}
