/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera61.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripción: A la orilla del río, al sur de la pradera.
****************************************************************************/

#include "path.h"
#include <sounds.h>
inherit SHERALD("pradera/pradera");

create()
{
    ::create();
    SetIntShort("la orilla del río Kandal");
    SetIntLong("La pradera, que se extiende hacia el norte, termina aquí en "
        "una especie de playa, en la ribera del Kandal.\nEl terreno es aquí "
        "más llano, por lo que el curso del río se vuelve más tranquilo.\nEn "
        "esta parte, el río apenas alcanza 1 metro 20 de profundidad, lo que "
        "hace que sea un buen sitio para darse un bañito.\nAl sur, el río te "
        "cierra el paso. En las demás direcciones se extiende la pradera.\n");
    SetIntSmell("Huele a humedad, algas y hierba.\n");
    AddDetail(({"playa","arena"}), "Arena fresca, fina y blanca.\n");
    AddDetail(({"rio","río","curso","cauce","agua"}), "El río discurre "
        "tranquilo y susurrante, y su agua está muy limpia.\n");
    AddExit("norte", SHERALD("pradera/pradera51"));
    AddExit("este", SHERALD("pradera/pradera60"));
    AddExit("oeste", SHERALD("pradera/pradera62"));
    int hora = QueryServer()->QueryState();
    if ((hora >= ND_PRENOON) && (hora <= ND_FALL)) AddItem(QUEST+"sherek/ninyo",REFRESH_DESTRUCT,1);
    poner_pnj();
    SetSoundEnvironment(SND_AMBIENTES("rio_bosque"));
}
