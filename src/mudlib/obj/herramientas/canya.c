/*
Fichero: canya.c
Autor: Aul�
Fecha: 29/10/2014
Descripci�n: Una ca�a de pescar.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit WEAPON;

create() {
    ::create();
    	SetStandard(WT_CAYADO, 2, P_SIZE_GENERIC, M_MADERA);
    SetShort("una ca�a de pescar");
    SetLong(
    "Es una ca�a de pescar hecha de madera flexible y recta que va afin�ndose hacia el "
    "extremo. Dispone de un carrete de madera y cobre bien nutrido de tanza que "
    "recorre la ca�a sujeta por peque�os soportes met�licos.\n");
    AddId(({"ca�a","ca�a de pescar","canya","canya de pescar", "herramienta", "canya_pescador", "canya_pescador"}));
    SetWeight(950);
    SetValue(1500);
}
