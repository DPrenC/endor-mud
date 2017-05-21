/* Archivo: /d/simauria/comun/objeto/otro/sherek/cantera/pico.c
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
    SetStandard(WT_MAZA,3,P_SIZE_GENERIC,M_ACERO,GENERO_MASCULINO);
    SetShort("un pico");
    SetLong("Es una barra terminada en punta aguda por un extremo, y en "
        "forma de cuchilla ancha y muy cortante en el otro, y con una anilla "
        "en el centro donde encaja un palo grueso para empuñarlo.\nSirve "
        "para resquebrajar las rocas, y arrancarlas de la montaña.\n");
    RemoveId("maza");
    AddId(({"pico","PicoQuest"}));
    SetNoDrop("No es buena idea soltarlo, quizá lo necesites aquí.\n");
    SetNumberHands(2);
}
