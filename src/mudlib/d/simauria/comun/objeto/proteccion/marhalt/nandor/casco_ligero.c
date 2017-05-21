/****************************************************************************
Fichero: casco_ligero.c
Autor: Ratwor
Fecha: 28/11/2007
Descripción: parte del equipo de los guardias del castillo.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_CASCO, 2, P_SIZE_LARGE, M_CUERO);
    SetShort("un casco ligero");
    SetLong("Es un liviano casco redondo que cubre la parte superior de la cabeza pero "
    "no ofrece ninguna protección al rostro y el cuello. Está hecho con varias capas de "
    "cuero endurecido superpuestas y reforzadas por una banda de hierro que forma el "
    "reborde inferior de la cual surgen otras dos que se cruzan perpendicularmente en la "
    "parte superior del casco.\n");    AddId(({"yelmo", "casco", "ligero", "armadura"}));
    Set(P_GENDER, GENDER_MALE);
    SetWeight(1500);
    AddId(({"casco", "casco ligero", "casco de cuero"}));
}
