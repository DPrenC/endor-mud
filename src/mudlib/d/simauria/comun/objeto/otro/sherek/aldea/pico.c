/* Archivo: /d/simauria/comun/objeto/otro/abadia/pico.c
* Descripción: Pico para los campesinos.
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
    SetStandard(WT_MAZA,3,P_SIZE_MEDIUM,M_ACERO,GENERO_MASCULINO);
    SetShort("un pico");
    SetLong("Es una barra terminada en punta roma por un extremo, y en forma de "
        "cuchilla estrecha en el otro, y con una anilla en el centro donde "
        "encaja un palo grueso para empuñarlo.\nSirve para quebrar la superficie "
        "del terreno, para removerlo o cavarlo después.\n");
    AddId(({"pico"}));
    SetNumberHands(2);
}
