/****************************************************************************
Fichero: /d/simauria/comun/objeto/proteccion/sherek/abadia/tunican.c
Autor: Lug y Yalin
Fecha: 19/09/2006
Descripci�n: T�nica para los novicios de la abad�a.
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
    SetShort("una t�nica blanca");
    SetLong("Es una t�nica de lino blanco, que visten los monjes de "
        "primer grado.\nLleva, como �nico adorno, el emblema de la diosa "
        "bordado en el pecho.\n");
    AddSubDetail(({"emblema"}),"Es la imagen de la diosa Sherek, una mujer "
        "con una serpiente enroscada en su brazo derecho, a la que decapita "
        "con una daga que sostiene en su mano izquierda.\n");
    SetResetQuality(100);
}
