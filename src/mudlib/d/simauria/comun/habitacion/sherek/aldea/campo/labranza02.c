/* Archivo        labranza02.c
Autor:         Yalin y Lug
Fecha:         14/05/2006
Descripci�n:   campos de cultivo de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("campo/huerta");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el norte puedes ver una empalizada que "
        "separa los cultivos de los pastos, hacia el oeste contin�an los "
        "campos sembrados, hacia el este y el sur el r�o Kandal te impide el "
        "paso.\n");
    SetIntNoise("Oyes el chapoteo de la corriente en el r�o.\n");
    SetIntSmell("Huele a tierra removida y a humedad.\n");
    AddDetail(({"empalizada","cerca"}),"Se trata de una vaya de varios pies "
        "de alto que separa los cultivos de los pastos para evitar que los "
        "animales puedan comerse las cosechas.\n");
    AddDetail(({"rio","r�o"}),"Ves el r�o Kandal que todav�a no adquiere las "
        "proporciones que tendr� en las llanuras m�s cerca del mar. En esta "
        "zona describe cerradas curvas entre las rocas y la corriente es "
        "bastante fuerte.\n");
    AddExit("oeste", SHERALD("campo/labranza01"));
    AddItem(PNJ("sherek/aldea/guardian"), REFRESH_DESTRUCT,1);
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
