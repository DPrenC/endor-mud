/***************************************************************************************
 ARCHIVO:	folker_07.c
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
    carcel=(RHOEHAB("koek/calles/folker_08"));

    AddExit("este",RHOEHAB("koek/calles/folker_08"));
    AddExit("oeste",RHOEHAB("koek/calles/plaza"));
    AddExit("noroeste",RHOEHAB("koek/calles/cendaf_03"));
    AddExit("suroeste",RHOEHAB("koek/calles/cendaf_04"));

    AddDetail(({"estatua","fundador"}),"Para ver eso mejor deberías acercarte a la plaza.\n");

    map[neu,des]="Esta es la calle Folker, una típica calle de un pueblo humano. "+
 	    "Al este puedes ver que la calle continúa su camino, al oeste ves "+
 	    "la plaza Zendak, con la estatua del fundador de Koek en el centro. "+
 	    "Al noroeste está la parte norte de la calle Cendaf, que lleva al "+
 	    "templo de Seri-Solderteg, y al suroeste sigue la misma calle hasta "+
 	    "la salida de Koek. ";
}