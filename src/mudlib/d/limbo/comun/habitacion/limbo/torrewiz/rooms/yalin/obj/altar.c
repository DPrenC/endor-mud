#include "path.h"
#include <properties.h>
#include <colours.h>
#include <moving.h>
#include <lock.h>
#include <search.h>
inherit "/std/room/items";
inherit "/std/container";
#define AO (TP->QueryGender()==GENERO_FEMENINO?"a":"o")

public int abrir_(string str)
{
    if (TO->id(str))
    {
        write("No ves "+str+" que abrir.\n");
        return 1;
    }
    return 0;
}

public int cerrar_(string str)
{
    if (TO->id(str))
    {
        write("No ves "+str+" que cerrar.\n");
        return 1;
    }
    return 0;
}

create()
{
    "*"::create();
    SetIds(({"altar"}));
    SetAds(({"de"}));
    SetShort("el altar");
    SetLong("Es una elegante mesa negra, tallada en ébano y cubierta con un mantel blanco.\n");
    AddSubDetail(({"mantel"}), "Es un fino mantel de lino blanco, tejido por un maestro duende en "
        "lejanas tierras.\n");
    AddId(({"altar","mesa","mesita"}));
    AddAdjective(({"madera"}));
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NOGET,"¡Qué inocente eres! ¿En serio pensabas cogerlo?\n");
    Set(P_LOCKSTATE,LOCK_OPEN);
    SetMaxIntWeight(10000);
    AddItem("lapiz");
    AddItem("hoja");
}
  
init()
{
    ::init();
    add_action("cerrar_","cerrar");
    add_action("abrir_","abrir");
}
        