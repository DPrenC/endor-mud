/**
 Descripci�n: eslab�n y pedernal para encender fuego
 **/


#include <properties.h>

inherit THING;

create()
{
    ::create();
    SetShort("eslab�n y pedernal");
    SetLong("Es un grueso eslab�n de acero unido por una cadenita a un �valo de la "
    "piedra conocida como pedernal. Al frotar ambas piezas con la suficiente destreza se "
    "pueden conseguir chispas para encender materiales inflamables.\n");
    SetIds(({"eslab�n", "eslabon", "encendedor", "pedernal", "piedra","lighter"})); // el lighter es necesario para encender las cosas.
    SetAds(({"de", "acero", "con"}));

    SetValue(300);
    SetWeight(75);
    Set(P_GENDER, GENDER_MALE);
}

