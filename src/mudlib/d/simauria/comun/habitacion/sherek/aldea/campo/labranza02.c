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
    SetIntLong(QueryIntLong()+"Hacia el norte puedes ver una empalizada que "
        "separa los cultivos de los pastos, hacia el oeste continúan los "
        "campos sembrados, hacia el este y el sur el río Kandal te impide el "
        "paso.\n");
    SetIntNoise("Oyes el chapoteo de la corriente en el río.\n");
    SetIntSmell("Huele a tierra removida y a humedad.\n");
    AddDetail(({"empalizada","cerca"}),"Se trata de una vaya de varios pies "
        "de alto que separa los cultivos de los pastos para evitar que los "
        "animales puedan comerse las cosechas.\n");
    AddDetail(({"rio","río"}),"Ves el río Kandal que todavía no adquiere las "
        "proporciones que tendrá en las llanuras más cerca del mar. En esta "
        "zona describe cerradas curvas entre las rocas y la corriente es "
        "bastante fuerte.\n");
    AddExit("oeste", SHERALD("campo/labranza01"));
    AddItem(PNJ("sherek/aldea/guardian"), REFRESH_DESTRUCT,1);
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
