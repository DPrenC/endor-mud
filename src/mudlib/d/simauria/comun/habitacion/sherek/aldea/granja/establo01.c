/* Archivo        establo01.c
   Autor:         Yalin y Lug
   Fecha:         12/05/2006
   Descripción:   establos de la granja (proyecto)
*/

#include "path.h"
inherit SHERALD("granja/establo");

create()
{
    ::create();
    AddItem(PNJ("sherek/aldea/caballot"), REFRESH_DESTRUCT,(d4()));
    AddItem(PNJ("sherek/aldea/caballom"), REFRESH_DESTRUCT,(d3()));
    AddItem(PNJ("sherek/aldea/caballos"), REFRESH_DESTRUCT,1);
    AddItem(PNJ("sherek/aldea/yegua"), REFRESH_DESTRUCT,(d4()));
    //AddItem(PNJ("sherek/aldea/potro"), REFRESH_DESTRUCT,(d4()));
    AddExit("este", SHERALD("granja/granja01"));
    AddItem(PNJ("sherek/aldea/aldeanog"),REFRESH_DESTRUCT,2);
}
