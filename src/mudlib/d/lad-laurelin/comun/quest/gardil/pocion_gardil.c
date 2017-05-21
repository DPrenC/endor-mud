/****************************************************************************
Fichero: pocion_gardil.c
Autor: Kastwey
Fecha: 07/04/2006
Descripci�n: La poci�n para darle a Gardil
****************************************************************************/


#include <properties.h>
#include <moving.h>

inherit THING;

private string pOwner;

public string SetOwner(string own) { return pOwner = own; }
public string QueryOwner() { return pOwner; }

public int cmd_beber(string str)
{
        object ob;
        if (!str || !(ob = present(str, TP)) || ob != TO)
            {
                    return 0;
                }
    return notify_fail("Despu�s de lo que te ha costado conseguir la poci�n, "
                       "decides ser fuerte y no caer en la tentaci�n de "
                       "beb�rtela.\n", NOTIFY_NOT_VALID);
}


public varargs int move(mixed dest, int method, mixed extra)
{
    if (!PO || method != M_GIVE || dest->QueryGardil()) return ::move(dest, method, extra);
    tell_object(PO, "Despu�s de valorar el esfuerzo invertido en conseguir esta poci�n, "
                    "decides conservarla.\n");
    return ME_NO_GIVE;
}

init()
{
    ::init();
    add_action("cmd_beber", "beber");
}

create()
{
    ::SetShort("una extra�a poci�n");
    SetLong("Es un vial de regeneraci�n, pero con una extra�a poci�n en su "
            "interior.\n");
    SetIds(({"vial", "vial de regeneracion", "vial de regeneraci�n", "pocion",
             "poci�n", "pocion extra�a", "poci�n extra�a", "pocion extranya",
             "poci�n extranya", "pocion_curar_gardil"}));
    Set(P_NOSELL, 1);
    SetValue(0);
    SetNoDrop("Despu�s de lo que te ha costado conseguirla, te da pena tirarla... Decides "
              "qued�rtela.\n");
}
