/**************************************************************************
Fichero: platano.c
Autor: Riberales.
Creaci�n: 27-09-05
Descripci�n: Un platanito.
[t] 22/02/2009: Uso la versi�n con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Un pl�tano");
    SetLong("Es un pl�tano que est� bastante madurito, y con motitas negras y "
            "todo.\n");
    SetIds(({"platano","pl�tano"}));
    SetWeight(90);
    SetValue(25);

    SetFoodMsgs(({"�aaam... hum, delicioso, como esperabas.\n", "@@Pl_Name@@ se come un pl�tano.\n"}));
//    SetFoodMsgs("�aaam... hum, delicioso, como esperabas.\n");
//    SetFoodMsg2("se come un pl�tano.\n");
    SetFoodStuff(18);
    SetFoodHeal(6);
}
