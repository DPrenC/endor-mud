/* Archivo: /d/simauria/comun/pnj/abadia/aldeanoc.c
* Descripción: Aldeano trabajando en los campos.
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
    SetShort(QueryShort()+"labrador");
    SetLong(QueryLong()+"Ahora está cumpliendo su turno de trabajo en los campos "
        "de cultivo, donde se producen las verduras y frutas que sirven como "
        "pago de tributos a los monjes de la abadía.\n");
    AddId(({"aldeano","campesino","labrador"}));
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
    SetGoChance(90);
    AddWalkZones(SHERALD("campo"));
}
