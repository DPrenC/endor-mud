/****************************************************************************
Fichero: guantes_seda.c
Autor: Ratwor
Fecha: 18/04/2008
Descripción: unos guantes de seda.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_GUANTES, 0, P_SIZE_MEDIUM, M_TELA);
    SetShort("unos guantes de seda");
    SetLong("Son unos delicados guantes de seda con dedos esbeltos y finos idóneos "
    "para una mujer, se prolongan hasta la altura del codo dando una apariencia muy "
    "sugerente.\n");
    SetIds(({"guantes", "guantes de seda"}));
    Set(P_NUMBER, NUMBER_PLURAL);
    SetValue(900);
}
