/* Archivo /d/simauria/comun/objeto/otro/abadia/azada.c
* Descripción: azada para los aldeanos labradores.
* Autor Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <materials.h>
#include <combat.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_HACHA,2,P_SIZE_MEDIUM,M_HIERRO);
    SetShort("una azada");
    SetLong("Es una hoja triangular, de hierro, unida a un mango delgado y "
        "ligeramente curvo, igualmente de hierro, con un puño de madera en el "
        "extremo para cogerla.\nSe usa para cavar ligeramente la tierra, "
        "especialmente para airear las raíces de las plantas ahuecando la tierra "
        "a su alrededor.\n");
    AddId(({"azada"}));
    SetNumberHands(1);
}
