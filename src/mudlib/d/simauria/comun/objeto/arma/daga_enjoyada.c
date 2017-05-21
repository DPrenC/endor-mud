/****************************************************************************
Fichero: daga_enjoyada
Autor: Ratwor
Fecha: 18/04/2008
Descripción: una daga enjoyada
****************************************************************************/

inherit WEAPON;
#include <combat.h>
#include <properties.h>

create() {
    ::create();
    SetStandard(WT_CUCHILLO, 1, P_SIZE_MEDIUM, M_ORO);
    SetIds(({"daga","arma", "daga enjoyada"}));
    SetShort("una daga enjoyada");
    SetLong("Es una daga lujosa. Es una herramienta de buena manufactura. Su filo largo "
    "y aguzado, combina a la perfección con su empuñadura de oro incrustada de "
    "piedras preciosas. La exigua guardia confiere a esta arma una apariencia mas "
    "estilizada a la vez que le da aspecto de inofensivo abrecartas.\n");
    SetWeight(400);
    SetValue(9000);
Set(P_GENDER,GENDER_FEMALE);
}
