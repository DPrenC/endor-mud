/***************************************************************************************
 ARCHIVO:	folker_01.c
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
    carcel=(RHOEHAB("koek/calles/folker_02"));

    AddExit("norte",RHOEHAB("koek/granja/camino_02"));
    AddExit("sur",RHOEHAB("koek/campos/puente_00"));
    AddExit("este",RHOEHAB("koek/calles/folker_02"));
    AddExit("oeste",RHOEHAB("koek/calles/folker_00"));
    AddItem(RHOEPNJ("koek/varios/patrullero"),REFRESH_DESTRUCT);
    map[neu,des]="Estás en la calle Folker. Es una calle algo transitada que "+
 	    "discurre por el sur de Koek. Al norte ves un camino que lleva a la "+
 	    "granja del pueblo. Al sur otro camino que lleva a los campos "+
 	    "de cultivo, pasando el puente que cruza el río Hedrikon. Al este "+
 	    "y al oeste la calle sigue su camino. ";
}