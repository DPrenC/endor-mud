/**************************************************************************
Fichero: ceolla.c
Autor: Riberales.
		[t] Tagoras
Creación: 27-09-05
Descripción: Una cebolla.
[t] 22/02/2009: Uso la versión con array de SetFoodMsgs en lugar de SetFoodMsg2.
[t] 05/01/2012: Arreglo algún tipo y quito W()
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Una cebolla");
    SetLong("Es una cebollita de toda la vida, de esas que se ponen en la "
            "ensalada y hacen llorar a la gente.\n");
    SetIds(({"cebolla"}));
    SetWeight(75);
    SetValue(16);

	SetFoodMsgs(({"Te comes la cebolla sin complejo alguno. Puaj, vaya aliento.\n", "@@Pl_Name@@ se come una cebolla.\n"}));
//    SetFoodMsgs("Te comes la cebolla sin complejo alguno. Puaj, vaya "
//                "aliento.\n");
//    SetFoodMsg2("se come una cebolla.\n");
    SetFoodStuff(12);
    SetFoodHeal(4);
}
