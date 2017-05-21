/*
Fichero: guadanya.c
Autor: Aule
Fecha: 20/09/2014
Descripci�n: guada�a para segar hierba, heno, etc.
*/

#include <properties.h>
#include <combat.h>
#include <materials.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_IMPROVISADA,3,P_SIZE_LARGE,M_ACERO);
    SetDamType(DT_SLASH);
    SetShort("una guada�a");
    SetLong(
    "Es una herramienta utilizada para segar la hierba. Consta de un largo mango con un "
    "asidero en la parte media y otro en el extremo del mango para empu�arla con ambas manos.\n"
    "En el mango se encaja una larga y curva hoja met�lica tan fina que el filo corta "
    "como una navaja de afeitar aunque necesita ser afilada cada poco tiempo para "
    "cortar bien la hierba.\n");
    AddId(({"guada�a","guadanya", "guada�a_campesino", "herramienta"}));
    SetNumberHands(2);
    SetWeight(2200);
}
