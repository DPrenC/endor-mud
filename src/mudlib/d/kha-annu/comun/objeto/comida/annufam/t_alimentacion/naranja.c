/**************************************************************************
Fichero: naranja.c
Autor: Riberales.
Creaci�n: 27-09-05
Descripci�n: Una naranja.
[t] 22/02/2009: Uso la versi�n con array de SetFoodMsgs en lugar de SetFoodMsg2.
***************************************************************************/

inherit FOOD;

public void create()
{
    ::create();
    SetFoodKind("food");
    SetShort("Una naranja");
    SetLong("Es una naranja, parece algo verde, pero seguro que est� muy "
            "buena.\n");
    SetIds(({"naranja"}));
    SetWeight(55);
    SetValue(28);

    SetFoodMsgs(({"Hum, est� algo �cida, pero bueno...\n", "@@Pl_Name se come una naranja.\n"}));
//    SetFoodMsgs("Hum, est� algo �cida, pero bueno...\n");
//    SetFoodMsg2("se come una naranja.\n");
    SetFoodStuff(11);
    SetFoodHeal(4);
}
