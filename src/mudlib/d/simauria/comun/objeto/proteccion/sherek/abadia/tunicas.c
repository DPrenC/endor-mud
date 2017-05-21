/****************************************************************************
Fichero: /d/simauria/comun/objeto/proteccion/sherek/abadia/tunicas.c
Autor: Lug y Yalin
Fecha: 19/09/2006
Descripción: Túnica para los superiores de la abadía.
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
    SetShort("una túnica roja");
    SetLong("Es una túnica de lino rojo, que visten los monjes de "
        "grado superior.\nLleva, como único adorno, el emblema de la diosa "
        "bordado en el pecho.\n");
    AddId(({"tunica","túnica","tunica roja","túnica roja"}));
    AddSubDetail(({"emblema"}),"Es la imagen de la diosa Sherek, una mujer "
        "con una serpiente enroscada en su brazo derecho, a la que decapita "
        "con una daga que sostiene en su mano izquierda.\n");
    SetResetQuality(100);
}
