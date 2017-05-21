/* Archivo        labranza02.c
Autor:         Yalin y Lug
Fecha:         14/05/2006
Descripción:   campos de cultivo de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("campo/huerta");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el norte y el oeste continúan los "
        "campos de cultivo. Hacia el este y el sur el río Kandal te impide "
        "el paso.\n");
    AddDetail(({"rio","río"}),"Ves el río Kandal que todavía no adquiere las "
        "proporciones que tendrá en las llanuras más cerca del mar. En esta "
        "zona describe cerradas curvas entre las rocas y la corriente es "
        "bastante fuerte.\n");
    AddExit("norte", SHERALD("campo/labranza01"));
    AddExit("oeste", SHERALD("campo/labranza03"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
