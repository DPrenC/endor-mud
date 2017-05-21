/* Archivo: /d/simauria/comun/objeto/otro/abadia/rastrillo.c
* Descripci�n: Rastrillo para los campesinos.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <materials.h>
#include <combat.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_CUCHILLO,3,P_SIZE_MEDIUM,M_ACERO,GENERO_MASCULINO);
    SetShort("un rastrillo");
    SetLong("Es una barra de acero de la que sale una hilera de p�as, con un "
        "palo ensartado en el centro en perpendicular a las p�as, para empu�arlo.\n"
        "Es usado para filtrar la tierra, quitando las piedras y hierbajos, "
        "ara�ando la superficie del terreno.\n");
    AddId(({"rastrillo"}));
    SetNumberHands(2);
}
