/***************************************************************************************
 ARCHIVO:	folker_03.c
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
    carcel=(RHOEHAB("koek/calles/folker_04"));

    AddExit("este",RHOEHAB("koek/calles/folker_04"));
    AddExit("oeste",RHOEHAB("koek/calles/folker_02"));

    map[neu,des]="Estás en la calle Folker. Es una típica calle de pueblo "+
 	    "bastante transitada. Al este está el cruce que enlaza con "+
 	    "la calle Kadhu, y al oeste sigue hasta perderse en el molino. ";
}