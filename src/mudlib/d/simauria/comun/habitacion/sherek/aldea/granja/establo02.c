/* Archivo        establo02.c
   Autor:         Yalin y Lug
   Fecha:         12/05/2006
   Descripción:   establos de la granja (proyecto)
*/

#include "path.h"
inherit SHERALD("granja/establo");

create()
{
    ::create();
    AddExit("este", SHERALD("granja/granja02"));
    AddItem(PNJ("sherek/aldea/cordero"),REFRESH_DESTRUCT,(d4()));
    AddItem(PNJ("sherek/aldea/oveja"),REFRESH_DESTRUCT,(d6()));
    AddItem(PNJ("sherek/aldea/carnero"),REFRESH_DESTRUCT,1);
    AddItem(PNJ("sherek/aldea/aldeanog"),REFRESH_DESTRUCT,2);
}
