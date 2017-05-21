/* ENDOR OROME banco.c */

#include <properties.h>
inherit "/std/asiento";

create()
{
    ::create();
    Set("name","un banco largo");
    SetDescripcion("Es un largo banco sin respaldo confeccionado con un �nico grueso "
    "tabl�n apoyado sobre cuatro patas robustas. Se trata del t�pico banco de taberna, "
    "simple, sencillo pero funcional.");
    SetMaxPlazas(4);
    AddId(({"banco"}));
    SetAds(({"de","madera","alargado"}));
    SetWeight(30000);
    SetValue(5000);
}

