/**************************************************************************
Fichero: tomate.c
Autor: Riberales.
Creación: 09-09-05
Descripción: Un señor tomate.
[t] 22/02/2009: Uso la versión con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Un tomate");
    SetLong("Es un tomate que parece bastante madurito, y de un rojo pasión.\n");
    SetIds(({"tomate"}));
    SetWeight(65);
    SetValue(20);

    SetFoodMsgs(({"Ñaaam... hum, delicioso, como esperabas.\n", "@@Pl_Name@@ se come un tomate.\n"}));
//    SetFoodMsgs("Ñaaam... hum, delicioso, como esperabas.\n");
//    SetFoodMsg2("se come un tomate.\n");
    SetFoodStuff(10);
    SetFoodHeal(2);
}
