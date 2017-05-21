/*=============================================================*
 |             << Fortaleza:Simauria [m] Maler >> 		       |
 *=============================================================*
 |               Creacion............. 02-05-00                |
 *=============================================================*/

#include "./path.h"

#include <properties.h>

inherit NPC;

create ()
{
    ::create();
    SetStandard("una golondrina","pajaro",10+random(5),GENERO_FEMENINO);
    SetShort("una preciosa golondrina");
    SetLong("Es una preciosa golondrina. Sus plumas son negras y blancas, y vuela "
            "a una velocidad impresionante. Un bello pájaro.\n");
    SetIds(({"golondrina","Golondrina","preciosa golondrina"}));
    SetHands(({({"pico",0,3})}));
    SetInt(1);
    SetDex(QueryDex()+9);
    SetAlign(50);
    SetSize(P_SIZE_SMALL);
    InitChats(3,"La golondrina hace un cambio brusco de dirección.\n");
    SetGoChance(10);
    AddWalkZones(ROOMFB(""));
}
