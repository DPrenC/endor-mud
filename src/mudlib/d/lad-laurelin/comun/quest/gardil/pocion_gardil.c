/****************************************************************************
Fichero: pocion_gardil.c
Autor: Kastwey
Fecha: 07/04/2006
Descripción: La poción para darle a Gardil
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
    return notify_fail("Después de lo que te ha costado conseguir la poción, "
                       "decides ser fuerte y no caer en la tentación de "
                       "bebértela.\n", NOTIFY_NOT_VALID);
}


public varargs int move(mixed dest, int method, mixed extra)
{
    if (!PO || method != M_GIVE || dest->QueryGardil()) return ::move(dest, method, extra);
    tell_object(PO, "Después de valorar el esfuerzo invertido en conseguir esta poción, "
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
    ::SetShort("una extraña poción");
    SetLong("Es un vial de regeneración, pero con una extraña poción en su "
            "interior.\n");
    SetIds(({"vial", "vial de regeneracion", "vial de regeneración", "pocion",
             "poción", "pocion extraña", "poción extraña", "pocion extranya",
             "poción extranya", "pocion_curar_gardil"}));
    Set(P_NOSELL, 1);
    SetValue(0);
    SetNoDrop("Después de lo que te ha costado conseguirla, te da pena tirarla... Decides "
              "quedártela.\n");
}
