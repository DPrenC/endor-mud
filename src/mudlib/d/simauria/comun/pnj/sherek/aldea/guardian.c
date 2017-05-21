/* Archivo: /d/simauria/comun/pnj/abadia/guardian.c
* Descripción: Guardián de la abadía para lavigilancia de la aldea y sus aledaños.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <skills.h>
inherit PNJ("sherek/gbase");

create()
{
    ::create();
    SetStandard("un guardián","humano",([ GC_LUCHADOR:40+d10() ]),GENERO_MASCULINO);
    SetShort("un guardián");
    SetLong("Es un miembro del servicio privado de guardias de la abadía de "
        "Sherek.\nSu entrenamiento es duro y continuado, lo que los convierte en "
        "perfectos y seguros vigilantes, por lo que se les dedica a la guardia y "
        "cuidado de los terrenos de la abadía, así como a la vigilancia del "
        "orden entre sus gentes, aunque nadie está seguro de si son protectores "
        "o carceleros. Quizá sean las dos cosas.\n");
    SetCon(QueryCon()+5);
    SetHP(QueryMaxHP());
    SetGoChance(90);
    AddWalkZones(({SHERALD("calles"),SHERALD("campo"),SHERALD("granja"),SHERALD("pastos"),SHERALD("tiendas"),SHERALD("pradera")}));
    AddItem(ARMA("sherek/aldea/espada"),REFRESH_REMOVE,2,SF(wieldme));
    AddItem(PROT("sherek/aldea/coraza"),REFRESH_REMOVE,1,SF(wearme));
    InitChats(5,({"El Guardián te mira con suspicacia.\n",
        "El guardián dice: Aquí no queremos líos.\n",
        "El guardián dice: ¿no estarás buscando problemas, verdad?\n",
        "El guardián acaricia la empuñadura de su espada.\n",
        "El guardián dice: No se te ocurra ninguna tontería.\n"}));
    InitAChats(10,({"El guardián grita: ¡Eso ha sido una estupidez!\n"}));
}

