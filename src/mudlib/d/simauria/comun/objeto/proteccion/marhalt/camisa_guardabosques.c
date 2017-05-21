/****************************************************************************
Fichero: camisa_guardabosques.c
Autor: Ratwor
Fecha: 14/05/2010
Descripción: una camisa de cuero para el guardabosques.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TUNICA, 3, P_SIZE_LARGE, M_CUERO);
    SetShort("una camisa de cuero");
    SetLong("Es una camisa de cuero blando trabajado con diseños relacionados con la "
    "naturaleza, que facilita a su portador el ocultamiento entre la maleza.\n");
    SetIds(({"camisa", "ropa"}));
    AddAdjective(({"blando", "de", "cuero"}));
    SetWeight(700);
    Set(P_GENDER, GENDER_FEMALE);

}
