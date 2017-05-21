/****************************************************************************
Fichero: /d/simauria/comun/objeto/proteccion/sherek/abadia/tunicaa.c
Autor: Lug y Yalin
Fecha: 19/09/2006
Descripci�n: T�nica para el abad.
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
    SetShort("una t�nica negra");
    SetLong("Es una t�nica de lino negro, una prenda exclusiva del abad.\n"
        "Lleva, como �nico adorno, el emblema de la diosa bordado en "
        "el pecho.\n");
    AddId(({"tunica","t�nica","tunica negra","t�nica negra"}));
    AddSubDetail(({"emblema"}),"Es la imagen de la diosa Sherek, una mujer "
        "con una serpiente enroscada en su brazo derecho, a la que decapita "
        "con una daga que sostiene en su mano izquierda.\n");
    SetResetQuality(100);
}
