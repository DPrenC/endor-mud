/***************************************************************************************
 ARCHIVO:	cendaf_02.c
 AUTOR:		[z] Zomax
 FECHA:		14-11-2001
 COMENTARIOS:	Calle Cendaf de Koek
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Cendaf");
    carcel=(RHOEHAB("koek/calles/cendaf_03"));

    AddExit("norte",RHOEHAB("koek/calles/cendaf_01"));
    AddExit("sur",RHOEHAB("koek/calles/cendaf_03"));
    AddExit("este",RHOEHAB("koek/varios/parque"));
    AddExit("oeste",RHOEHAB("koek/varios/caravanas"));

    map[neu,des]= "Esta es la calle Cendaf, que discurre desde la plaza Zendak "
		"en el sur hasta el templo de Seri-Solderteg en el norte. Al oeste "
		"puedes ver la parada de las caravanas y al este un pequeño pero "
		"acogedor parque. ";
}