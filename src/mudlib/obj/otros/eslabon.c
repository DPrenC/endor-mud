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
    SetIds(({"eslabón", "eslabon", "acero", "pedernal", "piedra de pedernal", "piedra pedernal", "piedra",
             "acero con piedra de pedernal", "acero con pedernal", "pedernal con acero"}));
    SetValue(100);
    SetWeight(75);
    Set(P_GENDER, GENDER_MALE);
}

