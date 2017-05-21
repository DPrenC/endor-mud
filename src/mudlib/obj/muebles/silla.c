/* ENDOR-MUD OROME silla.c */

#include <properties.h>

inherit "/std/asiento";

create()
{
    ::create();
    Set("name","una silla");
    SetDescripcion("Es una sencilla silla de madera con respaldo recto, cuatro patas y "
    "exenta de brazos.");
        AddId(({"silla"}));
    SetAds(({"de","madera","sencilla"}));
        SetValue(2000);
        Set(P_GENDER, GENERO_FEMENINO);
}

