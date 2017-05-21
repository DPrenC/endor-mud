/* ENDOR-MUD OROME banco_fragil.c */
#include <materials.h>
#include <properties.h>

inherit "/std/asiento";

create()
{
    ::create();
    Set("name","un banco viejo");
    SetDescripcion("Es un ruinoso y viejo banco pequeño de madera oscurecida por el tiempo.");
        AddId(({"banco"}));
        SetWeight(20000);
    SetAds(({"de","madera","viejo", "ruinoso"}));
        SetValue(2000);
    SetFirmeza(P_FIRMEZA_FRAGIL);
    SetMaxPlazas(2);
}

