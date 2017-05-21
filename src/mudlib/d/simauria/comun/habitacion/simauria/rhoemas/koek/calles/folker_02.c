/***************************************************************************************
 ARCHIVO:	folker_02.c
 AUTOR:		[z] Zomax
 FECHA:		08-11-2001
 COMENTARIOS:	Calle Folker de Koek
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Folker");
    carcel=(RHOEHAB("koek/calles/folker_03"));

    AddExit("norte",RHOEHAB("koek/varios/bardo"));
    AddExit("sur",RHOEHAB("koek/muelle/cofradia"));
    AddExit("este",RHOEHAB("koek/calles/folker_03"));
    AddExit("oeste",RHOEHAB("koek/calles/folker_01"));
    AddItem(RHOEPNJ("koek/ciudadanos/ciudadana"), REFRESH_DESTRUCT);
    map[neu,des]="Esta es la calle Folker, que discurre desde el molino en la "
 	    "punta más oeste hasta la cárcel, en el extremo este. Al norte "
 	    "puedes ver la casa del bardo local y al sur la cofradía de "
 	    "pescadores, siempre abierta. ";
}