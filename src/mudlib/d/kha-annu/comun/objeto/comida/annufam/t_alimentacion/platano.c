/**************************************************************************
Fichero: platano.c
Autor: Riberales.
Creación: 27-09-05
Descripción: Un platanito.
[t] 22/02/2009: Uso la versión con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Un plátano");
    SetLong("Es un plátano que está bastante madurito, y con motitas negras y "
            "todo.\n");
    SetIds(({"platano","plátano"}));
    SetWeight(90);
    SetValue(25);

    SetFoodMsgs(({"Ñaaam... hum, delicioso, como esperabas.\n", "@@Pl_Name@@ se come un plátano.\n"}));
//    SetFoodMsgs("Ñaaam... hum, delicioso, como esperabas.\n");
//    SetFoodMsg2("se come un plátano.\n");
    SetFoodStuff(18);
    SetFoodHeal(6);
}
