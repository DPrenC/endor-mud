/* Archivo:         viñedo06.c
Autor:            Yalin y Lug
Descripción:     viñedos en la aldea de Sloch
Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el este te impide el paso la maleza del "
        "bajo monte, al sur está el cauce del río Kandal. En las demás "
        "direcciones continúan los viñedos.\n");
    SetIntNoise("Escuchas el fuerte ruído del agua al correr por entre las "
        "rocas del cauce del río Kandal.\n");
    AddDetail(({"rio","río","cauce","sur"}),"Ves el cauce pedregoso "
        "del río Kandal, la corriente baja con fuerza y hace bastante "
        "estruendo.\n");
    AddDetail(({"este","monte","bajo monte","maleza"}),"es una espesura de arbustos "
        "y malezas que no te dejan avanzar más allá de donde estás.\n");
    AddExit("oeste", SHERALD("campo/vinyedo05"));
    AddExit("norte", SHERALD("campo/vinyedo04"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
