/****************************************************************************
Fichero: /d/simauria/comun/objeto/proteccion/sherek/abadia/tunicaa.c
Autor: Lug y Yalin
Fecha: 19/09/2006
Descripción: Túnica para el abad.
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
    SetShort("una túnica negra");
    SetLong("Es una túnica de lino negro, una prenda exclusiva del abad.\n"
        "Lleva, como único adorno, el emblema de la diosa bordado en "
        "el pecho.\n");
    AddId(({"tunica","túnica","tunica negra","túnica negra"}));
    AddSubDetail(({"emblema"}),"Es la imagen de la diosa Sherek, una mujer "
        "con una serpiente enroscada en su brazo derecho, a la que decapita "
        "con una daga que sostiene en su mano izquierda.\n");
    SetResetQuality(100);
}
