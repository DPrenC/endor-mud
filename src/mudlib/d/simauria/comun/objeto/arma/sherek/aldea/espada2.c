/* Archivo: /d/simauria/comun/objeto/arma/abadia/espada2.c
* Descripción: Espada larga para los guardianes de la casa del administrador.
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
    SetStandard(WT_ESPADA,10,P_SIZE_MEDIUM,M_ACERO);
    SetShort("una espada larga");
    SetLong("Es una gran espada de acero templado mediante un procedimiento "
        "secreto.\nCon casi metro y medio de longitud y una anchura considerable, requiere gran "
        "fuerza para manejarla. Si no eres lo bastante fuerte, tendrás que usar las dos manos.\n"
        "Ves algo escrito en la hoja.\n");
    SetIds(({"espada","espada larga"}));
    SetWeight(10000);
    SetQuality(100);
    SetResetQuality(100);
}

init()
{
    ::init();
    add_action("fmirar","mirar");
    add_action("fmirar","m");
}

public varargs mixed ChkEquip(object wielder, object weapon, int flags)
{
    if (weapon != TO) return EQ_OK;
    if (!wielder->QueryIsPlayer()) return EQ_OK;
    if (wielder->QueryStr()<20)
    {
        tell_object(wielder,"Eres muy débil para manejar bien esa espada. Necesitarás usar las dos "
            "manos.\n");
        SetNumberHands(2);
    }
    else SetNumberHands(1);
    return ::ChkEquip(wielder, weapon, flags);
}
