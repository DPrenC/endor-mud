/***************************************************************************************
 ARCHIVO:	folker_06.c
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
    carcel=(RHOEHAB("koek/calles/plaza"));

    AddExit("sur",RHOEHAB("koek/muelle/taberna"));
    AddExit("este",RHOEHAB("koek/calles/plaza"));
    AddExit("oeste",RHOEHAB("koek/calles/folker_05"));
    AddExit("nordeste",RHOEHAB("koek/calles/cendaf_03"));
    AddExit("sudeste",RHOEHAB("koek/calles/cendaf_04"));

    map[neu,des]="Estás en uno de los tramos de la calle Folker. Es una típica "+
 	    "calle, algo estrecha, que discurre de oeste a este. Al este "+
 	    "mas próximo puedes ver la plaza de Zendak, en honor al primer "+
 	    "habitante del lugar. Al sur está el Hogar del Pescador, edificado a "+
 	    "orillas del río Hedrikon. Al oeste la calle discurre hasta "+
 	    "la calle de los comerciantes y más. Al nordeste y sudeste "+
 	    "discurre la calle Cendaf, desde el templo de Seri-Solderteg "+
 	    "hasta la salida de Koek. ";
}