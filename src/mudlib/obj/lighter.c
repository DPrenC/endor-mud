/**
 Descripción: eslabón y pedernal para encender fuego
 **/


#include <properties.h>

inherit THING;

create()
{
    ::create();
    SetShort("eslabón y pedernal");
    SetLong("Es un grueso eslabón de acero unido por una cadenita a un óvalo de la "
    "piedra conocida como pedernal. Al frotar ambas piezas con la suficiente destreza se "
    "pueden conseguir chispas para encender materiales inflamables.\n");
    SetIds(({"eslabón", "eslabon", "encendedor", "pedernal", "piedra","lighter"})); // el lighter es necesario para encender las cosas.
    SetAds(({"de", "acero", "con"}));

    SetValue(300);
    SetWeight(75);
    Set(P_GENDER, GENDER_MALE);
}

