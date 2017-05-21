/* Archivo: /d/simauria/comun/objeto/arma/abadia/espada.c
* Descripción: Espada para los guardianes de la aldea.
* Autor: Lug y Yalin.
*/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>
inherit WEAPON;

fmirar(string str)
{
    if (!str) return 0;
    if (str=="hoja")
    {
        write("En uno de los lados de la hoja ves el emblema de Sherek, mientras "
             "que en el otro puedes leer:\n'Sherek me proteja y me dé la fuerza "
            "para servirla'\n");
        return 1;
    }
    if (str=="emblema")
    {
        write("Ves la imagen de una mujer con una serpiente enroscada en su "
            "brazo derecho, a la que decapita con una daga que sostiene en su "
            "mano izquierda.\n");
        return 1;
    }
}

create()
{
    ::create();
    SetStandard(WT_ESPADA,8,P_SIZE_MEDIUM,M_ACERO);
    SetShort("una espada");
    SetLong("Es una espada de acero templado mediante un procedimiento "
        "secreto.\n"
        "Ves algo escrito en la hoja.\n");
    SetIds(({"espada"}));
    SetNumberHands(1);
    SetQuality(100);
    SetResetQuality(100);
}

init()
{
    ::init();
    add_action("fmirar","mirar");
    add_action("fmirar","m");
}
