/*
Fichero: canya.c
Autor: Aulë
Fecha: 29/10/2014
Descripción: Una caña de pescar.
****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit WEAPON;

create() {
    ::create();
    	SetStandard(WT_CAYADO, 2, P_SIZE_GENERIC, M_MADERA);
    SetShort("una caña de pescar");
    SetLong(
    "Es una caña de pescar hecha de madera flexible y recta que va afinándose hacia el "
    "extremo. Dispone de un carrete de madera y cobre bien nutrido de tanza que "
    "recorre la caña sujeta por pequeños soportes metálicos.\n");
    AddId(({"caña","caña de pescar","canya","canya de pescar", "herramienta", "canya_pescador", "canya_pescador"}));
    SetWeight(950);
    SetValue(1500);
}
