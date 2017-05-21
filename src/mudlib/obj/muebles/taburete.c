/* ENDOR-MUD OROME taburete.c */

#include <properties.h>
inherit "/std/asiento";

create()
{
    ::create();
    Set("name","un taburete");
    SetDescripcion("Un taburete alto de madera negra.");
    AddId(({"taburete"}));
    SetAds(({"alto", "de", "madera"}));
    SetWeight(4000);

}
