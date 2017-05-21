/****************************************************************************
Fichero: capucha_p.c
Autor: Ratwor
Fecha: 14/05/2010
Descripción: una capucha pequeña
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create()
{
    ::create();
    SetStandard(AT_CAPUCHA, 1, P_SIZE_SMALL, M_TELA);
    SetShort("Una pequeña capucha");
    SetLong("Es una pequeña capucha que cubre la cabeza y el cuello, y si se desea también "
    "oculta el rostro de miradas indiscretas. Está hecha de tela embreada para "
    "resultar impermeable al agua por lo que ofrece una buena protección contra los "
    "elementos. Habitualmente suele combinarse con una capa o manto.\n");
    SetIds(({"capucha", "ropa"}));
    AddAdjective("pequeña");
    Set(P_GENDER, GENDER_FEMALE);
    SetWeight(300);
}
