/****************************************************************************
Fichero: tunica_bestol.c
Autor: Ratwor
Fecha: 26/11/2007
Descripci�n: Una t�nica para el errante de la Rosa de los vientos.
****************************************************************************/


#include "./path.h"
#include <combat.h>
#include <properties.h>
inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_TUNICA, 1,P_SIZE_LARGE,M_TELA);
    SetShort("una oscura t�nica");
    SetLong("Es una oscura t�nica de tela dura, de un color indeterminado entre "
    "verde oliva, marr�n oscuro o quiz� azul marino.\n Aunque se nota que est� limpia, "
    "la apariencia es de ser notablemente vieja. Destaca alrededor de ambos pu�os, "
    "unas peque�as equis bordadas con hilo dorado.\n");
    AddId(({"tunica","t�nica","tunica vieja","t�nica vieja"}));
    SetResetQuality(100);
}
