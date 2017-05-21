#include "path.h"
#include <properties.h>

inherit THING;

create()
{
    ::create();
    AddId(({"lapiz", "l�piz", "lapicero"}));
    SetShort("un l�piz");
    SetLong("Es una barrita cil�ndrica fabricada con una mezcla de ingredientes s�lo conocidos por Yalin.\nLa usa para "
        "escribir sus conjuros y f�rmulas esot�ricas.\n");
Set(P_WEIGHT,25);
Set(P_CANT_STEAL,1);
Set(P_NOSELL,1);
}

init(){
    ::init();
    add_action("cmd_escribir", "escribir");
}

int cmd_escribir(){
    if (!present(TO,TP))
        return notify_fail("Tendr�s que coger el l�piz si quieres escribir.\n", NOTIFY_NOT_VALID);
    if (!present("to_write"))
        return notify_fail("�No querr�s pintar en las paredes, verdad?.\n",
        NOTIFY_NOT_VALID);
}
