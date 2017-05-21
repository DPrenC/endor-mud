/* Archivo: /d/simauria/comun/objeto/otro/abadia/guadanya.c
* Descripci�n: Guada�a para los campesinos.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_ESPADA,3,P_SIZE_MEDIUM,M_HIERRO);
    SetShort("una guada�a");
    SetLong("Es un palo algo grueso, con una hoja curva de hierro saliendo "
        "oblicuamente de su parte inferior.\nSe usa principalmente para segar "
        "los cereales.");
    AddId(({"guada�a","guadanya"}));
    SetNumberHands(2);
}
