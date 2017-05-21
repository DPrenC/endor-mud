/**************************************************************************
Fichero: besugo.c
Autor: Riberales.
Creación: 21-09-05
Descripción: Un besugo de Lugo.
[t] 22/02/2009: Usi SetFoodMsgs con array en lugar de SetFoodMsg2
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("un besugo");
    SetLong("Es un besugo recién pescado, pero ya destripado y limpio.\n");
    SetIds(({"besugo","pescado"}));
    SetWeight(450);
    SetValue(620);

    SetFoodMsgs(({"Glub, blub... puaj, a lo crudo no está muy allá, pero bueno, alimenta.\n", "@@Pl_Name@@ se come un besugo.\n"}));
//    SetFoodMsgs("Glub, blub... puaj, a lo crudo no está muy allá, pero bueno, "
//                "alimenta.\n");
//    SetFoodMsg2("se come un besugo.\n");
    SetFoodStuff(20);
    SetFoodHeal(10);
}
