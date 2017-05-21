/****************************************************************************
Fichero: /d/simauria/comun/objeto/proteccion/sherek/abadia/tunicam.c
Autor: Lug y Yalin
Fecha: 19/09/2006
Descripción: Túnica para los numerarios de la abadía.
****************************************************************************/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>
inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_TUNICA, 1,P_SIZE_MEDIUM,M_TELA);
    SetShort("una túnica verde");
    SetLong("Es una túnica de lino verde, que visten los monjes de "
        "grado medio.\nLleva, como único adorno, el emblema de la diosa "
        "bordado en el pecho.\n");
    AddId(({"tunica","túnica","tunica verde","túnica verde"}));
    AddSubDetail(({"emblema"}),"Es la imagen de la diosa Sherek, una mujer "
        "con una serpiente enroscada en su brazo derecho, a la que decapita "
        "con una daga que sostiene en su mano izquierda.\n");
    SetResetQuality(100);
}
