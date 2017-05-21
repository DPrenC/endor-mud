/****************************************************************************
Fichero: capucha_p.c
Autor: Ratwor
Fecha: 14/05/2010
Descripci�n: una capucha peque�a
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_CAPUCHA, 1, P_SIZE_SMALL, M_TELA);
    SetShort("Una peque�a capucha");
    SetLong("Es una peque�a capucha que cubre la cabeza y el cuello, y si se desea tambi�n "
    "oculta el rostro de miradas indiscretas. Est� hecha de tela embreada para "
    "resultar impermeable al agua por lo que ofrece una buena protecci�n contra los "
    "elementos. Habitualmente suele combinarse con una capa o manto.\n");
    SetIds(({"capucha", "ropa"}));
    AddAdjective("peque�a");
    Set(P_GENDER, GENDER_FEMALE);
    SetWeight(300);
}
