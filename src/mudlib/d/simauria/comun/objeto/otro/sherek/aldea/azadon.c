/* Archivo /d/simauria/comun/objeto/otro/abadia/azadon.c
* Descripción: azadón para los aldeanos labradores.
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
    SetStandard(WT_HACHA,4,P_SIZE_MEDIUM,M_ACERO,GENERO_MASCULINO);
    SetShort("un azadón");
    SetLong("Es una hoja rectangular de acero, ligeramente curva, con uno de "
        "sus lados cortos afilado, y el otro unido a una anilla igualmente de "
        "acero,  donde se inserta un palo grueso y largo para cogerlo.\nSe usa "
        "para cavar la tierra y removerla para sembrar o prepararla para la siembra.\n");
    AddId(({"azadon","azadón"}));
    SetNumberHands(2);
}
