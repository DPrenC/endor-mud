/**************************************************************************
Fichero: mendrugo.c
Autor: [T] Tagoras
Creación: 28/03/2009
Descripción: Un mendrugo de pan
***************************************************************************/

inherit FOOD;

public void create()
{
	::create();
	SetFoodKind("food");
	SetShort("Un mendrugo");
	SetLong("Es un mendrugo de pan duro.\n");
	SetIds(({"mendrugo"}));
	SetAds(({"un", "de", "pan", "duro"}));
	SetWeight(25);
	SetValue(5);
	SetFoodMsgs(({"Te comes un mendrugo de pan duro.\n", "@@Pl_Name@@ se come un mendrugo de pan duro.\n"}));
	SetFoodStuff(3);
	SetFoodHeal(1);
}
