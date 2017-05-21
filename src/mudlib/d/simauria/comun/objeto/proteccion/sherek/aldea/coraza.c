/* archivo: /d/simauria/comun/objeto/proteccion/abadia/coraza.c
* Descripción: Coraza para los guardianes.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>
inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_CORAZA,15,P_SIZE_MEDIUM,M_ACERO);
    SetShort("una coraza");
    SetLong("Es una coraza de acero bruñido, con el emblema de Sherek grabado "
        "en el peto.\n");
    AddSubDetail(({"emblema"}),"Es la imagen de la diosa Sherek, una mujer "
        "con una serpiente enroscada en su brazo derecho, a la que decapita "
        "con una daga que sostiene en su mano izquierda.\n");
    AddId(({"coraza","coraza acero"}));
    SetQuality(100);
    SetResetQuality(100);
}
