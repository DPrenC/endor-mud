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
    SetIds(({"eslab�n", "eslabon", "acero", "pedernal", "piedra de pedernal", "piedra pedernal", "piedra",
             "acero con piedra de pedernal", "acero con pedernal", "pedernal con acero"}));
    SetValue(100);
    SetWeight(75);
    Set(P_GENDER, GENDER_MALE);
}

