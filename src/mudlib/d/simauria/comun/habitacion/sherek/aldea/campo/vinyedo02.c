/* Archivo:         viñedo02.c
Autor:           Yalin y Lug
Descripción:     viñedos en la aldea de Sloch
Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el oeste y el sur impide el paso el "
        "cauce del río Kandal. Al norte un pequeño muro te separa del camino "
        "que te trajo aquí. Hacia el este continúan los viñedos.\n");
    SetIntNoise("Escuchas el fuerte ruído del agua al correr por entre las "
        "rocas del cauce del río Kandal.\n");
    AddDetail(({"rio","río","cauce","este","sur"}),"Ves el cauce pedregoso "
        "del río Kandal que aquí hace una pronunciada curva de norte a este. "
        "La corriente baja con fuerza y hace bastante estruendo.\n");
    AddDetail(({"muro","pequeño muro"}),"El muro que separa el viñedo del "
        "camino está hecho con un par de sillares de piedra colocados uno "
        "sobre el otro. Es más testimonial que otra cosa.\n");
    AddExit("este", SHERALD("campo/vinyedo03"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
