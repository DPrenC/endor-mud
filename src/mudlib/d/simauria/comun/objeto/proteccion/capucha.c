/****************************************************************************
Fichero: capucha.c
Autor: Ratwor
Fecha: 20/04/2008
Descripción: una capucha
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_CAPUCHA, 1, P_SIZE_LARGE, M_TELA);
    SetShort("Una capucha");
    SetLong("Es una capucha que cubre la cabeza y el cuello, y si se desea también "
    "oculta el rostro de miradas indiscretas. Está hecha de tela embreada para "
    "resultar impermeable al agua por lo que ofrece una buena protección contra los "
    "elementos. Habitualmente suele combinarse con una capa o manto.\n");
    AddId(({"capucha", "armadura", "ropa"}));
    Set(P_GENDER, GENDER_FEMALE);
    SetWeight(500);
}
