/***************************************************************************************
 ARCHIVO:	folker_05.c
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
    carcel=(RHOEHAB("koek/calles/folker_06"));

    AddExit("este",RHOEHAB("koek/calles/folker_06"));
    AddExit("oeste",RHOEHAB("koek/calles/folker_04"));

    map[neu,des]="Caminas por la calle Folker, una típica calle de pueblo "+
 	       "que discurre de oeste a este por el sur de Koek. Al este "+
 	       "puedes ver que la calle sigue, y casi ves la plaza que hay "+
 	       "más allá. Al oeste ves el cruce de la calle de los comerciantes "+
 	       "con esta calle. ";
}