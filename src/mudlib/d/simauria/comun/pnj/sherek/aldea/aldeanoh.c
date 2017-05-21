/* Archivo: /d/simauria/comun/pnj/abadia/aldeanoh.c
* Descripción: Aldeano trabajando en su huerto.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
inherit PNJ("sherek/aldea/aldeano");

create()
{
    ::create();
    SetLong(QueryLong()+"Éste está trabajando en su huerto, las pocas horas que "
        "le deja libre su trabajo al servicio de los monjes de Sherek.\n");
    switch (random(5))
    {
        case 0:
            AddItem(OTRO("sherek/aldea/azada"),REFRESH_REMOVE,1, SF(wieldme));
            break;
        case 1:
            AddItem(OTRO("sherek/aldea/azadon"),REFRESH_REMOVE,1, SF(wieldme));
            break;
        case 2:
            AddItem(OTRO("sherek/aldea/guadanya"),REFRESH_REMOVE,1, SF(wieldme));
            break;
        case 3:
            AddItem(OTRO("sherek/aldea/pico"),REFRESH_REMOVE,1, SF(wieldme));
            break;
        case 4:
            AddItem(OTRO("sherek/aldea/rastrillo"),REFRESH_REMOVE,1, SF(wieldme));
            break;
        case 5: break;
    }
}
