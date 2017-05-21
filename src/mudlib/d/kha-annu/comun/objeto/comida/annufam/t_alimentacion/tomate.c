/**************************************************************************
Fichero: tomate.c
Autor: Riberales.
Creaci�n: 09-09-05
Descripci�n: Un se�or tomate.
[t] 22/02/2009: Uso la versi�n con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Un tomate");
    SetLong("Es un tomate que parece bastante madurito, y de un rojo pasi�n.\n");
    SetIds(({"tomate"}));
    SetWeight(65);
    SetValue(20);

    SetFoodMsgs(({"�aaam... hum, delicioso, como esperabas.\n", "@@Pl_Name@@ se come un tomate.\n"}));
//    SetFoodMsgs("�aaam... hum, delicioso, como esperabas.\n");
//    SetFoodMsg2("se come un tomate.\n");
    SetFoodStuff(10);
    SetFoodHeal(2);
}
