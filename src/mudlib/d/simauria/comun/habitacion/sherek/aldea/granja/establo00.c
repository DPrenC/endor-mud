/* Archivo        establo00.c
   Autor:         Yalin y Lug
   Fecha:         12/05/2006
   Descripción:   establos de la granja (proyecto)
*/

#include "path.h"
inherit SHERALD("granja/establo");

create()
{
    ::create();
    AddItem(PNJ("sherek/aldea/vaca"),REFRESH_DESTRUCT,(d8()));
    AddItem(PNJ("sherek/aldea/ternero"),REFRESH_DESTRUCT,(d4()));
    AddItem(PNJ("sherek/aldea/toro"),REFRESH_DESTRUCT,1);
    AddExit("este", SHERALD("granja/granja00"));
    AddItem(PNJ("sherek/aldea/aldeanog"),REFRESH_DESTRUCT,2);
}
