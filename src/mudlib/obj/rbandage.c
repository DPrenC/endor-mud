// a rotten bandage - made by MagicTCS 26/11/96
// now as unit instead of single item

#include <config.h>
#include <properties.h>

inherit THING;
inherit ARMOUR;

public int cmd_bandage(string str)
{
    return notify_fail("Esta venda está sucia, no la puedes volver a usar.\n",NOTIFY_NOT_VALID);
}

create()
{
    ::create();
    SetValue(0);
    SetWeight(30);
    SetShort("una venda sucia");
    SetLong("Esta venda está sucia. No puedes volver a usarla.\n");
    Set(P_GENDER, GENERO_FEMENINO);
    AddId("venda");
    AddAdjective("sucia");
}

public void init()
{
    (::init());
    add_action("cmd_bandage","vendar");
}
