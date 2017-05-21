/****************************************************************************
Fichero: guanteletes_noble.c
Autor: Ratwor
Fecha: 28/11/2007
Descripci�n: parte del equipo del noble del castillo.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_GUANTES, 3, P_SIZE_GENERIC, M_ACERO);
    SetShort("unos guanteletes");
    SetLong("Estos guanteletes est�n formados por una pieza met�lica que protege el "
    "dorso de la mano y la mu�eca, y una serie de piezas mas peque�as que cubrenn los "
    "dedos, unidas a la grande, entre si y a una secci�n de cuero grueso que cubre la "
    "palma de la mano.\n");
    AddId(({"guanteletes", "acero", "guantes"}));
    Set(P_GENDER, GENDER_MALE);
    Set(P_NUMBER, NUMBER_PLURAL);
    SetWeight(1200);
}
