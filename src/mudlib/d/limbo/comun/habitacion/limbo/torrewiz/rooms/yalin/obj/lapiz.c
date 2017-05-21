#include "path.h"
#include <properties.h>

inherit THING;

create()
{
    ::create();
    AddId(({"lapiz", "lápiz", "lapicero"}));
    SetShort("un lápiz");
    SetLong("Es una barrita cilíndrica fabricada con una mezcla de ingredientes sólo conocidos por Yalin.\nLa usa para "
        "escribir sus conjuros y fórmulas esotéricas.\n");
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
        return notify_fail("Tendrás que coger el lápiz si quieres escribir.\n", NOTIFY_NOT_VALID);
    if (!present("to_write"))
        return notify_fail("¿No querrás pintar en las paredes, verdad?.\n",
        NOTIFY_NOT_VALID);
}
