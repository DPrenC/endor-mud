/* Archivo: /d/simauria/comun/objeto/otro/sherek/cantera/pico.c
* Descripci�n: Pico para los campesinos.
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
        "en el centro donde encaja un palo grueso para empu�arlo.\nSirve "
        "para resquebrajar las rocas, y arrancarlas de la monta�a.\n");
    RemoveId("maza");
    AddId(({"pico","PicoQuest"}));
    SetNoDrop("No es buena idea soltarlo, quiz� lo necesites aqu�.\n");
    SetNumberHands(2);
}
