/**************************************************************************
Fichero: merluza.c
Autor: Riberales.
Creación: 25-09-05
Descripción: Una merluza andaluza.
[t] 22/02/2009: Uso la versión con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Una merluza");
    SetLong("Es una merluza fresca, lo que no quita que esté limpia.\n");
    SetIds(({"merluza","pescado"}));
    SetWeight(250);
    SetValue(420);
    SetFoodMsgs(({"Te comes una merluza, con sus espinas y todo.\n", "@@Pl_Name@@ se come una merluza.\n"}));
//    SetFoodMsgs("Te comes una merluza, con sus espinas y todo.\n");
//    SetFoodMsg2("se come una merluza.\n");


    SetFoodStuff(12);
    SetFoodHeal(5);
}
